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

/*! \file client_svstag.h
 * \brief Controls SVSTAGS.
 */

#ifndef INCLUDED_client_svstag_h
#define INCLUDED_client_svstag_h

struct ServicesTag
{
  list_node_t node;
  char *tag;
  unsigned int numeric;
  uint64_t umodes;
};

extern void svstag_detach(list_t *, unsigned int);
extern void svstag_attach(list_t *, unsigned int, const char *, const char *);
extern void svstag_clear_list(list_t *);
#endif  /* INCLUDED_client_svstag_h */
