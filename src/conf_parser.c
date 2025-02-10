/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 27 "conf_parser.y"


#include "stdinc.h"
#include "defaults.h"
#include "ircd.h"
#include "list.h"
#include "command.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_gecos.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "event.h"
#include "id.h"
#include "log.h"
#include "irc_string.h"
#include "memory.h"
#include "module.h"
#include "nuh.h"
#include "server.h"
#include "address.h"
#include "listener.h"
#include "user.h"
#include "motd.h"
#include "cloak.h"
#include "flatten_links.h"

int yylex(void);

static struct
{
  struct
  {
    list_t list;
  } mask,
    leaf,
    hub;

  struct
  {
    char buf[IRCD_BUFSIZE];
  } name,
    nick,
    user,
    host,
    addr,
    bind,
    file,
    ciph,
    cert,
    rpass,
    spass,
    whois,
    modes,
    class,
    target,
    prepend,
    command;

  struct
  {
    unsigned int value;
  } flags,
    size,
    type,
    port,
    timeout,
    aftype,
    attributes,
    ping_freq,
    max_perip_local,
    max_perip_global,
    con_freq,
    min_idle,
    max_idle,
    max_total,
    max_sendq,
    max_recvq,
    max_channels,
    cidr_bitlen_ipv4,
    cidr_bitlen_ipv6,
    number_per_cidr;
} block_state;

