/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

#include "config.h"
#include "stdinc.h"
#include "irc_string.h"
#include "nuh.h"

/**
 * @brief Parses an IRC `nick!user@host` mask into its components.
 *
 * This function splits a given IRC mask into its constituent parts: nickname,
 * username, and hostname. Depending on the format of the mask, some components
 * may not be present, in which case wildcard values (`*`) are assigned.
 * If `nickptr` is NULL, the nickname field is replaced by `*`, and the host field
 * takes the value of the input mask if no `@` or `!` is found.
 *
 * Supported IRC mask formats and their results:
 *
 * +--------------------+---------+--------+---------+
 * | Input Mask         | Nick    | User   | Host    |
 * +--------------------+---------+--------+---------+
 * | Dianora!db@db.net  | Dianora | db     | db.net  |
 * | Dianora            | Dianora | *      | *       |
 * | db.net             | *       | *      | db.net  |
 * | Dianora!           | Dianora | *      | *       |
 * | Dianora!@          | Dianora | *      | *       |
 * | Dianora!db         | Dianora | db     | *       |
 * | Dianora!@db.net    | Dianora | *      | db.net  |
 * | db@db.net          | *       | db     | db.net  |
 * | !db@db.net         | *       | db     | db.net  |
 * | !@db.net           | *       | *      | db.net  |
 * | !@                 | *       | *      | *       |
 * | @                  | *       | *      | *       |
 * | !                  | *       | *      | *       |
 * | (nickptr == NULL): |         |        |         |
 * | Dianora            | *       | *      | Dianora |
 * +--------------------+---------+--------+---------+
 *
 * @param iptr Pointer to a nuh_split structure containing the IRC mask
 * and the buffers for storing the parsed components.
 *
 * @note The function modifies the input `nuhmask` by inserting null terminators
 * to delimit components.
 */
void
nuh_split(struct nuh_split *const iptr)
{
  char *p = NULL, *q = NULL;

  /* Initialize all components to wildcards (`*`). */
  if (iptr->nickptr)
    strlcpy(iptr->nickptr, "*", iptr->nicksize);
  if (iptr->userptr)
    strlcpy(iptr->userptr, "*", iptr->usersize);
  if (iptr->hostptr)
    strlcpy(iptr->hostptr, "*", iptr->hostsize);

  /* Check for '!' delimiter to separate `nick` and `user@host`. */
  if ((p = strchr(iptr->nuhmask, '!')))
  {
    *p = '\0';

    if (iptr->nickptr && *iptr->nuhmask)
      strlcpy(iptr->nickptr, iptr->nuhmask, iptr->nicksize);

    /* Check for '@' delimiter within the `user@host` part. */
    if ((q = strchr(++p, '@')))
    {
      *q++ = '\0';

      if (iptr->userptr && *p)
        strlcpy(iptr->userptr, p, iptr->usersize);

      if (iptr->hostptr && *q)
        strlcpy(iptr->hostptr, q, iptr->hostsize);
    }
    else
    {
      /* No `@` found; only `user` exists after `!`. */
      if (iptr->userptr && *p)
        strlcpy(iptr->userptr, p, iptr->usersize);
    }
  }
  else
  {
    /* No '!' found; check for a `user@host` format. */
    if ((p = strchr(iptr->nuhmask, '@')))
    {
      *p++ = '\0';

      if (iptr->userptr && *iptr->nuhmask)
        strlcpy(iptr->userptr, iptr->nuhmask, iptr->usersize);

      if (iptr->hostptr && *p)
        strlcpy(iptr->hostptr, p, iptr->hostsize);
    }
    else
    {
      /* No `!` or `@` found; determine if it's a `nick` or `host`. */
      if (iptr->nickptr == NULL || strpbrk(iptr->nuhmask, ".:"))
      {
        if (iptr->hostptr)
          strlcpy(iptr->hostptr, iptr->nuhmask, iptr->hostsize);
      }
      else
      {
        if (iptr->nickptr)
          strlcpy(iptr->nickptr, iptr->nuhmask, iptr->nicksize);
      }
    }
  }
}
