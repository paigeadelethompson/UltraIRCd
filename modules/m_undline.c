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

/*! \file m_undline.c
 * \brief Includes required functions for processing the UNDLINE command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "io_string.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_shared.h"
#include "ircd.h"
#include "address.h"
#include "numeric.h"
#include "log.h"
#include "send.h"
#include "server_capab.h"
#include "parse.h"
#include "module.h"
#include "memory.h"
#include "aline.h"


/* static int remove_tdline_match(const char *host, const char *user)
 * Input: An ip to undline.
 * Output: returns YES on success, NO if no tdline removed.
 * Side effects: Any matching tdlines are removed.
 */
static void
dline_remove(struct Client *source, const struct aline_ctx *aline)
{
  struct io_addr iphost, *piphost;
  struct MaskItem *conf;

  if (address_parse_netmask(aline->host, &iphost, NULL) != HM_HOST)
    piphost = &iphost;
  else
    piphost = NULL;

  if ((conf = find_conf_by_address(NULL, piphost, CONF_DLINE, NULL, NULL, 0)) == NULL)
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":No D-Line for [%s] found", aline->host);
    return;
  }

  if (!IsConfDatabase(conf))
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":The D-Line for [%s] is in the configuration file and must be removed by hand",
                        conf->host);
    return;
  }

  if (IsClient(source))
    sendto_one_notice(source, &me, ":D-Line for [%s] is removed",
                      conf->host);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s has removed the D-Line for: [%s]",
                 get_oper_name(source), conf->host);
  log_write(LOG_TYPE_DLINE, LOG_SEVERITY_INFO, "%s removed D-Line for [%s]",
            get_oper_name(source), conf->host);

  delete_one_address_conf(aline->host, conf);
}

/*! \brief UNDLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = IP address
 *      - parv[2] = "ON"
 *      - parv[3] = target server
 */
static void
mo_undline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = false, .simple_mask = false };

  if (!HasOFlag(source, OPER_FLAG_UNDLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "undline");
    return;
  }

  if (aline_parse("UNDLINE", source, parc, parv, &aline) == false)
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_UNDLN, "UNDLINE %s %s",
                       aline.server, aline.host);

    /* Allow ON to apply local undline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "UNDLINE", CAPAB_UNDLN, CLUSTER_UNDLINE, "%s",
                       aline.host);

  dline_remove(source, &aline);
}

/*! \brief UNDLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = IP address
 */
static void
ms_undline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = false,
    .simple_mask = false,
    .host = parv[2],
    .server = parv[1]
  };

  sendto_match_servs(source, aline.server, CAPAB_UNDLN, "UNDLINE %s %s",
                     aline.server, aline.host);

  if (match(aline.server, me.name))
    return;

  if (HasFlag(source, FLAGS_SERVICE) ||
      shared_find(SHARED_UNDLINE, source->servptr->name, source->username, source->host))
    dline_remove(source, &aline);
}

static struct Command command_table =
{
  .name = "UNDLINE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_undline, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_undline, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("UNDLN", CAPAB_UNDLN, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("UNDLN");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