static void
reset_block_state(void)
{
  list_node_t *node, *node_next;
  list_t *tab[] = { &block_state.mask.list,
                        &block_state.leaf.list, &block_state.hub.list, NULL };

  for (list_t **list = tab; *list; ++list)
  {
    LIST_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      io_free(node->data);
      list_remove(node, *list);
      list_free_node(node);
    }
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 180 "conf_parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CONF_PARSER_H_INCLUDED
# define YY_YY_CONF_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ACCEPT_PASSWORD = 258,         /* ACCEPT_PASSWORD  */
    ADMIN = 259,                   /* ADMIN  */
    AFTYPE = 260,                  /* AFTYPE  */
    ANTI_NICK_FLOOD = 261,         /* ANTI_NICK_FLOOD  */
    ANTI_SPAM_EXIT_MESSAGE_TIME = 262, /* ANTI_SPAM_EXIT_MESSAGE_TIME  */
    AUTOCONN = 263,                /* AUTOCONN  */
    AWAY_COUNT = 264,              /* AWAY_COUNT  */
    AWAY_TIME = 265,               /* AWAY_TIME  */
    BYTES = 266,                   /* BYTES  */
    KBYTES = 267,                  /* KBYTES  */
    MBYTES = 268,                  /* MBYTES  */
    CALLER_ID_WAIT = 269,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 270,               /* CAN_FLOOD  */
    CHANNEL = 271,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 272,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 273,        /* CIDR_BITLEN_IPV6  */
    CLASS = 274,                   /* CLASS  */
    CLIENT = 275,                  /* CLIENT  */
    CLOAK_ENABLED = 276,           /* CLOAK_ENABLED  */
    CLOAK_CIDR_LEN_IPV4 = 277,     /* CLOAK_CIDR_LEN_IPV4  */
    CLOAK_CIDR_LEN_IPV6 = 278,     /* CLOAK_CIDR_LEN_IPV6  */
    CLOAK_NUM_BITS = 279,          /* CLOAK_NUM_BITS  */
    CLOAK_SECRET = 280,            /* CLOAK_SECRET  */
    CLOAK_SUFFIX = 281,            /* CLOAK_SUFFIX  */
    CLOSE = 282,                   /* CLOSE  */
    CONNECT = 283,                 /* CONNECT  */
    CONNECTFREQ = 284,             /* CONNECTFREQ  */
    CORE = 285,                    /* CORE  */
    CYCLE_ON_HOST_CHANGE = 286,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 287,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 288,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 289, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 290, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 291,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 292,                   /* DEFER  */
    DENY = 293,                    /* DENY  */
    DESCRIPTION = 294,             /* DESCRIPTION  */
    DIE = 295,                     /* DIE  */
    DISABLE_AUTH = 296,            /* DISABLE_AUTH  */
    DISABLE_FAKE_CHANNELS = 297,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 298, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 299,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 300,         /* DLINE_MIN_CIDR6  */
    EMAIL = 301,                   /* EMAIL  */
    ENABLE_ADMIN = 302,            /* ENABLE_ADMIN  */
    ENABLE_EXTBANS = 303,          /* ENABLE_EXTBANS  */
    ENABLE_OWNER = 304,            /* ENABLE_OWNER  */
    ENCRYPTED = 305,               /* ENCRYPTED  */
    EXCEED_LIMIT = 306,            /* EXCEED_LIMIT  */
    EXEMPT = 307,                  /* EXEMPT  */
    FAILED_OPER_NOTICE = 308,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 309,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 310,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 311,      /* FLATTEN_LINKS_FILE  */
    GECOS = 312,                   /* GECOS  */
    GENERAL = 313,                 /* GENERAL  */
    HIDDEN = 314,                  /* HIDDEN  */
    HIDDEN_NAME = 315,             /* HIDDEN_NAME  */
    HIDE_CHANS = 316,              /* HIDE_CHANS  */
    HIDE_IDLE = 317,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 318,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 319,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 320,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 321,           /* HIDE_SERVICES  */
    HOST = 322,                    /* HOST  */
    HUB = 323,                     /* HUB  */
    HUB_MASK = 324,                /* HUB_MASK  */
    INVISIBLE_ON_CONNECT = 325,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 326,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 327,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 328,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 329,      /* INVITE_EXPIRE_TIME  */
    IP = 330,                      /* IP  */
    IRCD_AUTH = 331,               /* IRCD_AUTH  */
    IRCD_FLAGS = 332,              /* IRCD_FLAGS  */
    IRCD_SID = 333,                /* IRCD_SID  */
    JOIN = 334,                    /* JOIN  */
    KILL = 335,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 336,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 337,                   /* KLINE  */
    KLINE_EXEMPT = 338,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 339,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 340,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 341,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 342,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 343,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 344,               /* LEAF_MASK  */
    LISTEN = 345,                  /* LISTEN  */
    LOADMODULE = 346,              /* LOADMODULE  */
    MASK = 347,                    /* MASK  */
    MASS = 348,                    /* MASS  */
    MAX_ACCEPT = 349,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 350,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 351,                /* MAX_BANS  */
    MAX_BANS_LARGE = 352,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 353,            /* MAX_CHANNELS  */
    MAX_IDLE = 354,                /* MAX_IDLE  */
    MAX_INVITES = 355,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 356,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 357,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 358,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 359,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 360,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 361,              /* MAX_NUMBER  */
    MAX_TARGETS = 362,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 363,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 364,                 /* MESSAGE  */
    MIN_IDLE = 365,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 366,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 367,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 368,                  /* MODULE  */
    MODULE_BASE_PATH = 369,        /* MODULE_BASE_PATH  */
    MOTD = 370,                    /* MOTD  */
    MOTD_FILE = 371,               /* MOTD_FILE  */
    NAME = 372,                    /* NAME  */
    NEED_IDENT = 373,              /* NEED_IDENT  */
    NEED_PASSWORD = 374,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 375,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 376,            /* NETWORK_NAME  */
    NICK = 377,                    /* NICK  */
    NO_OPER_FLOOD = 378,           /* NO_OPER_FLOOD  */
    NO_TILDE = 379,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 380,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 381,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 382,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 383,             /* OPER_UMODES  */
    OPERATOR = 384,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 385,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 386,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 387,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 388,                /* PASSWORD  */
    PATH = 389,                    /* PATH  */
    PING_COOKIE = 390,             /* PING_COOKIE  */
    PING_TIME = 391,               /* PING_TIME  */
    PORT = 392,                    /* PORT  */
    RANDOM_IDLE = 393,             /* RANDOM_IDLE  */
    REASON = 394,                  /* REASON  */
    REDIRPORT = 395,               /* REDIRPORT  */
    REDIRSERV = 396,               /* REDIRSERV  */
    REHASH = 397,                  /* REHASH  */
    REMOTE = 398,                  /* REMOTE  */
    REMOTEBAN = 399,               /* REMOTEBAN  */
    RESIDENT = 400,                /* RESIDENT  */
    RESV = 401,                    /* RESV  */
    RESV_EXEMPT = 402,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 403,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 404,                 /* SECONDS  */
    MINUTES = 405,                 /* MINUTES  */
    HOURS = 406,                   /* HOURS  */
    DAYS = 407,                    /* DAYS  */
    WEEKS = 408,                   /* WEEKS  */
    MONTHS = 409,                  /* MONTHS  */
    YEARS = 410,                   /* YEARS  */
    SEND_PASSWORD = 411,           /* SEND_PASSWORD  */
    SENDQ = 412,                   /* SENDQ  */
    SERVERHIDE = 413,              /* SERVERHIDE  */
    SERVERINFO = 414,              /* SERVERINFO  */
    SHORT_MOTD = 415,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 416,       /* SPECIALS_IN_IDENT  */
    SPOOF = 417,                   /* SPOOF  */
    SQUIT = 418,                   /* SQUIT  */
    STATS_E_DISABLED = 419,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 420,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 421,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 422,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 423,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 424,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 425,       /* STATS_U_OPER_ONLY  */
    T_ALL = 426,                   /* T_ALL  */
    T_BIND = 427,                  /* T_BIND  */
    T_COMMAND = 428,               /* T_COMMAND  */
    T_CLUSTER = 429,               /* T_CLUSTER  */
    T_DEBUG = 430,                 /* T_DEBUG  */
    T_DLINE = 431,                 /* T_DLINE  */
    T_FILE = 432,                  /* T_FILE  */
    T_GLOBOPS = 433,               /* T_GLOBOPS  */
    T_IPV4 = 434,                  /* T_IPV4  */
    T_IPV6 = 435,                  /* T_IPV6  */
    T_LOCOPS = 436,                /* T_LOCOPS  */
    T_LOG = 437,                   /* T_LOG  */
    T_OPME = 438,                  /* T_OPME  */
    T_PREPEND = 439,               /* T_PREPEND  */
    T_PSEUDO = 440,                /* T_PSEUDO  */
    T_RECVQ = 441,                 /* T_RECVQ  */
    T_RESTART = 442,               /* T_RESTART  */
    T_SERVER = 443,                /* T_SERVER  */
    T_SERVICE = 444,               /* T_SERVICE  */
    T_SET = 445,                   /* T_SET  */
    T_SHARED = 446,                /* T_SHARED  */
    T_SIZE = 447,                  /* T_SIZE  */
    T_TARGET = 448,                /* T_TARGET  */
    T_TLS = 449,                   /* T_TLS  */
    T_UMODES = 450,                /* T_UMODES  */
    T_UNDLINE = 451,               /* T_UNDLINE  */
    T_UNLIMITED = 452,             /* T_UNLIMITED  */
    T_UNRESV = 453,                /* T_UNRESV  */
    T_UNXLINE = 454,               /* T_UNXLINE  */
    T_WEBIRC = 455,                /* T_WEBIRC  */
    TBOOL = 456,                   /* TBOOL  */
    THROTTLE_COUNT = 457,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 458,           /* THROTTLE_TIME  */
    TIMEOUT = 459,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 460,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 461, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 462,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 463,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 464, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 465,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 466, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 467,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 468,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 469,           /* TS_WARN_DELTA  */
    TWODOTS = 470,                 /* TWODOTS  */
    TYPE = 471,                    /* TYPE  */
    UNKLINE = 472,                 /* UNKLINE  */
    USE_LOGGING = 473,             /* USE_LOGGING  */
    USER = 474,                    /* USER  */
    VHOST = 475,                   /* VHOST  */
    VHOST6 = 476,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 477,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 478,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 479,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 480,                   /* XLINE  */
    XLINE_EXEMPT = 481,            /* XLINE_EXEMPT  */
    QSTRING = 482,                 /* QSTRING  */
    NUMBER = 483                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ACCEPT_PASSWORD 258
#define ADMIN 259
#define AFTYPE 260
#define ANTI_NICK_FLOOD 261
#define ANTI_SPAM_EXIT_MESSAGE_TIME 262
#define AUTOCONN 263
#define AWAY_COUNT 264
#define AWAY_TIME 265
#define BYTES 266
#define KBYTES 267
#define MBYTES 268
#define CALLER_ID_WAIT 269
#define CAN_FLOOD 270
#define CHANNEL 271
#define CIDR_BITLEN_IPV4 272
#define CIDR_BITLEN_IPV6 273
#define CLASS 274
#define CLIENT 275
#define CLOAK_ENABLED 276
#define CLOAK_CIDR_LEN_IPV4 277
#define CLOAK_CIDR_LEN_IPV6 278
#define CLOAK_NUM_BITS 279
#define CLOAK_SECRET 280
#define CLOAK_SUFFIX 281
#define CLOSE 282
#define CONNECT 283
#define CONNECTFREQ 284
#define CORE 285
#define CYCLE_ON_HOST_CHANGE 286
#define DEFAULT_FLOODCOUNT 287
#define DEFAULT_FLOODTIME 288
#define DEFAULT_JOIN_FLOOD_COUNT 289
#define DEFAULT_JOIN_FLOOD_TIME 290
#define DEFAULT_MAX_CLIENTS 291
#define DEFER 292
#define DENY 293
#define DESCRIPTION 294
#define DIE 295
#define DISABLE_AUTH 296
#define DISABLE_FAKE_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DLINE_MIN_CIDR 299
#define DLINE_MIN_CIDR6 300
#define EMAIL 301
#define ENABLE_ADMIN 302
#define ENABLE_EXTBANS 303
#define ENABLE_OWNER 304
#define ENCRYPTED 305
#define EXCEED_LIMIT 306
#define EXEMPT 307
#define FAILED_OPER_NOTICE 308
#define FLATTEN_LINKS 309
#define FLATTEN_LINKS_DELAY 310
#define FLATTEN_LINKS_FILE 311
#define GECOS 312
#define GENERAL 313
#define HIDDEN 314
#define HIDDEN_NAME 315
#define HIDE_CHANS 316
#define HIDE_IDLE 317
#define HIDE_IDLE_FROM_OPERS 318
#define HIDE_SERVER_IPS 319
#define HIDE_SERVERS 320
#define HIDE_SERVICES 321
#define HOST 322
#define HUB 323
#define HUB_MASK 324
#define INVISIBLE_ON_CONNECT 325
#define INVITE_CLIENT_COUNT 326
#define INVITE_CLIENT_TIME 327
#define INVITE_DELAY_CHANNEL 328
#define INVITE_EXPIRE_TIME 329
#define IP 330
#define IRCD_AUTH 331
#define IRCD_FLAGS 332
#define IRCD_SID 333
#define JOIN 334
#define KILL 335
#define KILL_CHASE_TIME_LIMIT 336
#define KLINE 337
#define KLINE_EXEMPT 338
#define KLINE_MIN_CIDR 339
#define KLINE_MIN_CIDR6 340
#define KNOCK_CLIENT_COUNT 341
#define KNOCK_CLIENT_TIME 342
#define KNOCK_DELAY_CHANNEL 343
#define LEAF_MASK 344
#define LISTEN 345
#define LOADMODULE 346
#define MASK 347
#define MASS 348
#define MAX_ACCEPT 349
#define MAX_AWAY_LENGTH 350
#define MAX_BANS 351
#define MAX_BANS_LARGE 352
#define MAX_CHANNELS 353
#define MAX_IDLE 354
#define MAX_INVITES 355
#define MAX_KICK_LENGTH 356
#define MAX_MONITOR 357
#define MAX_NICK_CHANGES 358
#define MAX_NICK_LENGTH 359
#define MAX_NICK_TIME 360
#define MAX_NUMBER 361
#define MAX_TARGETS 362
#define MAX_TOPIC_LENGTH 363
#define MESSAGE 364
#define MIN_IDLE 365
#define MIN_NONWILDCARD 366
#define MIN_NONWILDCARD_SIMPLE 367
#define MODULE 368
#define MODULE_BASE_PATH 369
#define MOTD 370
#define MOTD_FILE 371
#define NAME 372
#define NEED_IDENT 373
#define NEED_PASSWORD 374
#define NETWORK_DESCRIPTION 375
#define NETWORK_NAME 376
#define NICK 377
#define NO_OPER_FLOOD 378
#define NO_TILDE 379
#define NUMBER_PER_CIDR 380
#define NUMBER_PER_IP_GLOBAL 381
#define NUMBER_PER_IP_LOCAL 382
#define OPER_UMODES 383
#define OPERATOR 384
#define OPERS_BYPASS_CALLERID 385
#define PACE_WAIT 386
#define PACE_WAIT_SIMPLE 387
#define PASSWORD 388
#define PATH 389
#define PING_COOKIE 390
#define PING_TIME 391
#define PORT 392
#define RANDOM_IDLE 393
#define REASON 394
#define REDIRPORT 395
#define REDIRSERV 396
#define REHASH 397
#define REMOTE 398
#define REMOTEBAN 399
#define RESIDENT 400
#define RESV 401
#define RESV_EXEMPT 402
#define RSA_PRIVATE_KEY_FILE 403
#define SECONDS 404
#define MINUTES 405
#define HOURS 406
#define DAYS 407
#define WEEKS 408
#define MONTHS 409
#define YEARS 410
#define SEND_PASSWORD 411
#define SENDQ 412
#define SERVERHIDE 413
#define SERVERINFO 414
#define SHORT_MOTD 415
#define SPECIALS_IN_IDENT 416
#define SPOOF 417
#define SQUIT 418
#define STATS_E_DISABLED 419
#define STATS_I_OPER_ONLY 420
#define STATS_K_OPER_ONLY 421
#define STATS_M_OPER_ONLY 422
#define STATS_O_OPER_ONLY 423
#define STATS_P_OPER_ONLY 424
#define STATS_U_OPER_ONLY 425
#define T_ALL 426
#define T_BIND 427
#define T_COMMAND 428
#define T_CLUSTER 429
#define T_DEBUG 430
#define T_DLINE 431
#define T_FILE 432
#define T_GLOBOPS 433
#define T_IPV4 434
#define T_IPV6 435
#define T_LOCOPS 436
#define T_LOG 437
#define T_OPME 438
#define T_PREPEND 439
#define T_PSEUDO 440
#define T_RECVQ 441
#define T_RESTART 442
#define T_SERVER 443
#define T_SERVICE 444
#define T_SET 445
#define T_SHARED 446
#define T_SIZE 447
#define T_TARGET 448
#define T_TLS 449
#define T_UMODES 450
#define T_UNDLINE 451
#define T_UNLIMITED 452
#define T_UNRESV 453
#define T_UNXLINE 454
#define T_WEBIRC 455
#define TBOOL 456
#define THROTTLE_COUNT 457
#define THROTTLE_TIME 458
#define TIMEOUT 459
#define TLS_CERTIFICATE_FILE 460
#define TLS_CERTIFICATE_FINGERPRINT 461
#define TLS_CIPHER_LIST 462
#define TLS_CIPHER_SUITES 463
#define TLS_CONNECTION_REQUIRED 464
#define TLS_DH_PARAM_FILE 465
#define TLS_MESSAGE_DIGEST_ALGORITHM 466
#define TLS_SUPPORTED_GROUPS 467
#define TS_MAX_DELTA 468
#define TS_WARN_DELTA 469
#define TWODOTS 470
#define TYPE 471
#define UNKLINE 472
#define USE_LOGGING 473
#define USER 474
#define VHOST 475
#define VHOST6 476
#define WARN_NO_CONNECT_BLOCK 477
#define WHOIS 478
#define WHOWAS_HISTORY_LENGTH 479
#define XLINE 480
#define XLINE_EXEMPT 481
#define QSTRING 482
#define NUMBER 483

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 136 "conf_parser.y"

  int number;
  char *string;

#line 694 "conf_parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ACCEPT_PASSWORD = 3,            /* ACCEPT_PASSWORD  */
  YYSYMBOL_ADMIN = 4,                      /* ADMIN  */
  YYSYMBOL_AFTYPE = 5,                     /* AFTYPE  */
  YYSYMBOL_ANTI_NICK_FLOOD = 6,            /* ANTI_NICK_FLOOD  */
  YYSYMBOL_ANTI_SPAM_EXIT_MESSAGE_TIME = 7, /* ANTI_SPAM_EXIT_MESSAGE_TIME  */
  YYSYMBOL_AUTOCONN = 8,                   /* AUTOCONN  */
  YYSYMBOL_AWAY_COUNT = 9,                 /* AWAY_COUNT  */
  YYSYMBOL_AWAY_TIME = 10,                 /* AWAY_TIME  */
  YYSYMBOL_BYTES = 11,                     /* BYTES  */
  YYSYMBOL_KBYTES = 12,                    /* KBYTES  */
  YYSYMBOL_MBYTES = 13,                    /* MBYTES  */
  YYSYMBOL_CALLER_ID_WAIT = 14,            /* CALLER_ID_WAIT  */
  YYSYMBOL_CAN_FLOOD = 15,                 /* CAN_FLOOD  */
  YYSYMBOL_CHANNEL = 16,                   /* CHANNEL  */
  YYSYMBOL_CIDR_BITLEN_IPV4 = 17,          /* CIDR_BITLEN_IPV4  */
  YYSYMBOL_CIDR_BITLEN_IPV6 = 18,          /* CIDR_BITLEN_IPV6  */
  YYSYMBOL_CLASS = 19,                     /* CLASS  */
  YYSYMBOL_CLIENT = 20,                    /* CLIENT  */
  YYSYMBOL_CLOAK_ENABLED = 21,             /* CLOAK_ENABLED  */
  YYSYMBOL_CLOAK_CIDR_LEN_IPV4 = 22,       /* CLOAK_CIDR_LEN_IPV4  */
  YYSYMBOL_CLOAK_CIDR_LEN_IPV6 = 23,       /* CLOAK_CIDR_LEN_IPV6  */
  YYSYMBOL_CLOAK_NUM_BITS = 24,            /* CLOAK_NUM_BITS  */
  YYSYMBOL_CLOAK_SECRET = 25,              /* CLOAK_SECRET  */
  YYSYMBOL_CLOAK_SUFFIX = 26,              /* CLOAK_SUFFIX  */
  YYSYMBOL_CLOSE = 27,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 28,                   /* CONNECT  */
  YYSYMBOL_CONNECTFREQ = 29,               /* CONNECTFREQ  */
  YYSYMBOL_CORE = 30,                      /* CORE  */
  YYSYMBOL_CYCLE_ON_HOST_CHANGE = 31,      /* CYCLE_ON_HOST_CHANGE  */
  YYSYMBOL_DEFAULT_FLOODCOUNT = 32,        /* DEFAULT_FLOODCOUNT  */
  YYSYMBOL_DEFAULT_FLOODTIME = 33,         /* DEFAULT_FLOODTIME  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_COUNT = 34,  /* DEFAULT_JOIN_FLOOD_COUNT  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_TIME = 35,   /* DEFAULT_JOIN_FLOOD_TIME  */
  YYSYMBOL_DEFAULT_MAX_CLIENTS = 36,       /* DEFAULT_MAX_CLIENTS  */
  YYSYMBOL_DEFER = 37,                     /* DEFER  */
  YYSYMBOL_DENY = 38,                      /* DENY  */
  YYSYMBOL_DESCRIPTION = 39,               /* DESCRIPTION  */
  YYSYMBOL_DIE = 40,                       /* DIE  */
  YYSYMBOL_DISABLE_AUTH = 41,              /* DISABLE_AUTH  */
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 42,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 43,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 44,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 45,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 46,                     /* EMAIL  */
  YYSYMBOL_ENABLE_ADMIN = 47,              /* ENABLE_ADMIN  */
  YYSYMBOL_ENABLE_EXTBANS = 48,            /* ENABLE_EXTBANS  */
  YYSYMBOL_ENABLE_OWNER = 49,              /* ENABLE_OWNER  */
  YYSYMBOL_ENCRYPTED = 50,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 51,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 52,                    /* EXEMPT  */
  YYSYMBOL_FAILED_OPER_NOTICE = 53,        /* FAILED_OPER_NOTICE  */
  YYSYMBOL_FLATTEN_LINKS = 54,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 55,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 56,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 57,                     /* GECOS  */
  YYSYMBOL_GENERAL = 58,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 59,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 60,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 61,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 62,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 63,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVER_IPS = 64,           /* HIDE_SERVER_IPS  */
  YYSYMBOL_HIDE_SERVERS = 65,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 66,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 67,                      /* HOST  */
  YYSYMBOL_HUB = 68,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 69,                  /* HUB_MASK  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 70,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 71,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 72,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 73,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 74,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 75,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 76,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 77,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 78,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 79,                      /* JOIN  */
  YYSYMBOL_KILL = 80,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 81,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 82,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 83,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 84,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 85,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 86,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 87,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 88,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 89,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 90,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 91,                /* LOADMODULE  */
  YYSYMBOL_MASK = 92,                      /* MASK  */
  YYSYMBOL_MASS = 93,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 94,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 95,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 96,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 97,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 98,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 99,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 100,              /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 101,          /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 102,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 103,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 104,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 105,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 106,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 107,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 108,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 109,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 110,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 111,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 112,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 113,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 114,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 115,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 116,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 117,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 118,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 119,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 120,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 121,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 122,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 123,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 124,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 125,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 126,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 127,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 128,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 129,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 130,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 131,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 132,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 133,                 /* PASSWORD  */
  YYSYMBOL_PATH = 134,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 135,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 136,                /* PING_TIME  */
  YYSYMBOL_PORT = 137,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 138,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 139,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 140,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 141,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 142,                   /* REHASH  */
  YYSYMBOL_REMOTE = 143,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 144,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 145,                 /* RESIDENT  */
  YYSYMBOL_RESV = 146,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 147,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 148,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 149,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 150,                  /* MINUTES  */
  YYSYMBOL_HOURS = 151,                    /* HOURS  */
  YYSYMBOL_DAYS = 152,                     /* DAYS  */
  YYSYMBOL_WEEKS = 153,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 154,                   /* MONTHS  */
  YYSYMBOL_YEARS = 155,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 156,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 157,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 158,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 159,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 160,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 161,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 162,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 163,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 164,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 165,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 166,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 167,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 168,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 169,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 170,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 171,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 172,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 173,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 174,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 175,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 176,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 177,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 178,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 179,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 180,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 181,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 182,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 183,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 184,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 185,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 186,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 187,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 188,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 189,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 190,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 191,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 192,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 193,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 194,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 195,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 196,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 197,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 198,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 199,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 200,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 201,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 202,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 203,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 204,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 205,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 206, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 207,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 208,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 209,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 210,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 211, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 212,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 213,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 214,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 215,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 216,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 217,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 218,              /* USE_LOGGING  */
  YYSYMBOL_USER = 219,                     /* USER  */
  YYSYMBOL_VHOST = 220,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 221,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 222,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 223,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 224,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 225,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 226,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 227,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 228,                   /* NUMBER  */
  YYSYMBOL_229_ = 229,                     /* ';'  */
  YYSYMBOL_230_ = 230,                     /* '}'  */
  YYSYMBOL_231_ = 231,                     /* '='  */
  YYSYMBOL_232_ = 232,                     /* ':'  */
  YYSYMBOL_233_ = 233,                     /* ','  */
  YYSYMBOL_234_ = 234,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 235,                 /* $accept  */
  YYSYMBOL_conf = 236,                     /* conf  */
  YYSYMBOL_conf_item = 237,                /* conf_item  */
  YYSYMBOL_timespec_ = 238,                /* timespec_  */
  YYSYMBOL_timespec = 239,                 /* timespec  */
  YYSYMBOL_sizespec_ = 240,                /* sizespec_  */
  YYSYMBOL_sizespec = 241,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 242,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 243,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 244,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 245,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 246,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 247,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 248,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 249,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 250, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 251, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 252, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 253, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 254, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 255, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 256, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 257,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 258,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 259,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 260,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 261, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 262, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 263, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 264, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 265,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 266,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 267,              /* admin_entry  */
  YYSYMBOL_admin_items = 268,              /* admin_items  */
  YYSYMBOL_admin_item = 269,               /* admin_item  */
  YYSYMBOL_admin_name = 270,               /* admin_name  */
  YYSYMBOL_admin_email = 271,              /* admin_email  */
  YYSYMBOL_admin_description = 272,        /* admin_description  */
  YYSYMBOL_motd_entry = 273,               /* motd_entry  */
  YYSYMBOL_274_1 = 274,                    /* $@1  */
  YYSYMBOL_motd_items = 275,               /* motd_items  */
  YYSYMBOL_motd_item = 276,                /* motd_item  */
  YYSYMBOL_motd_mask = 277,                /* motd_mask  */
  YYSYMBOL_motd_file = 278,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 279,             /* pseudo_entry  */
  YYSYMBOL_280_2 = 280,                    /* $@2  */
  YYSYMBOL_pseudo_items = 281,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 282,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 283,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 284,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 285,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 286,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 287,            /* logging_entry  */
  YYSYMBOL_logging_items = 288,            /* logging_items  */
  YYSYMBOL_logging_item = 289,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 290,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 291,       /* logging_file_entry  */
  YYSYMBOL_292_3 = 292,                    /* $@3  */
  YYSYMBOL_logging_file_items = 293,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 294,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 295,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 296,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 297,        /* logging_file_type  */
  YYSYMBOL_298_4 = 298,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 299,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 300,               /* oper_entry  */
  YYSYMBOL_301_5 = 301,                    /* $@5  */
  YYSYMBOL_oper_items = 302,               /* oper_items  */
  YYSYMBOL_oper_item = 303,                /* oper_item  */
  YYSYMBOL_oper_name = 304,                /* oper_name  */
  YYSYMBOL_oper_user = 305,                /* oper_user  */
  YYSYMBOL_oper_password = 306,            /* oper_password  */
  YYSYMBOL_oper_whois = 307,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 308,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 309, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 310, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 311,               /* oper_class  */
  YYSYMBOL_oper_umodes = 312,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 313,               /* oper_flags  */
  YYSYMBOL_314_6 = 314,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 315,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 316,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 317,              /* class_entry  */
  YYSYMBOL_318_7 = 318,                    /* $@7  */
  YYSYMBOL_class_items = 319,              /* class_items  */
  YYSYMBOL_class_item = 320,               /* class_item  */
  YYSYMBOL_class_name = 321,               /* class_name  */
  YYSYMBOL_class_ping_time = 322,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 323, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 324, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 325,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 326,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 327,         /* class_max_number  */
  YYSYMBOL_class_sendq = 328,              /* class_sendq  */
  YYSYMBOL_class_recvq = 329,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 330,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 331,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 332,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 333,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 334,           /* class_max_idle  */
  YYSYMBOL_class_flags = 335,              /* class_flags  */
  YYSYMBOL_336_8 = 336,                    /* $@8  */
  YYSYMBOL_class_flags_items = 337,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 338,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 339,             /* listen_entry  */
  YYSYMBOL_340_9 = 340,                    /* $@9  */
  YYSYMBOL_listen_flags = 341,             /* listen_flags  */
  YYSYMBOL_342_10 = 342,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 343,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 344,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 345,             /* listen_items  */
  YYSYMBOL_listen_item = 346,              /* listen_item  */
  YYSYMBOL_listen_port = 347,              /* listen_port  */
  YYSYMBOL_348_11 = 348,                   /* $@11  */
  YYSYMBOL_port_items = 349,               /* port_items  */
  YYSYMBOL_port_item = 350,                /* port_item  */
  YYSYMBOL_listen_address = 351,           /* listen_address  */
  YYSYMBOL_listen_host = 352,              /* listen_host  */
  YYSYMBOL_auth_entry = 353,               /* auth_entry  */
  YYSYMBOL_354_12 = 354,                   /* $@12  */
  YYSYMBOL_auth_items = 355,               /* auth_items  */
  YYSYMBOL_auth_item = 356,                /* auth_item  */
  YYSYMBOL_auth_user = 357,                /* auth_user  */
  YYSYMBOL_auth_passwd = 358,              /* auth_passwd  */
  YYSYMBOL_auth_class = 359,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 360,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 361,               /* auth_flags  */
  YYSYMBOL_362_13 = 362,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 363,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 364,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 365,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 366,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 367,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 368,               /* resv_entry  */
  YYSYMBOL_369_14 = 369,                   /* $@14  */
  YYSYMBOL_resv_items = 370,               /* resv_items  */
  YYSYMBOL_resv_item = 371,                /* resv_item  */
  YYSYMBOL_resv_mask = 372,                /* resv_mask  */
  YYSYMBOL_resv_reason = 373,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 374,              /* resv_exempt  */
  YYSYMBOL_service_entry = 375,            /* service_entry  */
  YYSYMBOL_service_items = 376,            /* service_items  */
  YYSYMBOL_service_item = 377,             /* service_item  */
  YYSYMBOL_service_name = 378,             /* service_name  */
  YYSYMBOL_shared_entry = 379,             /* shared_entry  */
  YYSYMBOL_380_15 = 380,                   /* $@15  */
  YYSYMBOL_shared_items = 381,             /* shared_items  */
  YYSYMBOL_shared_item = 382,              /* shared_item  */
  YYSYMBOL_shared_name = 383,              /* shared_name  */
  YYSYMBOL_shared_user = 384,              /* shared_user  */
  YYSYMBOL_shared_type = 385,              /* shared_type  */
  YYSYMBOL_386_16 = 386,                   /* $@16  */
  YYSYMBOL_shared_types = 387,             /* shared_types  */
  YYSYMBOL_shared_type_item = 388,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 389,            /* cluster_entry  */
  YYSYMBOL_390_17 = 390,                   /* $@17  */
  YYSYMBOL_cluster_items = 391,            /* cluster_items  */
  YYSYMBOL_cluster_item = 392,             /* cluster_item  */
  YYSYMBOL_cluster_name = 393,             /* cluster_name  */
  YYSYMBOL_cluster_type = 394,             /* cluster_type  */
  YYSYMBOL_395_18 = 395,                   /* $@18  */
  YYSYMBOL_cluster_types = 396,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 397,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 398,            /* connect_entry  */
  YYSYMBOL_399_19 = 399,                   /* $@19  */
  YYSYMBOL_connect_items = 400,            /* connect_items  */
  YYSYMBOL_connect_item = 401,             /* connect_item  */
  YYSYMBOL_connect_name = 402,             /* connect_name  */
  YYSYMBOL_connect_host = 403,             /* connect_host  */
  YYSYMBOL_connect_timeout = 404,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 405,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 406,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 407,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 408, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 409,             /* connect_port  */
  YYSYMBOL_connect_aftype = 410,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 411,            /* connect_flags  */
  YYSYMBOL_412_20 = 412,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 413,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 414,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 415,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 416,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 417,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 418,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 419,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 420,               /* kill_entry  */
  YYSYMBOL_421_21 = 421,                   /* $@21  */
  YYSYMBOL_kill_items = 422,               /* kill_items  */
  YYSYMBOL_kill_item = 423,                /* kill_item  */
  YYSYMBOL_kill_user = 424,                /* kill_user  */
  YYSYMBOL_kill_reason = 425,              /* kill_reason  */
  YYSYMBOL_deny_entry = 426,               /* deny_entry  */
  YYSYMBOL_427_22 = 427,                   /* $@22  */
  YYSYMBOL_deny_items = 428,               /* deny_items  */
  YYSYMBOL_deny_item = 429,                /* deny_item  */
  YYSYMBOL_deny_ip = 430,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 431,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 432,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 433,             /* exempt_items  */
  YYSYMBOL_exempt_item = 434,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 435,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 436,              /* gecos_entry  */
  YYSYMBOL_437_23 = 437,                   /* $@23  */
  YYSYMBOL_gecos_items = 438,              /* gecos_items  */
  YYSYMBOL_gecos_item = 439,               /* gecos_item  */
  YYSYMBOL_gecos_name = 440,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 441,             /* gecos_reason  */
  YYSYMBOL_general_entry = 442,            /* general_entry  */
  YYSYMBOL_general_items = 443,            /* general_items  */
  YYSYMBOL_general_item = 444,             /* general_item  */
  YYSYMBOL_general_away_count = 445,       /* general_away_count  */
  YYSYMBOL_general_away_time = 446,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 447,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 448, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 449, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 450,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 451,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 452,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 453,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 454, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 455, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 456,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 457,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 458, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 459,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 460,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 461, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 462,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 463,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 464, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 465, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 466, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 467, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 468, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 469, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 470, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 471, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 472, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 473,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 474,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 475, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 476, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 477,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 478,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 479, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 480,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 481,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 482,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 483,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 484,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 485,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 486,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 487, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 488, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 489, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 490,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 491, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 492, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 493,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 494,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 495,     /* general_cloak_suffix  */
  YYSYMBOL_channel_entry = 496,            /* channel_entry  */
  YYSYMBOL_channel_items = 497,            /* channel_items  */
  YYSYMBOL_channel_item = 498,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 499,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 500,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 501,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 502, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 503, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 504, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 505, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 506, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 507, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 508, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 509, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 510,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 511,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 512,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 513,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 514,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 515, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 516, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 517,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 518,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 519,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 520, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 521, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 522, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 523, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 524,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 525, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 526,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 527,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 528 /* serverhide_hide_server_ips  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  611
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1281

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   483


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   233,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   232,   229,
       2,   231,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   230,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   366,   366,   367,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   398,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   409,
     409,   410,   411,   412,   413,   420,   430,   437,   439,   441,
     441,   443,   447,   457,   459,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   480,   489,   498,   507,   516,   525,
     534,   543,   558,   573,   583,   597,   606,   629,   652,   660,
     669,   679,   681,   681,   682,   683,   684,   685,   687,   696,
     705,   719,   718,   736,   736,   737,   737,   737,   739,   745,
     756,   755,   774,   774,   775,   775,   775,   775,   775,   777,
     783,   789,   795,   818,   819,   819,   821,   821,   822,   824,
     831,   831,   844,   845,   847,   847,   848,   848,   850,   858,
     861,   867,   866,   872,   876,   880,   884,   888,   892,   896,
     900,   911,   910,   976,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   985,   986,   987,   989,   995,  1001,  1007,
    1013,  1024,  1030,  1041,  1047,  1054,  1053,  1059,  1059,  1060,
    1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,  1096,  1100,
    1104,  1108,  1112,  1116,  1120,  1124,  1128,  1132,  1136,  1140,
    1144,  1148,  1152,  1156,  1160,  1164,  1168,  1172,  1183,  1182,
    1238,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,
    1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1256,  1262,
    1268,  1274,  1280,  1286,  1292,  1298,  1304,  1311,  1317,  1323,
    1329,  1338,  1348,  1347,  1353,  1353,  1354,  1358,  1369,  1368,
    1375,  1374,  1379,  1379,  1380,  1384,  1388,  1392,  1396,  1402,
    1402,  1403,  1403,  1403,  1403,  1403,  1405,  1405,  1407,  1407,
    1409,  1422,  1439,  1445,  1456,  1455,  1503,  1503,  1504,  1505,
    1506,  1507,  1508,  1509,  1510,  1511,  1512,  1514,  1520,  1526,
    1532,  1544,  1543,  1549,  1549,  1550,  1554,  1558,  1562,  1566,
    1570,  1574,  1578,  1582,  1588,  1602,  1611,  1625,  1624,  1639,
    1639,  1640,  1640,  1640,  1640,  1642,  1648,  1654,  1664,  1666,
    1666,  1667,  1667,  1669,  1686,  1685,  1708,  1708,  1709,  1709,
    1709,  1709,  1711,  1717,  1737,  1736,  1742,  1742,  1743,  1747,
    1751,  1755,  1759,  1763,  1767,  1771,  1775,  1779,  1790,  1789,
    1808,  1808,  1809,  1809,  1809,  1811,  1818,  1817,  1823,  1823,
    1824,  1828,  1832,  1836,  1840,  1844,  1848,  1852,  1856,  1860,
    1871,  1870,  1948,  1948,  1949,  1950,  1951,  1952,  1953,  1954,
    1955,  1956,  1957,  1958,  1959,  1960,  1961,  1962,  1963,  1964,
    1966,  1972,  1978,  1984,  1990,  2003,  2016,  2022,  2028,  2032,
    2039,  2038,  2043,  2043,  2044,  2048,  2054,  2065,  2071,  2077,
    2083,  2099,  2098,  2122,  2122,  2123,  2123,  2123,  2125,  2145,
    2156,  2155,  2180,  2180,  2181,  2181,  2181,  2183,  2189,  2199,
    2201,  2201,  2202,  2202,  2204,  2222,  2221,  2242,  2242,  2243,
    2243,  2243,  2245,  2251,  2261,  2263,  2263,  2264,  2265,  2266,
    2267,  2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,  2276,
    2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,
    2287,  2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,
    2297,  2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,
    2307,  2308,  2309,  2310,  2311,  2312,  2313,  2314,  2315,  2318,
    2323,  2328,  2333,  2338,  2343,  2348,  2353,  2358,  2363,  2368,
    2373,  2378,  2383,  2388,  2393,  2401,  2406,  2411,  2416,  2421,
    2426,  2431,  2436,  2441,  2446,  2451,  2456,  2461,  2466,  2471,
    2476,  2481,  2486,  2491,  2496,  2501,  2506,  2511,  2516,  2521,
    2530,  2535,  2540,  2545,  2550,  2567,  2575,  2583,  2591,  2601,
    2614,  2616,  2616,  2617,  2618,  2619,  2620,  2621,  2622,  2623,
    2624,  2625,  2626,  2627,  2628,  2629,  2630,  2631,  2632,  2633,
    2634,  2635,  2637,  2642,  2648,  2654,  2659,  2664,  2669,  2674,
    2679,  2684,  2689,  2694,  2699,  2704,  2709,  2714,  2737,  2742,
    2751,  2753,  2753,  2754,  2755,  2756,  2757,  2758,  2759,  2760,
    2761,  2762,  2763,  2765,  2771,  2787,  2796,  2802,  2808,  2814,
    2823,  2829
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ACCEPT_PASSWORD",
  "ADMIN", "AFTYPE", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "AWAY_COUNT", "AWAY_TIME", "BYTES", "KBYTES", "MBYTES",
  "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CLASS", "CLIENT", "CLOAK_ENABLED",
  "CLOAK_CIDR_LEN_IPV4", "CLOAK_CIDR_LEN_IPV6", "CLOAK_NUM_BITS",
  "CLOAK_SECRET", "CLOAK_SUFFIX", "CLOSE", "CONNECT", "CONNECTFREQ",
  "CORE", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DEFER", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "EMAIL",
  "ENABLE_ADMIN", "ENABLE_EXTBANS", "ENABLE_OWNER", "ENCRYPTED",
  "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "FLATTEN_LINKS",
  "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL",
  "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN",
  "LOADMODULE", "MASK", "MASS", "MAX_ACCEPT", "MAX_AWAY_LENGTH",
  "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES",
  "MAX_KICK_LENGTH", "MAX_MONITOR", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH",
  "MESSAGE", "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE",
  "MODULE", "MODULE_BASE_PATH", "MOTD", "MOTD_FILE", "NAME", "NEED_IDENT",
  "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME", "NICK",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
  "NUMBER_PER_IP_LOCAL", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "RANDOM_IDLE", "REASON",
  "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN", "RESIDENT",
  "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPECIALS_IN_IDENT", "SPOOF",
  "SQUIT", "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_COMMAND", "T_CLUSTER",
  "T_DEBUG", "T_DLINE", "T_FILE", "T_GLOBOPS", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_LOG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_TARGET", "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME",
  "TIMEOUT", "TLS_CERTIFICATE_FILE", "TLS_CERTIFICATE_FINGERPRINT",
  "TLS_CIPHER_LIST", "TLS_CIPHER_SUITES", "TLS_CONNECTION_REQUIRED",
  "TLS_DH_PARAM_FILE", "TLS_MESSAGE_DIGEST_ALGORITHM",
  "TLS_SUPPORTED_GROUPS", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE",
  "XLINE_EXEMPT", "QSTRING", "NUMBER", "';'", "'}'", "'='", "':'", "','",
  "'{'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "module_base_path_entry", "loadmodule_entry",
  "module_attributes", "module_attributes_items", "module_attributes_item",
  "serverinfo_entry", "serverinfo_items", "serverinfo_item",
  "serverinfo_tls_certificate_file", "serverinfo_rsa_private_key_file",
  "serverinfo_tls_dh_param_file", "serverinfo_tls_cipher_list",
  "serverinfo_tls_cipher_suites",
  "serverinfo_tls_message_digest_algorithm",
  "serverinfo_tls_supported_groups", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_description", "serverinfo_default_max_clients",
  "serverinfo_max_nick_length", "serverinfo_max_topic_length",
  "serverinfo_motd_file", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "motd_entry", "$@1", "motd_items", "motd_item", "motd_mask", "motd_file",
  "pseudo_entry", "$@2", "pseudo_items", "pseudo_item", "pseudo_command",
  "pseudo_name", "pseudo_prepend", "pseudo_target", "logging_entry",
  "logging_items", "logging_item", "logging_use_logging",
  "logging_file_entry", "$@3", "logging_file_items", "logging_file_item",
  "logging_file_name", "logging_file_size", "logging_file_type", "$@4",
  "logging_file_type_item", "oper_entry", "$@5", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_tls_certificate_fingerprint",
  "oper_tls_connection_required", "oper_class", "oper_umodes",
  "oper_flags", "$@6", "oper_flags_items", "oper_flags_item",
  "class_entry", "$@7", "class_items", "class_item", "class_name",
  "class_ping_time", "class_number_per_ip_local",
  "class_number_per_ip_global", "class_connectfreq", "class_max_channels",
  "class_max_number", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@8", "class_flags_items", "class_flags_item",
  "listen_entry", "$@9", "listen_flags", "$@10", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@11", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@12", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@13",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@14", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@15",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@16", "shared_types", "shared_type_item",
  "cluster_entry", "$@17", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@18", "cluster_types", "cluster_type_item",
  "connect_entry", "$@19", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_timeout", "connect_bind",
  "connect_send_password", "connect_accept_password",
  "connect_tls_certificate_fingerprint", "connect_port", "connect_aftype",
  "connect_flags", "$@20", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_tls_cipher_list", "kill_entry", "$@21",
  "kill_items", "kill_item", "kill_user", "kill_reason", "deny_entry",
  "$@22", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "$@23", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
  "general_away_count", "general_away_time", "general_max_monitor",
  "general_whowas_history_length", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_kill_chase_time_limit", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_max_away_length", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_invisible_on_connect", "general_warn_no_connect_block",
  "general_stats_e_disabled", "general_stats_m_oper_only",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_u_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_specials_in_ident",
  "general_max_targets", "general_ping_cookie", "general_disable_auth",
  "general_throttle_count", "general_throttle_time", "general_oper_umodes",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_default_floodtime",
  "general_cloak_enabled", "general_cloak_cidr_len_ipv4",
  "general_cloak_cidr_len_ipv6", "general_cloak_num_bits",
  "general_cloak_secret", "general_cloak_suffix", "channel_entry",
  "channel_items", "channel_item", "channel_enable_extbans",
  "channel_enable_owner", "channel_enable_admin",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_invite_delay_channel",
  "channel_invite_expire_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_invites", "channel_max_bans",
  "channel_max_bans_large", "channel_max_kick_length",
  "channel_default_join_flood_count", "channel_default_join_flood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_flatten_links_delay",
  "serverhide_flatten_links_file", "serverhide_disable_remote_commands",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_hidden",
  "serverhide_hide_server_ips", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1016)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1016,   757, -1016,  -176,  -216,  -205, -1016, -1016, -1016,  -198,
   -1016,  -178, -1016, -1016, -1016,  -181,  -167, -1016, -1016, -1016,
    -147,  -144, -1016,  -140, -1016,  -136, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016,    16,   863,  -132,  -119,  -118,    39,  -116,
     477,  -114,  -109,  -106,  -103,   -88,   -92,   -75,   -69,   559,
     634,   -66,   111,   -65,    10,   -57,   -45,   -46,   -39,   -36,
      32, -1016, -1016, -1016, -1016, -1016,   -34,   -32,   -31,   -28,
     -17,    -7,    -4,    -3,    -2,    12,    20,    41,    45,    59,
      64,    66,    68,    73,   159, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016,   664,   647,    25, -1016,    78,     6,
   -1016, -1016,   179, -1016,    81,    88,    89,    99,   100,   102,
     103,   105,   109,   112,   113,   114,   115,   117,   119,   122,
     124,   125,   126,   128,   135,   137,   138,   144,   148,   149,
     150,   153,   154,   155,   156,   157,   161,   162,   164,   167,
     171,   173,   176,   177,   181,   182,   183,   184,   186,   187,
     188,   191,   192,   193,   194,    51, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,   402,     4,
      24,   -14,    13,   197,    14,   322,    27, -1016,   198,   203,
     204,   205,   206,   207,   211,   212,   214,   251, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,   199,   215,
     216,   217,   218,   219,   223,   225,   226,   227,   228,   231,
     232,   233,   234,   235,   238,   240,   166, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016,    87,   243,   244,    19, -1016,
   -1016, -1016,   229,   174, -1016,   245,    38, -1016, -1016,   146,
   -1016,   247,   250,   258,   259, -1016,   261,   262,   291,   292,
     293,   294,   276,   262,   262,   262,   277,   262,   262,   278,
     279,   283,   285,   287,   290, -1016,   295,   281,   289,   298,
   -1016,   302,   303,   305,   306,   307,   309,   313,   315,   317,
     321,   324,   284, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,   296,
     325,   326,   328,   332,   334,   335, -1016,   336,   337,   338,
     342,   343,   350,   352,   354,   121, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016,   355,   356,     5, -1016, -1016, -1016,   364,
     370, -1016, -1016,   372,   373,    31, -1016, -1016, -1016,   400,
     262,   288,   262,   262,   405,   323,   382,   383,   389,   390,
     419,   394,   262,   425,   399,   403,   427,   432,   262,   406,
     408,   411,   412,   421,   423,   262,   426,   428,   429,   452,
     431,   454,   262,   262,   459,   460,   434,   463,   466,   467,
     468,   473,   474,   475,   449,   262,   262,   262,   494,   450,
     469, -1016,   471,   472,   476, -1016,   478,   479,   480,   484,
     486,   320, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016,   487,   488,    48, -1016, -1016, -1016,   491,   490,
     492, -1016,   496, -1016,    36, -1016, -1016, -1016, -1016, -1016,
   -1016,   489, -1016, -1016, -1016,   500,   499,   501,    49, -1016,
   -1016, -1016,   505,   504,   508, -1016,   512,   513,   514,   516,
     521,   522,   525,   221, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016,   530,   529,   534,   537,    18,
   -1016, -1016, -1016, -1016,   503,   507,   262,   498,   568,   544,
     571,   576,   577,   551, -1016, -1016,   555,   560,   585,   561,
     564,   565,   567,   569,   570,   572,   574,   575,   578,   579,
     580,   581,   583,   582, -1016,   584,   573, -1016,   175, -1016,
   -1016, -1016, -1016,   597,   587, -1016,   319,   588,   589,   591,
     592,   593,    96, -1016, -1016, -1016, -1016, -1016,   598,   599,
   -1016,   600,   595, -1016,   596,   133, -1016, -1016, -1016, -1016,
     602,   603,   605, -1016,   606,   443,   607,   609,   611,   620,
     623,   627,   628,   629,   630,   632,   633,   637,   638,   640,
     641,   645,   646, -1016, -1016,   590,   635,   262,   648,   649,
     262,   653,   262,   657,   659,   660,   661,   262,   662,   662,
     656, -1016, -1016,   665,   -94,   667,   675,   672,   673,   671,
     677,   679,   663,   680,   681,   262,   686,   690,   689, -1016,
     692,   693,   694, -1016,   695, -1016,   698,   699,   700, -1016,
     701,   703,   704,   709,   711,   712,   714,   715,   716,   718,
     723,   724,   725,   726,   727,   728,   729,   733,   736,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   755,   756,   758,
     759,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     769, -1016, -1016,   772,   720,   696,   773,   774,   776,   777,
     778,   779, -1016,   780,   782,   781, -1016, -1016,   784,   785,
     770,   786,   787, -1016,   -14, -1016,   788,   790,   789, -1016,
   -1016,   792,   805,   791,   793,   794,   796,   797,   812,   798,
     799,   800, -1016, -1016,   801,   803,   804,   806, -1016,   807,
     808,   809,   810,   811,   813,   814,   815,   816, -1016,   817,
     818,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     828,   829,   830,   831,   832,   833, -1016, -1016,   836,   802,
     835, -1016,   837, -1016,   108, -1016,   838,   840,   841,   842,
     843, -1016,   844, -1016, -1016,   847,   839,   848,   849, -1016,
   -1016, -1016, -1016, -1016,   262,   262,   262,   262,   262,   262,
     262, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
     850,   851,   852,   -49,   853,   854,   855,   856,   857,   858,
     859,   860,   861,    11,   862,   864, -1016,   865,   866,   867,
     868,   869,   870,   871,    -5,   872,   873,   874,   875,   876,
     877,   878,   879, -1016,   880,   881, -1016, -1016,   882,   883,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016,   884,   885,   349,   886,   887,   888,   889,   890,
   -1016,   891,   892, -1016,   893,   894,   -16,   308,   895, -1016,
   -1016, -1016,   896,   897, -1016,   898,   900,   550,   901,   902,
     903,   904,   905,   906,   907, -1016,   908,   909,   910, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016,   911,   684, -1016, -1016,
     912,   845,   846, -1016,    92, -1016, -1016, -1016, -1016,   913,
     914,   915,   916, -1016, -1016,   917,   697,   918, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016,  -202, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016,   662,   662,   662, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,  -199, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016,  -191, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,  -188,
   -1016,   920,   786,   921, -1016, -1016, -1016, -1016, -1016, -1016,
     795, -1016,   919,   922, -1016,   923, -1016,   924,   925, -1016,
   -1016,   926, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016,  -185, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016,  -182, -1016, -1016,   932,
    -162,   929,   933, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,  -170,
   -1016, -1016, -1016,   -49, -1016, -1016, -1016, -1016,    -5, -1016,
     349, -1016,   -16, -1016, -1016, -1016,   562,   666,   563,   939,
     946,   928,   981, -1016,   550, -1016,   684,   934,   935,   936,
     351, -1016, -1016,   697, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,   937, -1016,
   -1016
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   208,   370,   420,     0,
     435,     0,   274,   411,   248,     0,     0,   101,   151,   307,
       0,     0,   348,     0,   110,     0,   324,     3,     4,     5,
      13,     6,    25,    26,     7,     8,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    23,     9,
      14,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    96,    95,   571,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   552,   568,   569,   570,   567,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   553,
     554,   564,   565,   566,     0,     0,     0,   433,     0,     0,
     431,   432,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,   447,   448,   490,
     454,   491,   485,   486,   487,   488,   458,   449,   450,   451,
     452,   453,   473,   455,   456,   457,   459,   460,   489,   464,
     465,   466,   467,   463,   462,   468,   475,   476,   469,   470,
     471,   461,   472,   483,   484,   481,   482,   474,   479,   480,
     477,   478,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   602,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   600,   599,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    69,    67,
      65,    70,    71,    72,    66,    56,    68,    58,    59,    60,
      61,    62,    63,    64,    57,     0,     0,     0,     0,   125,
     126,   127,     0,     0,   322,     0,     0,   320,   321,     0,
      97,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   551,     0,     0,     0,     0,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,   212,   215,   217,   218,   219,   220,
     221,   222,   223,   213,   214,   216,   224,   225,   226,     0,
       0,     0,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   373,   374,   375,   376,
     377,   378,   379,   380,   382,   381,   384,   388,   385,   386,
     387,   383,   426,     0,     0,     0,   423,   424,   425,     0,
       0,   430,   441,     0,     0,     0,   438,   439,   440,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   445,     0,     0,     0,   291,     0,     0,     0,     0,
       0,     0,   277,   278,   279,   280,   285,   281,   282,   283,
     284,   417,     0,     0,     0,   414,   415,   416,     0,     0,
       0,   250,     0,   262,     0,   260,   261,   263,   264,    52,
      51,    48,    50,    46,    45,     0,     0,     0,     0,   104,
     105,   106,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   161,
     162,   163,   160,   159,   164,     0,     0,     0,     0,     0,
     310,   311,   312,   313,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   591,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,   356,     0,   351,
     352,   353,   128,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   116,   115,   117,     0,     0,
     319,     0,     0,   334,     0,     0,   327,   328,   329,   330,
       0,     0,     0,    91,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   550,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,   389,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   372,
       0,     0,     0,   422,     0,   429,     0,     0,     0,   437,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   444,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,     0,     0,     0,   413,   265,     0,     0,
       0,     0,     0,   259,     0,   107,     0,     0,     0,   103,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   314,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,   354,     0,     0,
       0,   350,     0,   123,     0,   118,     0,     0,     0,     0,
       0,   112,     0,   318,   331,     0,     0,     0,     0,   326,
     100,    99,    98,   588,    29,    29,    29,    29,    29,    29,
      29,    31,    30,   589,   575,   574,   572,   573,   576,   577,
     578,   579,   580,   581,   582,   585,   586,   583,   584,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,     0,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   371,     0,     0,   421,   434,     0,     0,
     436,   510,   515,   499,   500,   528,   544,   545,   546,   547,
     548,   549,   503,   542,   543,   536,   504,   505,   509,   518,
     508,   506,   507,   513,   514,   501,   512,   511,   534,   540,
     541,   532,   539,   529,   527,   530,   535,   531,   533,   520,
     526,   525,   521,   522,   523,   524,   537,   538,   517,   516,
     519,   502,     0,     0,     0,     0,     0,     0,     0,     0,
     275,     0,     0,   412,     0,     0,     0,   270,   266,   269,
     249,    49,     0,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,     0,   308,
     606,   603,   604,   605,   610,   609,   611,   607,   608,    86,
      83,    90,    82,    87,    88,    89,    81,    85,    84,    75,
      74,    77,    78,    76,    79,    80,     0,     0,   349,   129,
       0,     0,     0,   141,     0,   133,   134,   136,   135,     0,
       0,     0,     0,   111,   323,     0,     0,     0,   325,    32,
      33,    34,    35,    36,    37,    38,   237,   238,   232,   247,
     246,     0,   245,   233,   241,   234,   240,   228,   239,   231,
     230,   229,    39,    39,    39,    41,    40,   235,   236,   395,
     398,   399,   409,   406,   391,   407,   404,   405,     0,   403,
     408,   390,   397,   394,   393,   392,   396,   410,   427,   428,
     442,   443,   289,   290,   299,   295,   296,   298,   303,   300,
     301,   302,   297,     0,   294,   288,   306,   305,   304,   287,
     419,   418,   273,   272,   257,   258,   255,   256,   254,     0,
     253,     0,     0,     0,   108,   109,   173,   170,   195,   206,
     182,   191,     0,   180,   185,     0,   200,     0,   194,   198,
     204,   184,   187,   196,   197,   201,   192,   199,   188,   205,
     190,   186,   189,     0,   178,   166,   168,   174,   171,   172,
     167,   169,   317,   315,   316,   355,   360,   366,   369,   362,
     368,   363,   367,   365,   361,   364,     0,   359,   137,     0,
       0,     0,     0,   132,   120,   119,   121,   122,   332,   338,
     344,   347,   340,   346,   341,   345,   343,   339,   342,     0,
     337,   333,   243,     0,    42,    43,    44,   401,     0,   292,
       0,   251,     0,   271,   268,   267,     0,     0,     0,     0,
       0,     0,     0,   176,     0,   357,     0,     0,     0,     0,
       0,   131,   335,     0,   244,   402,   293,   252,   181,   203,
     179,   207,   202,   193,   183,   177,   358,   138,   140,   139,
     149,   148,   144,   146,   150,   147,   143,   145,     0,   336,
     142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1016, -1016, -1016,  -171,  -325, -1015,  -668, -1016, -1016, -1016,
   -1016,   260, -1016, -1016,   642, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016,   961, -1016, -1016, -1016, -1016, -1016,
   -1016,   458, -1016, -1016, -1016, -1016, -1016,   540, -1016, -1016,
   -1016, -1016, -1016, -1016,   899, -1016, -1016, -1016, -1016,   123,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,   610, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016,   -95, -1016, -1016, -1016,   834, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016,   -62, -1016, -1016, -1016, -1016, -1016,   -64,
   -1016,   655, -1016, -1016, -1016,    28, -1016, -1016, -1016, -1016,
   -1016,   682, -1016, -1016, -1016, -1016, -1016, -1016, -1016,   -59,
   -1016, -1016, -1016, -1016, -1016, -1016,   613, -1016, -1016, -1016,
   -1016, -1016,   927, -1016, -1016, -1016, -1016,   549, -1016, -1016,
   -1016, -1016, -1016,   -78, -1016, -1016, -1016,   586, -1016, -1016,
   -1016, -1016,   -70, -1016, -1016, -1016,   783, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,   -51,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,   676, -1016,
   -1016, -1016, -1016, -1016,   771, -1016, -1016, -1016, -1016,  1050,
   -1016, -1016, -1016, -1016,   775, -1016, -1016, -1016, -1016,   996,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016,  1078, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016,   930, -1016, -1016, -1016, -1016, -1016,
   -1016, -1016, -1016, -1016
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   861,   862,  1085,  1086,    28,    29,   242,
     521,   522,    30,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,    31,    80,    81,    82,    83,    84,    32,    66,
     528,   529,   530,   531,    33,    73,   612,   613,   614,   615,
     616,   617,    34,   308,   309,   310,   311,   312,  1044,  1045,
    1046,  1047,  1048,  1201,  1278,    35,    67,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   783,
    1173,  1174,    36,    55,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   658,  1071,  1072,    37,    63,   513,   770,  1139,  1140,
     514,   515,   516,  1143,   988,   989,   517,   518,    38,    61,
     491,   492,   493,   494,   495,   496,   497,   755,  1123,  1124,
     498,   499,   500,    39,    68,   559,   560,   561,   562,   563,
      40,   316,   317,   318,    41,    75,   625,   626,   627,   628,
     629,   846,  1219,  1220,    42,    71,   598,   599,   600,   601,
     829,  1196,  1197,    43,    56,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   679,  1098,  1099,
     407,   408,   409,   410,   411,    44,    62,   504,   505,   506,
     507,    45,    57,   415,   416,   417,   418,    46,   129,   130,
     131,    47,    59,   425,   426,   427,   428,    48,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    49,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    50,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     894,   895,   636,  1096,  1134,   501,   412,   127,   642,   643,
     644,   314,   646,   647,  1069,   525,   519,    76,    53,   555,
     306,  1135,  1082,  1083,  1084,   508,   412,  1222,   555,    54,
    1227,  1223,   422,    76,  1228,  1248,    58,   508,  1229,   314,
     127,  1231,  1230,  1136,  1243,  1232,    64,  1245,  1244,   501,
     525,  1246,   133,    51,    52,    77,    60,   134,   135,  1252,
     136,   137,    78,  1253,    65,   138,   893,  1224,  1225,  1226,
     556,    77,   139,   140,   141,   142,   143,   144,    78,   556,
     413,   128,   145,   146,   147,   898,   899,    69,   595,  1070,
      70,   509,   148,  1040,    72,   149,   150,   607,    74,   510,
     413,   511,   124,   509,   151,   701,   526,   703,   704,  1040,
     557,   510,   306,   511,   128,   125,   126,   713,   132,   557,
     238,   152,   379,   719,   380,   239,   381,   315,   240,   241,
     726,   520,   153,    79,   621,   154,   155,   733,   734,   243,
     382,   526,   244,   502,   414,   156,   157,   621,   423,    79,
     746,   747,   748,   158,   159,   315,   160,   558,   161,   245,
      85,   512,   162,   163,   414,   246,   558,   268,   305,   313,
     424,   383,  1137,   512,   164,   607,   595,   319,  1138,   165,
     422,   166,   167,   168,   320,   321,   169,   502,   384,  1097,
     385,   527,   322,    86,    87,   323,  -130,   326,   386,   327,
     328,    88,   269,   329,   596,   270,    89,    90,    91,  1041,
     387,   170,   171,   608,   330,   172,   173,   174,   175,   176,
     177,   178,   532,   503,   331,  1041,   527,   332,   333,   334,
      92,    93,    94,    95,   271,   692,   420,   307,   388,   893,
     533,   801,   523,   335,   272,    96,    97,    98,   797,   604,
     622,   336,   247,   179,   180,    99,   100,   101,   389,   102,
     103,   698,   324,   622,   181,   182,   772,   503,   619,   609,
     273,   534,   337,   183,   274,   184,   338,   390,   765,   778,
     610,   480,   275,   276,  1042,   346,   277,   278,  -130,   611,
     339,   608,   596,   391,   248,   340,   423,   341,   535,   342,
    1042,   347,   348,   597,   343,   249,   250,   251,  1043,   419,
     252,   253,   429,   349,   279,   254,   255,   256,   424,   430,
     431,   482,  1202,   532,  1043,   392,   840,   393,   394,   307,
     432,   433,   882,   434,   435,   885,   436,   887,   536,   483,
     437,   533,   892,   438,   439,   440,   441,   609,   442,   623,
     443,   688,   624,   444,   537,   445,   446,   447,   610,   448,
     910,   350,   623,   848,  1114,   624,   449,   611,   450,   451,
     484,   280,   534,   281,   282,   452,   283,   284,   285,   453,
     454,   455,   351,   352,   456,   457,   458,   459,   460,   344,
     353,   597,   461,   462,   354,   463,   593,   485,   464,   535,
    1115,   355,   465,   482,   466,   830,   606,   467,   468,   356,
     357,   358,   469,   470,   471,   472,   538,   473,   474,   475,
     359,   483,   476,   477,   478,   479,   524,   539,   575,   564,
     540,  1270,  1116,  1271,   565,   566,   567,   568,   569,   536,
     541,   360,   570,   571,   542,   572,   576,   577,   578,   579,
     580,   791,   484,   486,   581,   537,   582,   583,   584,   585,
     487,   488,   586,   587,   588,   589,   590,  1117,  1118,   591,
     361,   592,   602,  1119,   630,   603,   618,   631,   133,   485,
    1272,   573,   489,   134,   135,   632,   136,   137,   633,   634,
     635,   138,   637,   638,   639,   640,  1120,  1273,   139,   140,
     141,   142,   143,   144,   641,   645,   648,   649,   145,   146,
     147,   650,   655,   651,   670,   652,   702,   538,   148,   653,
     656,   149,   150,  1141,   654,   672,  1274,  1275,   539,   657,
     151,   540,  1249,   659,   660,   486,   661,   662,   663,   490,
     664,   541,   487,   488,   665,   542,   666,   152,   667,  1121,
     761,   706,   668,   834,  1148,   669,   673,   674,   153,   675,
     247,   154,   155,   676,   489,   677,   678,   680,   681,   682,
    1276,   156,   157,   683,   684,  1122,  1277,  1149,  1150,   158,
     159,   685,   160,   686,   161,   687,   690,   691,   162,   163,
    1151,   694,   854,   855,   856,   857,   858,   859,   860,   695,
     164,   700,   248,   696,   697,   165,   705,   166,   167,   168,
     707,   708,   169,   249,   250,   251,   709,   710,   252,   253,
     711,   490,   712,   254,   255,   256,   714,   715,   717,  1152,
    1153,   716,  1154,   718,   720,   268,   721,   170,   171,   722,
     723,   172,   173,   174,   175,   176,   177,   178,   379,   724,
     380,   725,   381,   730,   727,   732,   728,   729,   731,  1155,
     735,   736,   737,  1156,   738,   346,   382,   739,   740,   741,
     269,   635,  1157,   270,   742,   743,   744,   745,   750,   179,
     180,   347,   348,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
     181,   182,  1158,   349,  1159,   749,  1160,   383,   751,   183,
     752,   184,   271,   753,   799,  1258,  1260,   754,   800,   756,
     757,   758,   272,  1161,   384,   759,   385,   760,   763,   764,
     767,   768,   774,   769,   386,   802,  1162,   771,  1163,   775,
     776,  1164,   777,  1165,   780,   781,   387,  1166,   273,   782,
    1167,   350,   274,   784,   785,   786,  1168,   787,  1169,  1170,
     275,   276,   788,   789,   277,   278,   790,     2,     3,   793,
     794,     4,   351,   352,   388,   795,  1186,  1171,   796,   803,
     353,   804,   805,     5,   354,  1172,     6,   806,   807,  1209,
     808,   355,   279,   809,   389,     7,   811,   810,   812,   356,
     357,   358,   813,   814,   815,     8,   816,   817,   832,   818,
     359,   819,   820,   390,   828,   821,   822,   823,   824,     9,
     825,   826,  1259,   827,    10,    11,   833,   835,   880,   391,
     836,   360,   837,   838,   839,   842,   845,   847,   843,   844,
    1187,   850,   851,    12,   852,   853,   863,    13,   864,   280,
     865,   281,   282,  1210,   283,   284,   285,    14,    15,   866,
     361,   392,   867,   393,   394,  1188,   868,   869,   870,   871,
    1189,   872,   873,   881,    85,  1190,   874,   875,  1211,   876,
     877,    16,    17,  1212,   878,   879,   901,   884,  1213,   883,
    1191,   886,  1192,  1193,   888,   896,    18,   889,   890,   891,
     893,   907,   897,  1214,   900,  1215,  1216,    86,    87,   902,
     903,  1194,   904,    19,   905,    88,   906,   908,   909,  1195,
      89,    90,    91,   911,  1217,    20,    21,   912,   913,   914,
     915,   973,  1218,   916,   917,   918,   919,   974,   594,   920,
     921,    22,   922,   923,    92,    93,    94,    95,   924,    23,
     925,   926,    24,   927,   928,   929,    25,   930,    26,    96,
      97,    98,   931,   932,   933,   934,   935,   936,   937,    99,
     100,   101,   938,   102,   103,   939,   940,   941,   942,   943,
     944,   945,   946,   947,   948,   949,   950,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   779,   960,   961,   962,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     975,   986,   976,   977,   978,   979,   996,   981,   980,   982,
     983,   984,   985,  1002,   987,   992,   990,   993,   994,   995,
     998,   999,   997,  1000,  1001,  1003,  1004,  1236,  1006,  1005,
    1007,  1008,  1261,  1037,   991,  1009,  1010,  1011,  1012,  1013,
    1014,   325,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1038,  1049,  1039,  1050,  1051,  1052,
    1056,  1263,  1053,  1054,  1055,  1057,  1199,  1200,  1058,  1066,
    1067,  1068,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1087,  1262,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1132,  1133,  1264,  1144,  1145,  1146,  1142,  1147,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1198,  1204,  1205,  1206,  1207,  1208,  1221,  1233,  1265,
    1235,  1237,   841,   792,  1238,  1239,  1240,  1241,  1242,  1247,
    1250,  1254,  1251,  1267,  1268,  1269,  1280,  1203,  1257,   773,
    1234,  1256,   798,   762,   849,  1279,  1266,  1255,   689,   421,
     766,   481,   345,     0,   831,     0,   693,   574,     0,     0,
       0,     0,     0,     0,     0,     0,   671,     0,     0,     0,
     699,     0,     0,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   620
};

static const yytype_int16 yycheck[] =
{
     668,   669,   327,     8,    20,     1,     1,     1,   333,   334,
     335,     1,   337,   338,    63,     1,    30,     1,   234,     1,
       1,    37,    11,    12,    13,     1,     1,   229,     1,   234,
     229,   233,     1,     1,   233,   197,   234,     1,   229,     1,
       1,   229,   233,    59,   229,   233,   227,   229,   233,     1,
       1,   233,     1,   229,   230,    39,   234,     6,     7,   229,
       9,    10,    46,   233,   231,    14,   228,  1082,  1083,  1084,
      52,    39,    21,    22,    23,    24,    25,    26,    46,    52,
      75,    75,    31,    32,    33,   179,   180,   234,     1,   138,
     234,    67,    41,     1,   234,    44,    45,     1,   234,    75,
      75,    77,   234,    67,    53,   430,    92,   432,   433,     1,
      92,    75,     1,    77,    75,   234,   234,   442,   234,    92,
     234,    70,     1,   448,     3,   234,     5,   117,   234,   232,
     455,   145,    81,   117,     1,    84,    85,   462,   463,   227,
      19,    92,   234,   139,   139,    94,    95,     1,   117,   117,
     475,   476,   477,   102,   103,   117,   105,   139,   107,   234,
       1,   137,   111,   112,   139,   234,   139,     1,   234,   234,
     139,    50,   188,   137,   123,     1,     1,   234,   194,   128,
       1,   130,   131,   132,   229,   231,   135,   139,    67,   194,
      69,   177,   231,    34,    35,   231,   177,   231,    77,   231,
     231,    42,    36,   231,   117,    39,    47,    48,    49,   117,
      89,   160,   161,   117,   231,   164,   165,   166,   167,   168,
     169,   170,     1,   219,   231,   117,   177,   231,   231,   231,
      71,    72,    73,    74,    68,   230,   230,   218,   117,   228,
      19,   566,   229,   231,    78,    86,    87,    88,   230,   230,
     117,   231,     1,   202,   203,    96,    97,    98,   137,   100,
     101,   230,   230,   117,   213,   214,   230,   219,   230,   173,
     104,    50,   231,   222,   108,   224,   231,   156,   230,   230,
     184,   230,   116,   117,   192,     1,   120,   121,   177,   193,
     231,   117,   117,   172,    43,   231,   117,   231,    77,   231,
     192,    17,    18,   216,   231,    54,    55,    56,   216,   231,
      59,    60,   231,    29,   148,    64,    65,    66,   139,   231,
     231,     1,   230,     1,   216,   204,   230,   206,   207,   218,
     231,   231,   657,   231,   231,   660,   231,   662,   117,    19,
     231,    19,   667,   231,   231,   231,   231,   173,   231,   216,
     231,   230,   219,   231,   133,   231,   231,   231,   184,   231,
     685,    77,   216,   230,    15,   219,   231,   193,   231,   231,
      50,   205,    50,   207,   208,   231,   210,   211,   212,   231,
     231,   231,    98,    99,   231,   231,   231,   231,   231,   230,
     106,   216,   231,   231,   110,   231,   230,    77,   231,    77,
      51,   117,   231,     1,   231,   230,   177,   231,   231,   125,
     126,   127,   231,   231,   231,   231,   195,   231,   231,   231,
     136,    19,   231,   231,   231,   231,   229,   206,   229,   231,
     209,    80,    83,    82,   231,   231,   231,   231,   231,   117,
     219,   157,   231,   231,   223,   231,   231,   231,   231,   231,
     231,   230,    50,   133,   231,   133,   231,   231,   231,   231,
     140,   141,   231,   231,   231,   231,   231,   118,   119,   231,
     186,   231,   229,   124,   227,   231,   231,   227,     1,    77,
     129,   230,   162,     6,     7,   227,     9,    10,   229,   228,
     228,    14,   201,   201,   201,   201,   147,   146,    21,    22,
      23,    24,    25,    26,   228,   228,   228,   228,    31,    32,
      33,   228,   231,   228,   230,   228,   228,   195,    41,   229,
     231,    44,    45,   215,   229,   229,   175,   176,   206,   231,
      53,   209,  1200,   231,   231,   133,   231,   231,   231,   219,
     231,   219,   140,   141,   231,   223,   231,    70,   231,   200,
     230,   228,   231,   234,     4,   231,   231,   231,    81,   231,
       1,    84,    85,   231,   162,   231,   231,   231,   231,   231,
     219,    94,    95,   231,   231,   226,   225,    27,    28,   102,
     103,   231,   105,   231,   107,   231,   231,   231,   111,   112,
      40,   227,   149,   150,   151,   152,   153,   154,   155,   229,
     123,   201,    43,   231,   231,   128,   201,   130,   131,   132,
     228,   228,   135,    54,    55,    56,   227,   227,    59,    60,
     201,   219,   228,    64,    65,    66,   201,   228,   201,    79,
      80,   228,    82,   201,   228,     1,   228,   160,   161,   228,
     228,   164,   165,   166,   167,   168,   169,   170,     1,   228,
       3,   228,     5,   201,   228,   201,   228,   228,   227,   109,
     201,   201,   228,   113,   201,     1,    19,   201,   201,   201,
      36,   228,   122,    39,   201,   201,   201,   228,   228,   202,
     203,    17,    18,   854,   855,   856,   857,   858,   859,   860,
     213,   214,   142,    29,   144,   201,   146,    50,   229,   222,
     229,   224,    68,   231,   201,   143,   143,   231,   201,   231,
     231,   231,    78,   163,    67,   231,    69,   231,   231,   231,
     229,   231,   233,   231,    77,   227,   176,   231,   178,   229,
     231,   181,   231,   183,   229,   231,    89,   187,   104,   231,
     190,    77,   108,   231,   231,   231,   196,   231,   198,   199,
     116,   117,   231,   231,   120,   121,   231,     0,     1,   229,
     231,     4,    98,    99,   117,   231,    82,   217,   231,   201,
     106,   227,   201,    16,   110,   225,    19,   201,   201,    82,
     229,   117,   148,   228,   137,    28,   201,   227,   227,   125,
     126,   127,   228,   228,   227,    38,   227,   227,   201,   227,
     136,   227,   227,   156,   231,   227,   227,   227,   227,    52,
     227,   229,   146,   229,    57,    58,   229,   229,   228,   172,
     231,   157,   231,   231,   231,   227,   231,   231,   229,   229,
     146,   229,   229,    76,   229,   229,   229,    80,   229,   205,
     229,   207,   208,   146,   210,   211,   212,    90,    91,   229,
     186,   204,   229,   206,   207,   171,   229,   229,   229,   229,
     176,   229,   229,   228,     1,   181,   229,   229,   171,   229,
     229,   114,   115,   176,   229,   229,   201,   228,   181,   231,
     196,   228,   198,   199,   227,   229,   129,   228,   228,   228,
     228,   228,   227,   196,   227,   198,   199,    34,    35,   227,
     227,   217,   231,   146,   227,    42,   227,   227,   227,   225,
      47,    48,    49,   227,   217,   158,   159,   227,   229,   227,
     227,   201,   225,   229,   229,   227,   227,   231,   286,   229,
     229,   174,   229,   229,    71,    72,    73,    74,   229,   182,
     229,   229,   185,   229,   229,   229,   189,   229,   191,    86,
      87,    88,   229,   229,   229,   229,   229,   229,   229,    96,
      97,    98,   229,   100,   101,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   528,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   227,
     227,   231,   228,   227,   227,   227,   201,   227,   229,   227,
     229,   227,   227,   201,   228,   227,   229,   227,   229,   227,
     227,   227,   231,   227,   227,   227,   227,   232,   227,   229,
     227,   227,    93,   231,   774,   229,   229,   229,   229,   229,
     229,    80,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   227,   229,   227,   229,   227,   227,   227,
     231,   143,   229,   229,   227,   227,   231,   231,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   146,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   143,   229,   229,   229,   233,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   228,  1244,
     229,   232,   612,   543,   232,   232,   232,   232,   232,   227,
     231,  1223,   229,   229,   229,   229,   229,  1044,  1232,   514,
    1142,  1230,   559,   491,   625,  1253,  1246,  1228,   395,   129,
     504,   185,   104,    -1,   598,    -1,   415,   257,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,    -1,    -1,
     425,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   316
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   236,     0,     1,     4,    16,    19,    28,    38,    52,
      57,    58,    76,    80,    90,    91,   114,   115,   129,   146,
     158,   159,   174,   182,   185,   189,   191,   237,   242,   243,
     247,   267,   273,   279,   287,   300,   317,   339,   353,   368,
     375,   379,   389,   398,   420,   426,   432,   436,   442,   496,
     517,   229,   230,   234,   234,   318,   399,   427,   234,   437,
     234,   354,   421,   340,   227,   231,   274,   301,   369,   234,
     234,   390,   234,   280,   234,   380,     1,    39,    46,   117,
     268,   269,   270,   271,   272,     1,    34,    35,    42,    47,
      48,    49,    71,    72,    73,    74,    86,    87,    88,    96,
      97,    98,   100,   101,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   234,   234,   234,     1,    75,   433,
     434,   435,   234,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    44,
      45,    53,    70,    81,    84,    85,    94,    95,   102,   103,
     105,   107,   111,   112,   123,   128,   130,   131,   132,   135,
     160,   161,   164,   165,   166,   167,   168,   169,   170,   202,
     203,   213,   214,   222,   224,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   234,   234,
     234,   232,   244,   227,   234,   234,   234,     1,    43,    54,
      55,    56,    59,    60,    64,    65,    66,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,     1,    36,
      39,    68,    78,   104,   108,   116,   117,   120,   121,   148,
     205,   207,   208,   210,   211,   212,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   234,     1,   218,   288,   289,
     290,   291,   292,   234,     1,   117,   376,   377,   378,   234,
     229,   231,   231,   231,   230,   269,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   230,   498,     1,    17,    18,    29,
      77,    98,    99,   106,   110,   117,   125,   126,   127,   136,
     157,   186,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,     1,
       3,     5,    19,    50,    67,    69,    77,    89,   117,   137,
     156,   172,   204,   206,   207,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   415,   416,   417,
     418,   419,     1,    75,   139,   428,   429,   430,   431,   231,
     230,   434,     1,   117,   139,   438,   439,   440,   441,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     230,   444,     1,    19,    50,    77,   133,   140,   141,   162,
     219,   355,   356,   357,   358,   359,   360,   361,   365,   366,
     367,     1,   139,   219,   422,   423,   424,   425,     1,    67,
      75,    77,   137,   341,   345,   346,   347,   351,   352,    30,
     145,   245,   246,   229,   229,     1,    92,   177,   275,   276,
     277,   278,     1,    19,    50,    77,   117,   133,   195,   206,
     209,   219,   223,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,     1,    52,    92,   139,   370,
     371,   372,   373,   374,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   230,   519,   229,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   230,   249,     1,   117,   216,   391,   392,
     393,   394,   229,   231,   230,   289,   177,     1,   117,   173,
     184,   193,   281,   282,   283,   284,   285,   286,   231,   230,
     377,     1,   117,   216,   219,   381,   382,   383,   384,   385,
     227,   227,   227,   229,   228,   228,   239,   201,   201,   201,
     201,   228,   239,   239,   239,   228,   239,   239,   228,   228,
     228,   228,   228,   229,   229,   231,   231,   231,   336,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     230,   320,   229,   231,   231,   231,   231,   231,   231,   412,
     231,   231,   231,   231,   231,   231,   231,   231,   230,   401,
     231,   231,   230,   429,   227,   229,   231,   231,   230,   439,
     201,   239,   228,   239,   239,   201,   228,   228,   228,   227,
     227,   201,   228,   239,   201,   228,   228,   201,   201,   239,
     228,   228,   228,   228,   228,   228,   239,   228,   228,   228,
     201,   227,   201,   239,   239,   201,   201,   228,   201,   201,
     201,   201,   201,   201,   201,   228,   239,   239,   239,   201,
     228,   229,   229,   231,   231,   362,   231,   231,   231,   231,
     231,   230,   356,   231,   231,   230,   423,   229,   231,   231,
     342,   231,   230,   346,   233,   229,   231,   231,   230,   276,
     229,   231,   231,   314,   231,   231,   231,   231,   231,   231,
     231,   230,   303,   229,   231,   231,   231,   230,   371,   201,
     201,   239,   227,   201,   227,   201,   201,   201,   229,   228,
     227,   201,   227,   228,   228,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   229,   229,   231,   395,
     230,   392,   201,   229,   234,   229,   231,   231,   231,   231,
     230,   282,   227,   229,   229,   231,   386,   231,   230,   382,
     229,   229,   229,   229,   149,   150,   151,   152,   153,   154,
     155,   238,   239,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     228,   228,   239,   231,   228,   239,   228,   239,   227,   228,
     228,   228,   239,   228,   241,   241,   229,   227,   179,   180,
     227,   201,   227,   227,   231,   227,   227,   228,   227,   227,
     239,   227,   227,   229,   227,   227,   229,   229,   227,   227,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   227,   201,   231,   227,   228,   227,   227,   227,
     229,   227,   227,   229,   227,   227,   231,   228,   349,   350,
     229,   246,   227,   227,   229,   227,   201,   231,   227,   227,
     227,   227,   201,   227,   227,   229,   227,   227,   227,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   227,   231,   229,   229,
       1,   117,   192,   216,   293,   294,   295,   296,   297,   227,
     227,   227,   227,   229,   229,   227,   231,   227,   229,   238,
     238,   238,   238,   238,   238,   238,   229,   229,   229,    63,
     138,   337,   338,   229,   229,   229,   229,   229,   229,   229,
     229,   229,    11,    12,    13,   240,   241,   229,   229,   229,
     229,   229,   229,   229,   229,   229,     8,   194,   413,   414,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,    15,    51,    83,   118,   119,   124,
     147,   200,   226,   363,   364,   229,   229,   229,   229,   229,
     229,   229,   229,   229,    20,    37,    59,   188,   194,   343,
     344,   215,   233,   348,   229,   229,   229,   229,     4,    27,
      28,    40,    79,    80,    82,   109,   113,   122,   142,   144,
     146,   163,   176,   178,   181,   183,   187,   190,   196,   198,
     199,   217,   225,   315,   316,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,    82,   146,   171,   176,
     181,   196,   198,   199,   217,   225,   396,   397,   229,   231,
     231,   298,   230,   294,   229,   229,   229,   229,   229,    82,
     146,   171,   176,   181,   196,   198,   199,   217,   225,   387,
     388,   229,   229,   233,   240,   240,   240,   229,   233,   229,
     233,   229,   233,   228,   350,   229,   232,   232,   232,   232,
     232,   232,   232,   229,   233,   229,   233,   227,   197,   241,
     231,   229,   229,   233,   338,   414,   364,   344,   143,   146,
     143,    93,   146,   143,   143,   316,   397,   229,   229,   229,
      80,    82,   129,   146,   175,   176,   219,   225,   299,   388,
     229
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   235,   236,   236,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   238,
     238,   239,   239,   239,   239,   239,   239,   239,   239,   240,
     240,   241,   241,   241,   241,   242,   243,   244,   244,   245,
     245,   246,   246,   247,   248,   248,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   268,   269,   269,   269,   269,   270,   271,
     272,   274,   273,   275,   275,   276,   276,   276,   277,   278,
     280,   279,   281,   281,   282,   282,   282,   282,   282,   283,
     284,   285,   286,   287,   288,   288,   289,   289,   289,   290,
     292,   291,   293,   293,   294,   294,   294,   294,   295,   296,
     296,   298,   297,   299,   299,   299,   299,   299,   299,   299,
     299,   301,   300,   302,   302,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   314,   313,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   318,   317,
     319,   319,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   336,   335,   337,   337,   338,   338,   340,   339,
     342,   341,   343,   343,   344,   344,   344,   344,   344,   345,
     345,   346,   346,   346,   346,   346,   348,   347,   349,   349,
     350,   350,   351,   352,   354,   353,   355,   355,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   357,   358,   359,
     360,   362,   361,   363,   363,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   365,   366,   367,   369,   368,   370,
     370,   371,   371,   371,   371,   372,   373,   374,   375,   376,
     376,   377,   377,   378,   380,   379,   381,   381,   382,   382,
     382,   382,   383,   384,   386,   385,   387,   387,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   390,   389,
     391,   391,   392,   392,   392,   393,   395,   394,   396,   396,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     399,   398,   400,   400,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   410,
     412,   411,   413,   413,   414,   414,   415,   416,   417,   418,
     419,   421,   420,   422,   422,   423,   423,   423,   424,   425,
     427,   426,   428,   428,   429,   429,   429,   430,   431,   432,
     433,   433,   434,   434,   435,   437,   436,   438,   438,   439,
     439,   439,   440,   441,   442,   443,   443,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   497,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   518,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     0,
       1,     2,     3,     3,     3,     4,     4,     0,     2,     3,
       1,     1,     1,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     2,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     2,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     3,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     0,     6,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     0,     5,     3,     1,
       1,     3,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     2,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 29: /* timespec_: %empty  */
#line 398 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3230 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3236 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3242 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3248 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3254 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3260 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3266 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3272 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 406 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3278 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 409 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3284 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 410 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3290 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 411 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3296 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3302 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 413 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3308 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 421 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3317 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3326 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 437 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3334 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 444 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3343 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 448 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3352 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 481 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3364 "conf_parser.c"
    break;

  case 75: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 490 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3376 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 499 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3388 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 508 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3400 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 517 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3412 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 526 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3424 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 535 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3436 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 544 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.name == NULL)
  {
    if (server_valid_name(yylval.string))
      ConfigServerInfo.name = io_strdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3454 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 559 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.sid == NULL)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = io_strdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3472 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 574 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3485 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 584 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    char *p = strchr(yylval.string, ' ');

    if (p)
      *p = '\0';

    io_free(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = io_strdup(yylval.string);
  }
}
#line 3502 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 598 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3514 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 607 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 1)
  {
    conf_error_report("default_max_clients too low, setting to 1");
    ConfigServerInfo.default_max_clients = 1;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "default_max_clients too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);

    ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3540 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 630 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 9)
  {
    conf_error_report("max_nick_length too low, setting to 9");
    ConfigServerInfo.max_nick_length = 9;
  }
  else if ((yyvsp[-1].number) > NICKLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_nick_length = NICKLEN;
  }
  else
    ConfigServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3566 "conf_parser.c"
    break;

  case 88: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 653 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3577 "conf_parser.c"
    break;

  case 89: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 661 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3589 "conf_parser.c"
    break;

  case 90: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 670 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3598 "conf_parser.c"
    break;

  case 98: /* admin_name: NAME '=' QSTRING ';'  */
