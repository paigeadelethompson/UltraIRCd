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

/**
 * @file id.h
 * @brief Functions for SID/UID generation and validation.
 *
 * This file contains declarations for functions related to Server ID (SID)
 * and User ID (UID) generation and validation. These functions are
 * essential for managing unique identifiers within the IRC daemon.
 */

#ifndef INCLUDED_id_h
#define INCLUDED_id_h

/**
 * @var IRC_MAXSID
 * @brief Maximum length of SID (Server ID).
 */
enum { IRC_MAXSID = 3 };

/**
 * @var IRC_MAXUID
 * @brief Maximum length of UID (User ID).
 */
enum { IRC_MAXUID = 6 };

/**
 * @var TOTALSIDUID
 * @brief Total length of SID and UID combined.
 */
enum { TOTALSIDUID = IRC_MAXSID + IRC_MAXUID };

extern bool valid_sid(const char *);
extern bool valid_uid(const char *);
extern void init_uid(void);
extern void generate_sid(void);
extern const char *uid_get(void);
#endif  /* INCLUDED_id_h */
