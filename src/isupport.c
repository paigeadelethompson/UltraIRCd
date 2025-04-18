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
 * @file isupport.c
 * @brief Implementation of IRC ISUPPORT messages (RPL_ISUPPORT) in ircd-hybrid.
 *
 * The ISUPPORT mechanism provides a means for IRC servers to communicate their
 * capabilities and configuration settings to clients during the connection
 * establishment phase. This file contains functions and structures necessary for
 * handling and managing ISUPPORT messages within the ircd-hybrid server.
 */

#include "stdinc.h"
#include "io_string.h"
#include "list.h"
#include "memory.h"
#include "send.h"
#include "numeric.h"
#include "client.h"
#include "ircd_defs.h"
#include "isupport.h"

/**
 * @enum ISUPPORT_TOKENS_PER_LINE
 * @brief Maximum number of tokens allowed in a single ISUPPORT response line.
 */
enum
{
  ISUPPORT_TOKENS_PER_LINE = 13
};

/**
 * @struct Isupport
 * @brief Structure representing an IRC ISUPPORT option.
 *
 * This structure encapsulates an IRC ISUPPORT option, including its name, options, and
 * numerical value if applicable.
 */
struct Isupport
{
  list_node_t node;  /**< Node for linking Isupport structures in a list. */
  char *name;  /**< Name of the ISUPPORT option. */
  char *options;  /**< Options associated with the ISUPPORT option. */
};

/**
 * @var isupport_list
 * @brief List containing Isupport structures representing active ISUPPORT options.
 *
 * The isupport_list is a linked list that stores Isupport structures, each representing
 * a unique ISUPPORT option in the ircd-hybrid server. This list serves as the central
 * repository for managing and organizing ISUPPORT options. Various operations, such as
 * addition, deletion, and retrieval, are performed on this list to maintain and update
 * ISUPPORT options dynamically.
 */
static list_t isupport_list;

/**
 * @var isupport_list_lines
 * @brief List containing formatted ISUPPORT strings for transmission.
 *
 * The isupport_list_lines is a linked list that stores formatted ISUPPORT strings, each
 * representing a line of ISUPPORT information suitable for sending to clients. These
 * strings are constructed based on the options stored in the isupport_list. The list is
 * updated and rebuilt as needed to reflect the current set of supported features and
 * configurations.
 */
static list_t isupport_list_lines;

/**
 * @brief Clears the list of lines used for RPL_ISUPPORT messages.
 *
 * This function removes all stored lines in preparation for rebuilding
 * the RPL_ISUPPORT response. It iterates through the list of lines,
 * deallocates memory, and frees the associated data.
 */
static void
isupport_clear_lines(void)
{
  while (isupport_list_lines.head)
  {
    list_node_t *node = isupport_list_lines.head;
    list_remove(node, &isupport_list_lines);
    io_free(node->data);
    list_free_node(node);
  }
}

/**
 * @brief Constructs formatted lines for ISUPPORT messages.
 *
 * This function constructs formatted lines for ISUPPORT messages based on the ISUPPORT
 * options stored in the isupport_list. Each line represents a set of ISUPPORT options,
 * and the resulting lines are stored in isupport_list_lines.
 */
static void
isupport_build_lines(void)
{
  char buf[IRCD_BUFSIZE];
  char *bufptr = buf;
  int tokens = 0;
  size_t len = 0;
  size_t reserve = HOSTLEN + NICKLEN + strlen(numeric_form(RPL_ISUPPORT)) + 3;  /* +3 for \r\n\0 */

  isupport_clear_lines();

  list_node_t *node;
  LIST_FOREACH(node, isupport_list.head)
  {
    const struct Isupport *support = node->data;
    size_t token_len = snprintf(NULL, 0, len ? " %s" : "%s", support->name);
    if (support->options)
      token_len += snprintf(NULL, 0, "=%s", support->options);

    if (tokens == ISUPPORT_TOKENS_PER_LINE || (len + token_len >= sizeof(buf) - reserve))
    {
      list_add_tail(io_strdup(buf), list_make_node(), &isupport_list_lines);
      bufptr = buf;
      len = 0;
      tokens = 0;
    }

    ++tokens;

    len += snprintf(bufptr + len, sizeof(buf) - len, len ? " %s" : "%s", support->name);
    if (support->options)
      len += snprintf(bufptr + len, sizeof(buf) - len, "=%s", support->options);

  }

  if (len > 0)
    list_add_tail(io_strdup(buf), list_make_node(), &isupport_list_lines);
}

