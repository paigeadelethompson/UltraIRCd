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

/*! \file m_whois.c
 * \brief Includes required functions for processing the WHOIS command.
 */

#include "stdinc.h"
#include "list.h"
#include "misc.h"
#include "module.h"
#include "io_string.h"
#include "io_time.h"
#include "client.h"
#include "client_svstag.h"
#include "hash.h"
#include "channel.h"
#include "channel_mode.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "server.h"
#include "user_mode.h"
#include "send.h"
#include "parse.h"
#include "ircd_hook.h"

/**
 * @enum whois_channel_visibility_t
 * @brief Enum for representing the visibility level of a channel in a WHOIS query.
 *
 * This enum defines the different levels of visibility for a channel when a WHOIS query is made.
 * Each value indicates the level of access the querying user has to the channel's information,
 * depending on their relationship to the channel and their user modes.
 */
typedef enum
{
  WHOIS_CHANNEL_VISIBILITY_FULL,  /**< Full visibility; no restrictions apply. Channel appears as "#channel". */
  WHOIS_CHANNEL_VISIBILITY_LIMITED,  /**< Channel is private (+p) or secret (+s). Channel appears as "?#channel". */
  WHOIS_CHANNEL_VISIBILITY_HIDDEN,  /**< Channel is hidden by the target's user mode (+p). Channel appears as "!#channel". */
  WHOIS_CHANNEL_VISIBILITY_NONE,  /**< Channel is not visible to the querying user. */
} whois_channel_visibility_t;

/**
 * @brief Determines the visibility level of a channel in a WHOIS query.
 *
 * This function evaluates the visibility level of a specified channel for a WHOIS query
 * based on the relationship between the source client, target client, and the channel's
 * properties. It returns a value indicating the level of access the querying user has
 * to the channel's information.
 *
 * @param channel A pointer to the Channel structure representing a channel in which the target client is a member.
 * @param source A pointer to the Client structure representing the querying user.
 * @param target A pointer to the Client structure representing the user being queried.
 * @return A whois_channel_visibility_t value indicating the visibility level of the channel.
*/
static whois_channel_visibility_t
whois_channel_visibility_get(struct Channel *channel, struct Client *source, struct Client *target)
{
  if (channel_is_public(channel) && user_mode_has_flag(target, UMODE_HIDECHANS) == false)
    return WHOIS_CHANNEL_VISIBILITY_FULL;

  if (source == target || member_find_link(source, channel))
    return WHOIS_CHANNEL_VISIBILITY_FULL;

  if (user_mode_has_flag(source, UMODE_OPER))
  {
    if (!channel_is_public(channel))
      return WHOIS_CHANNEL_VISIBILITY_LIMITED;
    /* user_mode_has_flag(target, UMODE_HIDECHANS) == true */
    return WHOIS_CHANNEL_VISIBILITY_HIDDEN;
  }

  return WHOIS_CHANNEL_VISIBILITY_NONE;
}

/* whois_person()
 *
 * inputs	- source client to report to
 *		- target client to report on
 * output	- NONE
 * side effects	- 
 */
