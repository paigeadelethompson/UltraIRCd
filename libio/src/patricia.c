/*
 * Dave Plonka <plonka@doit.wisc.edu>
 *
 * This file had been called "radix.c" in the MRT sources.
 *
 * I renamed it to "patricia.c" since it's not an implementation of a general
 * radix trie.  Also I pulled in various requirements from "prefix.c" and
 * "demo.c" so that it could be used as a standalone API.
 *
 * Copyright (c) 1999-2013
 *
 * The Regents of the University of Michigan ("The Regents") and Merit
 * Network, Inc.
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <assert.h> /* assert */
#include <stddef.h> /* NULL */
#include <stdio.h> /* sprintf, fprintf, stderr */
#include <stdlib.h> /* free, atol, calloc */
#include <string.h> /* memcpy, strchr, strlen */
#include <sys/types.h> /* BSD: for inet_addr */
#include <sys/socket.h> /* BSD, Linux: for inet_addr */
#include <netinet/in.h> /* BSD, Linux: for inet_addr */
#include <arpa/inet.h> /* BSD, Linux, Solaris: for inet_addr */

#include "memory.h"
#include "patricia.h"

#define prefix_to_uint8(prefix) ((const uint8_t *)&(prefix)->add.sin)

static bool
comp_with_mask(const uint8_t *addr, const uint8_t *dest, unsigned int mask)
{
  /* Mask length of zero matches everything. */
  if (mask == 0)
    return true;

  if (memcmp(addr, dest, mask / 8) == 0)
  {
    int n = mask / 8;
    int m = ~((1 << (8 - (mask % 8))) - 1);

    if (mask % 8 == 0 || (addr[n] & m) == (dest[n] & m))
      return true;
  }

  return false;
}

/*
 * convert prefix information to ascii string with length
 */
const char *
patricia_prefix_toa(const patricia_prefix_t *prefix, bool with_len)
{
  static char buf[INET6_ADDRSTRLEN + sizeof("/128")];

  assert(prefix);
  assert(prefix->ref_count >= 0);
  assert((prefix->family == AF_INET  && prefix->bitlen <=  32) ||
         (prefix->family == AF_INET6 && prefix->bitlen <= 128));

  inet_ntop(prefix->family, &prefix->add.sin6, buf, INET6_ADDRSTRLEN);

  if (with_len)
  {
    size_t len = strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "/%d", prefix->bitlen);
  }

  return buf;
}

static patricia_prefix_t *
New_Prefix2(int family, const void *dest, int bitlen, patricia_prefix_t *prefix)
{
  int addr_size = 0;

  switch (family)
  {
    case AF_INET:
      addr_size = sizeof(struct in_addr);
      break;
    case AF_INET6:
      addr_size = sizeof(struct in6_addr);
      break;
    default: return NULL;
  }

  bool dynamic_allocated = false;
  if (prefix == NULL)
  {
    prefix = io_calloc(sizeof(*prefix));
    dynamic_allocated = true;
  }

  memcpy(&prefix->add.sin6, dest, addr_size);
  prefix->bitlen = (bitlen >= 0) ? bitlen : addr_size * 8;
  prefix->family = family;
  prefix->ref_count = dynamic_allocated ? 1 : 0;

  return prefix;
}

static patricia_prefix_t *
New_Prefix(int family, const void *dest, int bitlen)
{
  return New_Prefix2(family, dest, bitlen, NULL);
}

/* ascii2prefix
 */
