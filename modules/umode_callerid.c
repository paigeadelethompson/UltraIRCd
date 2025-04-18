/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2025 ircd-hybrid development team
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

#include "module.h"
#include "stdinc.h"
#include "io_time.h"
#include "client.h"
#include "numeric.h"
#include "send.h"
#include "accept.h"
#include "conf.h"
#include "ircd_hook.h"
#include "isupport.h"
#include "user_mode.h"

static struct UserMode callerid_mode =
{
  .mode_char = 'g',
  .mode_flag = &UMODE_CALLERID
};

static hook_flow_t
msg_client_target_local_hook(void *ctx_)
{
  ircd_hook_msg_client_ctx *ctx = ctx_;

  if (user_mode_has_flag(ctx->target, UMODE_CALLERID) == false)
    return HOOK_FLOW_CONTINUE;

  if (accept_message(ctx->source, ctx->target))
    return HOOK_FLOW_CONTINUE;

  if (ctx->notice == false)
    sendto_one_numeric(ctx->source, &me, RPL_TARGUMODEG,
                       ctx->target->name, "+g", "server side ignore");

  if ((ctx->target->connection->last_caller_id_time +
       ConfigGeneral.caller_id_wait) < io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    if (ctx->notice == false)
      sendto_one_numeric(ctx->source, &me, RPL_TARGNOTIFY, ctx->target->name);

    sendto_one_numeric(ctx->target, &me, RPL_UMODEGMSG,
                       ctx->source->name, ctx->source->username, ctx->source->host, "+g");
    ctx->target->connection->last_caller_id_time = io_time_get(IO_TIME_MONOTONIC_SEC);
  }

  return HOOK_FLOW_STOP;
}

static hook_flow_t
whois_send_hook(void *ctx_)
{
  ircd_hook_whois_send_ctx *ctx = ctx_;

  if (user_mode_has_flag(ctx->target, UMODE_CALLERID) == false)
    return HOOK_FLOW_CONTINUE;

  sendto_one_numeric(ctx->source, &me, RPL_TARGUMODEG,
                     ctx->target->name, "+g", "server side ignore");
  return HOOK_FLOW_CONTINUE;
}

static void
init_handler(void)
{
  user_mode_register(&callerid_mode);
  hook_install(ircd_hook_msg_client_target_local, msg_client_target_local_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_whois_send, whois_send_hook, HOOK_PRIORITY_NORMAL);
  isupport_add("CALLERID", NULL);
}

static void
exit_handler(void)
{
  user_mode_unregister(&callerid_mode);
  hook_uninstall(ircd_hook_msg_client_target_local, msg_client_target_local_hook);
  hook_uninstall(ircd_hook_whois_send, whois_send_hook);
  isupport_delete("CALLERID");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