#line 688 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3610 "conf_parser.c"
    break;

  case 99: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 697 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3622 "conf_parser.c"
    break;

  case 100: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 706 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3634 "conf_parser.c"
    break;

  case 101: /* $@1: %empty  */
#line 719 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3643 "conf_parser.c"
    break;

  case 102: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 723 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3660 "conf_parser.c"
    break;

  case 108: /* motd_mask: MASK '=' QSTRING ';'  */
#line 740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3669 "conf_parser.c"
    break;

  case 109: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 746 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3678 "conf_parser.c"
    break;

  case 110: /* $@2: %empty  */
#line 756 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3687 "conf_parser.c"
    break;

  case 111: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 760 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.command.buf[0] ||
      !block_state.name.buf[0] ||
      !block_state.nick.buf[0] ||
      !block_state.host.buf[0])
    break;

  pseudo_register(block_state.name.buf, block_state.nick.buf, block_state.host.buf,
                  block_state.prepend.buf, block_state.command.buf);
}
#line 3705 "conf_parser.c"
    break;

  case 119: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3714 "conf_parser.c"
    break;

  case 120: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 784 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3723 "conf_parser.c"
    break;

  case 121: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 790 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3732 "conf_parser.c"
    break;

  case 122: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct nuh_split nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.nick.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.nick.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);
  }
}
#line 3754 "conf_parser.c"
    break;

  case 129: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 825 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3763 "conf_parser.c"
    break;

  case 130: /* $@3: %empty  */
