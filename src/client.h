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

/*! \file client.h
 * \brief Header including structures, macros and prototypes for client handling
 */


#ifndef INCLUDED_client_h
#define INCLUDED_client_h

#include "address.h"
#include "dbuf.h"
#include "fdlist.h"
#include "io.h"
#include "list.h"
#include "lookup.h"
#include "ircd_defs.h"


/** Client connection states */
enum
{
  STAT_CONNECTING = 1,  /**< Connecting to another server */
  STAT_HANDSHAKE,  /**< PASS, CAPAB, and SERVER sent */
  STAT_ME,  /**< This is &me */
  STAT_UNKNOWN,  /**< Unknown/unidentified connection */
  STAT_SERVER,  /**< Fully registered server */
  STAT_CLIENT,  /**< Fully registered client */
};

enum
{
  REG_NEED_USER = 1 << 0,  /**< User must send USER command */
  REG_NEED_NICK = 1 << 1,  /**< User must send NICK command */
  REG_NEED_CAP  = 1 << 2,  /**< In middle of CAP negotiations */
  REG_INIT      = REG_NEED_USER | REG_NEED_NICK
};

#define ID_or_name(x,client_p)  ((IsServer(client_p->from) && (x)->id[0]) ? (x)->id : (x)->name)

#define IsConnecting(x)         ((x)->status == STAT_CONNECTING)
#define IsHandshake(x)          ((x)->status == STAT_HANDSHAKE)
#define IsMe(x)                 ((x)->status == STAT_ME)
#define IsUnknown(x)            ((x)->status == STAT_UNKNOWN)
#define IsServer(x)             ((x)->status == STAT_SERVER)
#define IsClient(x)             ((x)->status == STAT_CLIENT)

#define SetConnecting(x)        {(x)->status = STAT_CONNECTING; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetHandshake(x)         {(x)->status = STAT_HANDSHAKE; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetMe(x)                {(x)->status = STAT_ME; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetUnknown(x)           {(x)->status = STAT_UNKNOWN; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetServer(x)            {(x)->status = STAT_SERVER; \
                                 (x)->handler = SERVER_HANDLER; }

#define SetClient(x)            {(x)->status = STAT_CLIENT; \
                                 (x)->handler = CLIENT_HANDLER; }

#define MyConnect(x)            ((x)->connection != NULL)
#define MyClient(x)             (MyConnect(x) && IsClient(x))


/** Client flags */
enum
{
  FLAGS_PINGSENT      = 1 <<  0,  /**< Unreplied ping sent */
  FLAGS_DEADSOCKET    = 1 <<  1,  /**< Local socket is dead--Exiting soon */
  FLAGS_KILLED        = 1 <<  2,  /**< Prevents "QUIT" from being sent for this */
  FLAGS_CLOSING       = 1 <<  3,  /**< Set when closing to suppress errors */
  FLAGS_GOTID         = 1 <<  4,  /**< Successful ident lookup achieved */
  FLAGS_SENDQEX       = 1 <<  5,  /**< Sendq exceeded */
  FLAGS_IPHASH        = 1 <<  6,  /**< Iphashed this client */
  FLAGS_MARK          = 1 <<  7,  /**< Marked client */
  FLAGS_CANFLOOD      = 1 <<  8,  /**< Client has the ability to flood */
  FLAGS_EXEMPTKLINE   = 1 <<  9,  /**< Client is exempt from k-lines */
  FLAGS_NOLIMIT       = 1 << 10,  /**< Client is exempt from limits */
  FLAGS_PING_COOKIE   = 1 << 11,  /**< PING Cookie */
  FLAGS_FLOODDONE     = 1 << 12,  /**< Flood grace period has been ended. */
  FLAGS_EOB           = 1 << 13,  /**< Server has sent us an EOB */
  FLAGS_HIDDEN        = 1 << 14,  /**< A hidden server. Not shown in /links */
  FLAGS_BLOCKED       = 1 << 15,  /**< Must wait for COMM_SELECT_WRITE */
  FLAGS_EXEMPTRESV    = 1 << 16,  /**< Client is exempt from RESV */
  FLAGS_GOTUSER       = 1 << 17,  /**< If we received a USER command */
  FLAGS_LOOKUP_DONE   = 1 << 18,  /**< Client has completed the lookup process */
  FLAGS_FLOOD_NOTICED = 1 << 19,  /**< Notice to opers about this flooder has been sent */
  FLAGS_SERVICE       = 1 << 20,  /**< Client/server is a network service */
  FLAGS_TLS           = 1 << 21,  /**< User is connected via TLS (Transport Layer Security) */
  FLAGS_SQUIT         = 1 << 22,
  FLAGS_EXEMPTXLINE   = 1 << 23,  /**< Client is exempt from x-lines */
  FLAGS_CAP302        = 1 << 24,  /**< Client supports the IRCv3 CAP 302 extension */
  FLAGS_SPOOF         = 1 << 25,
  FLAGS_INTRODUCED    = 1 << 26,
};

