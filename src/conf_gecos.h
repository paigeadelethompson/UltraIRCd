/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1998-2025 ircd-hybrid development team
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

/*! \file conf_gecos.h
 * \brief Implements gecos {} block configuration management.
 */

#ifndef INCLUDED_conf_gecos_h
#define INCLUDED_conf_gecos_h

struct GecosItem
{
  list_node_t node;
  char *mask;
  char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  bool in_database;
};

extern void gecos_delete(struct GecosItem *, bool);
extern void gecos_clear(void);
extern void gecos_expire(void);
extern struct GecosItem *gecos_make(void);
extern struct GecosItem *gecos_find(const char *, int (*)(const char *, const char *));
extern const list_t *gecos_get_list(void);
#endif  /* INCLUDED_conf_gecos_h */
