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

#ifndef INCLUDED_user_mode_h
#define INCLUDED_user_mode_h

struct Client;

/* External user mode symbols */
extern uint64_t UMODE_FLOOD;
extern uint64_t UMODE_SOFTCALLERID;
extern uint64_t UMODE_HIDDEN;
extern uint64_t UMODE_EXPIRATION;
extern uint64_t UMODE_REGONLY;
extern uint64_t UMODE_SECURE;
extern uint64_t UMODE_WEBIRC;
extern uint64_t UMODE_SECUREONLY;
extern uint64_t UMODE_ADMIN;
extern uint64_t UMODE_CCONN;
extern uint64_t UMODE_EXTERNAL;
extern uint64_t UMODE_CALLERID;
extern uint64_t UMODE_INVISIBLE;
extern uint64_t UMODE_REJ;
extern uint64_t UMODE_SKILL;
extern uint64_t UMODE_LOCOPS;
extern uint64_t UMODE_NCHANGE;
extern uint64_t UMODE_OPER;
extern uint64_t UMODE_HIDECHANS;
extern uint64_t UMODE_HIDEIDLE;
extern uint64_t UMODE_REGISTERED;

typedef enum
{
  USER_MODE_SUCCESS = 0,
  USER_MODE_RESULT_INVALID_CHAR,
  USER_MODE_RESULT_MODE_NOT_FOUND,
  USER_MODE_RESULT_MODE_ALREADY_EXISTS,
  USER_MODE_RESULT_POLICY_VIOLATION,
  USER_MODE_RESULT_CALLBACK_FAILED,
  USER_MODE_RESULT_COUNT,
} user_mode_result_t;

typedef enum
{
  USER_MODE_SOURCE_REGULAR,
  USER_MODE_SOURCE_SVSMODE,
} user_mode_source_t;

typedef enum
{
  USER_MODE_ACTION_ADD,
  USER_MODE_ACTION_DEL,
} user_mode_action_t;

typedef enum
{
  USER_MODE_POLICY_INTERNAL_ONLY = 1 << 0,
  USER_MODE_POLICY_OPER_ONLY     = 1 << 1,
  USER_MODE_POLICY_MANUAL_ONLY   = 1 << 2,
  USER_MODE_POLICY_SERVICE_ONLY  = 1 << 3,
} user_mode_policy_t;

typedef enum
{
  USER_MODE_SEND_CLIENT = 1 << 0,
  USER_MODE_SEND_SERVER = 1 << 1,
} user_mode_send_t;

typedef bool (*user_mode_callback_t)(struct Client *, user_mode_source_t);

struct UserMode
{
  char mode_char;
  uint64_t mode_bit;
  uint64_t *mode_flag;
  user_mode_policy_t policy;
  user_mode_callback_t set_callback;
  user_mode_callback_t unset_callback;
};

extern void user_mode_send(struct Client *, uint64_t, user_mode_send_t);
extern void user_mode_send_invalid(void);
extern bool user_mode_has(const struct Client *, char);
extern bool user_mode_has_flag(const struct Client *, uint64_t);
extern bool user_mode_has_mode(const struct Client *, const struct UserMode *);
extern bool user_mode_set_flag(struct Client *, uint64_t);
extern bool user_mode_set_flag_exec(struct Client *, uint64_t, user_mode_source_t);
extern bool user_mode_set_mode(struct Client *, const struct UserMode *);
extern bool user_mode_set_mode_exec(struct Client *, const struct UserMode *, user_mode_source_t);
extern bool user_mode_unset_flag(struct Client *, uint64_t);
extern bool user_mode_unset_flag_exec(struct Client *, uint64_t, user_mode_source_t);
extern bool user_mode_unset_mode(struct Client *, const struct UserMode *);
extern bool user_mode_unset_mode_exec(struct Client *, const struct UserMode *, user_mode_source_t);
extern uint64_t user_mode_get_oper_only(void);
extern uint64_t user_mode_string_to_flags(const char *);
extern user_mode_result_t user_mode_change(struct Client *, char, user_mode_source_t, user_mode_action_t);
extern user_mode_result_t user_mode_register(struct UserMode *);
extern user_mode_result_t user_mode_set(struct Client *, char, user_mode_source_t);
extern user_mode_result_t user_mode_unregister(struct UserMode *);
extern user_mode_result_t user_mode_unset(struct Client *, char, user_mode_source_t);
extern struct UserMode *user_mode_find(char);
extern const char *user_mode_get_string(void);
extern const char *user_mode_to_str(uint64_t);
#endif  /* INCLUDED_user_mode_h */
