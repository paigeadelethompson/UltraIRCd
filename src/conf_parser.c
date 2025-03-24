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
#line 29 "conf_parser.y"


#include "stdinc.h"
#include "defaults.h"
#include "io_string.h"
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
    DISABLE_DNS = 297,             /* DISABLE_DNS  */
    DISABLE_FAKE_CHANNELS = 298,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 299, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 300,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 301,         /* DLINE_MIN_CIDR6  */
    EMAIL = 302,                   /* EMAIL  */
    ENABLE_ADMIN = 303,            /* ENABLE_ADMIN  */
    ENABLE_EXTBANS = 304,          /* ENABLE_EXTBANS  */
    ENABLE_OWNER = 305,            /* ENABLE_OWNER  */
    ENCRYPTED = 306,               /* ENCRYPTED  */
    EXCEED_LIMIT = 307,            /* EXCEED_LIMIT  */
    EXEMPT = 308,                  /* EXEMPT  */
    FAILED_OPER_NOTICE = 309,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 310,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 311,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 312,      /* FLATTEN_LINKS_FILE  */
    GECOS = 313,                   /* GECOS  */
    GENERAL = 314,                 /* GENERAL  */
    HIDDEN = 315,                  /* HIDDEN  */
    HIDDEN_NAME = 316,             /* HIDDEN_NAME  */
    HIDE_CHANS = 317,              /* HIDE_CHANS  */
    HIDE_IDLE = 318,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 319,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 320,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 321,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 322,           /* HIDE_SERVICES  */
    HOST = 323,                    /* HOST  */
    HUB = 324,                     /* HUB  */
    HUB_MASK = 325,                /* HUB_MASK  */
    INVISIBLE_ON_CONNECT = 326,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 327,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 328,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 329,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 330,      /* INVITE_EXPIRE_TIME  */
    IP = 331,                      /* IP  */
    IRCD_AUTH = 332,               /* IRCD_AUTH  */
    IRCD_FLAGS = 333,              /* IRCD_FLAGS  */
    IRCD_SID = 334,                /* IRCD_SID  */
    JOIN = 335,                    /* JOIN  */
    KILL = 336,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 337,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 338,                   /* KLINE  */
    KLINE_EXEMPT = 339,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 340,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 341,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 342,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 343,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 344,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 345,               /* LEAF_MASK  */
    LISTEN = 346,                  /* LISTEN  */
    LOADMODULE = 347,              /* LOADMODULE  */
    MASK = 348,                    /* MASK  */
    MASS = 349,                    /* MASS  */
    MAX_ACCEPT = 350,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 351,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 352,                /* MAX_BANS  */
    MAX_BANS_LARGE = 353,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 354,            /* MAX_CHANNELS  */
    MAX_IDLE = 355,                /* MAX_IDLE  */
    MAX_INVITES = 356,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 357,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 358,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 359,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 360,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 361,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 362,              /* MAX_NUMBER  */
    MAX_TARGETS = 363,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 364,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 365,                 /* MESSAGE  */
    MIN_IDLE = 366,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 367,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 368,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 369,                  /* MODULE  */
    MODULE_BASE_PATH = 370,        /* MODULE_BASE_PATH  */
    MOTD = 371,                    /* MOTD  */
    MOTD_FILE = 372,               /* MOTD_FILE  */
    NAME = 373,                    /* NAME  */
    NEED_IDENT = 374,              /* NEED_IDENT  */
    NEED_PASSWORD = 375,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 376,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 377,            /* NETWORK_NAME  */
    NICK = 378,                    /* NICK  */
    NO_OPER_FLOOD = 379,           /* NO_OPER_FLOOD  */
    NO_TILDE = 380,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 381,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 382,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 383,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 384,             /* OPER_UMODES  */
    OPERATOR = 385,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 386,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 387,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 388,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 389,                /* PASSWORD  */
    PATH = 390,                    /* PATH  */
    PING_COOKIE = 391,             /* PING_COOKIE  */
    PING_TIME = 392,               /* PING_TIME  */
    PORT = 393,                    /* PORT  */
    RANDOM_IDLE = 394,             /* RANDOM_IDLE  */
    REASON = 395,                  /* REASON  */
    REDIRPORT = 396,               /* REDIRPORT  */
    REDIRSERV = 397,               /* REDIRSERV  */
    REHASH = 398,                  /* REHASH  */
    REMOTE = 399,                  /* REMOTE  */
    REMOTEBAN = 400,               /* REMOTEBAN  */
    RESIDENT = 401,                /* RESIDENT  */
    RESV = 402,                    /* RESV  */
    RESV_EXEMPT = 403,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 404,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 405,                 /* SECONDS  */
    MINUTES = 406,                 /* MINUTES  */
    HOURS = 407,                   /* HOURS  */
    DAYS = 408,                    /* DAYS  */
    WEEKS = 409,                   /* WEEKS  */
    MONTHS = 410,                  /* MONTHS  */
    YEARS = 411,                   /* YEARS  */
    SEND_PASSWORD = 412,           /* SEND_PASSWORD  */
    SENDQ = 413,                   /* SENDQ  */
    SERVERHIDE = 414,              /* SERVERHIDE  */
    SERVERINFO = 415,              /* SERVERINFO  */
    SHORT_MOTD = 416,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 417,       /* SPECIALS_IN_IDENT  */
    SPOOF = 418,                   /* SPOOF  */
    SQUIT = 419,                   /* SQUIT  */
    STATS_E_DISABLED = 420,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 421,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 422,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 423,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 424,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 425,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 426,       /* STATS_U_OPER_ONLY  */
    T_ALL = 427,                   /* T_ALL  */
    T_BIND = 428,                  /* T_BIND  */
    T_COMMAND = 429,               /* T_COMMAND  */
    T_CLUSTER = 430,               /* T_CLUSTER  */
    T_DEBUG = 431,                 /* T_DEBUG  */
    T_DLINE = 432,                 /* T_DLINE  */
    T_FILE = 433,                  /* T_FILE  */
    T_GLOBOPS = 434,               /* T_GLOBOPS  */
    T_IPV4 = 435,                  /* T_IPV4  */
    T_IPV6 = 436,                  /* T_IPV6  */
    T_LOCOPS = 437,                /* T_LOCOPS  */
    T_LOG = 438,                   /* T_LOG  */
    T_OPME = 439,                  /* T_OPME  */
    T_PREPEND = 440,               /* T_PREPEND  */
    T_PSEUDO = 441,                /* T_PSEUDO  */
    T_RECVQ = 442,                 /* T_RECVQ  */
    T_RESTART = 443,               /* T_RESTART  */
    T_SERVER = 444,                /* T_SERVER  */
    T_SERVICE = 445,               /* T_SERVICE  */
    T_SET = 446,                   /* T_SET  */
    T_SHARED = 447,                /* T_SHARED  */
    T_SIZE = 448,                  /* T_SIZE  */
    T_TARGET = 449,                /* T_TARGET  */
    T_TLS = 450,                   /* T_TLS  */
    T_UMODES = 451,                /* T_UMODES  */
    T_UNDLINE = 452,               /* T_UNDLINE  */
    T_UNLIMITED = 453,             /* T_UNLIMITED  */
    T_UNRESV = 454,                /* T_UNRESV  */
    T_UNXLINE = 455,               /* T_UNXLINE  */
    T_WEBIRC = 456,                /* T_WEBIRC  */
    TBOOL = 457,                   /* TBOOL  */
    THROTTLE_COUNT = 458,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 459,           /* THROTTLE_TIME  */
    TIMEOUT = 460,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 461,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 462, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 463,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 464,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 465, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 466,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 467, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 468,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 469,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 470,           /* TS_WARN_DELTA  */
    TWODOTS = 471,                 /* TWODOTS  */
    TYPE = 472,                    /* TYPE  */
    UNKLINE = 473,                 /* UNKLINE  */
    USE_LOGGING = 474,             /* USE_LOGGING  */
    USER = 475,                    /* USER  */
    VHOST = 476,                   /* VHOST  */
    VHOST6 = 477,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 478,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 479,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 480,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 481,                   /* XLINE  */
    XLINE_EXEMPT = 482,            /* XLINE_EXEMPT  */
    QSTRING = 483,                 /* QSTRING  */
    NUMBER = 484                   /* NUMBER  */
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
#define DISABLE_DNS 297
#define DISABLE_FAKE_CHANNELS 298
#define DISABLE_REMOTE_COMMANDS 299
#define DLINE_MIN_CIDR 300
#define DLINE_MIN_CIDR6 301
#define EMAIL 302
#define ENABLE_ADMIN 303
#define ENABLE_EXTBANS 304
#define ENABLE_OWNER 305
#define ENCRYPTED 306
#define EXCEED_LIMIT 307
#define EXEMPT 308
#define FAILED_OPER_NOTICE 309
#define FLATTEN_LINKS 310
#define FLATTEN_LINKS_DELAY 311
#define FLATTEN_LINKS_FILE 312
#define GECOS 313
#define GENERAL 314
#define HIDDEN 315
#define HIDDEN_NAME 316
#define HIDE_CHANS 317
#define HIDE_IDLE 318
#define HIDE_IDLE_FROM_OPERS 319
#define HIDE_SERVER_IPS 320
#define HIDE_SERVERS 321
#define HIDE_SERVICES 322
#define HOST 323
#define HUB 324
#define HUB_MASK 325
#define INVISIBLE_ON_CONNECT 326
#define INVITE_CLIENT_COUNT 327
#define INVITE_CLIENT_TIME 328
#define INVITE_DELAY_CHANNEL 329
#define INVITE_EXPIRE_TIME 330
#define IP 331
#define IRCD_AUTH 332
#define IRCD_FLAGS 333
#define IRCD_SID 334
#define JOIN 335
#define KILL 336
#define KILL_CHASE_TIME_LIMIT 337
#define KLINE 338
#define KLINE_EXEMPT 339
#define KLINE_MIN_CIDR 340
#define KLINE_MIN_CIDR6 341
#define KNOCK_CLIENT_COUNT 342
#define KNOCK_CLIENT_TIME 343
#define KNOCK_DELAY_CHANNEL 344
#define LEAF_MASK 345
#define LISTEN 346
#define LOADMODULE 347
#define MASK 348
#define MASS 349
#define MAX_ACCEPT 350
#define MAX_AWAY_LENGTH 351
#define MAX_BANS 352
#define MAX_BANS_LARGE 353
#define MAX_CHANNELS 354
#define MAX_IDLE 355
#define MAX_INVITES 356
#define MAX_KICK_LENGTH 357
#define MAX_MONITOR 358
#define MAX_NICK_CHANGES 359
#define MAX_NICK_LENGTH 360
#define MAX_NICK_TIME 361
#define MAX_NUMBER 362
#define MAX_TARGETS 363
#define MAX_TOPIC_LENGTH 364
#define MESSAGE 365
#define MIN_IDLE 366
#define MIN_NONWILDCARD 367
#define MIN_NONWILDCARD_SIMPLE 368
#define MODULE 369
#define MODULE_BASE_PATH 370
#define MOTD 371
#define MOTD_FILE 372
#define NAME 373
#define NEED_IDENT 374
#define NEED_PASSWORD 375
#define NETWORK_DESCRIPTION 376
#define NETWORK_NAME 377
#define NICK 378
#define NO_OPER_FLOOD 379
#define NO_TILDE 380
#define NUMBER_PER_CIDR 381
#define NUMBER_PER_IP_GLOBAL 382
#define NUMBER_PER_IP_LOCAL 383
#define OPER_UMODES 384
#define OPERATOR 385
#define OPERS_BYPASS_CALLERID 386
#define PACE_WAIT 387
#define PACE_WAIT_SIMPLE 388
#define PASSWORD 389
#define PATH 390
#define PING_COOKIE 391
#define PING_TIME 392
#define PORT 393
#define RANDOM_IDLE 394
#define REASON 395
#define REDIRPORT 396
#define REDIRSERV 397
#define REHASH 398
#define REMOTE 399
#define REMOTEBAN 400
#define RESIDENT 401
#define RESV 402
#define RESV_EXEMPT 403
#define RSA_PRIVATE_KEY_FILE 404
#define SECONDS 405
#define MINUTES 406
#define HOURS 407
#define DAYS 408
#define WEEKS 409
#define MONTHS 410
#define YEARS 411
#define SEND_PASSWORD 412
#define SENDQ 413
#define SERVERHIDE 414
#define SERVERINFO 415
#define SHORT_MOTD 416
#define SPECIALS_IN_IDENT 417
#define SPOOF 418
#define SQUIT 419
#define STATS_E_DISABLED 420
#define STATS_I_OPER_ONLY 421
#define STATS_K_OPER_ONLY 422
#define STATS_M_OPER_ONLY 423
#define STATS_O_OPER_ONLY 424
#define STATS_P_OPER_ONLY 425
#define STATS_U_OPER_ONLY 426
#define T_ALL 427
#define T_BIND 428
#define T_COMMAND 429
#define T_CLUSTER 430
#define T_DEBUG 431
#define T_DLINE 432
#define T_FILE 433
#define T_GLOBOPS 434
#define T_IPV4 435
#define T_IPV6 436
#define T_LOCOPS 437
#define T_LOG 438
#define T_OPME 439
#define T_PREPEND 440
#define T_PSEUDO 441
#define T_RECVQ 442
#define T_RESTART 443
#define T_SERVER 444
#define T_SERVICE 445
#define T_SET 446
#define T_SHARED 447
#define T_SIZE 448
#define T_TARGET 449
#define T_TLS 450
#define T_UMODES 451
#define T_UNDLINE 452
#define T_UNLIMITED 453
#define T_UNRESV 454
#define T_UNXLINE 455
#define T_WEBIRC 456
#define TBOOL 457
#define THROTTLE_COUNT 458
#define THROTTLE_TIME 459
#define TIMEOUT 460
#define TLS_CERTIFICATE_FILE 461
#define TLS_CERTIFICATE_FINGERPRINT 462
#define TLS_CIPHER_LIST 463
#define TLS_CIPHER_SUITES 464
#define TLS_CONNECTION_REQUIRED 465
#define TLS_DH_PARAM_FILE 466
#define TLS_MESSAGE_DIGEST_ALGORITHM 467
#define TLS_SUPPORTED_GROUPS 468
#define TS_MAX_DELTA 469
#define TS_WARN_DELTA 470
#define TWODOTS 471
#define TYPE 472
#define UNKLINE 473
#define USE_LOGGING 474
#define USER 475
#define VHOST 476
#define VHOST6 477
#define WARN_NO_CONNECT_BLOCK 478
#define WHOIS 479
#define WHOWAS_HISTORY_LENGTH 480
#define XLINE 481
#define XLINE_EXEMPT 482
#define QSTRING 483
#define NUMBER 484

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 138 "conf_parser.y"

  int number;
  char *string;

