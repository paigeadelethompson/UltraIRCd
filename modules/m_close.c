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

/*! \file m_close.c
 * \brief Includes required functions for processing the CLOSE command.
 */

#include "stdinc.h"
#include "list.h"
#include "module.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"

/*! \brief CLOSE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
mo_close(struct Client *source, int parc, char *parv[])
{
  if (!HasOFlag(source, OPER_FLAG_CLOSE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "close");
    return;
  }

  const unsigned int closed = list_length(&unknown_list);
  while (unknown_list.head)
  {
    struct Client *target = unknown_list.head->data;

    sendto_one_numeric(source, &me, RPL_CLOSING,
                       client_get_name(target, SHOW_IP), target->status);

    /*
     * Exit here is safe, because it is guaranteed not to be source
     * because it is unregistered and source is an oper.
     */
    client_exit(target, "Oper Closing");
  }

  sendto_one_numeric(source, &me, RPL_CLOSEEND, closed);
}

static struct Command command_table =
{
  .name = "CLOSE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_close }
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
