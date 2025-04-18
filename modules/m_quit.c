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

/*! \file m_quit.c
 * \brief Includes required functions for processing the QUIT command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "client.h"
#include "ircd.h"
#include "io_string.h"
#include "parse.h"
#include "user_mode.h"
#include "module.h"
#include "conf.h"


/*! \brief QUIT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = quit message
 */
static void
m_quit(struct Client *source, int parc, char *parv[])
{
  const char *reason = "";

  if (!string_is_empty(parv[1]) && (user_mode_has_flag(source, UMODE_OPER) ||
      (source->connection->created_monotonic + ConfigGeneral.anti_spam_exit_message_time)
      < io_time_get(IO_TIME_MONOTONIC_SEC)))
    reason = parv[1];

  client_exit_fmt(source, "Quit: %.*s", KICKLEN, reason);
}

/*! \brief QUIT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = quit message
 */
static void
ms_quit(struct Client *source, int parc, char *parv[])
{
  const char *reason = string_default(parv[1], "");
  client_exit_fmt(source, "%.*s", KICKLEN, reason);
}

static struct Command command_table =
{
  .name = "QUIT",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_quit },
  .handlers[CLIENT_HANDLER] = { .handler = m_quit },
  .handlers[SERVER_HANDLER] = { .handler = ms_quit },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_quit }
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