/**
 * @brief Finds an ISUPPORT option by name.
 *
 * Searches the list of ISUPPORT options for an option with the specified name.
 *
 * @param name The name of the ISUPPORT option to find.
 * @return A pointer to the Isupport structure if found, otherwise NULL.
 */
static struct Isupport *
isupport_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, isupport_list.head)
  {
    struct Isupport *support = node->data;
    if (irccmp(support->name, name) == 0)
      return support;
  }

  return NULL;
}

static int
isupport_cmp(const void *const a_, const void *const b_)
{
  const char *const a = ((const struct Isupport *)a_)->name;
  const char *const b = ((const struct Isupport *)b_)->name;
  return strcmp(a, b);
}

/**
 * @brief Creates a new ISUPPORT option.
 *
 * Creates a new ISUPPORT option with the specified name, options, and number.
 *
 * @param name The name of the ISUPPORT option.
 * @param options The options associated with the ISUPPORT option.
 * @param number The numerical value associated with the ISUPPORT option.
 * @return A pointer to the newly created Isupport structure.
 */
static struct Isupport *
isupport_create(const char *name, const char *options)
{
  struct Isupport *support = io_calloc(sizeof(*support));
  support->name = io_strdup(name);
  support->options = (options) ? io_strdup(options) : NULL;
  list_add_sorted(support, &support->node, &isupport_list, isupport_cmp);

  return support;
}

/**
 * @brief Destroys an ISUPPORT option.
 *
 * Removes an ISUPPORT option from the list and deallocates its memory.
 *
 * @param support A pointer to the Isupport structure to destroy.
 */
static void
isupport_destroy(struct Isupport *support)
{
  list_remove(&support->node, &isupport_list);
  io_free(support->name);
  io_free(support->options);
  io_free(support);
}

/**
 * @brief Adds or updates an ISUPPORT option.
 *
 * Adds a new ISUPPORT option or updates an existing one with the specified name,
 * options, and number. If an option with the same name exists, it is replaced.
 * After modification, the ISUPPORT lines are rebuilt.
 *
 * @param name The name of the ISUPPORT option.
 * @param options The options associated with the ISUPPORT option.
 * @param number The numerical value associated with the ISUPPORT option.
 */
void
isupport_add(const char *name, const char *format, ...)
{
  char buf[IRCD_BUFSIZE];

  if (format)
  {
    va_list args;

    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);
  }

  struct Isupport *support = isupport_find(name);
  if (support)
    isupport_destroy(support);

  isupport_create(name, format ? buf : NULL);

  /* Rebuild ISUPPORT lines after modification. */
  isupport_build_lines();
}

/**
 * @brief Deletes an ISUPPORT option.
 *
 * Deletes an ISUPPORT option with the specified name. After deletion,
 * the ISUPPORT lines are rebuilt.
 *
 * @param name The name of the ISUPPORT option to delete.
 */
void
isupport_delete(const char *name)
{
  struct Isupport *support = isupport_find(name);
  if (support == NULL)
    return;

  isupport_destroy(support);

  /* Rebuild ISUPPORT lines after modification. */
  isupport_build_lines();
}

/**
 * @brief Displays ISUPPORT information to a client.
 *
 * Sends formatted ISUPPORT messages to a client to inform them about the
 * server's supported features and settings.
 *
 * @param client A pointer to the Client structure.
 */
void
isupport_show(struct Client *client)
{
  list_node_t *node;

  LIST_FOREACH(node, isupport_list_lines.head)
  {
    const char *const string = node->data;
    sendto_one_numeric(client, &me, RPL_ISUPPORT, string);
  }
}