#define HasFlag(x, y) ((x)->flags &   (y))
#define AddFlag(x, y) ((x)->flags |=  (y))
#define DelFlag(x, y) ((x)->flags &= ~(y))


extern uint64_t UMODE_BOT;
extern uint64_t UMODE_DEAF;
extern uint64_t UMODE_FARCONNECT;
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
extern uint64_t UMODE_FLOOD;
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
extern uint64_t UMODE_SERVNOTICE;
extern uint64_t UMODE_WALLOP;
extern uint64_t UMODE_CLOAK;
extern uint64_t UMODE_SPY;

/** irc-operator privilege flags */
enum
{
  OPER_FLAG_ADMIN          = 1 <<  0,  /**< Oper can set user mode +a */
  OPER_FLAG_CLOSE          = 1 <<  1,  /**< Oper can use CLOSE command */
  OPER_FLAG_CONNECT        = 1 <<  2,  /**< Oper can do local CONNECT */
  OPER_FLAG_CONNECT_REMOTE = 1 <<  3,  /**< Oper can do remote CONNECT */
  OPER_FLAG_DIE            = 1 <<  4,  /**< Oper can use DIE command */
  OPER_FLAG_DLINE          = 1 <<  5,  /**< Oper can use DLINE command */
  OPER_FLAG_GLOBOPS        = 1 <<  6,  /**< Oper can use GLOBOPS command */
  OPER_FLAG_JOIN_RESV      = 1 <<  7,  /**< Oper can use JOIN on resv {} channels */
  OPER_FLAG_KILL           = 1 <<  8,  /**< Oper can KILL local users */
  OPER_FLAG_KILL_REMOTE    = 1 <<  9,  /**< Oper can KILL remote users */
  OPER_FLAG_KLINE          = 1 << 10,  /**< Oper can use KLINE command */
  OPER_FLAG_LOCOPS         = 1 << 11,  /**< Oper can use LOCOPS command */
  OPER_FLAG_MODULE         = 1 << 12,  /**< Oper can use MODULE command */
  OPER_FLAG_NICK_RESV      = 1 << 13,  /**< Oper can use NICK on resv {} nicks */
  OPER_FLAG_OPME           = 1 << 14,  /**< Oper can use OPME command */
  OPER_FLAG_REHASH         = 1 << 15,  /**< Oper can use REHASH command */
  OPER_FLAG_REHASH_REMOTE  = 1 << 16,  /**< Oper can do remote REHASH command */
  OPER_FLAG_REMOTEBAN      = 1 << 17,  /**< Oper can set remote bans */
  OPER_FLAG_RESTART        = 1 << 18,  /**< Oper can use RESTART command */
  OPER_FLAG_RESV           = 1 << 19,  /**< Oper can use RESV command */
  OPER_FLAG_SET            = 1 << 20,  /**< Oper can use SET command */
  OPER_FLAG_SQUIT          = 1 << 21,  /**< Oper can do local SQUIT */
  OPER_FLAG_SQUIT_REMOTE   = 1 << 22,  /**< Oper can do remote SQUIT */
  OPER_FLAG_UNDLINE        = 1 << 23,  /**< Oper can use UNDLINE command */
  OPER_FLAG_UNKLINE        = 1 << 24,  /**< Oper can use UNKLINE command */
  OPER_FLAG_UNRESV         = 1 << 25,  /**< Oper can use UNRESV command */
  OPER_FLAG_UNXLINE        = 1 << 26,  /**< Oper can use UNXLINE command */
  OPER_FLAG_WALLOPS        = 1 << 27,  /**< Oper can use WALLOPS command */
  OPER_FLAG_XLINE          = 1 << 28,  /**< Oper can use XLINE command */
  OPER_FLAG_MESSAGE_MASS   = 1 << 29,  /**< Oper can send mass messages */
};

