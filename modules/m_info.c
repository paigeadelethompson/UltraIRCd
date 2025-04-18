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

/*! \file m_info.c
 * \brief Includes required functions for processing the INFO command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "list.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "misc.h"
#include "server.h"
#include "send.h"
#include "user_mode.h"
#include "conf.h"
#include "parse.h"
#include "module.h"
#include "tls.h"
#include "info.h"

static const struct InfoEntry info_table[] =
{
  INFO_ENTRY_INIT("#define", "CPATH", INFO_OUTPUT_STRING, &ConfigGeneral.configfile, "Path to main configuration file"),
  INFO_ENTRY_INIT("#define", "DPATH", INFO_OUTPUT_STRING, &ConfigGeneral.dpath, "Root directory of installation"),
  INFO_ENTRY_INIT("#define", "SPATH", INFO_OUTPUT_STRING, &ConfigGeneral.spath, "Path to server executable"),
  INFO_ENTRY_INIT("#define, command-line", "DLPATH", INFO_OUTPUT_STRING, &ConfigGeneral.dlinefile, "Path to D-line database file"),
  INFO_ENTRY_INIT("#define, command-line", "KPATH", INFO_OUTPUT_STRING, &ConfigGeneral.klinefile, "Path to K-line database file"),
  INFO_ENTRY_INIT("#define, command-line", "RESVPATH", INFO_OUTPUT_STRING, &ConfigGeneral.resvfile, "Path to resv database file"),
  INFO_ENTRY_INIT("#define, command-line", "XPATH", INFO_OUTPUT_STRING, &ConfigGeneral.xlinefile, "Path to X-line database file"),
  INFO_ENTRY_INIT("admin", "description", INFO_OUTPUT_STRING, &ConfigAdminInfo.description, "Details of the institution, usually used for the admin's role"),
  INFO_ENTRY_INIT("admin", "email", INFO_OUTPUT_STRING, &ConfigAdminInfo.email, "Administrative contact email address"),
  INFO_ENTRY_INIT("admin", "name", INFO_OUTPUT_STRING, &ConfigAdminInfo.name, "Description of the server location (city, state, country), usually used for the admin's name"),
  INFO_ENTRY_INIT("channel", "default_join_flood_count", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.default_join_flood_count, "Startup value of JFLOODCOUNT"),
  INFO_ENTRY_INIT("channel", "default_join_flood_time", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.default_join_flood_time, "Startup value of JFLOODTIME"),
  INFO_ENTRY_INIT("channel", "disable_fake_channels", INFO_OUTPUT_BOOLEAN, &ConfigChannel.disable_fake_channels, "Forbids channels with special ASCII characters in their name"),
  INFO_ENTRY_INIT("channel", "enable_admin", INFO_OUTPUT_BOOLEAN, &ConfigChannel.enable_admin, "Enables channel prefix mode +a (channel admin)"),
  INFO_ENTRY_INIT("channel", "enable_extbans", INFO_OUTPUT_BOOLEAN, &ConfigChannel.enable_extbans, "Whether or not to enable extbans"),
  INFO_ENTRY_INIT("channel", "enable_owner", INFO_OUTPUT_BOOLEAN, &ConfigChannel.enable_owner, "Enables channel prefix mode +q (channel owner)"),
  INFO_ENTRY_INIT("channel", "invite_client_count", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.invite_client_count, "How many INVITE attempts are permitted in invite_client_time"),
  INFO_ENTRY_INIT("channel", "invite_client_time", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.invite_client_time, "How many invite_client_count invites are allowed in this time"),
  INFO_ENTRY_INIT("channel", "invite_delay_channel", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.invite_delay_channel, "Delay between INVITE attempts to a channel"),
  INFO_ENTRY_INIT("channel", "invite_expire_time", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.invite_expire_time, "Amount of time an INVITE will be active until it expires"),
  INFO_ENTRY_INIT("channel", "knock_client_count", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.knock_client_count, "How many KNOCK attempts are permitted in knock_client_time"),
  INFO_ENTRY_INIT("channel", "knock_client_time", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.knock_client_time, "How many knock_client_count knocks are allowed in this time"),
  INFO_ENTRY_INIT("channel", "knock_delay_channel", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.knock_delay_channel, "Delay between KNOCK attempts to a channel"),
  INFO_ENTRY_INIT("channel", "max_bans", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.max_bans, "Total +b/e/I modes allowed in a channel"),
  INFO_ENTRY_INIT("channel", "max_bans_large", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.max_bans_large, "Total +b/e/I modes allowed in a +L channel"),
  INFO_ENTRY_INIT("channel", "max_channels", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.max_channels, "Maximum number of channels a user can join"),
  INFO_ENTRY_INIT("channel", "max_invites", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.max_invites, "Maximum number of channels a user can be invited to"),
  INFO_ENTRY_INIT("channel", "max_kick_length", INFO_OUTPUT_UNSIGNED_INT, &ConfigChannel.max_kick_length, "Maximum length of a KICK message that the server will accept from a client"),
  INFO_ENTRY_INIT("general", "anti_nick_flood", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.anti_nick_flood, "NICK flood protection"),
  INFO_ENTRY_INIT("general", "anti_spam_exit_message_time", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.anti_spam_exit_message_time, "Duration a client must be connected for to have an exit message"),
  INFO_ENTRY_INIT("general", "away_count", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.away_count, "How many AWAY attempts are permitted in away_time"),
  INFO_ENTRY_INIT("general", "away_time", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.away_time, "How many away_count aways are allowed in this time"),
  INFO_ENTRY_INIT("general", "caller_id_wait", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.caller_id_wait, "Minimum delay between notifying UMODE +g users of messages"),
  INFO_ENTRY_INIT("general", "cloak_cidr_len_ipv4", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.cloak_cidr_len_ipv4, "CIDR length for IPv4 addresses used in hostname cloaking"),
  INFO_ENTRY_INIT("general", "cloak_cidr_len_ipv6", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.cloak_cidr_len_ipv6, "CIDR length for IPv6 addresses used in hostname cloaking"),
  INFO_ENTRY_INIT("general", "cloak_enabled", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.cloak_enabled, "Enable or disable hostname cloaking"),
  INFO_ENTRY_INIT("general", "cloak_num_bits", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.cloak_num_bits, "Number of bits for the MAC computation used in hostname cloaking"),
  INFO_ENTRY_INIT("general", "cloak_secret", INFO_OUTPUT_STRING_LITERAL, "<REDACTED>", "Secret key used in the MAC computation for hostname cloaking"),
  INFO_ENTRY_INIT("general", "cloak_suffix", INFO_OUTPUT_STRING, &ConfigGeneral.cloak_suffix, "Suffix appended to the cloaked hostname"),
  INFO_ENTRY_INIT("general", "cycle_on_host_change", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.cycle_on_host_change, "Send a fake QUIT/JOIN combination on host change"),
  INFO_ENTRY_INIT("general", "default_floodcount", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.default_floodcount, "Startup value of FLOODCOUNT"),
  INFO_ENTRY_INIT("general", "default_floodtime", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.default_floodtime, "Startup value of FLOODTIME"),
  INFO_ENTRY_INIT("general", "disable_auth", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.disable_auth, "Completely disable ident lookups"),
  INFO_ENTRY_INIT("general", "disable_dns", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.disable_dns, "Disable DNS lookups for client hostname resolution"),
  INFO_ENTRY_INIT("general", "dline_min_cidr", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.dline_min_cidr, "Minimum required length of a CIDR bitmask for IPv4 D-Lines"),
  INFO_ENTRY_INIT("general", "dline_min_cidr6", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.dline_min_cidr6, "Minimum required length of a CIDR bitmask for IPv6 D-Lines"),
  INFO_ENTRY_INIT("general", "failed_oper_notice", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.failed_oper_notice, "Inform opers if someone tries to /oper with the wrong credentials"),
  INFO_ENTRY_INIT("general", "ident_timeout", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.ident_timeout, "How long to wait for Ident replies"),
  INFO_ENTRY_INIT("general", "invisible_on_connect", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.invisible_on_connect, "Automatically set mode +i on connecting users"),
  INFO_ENTRY_INIT("general", "kill_chase_time_limit", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.kill_chase_time_limit, "Nick Change Tracker for KILL"),
  INFO_ENTRY_INIT("general", "kline_min_cidr", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.kline_min_cidr, "Minimum required length of a CIDR bitmask for IPv4 K-Lines"),
  INFO_ENTRY_INIT("general", "kline_min_cidr6", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.kline_min_cidr6, "Minimum required length of a CIDR bitmask for IPv6 K-Lines"),
  INFO_ENTRY_INIT("general", "max_accept", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.max_accept, "Maximum nicknames on accept list"),
  INFO_ENTRY_INIT("general", "max_away_length", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.max_away_length, "Maximum length of a AWAY message that the server will accept from a client"),
  INFO_ENTRY_INIT("general", "max_monitor", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.max_monitor, "Maximum nicknames on monitor list"),
  INFO_ENTRY_INIT("general", "max_nick_changes", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.max_nick_changes, "NICK change threshhold setting"),
  INFO_ENTRY_INIT("general", "max_nick_time", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.max_nick_time, "NICK flood protection time interval"),
  INFO_ENTRY_INIT("general", "max_targets", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.max_targets, "The maximum number of PRIVMSG/NOTICE targets"),
  INFO_ENTRY_INIT("general", "min_nonwildcard", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.min_nonwildcard, "Minimum non-wildcard chars in K/D lines"),
  INFO_ENTRY_INIT("general", "min_nonwildcard_simple", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.min_nonwildcard_simple, "Minimum non-wildcards in gecos bans"),
  INFO_ENTRY_INIT("general", "no_oper_flood", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.no_oper_flood, "Reduce flood control for operators"),
  INFO_ENTRY_INIT("general", "oper_umodes", INFO_OUTPUT_STRING, &ConfigGeneral.oper_umodes, "Default user modes assigned to operators upon successful OPER"),
  INFO_ENTRY_INIT("general", "opers_bypass_callerid", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.opers_bypass_callerid, "Allows IRC operators to message users who are +g (callerid)"),
  INFO_ENTRY_INIT("general", "pace_wait", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.pace_wait, "Minimum delay between uses of certain commands"),
  INFO_ENTRY_INIT("general", "pace_wait_simple", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.pace_wait_simple, "Minimum delay between less intensive commands"),
  INFO_ENTRY_INIT("general", "ping_cookie", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.ping_cookie, "Require ping cookies to connect"),
  INFO_ENTRY_INIT("general", "short_motd", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.short_motd, "Do not show MOTD; only tell clients they should read it"),
  INFO_ENTRY_INIT("general", "specials_in_ident", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.specials_in_ident, "Number of permissable '-', '_', or '.' characters in an ident"),
  INFO_ENTRY_INIT("general", "stats_P_oper_only", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.stats_P_oper_only, "STATS P output is only shown to operators"),
  INFO_ENTRY_INIT("general", "stats_e_disabled", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.stats_e_disabled, "Whether or not STATS e is disabled"),
  INFO_ENTRY_INIT("general", "stats_i_oper_only", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.stats_i_oper_only, "STATS I output is only shown to operators"),
  INFO_ENTRY_INIT("general", "stats_k_oper_only", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.stats_k_oper_only, "STATS K output is only shown to operators"),
  INFO_ENTRY_INIT("general", "stats_m_oper_only", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.stats_m_oper_only, "STATS m output is only shown to operators"),
  INFO_ENTRY_INIT("general", "stats_o_oper_only", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.stats_o_oper_only, "STATS O output is only shown to operators"),
  INFO_ENTRY_INIT("general", "stats_u_oper_only", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.stats_u_oper_only, "STATS u output is only shown to operators"),
  INFO_ENTRY_INIT("general", "throttle_count", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.throttle_count, "Number of connects in throttle_time before connections are blocked"),
  INFO_ENTRY_INIT("general", "throttle_time", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.throttle_time, "Minimum time between client reconnects"),
  INFO_ENTRY_INIT("general", "ts_max_delta", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.ts_max_delta, "Maximum permitted TS delta from another server"),
  INFO_ENTRY_INIT("general", "ts_warn_delta", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.ts_warn_delta, "Maximum permitted TS delta before displaying a warning"),
  INFO_ENTRY_INIT("general", "warn_no_connect_block", INFO_OUTPUT_BOOLEAN, &ConfigGeneral.warn_no_connect_block, "Display warning if connecting server lacks a connect{} block"),
  INFO_ENTRY_INIT("general", "whowas_history_length", INFO_OUTPUT_UNSIGNED_INT, &ConfigGeneral.whowas_history_length, "Length of the WHOWAS nick name history list"),
  INFO_ENTRY_INIT("log", "use_logging", INFO_OUTPUT_BOOLEAN, &ConfigLog.use_logging, "Enable logging"),
  INFO_ENTRY_INIT("serverhide", "disable_remote_commands", INFO_OUTPUT_BOOLEAN, &ConfigServerHide.disable_remote_commands, "Prevent users issuing commands on remote servers"),
  INFO_ENTRY_INIT("serverhide", "flatten_links", INFO_OUTPUT_BOOLEAN, &ConfigServerHide.flatten_links, "Flatten /links list"),
  INFO_ENTRY_INIT("serverhide", "flatten_links_delay", INFO_OUTPUT_UNSIGNED_INT, &ConfigServerHide.flatten_links_delay, "Links rehash delay"),
  INFO_ENTRY_INIT("serverhide", "flatten_links_file", INFO_OUTPUT_STRING, &ConfigServerHide.flatten_links_file, "Path to the flatten links cache file"),
  INFO_ENTRY_INIT("serverhide", "hidden", INFO_OUTPUT_BOOLEAN, &ConfigServerHide.hidden, "Hide this server from a flattened /links on remote servers"),
  INFO_ENTRY_INIT("serverhide", "hidden_name", INFO_OUTPUT_STRING, &ConfigServerHide.hidden_name, "Server name users see if hide_servers = yes"),
  INFO_ENTRY_INIT("serverhide", "hide_server_ips", INFO_OUTPUT_BOOLEAN, &ConfigServerHide.hide_server_ips, "Prevent people from seeing server IP addresses"),
  INFO_ENTRY_INIT("serverhide", "hide_servers", INFO_OUTPUT_BOOLEAN, &ConfigServerHide.hide_servers, "Hide servernames from users"),
  INFO_ENTRY_INIT("serverhide", "hide_services", INFO_OUTPUT_BOOLEAN, &ConfigServerHide.hide_services, "Hides the location of services server"),
  INFO_ENTRY_INIT("serverinfo", "default_max_clients", INFO_OUTPUT_UNSIGNED_INT, &ConfigServerInfo.default_max_clients, "The default maximum number of clients permitted simultaneously on this server"),
  INFO_ENTRY_INIT("serverinfo", "description", INFO_OUTPUT_STRING, &ConfigServerInfo.description, "Server description"),
  INFO_ENTRY_INIT("serverinfo", "hub", INFO_OUTPUT_BOOLEAN, &ConfigServerInfo.hub, "Server is a hub"),
  INFO_ENTRY_INIT("serverinfo", "max_nick_length", INFO_OUTPUT_UNSIGNED_INT, &ConfigServerInfo.max_nick_length, "Maximum nickname length"),
  INFO_ENTRY_INIT("serverinfo", "max_topic_length", INFO_OUTPUT_UNSIGNED_INT, &ConfigServerInfo.max_topic_length, "Maximum topic length"),
  INFO_ENTRY_INIT("serverinfo", "motd_file", INFO_OUTPUT_STRING, &ConfigServerInfo.motd_file, "Path to main motd (Message of the Day) file"),
  INFO_ENTRY_INIT("serverinfo", "name", INFO_OUTPUT_STRING, &ConfigServerInfo.name, "Server name"),
  INFO_ENTRY_INIT("serverinfo", "network_description", INFO_OUTPUT_STRING, &ConfigServerInfo.network_description, "Network description"),
  INFO_ENTRY_INIT("serverinfo", "network_name", INFO_OUTPUT_STRING, &ConfigServerInfo.network_name, "Network name"),
  INFO_ENTRY_INIT("serverinfo", "sid", INFO_OUTPUT_STRING, &ConfigServerInfo.sid, "Server ID")
};

static const char *const infotext[] =
{
  "ircd-hybrid --",
  "Based on the original code written by Jarkko Oikarinen",
  "Copyright (c) 1988-1991 University of Oulu, Computing Center",
  "Copyright (c) 1997-2025 ircd-hybrid development team",
  "",
  "This program is free software; you can redistribute it and/or",
  "modify it under the terms of the GNU General Public License as",
  "published by the Free Software Foundation; either version 2, or",
  "(at your option) any later version.",
  "",
  "",
  "The core team as of this major release:",
  "",
  "Dianora, Diane Bruce <db@db.net>",
  "Michael, Michael Wobst <michael@wobst.fr>",
  "Rodder, Jon Lusky <lusky@blown.net>",
  "Wohali, Joan Touzet <joant@ieee.org>",
  "",
  "The following people have contributed blood, sweat, and/or code to",
  "recent releases of ircd-hybrid, in nick alphabetical order:",
  "",
  "A1kmm, Andrew Miller <a1kmm@mware.virtualave.net>",
  "Adam, Adam <Adam@anope.org>",
  "Adrian Chadd <adrian@creative.net.au>",
  "adx, Piotr Nizynski <nizynski@sysplex.pl>",
  "AndroSyn, Aaron Sethman <androsyn@ratbox.org>",
  "bane, Dragan Dosen <bane@idolnet.org>",
  "billy-jon, William Bierman III <bill@thebiermans.org>",
  "bysin, Ben Kittridge <bkittridge@cfl.rr.com>",
  "cosine, Patrick Alken <wnder@uwns.underworld.net>",
  "cryogen, Stuart Walsh <stu@ipng.org.uk>",
  "David-T, David Taylor <davidt@yadt.co.uk>",
  "Dom, Dominic Hargreaves <dom@earth.li>",
  "Fawkes, Christoph Ostermeier <fawkes@phat-net.de>",
  "fgeek, Henri Salo <henri@nerv.fi>",
  "fl, Lee Hardy <lee@leeh.co.uk>",
  "Garion, Joost Vunderink <garion@efnet.nl>",
  "Habeeb, David Supuran <habeeb@cfl.rr.com>",
  "Hwy101, W. Campbell <wcampbel@botbay.net>",
  "jmallett, Juli Mallett <jmallett@FreeBSD.org>",
  "joshk, Joshua Kwan <joshk@triplehelix.org>",
  "jv, Jakub Vlasek <jv@pilsedu.cz>",
  "k9, Jeremy Chadwick <ircd@jdc.parodius.com>",
  "kire, Erik Small <smalle@hawaii.edu>",
  "knight, Alan LeVee <alan.levee@prometheus-designs.net>",
  "kre, Dinko Korunic <kreator@fly.srk.fer.hr>",
  "madmax, Paul Lomax <madmax@efnet.org>",
  "metalrock, Jack Low <xxjack12xx@gmail.com>",
  "r0d3nt, Andrew Strutt <andrew.strutt@gmail.com>",
  "Riedel, Dennis Vink <dennis@drvink.com>",
  "scuzzy, David Todd <scuzzy@aniverse.net>",
  "spookey, David Colburn <spookey@spookey.org>",
  "TimeMr14C, Yusuf Iskenderoglu <uhc0@stud.uni-karlsruhe.de>",
  "toot, Toby Verrall <to7@antipope.fsnet.co.uk>",
  "vx0, Mark Miller <mark@oc768.net>",
  "wiz, Jason Dambrosio <jason@wiz.cx>",
  "Xride, S\xC3\xB8ren Straarup <xride@x12.dk>",
  "zb^3, Alfred Perlstein <alfred@freebsd.org>",
  "",
  NULL
};

/* send_birthdate_online_time()
 *
 * inputs	- client pointer to send to
 * output	- NONE
 * side effects	- birthdate and online time are sent
 */
