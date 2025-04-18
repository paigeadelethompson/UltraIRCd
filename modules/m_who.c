/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
 *  Copyright (c) 1997-1999 Andrea "Nemesi" Cocito
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

/*! \file m_who.c
 * \brief Includes required functions for processing the WHO command.
 */

#include "stdinc.h"
#include "address.h"
#include "list.h"
#include "module.h"
#include "io_string.h"
#include "io_time.h"
#include "cap.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "isupport.h"
#include "numeric.h"
#include "send.h"
#include "user_mode.h"
#include "ircd_hook.h"
#include "conf.h"
#include "parse.h"

/** Maximum number of lines to send in response to a /WHO. */
enum { WHO_MAX_REPLIES = 500 };

enum
{
  WHOSELECT_OPER  = 1 << 0,  /**< Flag for /WHO: Show IRC operators. */
  WHOSELECT_EXTRA = 1 << 1,  /**< Flag for /WHO: Pull rank to see users. */
  WHOSELECT_DELAY = 1 << 2,  /**< Flag for /WHO: Show join-delayed users. */
};

enum
{
  WHO_FIELD_QTO = 1 <<  0,  /**< Display query token. */
  WHO_FIELD_CHA = 1 <<  1,  /**< Show common channel name. */
  WHO_FIELD_UID = 1 <<  2,  /**< Show username. */
  WHO_FIELD_NIP = 1 <<  3,  /**< Show IP address. */
  WHO_FIELD_HOS = 1 <<  4,  /**< Show hostname. */
  WHO_FIELD_SER = 1 <<  5,  /**< Show server. */
  WHO_FIELD_NIC = 1 <<  6,  /**< Show nickname. */
  WHO_FIELD_FLA = 1 <<  7,  /**< Show flags (away, oper, chanop, etc). */
  WHO_FIELD_DIS = 1 <<  8,  /**< Show hop count (distance). */
  WHO_FIELD_REN = 1 <<  9,  /**< Show realname (info). */
  WHO_FIELD_IDL = 1 << 10,  /**< Show idle time. */
  WHO_FIELD_ACC = 1 << 11,  /**< Show account name. */
  WHO_FIELD_OPL = 1 << 12,  /**< Show oplevel. */
  /** Default fields for /WHO */
  WHO_FIELD_DEF = WHO_FIELD_NIC | WHO_FIELD_UID | WHO_FIELD_HOS | WHO_FIELD_SER,
};

struct WhoQuery
{
  unsigned int bitsel;  /**< User mode matching flags */
  unsigned int matchsel;  /**< Field matching flags */
  unsigned int fields;  /**< Fields to be shown in the output */
  unsigned int maxmatches;  /**< Maximum number of replies to be sent */
  const char *token;  /**< User-defined query token */
};