static void
whois_send(struct Client *source, struct Client *target)
{
  list_node_t *node;

  sendto_one_numeric(source, &me, RPL_WHOISUSER,
                     target->name, target->username, target->host, target->info);

  if (user_mode_has_flag(source, UMODE_OPER) || source == target)
    sendto_one_numeric(source, &me, RPL_WHOISACTUALLY,
                       target->name, target->username, target->realhost, target->sockhost);

  if (list_length(&target->channel))
  {
    char buf[IRCD_BUFSIZE];
    char *bufptr = buf;

    /* :me.name 319 source->name target->name :~@#chan1 +#chan2 #chan3 ...\r\n */
    /* 1       23456            7            89                           0 1  */
    size_t len = strlen(target->name) + 11;

    if (MyConnect(source))
      len += strlen(me.name) + strlen(source->name);
    else
      len += IO_MAX(strlen(me.name), strlen(me.id)) + IO_MAX(strlen(source->name), strlen(source->id));

    LIST_FOREACH(node, target->channel.head)
    {
      const struct ChannelMember *member = node->data;
      whois_channel_visibility_t vis = whois_channel_visibility_get(member->channel, source, target);

      if (vis != WHOIS_CHANNEL_VISIBILITY_NONE)
      {
        if ((bufptr - buf) + member->channel->name_len + 1 + (vis != WHOIS_CHANNEL_VISIBILITY_FULL) + member_get_prefix_len(member, true) + len > sizeof(buf))
        {
          sendto_one_numeric(source, &me, RPL_WHOISCHANNELS, target->name, buf);
          bufptr = buf;
        }

        const char *channel_prefix = "";
        if (vis == WHOIS_CHANNEL_VISIBILITY_LIMITED)
          channel_prefix = "?";
        else if (vis == WHOIS_CHANNEL_VISIBILITY_HIDDEN)
          channel_prefix = "!";

        bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s%s%s" : "%s%s%s",
                           channel_prefix, member_get_prefix(member, true), member->channel->name);
      }
    }

    if (bufptr != buf)
      sendto_one_numeric(source, &me, RPL_WHOISCHANNELS, target->name, buf);
  }

  if ((ConfigServerHide.hide_servers || IsHidden(target->servptr)) &&
      !(user_mode_has_flag(source, UMODE_OPER) || source == target))
    sendto_one_numeric(source, &me, RPL_WHOISSERVER,
                       target->name, ConfigServerHide.hidden_name, ConfigServerInfo.network_description);
  else
    sendto_one_numeric(source, &me, RPL_WHOISSERVER,
                       target->name, target->servptr->name, target->servptr->info);

  if (target->away)
    sendto_one_numeric(source, &me, RPL_AWAY, target->name, target->away);

  if (user_mode_has_flag(target, UMODE_OPER) || HasFlag(target, FLAGS_SERVICE))
  {
    if (user_mode_has_flag(target, UMODE_HIDDEN) == false || user_mode_has_flag(source, UMODE_OPER))
    {
      const struct ServicesTag *svstag = list_peek_head(&target->svstags);
      if (svstag == NULL || svstag->numeric != RPL_WHOISOPERATOR)
      {
        const char *text;
        if (HasFlag(target, FLAGS_SERVICE))
          text = "is a Network Service";
        else if (user_mode_has_flag(target, UMODE_ADMIN))
          text = "is a Server Administrator";
        else  /* user_mode_has_flag(target, UMODE_OPER) == true */
          text = "is an IRC Operator";
        sendto_one_numeric(source, &me, RPL_WHOISOPERATOR, target->name, text);
      }
    }
  }

  LIST_FOREACH(node, target->svstags.head)
  {
    const struct ServicesTag *svstag = node->data;
    if (svstag->numeric == RPL_WHOISOPERATOR)
      if (user_mode_has_flag(target, UMODE_HIDDEN) && user_mode_has_flag(source, UMODE_OPER) == false)
        continue;

    if (svstag->umodes == 0 || user_mode_has_flag(source, svstag->umodes))
      sendto_one_numeric(source, &me, svstag->numeric | SND_EXPLICIT, "%s :%s",
                         target->name, svstag->tag);
  }

  if (user_mode_has_flag(source, UMODE_OPER) || source == target)
    sendto_one_numeric(source, &me, RPL_WHOISMODES,
                       target->name, user_mode_to_str(target->umodes));

  hook_dispatch(ircd_hook_whois_send, &(ircd_hook_whois_send_ctx){ .source = source, .target = target });

  if (MyConnect(target))
    if (user_mode_has_flag(target, UMODE_HIDEIDLE) == false || user_mode_has_flag(source, UMODE_OPER) || source == target)
      sendto_one_numeric(source, &me, RPL_WHOISIDLE,
                         target->name, client_get_idle_time(source, target), target->connection->created_real);
}

/* do_whois()
 *
 * inputs       - pointer to /whois source
 *              - number of parameters
 *              - pointer to parameters array
 * output       - pointer to void
 * side effects - Does whois
 */
static void
do_whois(struct Client *source, const char *name)
{
  struct Client *target = hash_find_client(name);

  if (target && IsClient(target))
    whois_send(source, target);
  else
    sendto_one_numeric(source, &me, ERR_NOSUCHNICK, name);

  sendto_one_numeric(source, &me, RPL_ENDOFWHOIS, name);
}

/*! \brief WHOIS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 *      - parv[2] = nickname
 */
static void
m_whois(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if (string_is_empty(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (!string_is_empty(parv[2]))
  {
    /* seeing as this is going across servers, we should limit it */
    if ((last_used + ConfigGeneral.pace_wait_simple) > io_time_get(IO_TIME_MONOTONIC_SEC))
    {
      sendto_one_numeric(source, &me, RPL_LOAD2HI, "WHOIS");
      return;
    }

    last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

    /*
     * if we have serverhide enabled, they can either ask the clients
     * server, or our server.. I don't see why they would need to ask
     * anything else for info about the client.. --fl_
     */
    if (ConfigServerHide.disable_remote_commands)
      parv[1] = parv[2];

    if (server_route_command(source, ":%s WHOIS %s :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

    parv[1] = parv[2];
  }

  do_whois(source, parv[1]);
}

/*! \brief WHOIS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 *      - parv[2] = nickname
 */
static void
mo_whois(struct Client *source, int parc, char *parv[])
{
  if (string_is_empty(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (!string_is_empty(parv[2]))
  {
    if (server_route_command(source, ":%s WHOIS %s :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

    parv[1] = parv[2];
  }

  do_whois(source, parv[1]);
}

static struct Command command_table =
{
  .name = "WHOIS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_whois },
  .handlers[SERVER_HANDLER] = { .handler = mo_whois },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_whois }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