#define HasOFlag(x, y) ((x)->connection->operflags &   (y))
#define AddOFlag(x, y) ((x)->connection->operflags |=  (y))
#define DelOFlag(x, y) ((x)->connection->operflags &= ~(y))
#define ClrOFlag(x)    ((x)->connection->operflags = 0)



/* flags macros. */
#define IsDead(x)               ((x)->flags & FLAGS_DEADSOCKET)
#define SetDead(x)              ((x)->flags |= FLAGS_DEADSOCKET)
#define IsDefunct(x)            ((x)->flags & (FLAGS_DEADSOCKET|FLAGS_CLOSING|FLAGS_KILLED))
#define IsHidden(x)             ((x)->flags &  FLAGS_HIDDEN)


/** Server ban types */
enum
{
  CLIENT_BAN_KLINE,
  CLIENT_BAN_DLINE,
  CLIENT_BAN_XLINE
};

/** addr_mask_type enumeration */
enum addr_mask_type
{
  HIDE_IP,  /**< IP is hidden. Resolved hostname is shown instead */
  SHOW_IP,  /**< IP is shown. No parts of it are hidden or masked */
  MASK_IP   /**< IP is masked. 255.255.255.255 is shown instead */
};

/** Server structure */
struct Server
{
  list_t server_list;  /**< Servers on this server */
  list_t client_list;  /**< Clients on this server */
  char *initiator_name;  /**< Who activated this connection */
};

/** ListTask structure */
struct ListTask
{
  list_node_t node;  /**< Embedded list node used to link into listing_client_list */
  list_t show_mask;  /**< Channels to show */
  list_t hide_mask;  /**< Channels to hide */

  unsigned int hash_index;  /**< The hash bucket we are currently in */
  unsigned int users_min;
  unsigned int users_max;
  unsigned int created_min;  /**< Real time */
  unsigned int created_max;  /**< Real time */
  unsigned int topicts_min;  /**< Real time */
  unsigned int topicts_max;  /**< Real time */
  char *topic;
};

/** Connection structure
 * Allocated only for local clients, that are directly connected
 * to this server with a socket.
 */
struct Connection
{
  list_node_t node;

  unsigned int registration;
  unsigned int cap;  /**< Client CAP bit-field */
  unsigned int capab;  /**< Server CAPAB bit field */

  unsigned int operflags;  /**< IRC Operator privilege flags */
  unsigned int random_ping;  /**< Holding a 32bit value used for PING cookies */

  uintmax_t send_marker;  /**< Used to enforce one send per user */
  uintmax_t last_data;  /**< Last time data read from socket; monotonic time */
  uintmax_t last_ping;  /**< Last time data read from socket; currently this is a copy of last_data
                             which can be modified by check_pings_list; monotonic time */
  uintmax_t created_real;  /**< Time client was created; real time */
  uintmax_t created_monotonic;  /**< Time client was created; monotonic time */
  uintmax_t last_caller_id_time;  /**< Monotonic time */
  uintmax_t first_received_message_time;  /**< Monotonic time */
  uintmax_t last_privmsg;  /**< Last time we got a PRIVMSG; monotonic time */
  uintmax_t last_join_time;  /**< When this client last joined a channel; monotonic time */
  uintmax_t last_leave_time;  /**< When this client last left a channel; monotonic time */

  unsigned int join_leave_count;  /**< Count of JOIN/LEAVE in less than MIN_JOIN_LEAVE_TIME seconds */
  unsigned int oper_warn_count_down;  /**< Warn opers of this possible spambot every time this gets to 0 */
  unsigned int received_number_of_privmsgs;

  struct ListTask  *list_task;

  struct dbuf_queue buf_sendq;
  struct dbuf_queue buf_recvq;

  struct
  {
    unsigned int messages;  /**< Statistics: protocol messages sent/received */
    uintmax_t bytes;  /**< Statistics: total bytes sent/received */
  } recv, send;

  struct
  {
    unsigned int count;  /**< How many AWAY/INVITE/KNOCK/NICK requests client has sent */
    uintmax_t last_attempt;  /**< Last time the AWAY/INVITE/KNOCK/NICK request was issued; monotonic time */
  } away, invite, knock, nick;

  struct LookupRequest *lookup;
  struct Listener *listener;  /**< Listener accepted from */
  list_t acceptlist;  /**< Clients I'll allow to talk to me */
  list_t monitors;  /**< Chain of Monitor pointer blocks */
  list_t confs;  /**< Configuration record associated */
  list_t invited;  /**< Chain of invite pointer blocks */