/*! \brief Send a WHO reply to a client who asked.
 * \param source Pointer to client requesting who.
 * \param target Client who is shown to \a source.
 * \param member ChannelMember pointer of a shared channel that provides visibility.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
who_send(struct Client *source, const struct Client *target,
         const struct ChannelMember *member, const struct WhoQuery *who)
{
  char buf[IRCD_BUFSIZE];
  char *p = buf;

  /*
   * NOTE: with current fields list and sizes this _cannot_ overrun,
   * and also the message finally sent shouldn't ever be truncated.
   */
  buf[1] = '\0';

  /* If we don't have a channel and we need one... try to find it. */
  if (member == NULL)
  {
    if (who->fields == 0 || (who->fields & (WHO_FIELD_CHA | WHO_FIELD_FLA)))
    {
      list_node_t *node;
      LIST_FOREACH(node, target->channel.head)
      {
        member = node->data;

        if (channel_is_public(member->channel) || source == target || member_find_link(source, member->channel))
          break;
        member = NULL;
      }
    }
  }

  /*
   * Place the fields in the buffer and send it. Note that who->fields == 0
   * means "default query".
   */

  if ((who->fields & WHO_FIELD_QTO))  /* Query token */
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", string_default(who->token, "0"));

  if (who->fields == 0 || (who->fields & WHO_FIELD_CHA))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", member ? member->channel->name : "*");

  if (who->fields == 0 || (who->fields & WHO_FIELD_UID))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->username);

  if ((who->fields & WHO_FIELD_NIP))
  {
    if (user_mode_has_flag(source, UMODE_OPER) || source == target)
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->sockhost);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", "255.255.255.255");
  }

  if (who->fields == 0 || (who->fields & WHO_FIELD_HOS))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->host);

  if (who->fields == 0 || (who->fields & WHO_FIELD_SER))
  {
    if (user_mode_has_flag(source, UMODE_OPER) == false &&
        (ConfigServerHide.hide_servers || IsHidden(target->servptr)))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", ConfigServerHide.hidden_name);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->servptr->name);
  }

  if (who->fields == 0 || (who->fields & WHO_FIELD_NIC))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->name);

  if (who->fields == 0 || (who->fields & WHO_FIELD_FLA))
  {
    char status[32] = { [0] = target->away ? 'G' : 'H' };

    ircd_hook_who_send_ctx ctx = { .source = source, .target = target };
    hook_dispatch(ircd_hook_who_send, &ctx);

    if (ctx.modes_len)
    {
      ctx.modes[ctx.modes_len] = '\0';
      strlcat(status, ctx.modes, sizeof(status));
    }

    if (member)
    {
      const char *prefix = member_get_prefix(member, who->fields || !!HasCap(source, CAP_MULTI_PREFIX));
      if (!string_is_empty(prefix))
        strlcat(status, prefix, sizeof(status));
    }

    p += snprintf(p, sizeof(buf) - (p - buf), " %s", status);
  }

  if (who->fields == 0 || (who->fields & WHO_FIELD_DIS))
  {
    if (user_mode_has_flag(source, UMODE_OPER) == false &&
        (ConfigServerHide.hide_servers || IsHidden(target->servptr)))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s%u", who->fields == 0 ? ":" : "", 0);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s%u", who->fields == 0 ? ":" : "", target->hopcount);
  }

  if ((who->fields & WHO_FIELD_IDL))
  {
    if (MyClient(target) &&
        (user_mode_has_flag(source, UMODE_OPER) || target == source))
      p += snprintf(p, sizeof(buf) - (p - buf), " %u", client_get_idle_time(source, target));
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %u", 0);
  }

  if ((who->fields & WHO_FIELD_ACC))
  {
    if (strcmp(target->account, "*"))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->account);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", "0");
  }

  if ((who->fields & WHO_FIELD_OPL))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", "n/a");

  if (who->fields == 0 || (who->fields & WHO_FIELD_REN))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s%s", who->fields ? ":" : "", target->info);
                                /* Place colon here for special reply ^ */

  sendto_one_numeric(source, &me, who->fields ? RPL_WHOSPCRPL : RPL_WHOREPLY, buf + 1);
}

/*!
 * \param source Pointer to client requesting who.
 * \param target Pointer to client to do who on.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 * \return true if mask matches, false otherwise.
 */
static bool
who_matches(struct Client *source, const struct Client *target,
            const char *mask, const struct WhoQuery *who)
{
  if ((who->bitsel & WHOSELECT_OPER))
    if (user_mode_has_flag(target, UMODE_OPER) == false ||
        (user_mode_has_flag(target, UMODE_HIDDEN) && user_mode_has_flag(source, UMODE_OPER) == false))
      return false;

  if (mask == NULL)
    return true;

  if ((who->matchsel & WHO_FIELD_NIC) && match(mask, target->name) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_UID) && match(mask, target->username) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_HOS))
  {
    if (match(mask, target->host) == 0)
      return true;
    if (user_mode_has_flag(source, UMODE_OPER) && match(mask, target->realhost) == 0)
      return true;
  }

  if ((who->matchsel & WHO_FIELD_REN) && match(mask, target->info) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_ACC) && match(mask, target->account) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_NIP) && user_mode_has_flag(source, UMODE_OPER))
  {
    struct io_addr addr;
    int bits = 0;
    const int ret = address_parse_netmask(mask, &addr, &bits);

    if (ret == HM_IPV4 || ret == HM_IPV6)
      if (address_match(&target->addr, &addr, false, false, bits))
        return true;

    if (match(mask, target->sockhost) == 0)
      return true;
  }

  if ((who->matchsel & WHO_FIELD_SER))
    if (user_mode_has_flag(source, UMODE_OPER) ||
        (ConfigServerHide.hide_servers == 0 && !IsHidden(target->servptr)))
      if (match(mask, target->servptr->name) == 0)
        return true;

  return false;
}

