/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file conf_xml.c
 * \brief XML configuration file parser implementation.
 */

#include "stdinc.h"
#include "schema_wrapper.h"
#include "conf_xml.h"
#include "conf.h"
#include "client.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "log.h"
#include "list.h"
#include "memory.h"
#include "numeric.h"
#include "user.h"
#include "send.h"
#include "res.h"
#include "tls.h"
#include "conf_xml.h"
#include "conf.h"
#include "log.h"
#include "memory.h"
#include "defaults.h"
#include "parse.h"  /* Must come before conf_pseudo.h for Command struct */
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_gecos.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "listener.h"
#include "misc.h"
#include "server.h"
#include "nuh.h"
#include "client.h"
#include "send.h"
#include "ircd.h"
#include "address.h"  /* For address matching functions */
#include "io_string.h"
#include "numeric.h"
#include "user.h"
#include "channel.h"
#include "channel_mode.h"
#include "list.h"
#include "ircd_defs.h"
#include "conf_db.h"
#include "motd.h"
#include "module.h"
#include "res.h"
#include "tls.h"

/* Forward declarations */
void conf_clear(void);
void conf_set_defaults(void);
void conf_validate(void);
static void xml_structured_error_handler(void *userData, const struct _xmlError *error);

/* Global variables */
static xmlSchemaPtr schema = NULL;
static xmlSchemaValidCtxtPtr schema_valid_ctx = NULL;

/* Helper functions */
static const char *
get_node_content(xmlNodePtr node)
{
  if (!node || !node->children || node->children->type != XML_TEXT_NODE)
    return NULL;

  return (const char *)node->children->content;
}

/* Forward declaration for dump_schema_for_debugging */
static void dump_schema_for_debugging(void);

static void
xml_error_handler(void *ctx, const char *msg, ...)
{
  char buf[IRCD_BUFSIZE];
  va_list args;

  va_start(args, msg);
  vsnprintf(buf, sizeof(buf), msg, args);
  va_end(args);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "XML Error: %s", buf);
}

/* Commented out to avoid unused function warning */
/*
static void
xml_warning_handler(void *ctx, const char *msg, ...)
{
  char buf[IRCD_BUFSIZE];
  va_list args;

  va_start(args, msg);
  vsnprintf(buf, sizeof(buf), msg, args);
  va_end(args);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_WARN, "XML Warning: %s", buf);
}
*/

/* Structured error handler for XML validation */
static void
xml_structured_error_handler(void *userData, const struct _xmlError *error)
{
  if (!error)
    return;
    
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "XML Validation Error: %s", 
            error->message ? error->message : "Unknown error");
            
  if (error->line > 0)
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Error at line %d, column %d", 
              error->line, error->int2);
}

/* Helper function to parse time specifications */
static unsigned int
parse_time_spec(const char *str)
{
  unsigned int total = 0;
  char *copy = io_strdup(str);
  char *token = strtok(copy, " ");

  while (token)
  {
    unsigned int value = atoi(token);
    token = strtok(NULL, " ");
    if (!token)
      break;

    if (strncasecmp(token, "year", 4) == 0)
      total += value * 60 * 60 * 24 * 365;
    else if (strncasecmp(token, "month", 5) == 0)
      total += value * 60 * 60 * 24 * 30;
    else if (strncasecmp(token, "week", 4) == 0)
      total += value * 60 * 60 * 24 * 7;
    else if (strncasecmp(token, "day", 3) == 0)
      total += value * 60 * 60 * 24;
    else if (strncasecmp(token, "hour", 4) == 0)
      total += value * 60 * 60;
    else if (strncasecmp(token, "minute", 6) == 0)
      total += value * 60;
    else if (strncasecmp(token, "second", 6) == 0)
      total += value;

    token = strtok(NULL, " ");
  }

  io_free(copy);
  return total;
}

/* Helper function to parse size specifications */
static unsigned int
parse_size_spec(const char *str)
{
  unsigned int total = 0;
  char *copy = io_strdup(str);
  char *token = strtok(copy, " ");

  while (token)
  {
    unsigned int value = atoi(token);
    token = strtok(NULL, " ");
    if (!token)
      break;

    if (strncasecmp(token, "mb", 2) == 0 || strncasecmp(token, "megabyte", 8) == 0)
      total += value * 1024 * 1024;
    else if (strncasecmp(token, "kb", 2) == 0 || strncasecmp(token, "kilobyte", 8) == 0)
      total += value * 1024;
    else if (strncasecmp(token, "byte", 4) == 0)
      total += value;

    token = strtok(NULL, " ");
  }

  io_free(copy);
  return total;
}

/* Parse helper functions for each configuration section */
static void
parse_serverinfo(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  xmlChar *sid = xmlGetProp(node, (const xmlChar *)"sid");
  xmlChar *description = xmlGetProp(node, (const xmlChar *)"description");
  xmlChar *network_name = xmlGetProp(node, (const xmlChar *)"network_name");
  xmlChar *network_desc = xmlGetProp(node, (const xmlChar *)"network_description");
  xmlChar *max_clients = xmlGetProp(node, (const xmlChar *)"default_max_clients");
  xmlChar *max_nick_length = xmlGetProp(node, (const xmlChar *)"max_nick_length");
  xmlChar *max_topic_length = xmlGetProp(node, (const xmlChar *)"max_topic_length");
  xmlChar *hub = xmlGetProp(node, (const xmlChar *)"hub");
  xmlChar *motd_file = xmlGetProp(node, (const xmlChar *)"motd_file");

  if (name)
    ConfigServerInfo.name = io_strdup((const char *)name);
  if (sid)
    ConfigServerInfo.sid = io_strdup((const char *)sid);
  if (description)
    ConfigServerInfo.description = io_strdup((const char *)description);
  if (network_name)
    ConfigServerInfo.network_name = io_strdup((const char *)network_name);
  if (network_desc)
    ConfigServerInfo.network_description = io_strdup((const char *)network_desc);
  if (max_clients)
    ConfigServerInfo.default_max_clients = atoi((const char *)max_clients);
  if (max_nick_length)
    ConfigServerInfo.max_nick_length = atoi((const char *)max_nick_length);
  if (max_topic_length)
    ConfigServerInfo.max_topic_length = atoi((const char *)max_topic_length);
  if (hub)
    ConfigServerInfo.hub = xmlStrcmp(hub, (const xmlChar *)"yes") == 0;
  if (motd_file)
    ConfigServerInfo.motd_file = io_strdup((const char *)motd_file);

  xmlFree(name);
  xmlFree(sid);
  xmlFree(description);
  xmlFree(network_name);
  xmlFree(network_desc);
  xmlFree(max_clients);
  xmlFree(max_nick_length);
  xmlFree(max_topic_length);
  xmlFree(hub);
  xmlFree(motd_file);
}

static void
parse_admin(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  xmlChar *description = xmlGetProp(node, (const xmlChar *)"description");
  xmlChar *email = xmlGetProp(node, (const xmlChar *)"email");

  if (name)
    ConfigAdminInfo.name = io_strdup((const char *)name);
  if (description)
    ConfigAdminInfo.description = io_strdup((const char *)description);
  if (email)
    ConfigAdminInfo.email = io_strdup((const char *)email);

  xmlFree(name);
  xmlFree(description);
  xmlFree(email);
}