#line 696 "conf_parser.c"

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
  YYSYMBOL_DISABLE_DNS = 42,               /* DISABLE_DNS  */
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 43,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 44,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 45,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 46,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 47,                     /* EMAIL  */
  YYSYMBOL_ENABLE_ADMIN = 48,              /* ENABLE_ADMIN  */
  YYSYMBOL_ENABLE_EXTBANS = 49,            /* ENABLE_EXTBANS  */
  YYSYMBOL_ENABLE_OWNER = 50,              /* ENABLE_OWNER  */
  YYSYMBOL_ENCRYPTED = 51,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 52,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 53,                    /* EXEMPT  */
  YYSYMBOL_FAILED_OPER_NOTICE = 54,        /* FAILED_OPER_NOTICE  */
  YYSYMBOL_FLATTEN_LINKS = 55,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 56,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 57,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 58,                     /* GECOS  */
  YYSYMBOL_GENERAL = 59,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 60,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 61,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 62,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 63,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 64,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVER_IPS = 65,           /* HIDE_SERVER_IPS  */
  YYSYMBOL_HIDE_SERVERS = 66,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 67,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 68,                      /* HOST  */
  YYSYMBOL_HUB = 69,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 70,                  /* HUB_MASK  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 71,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 72,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 73,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 74,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 75,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 76,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 77,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 78,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 79,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 80,                      /* JOIN  */
  YYSYMBOL_KILL = 81,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 82,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 83,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 84,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 85,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 86,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 87,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 88,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 89,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 90,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 91,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 92,                /* LOADMODULE  */
  YYSYMBOL_MASK = 93,                      /* MASK  */
  YYSYMBOL_MASS = 94,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 95,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 96,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 97,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 98,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 99,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 100,                 /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 101,              /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 102,          /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 103,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 104,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 105,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 106,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 107,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 108,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 109,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 110,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 111,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 112,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 113,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 114,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 115,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 116,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 117,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 118,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 119,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 120,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 121,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 122,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 123,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 124,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 125,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 126,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 127,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 128,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 129,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 130,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 131,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 132,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 133,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 134,                 /* PASSWORD  */
  YYSYMBOL_PATH = 135,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 136,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 137,                /* PING_TIME  */
  YYSYMBOL_PORT = 138,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 139,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 140,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 141,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 142,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 143,                   /* REHASH  */
  YYSYMBOL_REMOTE = 144,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 145,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 146,                 /* RESIDENT  */
  YYSYMBOL_RESV = 147,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 148,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 149,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 150,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 151,                  /* MINUTES  */
  YYSYMBOL_HOURS = 152,                    /* HOURS  */
  YYSYMBOL_DAYS = 153,                     /* DAYS  */
  YYSYMBOL_WEEKS = 154,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 155,                   /* MONTHS  */
  YYSYMBOL_YEARS = 156,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 157,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 158,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 159,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 160,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 161,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 162,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 163,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 164,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 165,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 166,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 167,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 168,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 169,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 170,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 171,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 172,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 173,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 174,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 175,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 176,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 177,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 178,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 179,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 180,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 181,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 182,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 183,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 184,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 185,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 186,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 187,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 188,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 189,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 190,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 191,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 192,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 193,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 194,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 195,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 196,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 197,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 198,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 199,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 200,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 201,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 202,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 203,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 204,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 205,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 206,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 207, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 208,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 209,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 210,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 211,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 212, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 213,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 214,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 215,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 216,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 217,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 218,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 219,              /* USE_LOGGING  */
  YYSYMBOL_USER = 220,                     /* USER  */
  YYSYMBOL_VHOST = 221,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 222,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 223,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 224,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 225,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 226,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 227,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 228,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 229,                   /* NUMBER  */
  YYSYMBOL_230_ = 230,                     /* ';'  */
  YYSYMBOL_231_ = 231,                     /* '}'  */
  YYSYMBOL_232_ = 232,                     /* '='  */
  YYSYMBOL_233_ = 233,                     /* ':'  */
  YYSYMBOL_234_ = 234,                     /* ','  */
  YYSYMBOL_235_ = 235,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 236,                 /* $accept  */
  YYSYMBOL_conf = 237,                     /* conf  */
  YYSYMBOL_conf_item = 238,                /* conf_item  */
  YYSYMBOL_timespec_ = 239,                /* timespec_  */
  YYSYMBOL_timespec = 240,                 /* timespec  */
  YYSYMBOL_sizespec_ = 241,                /* sizespec_  */
  YYSYMBOL_sizespec = 242,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 243,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 244,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 245,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 246,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 247,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 248,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 249,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 250,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 251, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 252, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 253, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 254, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 255, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 256, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 257, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 258,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 259,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 260,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 261,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 262, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 263, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 264, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 265, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 266,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 267,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 268,              /* admin_entry  */
  YYSYMBOL_admin_items = 269,              /* admin_items  */
  YYSYMBOL_admin_item = 270,               /* admin_item  */
  YYSYMBOL_admin_name = 271,               /* admin_name  */
  YYSYMBOL_admin_email = 272,              /* admin_email  */
  YYSYMBOL_admin_description = 273,        /* admin_description  */
  YYSYMBOL_motd_entry = 274,               /* motd_entry  */
  YYSYMBOL_275_1 = 275,                    /* $@1  */
  YYSYMBOL_motd_items = 276,               /* motd_items  */
  YYSYMBOL_motd_item = 277,                /* motd_item  */
  YYSYMBOL_motd_mask = 278,                /* motd_mask  */
  YYSYMBOL_motd_file = 279,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 280,             /* pseudo_entry  */
  YYSYMBOL_281_2 = 281,                    /* $@2  */
  YYSYMBOL_pseudo_items = 282,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 283,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 284,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 285,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 286,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 287,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 288,            /* logging_entry  */
  YYSYMBOL_logging_items = 289,            /* logging_items  */
  YYSYMBOL_logging_item = 290,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 291,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 292,       /* logging_file_entry  */
  YYSYMBOL_293_3 = 293,                    /* $@3  */
  YYSYMBOL_logging_file_items = 294,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 295,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 296,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 297,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 298,        /* logging_file_type  */
  YYSYMBOL_299_4 = 299,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 300,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 301,               /* oper_entry  */
  YYSYMBOL_302_5 = 302,                    /* $@5  */
  YYSYMBOL_oper_items = 303,               /* oper_items  */
  YYSYMBOL_oper_item = 304,                /* oper_item  */
  YYSYMBOL_oper_name = 305,                /* oper_name  */
  YYSYMBOL_oper_user = 306,                /* oper_user  */
  YYSYMBOL_oper_password = 307,            /* oper_password  */
  YYSYMBOL_oper_whois = 308,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 309,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 310, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 311, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 312,               /* oper_class  */
  YYSYMBOL_oper_umodes = 313,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 314,               /* oper_flags  */
  YYSYMBOL_315_6 = 315,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 316,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 317,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 318,              /* class_entry  */
  YYSYMBOL_319_7 = 319,                    /* $@7  */
  YYSYMBOL_class_items = 320,              /* class_items  */
  YYSYMBOL_class_item = 321,               /* class_item  */
  YYSYMBOL_class_name = 322,               /* class_name  */
  YYSYMBOL_class_ping_time = 323,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 324, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 325, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 326,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 327,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 328,         /* class_max_number  */
  YYSYMBOL_class_sendq = 329,              /* class_sendq  */
  YYSYMBOL_class_recvq = 330,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 331,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 332,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 333,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 334,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 335,           /* class_max_idle  */
  YYSYMBOL_class_flags = 336,              /* class_flags  */
  YYSYMBOL_337_8 = 337,                    /* $@8  */
  YYSYMBOL_class_flags_items = 338,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 339,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 340,             /* listen_entry  */
  YYSYMBOL_341_9 = 341,                    /* $@9  */
  YYSYMBOL_listen_flags = 342,             /* listen_flags  */
  YYSYMBOL_343_10 = 343,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 344,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 345,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 346,             /* listen_items  */
  YYSYMBOL_listen_item = 347,              /* listen_item  */
  YYSYMBOL_listen_port = 348,              /* listen_port  */
  YYSYMBOL_349_11 = 349,                   /* $@11  */
  YYSYMBOL_port_items = 350,               /* port_items  */
  YYSYMBOL_port_item = 351,                /* port_item  */
  YYSYMBOL_listen_address = 352,           /* listen_address  */
  YYSYMBOL_listen_host = 353,              /* listen_host  */
  YYSYMBOL_auth_entry = 354,               /* auth_entry  */
  YYSYMBOL_355_12 = 355,                   /* $@12  */
  YYSYMBOL_auth_items = 356,               /* auth_items  */
  YYSYMBOL_auth_item = 357,                /* auth_item  */
  YYSYMBOL_auth_user = 358,                /* auth_user  */
  YYSYMBOL_auth_passwd = 359,              /* auth_passwd  */
  YYSYMBOL_auth_class = 360,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 361,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 362,               /* auth_flags  */
  YYSYMBOL_363_13 = 363,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 364,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 365,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 366,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 367,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 368,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 369,               /* resv_entry  */
  YYSYMBOL_370_14 = 370,                   /* $@14  */
  YYSYMBOL_resv_items = 371,               /* resv_items  */
  YYSYMBOL_resv_item = 372,                /* resv_item  */
  YYSYMBOL_resv_mask = 373,                /* resv_mask  */
  YYSYMBOL_resv_reason = 374,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 375,              /* resv_exempt  */
  YYSYMBOL_service_entry = 376,            /* service_entry  */
  YYSYMBOL_service_items = 377,            /* service_items  */
  YYSYMBOL_service_item = 378,             /* service_item  */
  YYSYMBOL_service_name = 379,             /* service_name  */
  YYSYMBOL_shared_entry = 380,             /* shared_entry  */
  YYSYMBOL_381_15 = 381,                   /* $@15  */
  YYSYMBOL_shared_items = 382,             /* shared_items  */
  YYSYMBOL_shared_item = 383,              /* shared_item  */
  YYSYMBOL_shared_name = 384,              /* shared_name  */
  YYSYMBOL_shared_user = 385,              /* shared_user  */
  YYSYMBOL_shared_type = 386,              /* shared_type  */
  YYSYMBOL_387_16 = 387,                   /* $@16  */
  YYSYMBOL_shared_types = 388,             /* shared_types  */
  YYSYMBOL_shared_type_item = 389,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 390,            /* cluster_entry  */
  YYSYMBOL_391_17 = 391,                   /* $@17  */
  YYSYMBOL_cluster_items = 392,            /* cluster_items  */
  YYSYMBOL_cluster_item = 393,             /* cluster_item  */
  YYSYMBOL_cluster_name = 394,             /* cluster_name  */
  YYSYMBOL_cluster_type = 395,             /* cluster_type  */
  YYSYMBOL_396_18 = 396,                   /* $@18  */
  YYSYMBOL_cluster_types = 397,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 398,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 399,            /* connect_entry  */
  YYSYMBOL_400_19 = 400,                   /* $@19  */
  YYSYMBOL_connect_items = 401,            /* connect_items  */
  YYSYMBOL_connect_item = 402,             /* connect_item  */
  YYSYMBOL_connect_name = 403,             /* connect_name  */
  YYSYMBOL_connect_host = 404,             /* connect_host  */
  YYSYMBOL_connect_timeout = 405,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 406,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 407,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 408,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 409, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 410,             /* connect_port  */
  YYSYMBOL_connect_aftype = 411,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 412,            /* connect_flags  */
  YYSYMBOL_413_20 = 413,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 414,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 415,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 416,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 417,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 418,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 419,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 420,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 421,               /* kill_entry  */
  YYSYMBOL_422_21 = 422,                   /* $@21  */
  YYSYMBOL_kill_items = 423,               /* kill_items  */
  YYSYMBOL_kill_item = 424,                /* kill_item  */
  YYSYMBOL_kill_user = 425,                /* kill_user  */
  YYSYMBOL_kill_reason = 426,              /* kill_reason  */
  YYSYMBOL_deny_entry = 427,               /* deny_entry  */
  YYSYMBOL_428_22 = 428,                   /* $@22  */
  YYSYMBOL_deny_items = 429,               /* deny_items  */
  YYSYMBOL_deny_item = 430,                /* deny_item  */
  YYSYMBOL_deny_ip = 431,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 432,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 433,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 434,             /* exempt_items  */
  YYSYMBOL_exempt_item = 435,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 436,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 437,              /* gecos_entry  */
  YYSYMBOL_438_23 = 438,                   /* $@23  */
  YYSYMBOL_gecos_items = 439,              /* gecos_items  */
  YYSYMBOL_gecos_item = 440,               /* gecos_item  */
  YYSYMBOL_gecos_name = 441,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 442,             /* gecos_reason  */
  YYSYMBOL_general_entry = 443,            /* general_entry  */
  YYSYMBOL_general_items = 444,            /* general_items  */
  YYSYMBOL_general_item = 445,             /* general_item  */
  YYSYMBOL_general_away_count = 446,       /* general_away_count  */
  YYSYMBOL_general_away_time = 447,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 448,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 449, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 450, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 451,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 452,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 453,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 454,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 455, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 456, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 457,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 458,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 459, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 460,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 461,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 462, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 463,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 464,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 465, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 466, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 467, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 468, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 469, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 470, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 471, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 472, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 473, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 474,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 475,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 476, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 477, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 478,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 479,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 480, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 481,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 482,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 483,     /* general_disable_auth  */
  YYSYMBOL_general_disable_dns = 484,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 485,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 486,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 487,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 488,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 489, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 490, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 491, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 492,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 493, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 494, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 495,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 496,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 497,     /* general_cloak_suffix  */
  YYSYMBOL_channel_entry = 498,            /* channel_entry  */
  YYSYMBOL_channel_items = 499,            /* channel_items  */
  YYSYMBOL_channel_item = 500,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 501,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 502,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 503,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 504, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 505, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 506, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 507, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 508, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 509, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 510, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 511, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 512,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 513,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 514,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 515,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 516,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 517, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 518, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 519,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 520,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 521,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 522, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 523, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 524, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 525, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 526,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 527, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 528,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 529,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 530 /* serverhide_hide_server_ips  */
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   1328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  236
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  295
/* YYNRULES -- Number of rules.  */
#define YYNRULES  613
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1286

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   484


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
       2,     2,     2,     2,   234,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   233,   230,
       2,   232,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   235,     2,   231,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   369,   369,   370,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   401,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   412,
     412,   413,   414,   415,   416,   423,   433,   440,   442,   444,
     444,   446,   450,   460,   462,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   483,   492,   501,   510,   519,   528,
     537,   546,   561,   576,   586,   600,   609,   632,   655,   663,
     672,   682,   684,   684,   685,   686,   687,   688,   690,   699,
     708,   722,   721,   739,   739,   740,   740,   740,   742,   748,
     759,   758,   777,   777,   778,   778,   778,   778,   778,   780,
     786,   792,   798,   821,   822,   822,   824,   824,   825,   827,
     834,   834,   847,   848,   850,   850,   851,   851,   853,   861,
     864,   870,   869,   875,   879,   883,   887,   891,   895,   899,
     903,   914,   913,   979,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   992,   998,  1004,  1010,
    1016,  1027,  1033,  1044,  1050,  1057,  1056,  1062,  1062,  1063,
    1067,  1071,  1075,  1079,  1083,  1087,  1091,  1095,  1099,  1103,
    1107,  1111,  1115,  1119,  1123,  1127,  1131,  1135,  1139,  1143,
    1147,  1151,  1155,  1159,  1163,  1167,  1171,  1175,  1186,  1185,
    1241,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1259,  1265,
    1271,  1277,  1283,  1289,  1295,  1301,  1307,  1314,  1320,  1326,
    1332,  1341,  1351,  1350,  1356,  1356,  1357,  1361,  1372,  1371,
    1378,  1377,  1382,  1382,  1383,  1387,  1391,  1395,  1399,  1405,
    1405,  1406,  1406,  1406,  1406,  1406,  1408,  1408,  1410,  1410,
    1412,  1425,  1442,  1448,  1459,  1458,  1506,  1506,  1507,  1508,
    1509,  1510,  1511,  1512,  1513,  1514,  1515,  1517,  1523,  1529,
    1535,  1547,  1546,  1552,  1552,  1553,  1557,  1561,  1565,  1569,
    1573,  1577,  1581,  1585,  1591,  1605,  1614,  1628,  1627,  1642,
    1642,  1643,  1643,  1643,  1643,  1645,  1651,  1657,  1667,  1669,
    1669,  1670,  1670,  1672,  1689,  1688,  1711,  1711,  1712,  1712,
    1712,  1712,  1714,  1720,  1740,  1739,  1745,  1745,  1746,  1750,
    1754,  1758,  1762,  1766,  1770,  1774,  1778,  1782,  1793,  1792,
    1811,  1811,  1812,  1812,  1812,  1814,  1821,  1820,  1826,  1826,
    1827,  1831,  1835,  1839,  1843,  1847,  1851,  1855,  1859,  1863,
    1874,  1873,  1939,  1939,  1940,  1941,  1942,  1943,  1944,  1945,
    1946,  1947,  1948,  1949,  1950,  1951,  1952,  1953,  1954,  1955,
    1957,  1963,  1969,  1975,  1981,  1994,  2007,  2013,  2019,  2023,
    2030,  2029,  2034,  2034,  2035,  2039,  2045,  2056,  2062,  2068,
    2074,  2090,  2089,  2113,  2113,  2114,  2114,  2114,  2116,  2136,
    2147,  2146,  2171,  2171,  2172,  2172,  2172,  2174,  2180,  2190,
    2192,  2192,  2193,  2193,  2195,  2213,  2212,  2233,  2233,  2234,
    2234,  2234,  2236,  2242,  2252,  2254,  2254,  2255,  2256,  2257,
    2258,  2259,  2260,  2261,  2262,  2263,  2264,  2265,  2266,  2267,
    2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,  2276,  2277,
    2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,
    2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,  2297,
    2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,  2307,
    2310,  2315,  2320,  2325,  2330,  2335,  2340,  2345,  2350,  2355,
    2360,  2365,  2370,  2375,  2380,  2385,  2393,  2398,  2403,  2408,
    2413,  2418,  2423,  2428,  2433,  2438,  2443,  2448,  2453,  2458,
    2463,  2468,  2473,  2478,  2483,  2488,  2493,  2498,  2503,  2508,
    2513,  2518,  2527,  2532,  2537,  2542,  2547,  2564,  2572,  2580,
    2588,  2598,  2611,  2613,  2613,  2614,  2615,  2616,  2617,  2618,
    2619,  2620,  2621,  2622,  2623,  2624,  2625,  2626,  2627,  2628,
    2629,  2630,  2631,  2632,  2634,  2639,  2645,  2651,  2656,  2661,
    2666,  2671,  2676,  2681,  2686,  2691,  2696,  2701,  2706,  2711,
    2734,  2739,  2748,  2750,  2750,  2751,  2752,  2753,  2754,  2755,
    2756,  2757,  2758,  2759,  2760,  2762,  2768,  2784,  2793,  2799,
    2805,  2811,  2820,  2826
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
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
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_DNS",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR",
  "DLINE_MIN_CIDR6", "EMAIL", "ENABLE_ADMIN", "ENABLE_EXTBANS",
  "ENABLE_OWNER", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY",
  "FLATTEN_LINKS_FILE", "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME",
  "INVITE_DELAY_CHANNEL", "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT",
  "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6",
  "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL",
  "LEAF_MASK", "LISTEN", "LOADMODULE", "MASK", "MASS", "MAX_ACCEPT",
  "MAX_AWAY_LENGTH", "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS",
  "MAX_IDLE", "MAX_INVITES", "MAX_KICK_LENGTH", "MAX_MONITOR",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MESSAGE", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE",
  "MODULE_BASE_PATH", "MOTD", "MOTD_FILE", "NAME", "NEED_IDENT",
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
  "general_disable_dns", "general_throttle_count", "general_throttle_time",
  "general_oper_umodes", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_default_floodtime", "general_cloak_enabled",
  "general_cloak_cidr_len_ipv4", "general_cloak_cidr_len_ipv6",
  "general_cloak_num_bits", "general_cloak_secret", "general_cloak_suffix",
  "channel_entry", "channel_items", "channel_item",
  "channel_enable_extbans", "channel_enable_owner", "channel_enable_admin",
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