static patricia_prefix_t *
ascii2prefix(int family, const char *string)
{
  int bitlen, maxbitlen = 0;

  assert(string);

  /* Easy way to handle both families */
  if (family == 0)
    family = strchr(string, ':') ? AF_INET6 : AF_INET;

  if (family == AF_INET)
    maxbitlen = sizeof(struct in_addr)  * 8;
  else if (family == AF_INET6)
    maxbitlen = sizeof(struct in6_addr) * 8;

  char save[INET6_ADDRSTRLEN];
  const char *const cp = strchr(string, '/');
  if (cp)
  {
    size_t length = cp - string;
    if (length >= sizeof(save))
      return NULL;

    bitlen = atoi(cp + 1);

    /* Copy the string to save. Avoid destroying the string */
    memcpy(save, string, length);
    save[length] = '\0';

    string = save;

    if (bitlen < 0 || bitlen > maxbitlen)
      bitlen = maxbitlen;
  }
  else
    bitlen = maxbitlen;

  union
  {
    struct in_addr sin;
    struct in6_addr sin6;
  } sin;

  if (inet_pton(family, string, &sin) <= 0)
    return NULL;

  return New_Prefix(family, &sin, bitlen);
}

static patricia_prefix_t *
Ref_Prefix(patricia_prefix_t *prefix)
{
  if (prefix == NULL)
    return NULL;

  if (prefix->ref_count == 0)
    /* Make a copy in case of a static prefix */
    return New_Prefix2(prefix->family, &prefix->add, prefix->bitlen, NULL);

  prefix->ref_count++;

  return prefix;
}

static void
Deref_Prefix(patricia_prefix_t *prefix)
{
  if (prefix == NULL)
    return;

  /* For secure programming, raise an assert. No static prefix can call this */
  assert(prefix->ref_count > 0);
  if (--prefix->ref_count <= 0)
    io_free(prefix);
}

/* these routines support continuous mask only */

patricia_tree_t *
patricia_new(unsigned int maxbits)
{
  patricia_tree_t *tree = io_calloc(sizeof(*tree));
  tree->maxbits = maxbits;

  assert(maxbits <= PATRICIA_MAXBITS);  /* XXX */
  return tree;
}

/*
 * if func is supplied, it will be called as func(node->data)
 * before deleting the node
 */
void
patricia_clear(patricia_tree_t *tree, void (*func)(void *))
{
  assert(tree);

  if (tree->head == NULL)
    return;

  patricia_node_t *Xstack[PATRICIA_MAXBITS + 1];
  patricia_node_t **Xsp = Xstack;

  patricia_node_t *Xrn = tree->head;
  while (Xrn)
  {
    patricia_node_t *l = Xrn->l;
    patricia_node_t *r = Xrn->r;

    if (Xrn->prefix)
    {
      Deref_Prefix(Xrn->prefix);

      if (Xrn->data && func)
        func(Xrn->data);
    }
    else
      assert(Xrn->data == NULL);

    io_free(Xrn);
    tree->num_active_node--;

    if (l)
    {
      if (r)
        *Xsp++ = r;

      Xrn = l;
    }
    else if (r)
      Xrn = r;
    else if (Xsp != Xstack)
      Xrn = *(--Xsp);
    else
      Xrn = NULL;
  }

  tree->head = NULL;

  assert(tree->num_active_node == 0);
}

void
patricia_destroy(patricia_tree_t *tree, void (*func)(void *))
{
  patricia_clear(tree, func);
  io_free(tree);
}

/*
 * if func is supplied, it will be called as func(node->prefix, node->data)
 */
void
patricia_process(patricia_tree_t *tree, void (*func)(patricia_prefix_t *, void *))
{
  assert(func);

  patricia_node_t *node;
  PATRICIA_WALK(tree->head, node) {
    func(node->prefix, node->data);
  } PATRICIA_WALK_END;
}