static void
parse_class(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  if (!name)
    return;

  struct ClassItem *class = class_find((const char *)name, false);
  if (class == NULL)
    class = class_make();

  class->active = true;
  io_free(class->name);
  class->name = io_strdup((const char *)name);

  xmlChar *ping_time = xmlGetProp(node, (const xmlChar *)"ping_time");
  xmlChar *connectfreq = xmlGetProp(node, (const xmlChar *)"connectfreq");
  xmlChar *max_number = xmlGetProp(node, (const xmlChar *)"max_number");
  xmlChar *sendq = xmlGetProp(node, (const xmlChar *)"sendq");
  xmlChar *recvq = xmlGetProp(node, (const xmlChar *)"recvq");
  xmlChar *max_channels = xmlGetProp(node, (const xmlChar *)"max_channels");
  xmlChar *max_perip_local = xmlGetProp(node, (const xmlChar *)"max_perip_local");
  xmlChar *max_perip_global = xmlGetProp(node, (const xmlChar *)"max_perip_global");
  xmlChar *cidr_bitlen_ipv4 = xmlGetProp(node, (const xmlChar *)"cidr_bitlen_ipv4");
  xmlChar *cidr_bitlen_ipv6 = xmlGetProp(node, (const xmlChar *)"cidr_bitlen_ipv6");
  xmlChar *number_per_cidr = xmlGetProp(node, (const xmlChar *)"number_per_cidr");
  xmlChar *min_idle = xmlGetProp(node, (const xmlChar *)"min_idle");
  xmlChar *max_idle = xmlGetProp(node, (const xmlChar *)"max_idle");
  xmlChar *random_idle = xmlGetProp(node, (const xmlChar *)"random_idle");
  xmlChar *hide_idle_from_opers = xmlGetProp(node, (const xmlChar *)"hide_idle_from_opers");

  if (ping_time)
    class->ping_freq = parse_time_spec((const char *)ping_time);
  if (connectfreq)
    class->con_freq = parse_time_spec((const char *)connectfreq);
  if (max_number)
    class->max_total = atoi((const char *)max_number);
  if (sendq)
    class->max_sendq = parse_size_spec((const char *)sendq);
  if (recvq)
    class->max_recvq = parse_size_spec((const char *)recvq);
  if (max_channels)
    class->max_channels = atoi((const char *)max_channels);
  if (max_perip_local)
    class->max_perip_local = atoi((const char *)max_perip_local);
  if (max_perip_global)
    class->max_perip_global = atoi((const char *)max_perip_global);
  if (cidr_bitlen_ipv4)
    class->cidr_bitlen_ipv4 = atoi((const char *)cidr_bitlen_ipv4);
  if (cidr_bitlen_ipv6)
    class->cidr_bitlen_ipv6 = atoi((const char *)cidr_bitlen_ipv6);
  if (number_per_cidr)
    class->number_per_cidr = atoi((const char *)number_per_cidr);
  if (min_idle)
    class->min_idle = parse_time_spec((const char *)min_idle);
  if (max_idle)
    class->max_idle = parse_time_spec((const char *)max_idle);
  if (random_idle)
    class->flags |= CLASS_FLAGS_RANDOM_IDLE;
  if (hide_idle_from_opers)
    class->flags |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;

  xmlFree(name);
  xmlFree(ping_time);
  xmlFree(connectfreq);
  xmlFree(max_number);
  xmlFree(sendq);
  xmlFree(recvq);
  xmlFree(max_channels);
  xmlFree(max_perip_local);
  xmlFree(max_perip_global);
  xmlFree(cidr_bitlen_ipv4);
  xmlFree(cidr_bitlen_ipv6);
  xmlFree(number_per_cidr);
  xmlFree(min_idle);
  xmlFree(max_idle);
  xmlFree(random_idle);
  xmlFree(hide_idle_from_opers);
}

static void
parse_channel(xmlNodePtr node)
{
  xmlChar *max_bans = xmlGetProp(node, (const xmlChar *)"max_bans");
  xmlChar *max_bans_large = xmlGetProp(node, (const xmlChar *)"max_bans_large");
  xmlChar *max_invites = xmlGetProp(node, (const xmlChar *)"max_invites");
  xmlChar *max_kick_length = xmlGetProp(node, (const xmlChar *)"max_kick_length");
  xmlChar *max_channels = xmlGetProp(node, (const xmlChar *)"max_channels");
  xmlChar *invite_client_count = xmlGetProp(node, (const xmlChar *)"invite_client_count");
  xmlChar *invite_client_time = xmlGetProp(node, (const xmlChar *)"invite_client_time");
  xmlChar *invite_delay_channel = xmlGetProp(node, (const xmlChar *)"invite_delay_channel");
  xmlChar *invite_expire_time = xmlGetProp(node, (const xmlChar *)"invite_expire_time");
  xmlChar *knock_client_count = xmlGetProp(node, (const xmlChar *)"knock_client_count");
  xmlChar *knock_client_time = xmlGetProp(node, (const xmlChar *)"knock_client_time");
  xmlChar *knock_delay_channel = xmlGetProp(node, (const xmlChar *)"knock_delay_channel");
  xmlChar *default_join_flood_count = xmlGetProp(node, (const xmlChar *)"default_join_flood_count");
  xmlChar *default_join_flood_time = xmlGetProp(node, (const xmlChar *)"default_join_flood_time");
  xmlChar *disable_fake_channels = xmlGetProp(node, (const xmlChar *)"disable_fake_channels");
  xmlChar *enable_extbans = xmlGetProp(node, (const xmlChar *)"enable_extbans");
  xmlChar *enable_owner = xmlGetProp(node, (const xmlChar *)"enable_owner");
  xmlChar *enable_admin = xmlGetProp(node, (const xmlChar *)"enable_admin");

  if (max_bans)
    ConfigChannel.max_bans = atoi((const char *)max_bans);
  if (max_bans_large)
    ConfigChannel.max_bans_large = atoi((const char *)max_bans_large);
  if (max_invites)
    ConfigChannel.max_invites = atoi((const char *)max_invites);
  if (max_kick_length)
    ConfigChannel.max_kick_length = atoi((const char *)max_kick_length);
  if (max_channels)
    ConfigChannel.max_channels = atoi((const char *)max_channels);
  if (invite_client_count)
    ConfigChannel.invite_client_count = atoi((const char *)invite_client_count);
  if (invite_client_time)
    ConfigChannel.invite_client_time = parse_time_spec((const char *)invite_client_time);
  if (invite_delay_channel)
    ConfigChannel.invite_delay_channel = parse_time_spec((const char *)invite_delay_channel);
  if (invite_expire_time)
    ConfigChannel.invite_expire_time = parse_time_spec((const char *)invite_expire_time);
  if (knock_client_count)
    ConfigChannel.knock_client_count = atoi((const char *)knock_client_count);
  if (knock_client_time)
    ConfigChannel.knock_client_time = parse_time_spec((const char *)knock_client_time);
  if (knock_delay_channel)
    ConfigChannel.knock_delay_channel = parse_time_spec((const char *)knock_delay_channel);
  if (default_join_flood_count)
    ConfigChannel.default_join_flood_count = atoi((const char *)default_join_flood_count);
  if (default_join_flood_time)
    ConfigChannel.default_join_flood_time = parse_time_spec((const char *)default_join_flood_time);
  if (disable_fake_channels)
    ConfigChannel.disable_fake_channels = xmlStrcmp(disable_fake_channels, (const xmlChar *)"yes") == 0;
  if (enable_extbans)
    ConfigChannel.enable_extbans = xmlStrcmp(enable_extbans, (const xmlChar *)"yes") == 0;
  if (enable_owner)
    ConfigChannel.enable_owner = xmlStrcmp(enable_owner, (const xmlChar *)"yes") == 0;
  if (enable_admin)
    ConfigChannel.enable_admin = xmlStrcmp(enable_admin, (const xmlChar *)"yes") == 0;

  xmlFree(max_bans);
  xmlFree(max_bans_large);
  xmlFree(max_invites);
  xmlFree(max_kick_length);
  xmlFree(max_channels);
  xmlFree(invite_client_count);
  xmlFree(invite_client_time);
  xmlFree(invite_delay_channel);
  xmlFree(invite_expire_time);
  xmlFree(knock_client_count);
  xmlFree(knock_client_time);
  xmlFree(knock_delay_channel);
  xmlFree(default_join_flood_count);
  xmlFree(default_join_flood_time);
  xmlFree(disable_fake_channels);
  xmlFree(enable_extbans);
  xmlFree(enable_owner);
  xmlFree(enable_admin);
}