#define YYPACT_NINF (-1035)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1035,   701, -1035,  -186,  -221,  -218, -1035, -1035, -1035,  -201,
   -1035,  -196, -1035, -1035, -1035,  -162,  -190, -1035, -1035, -1035,
    -154,  -148, -1035,  -131, -1035,  -129, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035,    46,   868,  -110,  -108,  -103,    27,   -99,
     484,   -86,   -77,   -72,  -118,   -62,   -67,   -66,   -63,   618,
     601,   -60,    24,   -57,    19,   -55,   -48,   -47,   -46,   -42,
      17, -1035, -1035, -1035, -1035, -1035,   -39,   -35,   -27,   -24,
     -21,   -18,   -17,   -16,   -14,    -5,    67,    86,    92,    93,
      96,    98,    99,   100,   188, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,   740,   386,    10, -1035,   102,    40,
   -1035, -1035,    39, -1035,   105,   107,   108,   109,   114,   115,
     116,   117,   120,   127,   128,   135,   136,   138,   139,   141,
     143,   144,   148,   151,   153,   154,   158,   160,   161,   162,
     163,   165,   167,   169,   175,   176,   178,   180,   183,   197,
     198,   199,   209,   210,   211,   212,   223,   225,   229,   230,
     231,   234,   237,   238,   240,   241,    88, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
     355,     5,    23,    -3,    -1,    79,     3,   402,    47, -1035,
     243,   245,   246,   247,   249,   254,   255,   260,   267,     2,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
      91,   268,   270,   271,   279,   280,   281,   287,   290,   291,
     295,   296,   300,   301,   303,   305,   307,   308,   205, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,    49,   166,   309,
      20, -1035, -1035, -1035,    94,   170, -1035,   310,    42, -1035,
   -1035,   146, -1035,   174,   192,   316,   253, -1035,   317,   319,
     257,   343,   347,   348,   322,   319,   319,   319,   323,   319,
     319,   325,   327,   328,   329,   333,   334, -1035,   335,   331,
     336,   339, -1035,   340,   341,   342,   346,   349,   350,   351,
     352,   353,   354,   363,   251, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,   337,   367,   368,   369,   371,   373,   374, -1035,   375,
     379,   382,   389,   391,   392,   393,   395,   227, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,   396,   399,     4, -1035, -1035,
   -1035,   390,   403, -1035, -1035,   404,   406,    36, -1035, -1035,
   -1035,   432,   319,   410,   319,   319,   433,   412,   413,   414,
     416,   419,   446,   427,   319,   455,   456,   431,   435,   459,
     463,   319,   437,   438,   439,   440,   442,   447,   319,   448,
     452,   453,   487,   458,   488,   319,   319,   489,   491,   466,
     495,   498,   501,   502,   506,   509,   510,   485,   319,   319,
     319,   513,   492,   486, -1035,   494,   493,   500, -1035,   503,
     511,   512,   515,   519,    14, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,   520,   521,    73, -1035, -1035,
   -1035,   497,   523,   524, -1035,   529, -1035,    50, -1035, -1035,
   -1035, -1035, -1035, -1035,   496, -1035, -1035, -1035,   504,   530,
     531,    48, -1035, -1035, -1035,   508,   532,   533, -1035,   534,
     536,   538,   539,   540,   541,   542,   264, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   546,   545,
     547,   548,    69, -1035, -1035, -1035, -1035,   543,   579,   319,
     514,   581,   556,   583,   584,   585,   558, -1035, -1035,   560,
     562,   592,   567,   568,   569,   571,   573,   574,   575,   576,
     577,   578,   580,   587,   591,   593,   566, -1035,   590,   594,
   -1035,    89, -1035, -1035, -1035, -1035,   609,   597, -1035,   588,
     598,   600,   602,   604,   605,   122, -1035, -1035, -1035, -1035,
   -1035,   596,   599, -1035,   603,   606, -1035,   610,    81, -1035,
   -1035, -1035, -1035,   611,   613,   614, -1035,   615,   272,   616,
     619,   624,   626,   627,   629,   632,   633,   634,   635,   640,
     642,   643,   644,   645,   648,   651, -1035, -1035,   654,   657,
     319,   650,   659,   319,   660,   319,   664,   665,   666,   667,
     319,   668,   668,   669, -1035, -1035,   672,  -120,   673,   620,
     676,   678,   677,   682,   684,   685,   687,   691,   319,   692,
     693,   683, -1035,   694,   695,   698, -1035,   699, -1035,   696,
     697,   700, -1035,   702,   703,   705,   706,   707,   709,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     728,   729,   730,   731,   732,   733,   734,   738,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   754,   755,   756,   757,   758,   759,   760,   761,   762,
     763,   764,   765,   766,   767, -1035, -1035,   710,   796,   768,
     771,   772,   774,   775,   776,   777, -1035,   778,   780,   779,
   -1035, -1035,   782,   783,   773,   784,   785, -1035,    -3, -1035,
     786,   788,   787, -1035, -1035,   790,   810,   789,   791,   792,
     794,   795,   822,   797,   798,   799, -1035, -1035,   800,   802,
     803,   804, -1035,   805,   806,   807,   808,   809,   811,   812,
     813,   814, -1035,   815,   816,   817,   818,   819,   820,   821,
     823,   824,   825,   826,   827,   828,   829,   830,   831,   832,
   -1035, -1035,   835,   801,   834, -1035,   836, -1035,   164, -1035,
     837,   839,   840,   841,   842, -1035,   843, -1035, -1035,   846,
     838,   847,   848, -1035, -1035, -1035, -1035, -1035,   319,   319,
     319,   319,   319,   319,   319, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,   849,   850,   851,     7,   852,   853,
     854,   855,   856,   857,   858,   859,   860,    18,   861,   862,
   -1035,   863,   864,   865,   866,   867,   869,   870,     8,   871,
     872,   873,   874,   875,   876,   877,   878, -1035,   879,   880,
   -1035, -1035,   881,   882, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   883,   884,   320,
     885,   886,   887,   888,   889, -1035,   890,   891, -1035,   892,
     893,    15,   908,   793, -1035, -1035, -1035,   895,   896, -1035,
     897,   898,   549,   899,   900,   901,   902,   903,   904,   905,
   -1035,   906,   907,   909, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,   910,   653, -1035, -1035,   911,   844,   845, -1035,    77,
   -1035, -1035, -1035, -1035,   912,   913,   914,   915, -1035, -1035,
     916,   708,   917, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035,  -211, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   668,   668,   668,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035,  -208, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,  -198, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,  -158, -1035,   919,   784,   920, -1035,
   -1035, -1035, -1035, -1035, -1035,   918, -1035,   921,   922, -1035,
     923, -1035,   924,   925, -1035, -1035,   926, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,  -157, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,  -151, -1035, -1035,   932,  -191,   929,   933, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,  -146, -1035, -1035, -1035,     7, -1035,
   -1035, -1035, -1035,     8, -1035,   320, -1035,    15, -1035, -1035,
   -1035,   927,   951,   994,   938,  1002,  1008,  1009, -1035,   549,
   -1035,   653,   934,   935,   936,   384, -1035, -1035,   708, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035,   937, -1035, -1035
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
       0,    93,    94,    96,    95,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,   570,   571,   572,   569,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   555,
     556,   566,   567,   568,     0,     0,     0,   433,     0,     0,
     431,   432,     0,   499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   446,   447,   448,
     491,   454,   492,   486,   487,   488,   489,   458,   449,   450,
     451,   452,   453,   473,   455,   456,   457,   459,   460,   490,
     464,   465,   466,   467,   463,   462,   468,   475,   476,   469,
     470,   471,   461,   472,   483,   484,   485,   481,   482,   474,
     479,   480,   477,   478,   493,   494,   495,   496,   497,   498,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   604,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,   598,   599,   600,   602,   601,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      69,    67,    65,    70,    71,    72,    66,    56,    68,    58,
      59,    60,    61,    62,    63,    64,    57,     0,     0,     0,
       0,   125,   126,   127,     0,     0,   322,     0,     0,   320,
     321,     0,    97,     0,     0,     0,     0,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   553,     0,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   211,   212,   215,   217,   218,
     219,   220,   221,   222,   223,   213,   214,   216,   224,   225,
     226,     0,     0,     0,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   373,   374,
     375,   376,   377,   378,   379,   380,   382,   381,   384,   388,
     385,   386,   387,   383,   426,     0,     0,     0,   423,   424,
     425,     0,     0,   430,   441,     0,     0,     0,   438,   439,
     440,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   445,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,   277,   278,   279,   280,   285,
     281,   282,   283,   284,   417,     0,     0,     0,   414,   415,
     416,     0,     0,     0,   250,     0,   262,     0,   260,   261,
     263,   264,    52,    51,    48,    50,    46,    45,     0,     0,
       0,     0,   104,   105,   106,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   155,   156,
     157,   158,   161,   162,   163,   160,   159,   164,     0,     0,
       0,     0,     0,   310,   311,   312,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   593,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
     356,     0,   351,   352,   353,   128,     0,     0,   124,     0,
       0,     0,     0,     0,     0,     0,   113,   114,   116,   115,
     117,     0,     0,   319,     0,     0,   334,     0,     0,   327,
     328,   329,   330,     0,     0,     0,    91,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   552,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   210,   389,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   372,     0,     0,     0,   422,     0,   429,     0,
       0,     0,   437,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   444,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,     0,     0,
     413,   265,     0,     0,     0,     0,     0,   259,     0,   107,
       0,     0,     0,   103,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   314,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,   354,     0,     0,     0,   350,     0,   123,     0,   118,
       0,     0,     0,     0,     0,   112,     0,   318,   331,     0,
       0,     0,     0,   326,   100,    99,    98,   590,    29,    29,
      29,    29,    29,    29,    29,    31,    30,   591,   577,   576,
     574,   575,   578,   579,   580,   581,   582,   583,   584,   587,
     588,   585,   586,   589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,     0,     0,
     209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,     0,     0,
     421,   434,     0,     0,   436,   511,   516,   500,   501,   529,
     546,   547,   548,   549,   550,   551,   504,   544,   545,   537,
     538,   505,   506,   510,   519,   509,   507,   508,   514,   515,
     502,   513,   512,   535,   542,   543,   533,   541,   530,   528,
     531,   536,   532,   534,   521,   527,   526,   522,   523,   524,
     525,   539,   540,   518,   517,   520,   503,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,   412,     0,
       0,     0,   270,   266,   269,   249,    49,     0,     0,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,     0,     0,   308,   608,   605,   606,   607,   612,
     611,   613,   609,   610,    86,    83,    90,    82,    87,    88,
      89,    81,    85,    84,    75,    74,    77,    78,    76,    79,
      80,     0,     0,   349,   129,     0,     0,     0,   141,     0,
     133,   134,   136,   135,     0,     0,     0,     0,   111,   323,
       0,     0,     0,   325,    32,    33,    34,    35,    36,    37,
      38,   237,   238,   232,   247,   246,     0,   245,   233,   241,
     234,   240,   228,   239,   231,   230,   229,    39,    39,    39,
      41,    40,   235,   236,   395,   398,   399,   409,   406,   391,
     407,   404,   405,     0,   403,   408,   390,   397,   394,   393,
     392,   396,   410,   427,   428,   442,   443,   289,   290,   299,
     295,   296,   298,   303,   300,   301,   302,   297,     0,   294,
     288,   306,   305,   304,   287,   419,   418,   273,   272,   257,
     258,   255,   256,   254,     0,   253,     0,     0,     0,   108,
     109,   173,   170,   195,   206,   182,   191,     0,   180,   185,
       0,   200,     0,   194,   198,   204,   184,   187,   196,   197,
     201,   192,   199,   188,   205,   190,   186,   189,     0,   178,
     166,   168,   174,   171,   172,   167,   169,   317,   315,   316,
     355,   360,   366,   369,   362,   368,   363,   367,   365,   361,
     364,     0,   359,   137,     0,     0,     0,     0,   132,   120,
     119,   121,   122,   332,   338,   344,   347,   340,   346,   341,
     345,   343,   339,   342,     0,   337,   333,   243,     0,    42,
      43,    44,   401,     0,   292,     0,   251,     0,   271,   268,
     267,     0,     0,     0,     0,     0,     0,     0,   176,     0,
     357,     0,     0,     0,     0,     0,   131,   335,     0,   244,
     402,   293,   252,   181,   203,   179,   207,   202,   193,   183,
     177,   358,   138,   140,   139,   149,   148,   144,   146,   150,
     147,   143,   145,     0,   336,   142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1035, -1035, -1035,  -412,  -327, -1034,  -671, -1035, -1035, -1035,
   -1035,   262, -1035, -1035,   894, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,   972, -1035, -1035, -1035, -1035, -1035,
   -1035,   400, -1035, -1035, -1035, -1035, -1035,   553, -1035, -1035,
   -1035, -1035, -1035, -1035,   928, -1035, -1035, -1035, -1035,   113,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   623, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,   -79, -1035, -1035, -1035,   833, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035,   -56, -1035, -1035, -1035, -1035, -1035,   -64,
   -1035,   658, -1035, -1035, -1035,    29, -1035, -1035, -1035, -1035,
   -1035,   680, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   -58,
   -1035, -1035, -1035, -1035, -1035, -1035,   617, -1035, -1035, -1035,
   -1035, -1035,   930, -1035, -1035, -1035, -1035,   550, -1035, -1035,
   -1035, -1035, -1035,   -87, -1035, -1035, -1035,   582, -1035, -1035,
   -1035, -1035,   -71, -1035, -1035, -1035,   931, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   -52,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   679, -1035,
   -1035, -1035, -1035, -1035,   770, -1035, -1035, -1035, -1035,  1055,
   -1035, -1035, -1035, -1035,   769, -1035, -1035, -1035, -1035,   999,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,  1084, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,   939, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   865,   866,  1090,  1091,    28,    29,   244,
     524,   525,    30,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    31,    80,    81,    82,    83,    84,    32,    66,
     531,   532,   533,   534,    33,    73,   615,   616,   617,   618,
     619,   620,    34,   310,   311,   312,   313,   314,  1049,  1050,
    1051,  1052,  1053,  1206,  1283,    35,    67,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   787,
    1178,  1179,    36,    55,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   661,  1076,  1077,    37,    63,   516,   774,  1144,  1145,
     517,   518,   519,  1148,   993,   994,   520,   521,    38,    61,
     494,   495,   496,   497,   498,   499,   500,   759,  1128,  1129,
     501,   502,   503,    39,    68,   562,   563,   564,   565,   566,
      40,   318,   319,   320,    41,    75,   628,   629,   630,   631,
     632,   850,  1224,  1225,    42,    71,   601,   602,   603,   604,
     833,  1201,  1202,    43,    56,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   682,  1103,  1104,
     409,   410,   411,   412,   413,    44,    62,   507,   508,   509,
     510,    45,    57,   417,   418,   419,   420,    46,   129,   130,
     131,    47,    59,   427,   428,   429,   430,    48,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,    49,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    50,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     898,   899,   639,   249,   528,   414,   504,  1253,   645,   646,
     647,   414,   649,   650,    53,   485,  1101,    54,    76,  1227,
     316,   308,  1232,  1228,   511,   308,  1233,   522,   127,  1087,
    1088,  1089,  1234,   486,    58,  1139,  1235,   424,   897,    60,
     424,   127,    65,   316,    51,    52,   250,    76,   558,   528,
     598,   511,  1140,  1229,  1230,  1231,    77,   251,   252,   253,
     902,   903,   254,   255,    78,   487,    64,   256,   257,   258,
     558,  1074,  1236,  1248,   504,  1141,  1237,  1249,  1045,  1250,
     415,    69,   624,  1251,  1257,    77,   415,    70,  1258,   133,
     598,   512,   488,    78,   134,   135,   529,   136,   137,   513,
     559,   514,   138,   128,    72,   704,    74,   706,   707,   139,
     140,   141,   142,   143,   144,   243,   128,   716,   512,   145,
     146,   147,   559,   610,   723,   124,   513,   125,   514,   148,
     149,   730,   126,   150,   151,    79,   132,   317,   737,   738,
     560,   529,   152,   523,   416,   505,  1075,   624,   489,   240,
     416,   750,   751,   752,   425,   490,   491,   425,   241,   153,
     317,   515,   560,   242,    79,  1045,   245,   599,   246,   247,
     154,   610,   248,   155,   156,   307,   426,   492,   315,   426,
     321,   530,   322,   157,   158,   323,   324,   561,   515,    85,
     325,   159,   160,   328,   161,  1046,   162,   329,  -130,   625,
     163,   164,  -130,  1102,  1142,   330,   270,   599,   331,   561,
    1143,   332,   165,   505,   333,   334,   335,   166,   336,   167,
     168,   169,    86,    87,   170,   506,   530,   337,   381,   526,
     382,    88,   383,   576,   493,   695,    89,    90,    91,   309,
     611,   271,   805,   309,   272,   765,   384,   897,   326,   171,
     172,   607,   348,   173,   174,   175,   176,   177,   178,   179,
      92,    93,    94,    95,   625,   535,   600,   701,   349,   350,
    1047,   422,   609,   622,   273,    96,    97,    98,   385,   782,
     351,   776,  1046,   536,   274,    99,   100,   101,   611,   102,
     103,   180,   181,   506,  1048,   386,   612,   387,   626,   338,
     801,   627,   182,   183,   769,   388,   600,   613,  1207,   527,
     275,   184,   852,   185,   276,   537,   614,   389,   339,   483,
     834,   578,   277,   278,   340,   341,   279,   280,   342,   352,
     343,   344,   345,   886,   421,  1119,   889,   431,   891,   432,
     433,   434,   538,   896,   612,   390,   435,   436,   437,   438,
     353,   354,   439,   844,   281,   613,   485,  1047,   355,   440,
     441,   914,   356,   626,   614,   391,   627,   442,   443,   357,
     444,   445,  1120,   446,   486,   447,   448,   358,   359,   360,
     449,  1048,   539,   450,   392,   451,   452,   381,   361,   382,
     453,   383,   454,   455,   456,   457,   605,   458,   540,   459,
     393,   460,   633,   535,  1121,   384,   487,   461,   462,   362,
     463,   282,   464,   283,   284,   465,   285,   286,   287,   346,
     634,   536,   858,   859,   860,   861,   862,   863,   864,   466,
     467,   468,   394,   488,   395,   396,   596,   385,   363,  1122,
    1123,   469,   470,   471,   472,  1124,  1064,  1065,  1066,  1067,
    1068,  1069,  1070,   537,   386,   473,   387,   474,   691,   640,
     541,   475,   476,   477,   388,  1275,   478,  1276,  1125,   479,
     480,   542,   481,   482,   543,   567,   389,   568,   569,   570,
     538,   571,   673,   636,   544,   133,   572,   573,   545,   489,
     134,   135,   574,   136,   137,   795,   490,   491,   138,   575,
     579,   638,   580,   581,   390,   139,   140,   141,   142,   143,
     144,   582,   583,   584,  1277,   145,   146,   147,   492,   585,
     539,  1126,   586,   587,   391,   148,   149,   588,   589,   150,
     151,  1278,   590,   591,  1254,   592,   540,   593,   152,   594,
     595,   606,   621,   392,   635,   641,   637,  1127,   638,   642,
     643,   644,   648,  1153,   651,   153,   652,   653,   654,   393,
    1279,  1280,   655,   658,   656,   657,   154,   675,   659,   155,
     156,   660,   662,   663,   664,   493,  1154,  1155,   665,   157,
     158,   666,   667,   668,   669,   670,   671,   159,   160,  1156,
     161,   394,   162,   395,   396,   672,   163,   164,   541,   676,
     677,   678,   270,   679,  1281,   680,   681,   683,   165,   542,
    1282,   684,   543,   166,   685,   167,   168,   169,   697,   249,
     170,   686,   544,   687,   688,   689,   545,   690,   693,  1157,
    1158,   694,  1159,   698,   703,   708,   699,   271,   700,   705,
     272,   709,   710,   711,   712,   171,   172,   713,   714,   173,
     174,   175,   176,   177,   178,   179,   715,   717,   718,  1160,
     719,   721,   250,  1161,   720,   722,   724,   725,   726,   727,
     273,   728,  1162,   251,   252,   253,   729,   731,   254,   255,
     274,   732,   733,   256,   257,   258,   735,   180,   181,   734,
     736,   739,  1163,   740,  1164,   741,  1165,   742,   182,   183,
     743,     2,     3,   744,   745,     4,   275,   184,   746,   185,
     276,   747,   748,  1166,   749,   753,   755,     5,   277,   278,
       6,   754,   279,   280,   756,   757,  1167,   771,  1168,     7,
     778,  1169,   758,  1170,   779,   760,  1191,  1171,   784,     8,
    1172,   348,   806,   761,   762,   803,  1173,   763,  1174,  1175,
     281,   764,   767,   768,     9,   772,   773,   349,   350,    10,
      11,   775,   780,   781,   785,   786,   788,  1176,   789,   351,
     790,   791,   792,   793,   794,  1177,   797,   798,    12,   799,
     800,   804,    13,   807,   808,   809,   810,   811,   812,   813,
     814,  1214,    14,    15,   815,   816,   830,   817,   818,   819,
    1192,   820,   821,   822,   823,   824,   825,   282,   826,   283,
     284,   836,   285,   286,   287,   827,    16,    17,   352,   828,
     831,   829,   905,   838,   846,  1193,   832,   837,   839,   847,
    1194,    18,   840,   848,   841,  1195,   842,   843,   849,   353,
     354,   854,   851,   855,   856,   857,   867,   355,    19,   868,
    1196,   356,  1197,  1198,   869,  1215,   870,   871,   357,   872,
      20,    21,   873,   874,   875,   876,   358,   359,   360,    85,
     877,  1199,   878,   879,   880,   881,    22,   361,   882,  1200,
    1216,   883,   887,   884,    23,  1217,   885,    24,   888,   890,
    1218,    25,   892,    26,   893,   894,   895,   897,   362,   900,
     901,   904,    86,    87,   906,  1219,   907,  1220,  1221,   908,
     909,    88,   910,   917,   911,   912,    89,    90,    91,   913,
     915,   916,   918,   919,   922,   923,  1222,   363,   920,   921,
     924,   783,   925,   926,  1223,   927,   928,   929,   977,   930,
      92,    93,    94,    95,   931,   932,   933,   934,   935,   936,
     937,   938,   939,   940,   941,    96,    97,    98,   942,   943,
     944,   945,   946,   947,   948,    99,   100,   101,   949,   102,
     103,   950,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   966,   967,   968,
     969,   970,   971,   972,   973,   974,   975,   976,   978,   980,
     979,   981,   982,   983,   984,   991,   986,   985,   987,   988,
     989,   990,  1001,   992,   997,   995,   998,   999,  1000,  1003,
    1004,  1002,  1005,  1006,  1007,  1008,  1009,  1147,  1011,  1010,
    1012,  1013,  1266,  1042,  1014,  1015,  1016,  1017,  1018,  1019,
     996,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    1029,  1030,   327,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1043,  1054,  1044,  1055,  1056,  1057,
    1061,  1263,  1058,  1059,  1060,  1062,  1204,  1205,  1063,  1071,
    1072,  1073,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1264,  1099,
    1100,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1146,  1149,  1150,  1151,  1152,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1265,  1189,
    1190,  1203,  1209,  1210,  1211,  1212,  1213,  1226,  1238,  1267,
    1240,  1241,  1268,  1269,  1242,  1243,  1244,  1245,  1246,  1247,
    1252,  1255,  1208,  1256,  1272,  1273,  1274,  1285,   845,   796,
    1270,  1284,  1259,  1262,   766,   777,  1239,  1261,   853,   802,
    1271,  1260,   597,   835,   423,   484,   770,   696,   347,     0,
       0,     0,     0,     0,     0,     0,   702,   674,   577,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   608,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   623,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   692
};