static void
send_birthdate_online_time(struct Client *client)
{
  sendto_one_numeric(client, &me, RPL_INFO | SND_EXPLICIT, ":On-line since %s",
                     date(me.connection->created_real));
}

/* send_info_text()
 *
 * inputs       - client pointer to send info text to
 * output       - NONE
 * side effects - info text is sent to client
 */
static void
send_info_text(struct Client *client)
{
  sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "INFO requested by %s (%s@%s) [%s]",
                 client->name, client->username, client->host, client->servptr->name);

  for (const char *const *text = infotext; *text; ++text)
  {
    const char *line = *text;
    if (*line == '\0')
      line = " ";

    sendto_one_numeric(client, &me, RPL_INFO, line);
  }

  if (user_mode_has_flag(client, UMODE_OPER))
  {
    info_send(client);

    if (tls_is_initialized())
      sendto_one_numeric(client, &me, RPL_INFO, tls_get_version());
  }

  send_birthdate_online_time(client);

  sendto_one_numeric(client, &me, RPL_ENDOFINFO);
}

/*! \brief INFO command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static void
m_info(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "INFO");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_route_command(source, ":%s INFO :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

  send_info_text(source);
}

/*! \brief INFO command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static void
ms_info(struct Client *source, int parc, char *parv[])
{
  if (server_route_command(source, ":%s INFO :%s", 1, parv)->result != SERVER_ROUTE_ISME)
    return;

  send_info_text(source);
}

static struct Command command_table =
{
  .name = "INFO",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_info },
  .handlers[SERVER_HANDLER] = { .handler = ms_info },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = ms_info }
};

static void
init_handler(void)
{
  info_register_array(info_table, IO_ARRAY_LENGTH(info_table));
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  info_unregister_array(info_table, IO_ARRAY_LENGTH(info_table));
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