static void
parse_serverhide(xmlNodePtr node)
{
  xmlChar *flatten_links = xmlGetProp(node, (const xmlChar *)"flatten_links");
  xmlChar *flatten_links_delay = xmlGetProp(node, (const xmlChar *)"flatten_links_delay");
  xmlChar *flatten_links_file = xmlGetProp(node, (const xmlChar *)"flatten_links_file");
  xmlChar *disable_remote_commands = xmlGetProp(node, (const xmlChar *)"disable_remote_commands");
  xmlChar *hide_servers = xmlGetProp(node, (const xmlChar *)"hide_servers");
  xmlChar *hide_services = xmlGetProp(node, (const xmlChar *)"hide_services");
  xmlChar *hidden = xmlGetProp(node, (const xmlChar *)"hidden");
  xmlChar *hidden_name = xmlGetProp(node, (const xmlChar *)"hidden_name");
  xmlChar *hide_server_ips = xmlGetProp(node, (const xmlChar *)"hide_server_ips");

  if (flatten_links)
    ConfigServerHide.flatten_links = xmlStrcmp(flatten_links, (const xmlChar *)"yes") == 0;
  if (flatten_links_delay)
    ConfigServerHide.flatten_links_delay = parse_time_spec((const char *)flatten_links_delay);
  if (flatten_links_file)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup((const char *)flatten_links_file);
  }
  if (disable_remote_commands)
    ConfigServerHide.disable_remote_commands = xmlStrcmp(disable_remote_commands, (const xmlChar *)"yes") == 0;
  if (hide_servers)
    ConfigServerHide.hide_servers = xmlStrcmp(hide_servers, (const xmlChar *)"yes") == 0;
  if (hide_services)
    ConfigServerHide.hide_services = xmlStrcmp(hide_services, (const xmlChar *)"yes") == 0;
  if (hidden)
    ConfigServerHide.hidden = xmlStrcmp(hidden, (const xmlChar *)"yes") == 0;
  if (hidden_name)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup((const char *)hidden_name);
  }
  if (hide_server_ips)
    ConfigServerHide.hide_server_ips = xmlStrcmp(hide_server_ips, (const xmlChar *)"yes") == 0;

  xmlFree(flatten_links);
  xmlFree(flatten_links_delay);
  xmlFree(flatten_links_file);
  xmlFree(disable_remote_commands);
  xmlFree(hide_servers);
  xmlFree(hide_services);
  xmlFree(hidden);
  xmlFree(hidden_name);
  xmlFree(hide_server_ips);
}

static void
parse_log(xmlNodePtr node)
{
  xmlNodePtr child;
  enum log_type log_type = LOG_TYPE_IRCD;
  enum log_severity severity = LOG_SEVERITY_INFO;
  size_t size_value = 0;
  const char *name = NULL;

  for (child = node->children; child; child = child->next)
  {
    if (child->type != XML_ELEMENT_NODE)
      continue;

    if (strcmp((char *)child->name, "type") == 0)
    {
      const char *type = get_node_content(child);
      if (type)
      {
        if (strcmp(type, "ircd") == 0)
          log_type = LOG_TYPE_IRCD;
        else if (strcmp(type, "kill") == 0)
          log_type = LOG_TYPE_KILL;
        else if (strcmp(type, "kline") == 0)
          log_type = LOG_TYPE_KLINE;
        else if (strcmp(type, "dline") == 0)
          log_type = LOG_TYPE_DLINE;
        else if (strcmp(type, "xline") == 0)
          log_type = LOG_TYPE_XLINE;
        else if (strcmp(type, "resv") == 0)
          log_type = LOG_TYPE_RESV;
        else if (strcmp(type, "oper") == 0)
          log_type = LOG_TYPE_OPER;
        else if (strcmp(type, "debug") == 0)
          log_type = LOG_TYPE_DEBUG;
      }
    }
    else if (strcmp((char *)child->name, "severity") == 0)
    {
      const char *sev = get_node_content(child);
      if (sev)
      {
        if (strcmp(sev, "debug") == 0)
          severity = LOG_SEVERITY_DEBUG;
        else if (strcmp(sev, "info") == 0)
          severity = LOG_SEVERITY_INFO;
        else if (strcmp(sev, "notice") == 0)
          severity = LOG_SEVERITY_NOTICE;
        else if (strcmp(sev, "warn") == 0)
          severity = LOG_SEVERITY_WARN;
        else if (strcmp(sev, "error") == 0)
          severity = LOG_SEVERITY_ERROR;
        else if (strcmp(sev, "critical") == 0)
          severity = LOG_SEVERITY_CRITICAL;
      }
    }
    else if (strcmp((char *)child->name, "size") == 0)
    {
      const char *size = get_node_content(child);
      if (size)
        size_value = parse_size_spec(size);
    }
    else if (strcmp((char *)child->name, "name") == 0)
    {
      name = get_node_content(child);
    }
  }

  if (name)
    log_add(log_type, severity, false, size_value, name);
}

static void
parse_oper(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  xmlChar *user = xmlGetProp(node, (const xmlChar *)"user");
  xmlChar *password = xmlGetProp(node, (const xmlChar *)"password");
  xmlChar *class_name = xmlGetProp(node, (const xmlChar *)"class");
  xmlChar *encrypted = xmlGetProp(node, (const xmlChar *)"encrypted");
  xmlChar *flags = xmlGetProp(node, (const xmlChar *)"flags");

  if (!name || !user || !password)
    return;

  struct MaskItem *conf = conf_make(CONF_OPER);
  conf->name = io_strdup((const char *)name);

  struct nuh_split nuh;  /* Use correct struct name */
  nuh.nuhmask = (char *)user;
  nuh.nickptr = NULL;
  nuh.userptr = conf->user;
  nuh.hostptr = conf->host;
  nuh.nicksize = 0;
  nuh.usersize = sizeof(conf->user);
  nuh.hostsize = sizeof(conf->host);

  nuh_split(&nuh);

  conf->passwd = io_strdup((const char *)password);

  if (encrypted && xmlStrcmp(encrypted, (const xmlChar *)"yes") == 0)
    conf->flags |= CONF_FLAGS_ENCRYPTED;

  /* Parse oper flags */
  if (flags)
  {
    char *flag_str = io_strdup((const char *)flags);
    char *flag = strtok(flag_str, ",");
    while (flag)
    {
      while (*flag == ' ')
        ++flag;

      if (strcmp(flag, "admin") == 0)
        conf->port |= UMODE_ADMIN;  /* Use port field for modes */
      else if (strcmp(flag, "oper") == 0)
        conf->port |= UMODE_OPER;
      else if (strcmp(flag, "locop") == 0)
        conf->port |= UMODE_LOCOPS;

      flag = strtok(NULL, ",");
    }
    io_free(flag_str);
  }

  conf_assign_class(conf, (const char *)class_name);

  xmlFree(name);
  xmlFree(user);
  xmlFree(password);
  xmlFree(class_name);
  xmlFree(encrypted);
  xmlFree(flags);
}

static void
parse_listen(xmlNodePtr node)
{
  xmlChar *port = xmlGetProp(node, (const xmlChar *)"port");
  xmlChar *ip = xmlGetProp(node, (const xmlChar *)"ip");
  xmlChar *host = xmlGetProp(node, (const xmlChar *)"host");
  xmlChar *flags = xmlGetProp(node, (const xmlChar *)"flags");

  if (!port)
    return;

  unsigned int listener_flags = 0;
  if (flags)
  {
    char *flag_str = io_strdup((const char *)flags);
    char *flag = strtok(flag_str, ",");
    while (flag)
    {
      while (*flag == ' ')
        ++flag;

      if (strcmp(flag, "tls") == 0)
        listener_flags |= LISTENER_TLS;
      else if (strcmp(flag, "hidden") == 0)
        listener_flags |= LISTENER_HIDDEN;
      else if (strcmp(flag, "server") == 0)
        listener_flags |= LISTENER_SERVER;
      else if (strcmp(flag, "client") == 0)
        listener_flags |= LISTENER_CLIENT;
      else if (strcmp(flag, "defer") == 0)
        listener_flags |= LISTENER_DEFER;

      flag = strtok(NULL, ",");
    }
    io_free(flag_str);
  }

  const char *addr = ip ? (const char *)ip : (host ? (const char *)host : "");
  char *port_str = io_strdup((const char *)port);
  char *port_range = strchr(port_str, ':');

  if (port_range)
  {
    *port_range = '\0';
    int start_port = atoi(port_str);
    int end_port = atoi(port_range + 1);

    for (int i = start_port; i <= end_port; ++i)
      listener_add(i, addr, listener_flags);
  }
  else
  {
    listener_add(atoi(port_str), addr, listener_flags);
  }

  io_free(port_str);
  xmlFree(port);
  xmlFree(ip);
  xmlFree(host);
  xmlFree(flags);
}