static const yytype_int16 yycheck[] =
{
     671,   672,   329,     1,     1,     1,     1,   198,   335,   336,
     337,     1,   339,   340,   235,     1,     8,   235,     1,   230,
       1,     1,   230,   234,     1,     1,   234,    30,     1,    11,
      12,    13,   230,    19,   235,    20,   234,     1,   229,   235,
       1,     1,   232,     1,   230,   231,    44,     1,     1,     1,
       1,     1,    37,  1087,  1088,  1089,    39,    55,    56,    57,
     180,   181,    60,    61,    47,    51,   228,    65,    66,    67,
       1,    64,   230,   230,     1,    60,   234,   234,     1,   230,
      76,   235,     1,   234,   230,    39,    76,   235,   234,     1,
       1,    68,    78,    47,     6,     7,    93,     9,    10,    76,
      53,    78,    14,    76,   235,   432,   235,   434,   435,    21,
      22,    23,    24,    25,    26,   233,    76,   444,    68,    31,
      32,    33,    53,     1,   451,   235,    76,   235,    78,    41,
      42,   458,   235,    45,    46,   118,   235,   118,   465,   466,
      93,    93,    54,   146,   140,   140,   139,     1,   134,   235,
     140,   478,   479,   480,   118,   141,   142,   118,   235,    71,
     118,   138,    93,   235,   118,     1,   228,   118,   235,   235,
      82,     1,   235,    85,    86,   235,   140,   163,   235,   140,
     235,   178,   230,    95,    96,   232,   232,   140,   138,     1,
     232,   103,   104,   232,   106,   118,   108,   232,   178,   118,
     112,   113,   178,   195,   189,   232,     1,   118,   232,   140,
     195,   232,   124,   140,   232,   232,   232,   129,   232,   131,
     132,   133,    34,    35,   136,   220,   178,   232,     1,   230,
       3,    43,     5,   231,   220,   231,    48,    49,    50,   219,
     118,    36,   569,   219,    39,   231,    19,   229,   231,   161,
     162,   231,     1,   165,   166,   167,   168,   169,   170,   171,
      72,    73,    74,    75,   118,     1,   217,   231,    17,    18,
     193,   231,   178,   231,    69,    87,    88,    89,    51,   231,
      29,   231,   118,    19,    79,    97,    98,    99,   118,   101,
     102,   203,   204,   220,   217,    68,   174,    70,   217,   232,
     231,   220,   214,   215,   231,    78,   217,   185,   231,   230,
     105,   223,   231,   225,   109,    51,   194,    90,   232,   231,
     231,   230,   117,   118,   232,   232,   121,   122,   232,    78,
     232,   232,   232,   660,   232,    15,   663,   232,   665,   232,
     232,   232,    78,   670,   174,   118,   232,   232,   232,   232,
      99,   100,   232,   231,   149,   185,     1,   193,   107,   232,
     232,   688,   111,   217,   194,   138,   220,   232,   232,   118,
     232,   232,    52,   232,    19,   232,   232,   126,   127,   128,
     232,   217,   118,   232,   157,   232,   232,     1,   137,     3,
     232,     5,   232,   232,   232,   232,   230,   232,   134,   232,
     173,   232,   228,     1,    84,    19,    51,   232,   232,   158,
     232,   206,   232,   208,   209,   232,   211,   212,   213,   231,
     228,    19,   150,   151,   152,   153,   154,   155,   156,   232,
     232,   232,   205,    78,   207,   208,   231,    51,   187,   119,
     120,   232,   232,   232,   232,   125,   858,   859,   860,   861,
     862,   863,   864,    51,    68,   232,    70,   232,   231,   202,
     196,   232,   232,   232,    78,    81,   232,    83,   148,   232,
     232,   207,   232,   232,   210,   232,    90,   232,   232,   232,
      78,   232,   231,   230,   220,     1,   232,   232,   224,   134,
       6,     7,   232,     9,    10,   231,   141,   142,    14,   232,
     232,   229,   232,   232,   118,    21,    22,    23,    24,    25,
      26,   232,   232,   232,   130,    31,    32,    33,   163,   232,
     118,   201,   232,   232,   138,    41,    42,   232,   232,    45,
      46,   147,   232,   232,  1205,   232,   134,   232,    54,   232,
     232,   232,   232,   157,   228,   202,   229,   227,   229,   202,
     202,   229,   229,     4,   229,    71,   229,   229,   229,   173,
     176,   177,   229,   232,   230,   230,    82,   230,   232,    85,
      86,   232,   232,   232,   232,   220,    27,    28,   232,    95,
      96,   232,   232,   232,   232,   232,   232,   103,   104,    40,
     106,   205,   108,   207,   208,   232,   112,   113,   196,   232,
     232,   232,     1,   232,   220,   232,   232,   232,   124,   207,
     226,   232,   210,   129,   232,   131,   132,   133,   228,     1,
     136,   232,   220,   232,   232,   232,   224,   232,   232,    80,
      81,   232,    83,   230,   202,   202,   232,    36,   232,   229,
      39,   229,   229,   229,   228,   161,   162,   228,   202,   165,
     166,   167,   168,   169,   170,   171,   229,   202,   202,   110,
     229,   202,    44,   114,   229,   202,   229,   229,   229,   229,
      69,   229,   123,    55,    56,    57,   229,   229,    60,    61,
      79,   229,   229,    65,    66,    67,   228,   203,   204,   202,
     202,   202,   143,   202,   145,   229,   147,   202,   214,   215,
     202,     0,     1,   202,   202,     4,   105,   223,   202,   225,
     109,   202,   202,   164,   229,   202,   230,    16,   117,   118,
      19,   229,   121,   122,   230,   232,   177,   230,   179,    28,
     234,   182,   232,   184,   230,   232,    83,   188,   230,    38,
     191,     1,   228,   232,   232,   202,   197,   232,   199,   200,
     149,   232,   232,   232,    53,   232,   232,    17,    18,    58,
      59,   232,   232,   232,   232,   232,   232,   218,   232,    29,
     232,   232,   232,   232,   232,   226,   230,   232,    77,   232,
     232,   202,    81,   202,   228,   202,   202,   202,   230,   229,
     228,    83,    91,    92,   202,   228,   230,   229,   229,   228,
     147,   228,   228,   228,   228,   228,   228,   206,   228,   208,
     209,   202,   211,   212,   213,   228,   115,   116,    78,   228,
     230,   228,   202,   235,   228,   172,   232,   230,   230,   230,
     177,   130,   232,   230,   232,   182,   232,   232,   232,    99,
     100,   230,   232,   230,   230,   230,   230,   107,   147,   230,
     197,   111,   199,   200,   230,   147,   230,   230,   118,   230,
     159,   160,   230,   230,   230,   230,   126,   127,   128,     1,
     230,   218,   230,   230,   230,   230,   175,   137,   230,   226,
     172,   230,   232,   229,   183,   177,   229,   186,   229,   229,
     182,   190,   228,   192,   229,   229,   229,   229,   158,   230,
     228,   228,    34,    35,   228,   197,   228,   199,   200,   232,
     228,    43,   228,   230,   229,   228,    48,    49,    50,   228,
     228,   228,   228,   228,   228,   228,   218,   187,   230,   230,
     230,   531,   230,   230,   226,   230,   230,   230,   228,   230,
      72,    73,    74,    75,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,    87,    88,    89,   230,   230,
     230,   230,   230,   230,   230,    97,    98,    99,   230,   101,
     102,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   202,   228,
     232,   229,   228,   228,   228,   232,   228,   230,   228,   230,
     228,   228,   202,   229,   228,   230,   228,   230,   228,   228,
     228,   232,   228,   228,   202,   228,   228,   234,   228,   230,
     228,   228,    94,   232,   230,   230,   230,   230,   230,   230,
     778,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,    80,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   228,   230,   228,   230,   228,   228,   228,
     232,   144,   230,   230,   228,   228,   232,   232,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   147,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   216,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   144,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   229,   147,
     230,   233,   144,   144,   233,   233,   233,   233,   233,   233,
     228,   232,  1049,   230,   230,   230,   230,   230,   615,   546,
    1249,  1258,  1228,  1237,   494,   517,  1147,  1235,   628,   562,
    1251,  1233,   288,   601,   129,   186,   507,   417,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   427,   364,   259,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   237,     0,     1,     4,    16,    19,    28,    38,    53,
      58,    59,    77,    81,    91,    92,   115,   116,   130,   147,
     159,   160,   175,   183,   186,   190,   192,   238,   243,   244,
     248,   268,   274,   280,   288,   301,   318,   340,   354,   369,
     376,   380,   390,   399,   421,   427,   433,   437,   443,   498,
     519,   230,   231,   235,   235,   319,   400,   428,   235,   438,
     235,   355,   422,   341,   228,   232,   275,   302,   370,   235,
     235,   391,   235,   281,   235,   381,     1,    39,    47,   118,
     269,   270,   271,   272,   273,     1,    34,    35,    43,    48,
      49,    50,    72,    73,    74,    75,    87,    88,    89,    97,
      98,    99,   101,   102,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   235,   235,   235,     1,    76,   434,
     435,   436,   235,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    42,
      45,    46,    54,    71,    82,    85,    86,    95,    96,   103,
     104,   106,   108,   112,   113,   124,   129,   131,   132,   133,
     136,   161,   162,   165,   166,   167,   168,   169,   170,   171,
     203,   204,   214,   215,   223,   225,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     235,   235,   235,   233,   245,   228,   235,   235,   235,     1,
      44,    55,    56,    57,    60,    61,    65,    66,    67,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
       1,    36,    39,    69,    79,   105,   109,   117,   118,   121,
     122,   149,   206,   208,   209,   211,   212,   213,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   235,     1,   219,
     289,   290,   291,   292,   293,   235,     1,   118,   377,   378,
     379,   235,   230,   232,   232,   232,   231,   270,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   231,   500,     1,    17,
      18,    29,    78,    99,   100,   107,   111,   118,   126,   127,
     128,   137,   158,   187,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,     1,     3,     5,    19,    51,    68,    70,    78,    90,
     118,   138,   157,   173,   205,   207,   208,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   416,
     417,   418,   419,   420,     1,    76,   140,   429,   430,   431,
     432,   232,   231,   435,     1,   118,   140,   439,   440,   441,
     442,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   231,   445,     1,    19,    51,    78,   134,
     141,   142,   163,   220,   356,   357,   358,   359,   360,   361,
     362,   366,   367,   368,     1,   140,   220,   423,   424,   425,
     426,     1,    68,    76,    78,   138,   342,   346,   347,   348,
     352,   353,    30,   146,   246,   247,   230,   230,     1,    93,
     178,   276,   277,   278,   279,     1,    19,    51,    78,   118,
     134,   196,   207,   210,   220,   224,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     1,    53,
      93,   140,   371,   372,   373,   374,   375,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   231,   521,   230,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   231,   250,     1,   118,
     217,   392,   393,   394,   395,   230,   232,   231,   290,   178,
       1,   118,   174,   185,   194,   282,   283,   284,   285,   286,
     287,   232,   231,   378,     1,   118,   217,   220,   382,   383,
     384,   385,   386,   228,   228,   228,   230,   229,   229,   240,
     202,   202,   202,   202,   229,   240,   240,   240,   229,   240,
     240,   229,   229,   229,   229,   229,   230,   230,   232,   232,
     232,   337,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   231,   321,   230,   232,   232,   232,   232,
     232,   232,   413,   232,   232,   232,   232,   232,   232,   232,
     232,   231,   402,   232,   232,   231,   430,   228,   230,   232,
     232,   231,   440,   202,   240,   229,   240,   240,   202,   229,
     229,   229,   228,   228,   202,   229,   240,   202,   202,   229,
     229,   202,   202,   240,   229,   229,   229,   229,   229,   229,
     240,   229,   229,   229,   202,   228,   202,   240,   240,   202,
     202,   229,   202,   202,   202,   202,   202,   202,   202,   229,
     240,   240,   240,   202,   229,   230,   230,   232,   232,   363,
     232,   232,   232,   232,   232,   231,   357,   232,   232,   231,
     424,   230,   232,   232,   343,   232,   231,   347,   234,   230,
     232,   232,   231,   277,   230,   232,   232,   315,   232,   232,
     232,   232,   232,   232,   232,   231,   304,   230,   232,   232,
     232,   231,   372,   202,   202,   240,   228,   202,   228,   202,
     202,   202,   230,   229,   228,   202,   228,   229,   229,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     230,   230,   232,   396,   231,   393,   202,   230,   235,   230,
     232,   232,   232,   232,   231,   283,   228,   230,   230,   232,
     387,   232,   231,   383,   230,   230,   230,   230,   150,   151,
     152,   153,   154,   155,   156,   239,   240,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   229,   229,   240,   232,   229,   240,
     229,   240,   228,   229,   229,   229,   240,   229,   242,   242,
     230,   228,   180,   181,   228,   202,   228,   228,   232,   228,
     228,   229,   228,   228,   240,   228,   228,   230,   228,   228,
     230,   230,   228,   228,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   228,   202,   232,
     228,   229,   228,   228,   228,   230,   228,   228,   230,   228,
     228,   232,   229,   350,   351,   230,   247,   228,   228,   230,
     228,   202,   232,   228,   228,   228,   228,   202,   228,   228,
     230,   228,   228,   228,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   228,   232,   230,   230,     1,   118,   193,   217,   294,
     295,   296,   297,   298,   228,   228,   228,   228,   230,   230,
     228,   232,   228,   230,   239,   239,   239,   239,   239,   239,
     239,   230,   230,   230,    64,   139,   338,   339,   230,   230,
     230,   230,   230,   230,   230,   230,   230,    11,    12,    13,
     241,   242,   230,   230,   230,   230,   230,   230,   230,   230,
     230,     8,   195,   414,   415,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,    15,
      52,    84,   119,   120,   125,   148,   201,   227,   364,   365,
     230,   230,   230,   230,   230,   230,   230,   230,   230,    20,
      37,    60,   189,   195,   344,   345,   216,   234,   349,   230,
     230,   230,   230,     4,    27,    28,    40,    80,    81,    83,
     110,   114,   123,   143,   145,   147,   164,   177,   179,   182,
     184,   188,   191,   197,   199,   200,   218,   226,   316,   317,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,    83,   147,   172,   177,   182,   197,   199,   200,   218,
     226,   397,   398,   230,   232,   232,   299,   231,   295,   230,
     230,   230,   230,   230,    83,   147,   172,   177,   182,   197,
     199,   200,   218,   226,   388,   389,   230,   230,   234,   241,
     241,   241,   230,   234,   230,   234,   230,   234,   229,   351,
     230,   233,   233,   233,   233,   233,   233,   233,   230,   234,
     230,   234,   228,   198,   242,   232,   230,   230,   234,   339,
     415,   365,   345,   144,   147,   144,    94,   147,   144,   144,
     317,   398,   230,   230,   230,    81,    83,   130,   147,   176,
     177,   220,   226,   300,   389,   230
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   236,   237,   237,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   239,
     239,   240,   240,   240,   240,   240,   240,   240,   240,   241,
     241,   242,   242,   242,   242,   243,   244,   245,   245,   246,
     246,   247,   247,   248,   249,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   269,   270,   270,   270,   270,   271,   272,
     273,   275,   274,   276,   276,   277,   277,   277,   278,   279,
     281,   280,   282,   282,   283,   283,   283,   283,   283,   284,
     285,   286,   287,   288,   289,   289,   290,   290,   290,   291,
     293,   292,   294,   294,   295,   295,   295,   295,   296,   297,
     297,   299,   298,   300,   300,   300,   300,   300,   300,   300,
     300,   302,   301,   303,   303,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   315,   314,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   319,   318,
     320,   320,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   337,   336,   338,   338,   339,   339,   341,   340,
     343,   342,   344,   344,   345,   345,   345,   345,   345,   346,
     346,   347,   347,   347,   347,   347,   349,   348,   350,   350,
     351,   351,   352,   353,   355,   354,   356,   356,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   358,   359,   360,
     361,   363,   362,   364,   364,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   366,   367,   368,   370,   369,   371,
     371,   372,   372,   372,   372,   373,   374,   375,   376,   377,
     377,   378,   378,   379,   381,   380,   382,   382,   383,   383,
     383,   383,   384,   385,   387,   386,   388,   388,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   391,   390,
     392,   392,   393,   393,   393,   394,   396,   395,   397,   397,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     400,   399,   401,   401,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   411,
     413,   412,   414,   414,   415,   415,   416,   417,   418,   419,
     420,   422,   421,   423,   423,   424,   424,   424,   425,   426,
     428,   427,   429,   429,   430,   430,   430,   431,   432,   433,
     434,   434,   435,   435,   436,   438,   437,   439,   439,   440,
     440,   440,   441,   442,   443,   444,   444,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   499,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   520,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
#line 401 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3521 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3527 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3533 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3539 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3545 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 406 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3551 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 407 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3557 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 408 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3563 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 409 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3569 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 412 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3575 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 413 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3581 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 414 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3587 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 415 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3593 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 416 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3599 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 424 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3608 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 434 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3617 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 440 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3625 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 447 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3634 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 451 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3643 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 484 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3655 "conf_parser.c"
    break;

  case 75: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 493 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3667 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 502 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3679 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 511 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3691 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 520 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3703 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 529 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3715 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 538 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3727 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 547 "conf_parser.y"
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
#line 3745 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 562 "conf_parser.y"
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
#line 3763 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 577 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3776 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 587 "conf_parser.y"
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
#line 3793 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 601 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3805 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 610 "conf_parser.y"
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
#line 3831 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 633 "conf_parser.y"
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
#line 3857 "conf_parser.c"
    break;

  case 88: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 656 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3868 "conf_parser.c"
    break;

  case 89: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 664 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3880 "conf_parser.c"
    break;

  case 90: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 673 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3889 "conf_parser.c"
    break;

  case 98: /* admin_name: NAME '=' QSTRING ';'  */
#line 691 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3901 "conf_parser.c"
    break;

  case 99: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 700 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3913 "conf_parser.c"
    break;

  case 100: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 709 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3925 "conf_parser.c"
    break;

  case 101: /* $@1: %empty  */
#line 722 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3934 "conf_parser.c"
    break;

  case 102: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 726 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3951 "conf_parser.c"
    break;

  case 108: /* motd_mask: MASK '=' QSTRING ';'  */
#line 743 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3960 "conf_parser.c"
    break;

  case 109: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 749 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3969 "conf_parser.c"
    break;

  case 110: /* $@2: %empty  */
#line 759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3978 "conf_parser.c"
    break;

  case 111: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 763 "conf_parser.y"
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
#line 3996 "conf_parser.c"
    break;

  case 119: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 781 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4005 "conf_parser.c"
    break;

  case 120: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4014 "conf_parser.c"
    break;

  case 121: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 793 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4023 "conf_parser.c"
    break;

  case 122: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 799 "conf_parser.y"
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
#line 4045 "conf_parser.c"
    break;

  case 129: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 4054 "conf_parser.c"
    break;

  case 130: /* $@3: %empty  */
#line 834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4063 "conf_parser.c"
    break;

  case 131: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4076 "conf_parser.c"
    break;

  case 138: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 854 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4087 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 862 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4095 "conf_parser.c"
    break;

  case 140: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 865 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4103 "conf_parser.c"
    break;

  case 141: /* $@4: %empty  */
#line 870 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4112 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: USER  */
#line 876 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4121 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: OPERATOR  */
#line 880 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4130 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: XLINE  */
#line 884 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4139 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: RESV  */
#line 888 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4148 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DLINE  */
#line 892 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4157 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KLINE  */
#line 896 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4166 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: KILL  */
#line 900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4175 "conf_parser.c"
    break;

  case 150: /* logging_file_type_item: T_DEBUG  */
#line 904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4184 "conf_parser.c"
    break;

  case 151: /* $@5: %empty  */
#line 914 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 4196 "conf_parser.c"
    break;

  case 152: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 921 "conf_parser.y"
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

    if (string_is_empty(s))
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

    conf_assign_class(conf, block_state.class.buf);
  }
}
#line 4258 "conf_parser.c"
    break;

  case 166: /* oper_name: NAME '=' QSTRING ';'  */