patricia_node_t *
patricia_search_exact(patricia_tree_t *tree, patricia_prefix_t *prefix)
{
  assert(tree);
  assert(prefix);
  assert(prefix->bitlen <= tree->maxbits);

  if (tree->head == NULL)
    return NULL;

  patricia_node_t *node = tree->head;
  const uint8_t *addr = prefix_to_uint8(prefix);
  unsigned int bitlen = prefix->bitlen;

  while (node->bit < bitlen)
  {
    if (BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
      node = node->r;
    else
      node = node->l;

    if (node == NULL)
      return NULL;
  }

  if (node->bit > bitlen || node->prefix == NULL)
    return NULL;

  assert(node->bit == bitlen);
  assert(node->bit == node->prefix->bitlen);

  if (comp_with_mask(prefix_to_uint8(node->prefix), prefix_to_uint8(prefix), bitlen))
    return node;

  return NULL;
}

/* if inclusive != 0, "best" may be the given prefix itself */
patricia_node_t *
patricia_search_best2(patricia_tree_t *tree, patricia_prefix_t *prefix, bool inclusive)
{
  assert(tree);
  assert(prefix);
  assert(prefix->bitlen <= tree->maxbits);

  if (tree->head == NULL)
    return NULL;

  patricia_node_t *node = tree->head;
  patricia_node_t *stack[PATRICIA_MAXBITS + 1];
  const uint8_t *addr = prefix_to_uint8(prefix);
  unsigned int bitlen = prefix->bitlen;
  int cnt = 0;

  while (node->bit < bitlen)
  {
    if (node->prefix)
      stack[cnt++] = node;

    if (BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
      node = node->r;
    else
      node = node->l;

    if (node == NULL)
      break;
  }

  if (inclusive && node && node->prefix)
    stack[cnt++] = node;

  if (cnt <= 0)
    return NULL;

  while (--cnt >= 0)
  {
    node = stack[cnt];

    if (comp_with_mask(prefix_to_uint8(node->prefix),
                       prefix_to_uint8(prefix), node->prefix->bitlen) && node->prefix->bitlen <= bitlen)
      return node;
  }

  return NULL;
}

patricia_node_t *
patricia_search_best(patricia_tree_t *tree, patricia_prefix_t *prefix)
{
  return patricia_search_best2(tree, prefix, 1);
}

patricia_node_t *
patricia_lookup(patricia_tree_t *tree, patricia_prefix_t *prefix)
{
  assert(tree);
  assert(prefix);
  assert(prefix->bitlen <= tree->maxbits);

  if (tree->head == NULL)
  {
    patricia_node_t *node = io_calloc(sizeof(*node));
    node->bit = prefix->bitlen;
    node->prefix = Ref_Prefix(prefix);
    tree->head = node;
    tree->num_active_node++;

    return node;
  }

  const uint8_t *addr = prefix_to_uint8(prefix);
  unsigned int bitlen = prefix->bitlen;
  patricia_node_t *node = tree->head;

  while (node->bit < bitlen || node->prefix == NULL)
  {
    if (node->bit < tree->maxbits && BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
    {
      if (node->r == NULL)
        break;

      node = node->r;
    }
    else
    {
      if (node->l == NULL)
        break;

      node = node->l;
    }

    assert(node);
  }

  assert(node->prefix);

  const uint8_t *test_addr = prefix_to_uint8(node->prefix);

  /* Find the first bit different */
  unsigned int check_bit = node->bit < bitlen ? node->bit : bitlen;
  unsigned int differ_bit = 0;
  int j, r;

  for (unsigned int i = 0; i * 8 < check_bit; i++)
  {
    if ((r = (addr[i] ^ test_addr[i])) == 0)
    {
      differ_bit = (i + 1) * 8;
      continue;
    }

    /* I know the better way, but for now */
    for (j = 0; j < 8; j++)
      if (BIT_TEST(r, (0x80 >> j)))
        break;

    /* Must be found */
    assert(j < 8);
    differ_bit = i * 8 + j;
    break;
  }

  if (differ_bit > check_bit)
    differ_bit = check_bit;

  patricia_node_t *parent = node->parent;
  while (parent && parent->bit >= differ_bit)
  {
    node = parent;
    parent = node->parent;
  }

  if (differ_bit == bitlen && node->bit == bitlen)
  {
    if (node->prefix)
      return node;

    node->prefix = Ref_Prefix(prefix);
    assert(node->data == NULL);

    return node;
  }

  patricia_node_t *new_node = io_calloc(sizeof(*new_node));
  new_node->bit = prefix->bitlen;
  new_node->prefix = Ref_Prefix(prefix);
  tree->num_active_node++;

  if (node->bit == differ_bit)
  {
    new_node->parent = node;

    if (node->bit < tree->maxbits && BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
    {
      assert(node->r == NULL);
      node->r = new_node;
    }
    else
    {
      assert(node->l == NULL);
      node->l = new_node;
    }

    return new_node;
  }

  if (bitlen == differ_bit)
  {
    if (bitlen < tree->maxbits && BIT_TEST(test_addr[bitlen >> 3], 0x80 >> (bitlen & 0x07)))
      new_node->r = node;
    else
      new_node->l = node;

    new_node->parent = node->parent;

    if (node->parent == NULL)
    {
      assert(tree->head == node);
      tree->head = new_node;
    }
    else if (node->parent->r == node)
      node->parent->r = new_node;
    else
      node->parent->l = new_node;

    node->parent = new_node;
  }
  else
  {
    patricia_node_t *glue = io_calloc(sizeof(*glue));
    glue->bit = differ_bit;
    glue->parent = node->parent;
    tree->num_active_node++;

    if (differ_bit < tree->maxbits && BIT_TEST(addr[differ_bit >> 3], 0x80 >> (differ_bit & 0x07)))
    {
      glue->r = new_node;
      glue->l = node;
    }
    else
    {
      glue->r = node;
      glue->l = new_node;
    }

    new_node->parent = glue;

    if (node->parent == NULL)
    {
      assert(tree->head == node);
      tree->head = glue;
    }
    else if (node->parent->r == node)
      node->parent->r = glue;
    else
      node->parent->l = glue;

    node->parent = glue;
  }

  return new_node;
}

void
patricia_remove(patricia_tree_t *tree, patricia_node_t *node)
{
  assert(tree);
  assert(node);

  if (node->r && node->l)
  {
    /*
     * This might be a placeholder node -- have to check and make sure
     * there is a prefix associated with it !
     */
    if (node->prefix)
      Deref_Prefix(node->prefix);

    node->prefix = NULL;
    /* Also I needed to clear data pointer -- masaki */
    node->data = NULL;
    return;
  }

  patricia_node_t *parent, *child;
  if (node->r == NULL && node->l == NULL)
  {
    parent = node->parent;
    Deref_Prefix(node->prefix);
    io_free(node);
    tree->num_active_node--;

    if (parent == NULL)
    {
      assert(tree->head == node);
      tree->head = NULL;
      return;
    }

    if (parent->r == node)
    {
      parent->r = NULL;
      child = parent->l;
    }
    else
    {
      assert(parent->l == node);

      parent->l = NULL;
      child = parent->r;
    }

    if (parent->prefix)
      return;

    /* We need to remove parent too */
    if (parent->parent == NULL)
    {
      assert(tree->head == parent);
      tree->head = child;
    }
    else if (parent->parent->r == parent)
      parent->parent->r = child;
    else
    {
      assert(parent->parent->l == parent);
      parent->parent->l = child;
    }

    child->parent = parent->parent;
    io_free(parent);
    tree->num_active_node--;
    return;
  }

  if (node->r)
    child = node->r;
  else
  {
    assert(node->l);
    child = node->l;
  }

  parent = node->parent;
  child->parent = parent;

  Deref_Prefix(node->prefix);
  io_free(node);
  tree->num_active_node--;

  if (parent == NULL)
  {
    assert(tree->head == node);
    tree->head = child;
    return;
  }

  if (parent->r == node)
    parent->r = child;
  else
  {
    assert(parent->l == node);
    parent->l = child;
  }
}

patricia_node_t *
patricia_make_and_lookup(patricia_tree_t *tree, const char *string)
{
  patricia_prefix_t *prefix = ascii2prefix(0, string);
  if (prefix == NULL)
    return NULL;

  patricia_node_t *node = patricia_lookup(tree, prefix);
  Deref_Prefix(prefix);
  return node;
}

patricia_node_t *
patricia_make_and_lookup_addr(patricia_tree_t *tree, const struct sockaddr *addr, int bitlen)
{
  int family;
  const void *dest;

  if (addr->sa_family == AF_INET6)
  {
    if (bitlen == 0 || bitlen > 128)
      bitlen = 128;

    family = AF_INET6;
    dest = &((const struct sockaddr_in6 *)addr)->sin6_addr;
  }
  else
  {
    if (bitlen == 0 || bitlen > 32)
      bitlen = 32;

    family = AF_INET;
    dest = &((const struct sockaddr_in *)addr)->sin_addr;
  }

  patricia_prefix_t *prefix = New_Prefix(family, dest, bitlen);
  if (prefix == NULL)
    return NULL;

  patricia_node_t *node = patricia_lookup(tree, prefix);
  Deref_Prefix(prefix);
  return node;
}

void
patricia_lookup_then_remove(patricia_tree_t *tree, const char *string)
{
  patricia_node_t *node = patricia_try_search_exact(tree, string);
  if (node)
    patricia_remove(tree, node);
}

patricia_node_t *
patricia_try_search_exact(patricia_tree_t *tree, const char *string)
{
  patricia_prefix_t *prefix = ascii2prefix(0, string);
  if (prefix == NULL)
    return NULL;

  patricia_node_t *node = patricia_search_exact(tree, prefix);
  Deref_Prefix(prefix);
  return node;
}

patricia_node_t *
patricia_try_search_best(patricia_tree_t *tree, const char *string)
{
  patricia_prefix_t *prefix = ascii2prefix(0, string);
  if (prefix == NULL)
    return NULL;

  patricia_node_t *node = patricia_search_best(tree, prefix);
  Deref_Prefix(prefix);
  return node;
}

patricia_node_t *
patricia_try_search_exact_addr(patricia_tree_t *tree, const struct sockaddr *addr, int bitlen)
{
  int family;
  const void *dest;

  if (addr->sa_family == AF_INET6)
  {
    if (bitlen == 0 || bitlen > 128)
      bitlen = 128;

    family = AF_INET6;
    dest = &((const struct sockaddr_in6 *)addr)->sin6_addr;
  }
  else
  {
    if (bitlen == 0 || bitlen > 32)
      bitlen = 32;

    family = AF_INET;
    dest = &((const struct sockaddr_in *)addr)->sin_addr;
  }

  patricia_prefix_t *prefix = New_Prefix(family, dest, bitlen);
  if (prefix == NULL)
    return NULL;

  patricia_node_t *node = patricia_search_exact(tree, prefix);
  Deref_Prefix(prefix);
  return node;
}

patricia_node_t *
patricia_try_search_best_addr(patricia_tree_t *tree, const struct sockaddr *addr, int bitlen)
{
  int family;
  const void *dest;

  if (addr->sa_family == AF_INET6)
  {
    if (bitlen == 0 || bitlen > 128)
      bitlen = 128;

    family = AF_INET6;
    dest = &((const struct sockaddr_in6 *)addr)->sin6_addr;
  }
  else
  {
    if (bitlen == 0 || bitlen > 32)
      bitlen = 32;

    family = AF_INET;
    dest = &((const struct sockaddr_in *)addr)->sin_addr;
  }

  patricia_prefix_t *prefix = New_Prefix(family, dest, bitlen);
  if (prefix == NULL)
    return NULL;

  patricia_node_t *node = patricia_search_best(tree, prefix);
  Deref_Prefix(prefix);
  return node;
}
