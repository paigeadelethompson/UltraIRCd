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

/*! \file packet.h
 * \brief A header for the packet functions.
 */

#ifndef INCLUDED_packet_h
#define INCLUDED_packet_h

#include "fdlist.h"

/*
 * This hides in here rather than in defaults.h because it really shouldn't
 * be tweaked unless you *REALLY REALLY* know what you're doing!
 * Remember, messages are only anti-flooded on incoming from the client, not on
 * incoming from a server for a given client, so if you tweak this you risk
 * allowing a client to flood differently depending upon where they are on
 * the network.
 *   -- adrian
 */
/* MAX_FLOOD is the amount of lines in a 'burst' we allow from a client,
 * anything beyond MAX_FLOOD is limited to about one line per second.
 *
 * MAX_FLOOD_BURST is the amount of lines we allow from a client who has
 * just connected.  this allows clients to rejoin multiple channels
 * without being so heavily penalised they excess flood.
 */
enum
{
  MAX_FLOOD = 5,
  MAX_FLOOD_BURST = MAX_FLOOD * 8
};

extern void read_packet(fde_t *, void *);
extern void flood_recalc(fde_t *, void *);
extern void flood_endgrace(struct Client *);
#endif  /* INCLUDED_packet_h */