#line 993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4267 "conf_parser.c"
    break;

  case 167: /* oper_user: USER '=' QSTRING ';'  */
#line 999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4276 "conf_parser.c"
    break;

  case 168: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4285 "conf_parser.c"
    break;

  case 169: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4294 "conf_parser.c"
    break;

  case 170: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1017 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4308 "conf_parser.c"
    break;

  case 171: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1028 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4317 "conf_parser.c"
    break;

  case 172: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1034 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4331 "conf_parser.c"
    break;

  case 173: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4340 "conf_parser.c"
    break;

  case 174: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1051 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4349 "conf_parser.c"
    break;

  case 175: /* $@6: %empty  */
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4358 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL ':' REMOTE  */
#line 1064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4367 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: KILL  */
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4376 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4385 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: CONNECT  */
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4394 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4403 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: SQUIT  */
#line 1084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4412 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: KLINE  */
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4421 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: UNKLINE  */
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4430 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_DLINE  */
#line 1096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4439 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_UNDLINE  */
#line 1100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4448 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: XLINE  */
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4457 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_UNXLINE  */
#line 1108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4466 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: DIE  */
#line 1112 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4475 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_RESTART  */
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4484 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4493 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: REHASH  */
#line 1124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4502 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: ADMIN  */
#line 1128 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4511 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_GLOBOPS  */
#line 1132 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4520 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: T_LOCOPS  */
#line 1136 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4529 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: REMOTEBAN  */
#line 1140 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4538 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: T_SET  */
#line 1144 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4547 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: MODULE  */
#line 1148 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4556 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: T_OPME  */
#line 1152 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4565 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: NICK ':' RESV  */
#line 1156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4574 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: JOIN ':' RESV  */
#line 1160 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4583 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: RESV  */
#line 1164 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4592 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: T_UNRESV  */
#line 1168 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4601 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: CLOSE  */
#line 1172 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4610 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1176 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4619 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4635 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1197 "conf_parser.y"
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
#line 4683 "conf_parser.c"
    break;

  case 228: /* class_name: NAME '=' QSTRING ';'  */