static void
parse_auth(xmlNodePtr node)
{
  xmlChar *user = xmlGetProp(node, (const xmlChar *)"user");
  if (!user)
    return;

  struct MaskItem *conf = conf_make(CONF_CLIENT);
  struct nuh_split nuh = { 0 };  /* Use correct struct name */
  nuh.nuhmask = (char *)user;
  nuh.nickptr = NULL;
  nuh.userptr = conf->user;
  nuh.hostptr = conf->host;
  nuh.nicksize = 0;
  nuh.usersize = sizeof(conf->user);
  nuh.hostsize = sizeof(conf->host);

  nuh_split(&nuh);

  xmlChar *password = xmlGetProp(node, (const xmlChar *)"password");
  xmlChar *class_name = xmlGetProp(node, (const xmlChar *)"class");
  xmlChar *flags = xmlGetProp(node, (const xmlChar *)"flags");
  xmlChar *spoof = xmlGetProp(node, (const xmlChar *)"spoof");
  xmlChar *redirserv = xmlGetProp(node, (const xmlChar *)"redirserv");
  xmlChar *redirport = xmlGetProp(node, (const xmlChar *)"redirport");
  xmlChar *encrypted = xmlGetProp(node, (const xmlChar *)"encrypted");

  if (password)
    conf->passwd = io_strdup((const char *)password);
  if (spoof)
    conf->name = io_strdup((const char *)spoof);
  if (redirserv)
  {
    conf->name = io_strdup((const char *)redirserv);
    conf->flags |= CONF_FLAGS_REDIR;
  }
  if (redirport)
  {
    conf->port = atoi((const char *)redirport);
    conf->flags |= CONF_FLAGS_REDIR;
  }
  if (encrypted && xmlStrcmp(encrypted, (const xmlChar *)"yes") == 0)
    conf->flags |= CONF_FLAGS_ENCRYPTED;

  /* Parse auth flags */
  if (flags)
  {
    char *flag_str = io_strdup((const char *)flags);
    char *flag = strtok(flag_str, ",");
    while (flag)
    {
      while (*flag == ' ')
        flag++;

      if (strcmp(flag, "exceed_limit") == 0)
        conf->flags |= CONF_FLAGS_NOLIMIT;
      else if (strcmp(flag, "kline_exempt") == 0)
        conf->flags |= CONF_FLAGS_EXEMPTKLINE;
      else if (strcmp(flag, "xline_exempt") == 0)
        conf->flags |= CONF_FLAGS_EXEMPTXLINE;
      else if (strcmp(flag, "need_ident") == 0)
        conf->flags |= CONF_FLAGS_NEED_IDENTD;
      else if (strcmp(flag, "can_flood") == 0)
        conf->flags |= CONF_FLAGS_CAN_FLOOD;
      else if (strcmp(flag, "no_tilde") == 0)
        conf->flags |= CONF_FLAGS_NO_TILDE;
      else if (strcmp(flag, "resv_exempt") == 0)
        conf->flags |= CONF_FLAGS_EXEMPTRESV;
      else if (strcmp(flag, "webirc") == 0)
        conf->flags |= CONF_FLAGS_WEBIRC;
      else if (strcmp(flag, "need_password") == 0)
        conf->flags |= CONF_FLAGS_NEED_PASSWORD;

      flag = strtok(NULL, ",");
    }
    io_free(flag_str);
  }

  conf_assign_class(conf, (const char *)class_name);
  add_conf_by_address(CONF_CLIENT, conf);

  xmlFree(user);
  xmlFree(password);
  xmlFree(class_name);
  xmlFree(flags);
  xmlFree(spoof);
  xmlFree(redirserv);
  xmlFree(redirport);
  xmlFree(encrypted);
}

static void
parse_connect(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  xmlChar *host = xmlGetProp(node, (const xmlChar *)"host");
  if (!name || !host)
    return;

  struct MaskItem *conf = conf_make(CONF_SERVER);
  conf->name = io_strdup((const char *)name);
  conf->host = io_strdup((const char *)host);

  xmlChar *timeout = xmlGetProp(node, (const xmlChar *)"timeout");
  xmlChar *bind = xmlGetProp(node, (const xmlChar *)"bind");
  xmlChar *send_password = xmlGetProp(node, (const xmlChar *)"send_password");
  xmlChar *accept_password = xmlGetProp(node, (const xmlChar *)"accept_password");
  xmlChar *tls_certificate_fingerprint = xmlGetProp(node, (const xmlChar *)"tls_certificate_fingerprint");
  xmlChar *port = xmlGetProp(node, (const xmlChar *)"port");
  xmlChar *aftype = xmlGetProp(node, (const xmlChar *)"aftype");
  xmlChar *tls_cipher_list = xmlGetProp(node, (const xmlChar *)"tls_cipher_list");
  xmlChar *flags = xmlGetProp(node, (const xmlChar *)"flags");
  xmlChar *hub_mask = xmlGetProp(node, (const xmlChar *)"hub_mask");
  xmlChar *leaf_mask = xmlGetProp(node, (const xmlChar *)"leaf_mask");
  xmlChar *class_name = xmlGetProp(node, (const xmlChar *)"class");
  xmlChar *encrypted = xmlGetProp(node, (const xmlChar *)"encrypted");

  if (timeout)
    conf->timeout = parse_time_spec((const char *)timeout);
  if (bind)
  {
    conf->bind = io_calloc(sizeof(*conf->bind));
    if (address_from_string((const char *)bind, conf->bind) == false)
    {
      log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Invalid netmask for server bind(%s)", (const char *)bind);
      io_free(conf->bind);
      conf->bind = NULL;
    }
  }
  if (send_password)
    conf->passwd = io_strdup((const char *)send_password);
  if (accept_password)
    conf->spasswd = io_strdup((const char *)accept_password);
  if (tls_certificate_fingerprint)
    conf->certfp = io_strdup((const char *)tls_certificate_fingerprint);
  if (port)
    conf->port = atoi((const char *)port);
  if (aftype)
  {
    if (xmlStrcmp(aftype, (const xmlChar *)"ipv4") == 0)
      conf->aftype = AF_INET;
    else if (xmlStrcmp(aftype, (const xmlChar *)"ipv6") == 0)
      conf->aftype = AF_INET6;
  }
  if (tls_cipher_list)
    conf->cipher_list = io_strdup((const char *)tls_cipher_list);
  if (flags)
  {
    char *flag_str = io_strdup((const char *)flags);
    char *flag = strtok(flag_str, ",");
    while (flag)
    {
      while (*flag == ' ')
        flag++;

      if (strcmp(flag, "autoconn") == 0)
        conf->flags |= CONF_FLAGS_ALLOW_AUTO_CONN;
      else if (strcmp(flag, "tls") == 0)
        conf->flags |= CONF_FLAGS_TLS;

      flag = strtok(NULL, ",");
    }
    io_free(flag_str);
  }
  if (hub_mask)
    list_add(io_strdup((const char *)hub_mask), list_make_node(), &conf->hub_list);
  if (leaf_mask)
    list_add(io_strdup((const char *)leaf_mask), list_make_node(), &conf->leaf_list);
  if (encrypted && xmlStrcmp(encrypted, (const xmlChar *)"yes") == 0)
    conf->flags |= CONF_FLAGS_ENCRYPTED;

  conf_assign_class(conf, (const char *)class_name);
  conf_dns_lookup(conf);

  xmlFree(name);
  xmlFree(host);
  xmlFree(timeout);
  xmlFree(bind);
  xmlFree(send_password);
  xmlFree(accept_password);
  xmlFree(tls_certificate_fingerprint);
  xmlFree(port);
  xmlFree(aftype);
  xmlFree(tls_cipher_list);
  xmlFree(flags);
  xmlFree(hub_mask);
  xmlFree(leaf_mask);
  xmlFree(class_name);
  xmlFree(encrypted);
}

