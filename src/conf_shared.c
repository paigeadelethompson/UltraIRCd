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

/*! \file conf_shared.c
 * \brief Implements shared {} block configuration management.
 */

#include "stdinc.h"
#include "list.h"
#include "io_string.h"
#include "memory.h"
#include "conf_shared.h"

static list_t shared_list;

const list_t *
shared_get_list(void)
{
  return &shared_list;
}

void
shared_clear(void)
{
  while (shared_list.head)
  {
    struct SharedItem *shared = shared_list.head->data;
    list_remove(&shared->node, &shared_list);
    io_free(shared->server);
    io_free(shared->user);
    io_free(shared->host);
    io_free(shared);
  }
}

struct SharedItem *
shared_make(void)
{
  struct SharedItem *shared = io_calloc(sizeof(*shared));
  list_add(shared, &shared->node, &shared_list);

  return shared;
}

const struct SharedItem *
shared_find(unsigned int type, const char *server, const char *user, const char *host)
{
  list_node_t *node;

  LIST_FOREACH(node, shared_list.head)
  {
    const struct SharedItem *shared = node->data;
    if (shared->type & type)
      if (match(shared->server, server) == 0)
        if (match(shared->user, user) == 0 && match(shared->host, host) == 0)
          return shared;
  }

  return NULL;
}