#line 1260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4692 "conf_parser.c"
    break;

  case 229: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4701 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1272 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4710 "conf_parser.c"
    break;

  case 231: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1278 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4719 "conf_parser.c"
    break;

  case 232: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1284 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4728 "conf_parser.c"
    break;

  case 233: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1290 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4737 "conf_parser.c"
    break;

  case 234: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1296 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4746 "conf_parser.c"
    break;

  case 235: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1302 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4755 "conf_parser.c"
    break;

  case 236: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1308 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4765 "conf_parser.c"
    break;

  case 237: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1315 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4774 "conf_parser.c"
    break;

  case 238: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1321 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4783 "conf_parser.c"
    break;

  case 239: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1327 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4792 "conf_parser.c"
    break;

  case 240: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1333 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4804 "conf_parser.c"
    break;

  case 241: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1342 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4816 "conf_parser.c"
    break;

  case 242: /* $@8: %empty  */
#line 1351 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4825 "conf_parser.c"
    break;

  case 246: /* class_flags_item: RANDOM_IDLE  */
#line 1358 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4834 "conf_parser.c"
    break;

  case 247: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1362 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4843 "conf_parser.c"
    break;

  case 248: /* $@9: %empty  */
#line 1372 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4852 "conf_parser.c"
    break;

  case 250: /* $@10: %empty  */