static void
parse_cluster(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  xmlChar *type = xmlGetProp(node, (const xmlChar *)"type");
  if (!name || !type)
    return;

  struct ClusterItem *cluster = cluster_make();
  cluster->server = io_strdup((const char *)name);

  /* Parse cluster type */
  char *type_str = io_strdup((const char *)type);
  char *type_token = strtok(type_str, ",");
  while (type_token)
  {
    while (*type_token == ' ')
      ++type_token;

    if (strcmp(type_token, "kline") == 0)
      cluster->type |= CLUSTER_KLINE;
    else if (strcmp(type_token, "unkline") == 0)
      cluster->type |= CLUSTER_UNKLINE;
    else if (strcmp(type_token, "dline") == 0)
      cluster->type |= CLUSTER_DLINE;
    else if (strcmp(type_token, "undline") == 0)
      cluster->type |= CLUSTER_UNDLINE;
    else if (strcmp(type_token, "xline") == 0)
      cluster->type |= CLUSTER_XLINE;
    else if (strcmp(type_token, "unxline") == 0)
      cluster->type |= CLUSTER_UNXLINE;
    else if (strcmp(type_token, "resv") == 0)
      cluster->type |= CLUSTER_RESV;
    else if (strcmp(type_token, "unresv") == 0)
      cluster->type |= CLUSTER_UNRESV;
    else if (strcmp(type_token, "locops") == 0)
      cluster->type |= CLUSTER_LOCOPS;
    else if (strcmp(type_token, "all") == 0)
      cluster->type = CLUSTER_ALL;

    type_token = strtok(NULL, ",");
  }
  io_free(type_str);

  xmlFree(name);
  xmlFree(type);
}

static void
parse_shared(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  xmlChar *user = xmlGetProp(node, (const xmlChar *)"user");
  xmlChar *type = xmlGetProp(node, (const xmlChar *)"type");
  if (!name || !user || !type)
    return;

  struct SharedItem *shared = shared_make();
  shared->server = io_strdup((const char *)name);

  struct nuh_split nuh = { 0 };  /* Use correct struct name */
  nuh.nuhmask = (char *)user;
  nuh.nickptr = NULL;
  nuh.userptr = shared->user;
  nuh.hostptr = shared->host;
  nuh.nicksize = 0;
  nuh.usersize = sizeof(shared->user);
  nuh.hostsize = sizeof(shared->host);

  nuh_split(&nuh);

  /* Parse shared type */
  char *type_str = io_strdup((const char *)type);
  char *type_token = strtok(type_str, ",");
  while (type_token)
  {
    while (*type_token == ' ')
      ++type_token;

    if (strcmp(type_token, "kline") == 0)
      shared->type |= SHARED_KLINE;
    else if (strcmp(type_token, "unkline") == 0)
      shared->type |= SHARED_UNKLINE;
    else if (strcmp(type_token, "dline") == 0)
      shared->type |= SHARED_DLINE;
    else if (strcmp(type_token, "undline") == 0)
      shared->type |= SHARED_UNDLINE;
    else if (strcmp(type_token, "xline") == 0)
      shared->type |= SHARED_XLINE;
    else if (strcmp(type_token, "unxline") == 0)
      shared->type |= SHARED_UNXLINE;
    else if (strcmp(type_token, "resv") == 0)
      shared->type |= SHARED_RESV;
    else if (strcmp(type_token, "unresv") == 0)
      shared->type |= SHARED_UNRESV;
    else if (strcmp(type_token, "locops") == 0)
      shared->type |= SHARED_LOCOPS;
    else if (strcmp(type_token, "all") == 0)
      shared->type = SHARED_ALL;

    type_token = strtok(NULL, ",");
  }
  io_free(type_str);

  xmlFree(name);
  xmlFree(user);
  xmlFree(type);
}

static void
parse_gecos(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  xmlChar *reason = xmlGetProp(node, (const xmlChar *)"reason");
  if (!name)
    return;

  struct GecosItem *gecos = gecos_make();
  gecos->mask = io_strdup((const char *)name);
  gecos->reason = reason ? io_strdup((const char *)reason) : io_strdup(CONF_NOREASON);

  xmlFree(name);
  xmlFree(reason);
}

static void
parse_pseudo(xmlNodePtr node)
{
  xmlChar *command = xmlGetProp(node, (const xmlChar *)"command");
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  xmlChar *target = xmlGetProp(node, (const xmlChar *)"target");
  xmlChar *prepend = xmlGetProp(node, (const xmlChar *)"prepend");
  if (!command || !name || !target)
    return;

  pseudo_register((const char *)name, NULL, NULL, (const char *)prepend, (const char *)command);

  xmlFree(command);
  xmlFree(name);
  xmlFree(target);
  xmlFree(prepend);
}

static void
parse_kill(xmlNodePtr node)
{
  xmlChar *user = xmlGetProp(node, (const xmlChar *)"user");
  xmlChar *reason = xmlGetProp(node, (const xmlChar *)"reason");
  if (!user)
    return;

  struct MaskItem *conf = conf_make(CONF_KLINE);
  struct nuh_split nuh = { 0 };  /* Use correct struct name */
  nuh.nuhmask = (char *)user;
  nuh.nickptr = NULL;
  nuh.userptr = conf->user;
  nuh.hostptr = conf->host;
  nuh.nicksize = 0;
  nuh.usersize = sizeof(conf->user);
  nuh.hostsize = sizeof(conf->host);

  nuh_split(&nuh);

  conf->reason = reason ? io_strdup((const char *)reason) : io_strdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);

  xmlFree(user);
  xmlFree(reason);
}

static void
parse_deny(xmlNodePtr node)
{
  xmlChar *ip = xmlGetProp(node, (const xmlChar *)"ip");
  xmlChar *reason = xmlGetProp(node, (const xmlChar *)"reason");
  if (!ip)
    return;

  if (address_parse_netmask((const char *)ip, NULL, NULL) != HM_HOST)
  {
    struct MaskItem *conf = conf_make(CONF_DLINE);
    conf->host = io_strdup((const char *)ip);
    conf->reason = reason ? io_strdup((const char *)reason) : io_strdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }

  xmlFree(ip);
  xmlFree(reason);
}

static void
parse_exempt(xmlNodePtr node)
{
  xmlChar *ip = xmlGetProp(node, (const xmlChar *)"ip");
  if (!ip)
    return;

  if (address_parse_netmask((const char *)ip, NULL, NULL) != HM_HOST)
  {
    struct MaskItem *conf = conf_make(CONF_EXEMPT);
    conf->host = io_strdup((const char *)ip);
    add_conf_by_address(CONF_EXEMPT, conf);
  }

  xmlFree(ip);
}

static void
parse_resv(xmlNodePtr node)
{
  xmlChar *mask = xmlGetProp(node, (const xmlChar *)"mask");
  xmlChar *reason = xmlGetProp(node, (const xmlChar *)"reason");
  xmlChar *exempt = xmlGetProp(node, (const xmlChar *)"exempt");
  if (!mask)
    return;

  list_t exempt_list = { 0 };
  if (exempt)
  {
    char *exempt_str = io_strdup((const char *)exempt);
    char *exempt_mask = strtok(exempt_str, ",");
    while (exempt_mask)
    {
      while (*exempt_mask == ' ')
        exempt_mask++;

      list_add(io_strdup(exempt_mask), list_make_node(), &exempt_list);
      exempt_mask = strtok(NULL, ",");
    }
    io_free(exempt_str);
  }

  resv_make((const char *)mask,
            reason ? (const char *)reason : CONF_NOREASON,
            exempt ? &exempt_list : NULL);

  while (exempt_list.head)
  {
    list_node_t *node = exempt_list.head;
    io_free(node->data);
    list_remove(node, &exempt_list);
    list_free_node(node);
  }

  xmlFree(mask);
  xmlFree(reason);
  xmlFree(exempt);
}