/*! \brief Lists matching clients on specified channel. Marks matched clients.
 * \param source Pointer to client requesting who.
 * \param channel Pointer to channel member chain.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
who_on_common_channel(struct Client *source, struct Channel *channel,
                      const char *mask, struct WhoQuery *who)
{
  list_node_t *node;

  LIST_FOREACH(node, channel->members.head)
  {
    struct ChannelMember *member = node->data;
    struct Client *target = member->client;

    if (user_mode_has_flag(target, UMODE_INVISIBLE) == false || HasFlag(target, FLAGS_MARK))
      continue;

    AddFlag(target, FLAGS_MARK);

    if (who->maxmatches)
    {
      if (who_matches(source, target, mask, who))
      {
        who_send(source, target, member, who);
        --who->maxmatches;
      }
    }
  }
}

/*! \brief Does a global scan of all clients looking for match.
 * \param source Pointer to client requesting who.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
who_global(struct Client *source, const char *mask, struct WhoQuery *who)
{
  static uintmax_t last_used = 0;

  if (user_mode_has_flag(source, UMODE_OPER) == false)
  {
    if ((last_used + ConfigGeneral.pace_wait) > io_time_get(IO_TIME_MONOTONIC_SEC))
    {
      sendto_one_numeric(source, &me, RPL_LOAD2HI, "WHO");
      return;
    }

    last_used = io_time_get(IO_TIME_MONOTONIC_SEC);
  }

  /* First, list all matching invisible clients on common channels */
  list_node_t *node;
  LIST_FOREACH(node, source->channel.head)
  {
    struct ChannelMember *member = node->data;
    who_on_common_channel(source, member->channel, mask, who);
  }

  /* Second, list all matching visible clients */
  LIST_FOREACH(node, global_client_list.head)
  {
    struct Client *target = node->data;

    assert(IsClient(target));

    if (user_mode_has_flag(target, UMODE_INVISIBLE))
    {
      DelFlag(target, FLAGS_MARK);
      continue;
    }

    if (who->maxmatches)
    {
      if (who_matches(source, target, mask, who))
      {
        who_send(source, target, NULL, who);
        --who->maxmatches;
      }
    }
  }
}

/*! \brief Does a WHO on given channel.
 * \param source Pointer to client requesting who.
 * \param channel Pointer to channel to do who on.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
who_on_channel(struct Client *source, struct Channel *channel, const struct WhoQuery *who)
{
  bool is_member = false;

  if (user_mode_has_flag(source, UMODE_ADMIN) || member_find_link(source, channel))
    is_member = true;
  else if (channel_has_mode(channel, MODE_SECRET))
    return;

  list_node_t *node;
  LIST_FOREACH(node, channel->members.head)
  {
    struct ChannelMember *member = node->data;
    struct Client *target = member->client;

    if (is_member || user_mode_has_flag(target, UMODE_INVISIBLE) == false)
    {
      if ((who->bitsel & WHOSELECT_OPER))
        if (user_mode_has_flag(target, UMODE_OPER) == false ||
            (user_mode_has_flag(target, UMODE_HIDDEN) && user_mode_has_flag(source, UMODE_OPER) == false))
          continue;

      who_send(source, target, member, who);
    }
  }
}

/*! \brief WHO command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = mask
 *      - parv[2] = additional selection flag, only 'o' for now.
 *                  and %flags to specify what fields to output
 *                  plus a ,querytype if the t flag is specified
 *                  so the final thing will be like o%tnchu,777
 */