#line 831 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3772 "conf_parser.c"
    break;

  case 131: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 835 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3785 "conf_parser.c"
    break;

  case 138: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 851 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3796 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 859 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3804 "conf_parser.c"
    break;

  case 140: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 862 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3812 "conf_parser.c"
    break;

  case 141: /* $@4: %empty  */
#line 867 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3821 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: USER  */
#line 873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3830 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: OPERATOR  */
#line 877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3839 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: XLINE  */
#line 881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3848 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: RESV  */
#line 885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3857 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DLINE  */
#line 889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3866 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KLINE  */
#line 893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3875 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: KILL  */
#line 897 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3884 "conf_parser.c"
    break;

  case 150: /* logging_file_type_item: T_DEBUG  */
#line 901 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3893 "conf_parser.c"
    break;

  case 151: /* $@5: %empty  */
#line 911 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3905 "conf_parser.c"
    break;

  case 152: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 918 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (!block_state.rpass.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
  {
    char *s = node->data;

    if (EmptyString(s))
      continue;

    struct nuh_split nuh =
    {
      .nuhmask = s,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);

    struct MaskItem *conf = conf_make(CONF_OPER);
    conf->addr = io_calloc(sizeof(*conf->addr));
    conf->name = io_strdup(block_state.name.buf);
    conf->user = io_strdup(block_state.user.buf);
    conf->host = io_strdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = io_strdup(block_state.cert.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = io_strdup(block_state.rpass.buf);

    if (block_state.whois.buf[0])
      conf->whois = io_strdup(block_state.whois.buf);

    if (block_state.modes.buf[0])
      conf->modes = io_strdup(block_state.modes.buf);

    conf->flags = block_state.flags.value;
    conf->port  = block_state.port.value;
    conf->htype = address_parse_netmask(conf->host, conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);
  }
}
#line 3967 "conf_parser.c"
    break;

  case 166: /* oper_name: NAME '=' QSTRING ';'  */
#line 990 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3976 "conf_parser.c"
    break;

  case 167: /* oper_user: USER '=' QSTRING ';'  */
#line 996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3985 "conf_parser.c"
    break;

  case 168: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3994 "conf_parser.c"
    break;

  case 169: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4003 "conf_parser.c"
    break;

  case 170: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1014 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4017 "conf_parser.c"
    break;

  case 171: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1025 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4026 "conf_parser.c"
    break;

  case 172: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1031 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4040 "conf_parser.c"
    break;

  case 173: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4049 "conf_parser.c"
    break;

  case 174: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4058 "conf_parser.c"
    break;

  case 175: /* $@6: %empty  */
#line 1054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4067 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL ':' REMOTE  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4076 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: KILL  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4085 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4094 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: CONNECT  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4103 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4112 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: SQUIT  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4121 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: KLINE  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4130 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: UNKLINE  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4139 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_DLINE  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4148 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_UNDLINE  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4157 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: XLINE  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4166 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_UNXLINE  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4175 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: DIE  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4184 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_RESTART  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4193 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4202 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: REHASH  */
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4211 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: ADMIN  */
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4220 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_GLOBOPS  */
#line 1129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4229 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: T_LOCOPS  */
#line 1133 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4238 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: REMOTEBAN  */
#line 1137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4247 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: T_SET  */
#line 1141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4256 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: MODULE  */
#line 1145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4265 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: T_OPME  */
#line 1149 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4274 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: NICK ':' RESV  */
#line 1153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4283 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: JOIN ':' RESV  */
#line 1157 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4292 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: RESV  */
#line 1161 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4301 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: T_UNRESV  */
#line 1165 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4310 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: CLOSE  */
#line 1169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4319 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1173 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4328 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1183 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4344 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  struct ClassItem *class = class_find(block_state.class.buf, false);
  if (class == NULL)
    class = class_make();

  class->active = true;
  io_free(class->name);
  class->name = io_strdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip_local = block_state.max_perip_local.value;
  class->max_perip_global = block_state.max_perip_global.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
  class->max_sendq = block_state.max_sendq.value;
  class->max_recvq = block_state.max_recvq.value;
  class->max_channels = block_state.max_channels.value;

  if (block_state.min_idle.value > block_state.max_idle.value)
  {
    block_state.min_idle.value = 0;
    block_state.max_idle.value = 0;
    block_state.flags.value &= ~CLASS_FLAGS_FAKE_IDLE;
  }

  class->flags = block_state.flags.value;
  class->min_idle = block_state.min_idle.value;
  class->max_idle = block_state.max_idle.value;

  bool diff = (class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value ||
               class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value);
  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;

  if (diff)
    class_ip_limit_rebuild(class);
}
#line 4392 "conf_parser.c"
    break;

  case 228: /* class_name: NAME '=' QSTRING ';'  */