static void
parse_service(xmlNodePtr node)
{
  xmlChar *name = xmlGetProp(node, (const xmlChar *)"name");
  if (!name)
    return;

  if (server_valid_name((const char *)name))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup((const char *)name);
  }

  xmlFree(name);
}

/* Main parsing function */
static int
parse_xml_config(xmlDocPtr doc, bool cold)
{
  xmlNodePtr root = xmlDocGetRootElement(doc);
  if (!root)
    return XML_PARSE_ERROR_PARSE_FAILED;

  if (xmlStrcmp(root->name, (const xmlChar *)"ircd"))
  {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Root element is not 'ircd'");
    return XML_PARSE_ERROR_PARSE_FAILED;
  }

  /* Clear old configuration */
  if (!cold)
    conf_clear();

  /* Set default values */
  conf_set_defaults();

  /* Parse each section */
  for (xmlNodePtr node = root->children; node; node = node->next)
  {
    if (node->type != XML_ELEMENT_NODE)
      continue;

    if (xmlStrcmp(node->name, (const xmlChar *)"serverinfo") == 0)
      parse_serverinfo(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"admin") == 0)
      parse_admin(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"class") == 0)
      parse_class(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"channel") == 0)
      parse_channel(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"serverhide") == 0)
      parse_serverhide(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"log") == 0)
      parse_log(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"oper") == 0)
      parse_oper(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"listen") == 0)
      parse_listen(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"auth") == 0)
      parse_auth(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"connect") == 0)
      parse_connect(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"cluster") == 0)
      parse_cluster(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"shared") == 0)
      parse_shared(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"gecos") == 0)
      parse_gecos(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"pseudo") == 0)
      parse_pseudo(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"kill") == 0)
      parse_kill(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"deny") == 0)
      parse_deny(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"exempt") == 0)
      parse_exempt(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"resv") == 0)
      parse_resv(node);
    else if (xmlStrcmp(node->name, (const xmlChar *)"service") == 0)
      parse_service(node);
  }

  /* Validate configuration */
  conf_validate();

  return XML_PARSE_SUCCESS;
}

/* Public functions */
int
conf_xml_init(void)
{
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Initializing XML parser");
  xmlInitParser();
  xmlSetGenericErrorFunc(NULL, xml_error_handler);
  xmlSetStructuredErrorFunc(NULL, NULL);

  /* Load schema from embedded bytes */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Creating schema parser context");
  xmlSchemaParserCtxtPtr parser_ctx = xmlSchemaNewMemParserCtxt((const char *)_home_netcraveos_ircd_hybrid_etc_ircd_xsd, _home_netcraveos_ircd_hybrid_etc_ircd_xsd_len);
  if (!parser_ctx) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to create schema parser context");
    return XML_PARSE_ERROR_SCHEMA_INVALID;
  }

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Parsing schema");
  schema = xmlSchemaParse(parser_ctx);
  xmlSchemaFreeParserCtxt(parser_ctx);

  if (!schema) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to parse schema");
    return XML_PARSE_ERROR_SCHEMA_INVALID;
  }
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Schema parsed successfully");
  
  /* Dump schema for debugging */
  dump_schema_for_debugging();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Creating schema validation context");
  schema_valid_ctx = xmlSchemaNewValidCtxt(schema);
  if (!schema_valid_ctx) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to create schema validation context");
    xmlSchemaFree(schema);
    schema = NULL;
    return XML_PARSE_ERROR_SCHEMA_INVALID;
  }
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Schema validation context created successfully");

  /* Set validation options to stop after first error */
  xmlSchemaSetValidOptions(schema_valid_ctx, XML_SCHEMA_VAL_VC_I_CREATE);

  /* Set up error handlers */
  xmlSchemaSetValidStructuredErrors(schema_valid_ctx, xml_structured_error_handler, NULL);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "XML parser initialized successfully");
  return XML_PARSE_SUCCESS;
}

void
conf_xml_cleanup(void)
{
  if (schema_valid_ctx)
    xmlSchemaFreeValidCtxt(schema_valid_ctx);
  if (schema)
    xmlSchemaFree(schema);

  xmlCleanupParser();
}

/* Helper function to handle XML validation errors */
static void
handle_xml_validation_error(xmlDocPtr doc, int result)
{
  const struct _xmlError *error = xmlGetLastError();
  if (error) {
    /* Log a brief error description */
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Configuration validation failed: %s", 
              error->message ? error->message : "Unknown validation error");
    
    /* Log more verbose debug information */
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Validation error details: domain=%d, line=%d, column=%d, message=%s", 
              error->domain, error->line, error->int2, 
              error->message ? error->message : "Unknown validation error");
    
    /* Try to get more errors if available */
    int error_count = 1;
    while ((error = xmlGetLastError()) != NULL) {
      log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Additional error #%d: domain=%d, line=%d, column=%d, message=%s", 
                error_count++, error->domain, error->line, error->int2, 
                error->message ? error->message : "Unknown validation error");
    }
    
    /* Dump the XML document for debugging */
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Dumping XML document for debugging:");
    xmlDocPtr debug_doc = xmlCopyDoc(doc, 1);
    if (debug_doc) {
      xmlChar *debug_buffer;
      int debug_size;
      xmlDocDumpMemory(debug_doc, &debug_buffer, &debug_size);
      if (debug_buffer) {
        log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "XML content: %s", debug_buffer);
        xmlFree(debug_buffer);
      }
      xmlFreeDoc(debug_doc);
    }
  } else {
    /* If no error details are available, try to get more information */
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Generated configuration failed validation with error code: %d", result);
    
    /* Check if schema is loaded */
    if (!schema) {
      log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Schema is not loaded, validation cannot proceed");
    }
    
    /* Check if validation context is available */
    if (!schema_valid_ctx) {
      log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Schema validation context is not available");
    }
    
    /* Dump the XML document for debugging */
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Dumping XML document for debugging (no error details available):");
    xmlDocPtr debug_doc = xmlCopyDoc(doc, 1);
    if (debug_doc) {
      xmlChar *debug_buffer;
      int debug_size;
      xmlDocDumpMemory(debug_doc, &debug_buffer, &debug_size);
      if (debug_buffer) {
        log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "XML content: %s", debug_buffer);
        xmlFree(debug_buffer);
      }
      xmlFreeDoc(debug_doc);
    }
  }
}

/* Helper function to check schema validation status */
static bool
check_schema_validation_status(void)
{
  if (!schema) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Schema is not loaded, validation cannot proceed");
    return false;
  }
  
  if (!schema_valid_ctx) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Schema validation context is not available");
    return false;
  }
  
  return true;
}

int
conf_xml_parse(const char *filename, bool cold)
{
  xmlDocPtr doc = xmlReadFile(filename, NULL, XML_PARSE_NONET);
  if (!doc)
    return XML_PARSE_ERROR_FILE_NOT_FOUND;

  /* Validate against schema */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Validating XML document against schema");
  
  /* Check schema validation status */
  if (!check_schema_validation_status()) {
    xmlFreeDoc(doc);
    return XML_PARSE_ERROR_SCHEMA_INVALID;
  }
  
  /* Set validation options to stop after first error */
  xmlSchemaSetValidOptions(schema_valid_ctx, XML_SCHEMA_VAL_VC_I_CREATE);

  int result = xmlSchemaValidateDoc(schema_valid_ctx, doc);
  
  if (result != 0) {
    handle_xml_validation_error(doc, result);
    xmlFreeDoc(doc);
    return XML_PARSE_ERROR_VALIDATION_FAILED;
  }
  
  xmlFreeDoc(doc);

  return parse_xml_config(doc, cold);
}

