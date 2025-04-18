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

/*! \file m_kill.c
 * \brief Includes required functions for processing the KILL command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "server.h"
#include "conf.h"
#include "send.h"
#include "user_mode.h"
#include "whowas.h"
#include "io_string.h"
#include "parse.h"
#include "module.h"


/*! \brief KILL command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = kill victim
 *      - parv[2] = reason
 */
static void
mo_kill(struct Client *source, int parc, char *parv[])
{
  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
  {
    /*
     * If the user has recently changed nick, automatically
     * rewrite the KILL for this new nickname--this keeps
     * servers in synch when nick change and kill collide
     */
    target = whowas_get_history(parv[1], ConfigGeneral.kill_chase_time_limit);
    if (target == NULL)
    {
      sendto_one_numeric(source, &me, ERR_NOSUCHNICK, parv[1]);
      return;
    }

    sendto_one_notice(source, &me, ":KILL changed from %s to %s",
                      parv[1], target->name);
  }

  if (!MyConnect(target) && !HasOFlag(source, OPER_FLAG_KILL_REMOTE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "kill:remote");
    return;
  }

  if (MyConnect(target) && !HasOFlag(source, OPER_FLAG_KILL))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "kill");
    return;
  }

  if (IsServer(target) || IsMe(target))
  {
    sendto_one_numeric(source, &me, ERR_CANTKILLSERVER);
    return;
  }

  const char *reason = string_default(parv[2], CONF_NOREASON);
  if (MyConnect(target))
    sendto_one(target, ":%s!%s@%s KILL %s :%.*s",
               source->name, source->username, source->host,
               target->name, REASONLEN, reason);

  /*
   * Do not change the format of this message. There's no point in changing messages
   * that have been around for ever, for no reason..
   */
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Received KILL message for %s!%s@%s[%s]. From %s Path: %s (%.*s)",
                 target->name, target->username, target->host,
                 target->servptr->name, source->name, me.name, REASONLEN, reason);

  log_write(LOG_TYPE_KILL, LOG_SEVERITY_INFO, "KILL %s by %s (%s)",
            target->name, source->name, reason);

  /*
   * And pass on the message to other servers. Note, that if KILL was changed,
   * the message has to be sent to all links, also back.
   */
  if (!MyConnect(target))
  {
    sendto_servers(source, 0, 0, ":%s KILL %s :%s!%s!%s!%s (%.*s)",
                   source->id, target->id, me.name, source->host,
                   source->username, source->name, REASONLEN, reason);

    /*
     * Set FLAGS_KILLED. This prevents client_exit() from sending
     * the unnecessary QUIT for this. (This flag should never be
     * set in any other place)
     */
    AddFlag(target, FLAGS_KILLED);
  }

  client_exit_fmt(target, "Killed (%s (%.*s))", source->name, REASONLEN, reason);
}

/*! \brief KILL command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = kill victim
 *      - parv[2] = kill path and reason
 */
static void
ms_kill(struct Client *source, int parc, char *parv[])
{
  char def_reason[] = CONF_NOREASON;

  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
    return;

  char *reason = strchr(parv[2], ' ');
  if (reason)
    *reason++ = '\0';
  else
    reason = def_reason;

  if (IsServer(target) || IsMe(target))
  {
    sendto_one_numeric(source, &me, ERR_CANTKILLSERVER);
    return;
  }

  if (MyConnect(target))
  {
    if (IsServer(source))
    {
      /* Don't send clients kills from a hidden server */
      if ((IsHidden(source) || ConfigServerHide.hide_servers) && user_mode_has_flag(target, UMODE_OPER) == false)
        sendto_one(target, ":%s KILL %s :%s",
                   me.name, target->name, reason);
      else
        sendto_one(target, ":%s KILL %s :%s",
                   source->name, target->name, reason);
    }
    else
      sendto_one(target, ":%s!%s@%s KILL %s :%s",
                 source->name, source->username, source->host, target->name, reason);
  }

  /*
   * Be warned, this message must be From %s, or it confuses clients
   * so don't change it to From: or the case or anything! -- fl -- db
   */
  /*
   * Path must contain at least 2 !'s, or bitchx falsely declares it
   * local --fl
   */
  if (IsClient(source))  /* Send it normally */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Received KILL message for %s!%s@%s[%s]. From %s Path: %s!%s!%s!%s %s",
                   target->name, target->username, target->host,
                   target->servptr->name, source->name,
                   source->servptr->name, source->host, source->username, source->name, reason);
  else
    sendto_clients(UMODE_SKILL, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Received KILL message for %s!%s@%s[%s]. From %s %s",
                   target->name, target->username, target->host,
                   target->servptr->name, source->name, reason);

  log_write(LOG_TYPE_KILL, LOG_SEVERITY_INFO, "KILL %s by %s (%s)",
            target->name, source->name, reason);

  sendto_servers(source, 0, 0, ":%s KILL %s :%s %s",
                 source->id, target->id, parv[2], reason);
  AddFlag(target, FLAGS_KILLED);

  /* Reason comes supplied with its own ()'s */
  if (IsServer(source) && (IsHidden(source) || ConfigServerHide.hide_servers))
    client_exit_fmt(target, "Killed (%s %s)", me.name, reason);
  else
    client_exit_fmt(target, "Killed (%s %s)", source->name, reason);
}


static struct Command command_table =
{
  .name = "KILL",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_kill, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_kill, .args_min = 2 }
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
  .core = true
};
