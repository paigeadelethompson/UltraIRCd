/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2025 ircd-hybrid development team
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

/*! \file m_post.c
 * \brief Includes required functions for processing the POST/GET/PUT command.
 */

#include "stdinc.h"
#include "misc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "module.h"


/*! \brief GET/POST/PUT command handler
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
mr_dumb_proxy(struct Client *source, int parc, char *parv[])
{
  sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "HTTP Proxy disconnected: [%s@%s]",
                 source->username, source->host);
  client_exit(source, "Client Exit");
}

static struct Command command_table[] =
{
  [0] = {
    .name = "GET",
    .handlers[UNREGISTERED_HANDLER] = { .handler = mr_dumb_proxy },
    .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
    .handlers[SERVER_HANDLER] = { .handler = m_ignore },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = m_ignore }
  },
  [1] = {
    .name = "POST",
    .handlers[UNREGISTERED_HANDLER] = { .handler = mr_dumb_proxy },
    .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
    .handlers[SERVER_HANDLER] = { .handler = m_ignore },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = m_ignore }
  },
  [2] = {
    .name = "PUT",
    .handlers[UNREGISTERED_HANDLER] = { .handler = mr_dumb_proxy },
    .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
    .handlers[SERVER_HANDLER] = { .handler = m_ignore },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = m_ignore }
  }
};

static void
init_handler(void)
{
  command_add_array(command_table, IO_ARRAY_LENGTH(command_table));
}

static void
exit_handler(void)
{
  command_del_array(command_table, IO_ARRAY_LENGTH(command_table));
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