const char *
conf_xml_error_str(int error_code)
{
  switch (error_code)
  {
    case XML_PARSE_SUCCESS:
      return "Success";
    case XML_PARSE_ERROR_SCHEMA_INVALID:
      return "Invalid XML schema";
    case XML_PARSE_ERROR_FILE_NOT_FOUND:
      return "Configuration file not found";
    case XML_PARSE_ERROR_PARSE_FAILED:
      return "Failed to parse XML configuration";
    case XML_PARSE_ERROR_VALIDATION_FAILED:
      return "XML validation failed";
    default:
      return "Unknown error";
  }
}

/* Custom read function for xmlReadIO that matches the xmlInputReadCallback signature */
static int
custom_read_callback(void *context, char *buffer, int len)
{
  FILE *fp = (FILE *)context;
  size_t bytes_read = fread(buffer, 1, len, fp);
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "custom_read_callback: read %zu bytes", bytes_read);
  return (int)bytes_read;
}

/* Helper functions for configuration generation */
static void
write_xml_header(FILE *fp)
{
  fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(fp, "<!--\n");
  fprintf(fp, " * ircd-hybrid configuration file\n");
  fprintf(fp, " * Generated by conf_generate_default\n");
  fprintf(fp, " *\n");
  fprintf(fp, " * This file contains all configuration options for the ircd-hybrid IRC server.\n");
  fprintf(fp, " * Edit this file to customize your server settings.\n");
  fprintf(fp, " *\n");
  fprintf(fp, " * For more information, see the documentation at:\n");
  fprintf(fp, " * https://github.com/ircd-hybrid/ircd-hybrid/wiki\n");
  fprintf(fp, " -->\n\n");
  fprintf(fp, "<ircd xmlns=\"http://www.ultra-ircd.org/ircd\">\n\n");
}

static void
write_module_base_path(FILE *fp)
{
  fprintf(fp, "  <!-- Module Base Path Configuration -->\n");
  fprintf(fp, "  <module_base_path\n");
  fprintf(fp, "    path=\"%s/modules\"\n", LIBPATH);
  fprintf(fp, "  />\n\n");
}

static void
write_serverinfo(FILE *fp)
{
  fprintf(fp, "  <!-- Server Information -->\n");
  fprintf(fp, "  <serverinfo\n");
  fprintf(fp, "    name=\"irc.example.com\"\n");
  fprintf(fp, "    sid=\"001\"\n");
  fprintf(fp, "    description=\"Example IRC Server\"\n");
  fprintf(fp, "    network_name=\"Example Network\"\n");
  fprintf(fp, "    network_description=\"A network of IRC servers\"\n");
  fprintf(fp, "    default_max_clients=\"100\"\n");
  fprintf(fp, "    max_nick_length=\"30\"\n");
  fprintf(fp, "    max_topic_length=\"300\"\n");
  fprintf(fp, "    hub=\"no\"\n");
  fprintf(fp, "    motd_file=\"/etc/ircd-hybrid/motd\"\n");
  fprintf(fp, "    rsa_private_key_file=\"/etc/ircd-hybrid/ircd.key\"\n");
  fprintf(fp, "    tls_certificate_file=\"/etc/ircd-hybrid/ircd.crt\"\n");
  fprintf(fp, "    tls_dh_param_file=\"/etc/ircd-hybrid/dh.pem\"\n");
  fprintf(fp, "    tls_supported_groups=\"X25519:P-256:P-384\"\n");
  fprintf(fp, "    tls_cipher_list=\"ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384\"\n");
  fprintf(fp, "    tls_cipher_suites=\"TLS_AES_256_GCM-SHA384:TLS_CHACHA20_POLY1305_SHA256\"\n");
  fprintf(fp, "    tls_message_digest_algorithm=\"SHA256\"\n");
  fprintf(fp, "  />\n\n");
}

static void
write_admin_info(FILE *fp)
{
  fprintf(fp, "  <!-- Admin Information -->\n");
  fprintf(fp, "  <admin\n");
  fprintf(fp, "    name=\"Example Admin\"\n");
  fprintf(fp, "    description=\"Example IRC Network Administrator\"\n");
  fprintf(fp, "    email=\"admin@example.com\"\n");
  fprintf(fp, "  />\n\n");
}

static void
write_class_config(FILE *fp)
{
  fprintf(fp, "  <!-- Class Configuration -->\n");
  fprintf(fp, "  <class\n");
  fprintf(fp, "    name=\"users\"\n");
  fprintf(fp, "    ping_time=\"90 seconds\"\n");
  fprintf(fp, "    connectfreq=\"60 seconds\"\n");
  fprintf(fp, "    max_number=\"100\"\n");
  fprintf(fp, "    sendq=\"1 megabyte\"\n");
  fprintf(fp, "    recvq=\"1 megabyte\"\n");
  fprintf(fp, "    max_channels=\"20\"\n");
  fprintf(fp, "    max_perip_local=\"3\"\n");
  fprintf(fp, "    max_perip_global=\"5\"\n");
  fprintf(fp, "    min_idle=\"30 minutes\"\n");
  fprintf(fp, "    max_idle=\"120 minutes\"\n");
  fprintf(fp, "    cidr_bitlen_ipv4=\"24\"\n");
  fprintf(fp, "    cidr_bitlen_ipv6=\"64\"\n");
  fprintf(fp, "    number_per_cidr=\"3\"\n");
  fprintf(fp, "    random_idle=\"yes\"\n");
  fprintf(fp, "    hide_idle_from_opers=\"no\"\n");
  fprintf(fp, "  />\n\n");

  fprintf(fp, "  <class\n");
  fprintf(fp, "    name=\"opers\"\n");
  fprintf(fp, "    ping_time=\"90 seconds\"\n");
  fprintf(fp, "    connectfreq=\"60 seconds\"\n");
  fprintf(fp, "    max_number=\"20\"\n");
  fprintf(fp, "    sendq=\"5 megabytes\"\n");
  fprintf(fp, "    recvq=\"5 megabytes\"\n");
  fprintf(fp, "    max_channels=\"100\"\n");
  fprintf(fp, "    max_perip_local=\"5\"\n");
  fprintf(fp, "    max_perip_global=\"10\"\n");
  fprintf(fp, "    min_idle=\"30 minutes\"\n");
  fprintf(fp, "    max_idle=\"120 minutes\"\n");
  fprintf(fp, "    cidr_bitlen_ipv4=\"24\"\n");
  fprintf(fp, "    cidr_bitlen_ipv6=\"64\"\n");
  fprintf(fp, "    number_per_cidr=\"5\"\n");
  fprintf(fp, "    random_idle=\"yes\"\n");
  fprintf(fp, "    hide_idle_from_opers=\"no\"\n");
  fprintf(fp, "  />\n\n");

  fprintf(fp, "  <class\n");
  fprintf(fp, "    name=\"servers\"\n");
  fprintf(fp, "    ping_time=\"90 seconds\"\n");
  fprintf(fp, "    connectfreq=\"60 seconds\"\n");
  fprintf(fp, "    max_number=\"10\"\n");
  fprintf(fp, "    sendq=\"10 megabytes\"\n");
  fprintf(fp, "    recvq=\"10 megabytes\"\n");
  fprintf(fp, "    max_channels=\"0\"\n");
  fprintf(fp, "    max_perip_local=\"0\"\n");
  fprintf(fp, "    max_perip_global=\"0\"\n");
  fprintf(fp, "    min_idle=\"30 minutes\"\n");
  fprintf(fp, "    max_idle=\"120 minutes\"\n");
  fprintf(fp, "    cidr_bitlen_ipv4=\"24\"\n");
  fprintf(fp, "    cidr_bitlen_ipv6=\"64\"\n");
  fprintf(fp, "    number_per_cidr=\"0\"\n");
  fprintf(fp, "    random_idle=\"yes\"\n");
  fprintf(fp, "    hide_idle_from_opers=\"no\"\n");
  fprintf(fp, "  />\n\n");
}

