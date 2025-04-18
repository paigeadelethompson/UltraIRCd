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

/*! \file user.h
 * \brief A header for the user functions.
 */

#ifndef INCLUDED_user_h
#define INCLUDED_user_h

struct Client;

extern void show_lusers(struct Client *);
extern void user_set_hostmask(struct Client *, const char *, bool);
extern void user_register_local(struct Client *);
extern void user_register_remote(struct Client *);
extern bool valid_hostname(const char *);
extern bool valid_username(const char *, bool);
extern bool valid_nickname(const char *, bool);
#endif  /* INCLUDED_user_h */
