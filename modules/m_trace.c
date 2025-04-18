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

/*! \file m_trace.c
 * \brief Includes required functions for processing the TRACE command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "io_string.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "user_mode.h"
#include "parse.h"
#include "module.h"
#include "conf.h"
#include "conf_class.h"


static void
trace_get_dependent(unsigned int *const servers,
                    unsigned int *const clients, const struct Client *target)
{
  (*servers)++;
  (*clients) += list_length(&target->serv->client_list);

  list_node_t *node;
  LIST_FOREACH(node, target->serv->server_list.head)
    trace_get_dependent(servers, clients, node->data);
}

/* report_this_status()
 *
 * inputs       - pointer to client to report to
 *              - pointer to client to report about
 * output       - counter of number of hits
 * side effects - NONE
 */
static void
trace_send_status(struct Client *source, const struct Client *target)
{
  const char *name = client_get_name(target, HIDE_IP);
  const char *class_name = class_get_name(&target->connection->confs);

  switch (target->status)
  {
    case STAT_CONNECTING:
      sendto_one_numeric(source, &me, RPL_TRACECONNECTING,
                         class_name, user_mode_has_flag(source, UMODE_ADMIN) ? name : target->name);
      break;
    case STAT_HANDSHAKE:
      sendto_one_numeric(source, &me, RPL_TRACEHANDSHAKE,
                         class_name, user_mode_has_flag(source, UMODE_ADMIN) ? name : target->name);
      break;
    case STAT_ME:
      break;
    case STAT_UNKNOWN:
      sendto_one_numeric(source, &me, RPL_TRACEUNKNOWN,
                         class_name, name, target->sockhost,
                         io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->created_monotonic);
      break;
    case STAT_CLIENT:
      if (user_mode_has_flag(target, UMODE_OPER))
        sendto_one_numeric(source, &me, RPL_TRACEOPERATOR,
                           class_name, name, target->sockhost,
                           io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_data,
                           client_get_idle_time(source, target));
      else
        sendto_one_numeric(source, &me, RPL_TRACEUSER,
                           class_name, name, target->sockhost,
                           io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_data,
                           client_get_idle_time(source, target));
      break;
    case STAT_SERVER:
    {
      unsigned int servers = 0;
      unsigned int clients = 0;

      trace_get_dependent(&servers, &clients, target);

      if (user_mode_has_flag(source, UMODE_ADMIN) == false)
        name = client_get_name(target, MASK_IP);

      sendto_one_numeric(source, &me, RPL_TRACESERVER,
                         class_name, servers, clients, name,
                         target->serv->initiator_name ? target->serv->initiator_name : "*", "*",
                         me.name, io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_data);
      break;
    }

    default: /* ...we actually shouldn't come here... --msa */
      sendto_one_numeric(source, &me, RPL_TRACENEWTYPE, name);
      break;
  }
}

static void
do_trace(struct Client *source, const char *name)
{
  assert(user_mode_has_flag(source, UMODE_OPER));

  sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "TRACE requested by %s (%s@%s) [%s]",
                 source->name, source->username, source->host, source->servptr->name);

  bool doall = false;
  if (string_is_empty(name))
    doall = true;
  else if (match(name, me.name) == 0)
    doall = true;
  else if (!MyClient(source) && strcmp(name, me.id) == 0)
    doall = true;

  const list_node_t *node;
  const list_t *tab[] = { &local_client_list,
                          &local_server_list, &unknown_list, NULL };
  for (const list_t **list = tab; *list; ++list)
  {
    LIST_FOREACH(node, (*list)->head)
    {
      const struct Client *target = node->data;

      if (doall || match(name, target->name) == 0)
        trace_send_status(source, target);
    }
  }

  if (doall)
  {
    LIST_FOREACH(node, class_get_list()->head)
    {
      const struct ClassItem *class = node->data;

      if (class->ref_count)
        sendto_one_numeric(source, &me, RPL_TRACECLASS, class->name, class->ref_count);
    }
  }

  sendto_one_numeric(source, &me, RPL_TRACEEND, me.name);
}

/*! \brief TRACE command handler
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
m_trace(struct Client *source, int parc, char *parv[])
{
  sendto_one_numeric(source, &me, RPL_TRACEEND, me.name);
}

/*! \brief TRACE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nick or server name to trace
 *      - parv[2] = nick or server name to forward the trace to
 */
static void
mo_trace(struct Client *source, int parc, char *parv[])
{
  if (parc > 2)
    if (server_route_command(source, ":%s TRACE %s :%s", 2, parv)->result != SERVER_ROUTE_ISME)
      return;

  const server_route_t *route = server_route_command(source, ":%s TRACE :%s", 1, parv);
  switch (route->result)
  {
    case SERVER_ROUTE_PASS:
      sendto_one_numeric(source, &me, RPL_TRACELINK,
                         IRCD_VERSION, route->target->name, route->target->from->name);
      break;
    case SERVER_ROUTE_ISME:
      do_trace(source, parv[1]);
      break;
    default:
      break;
  }
}

static struct Command command_table =
{
  .name = "TRACE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_trace },
  .handlers[SERVER_HANDLER] = { .handler = mo_trace },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_trace }
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