#line 1257 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4401 "conf_parser.c"
    break;

  case 229: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1263 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4410 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1269 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4419 "conf_parser.c"
    break;

  case 231: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4428 "conf_parser.c"
    break;

  case 232: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1281 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4437 "conf_parser.c"
    break;

  case 233: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1287 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4446 "conf_parser.c"
    break;

  case 234: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1293 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4455 "conf_parser.c"
    break;

  case 235: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1299 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4464 "conf_parser.c"
    break;

  case 236: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1305 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4474 "conf_parser.c"
    break;

  case 237: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1312 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4483 "conf_parser.c"
    break;

  case 238: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1318 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4492 "conf_parser.c"
    break;

  case 239: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1324 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4501 "conf_parser.c"
    break;

  case 240: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1330 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4513 "conf_parser.c"
    break;

  case 241: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1339 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4525 "conf_parser.c"
    break;

  case 242: /* $@8: %empty  */
#line 1348 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4534 "conf_parser.c"
    break;

  case 246: /* class_flags_item: RANDOM_IDLE  */
#line 1355 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4543 "conf_parser.c"
    break;

  case 247: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1359 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4552 "conf_parser.c"
    break;

  case 248: /* $@9: %empty  */
#line 1369 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4561 "conf_parser.c"
    break;

  case 250: /* $@10: %empty  */