  fde_t *fd;  /**< Pointer to fdlist.c:fd_table[] */

  /* Anti-flood stuff. We track how many messages were parsed and how
   * many we were allowed in the current second, and apply a simple
   * decay to avoid flooding.
   *   -- adrian
   */
  int sent_parsed;  /**< How many messages we've parsed in this second */

  char *password;  /**< Password supplied by the client/server */
};

/** Client structure */
struct Client
{
  list_node_t node;
  list_node_t lnode;  /**< Used for Server->servers/users */

  struct Connection *connection;  /**< Connection structure associated with this client */
  struct Client *hnext;  /**< For client hash table lookups by name */
  struct Client *idhnext;  /**< For SID hash table lookups by sid */
  struct Server *serv;  /**< ...defined, if this is a server */
  struct Client *servptr;  /**< Points to server this Client is on */
  struct Client *from;  /**< == self, if Local Client, *NEVER* NULL! */

  uintmax_t tsinfo;  /**< Timestamp on this nick; real time */

  unsigned int flags;  /**< Client flags */
  uint64_t umodes;  /**< User modes this client has set */
  unsigned int hopcount;  /**< Number of servers to this 0 = local */
  unsigned int status;  /**< Client type */
  unsigned int handler;  /**< Handler index */

  list_t whowas_list;
  list_t channel;  /**< Chain of channel pointer blocks */
  list_t svstags;  /**< List of ServicesTag items */

  struct io_addr addr;  /**< Real IP address */

  char *tls_certfp;  /**< TLS certificate fingerprint */
  char *tls_cipher;  /**< Exact copy of tls_get_cipher() */
  char *away;  /**< Client's AWAY message. Can be set/unset via AWAY command */

  char name[HOSTLEN + 1];  /**< Unique name for a client nick or host */
  char id[IDLEN + 1];  /**< Client ID, unique ID per client */
  char account[ACCOUNTLEN + 1];  /**< Services account */

  /** client->username is the username from ident or the USER message,
   * If the client is idented the USER message is ignored, otherwise
   * the username part of the USER message is put here prefixed with a
   * tilde depending on the auth{} block. Once a client has registered,
   * this field should be considered read-only.
   */
  char username[USERLEN + 1];  /**< client's username */

  /** client->host contains the resolved name or ip address as a string
   * for the user, it may be fiddled with for oper spoofing etc.
   * once it's changed the *real* address goes away.
   */
  char host[HOSTLEN + 1];  /**< Client's hostname. Can be faked/spoofed */

  /** client->realhost contains the resolved name or ip address as a string
   * for the user. Once a client has registered, this field should be
   * considered read-only.
   */
  char realhost[HOSTLEN + 1];  /**< Client's real hostname */


  /** client->info for unix clients will normally contain the info from the
   * gcos field in /etc/passwd but anything can go here.
   */
  char info[REALLEN + 1];  /**< Free form additional client info */

  /** client->sockhost contains the ip address gotten from the socket as a
   * string, this field should be considered read-only once the connection
   * has been made. (set in s_bsd.c only)
   */
  char sockhost[HOSTIPLEN + 1];  /**< This is the host name from the socket ip address as string */
};

extern struct Client me;
extern list_t listing_client_list;
extern list_t global_client_list;
extern list_t global_server_list;  /* global servers on the network */
extern list_t local_client_list;  /* local clients only ON this server */
extern list_t local_server_list;  /* local servers to this server ONLY */
extern list_t unknown_list;  /* unknown clients ON this server only */
extern list_t oper_list;  /* our opers, duplicated in local_client_list */

extern void client_exit(struct Client *, const char *);
extern void client_exit_fmt(struct Client *, const char *, ...) IO_AFP(2,3);
extern void conf_try_ban(struct Client *, int, const char *);
extern void check_conf_klines(void);
extern void client_init(void);
extern void dead_link_on_write(struct Client *, int);
extern void dead_link_on_read(struct Client *, int);
extern void exit_aborted_clients(void);
extern void free_exited_clients(void);
extern unsigned int client_get_idle_time(const struct Client *, const struct Client *);
extern struct Client *client_make(struct Client *);
extern struct Client *find_chasing(struct Client *, const char *);
extern struct Client *find_person(const struct Client *, const char *);
extern const char *client_get_name(const struct Client *, enum addr_mask_type);
#endif  /* INCLUDED_client_h */
