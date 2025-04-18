/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015-2025 ircd-hybrid development team
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

/*! \file m_svstag.c
 * \brief Includes required functions for processing the SVSTAG command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "io_string.h"


/*! \brief SVSTAG command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = TS
 *      - parv[3] = [-][raw]
 *      - parv[4] = required user mode(s) to see the tag
 *      - parv[5] = tag line
 */
static void
ms_svstag(struct Client *source, int parc, char *parv[])
{
  if (!HasFlag(source, FLAGS_SERVICE) && !IsServer(source))
    return;

  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
    return;

  uintmax_t ts = strtoumax(parv[2], NULL, 10);
  if (ts && (ts != target->tsinfo))
    return;

  if (strcmp(parv[3], "-") == 0)
  {
    svstag_clear_list(&target->svstags);
    sendto_servers(source, 0, 0, ":%s SVSTAG %s %ju -",
                   source->id, target->id, target->tsinfo);
    return;
  }

  if (string_is_empty(parv[5]))
    return;

  svstag_attach(&target->svstags, strtoul(parv[3], NULL, 10), parv[4], parv[5]);

  sendto_servers(source, 0, 0, ":%s SVSTAG %s %ju %s %s :%s",
                 source->id, target->id, target->tsinfo, parv[3], parv[4], parv[5]);
}

static struct Command command_table =
{
  .name = "SVSTAG",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svstag, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
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