#line 1375 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4569 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_TLS  */
#line 1381 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4578 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: HIDDEN  */
#line 1385 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4587 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: T_SERVER  */
#line 1389 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4596 "conf_parser.c"
    break;

  case 257: /* listen_flags_item: CLIENT  */
#line 1393 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4605 "conf_parser.c"
    break;

  case 258: /* listen_flags_item: DEFER  */
#line 1397 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4614 "conf_parser.c"
    break;

  case 266: /* $@11: %empty  */
#line 1405 "conf_parser.y"
                                 { reset_block_state(); }
#line 4620 "conf_parser.c"
    break;

  case 270: /* port_item: NUMBER  */
#line 1410 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_TLS)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4638 "conf_parser.c"
    break;

  case 271: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1423 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_TLS)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      listener_add(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4658 "conf_parser.c"
    break;

  case 272: /* listen_address: IP '=' QSTRING ';'  */
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4667 "conf_parser.c"
    break;

  case 273: /* listen_host: HOST '=' QSTRING ';'  */
#line 1446 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4676 "conf_parser.c"
    break;

  case 274: /* $@12: %empty  */
#line 1456 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4685 "conf_parser.c"
    break;

  case 275: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1460 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
  {
    char *s = node->data;

    if (EmptyString(s))
      continue;

    struct nuh_split nuh =
    {
      .nuhmask = s,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);

    struct MaskItem *conf = conf_make(CONF_CLIENT);
    conf->user = io_strdup(block_state.user.buf);
    conf->host = io_strdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = io_strdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->name = io_strdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 4732 "conf_parser.c"
    break;

  case 287: /* auth_user: USER '=' QSTRING ';'  */
#line 1515 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4741 "conf_parser.c"
    break;

  case 288: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1521 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4750 "conf_parser.c"
    break;

  case 289: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1527 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4759 "conf_parser.c"
    break;

  case 290: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1533 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4773 "conf_parser.c"
    break;

  case 291: /* $@13: %empty  */
#line 1544 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4782 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: EXCEED_LIMIT  */
#line 1551 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4791 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: KLINE_EXEMPT  */
#line 1555 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4800 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: XLINE_EXEMPT  */
#line 1559 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4809 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: NEED_IDENT  */
#line 1563 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4818 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: CAN_FLOOD  */
#line 1567 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4827 "conf_parser.c"
    break;

  case 300: /* auth_flags_item: NO_TILDE  */
#line 1571 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4836 "conf_parser.c"
    break;

  case 301: /* auth_flags_item: RESV_EXEMPT  */
#line 1575 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4845 "conf_parser.c"
    break;

  case 302: /* auth_flags_item: T_WEBIRC  */
#line 1579 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4854 "conf_parser.c"
    break;

  case 303: /* auth_flags_item: NEED_PASSWORD  */
#line 1583 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4863 "conf_parser.c"
    break;

  case 304: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1589 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    log_write(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 4880 "conf_parser.c"
    break;

  case 305: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1603 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4892 "conf_parser.c"
    break;

  case 306: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1612 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4904 "conf_parser.c"
    break;

  case 307: /* $@14: %empty  */
#line 1625 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4916 "conf_parser.c"
    break;

  case 308: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1632 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4927 "conf_parser.c"
    break;

  case 315: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1643 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4936 "conf_parser.c"
    break;

  case 316: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1649 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4945 "conf_parser.c"
    break;

  case 317: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4954 "conf_parser.c"
    break;

  case 323: /* service_name: NAME '=' QSTRING ';'  */
#line 1670 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 4969 "conf_parser.c"
    break;

  case 324: /* $@15: %empty  */
#line 1686 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4985 "conf_parser.c"
    break;

  case 325: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1697 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5000 "conf_parser.c"
    break;

  case 332: /* shared_name: NAME '=' QSTRING ';'  */
#line 1712 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5009 "conf_parser.c"
    break;

  case 333: /* shared_user: USER '=' QSTRING ';'  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct nuh_split nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);
  }
}
#line 5031 "conf_parser.c"
    break;

  case 334: /* $@16: %empty  */
#line 1737 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5040 "conf_parser.c"
    break;

  case 338: /* shared_type_item: KLINE  */
#line 1744 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5049 "conf_parser.c"
    break;

  case 339: /* shared_type_item: UNKLINE  */
#line 1748 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5058 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_DLINE  */
#line 1752 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5067 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_UNDLINE  */
#line 1756 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5076 "conf_parser.c"
    break;

  case 342: /* shared_type_item: XLINE  */
#line 1760 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5085 "conf_parser.c"
    break;

  case 343: /* shared_type_item: T_UNXLINE  */
#line 1764 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5094 "conf_parser.c"
    break;

  case 344: /* shared_type_item: RESV  */
#line 1768 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5103 "conf_parser.c"
    break;

  case 345: /* shared_type_item: T_UNRESV  */
#line 1772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5112 "conf_parser.c"
    break;

  case 346: /* shared_type_item: T_LOCOPS  */
#line 1776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5121 "conf_parser.c"
    break;

  case 347: /* shared_type_item: T_ALL  */
#line 1780 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5130 "conf_parser.c"
    break;

  case 348: /* $@17: %empty  */
#line 1790 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5144 "conf_parser.c"
    break;

  case 349: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1799 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5157 "conf_parser.c"
    break;

  case 355: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5166 "conf_parser.c"
    break;

  case 356: /* $@18: %empty  */
#line 1818 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5175 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: KLINE  */
#line 1825 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5184 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: UNKLINE  */
#line 1829 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5193 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_DLINE  */
#line 1833 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5202 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_UNDLINE  */
#line 1837 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5211 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: XLINE  */
#line 1841 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5220 "conf_parser.c"
    break;

  case 365: /* cluster_type_item: T_UNXLINE  */
#line 1845 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5229 "conf_parser.c"
    break;

  case 366: /* cluster_type_item: RESV  */
#line 1849 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5238 "conf_parser.c"
    break;

  case 367: /* cluster_type_item: T_UNRESV  */
#line 1853 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5247 "conf_parser.c"
    break;

  case 368: /* cluster_type_item: T_LOCOPS  */
#line 1857 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5256 "conf_parser.c"
    break;

  case 369: /* cluster_type_item: T_ALL  */
#line 1861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5265 "conf_parser.c"
    break;

  case 370: /* $@19: %empty  */
#line 1871 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5280 "conf_parser.c"
    break;

  case 371: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1881 "conf_parser.y"
{
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (server_valid_name(block_state.name.buf) == false)
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  struct MaskItem *conf = conf_make(CONF_SERVER);
  conf->addr = io_calloc(sizeof(*conf->addr));
  conf->port = block_state.port.value;
  conf->timeout = block_state.timeout.value;
  conf->flags = block_state.flags.value;
  conf->aftype = block_state.aftype.value;
  conf->host = io_strdup(block_state.host.buf);
  conf->name = io_strdup(block_state.name.buf);
  conf->passwd = io_strdup(block_state.rpass.buf);
  conf->spasswd = io_strdup(block_state.spass.buf);

  if (block_state.cert.buf[0])
    conf->certfp = io_strdup(block_state.cert.buf);

  if (block_state.ciph.buf[0])
    conf->cipher_list = io_strdup(block_state.ciph.buf);

  list_move_list(&block_state.leaf.list, &conf->leaf_list);
  list_move_list(&block_state.hub.list, &conf->hub_list);

  if (block_state.bind.buf[0])
  {
    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(block_state.bind.buf, NULL, &hints, &res))
      log_write(LOG_TYPE_IRCD, "Invalid netmask for server bind(%s)", block_state.bind.buf);
    else
    {
      assert(res);

      conf->bind = io_calloc(sizeof(*conf->bind));

      memcpy(conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind->ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  conf_dns_lookup(conf);
}
#line 5351 "conf_parser.c"
    break;

  case 390: /* connect_name: NAME '=' QSTRING ';'  */
#line 1967 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5360 "conf_parser.c"
    break;

  case 391: /* connect_host: HOST '=' QSTRING ';'  */
#line 1973 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5369 "conf_parser.c"
    break;

  case 392: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1979 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5378 "conf_parser.c"
    break;

  case 393: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1985 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5387 "conf_parser.c"
    break;

  case 394: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1991 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (*yylval.string == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr(yylval.string, ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
#line 5403 "conf_parser.c"
    break;

  case 395: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2004 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (*yylval.string == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr(yylval.string, ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5419 "conf_parser.c"
    break;

  case 396: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2017 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5428 "conf_parser.c"
    break;

  case 397: /* connect_port: PORT '=' NUMBER ';'  */
#line 2023 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5437 "conf_parser.c"
    break;

  case 398: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2029 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5446 "conf_parser.c"
    break;

  case 399: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5455 "conf_parser.c"
    break;

  case 400: /* $@20: %empty  */
#line 2039 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5463 "conf_parser.c"
    break;

  case 404: /* connect_flags_item: AUTOCONN  */
#line 2045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5472 "conf_parser.c"
    break;

  case 405: /* connect_flags_item: T_TLS  */
#line 2049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5481 "conf_parser.c"
    break;

  case 406: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2055 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5495 "conf_parser.c"
    break;

  case 407: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2066 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5504 "conf_parser.c"
    break;

  case 408: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5513 "conf_parser.c"
    break;

  case 409: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2078 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5522 "conf_parser.c"
    break;

  case 410: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2084 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5536 "conf_parser.c"
    break;

  case 411: /* $@21: %empty  */
#line 2099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5545 "conf_parser.c"
    break;

  case 412: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2103 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  struct MaskItem *conf = conf_make(CONF_KLINE);
  conf->user = io_strdup(block_state.user.buf);
  conf->host = io_strdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = io_strdup(block_state.rpass.buf);
  else
    conf->reason = io_strdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
#line 5568 "conf_parser.c"
    break;

  case 418: /* kill_user: USER '=' QSTRING ';'  */
#line 2126 "conf_parser.y"
{

  if (conf_parser_ctx.pass == 2)
  {
    struct nuh_split nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);
  }
}
#line 5591 "conf_parser.c"
    break;

  case 419: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5600 "conf_parser.c"
    break;

  case 420: /* $@22: %empty  */
#line 2156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5609 "conf_parser.c"
    break;

  case 421: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2160 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (address_parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    struct MaskItem *conf = conf_make(CONF_DLINE);
    conf->host = io_strdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = io_strdup(block_state.rpass.buf);
    else
      conf->reason = io_strdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
#line 5633 "conf_parser.c"
    break;

  case 427: /* deny_ip: IP '=' QSTRING ';'  */
#line 2184 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5642 "conf_parser.c"
    break;

  case 428: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2190 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5651 "conf_parser.c"
    break;

  case 434: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (*yylval.string && address_parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = io_strdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5668 "conf_parser.c"
    break;

  case 435: /* $@23: %empty  */
#line 2222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5677 "conf_parser.c"
    break;

  case 436: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2226 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  struct GecosItem *gecos = gecos_make();
  gecos->mask = io_strdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    gecos->reason = io_strdup(block_state.rpass.buf);
  else
    gecos->reason = io_strdup(CONF_NOREASON);
}
#line 5697 "conf_parser.c"
    break;

  case 442: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5706 "conf_parser.c"
    break;

  case 443: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2252 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5715 "conf_parser.c"
    break;

  case 499: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2319 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c"
    break;

  case 500: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2324 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5731 "conf_parser.c"
    break;

  case 501: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2329 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5739 "conf_parser.c"
    break;

  case 502: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2334 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5747 "conf_parser.c"
    break;

  case 503: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2339 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5755 "conf_parser.c"
    break;

  case 504: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2344 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5763 "conf_parser.c"
    break;

  case 505: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2349 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5771 "conf_parser.c"
    break;

  case 506: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2354 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5779 "conf_parser.c"
    break;

  case 507: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2359 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5787 "conf_parser.c"
    break;

  case 508: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2364 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5795 "conf_parser.c"
    break;

  case 509: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2369 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5803 "conf_parser.c"
    break;

  case 510: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2374 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5811 "conf_parser.c"
    break;

  case 511: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2379 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5819 "conf_parser.c"
    break;

  case 512: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2384 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5827 "conf_parser.c"
    break;

  case 513: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2389 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5835 "conf_parser.c"
    break;

  case 514: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2394 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5846 "conf_parser.c"
    break;

  case 515: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2402 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5854 "conf_parser.c"
    break;

  case 516: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2407 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5862 "conf_parser.c"
    break;

  case 517: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2412 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5870 "conf_parser.c"
    break;

  case 518: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2417 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5878 "conf_parser.c"
    break;

  case 519: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2422 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5886 "conf_parser.c"
    break;

  case 520: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2427 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5894 "conf_parser.c"
    break;

  case 521: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2432 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5902 "conf_parser.c"
    break;

  case 522: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2437 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5910 "conf_parser.c"
    break;

  case 523: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2442 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5918 "conf_parser.c"
    break;

  case 524: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2447 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5926 "conf_parser.c"
    break;

  case 525: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2452 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5934 "conf_parser.c"
    break;

  case 526: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2457 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5942 "conf_parser.c"
    break;

  case 527: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2462 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5950 "conf_parser.c"
    break;

  case 528: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2467 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5958 "conf_parser.c"
    break;

  case 529: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2472 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5966 "conf_parser.c"
    break;

  case 530: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2477 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5974 "conf_parser.c"
    break;

  case 531: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2482 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5982 "conf_parser.c"
    break;

  case 532: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2487 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5990 "conf_parser.c"
    break;

  case 533: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2492 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 5998 "conf_parser.c"
    break;

  case 534: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2497 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6006 "conf_parser.c"
    break;

  case 535: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2502 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6014 "conf_parser.c"
    break;

  case 536: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2507 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6022 "conf_parser.c"
    break;

  case 537: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2512 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c"
    break;

  case 538: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2517 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c"
    break;

  case 539: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2522 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6050 "conf_parser.c"
    break;

  case 540: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2531 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6058 "conf_parser.c"
    break;

  case 541: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2536 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6066 "conf_parser.c"
    break;

  case 542: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2541 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6074 "conf_parser.c"
    break;

  case 543: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2546 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6082 "conf_parser.c"
    break;

  case 544: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2551 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
  {
    ConfigGeneral.cloak_enabled = true;
    cloak_set_enabled();
  }
  else
  {
    ConfigGeneral.cloak_enabled = false;
    cloak_set_disabled();
  }
}
#line 6102 "conf_parser.c"
    break;

  case 545: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2568 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6113 "conf_parser.c"
    break;

  case 546: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2576 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6124 "conf_parser.c"
    break;

  case 547: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2584 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6135 "conf_parser.c"
    break;

  case 548: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2592 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6148 "conf_parser.c"
    break;

  case 549: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2602 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6161 "conf_parser.c"
    break;

  case 572: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2638 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6169 "conf_parser.c"
    break;

  case 573: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2643 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6178 "conf_parser.c"
    break;

  case 574: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2649 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6187 "conf_parser.c"
    break;

  case 575: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2655 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6195 "conf_parser.c"
    break;

  case 576: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2660 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6203 "conf_parser.c"
    break;

  case 577: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2665 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6211 "conf_parser.c"
    break;

  case 578: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2670 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6219 "conf_parser.c"
    break;

  case 579: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2675 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6227 "conf_parser.c"
    break;

  case 580: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2680 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6235 "conf_parser.c"
    break;

  case 581: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2685 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6243 "conf_parser.c"
    break;

  case 582: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2690 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6251 "conf_parser.c"
    break;

  case 583: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2695 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6259 "conf_parser.c"
    break;

  case 584: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2700 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6267 "conf_parser.c"
    break;

  case 585: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2705 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6275 "conf_parser.c"
    break;

  case 586: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2710 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6283 "conf_parser.c"
    break;

  case 587: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2715 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 1)
  {
    conf_error_report("max_kick_length too low, setting to 9");
    ConfigChannel.max_kick_length = KICKLEN;
  }
  else if ((yyvsp[-1].number) > KICKLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_kick_length too high, setting to %d", KICKLEN);
    conf_error_report(buf);

    ConfigChannel.max_kick_length = KICKLEN;
  }
  else
    ConfigChannel.max_kick_length = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c"
    break;

  case 588: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2738 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6317 "conf_parser.c"
    break;

  case 589: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2743 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6325 "conf_parser.c"
    break;

  case 603: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6334 "conf_parser.c"
    break;

  case 604: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].number) > 0)
    {
      event_flatten_links_write_file.when = (yyvsp[-1].number);
      event_add(&event_flatten_links_write_file, NULL);
    }
    else
     event_delete(&event_flatten_links_write_file);

    ConfigServerHide.flatten_links_delay = (yyvsp[-1].number);
  }
}
#line 6353 "conf_parser.c"
    break;

  case 605: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6365 "conf_parser.c"
    break;

  case 606: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2797 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6374 "conf_parser.c"
    break;

  case 607: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6383 "conf_parser.c"
    break;

  case 608: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2809 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6392 "conf_parser.c"
    break;

  case 609: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2815 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6404 "conf_parser.c"
    break;

  case 610: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6413 "conf_parser.c"
    break;

  case 611: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 2830 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6422 "conf_parser.c"
    break;


#line 6426 "conf_parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

