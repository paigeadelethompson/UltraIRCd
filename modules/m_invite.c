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

/*! \file m_invite.c
 * \brief Includes required functions for processing the INVITE command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "list.h"
#include "cap.h"
#include "channel.h"
#include "channel_invite.h"
#include "channel_mode.h"
#include "client.h"
#include "conf.h"
#include "hash.h"
#include "io_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "module.h"


static void
send_invite(struct Client *source, struct Client *target, struct Channel *channel)
{
  channel->last_invite_time = io_time_get(IO_TIME_MONOTONIC_SEC);

  if (MyConnect(target))
  {
    sendto_one(target, ":%s!%s@%s INVITE %s :%s",
               source->name, source->username, source->host, target->name, channel->name);

    if (channel_has_mode(channel, MODE_INVITEONLY))
      invite_add(channel, target);  /* Add the invite if channel is +i */
  }

  if (channel_has_mode(channel, MODE_INVITEONLY))
    sendto_channel_local(NULL, channel, CHACCESS_HALFOP, 0, CAP_INVITE_NOTIFY,
                         ":%s NOTICE %%%s :%s is inviting %s to %s.",
                         me.name, channel->name, source->name, target->name, channel->name);

  sendto_channel_local(NULL, channel, CHACCESS_HALFOP, CAP_INVITE_NOTIFY, 0, ":%s!%s@%s INVITE %s %s",
                       source->name, source->username, source->host, target->name, channel->name);
  sendto_servers(source, 0, 0, ":%s INVITE %s %s %ju",
                 source->id, target->id, channel->name, channel->creation_time);
}

/*! \brief INVITE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = user to invite
 *      - parv[2] = channel name
 */
static void
m_invite(struct Client *source, int parc, char *parv[])
{
  if (parc < 2)
  {
    list_node_t *node;
    LIST_FOREACH(node, source->connection->invited.head)
    {
      const struct Invite *const invite = node->data;
      sendto_one_numeric(source, &me, RPL_INVITELIST, invite->channel->name);
    }

    sendto_one_numeric(source, &me, RPL_ENDOFINVITELIST);
    return;
  }

  if (string_is_empty(parv[2]))
  {
    sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, "INVITE");
    return;
  }

  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHNICK, parv[1]);
    return;
  }

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, parv[2]);
    return;
  }

  struct ChannelMember *member = member_find_link(source, channel);
  if (member == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  if (member_highest_rank(member) < CHACCESS_HALFOP)
  {
    sendto_one_numeric(source, &me, ERR_CHANOPRIVSNEEDED, channel->name);
    return;
  }

  if (member_find_link(target, channel))
  {
    sendto_one_numeric(source, &me, ERR_USERONCHANNEL, target->name, channel->name);
    return;
  }

  if (channel_has_mode(channel, MODE_NOINVITE))
  {
    sendto_one_numeric(source, &me, ERR_NOINVITE, target->name, channel->name);
    return;
  }

  if ((source->connection->invite.last_attempt + ConfigChannel.invite_client_time) < io_time_get(IO_TIME_MONOTONIC_SEC))
    source->connection->invite.count = 0;

  if (source->connection->invite.count > ConfigChannel.invite_client_count)
  {
    sendto_one_numeric(source, &me, ERR_TOOMANYINVITE, channel->name, "user");
    return;
  }

  if ((channel->last_invite_time + ConfigChannel.invite_delay_channel) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, ERR_TOOMANYINVITE, channel->name, "channel");
    return;
  }

  source->connection->invite.last_attempt = io_time_get(IO_TIME_MONOTONIC_SEC);
  source->connection->invite.count++;

  sendto_one_numeric(source, &me, RPL_INVITING, target->name, channel->name);

  if (target->away)
    sendto_one_numeric(source, &me, RPL_AWAY, target->name, target->away);

  send_invite(source, target, channel);
}

/*! \brief INVITE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = user to invite
 *      - parv[2] = channel name
 *      - parv[3] = channel timestamp
 */
static void
ms_invite(struct Client *source, int parc, char *parv[])
{
  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
    return;

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
    return;

  if (member_find_link(target, channel))
    return;

  if (strtoumax(parv[3], NULL, 10) > channel->creation_time)
    return;

  send_invite(source, target, channel);
}

static struct Command command_table =
{
  .name = "INVITE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_invite, .end_grace_period = true },
  .handlers[SERVER_HANDLER] = { .handler = ms_invite, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_invite, .end_grace_period = true }
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