static void
write_channel_config(FILE *fp)
{
  fprintf(fp, "  <!-- Channel Configuration -->\n");
  fprintf(fp, "  <channel\n");
  fprintf(fp, "    max_bans=\"100\"\n");
  fprintf(fp, "    max_bans_large=\"200\"\n");
  fprintf(fp, "    max_invites=\"100\"\n");
  fprintf(fp, "    max_kick_length=\"200\"\n");
  fprintf(fp, "    max_channels=\"20\"\n");
  fprintf(fp, "    invite_client_count=\"20\"\n");
  fprintf(fp, "    invite_client_time=\"60 seconds\"\n");
  fprintf(fp, "    invite_delay_channel=\"30 seconds\"\n");
  fprintf(fp, "    invite_expire_time=\"1 day\"\n");
  fprintf(fp, "    knock_client_count=\"20\"\n");
  fprintf(fp, "    knock_client_time=\"60 seconds\"\n");
  fprintf(fp, "    knock_delay_channel=\"30 seconds\"\n");
  fprintf(fp, "    default_join_flood_count=\"10\"\n");
  fprintf(fp, "    default_join_flood_time=\"10 seconds\"\n");
  fprintf(fp, "    disable_fake_channels=\"no\"\n");
  fprintf(fp, "    enable_extbans=\"yes\"\n");
  fprintf(fp, "    enable_owner=\"yes\"\n");
  fprintf(fp, "    enable_admin=\"yes\"\n");
  fprintf(fp, "  />\n\n");
}

static void
write_serverhide_config(FILE *fp)
{
  fprintf(fp, "  <!-- Server Hiding Configuration -->\n");
  fprintf(fp, "  <serverhide\n");
  fprintf(fp, "    flatten_links=\"no\"\n");
  fprintf(fp, "    flatten_links_delay=\"30 seconds\"\n");
  fprintf(fp, "    flatten_links_file=\"/etc/ircd-hybrid/flatten_links.conf\"\n");
  fprintf(fp, "    disable_remote_commands=\"no\"\n");
  fprintf(fp, "    hide_servers=\"no\"\n");
  fprintf(fp, "    hide_services=\"no\"\n");
  fprintf(fp, "    hidden=\"no\"\n");
  fprintf(fp, "    hidden_name=\"irc.example.com\"\n");
  fprintf(fp, "    hide_server_ips=\"yes\"\n");
  fprintf(fp, "  />\n\n");
}

static void
write_logging_config(FILE *fp)
{
  fprintf(fp, "  <!-- Logging Configuration -->\n");
  fprintf(fp, "  <log use_logging=\"yes\">\n");
  fprintf(fp, "    <file\n");
  fprintf(fp, "      name=\"stderr\"\n");
  fprintf(fp, "      type=\"user\"\n");
  fprintf(fp, "      severity=\"info\"\n");
  fprintf(fp, "      size=\"10 megabytes\"\n");
  fprintf(fp, "    />\n");
  fprintf(fp, "    <file\n");
  fprintf(fp, "      name=\"stderr\"\n");
  fprintf(fp, "      type=\"operator\"\n");
  fprintf(fp, "      severity=\"info\"\n");
  fprintf(fp, "      size=\"10 megabytes\"\n");
  fprintf(fp, "    />\n");
  fprintf(fp, "    <file\n");
  fprintf(fp, "      name=\"stderr\"\n");
  fprintf(fp, "      type=\"debug\"\n");
  fprintf(fp, "      severity=\"debug\"\n");
  fprintf(fp, "      size=\"10 megabytes\"\n");
  fprintf(fp, "    />\n");
  fprintf(fp, "    <file\n");
  fprintf(fp, "      name=\"stderr\"\n");
  fprintf(fp, "      type=\"xline\"\n");
  fprintf(fp, "      severity=\"info\"\n");
  fprintf(fp, "      size=\"10 megabytes\"\n");
  fprintf(fp, "    />\n");
  fprintf(fp, "  </log>\n\n");
}

static void
write_xml_footer(FILE *fp)
{
  fprintf(fp, "</ircd>\n");
}

bool
conf_generate_default(const char *filename)
{
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "conf_generate_default: starting with filename=%s", 
            filename ? filename : "NULL (stdout)");
  
  /* Check if schema is loaded, if not, initialize it */
  if (!schema || !schema_valid_ctx) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Schema not loaded, initializing XML parser");
    int result = conf_xml_init();
    if (result != XML_PARSE_SUCCESS) {
      log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to initialize XML parser: %s", 
                conf_xml_error_str(result));
      return false;
    }
  }
  
  FILE *fp = filename ? fopen(filename, "w") : stdout;
  if (!fp) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to open output file: %s", strerror(errno));
    return false;
  }
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Output file opened successfully");

  /* Create a buffer to store the configuration */
  char *config_buffer = NULL;
  size_t buffer_size = 0;
  FILE *buffer_fp = open_memstream(&config_buffer, &buffer_size);
  if (!buffer_fp) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to allocate memory for configuration buffer: %s", strerror(errno));
    if (filename)
      fclose(fp);
    return false;
  }
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Memory buffer created successfully");

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Generating default configuration...");

  /* Write configuration to the buffer */
  write_xml_header(buffer_fp);
  write_module_base_path(buffer_fp);
  write_serverinfo(buffer_fp);
  write_admin_info(buffer_fp);
  write_class_config(buffer_fp);
  write_channel_config(buffer_fp);
  write_serverhide_config(buffer_fp);
  write_logging_config(buffer_fp);
  write_xml_footer(buffer_fp);
  
  /* Close the buffer file to finalize the string */
  fclose(buffer_fp);
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Configuration buffer generated, size: %zu bytes", buffer_size);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Configuration generation complete, validating against schema...");
  
  /* Create a memory stream for validation */
  FILE *validation_stream = fmemopen(config_buffer, buffer_size, "r");
  if (!validation_stream) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to create memory stream for validation: %s", strerror(errno));
    free(config_buffer);
    if (filename)
      fclose(fp);
    return false;
  }
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Memory stream created for validation");
  
  /* Parse the XML from memory stream using our custom read function */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Parsing XML from memory stream");
  xmlDocPtr doc = xmlReadIO(custom_read_callback, 
                           (xmlInputCloseCallback)fclose, 
                           validation_stream, 
                           NULL, 
                           NULL, 
                           XML_PARSE_NONET);
  
  if (!doc) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to parse generated configuration: %s", 
              xmlGetLastError() ? xmlGetLastError()->message : "Unknown error");
    free(config_buffer);
    if (filename)
      fclose(fp);
    return false;
  }
  
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "XML document parsed successfully");
  
  /* Validate against schema */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Validating XML document against schema");
  
  /* Check schema validation status */
  if (!check_schema_validation_status()) {
    xmlFreeDoc(doc);
    free(config_buffer);
    if (filename)
      fclose(fp);
    return false;
  }
  
  /* Set validation options to stop after first error */
  xmlSchemaSetValidOptions(schema_valid_ctx, XML_SCHEMA_VAL_VC_I_CREATE);

  int result = xmlSchemaValidateDoc(schema_valid_ctx, doc);
  
  if (result != 0) {
    handle_xml_validation_error(doc, result);
    xmlFreeDoc(doc);
    free(config_buffer);
    if (filename)
      fclose(fp);
    return false;
  }
  
  xmlFreeDoc(doc);
  
  /* Write the validated configuration to the output file */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Writing validated configuration to output");
  if (fwrite(config_buffer, 1, buffer_size, fp) != buffer_size) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to write configuration to output: %s", strerror(errno));
    free(config_buffer);
    if (filename)
      fclose(fp);
    return false;
  }
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Configuration written to output successfully");
  
  /* Clean up */
  free(config_buffer);
  
  if (filename)
    fclose(fp);
  else
    fflush(stdout);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Default configuration successfully generated%s", 
            filename ? " and written to file" : " and written to stdout");

  return true;
}

/* Helper function to dump schema for debugging */
static void
dump_schema_for_debugging(void)
{
  if (!schema) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Cannot dump schema: schema is not loaded");
    return;
  }
  
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Dumping schema for debugging:");
  
  /* Instead of trying to access the internal structure, we'll just log that the schema is loaded */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Schema is loaded and available for validation");
  
  /* We can't directly access the schema document, so we'll just log that we're using the embedded schema */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "Using embedded schema from _home_netcraveos_ircd_hybrid_etc_ircd_xsd");
} 