static void
m_who(struct Client *source, int parc, char *parv[])
{
  char *mask = parv[1];
  char *options = parv[2];
  char *token = NULL;
  struct WhoQuery w = { .maxmatches = WHO_MAX_REPLIES }, *who = &w;

  if (!string_is_empty(options))
  {
    char ch;
    char *p = options;

    while ((ch = *p++) && (ch != '%') && (ch != ','))
    {
      switch (ch)
      {
        case 'o':
        case 'O':
          who->bitsel |= WHOSELECT_OPER;
          break;
        case 'n':
        case 'N':
          who->matchsel |= WHO_FIELD_NIC;
          break;
        case 'u':
        case 'U':
          who->matchsel |= WHO_FIELD_UID;
          break;
        case 'h':
        case 'H':
          who->matchsel |= WHO_FIELD_HOS;
          break;
        case 'i':
        case 'I':
          who->matchsel |= WHO_FIELD_NIP;
          break;
        case 's':
        case 'S':
          who->matchsel |= WHO_FIELD_SER;
          break;
        case 'r':
        case 'R':
          who->matchsel |= WHO_FIELD_REN;
          break;
        case 'a':
        case 'A':
          who->matchsel |= WHO_FIELD_ACC;
          break;
      }
    }

    if (ch == '%')
    {
      while ((ch = *p++) && (ch != ','))
      {
        switch (ch)
        {
          case 'c':
          case 'C':
            who->fields |= WHO_FIELD_CHA;
            break;
          case 'd':
          case 'D':
            who->fields |= WHO_FIELD_DIS;
            break;
          case 'f':
          case 'F':
            who->fields |= WHO_FIELD_FLA;
            break;
          case 'h':
          case 'H':
            who->fields |= WHO_FIELD_HOS;
            break;
          case 'i':
          case 'I':
            who->fields |= WHO_FIELD_NIP;
            break;
          case 'l':
          case 'L':
            who->fields |= WHO_FIELD_IDL;
            break;
          case 'n':
          case 'N':
            who->fields |= WHO_FIELD_NIC;
            break;
          case 'r':
          case 'R':
            who->fields |= WHO_FIELD_REN;
            break;
          case 's':
          case 'S':
            who->fields |= WHO_FIELD_SER;
            break;
          case 't':
          case 'T':
            who->fields |= WHO_FIELD_QTO;
            break;
          case 'u':
          case 'U':
            who->fields |= WHO_FIELD_UID;
            break;
          case 'a':
          case 'A':
            who->fields |= WHO_FIELD_ACC;
            break;
          case 'o':
          case 'O':
            who->fields |= WHO_FIELD_OPL;
            break;
        }
      }
    }

    if (ch)
      token = p;

    if (token && (who->fields & WHO_FIELD_QTO))
    {
      p = token;
      if (!((*p > '9') || (*p < '0')))
        p++;
      if (!((*p > '9') || (*p < '0')))
        p++;
      if (!((*p > '9') || (*p < '0')))
        p++;
      *p = '\0';
    }
    else
      token = NULL;

    who->token = token;
  }

  /* '/who #some_channel' */
  if (IsChanPrefix(*mask))
  {
    /* List all users on a given channel */
    struct Channel *channel = hash_find_channel(mask);
    if (channel)
      who_on_channel(source, channel, who);

    sendto_one_numeric(source, &me, RPL_ENDOFWHO, mask);
    return;
  }

  /* '/who nick' */
  if (who->matchsel == 0 || (who->matchsel & WHO_FIELD_NIC))
  {
    const struct Client *target = find_person(source, mask);
    if (target)
    {
      if (!(who->bitsel & WHOSELECT_OPER) ||
          (user_mode_has_flag(target, UMODE_OPER) &&
           (user_mode_has_flag(target, UMODE_HIDDEN) == false || user_mode_has_flag(source, UMODE_OPER))))
        who_send(source, target, NULL, who);

      sendto_one_numeric(source, &me, RPL_ENDOFWHO, mask);
      return;
    }
  }

  collapse(mask);
  if (strcmp(mask, "0") == 0 ||
      strcmp(mask, "*") == 0)
    mask = NULL;

  if (who->matchsel == 0)
    who->matchsel = WHO_FIELD_DEF;

  who_global(source, mask, who);

  if (who->maxmatches == 0)
    sendto_one_numeric(source, &me, ERR_WHOLIMEXCEED, WHO_MAX_REPLIES, "WHO");
  sendto_one_numeric(source, &me, RPL_ENDOFWHO, string_default(mask, "*"));
}

static struct Command command_table =
{
  .name = "WHO",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_who, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_who, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  isupport_add("WHOX", NULL);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  isupport_delete("WHOX");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