#line 1378 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4860 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_TLS  */
#line 1384 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4869 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: HIDDEN  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4878 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: T_SERVER  */
#line 1392 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4887 "conf_parser.c"
    break;

  case 257: /* listen_flags_item: CLIENT  */
#line 1396 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4896 "conf_parser.c"
    break;

  case 258: /* listen_flags_item: DEFER  */
#line 1400 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4905 "conf_parser.c"
    break;

  case 266: /* $@11: %empty  */
#line 1408 "conf_parser.y"
                                 { reset_block_state(); }
#line 4911 "conf_parser.c"
    break;

  case 270: /* port_item: NUMBER  */
#line 1413 "conf_parser.y"
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
#line 4929 "conf_parser.c"
    break;

  case 271: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1426 "conf_parser.y"
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
#line 4949 "conf_parser.c"
    break;

  case 272: /* listen_address: IP '=' QSTRING ';'  */
#line 1443 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4958 "conf_parser.c"
    break;

  case 273: /* listen_host: HOST '=' QSTRING ';'  */
#line 1449 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4967 "conf_parser.c"
    break;

  case 274: /* $@12: %empty  */
#line 1459 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4976 "conf_parser.c"
    break;

  case 275: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1463 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
  {
    char *s = node->data;

    if (string_is_empty(s))
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

    conf_assign_class(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 5023 "conf_parser.c"
    break;

  case 287: /* auth_user: USER '=' QSTRING ';'  */
#line 1518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5032 "conf_parser.c"
    break;

  case 288: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1524 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5041 "conf_parser.c"
    break;

  case 289: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1530 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5050 "conf_parser.c"
    break;

  case 290: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1536 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5064 "conf_parser.c"
    break;

  case 291: /* $@13: %empty  */
#line 1547 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5073 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: EXCEED_LIMIT  */
#line 1554 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5082 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: KLINE_EXEMPT  */
#line 1558 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5091 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: XLINE_EXEMPT  */
#line 1562 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5100 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: NEED_IDENT  */
#line 1566 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5109 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: CAN_FLOOD  */
#line 1570 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5118 "conf_parser.c"
    break;

  case 300: /* auth_flags_item: NO_TILDE  */
#line 1574 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5127 "conf_parser.c"
    break;

  case 301: /* auth_flags_item: RESV_EXEMPT  */
#line 1578 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5136 "conf_parser.c"
    break;

  case 302: /* auth_flags_item: T_WEBIRC  */
#line 1582 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5145 "conf_parser.c"
    break;

  case 303: /* auth_flags_item: NEED_PASSWORD  */
#line 1586 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5154 "conf_parser.c"
    break;

  case 304: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1592 "conf_parser.y"
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
#line 5171 "conf_parser.c"
    break;

  case 305: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1606 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5183 "conf_parser.c"
    break;

  case 306: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1615 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5195 "conf_parser.c"
    break;

  case 307: /* $@14: %empty  */
#line 1628 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5207 "conf_parser.c"
    break;

  case 308: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1635 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5218 "conf_parser.c"
    break;

  case 315: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5227 "conf_parser.c"
    break;

  case 316: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5236 "conf_parser.c"
    break;

  case 317: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5245 "conf_parser.c"
    break;

  case 323: /* service_name: NAME '=' QSTRING ';'  */
#line 1673 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5260 "conf_parser.c"
    break;

  case 324: /* $@15: %empty  */
#line 1689 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5276 "conf_parser.c"
    break;

  case 325: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1700 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5291 "conf_parser.c"
    break;

  case 332: /* shared_name: NAME '=' QSTRING ';'  */
#line 1715 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5300 "conf_parser.c"
    break;

  case 333: /* shared_user: USER '=' QSTRING ';'  */
#line 1721 "conf_parser.y"
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
#line 5322 "conf_parser.c"
    break;

  case 334: /* $@16: %empty  */
#line 1740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5331 "conf_parser.c"
    break;

  case 338: /* shared_type_item: KLINE  */
#line 1747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5340 "conf_parser.c"
    break;

  case 339: /* shared_type_item: UNKLINE  */
#line 1751 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5349 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_DLINE  */
#line 1755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5358 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_UNDLINE  */
#line 1759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5367 "conf_parser.c"
    break;

  case 342: /* shared_type_item: XLINE  */
#line 1763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5376 "conf_parser.c"
    break;

  case 343: /* shared_type_item: T_UNXLINE  */
#line 1767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5385 "conf_parser.c"
    break;

  case 344: /* shared_type_item: RESV  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5394 "conf_parser.c"
    break;

  case 345: /* shared_type_item: T_UNRESV  */
#line 1775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5403 "conf_parser.c"
    break;

  case 346: /* shared_type_item: T_LOCOPS  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5412 "conf_parser.c"
    break;

  case 347: /* shared_type_item: T_ALL  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5421 "conf_parser.c"
    break;

  case 348: /* $@17: %empty  */
#line 1793 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5435 "conf_parser.c"
    break;

  case 349: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1802 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5448 "conf_parser.c"
    break;

  case 355: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1815 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5457 "conf_parser.c"
    break;

  case 356: /* $@18: %empty  */
#line 1821 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5466 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: KLINE  */
#line 1828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5475 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: UNKLINE  */
#line 1832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5484 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_DLINE  */
#line 1836 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5493 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_UNDLINE  */
#line 1840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5502 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: XLINE  */
#line 1844 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5511 "conf_parser.c"
    break;

  case 365: /* cluster_type_item: T_UNXLINE  */
#line 1848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5520 "conf_parser.c"
    break;

  case 366: /* cluster_type_item: RESV  */
#line 1852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5529 "conf_parser.c"
    break;

  case 367: /* cluster_type_item: T_UNRESV  */
#line 1856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5538 "conf_parser.c"
    break;

  case 368: /* cluster_type_item: T_LOCOPS  */
#line 1860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5547 "conf_parser.c"
    break;

  case 369: /* cluster_type_item: T_ALL  */
#line 1864 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5556 "conf_parser.c"
    break;

  case 370: /* $@19: %empty  */
#line 1874 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5571 "conf_parser.c"
    break;

  case 371: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1884 "conf_parser.y"
{
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
    struct io_addr tmp;
    if (address_from_string(block_state.bind.buf, &tmp) == false)
      log_write(LOG_TYPE_IRCD, "Invalid netmask for server bind(%s)", block_state.bind.buf);
    else
    {
      conf->bind = io_calloc(sizeof(*conf->bind));
      address_copy(conf->bind, &tmp);
    }
  }

  conf_assign_class(conf, block_state.class.buf);
  conf_dns_lookup(conf);
}
#line 5630 "conf_parser.c"
    break;

  case 390: /* connect_name: NAME '=' QSTRING ';'  */
#line 1958 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5639 "conf_parser.c"
    break;

  case 391: /* connect_host: HOST '=' QSTRING ';'  */
#line 1964 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5648 "conf_parser.c"
    break;

  case 392: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1970 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5657 "conf_parser.c"
    break;

  case 393: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1976 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5666 "conf_parser.c"
    break;

  case 394: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1982 "conf_parser.y"
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
#line 5682 "conf_parser.c"
    break;

  case 395: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1995 "conf_parser.y"
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
#line 5698 "conf_parser.c"
    break;

  case 396: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5707 "conf_parser.c"
    break;

  case 397: /* connect_port: PORT '=' NUMBER ';'  */
#line 2014 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5716 "conf_parser.c"
    break;

  case 398: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2020 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5725 "conf_parser.c"
    break;

  case 399: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2024 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5734 "conf_parser.c"
    break;

  case 400: /* $@20: %empty  */
#line 2030 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5742 "conf_parser.c"
    break;

  case 404: /* connect_flags_item: AUTOCONN  */
#line 2036 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5751 "conf_parser.c"
    break;

  case 405: /* connect_flags_item: T_TLS  */
#line 2040 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5760 "conf_parser.c"
    break;

  case 406: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2046 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5774 "conf_parser.c"
    break;

  case 407: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5783 "conf_parser.c"
    break;

  case 408: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2063 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5792 "conf_parser.c"
    break;

  case 409: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5801 "conf_parser.c"
    break;

  case 410: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2075 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5815 "conf_parser.c"
    break;

  case 411: /* $@21: %empty  */
#line 2090 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5824 "conf_parser.c"
    break;

  case 412: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2094 "conf_parser.y"
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
#line 5847 "conf_parser.c"
    break;

  case 418: /* kill_user: USER '=' QSTRING ';'  */
#line 2117 "conf_parser.y"
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
#line 5870 "conf_parser.c"
    break;

  case 419: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5879 "conf_parser.c"
    break;

  case 420: /* $@22: %empty  */
#line 2147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5888 "conf_parser.c"
    break;

  case 421: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2151 "conf_parser.y"
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
#line 5912 "conf_parser.c"
    break;

  case 427: /* deny_ip: IP '=' QSTRING ';'  */
#line 2175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5921 "conf_parser.c"
    break;

  case 428: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2181 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5930 "conf_parser.c"
    break;

  case 434: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2196 "conf_parser.y"
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
#line 5947 "conf_parser.c"
    break;

  case 435: /* $@23: %empty  */
#line 2213 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5956 "conf_parser.c"
    break;

  case 436: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2217 "conf_parser.y"
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
#line 5976 "conf_parser.c"
    break;

  case 442: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5985 "conf_parser.c"
    break;

  case 443: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2243 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5994 "conf_parser.c"
    break;

  case 500: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2311 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 6002 "conf_parser.c"
    break;

  case 501: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2316 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 6010 "conf_parser.c"
    break;

  case 502: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2321 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6018 "conf_parser.c"
    break;

  case 503: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2326 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6026 "conf_parser.c"
    break;

  case 504: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2331 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 6034 "conf_parser.c"
    break;

  case 505: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2336 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6042 "conf_parser.c"
    break;

  case 506: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2341 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6050 "conf_parser.c"
    break;

  case 507: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2346 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6058 "conf_parser.c"
    break;

  case 508: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2351 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6066 "conf_parser.c"
    break;

  case 509: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2356 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6074 "conf_parser.c"
    break;

  case 510: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2361 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6082 "conf_parser.c"
    break;

  case 511: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2366 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6090 "conf_parser.c"
    break;

  case 512: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2371 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6098 "conf_parser.c"
    break;

  case 513: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2376 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6106 "conf_parser.c"
    break;

  case 514: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2381 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6114 "conf_parser.c"
    break;

  case 515: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2386 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6125 "conf_parser.c"
    break;

  case 516: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2394 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6133 "conf_parser.c"
    break;

  case 517: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2399 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6141 "conf_parser.c"
    break;

  case 518: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2404 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6149 "conf_parser.c"
    break;

  case 519: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2409 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6157 "conf_parser.c"
    break;

  case 520: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2414 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6165 "conf_parser.c"
    break;

  case 521: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2419 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6173 "conf_parser.c"
    break;

  case 522: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2424 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6181 "conf_parser.c"
    break;

  case 523: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2429 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6189 "conf_parser.c"
    break;

  case 524: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2434 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6197 "conf_parser.c"
    break;

  case 525: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2439 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6205 "conf_parser.c"
    break;

  case 526: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2444 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6213 "conf_parser.c"
    break;

  case 527: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2449 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6221 "conf_parser.c"
    break;

  case 528: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2454 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6229 "conf_parser.c"
    break;

  case 529: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2459 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6237 "conf_parser.c"
    break;

  case 530: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2464 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6245 "conf_parser.c"
    break;

  case 531: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2469 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6253 "conf_parser.c"
    break;

  case 532: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2474 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6261 "conf_parser.c"
    break;

  case 533: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2479 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6269 "conf_parser.c"
    break;

  case 534: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2484 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6277 "conf_parser.c"
    break;

  case 535: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2489 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6285 "conf_parser.c"
    break;

  case 536: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2494 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6293 "conf_parser.c"
    break;

  case 537: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2499 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6301 "conf_parser.c"
    break;

  case 538: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2504 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6309 "conf_parser.c"
    break;

  case 539: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2509 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6317 "conf_parser.c"
    break;

  case 540: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2514 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6325 "conf_parser.c"
    break;

  case 541: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2519 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6337 "conf_parser.c"
    break;

  case 542: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2528 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6345 "conf_parser.c"
    break;

  case 543: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2533 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6353 "conf_parser.c"
    break;

  case 544: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2538 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6361 "conf_parser.c"
    break;

  case 545: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2543 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6369 "conf_parser.c"
    break;

  case 546: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2548 "conf_parser.y"
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
#line 6389 "conf_parser.c"
    break;

  case 547: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2565 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6400 "conf_parser.c"
    break;

  case 548: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2573 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6411 "conf_parser.c"
    break;

  case 549: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2581 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6422 "conf_parser.c"
    break;

  case 550: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2589 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6435 "conf_parser.c"
    break;

  case 551: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2599 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6448 "conf_parser.c"
    break;

  case 574: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2635 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6456 "conf_parser.c"
    break;

  case 575: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2640 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6465 "conf_parser.c"
    break;

  case 576: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2646 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6474 "conf_parser.c"
    break;

  case 577: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2652 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6482 "conf_parser.c"
    break;

  case 578: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2657 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6490 "conf_parser.c"
    break;

  case 579: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2662 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6498 "conf_parser.c"
    break;

  case 580: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2667 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6506 "conf_parser.c"
    break;

  case 581: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2672 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6514 "conf_parser.c"
    break;

  case 582: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2677 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6522 "conf_parser.c"
    break;

  case 583: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2682 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6530 "conf_parser.c"
    break;

  case 584: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2687 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6538 "conf_parser.c"
    break;

  case 585: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2692 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6546 "conf_parser.c"
    break;

  case 586: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2697 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6554 "conf_parser.c"
    break;

  case 587: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2702 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6562 "conf_parser.c"
    break;

  case 588: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2707 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6570 "conf_parser.c"
    break;

  case 589: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2712 "conf_parser.y"
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
#line 6596 "conf_parser.c"
    break;

  case 590: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2735 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6604 "conf_parser.c"
    break;

  case 591: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2740 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6612 "conf_parser.c"
    break;

  case 605: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6621 "conf_parser.c"
    break;

  case 606: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2769 "conf_parser.y"
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
#line 6640 "conf_parser.c"
    break;

  case 607: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2785 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6652 "conf_parser.c"
    break;

  case 608: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2794 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6661 "conf_parser.c"
    break;

  case 609: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2800 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6670 "conf_parser.c"
    break;

  case 610: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2806 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6679 "conf_parser.c"
    break;

  case 611: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6691 "conf_parser.c"
    break;

  case 612: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2821 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6700 "conf_parser.c"
    break;

  case 613: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 2827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6709 "conf_parser.c"
    break;


#line 6713 "conf_parser.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

