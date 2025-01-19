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
    MAX_BANS = 350,                /* MAX_BANS  */
    MAX_BANS_LARGE = 351,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 352,            /* MAX_CHANNELS  */
    MAX_IDLE = 353,                /* MAX_IDLE  */
    MAX_INVITES = 354,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 355,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 356,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 357,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 358,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 359,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 360,              /* MAX_NUMBER  */
    MAX_TARGETS = 361,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 362,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 363,                 /* MESSAGE  */
    MIN_IDLE = 364,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 365,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 366,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 367,                  /* MODULE  */
    MODULE_BASE_PATH = 368,        /* MODULE_BASE_PATH  */
    MOTD = 369,                    /* MOTD  */
    MOTD_FILE = 370,               /* MOTD_FILE  */
    NAME = 371,                    /* NAME  */
    NEED_IDENT = 372,              /* NEED_IDENT  */
    NEED_PASSWORD = 373,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 374,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 375,            /* NETWORK_NAME  */
    NICK = 376,                    /* NICK  */
    NO_OPER_FLOOD = 377,           /* NO_OPER_FLOOD  */
    NO_TILDE = 378,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 379,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 380,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 381,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 382,             /* OPER_UMODES  */
    OPERATOR = 383,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 384,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 385,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 386,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 387,                /* PASSWORD  */
    PATH = 388,                    /* PATH  */
    PING_COOKIE = 389,             /* PING_COOKIE  */
    PING_TIME = 390,               /* PING_TIME  */
    PORT = 391,                    /* PORT  */
    RANDOM_IDLE = 392,             /* RANDOM_IDLE  */
    REASON = 393,                  /* REASON  */
    REDIRPORT = 394,               /* REDIRPORT  */
    REDIRSERV = 395,               /* REDIRSERV  */
    REHASH = 396,                  /* REHASH  */
    REMOTE = 397,                  /* REMOTE  */
    REMOTEBAN = 398,               /* REMOTEBAN  */
    RESIDENT = 399,                /* RESIDENT  */
    RESV = 400,                    /* RESV  */
    RESV_EXEMPT = 401,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 402,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 403,                 /* SECONDS  */
    MINUTES = 404,                 /* MINUTES  */
    HOURS = 405,                   /* HOURS  */
    DAYS = 406,                    /* DAYS  */
    WEEKS = 407,                   /* WEEKS  */
    MONTHS = 408,                  /* MONTHS  */
    YEARS = 409,                   /* YEARS  */
    SEND_PASSWORD = 410,           /* SEND_PASSWORD  */
    SENDQ = 411,                   /* SENDQ  */
    SERVERHIDE = 412,              /* SERVERHIDE  */
    SERVERINFO = 413,              /* SERVERINFO  */
    SHORT_MOTD = 414,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 415,       /* SPECIALS_IN_IDENT  */
    SPOOF = 416,                   /* SPOOF  */
    SQUIT = 417,                   /* SQUIT  */
    STATS_E_DISABLED = 418,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 419,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 420,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 421,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 422,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 423,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 424,       /* STATS_U_OPER_ONLY  */
    T_ALL = 425,                   /* T_ALL  */
    T_BIND = 426,                  /* T_BIND  */
    T_COMMAND = 427,               /* T_COMMAND  */
    T_CLUSTER = 428,               /* T_CLUSTER  */
    T_DEBUG = 429,                 /* T_DEBUG  */
    T_DLINE = 430,                 /* T_DLINE  */
    T_FILE = 431,                  /* T_FILE  */
    T_GLOBOPS = 432,               /* T_GLOBOPS  */
    T_IPV4 = 433,                  /* T_IPV4  */
    T_IPV6 = 434,                  /* T_IPV6  */
    T_LOCOPS = 435,                /* T_LOCOPS  */
    T_LOG = 436,                   /* T_LOG  */
    T_OPME = 437,                  /* T_OPME  */
    T_PREPEND = 438,               /* T_PREPEND  */
    T_PSEUDO = 439,                /* T_PSEUDO  */
    T_RECVQ = 440,                 /* T_RECVQ  */
    T_RESTART = 441,               /* T_RESTART  */
    T_SERVER = 442,                /* T_SERVER  */
    T_SERVICE = 443,               /* T_SERVICE  */
    T_SET = 444,                   /* T_SET  */
    T_SHARED = 445,                /* T_SHARED  */
    T_SIZE = 446,                  /* T_SIZE  */
    T_TARGET = 447,                /* T_TARGET  */
    T_TLS = 448,                   /* T_TLS  */
    T_UMODES = 449,                /* T_UMODES  */
    T_UNDLINE = 450,               /* T_UNDLINE  */
    T_UNLIMITED = 451,             /* T_UNLIMITED  */
    T_UNRESV = 452,                /* T_UNRESV  */
    T_UNXLINE = 453,               /* T_UNXLINE  */
    T_WEBIRC = 454,                /* T_WEBIRC  */
    TBOOL = 455,                   /* TBOOL  */
    THROTTLE_COUNT = 456,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 457,           /* THROTTLE_TIME  */
    TIMEOUT = 458,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 459,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 460, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 461,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 462,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 463, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 464,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 465, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 466,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 467,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 468,           /* TS_WARN_DELTA  */
    TWODOTS = 469,                 /* TWODOTS  */
    TYPE = 470,                    /* TYPE  */
    UNKLINE = 471,                 /* UNKLINE  */
    USE_LOGGING = 472,             /* USE_LOGGING  */
    USER = 473,                    /* USER  */
    VHOST = 474,                   /* VHOST  */
    VHOST6 = 475,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 476,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 477,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 478,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 479,                   /* XLINE  */
    XLINE_EXEMPT = 480,            /* XLINE_EXEMPT  */
    QSTRING = 481,                 /* QSTRING  */
    NUMBER = 482                   /* NUMBER  */
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
#define MAX_BANS 350
#define MAX_BANS_LARGE 351
#define MAX_CHANNELS 352
#define MAX_IDLE 353
#define MAX_INVITES 354
#define MAX_KICK_LENGTH 355
#define MAX_MONITOR 356
#define MAX_NICK_CHANGES 357
#define MAX_NICK_LENGTH 358
#define MAX_NICK_TIME 359
#define MAX_NUMBER 360
#define MAX_TARGETS 361
#define MAX_TOPIC_LENGTH 362
#define MESSAGE 363
#define MIN_IDLE 364
#define MIN_NONWILDCARD 365
#define MIN_NONWILDCARD_SIMPLE 366
#define MODULE 367
#define MODULE_BASE_PATH 368
#define MOTD 369
#define MOTD_FILE 370
#define NAME 371
#define NEED_IDENT 372
#define NEED_PASSWORD 373
#define NETWORK_DESCRIPTION 374
#define NETWORK_NAME 375
#define NICK 376
#define NO_OPER_FLOOD 377
#define NO_TILDE 378
#define NUMBER_PER_CIDR 379
#define NUMBER_PER_IP_GLOBAL 380
#define NUMBER_PER_IP_LOCAL 381
#define OPER_UMODES 382
#define OPERATOR 383
#define OPERS_BYPASS_CALLERID 384
#define PACE_WAIT 385
#define PACE_WAIT_SIMPLE 386
#define PASSWORD 387
#define PATH 388
#define PING_COOKIE 389
#define PING_TIME 390
#define PORT 391
#define RANDOM_IDLE 392
#define REASON 393
#define REDIRPORT 394
#define REDIRSERV 395
#define REHASH 396
#define REMOTE 397
#define REMOTEBAN 398
#define RESIDENT 399
#define RESV 400
#define RESV_EXEMPT 401
#define RSA_PRIVATE_KEY_FILE 402
#define SECONDS 403
#define MINUTES 404
#define HOURS 405
#define DAYS 406
#define WEEKS 407
#define MONTHS 408
#define YEARS 409
#define SEND_PASSWORD 410
#define SENDQ 411
#define SERVERHIDE 412
#define SERVERINFO 413
#define SHORT_MOTD 414
#define SPECIALS_IN_IDENT 415
#define SPOOF 416
#define SQUIT 417
#define STATS_E_DISABLED 418
#define STATS_I_OPER_ONLY 419
#define STATS_K_OPER_ONLY 420
#define STATS_M_OPER_ONLY 421
#define STATS_O_OPER_ONLY 422
#define STATS_P_OPER_ONLY 423
#define STATS_U_OPER_ONLY 424
#define T_ALL 425
#define T_BIND 426
#define T_COMMAND 427
#define T_CLUSTER 428
#define T_DEBUG 429
#define T_DLINE 430
#define T_FILE 431
#define T_GLOBOPS 432
#define T_IPV4 433
#define T_IPV6 434
#define T_LOCOPS 435
#define T_LOG 436
#define T_OPME 437
#define T_PREPEND 438
#define T_PSEUDO 439
#define T_RECVQ 440
#define T_RESTART 441
#define T_SERVER 442
#define T_SERVICE 443
#define T_SET 444
#define T_SHARED 445
#define T_SIZE 446
#define T_TARGET 447
#define T_TLS 448
#define T_UMODES 449
#define T_UNDLINE 450
#define T_UNLIMITED 451
#define T_UNRESV 452
#define T_UNXLINE 453
#define T_WEBIRC 454
#define TBOOL 455
#define THROTTLE_COUNT 456
#define THROTTLE_TIME 457
#define TIMEOUT 458
#define TLS_CERTIFICATE_FILE 459
#define TLS_CERTIFICATE_FINGERPRINT 460
#define TLS_CIPHER_LIST 461
#define TLS_CIPHER_SUITES 462
#define TLS_CONNECTION_REQUIRED 463
#define TLS_DH_PARAM_FILE 464
#define TLS_MESSAGE_DIGEST_ALGORITHM 465
#define TLS_SUPPORTED_GROUPS 466
#define TS_MAX_DELTA 467
#define TS_WARN_DELTA 468
#define TWODOTS 469
#define TYPE 470
#define UNKLINE 471
#define USE_LOGGING 472
#define USER 473
#define VHOST 474
#define VHOST6 475
#define WARN_NO_CONNECT_BLOCK 476
#define WHOIS 477
#define WHOWAS_HISTORY_LENGTH 478
#define XLINE 479
#define XLINE_EXEMPT 480
#define QSTRING 481
#define NUMBER 482

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 136 "conf_parser.y"

  int number;
  char *string;

#line 692 "conf_parser.c"

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
  YYSYMBOL_MAX_BANS = 95,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 96,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 97,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 98,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 99,               /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 100,          /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 101,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 102,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 103,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 104,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 105,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 106,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 107,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 108,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 109,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 110,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 111,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 112,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 113,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 114,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 115,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 116,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 117,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 118,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 119,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 120,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 121,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 122,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 123,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 124,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 125,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 126,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 127,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 128,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 129,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 130,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 131,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 132,                 /* PASSWORD  */
  YYSYMBOL_PATH = 133,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 134,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 135,                /* PING_TIME  */
  YYSYMBOL_PORT = 136,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 137,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 138,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 139,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 140,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 141,                   /* REHASH  */
  YYSYMBOL_REMOTE = 142,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 143,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 144,                 /* RESIDENT  */
  YYSYMBOL_RESV = 145,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 146,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 147,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 148,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 149,                  /* MINUTES  */
  YYSYMBOL_HOURS = 150,                    /* HOURS  */
  YYSYMBOL_DAYS = 151,                     /* DAYS  */
  YYSYMBOL_WEEKS = 152,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 153,                   /* MONTHS  */
  YYSYMBOL_YEARS = 154,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 155,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 156,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 157,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 158,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 159,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 160,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 161,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 162,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 163,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 164,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 165,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 166,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 167,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 168,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 169,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 170,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 171,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 172,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 173,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 174,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 175,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 176,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 177,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 178,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 179,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 180,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 181,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 182,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 183,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 184,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 185,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 186,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 187,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 188,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 189,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 190,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 191,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 192,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 193,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 194,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 195,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 196,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 197,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 198,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 199,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 200,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 201,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 202,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 203,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 204,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 205, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 206,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 207,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 208,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 209,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 210, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 211,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 212,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 213,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 214,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 215,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 216,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 217,              /* USE_LOGGING  */
  YYSYMBOL_USER = 218,                     /* USER  */
  YYSYMBOL_VHOST = 219,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 220,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 221,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 222,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 223,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 224,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 225,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 226,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 227,                   /* NUMBER  */
  YYSYMBOL_228_ = 228,                     /* ';'  */
  YYSYMBOL_229_ = 229,                     /* '}'  */
  YYSYMBOL_230_ = 230,                     /* '='  */
  YYSYMBOL_231_ = 231,                     /* ':'  */
  YYSYMBOL_232_ = 232,                     /* ','  */
  YYSYMBOL_233_ = 233,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 234,                 /* $accept  */
  YYSYMBOL_conf = 235,                     /* conf  */
  YYSYMBOL_conf_item = 236,                /* conf_item  */
  YYSYMBOL_timespec_ = 237,                /* timespec_  */
  YYSYMBOL_timespec = 238,                 /* timespec  */
  YYSYMBOL_sizespec_ = 239,                /* sizespec_  */
  YYSYMBOL_sizespec = 240,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 241,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 242,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 243,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 244,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 245,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 246,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 247,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 248,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 249, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 250, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 251, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 252, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 253, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 254, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 255, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 256,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 257,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 258,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 259,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 260, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 261, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 262, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 263, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 264,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 265,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 266,              /* admin_entry  */
  YYSYMBOL_admin_items = 267,              /* admin_items  */
  YYSYMBOL_admin_item = 268,               /* admin_item  */
  YYSYMBOL_admin_name = 269,               /* admin_name  */
  YYSYMBOL_admin_email = 270,              /* admin_email  */
  YYSYMBOL_admin_description = 271,        /* admin_description  */
  YYSYMBOL_motd_entry = 272,               /* motd_entry  */
  YYSYMBOL_273_1 = 273,                    /* $@1  */
  YYSYMBOL_motd_items = 274,               /* motd_items  */
  YYSYMBOL_motd_item = 275,                /* motd_item  */
  YYSYMBOL_motd_mask = 276,                /* motd_mask  */
  YYSYMBOL_motd_file = 277,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 278,             /* pseudo_entry  */
  YYSYMBOL_279_2 = 279,                    /* $@2  */
  YYSYMBOL_pseudo_items = 280,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 281,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 282,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 283,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 284,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 285,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 286,            /* logging_entry  */
  YYSYMBOL_logging_items = 287,            /* logging_items  */
  YYSYMBOL_logging_item = 288,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 289,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 290,       /* logging_file_entry  */
  YYSYMBOL_291_3 = 291,                    /* $@3  */
  YYSYMBOL_logging_file_items = 292,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 293,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 294,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 295,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 296,        /* logging_file_type  */
  YYSYMBOL_297_4 = 297,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 298,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 299,               /* oper_entry  */
  YYSYMBOL_300_5 = 300,                    /* $@5  */
  YYSYMBOL_oper_items = 301,               /* oper_items  */
  YYSYMBOL_oper_item = 302,                /* oper_item  */
  YYSYMBOL_oper_name = 303,                /* oper_name  */
  YYSYMBOL_oper_user = 304,                /* oper_user  */
  YYSYMBOL_oper_password = 305,            /* oper_password  */
  YYSYMBOL_oper_whois = 306,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 307,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 308, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 309, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 310,               /* oper_class  */
  YYSYMBOL_oper_umodes = 311,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 312,               /* oper_flags  */
  YYSYMBOL_313_6 = 313,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 314,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 315,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 316,              /* class_entry  */
  YYSYMBOL_317_7 = 317,                    /* $@7  */
  YYSYMBOL_class_items = 318,              /* class_items  */
  YYSYMBOL_class_item = 319,               /* class_item  */
  YYSYMBOL_class_name = 320,               /* class_name  */
  YYSYMBOL_class_ping_time = 321,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 322, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 323, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 324,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 325,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 326,         /* class_max_number  */
  YYSYMBOL_class_sendq = 327,              /* class_sendq  */
  YYSYMBOL_class_recvq = 328,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 329,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 330,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 331,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 332,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 333,           /* class_max_idle  */
  YYSYMBOL_class_flags = 334,              /* class_flags  */
  YYSYMBOL_335_8 = 335,                    /* $@8  */
  YYSYMBOL_class_flags_items = 336,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 337,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 338,             /* listen_entry  */
  YYSYMBOL_339_9 = 339,                    /* $@9  */
  YYSYMBOL_listen_flags = 340,             /* listen_flags  */
  YYSYMBOL_341_10 = 341,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 342,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 343,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 344,             /* listen_items  */
  YYSYMBOL_listen_item = 345,              /* listen_item  */
  YYSYMBOL_listen_port = 346,              /* listen_port  */
  YYSYMBOL_347_11 = 347,                   /* $@11  */
  YYSYMBOL_port_items = 348,               /* port_items  */
  YYSYMBOL_port_item = 349,                /* port_item  */
  YYSYMBOL_listen_address = 350,           /* listen_address  */
  YYSYMBOL_listen_host = 351,              /* listen_host  */
  YYSYMBOL_auth_entry = 352,               /* auth_entry  */
  YYSYMBOL_353_12 = 353,                   /* $@12  */
  YYSYMBOL_auth_items = 354,               /* auth_items  */
  YYSYMBOL_auth_item = 355,                /* auth_item  */
  YYSYMBOL_auth_user = 356,                /* auth_user  */
  YYSYMBOL_auth_passwd = 357,              /* auth_passwd  */
  YYSYMBOL_auth_class = 358,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 359,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 360,               /* auth_flags  */
  YYSYMBOL_361_13 = 361,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 362,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 363,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 364,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 365,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 366,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 367,               /* resv_entry  */
  YYSYMBOL_368_14 = 368,                   /* $@14  */
  YYSYMBOL_resv_items = 369,               /* resv_items  */
  YYSYMBOL_resv_item = 370,                /* resv_item  */
  YYSYMBOL_resv_mask = 371,                /* resv_mask  */
  YYSYMBOL_resv_reason = 372,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 373,              /* resv_exempt  */
  YYSYMBOL_service_entry = 374,            /* service_entry  */
  YYSYMBOL_service_items = 375,            /* service_items  */
  YYSYMBOL_service_item = 376,             /* service_item  */
  YYSYMBOL_service_name = 377,             /* service_name  */
  YYSYMBOL_shared_entry = 378,             /* shared_entry  */
  YYSYMBOL_379_15 = 379,                   /* $@15  */
  YYSYMBOL_shared_items = 380,             /* shared_items  */
  YYSYMBOL_shared_item = 381,              /* shared_item  */
  YYSYMBOL_shared_name = 382,              /* shared_name  */
  YYSYMBOL_shared_user = 383,              /* shared_user  */
  YYSYMBOL_shared_type = 384,              /* shared_type  */
  YYSYMBOL_385_16 = 385,                   /* $@16  */
  YYSYMBOL_shared_types = 386,             /* shared_types  */
  YYSYMBOL_shared_type_item = 387,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 388,            /* cluster_entry  */
  YYSYMBOL_389_17 = 389,                   /* $@17  */
  YYSYMBOL_cluster_items = 390,            /* cluster_items  */
  YYSYMBOL_cluster_item = 391,             /* cluster_item  */
  YYSYMBOL_cluster_name = 392,             /* cluster_name  */
  YYSYMBOL_cluster_type = 393,             /* cluster_type  */
  YYSYMBOL_394_18 = 394,                   /* $@18  */
  YYSYMBOL_cluster_types = 395,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 396,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 397,            /* connect_entry  */
  YYSYMBOL_398_19 = 398,                   /* $@19  */
  YYSYMBOL_connect_items = 399,            /* connect_items  */
  YYSYMBOL_connect_item = 400,             /* connect_item  */
  YYSYMBOL_connect_name = 401,             /* connect_name  */
  YYSYMBOL_connect_host = 402,             /* connect_host  */
  YYSYMBOL_connect_timeout = 403,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 404,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 405,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 406,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 407, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 408,             /* connect_port  */
  YYSYMBOL_connect_aftype = 409,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 410,            /* connect_flags  */
  YYSYMBOL_411_20 = 411,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 412,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 413,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 414,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 415,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 416,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 417,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 418,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 419,               /* kill_entry  */
  YYSYMBOL_420_21 = 420,                   /* $@21  */
  YYSYMBOL_kill_items = 421,               /* kill_items  */
  YYSYMBOL_kill_item = 422,                /* kill_item  */
  YYSYMBOL_kill_user = 423,                /* kill_user  */
  YYSYMBOL_kill_reason = 424,              /* kill_reason  */
  YYSYMBOL_deny_entry = 425,               /* deny_entry  */
  YYSYMBOL_426_22 = 426,                   /* $@22  */
  YYSYMBOL_deny_items = 427,               /* deny_items  */
  YYSYMBOL_deny_item = 428,                /* deny_item  */
  YYSYMBOL_deny_ip = 429,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 430,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 431,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 432,             /* exempt_items  */
  YYSYMBOL_exempt_item = 433,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 434,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 435,              /* gecos_entry  */
  YYSYMBOL_436_23 = 436,                   /* $@23  */
  YYSYMBOL_gecos_items = 437,              /* gecos_items  */
  YYSYMBOL_gecos_item = 438,               /* gecos_item  */
  YYSYMBOL_gecos_name = 439,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 440,             /* gecos_reason  */
  YYSYMBOL_general_entry = 441,            /* general_entry  */
  YYSYMBOL_general_items = 442,            /* general_items  */
  YYSYMBOL_general_item = 443,             /* general_item  */
  YYSYMBOL_general_away_count = 444,       /* general_away_count  */
  YYSYMBOL_general_away_time = 445,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 446,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 447, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 448, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 449,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 450,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 451,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 452,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 453, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 454, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 455,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 456,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 457, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 458,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 459, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 460,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 461,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 462, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 463, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 464, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 465, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 466, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 467, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 468, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 469, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 470, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 471,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 472,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 473, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 474, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 475,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 476,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 477, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 478,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 479,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 480,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 481,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 482,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 483,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 484,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 485, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 486, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 487, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 488,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 489, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 490, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 491,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 492,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 493,     /* general_cloak_suffix  */
  YYSYMBOL_channel_entry = 494,            /* channel_entry  */
  YYSYMBOL_channel_items = 495,            /* channel_items  */
  YYSYMBOL_channel_item = 496,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 497,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 498,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 499,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 500, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 501, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 502, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 503, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 504, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 505, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 506, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 507, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 508,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 509,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 510,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 511,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 512,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 513, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 514, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 515,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 516,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 517,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 518, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 519, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 520, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 521, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 522,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 523, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 524,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 525,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 526 /* serverhide_hide_server_ips  */
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
#define YYNTOKENS  234
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  293
/* YYNRULES -- Number of rules.  */
#define YYNRULES  609
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1276

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   482


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
       2,     2,     2,     2,   232,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   231,   228,
       2,   230,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   233,     2,   229,     2,     2,     2,     2,
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
     225,   226,   227
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   365,   365,   366,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   397,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   408,
     408,   409,   410,   411,   412,   419,   429,   436,   438,   440,
     440,   442,   446,   456,   458,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   479,   488,   497,   506,   515,   524,
     533,   542,   557,   572,   582,   596,   605,   628,   651,   674,
     683,   693,   695,   695,   696,   697,   698,   699,   701,   710,
     719,   733,   732,   750,   750,   751,   751,   751,   753,   759,
     770,   769,   788,   788,   789,   789,   789,   789,   789,   791,
     797,   803,   809,   832,   833,   833,   835,   835,   836,   838,
     845,   845,   858,   859,   861,   861,   862,   862,   864,   872,
     875,   881,   880,   886,   890,   894,   898,   902,   906,   910,
     914,   925,   924,   990,   990,   991,   992,   993,   994,   995,
     996,   997,   998,   999,  1000,  1001,  1003,  1009,  1015,  1021,
    1027,  1038,  1044,  1055,  1061,  1068,  1067,  1073,  1073,  1074,
    1078,  1082,  1086,  1090,  1094,  1098,  1102,  1106,  1110,  1114,
    1118,  1122,  1126,  1130,  1134,  1138,  1142,  1146,  1150,  1154,
    1158,  1162,  1166,  1170,  1174,  1178,  1182,  1186,  1197,  1196,
    1252,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1270,  1276,
    1282,  1288,  1294,  1300,  1306,  1312,  1318,  1325,  1331,  1337,
    1343,  1352,  1362,  1361,  1367,  1367,  1368,  1372,  1383,  1382,
    1389,  1388,  1393,  1393,  1394,  1398,  1402,  1406,  1410,  1416,
    1416,  1417,  1417,  1417,  1417,  1417,  1419,  1419,  1421,  1421,
    1423,  1436,  1453,  1459,  1470,  1469,  1517,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1528,  1534,  1540,
    1546,  1558,  1557,  1563,  1563,  1564,  1568,  1572,  1576,  1580,
    1584,  1588,  1592,  1596,  1602,  1616,  1625,  1639,  1638,  1653,
    1653,  1654,  1654,  1654,  1654,  1656,  1662,  1668,  1678,  1680,
    1680,  1681,  1681,  1683,  1700,  1699,  1722,  1722,  1723,  1723,
    1723,  1723,  1725,  1731,  1751,  1750,  1756,  1756,  1757,  1761,
    1765,  1769,  1773,  1777,  1781,  1785,  1789,  1793,  1804,  1803,
    1822,  1822,  1823,  1823,  1823,  1825,  1832,  1831,  1837,  1837,
    1838,  1842,  1846,  1850,  1854,  1858,  1862,  1866,  1870,  1874,
    1885,  1884,  1962,  1962,  1963,  1964,  1965,  1966,  1967,  1968,
    1969,  1970,  1971,  1972,  1973,  1974,  1975,  1976,  1977,  1978,
    1980,  1986,  1992,  1998,  2004,  2017,  2030,  2036,  2042,  2046,
    2053,  2052,  2057,  2057,  2058,  2062,  2068,  2079,  2085,  2091,
    2097,  2113,  2112,  2136,  2136,  2137,  2137,  2137,  2139,  2159,
    2170,  2169,  2194,  2194,  2195,  2195,  2195,  2197,  2203,  2213,
    2215,  2215,  2216,  2216,  2218,  2236,  2235,  2256,  2256,  2257,
    2257,  2257,  2259,  2265,  2275,  2277,  2277,  2278,  2279,  2280,
    2281,  2282,  2283,  2284,  2285,  2286,  2287,  2288,  2289,  2290,
    2291,  2292,  2293,  2294,  2295,  2296,  2297,  2298,  2299,  2300,
    2301,  2302,  2303,  2304,  2305,  2306,  2307,  2308,  2309,  2310,
    2311,  2312,  2313,  2314,  2315,  2316,  2317,  2318,  2319,  2320,
    2321,  2322,  2323,  2324,  2325,  2326,  2327,  2328,  2331,  2336,
    2341,  2346,  2351,  2356,  2361,  2366,  2371,  2376,  2381,  2386,
    2391,  2396,  2401,  2406,  2411,  2416,  2421,  2426,  2431,  2436,
    2441,  2446,  2451,  2456,  2461,  2466,  2471,  2476,  2481,  2486,
    2491,  2496,  2501,  2506,  2511,  2516,  2521,  2526,  2535,  2540,
    2545,  2550,  2555,  2572,  2580,  2588,  2596,  2606,  2619,  2621,
    2621,  2622,  2623,  2624,  2625,  2626,  2627,  2628,  2629,  2630,
    2631,  2632,  2633,  2634,  2635,  2636,  2637,  2638,  2639,  2640,
    2642,  2647,  2653,  2659,  2664,  2669,  2674,  2679,  2684,  2689,
    2694,  2699,  2704,  2709,  2714,  2719,  2742,  2747,  2756,  2758,
    2758,  2759,  2760,  2761,  2762,  2763,  2764,  2765,  2766,  2767,
    2768,  2770,  2776,  2792,  2801,  2807,  2813,  2819,  2828,  2834
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
  "LOADMODULE", "MASK", "MASS", "MAX_ACCEPT", "MAX_BANS", "MAX_BANS_LARGE",
  "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES", "MAX_KICK_LENGTH",
  "MAX_MONITOR", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MESSAGE", "MIN_IDLE",
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
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_invisible_on_connect",
  "general_warn_no_connect_block", "general_stats_e_disabled",
  "general_stats_m_oper_only", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_u_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_specials_in_ident", "general_max_targets",
  "general_ping_cookie", "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes",
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

#define YYPACT_NINF (-1005)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1005,   717, -1005,  -158,  -219,  -205, -1005, -1005, -1005,  -202,
   -1005,  -196, -1005, -1005, -1005,  -186,  -181, -1005, -1005, -1005,
    -182,  -173, -1005,  -167, -1005,  -155, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,   152,   888,  -148,  -141,  -129,    31,  -123,
     466,  -120,  -119,  -118,  -168,  -107,  -109,  -100,   -99,   558,
     543,   -87,    87,   -75,    29,   -61,   -54,  -104,   -52,   -49,
       2, -1005, -1005, -1005, -1005, -1005,   -48,   -47,   -31,   -29,
     -26,   -23,   -20,   -19,   -15,   -14,     8,    27,    39,    52,
      61,    62,    63,    66,   202, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,   762,   646,    25, -1005,    70,    26,
   -1005, -1005,   146, -1005,    78,    80,    85,    88,    93,    94,
      98,    99,   102,   103,   105,   107,   108,   109,   115,   116,
     117,   119,   121,   122,   123,   125,   128,   140,   141,   142,
     143,   148,   149,   150,   151,   154,   155,   157,   161,   162,
     166,   169,   170,   174,   179,   180,   183,   184,   186,   187,
     191,   192,   193,   199,    58, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005,   376,    10,   427,    -9,
      37,    89,    33,   504,    35, -1005,   200,   204,   205,   206,
     207,   208,   209,   216,   219,   111, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005,   226,   225,   227,   230,
     233,   234,   235,   236,   238,   244,   247,   248,   249,   251,
     255,   256,   263,   270,   241, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,    15,   243,   271,    17, -1005, -1005, -1005,
     268,    22, -1005,   273,    16, -1005, -1005,    68, -1005,   -24,
      38,   124,   281, -1005,   285,   286,   176,   232,   283,   314,
     290,   286,   286,   286,   291,   286,   286,   293,   294,   295,
     297,   298,   299, -1005,   300,   296,   301,   303, -1005,   304,
     305,   308,   309,   310,   311,   312,   313,   315,   316,   318,
     277, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005,   321,   322,   323,
     325,   326,   327,   328, -1005,   331,   332,   335,   339,   341,
     343,   344,   345,   253, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005,   348,   350,    18, -1005, -1005, -1005,   357,   356, -1005,
   -1005,   355,   361,     6, -1005, -1005, -1005,   329,   286,   359,
     286,   286,   387,   365,   378,   379,   377,   381,   408,   382,
     286,   410,   388,   389,   419,   428,   286,   411,   412,   413,
     416,   418,   286,   421,   425,   426,   437,   429,   454,   286,
     286,   456,   457,   433,   461,   464,   469,   471,   472,   473,
     475,   439,   286,   286,   286,   476,   450,   453, -1005,   458,
     452,   455, -1005,   462,   463,   465,   467,   470,   266, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   474,
     478,    23, -1005, -1005, -1005,   460,   480,   484, -1005,   486,
   -1005,    19, -1005, -1005, -1005, -1005, -1005, -1005,   459, -1005,
   -1005, -1005,   483,   489,   490,    24, -1005, -1005, -1005,   500,
     499,   501, -1005,   502,   508,   510,   511,   513,   516,   526,
     189, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005,   506,   528,   531,   534,     3, -1005, -1005, -1005,
   -1005,   494,   530,   286,   539,   566,   541,   568,   570,   571,
     544, -1005, -1005,   549,   551,   581,   557,   560,   561,   559,
     563,   569,   572,   573,   574,   576,   577,   578,   579,   580,
     556, -1005,   564,   588, -1005,    97, -1005, -1005, -1005, -1005,
     594,   593, -1005,   451,   595,   592,   596,   597,   598,    14,
   -1005, -1005, -1005, -1005, -1005,   599,   601, -1005,   604,   603,
   -1005,   605,    96, -1005, -1005, -1005, -1005,   606,   608,   609,
   -1005,   610,   214,   612,   613,   614,   615,   616,   618,   619,
     620,   622,   625,   626,   627,   628,   629,   630,   633,   636,
   -1005, -1005,   638,   639,   286,   640,   641,   286,   649,   286,
     647,   650,   653,   654,   286,   655,   655,   644, -1005, -1005,
     657,  -102,   658,   624,   659,   665,   662,   667,   668,   669,
     673,   674,   286,   676,   677,   678, -1005,   682,   684,   683,
   -1005,   685, -1005,   686,   689,   688, -1005,   691,   692,   693,
     696,   697,   698,   699,   700,   705,   706,   710,   711,   712,
     713,   714,   715,   716,   718,   720,   721,   723,   724,   725,
     726,   727,   728,   729,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   749,   750,   751,   752,   753,
     754,   758,   761,   763,   764,   765,   766, -1005, -1005,   719,
     695,   687,   769,   770,   772,   773,   774,   768, -1005,   775,
     776,   777, -1005, -1005,   778,   780,   760,   781,   779, -1005,
      -9, -1005,   783,   784,   785, -1005, -1005,   786,   803,   787,
     788,   789,   790,   792,   811,   793,   794,   795, -1005, -1005,
     796,   798,   799,   800, -1005,   801,   802,   804,   805,   806,
     807,   808,   809,   810, -1005,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   822,   823,   824,   825,   826,
     827,   828, -1005, -1005,   831,   791,   830, -1005,   832, -1005,
       5, -1005,   833,   835,   836,   837,   838, -1005,   839, -1005,
   -1005,   842,   797,   843,   844, -1005, -1005, -1005, -1005, -1005,
     286,   286,   286,   286,   286,   286,   286, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005,   845,   846,   847,   -28,
     848,   849,   850,   851,   852,   853,   854,   855,   856,    34,
     857,   858, -1005,   859,   860,   861,   862,   863,   864,   865,
      36,   866,   867,   868,   869,   870,   871,   872,   873, -1005,
     874,   875, -1005, -1005,   876,   877, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005,   878,   879,   481,
     880,   881,   882,   883,   884, -1005,   885,   886, -1005,   887,
     889,   120,   485,   890, -1005, -1005, -1005,   891,   892, -1005,
     893,   895,   562,   896,   897,   898,   899,   900,   901,   902,
   -1005,   903,   904,   905, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005,   906,   245, -1005, -1005,   907,   834,   840, -1005,     4,
   -1005, -1005, -1005, -1005,   908,   909,   910,   911, -1005, -1005,
     912,   734,   913, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005,  -199, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005,   655,   655,   655,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,  -190, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,  -189, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,  -178, -1005,   915,   781,   916, -1005,
   -1005, -1005, -1005, -1005, -1005,   188, -1005,   565,   914, -1005,
     917, -1005,   918,   919, -1005, -1005,   920, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,  -176, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005,  -171, -1005, -1005,   921,  -174,   841,   924, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,  -170, -1005, -1005, -1005,   -28, -1005,
   -1005, -1005, -1005,    36, -1005,   481, -1005,   120, -1005, -1005,
   -1005,   923,   894,   974,   933,   973,  1001,  1004, -1005,   562,
   -1005,   245,   925,   926,   927,   645, -1005, -1005,   734, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,   928, -1005, -1005
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
       0,    93,    94,    96,    95,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,   566,   567,   568,   565,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   551,
     552,   562,   563,   564,     0,     0,     0,   433,     0,     0,
     431,   432,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   446,   447,   448,   489,   454,
     490,   484,   485,   486,   487,   458,   449,   450,   451,   452,
     453,   455,   456,   457,   459,   460,   488,   464,   465,   466,
     467,   463,   462,   468,   474,   475,   469,   470,   471,   461,
     472,   482,   483,   480,   481,   473,   478,   479,   476,   477,
     491,   492,   493,   494,   495,   496,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,   591,   592,   593,
     594,   595,   596,   598,   597,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    69,    67,    65,    70,
      71,    72,    66,    56,    68,    58,    59,    60,    61,    62,
      63,    64,    57,     0,     0,     0,     0,   125,   126,   127,
       0,     0,   322,     0,     0,   320,   321,     0,    97,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   549,     0,     0,     0,     0,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   211,   212,   215,   217,   218,   219,   220,   221,   222,
     223,   213,   214,   216,   224,   225,   226,     0,     0,     0,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   373,   374,   375,   376,   377,   378,
     379,   380,   382,   381,   384,   388,   385,   386,   387,   383,
     426,     0,     0,     0,   423,   424,   425,     0,     0,   430,
     441,     0,     0,     0,   438,   439,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   445,     0,
       0,     0,   291,     0,     0,     0,     0,     0,     0,   277,
     278,   279,   280,   285,   281,   282,   283,   284,   417,     0,
       0,     0,   414,   415,   416,     0,     0,     0,   250,     0,
     262,     0,   260,   261,   263,   264,    52,    51,    48,    50,
      46,    45,     0,     0,     0,     0,   104,   105,   106,     0,
       0,     0,   175,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   155,   156,   157,   158,   161,   162,   163,   160,
     159,   164,     0,     0,     0,     0,     0,   310,   311,   312,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   589,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,   356,     0,   351,   352,   353,   128,
       0,     0,   124,     0,     0,     0,     0,     0,     0,     0,
     113,   114,   116,   115,   117,     0,     0,   319,     0,     0,
     334,     0,     0,   327,   328,   329,   330,     0,     0,     0,
      91,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     548,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   210,   389,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   372,     0,     0,     0,
     422,     0,   429,     0,     0,     0,   437,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   444,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,     0,
       0,     0,   413,   265,     0,     0,     0,     0,     0,   259,
       0,   107,     0,     0,     0,   103,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   314,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   588,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,   354,     0,     0,     0,   350,     0,   123,
       0,   118,     0,     0,     0,     0,     0,   112,     0,   318,
     331,     0,     0,     0,     0,   326,   100,    99,    98,   586,
      29,    29,    29,    29,    29,    29,    29,    31,    30,   587,
     573,   572,   570,   571,   574,   575,   576,   577,   578,   579,
     580,   583,   584,   581,   582,   585,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
       0,     0,   421,   434,     0,     0,   436,   509,   513,   498,
     499,   526,   542,   543,   544,   545,   546,   547,   502,   540,
     541,   534,   503,   504,   508,   516,   507,   505,   506,   512,
     500,   511,   510,   532,   538,   539,   530,   537,   527,   525,
     528,   533,   529,   531,   518,   524,   523,   519,   520,   521,
     522,   535,   536,   515,   514,   517,   501,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,   412,     0,
       0,     0,   270,   266,   269,   249,    49,     0,     0,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,     0,     0,   308,   604,   601,   602,   603,   608,
     607,   609,   605,   606,    86,    83,    90,    82,    87,    88,
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
   -1005, -1005, -1005,   -41,  -323, -1004,  -665, -1005, -1005, -1005,
   -1005,   -69, -1005, -1005,   747, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,  1077, -1005, -1005, -1005, -1005, -1005,
   -1005,   177, -1005, -1005, -1005, -1005, -1005,   550, -1005, -1005,
   -1005, -1005, -1005, -1005,   922, -1005, -1005, -1005, -1005,   126,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   621, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005,   -81, -1005, -1005, -1005,   829, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,   -58, -1005, -1005, -1005, -1005, -1005,   -65,
   -1005,   652, -1005, -1005, -1005,    30, -1005, -1005, -1005, -1005,
   -1005,   680, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   -59,
   -1005, -1005, -1005, -1005, -1005, -1005,   617, -1005, -1005, -1005,
   -1005, -1005,   929, -1005, -1005, -1005, -1005,   542, -1005, -1005,
   -1005, -1005, -1005,   -79, -1005, -1005, -1005,   575, -1005, -1005,
   -1005, -1005,   -70, -1005, -1005, -1005,   782, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   -51,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   675, -1005,
   -1005, -1005, -1005, -1005,   767, -1005, -1005, -1005, -1005,  1045,
   -1005, -1005, -1005, -1005,   755, -1005, -1005, -1005, -1005,   993,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005,  1075, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,   930, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   857,   858,  1080,  1081,    28,    29,   240,
     518,   519,    30,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    31,    80,    81,    82,    83,    84,    32,    66,
     525,   526,   527,   528,    33,    73,   609,   610,   611,   612,
     613,   614,    34,   306,   307,   308,   309,   310,  1039,  1040,
    1041,  1042,  1043,  1196,  1273,    35,    67,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   779,
    1168,  1169,    36,    55,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   655,  1066,  1067,    37,    63,   510,   766,  1134,  1135,
     511,   512,   513,  1138,   983,   984,   514,   515,    38,    61,
     488,   489,   490,   491,   492,   493,   494,   751,  1118,  1119,
     495,   496,   497,    39,    68,   556,   557,   558,   559,   560,
      40,   314,   315,   316,    41,    75,   622,   623,   624,   625,
     626,   842,  1214,  1215,    42,    71,   595,   596,   597,   598,
     825,  1191,  1192,    43,    56,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   676,  1093,  1094,
     405,   406,   407,   408,   409,    44,    62,   501,   502,   503,
     504,    45,    57,   413,   414,   415,   416,    46,   129,   130,
     131,    47,    59,   423,   424,   425,   426,    48,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      49,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    50,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     890,   891,   633,    76,   552,  1035,  1035,   420,   639,   640,
     641,   498,   643,   644,    53,   604,   592,   312,   304,   410,
     505,   516,  1243,   604,   498,   522,   410,   127,    54,  1217,
     312,    58,   127,  1218,   522,  1064,   552,    60,  1222,  1224,
      64,    77,  1223,  1225,  1091,  1077,  1078,  1079,    78,    65,
    1226,    69,  1238,   889,  1227,   553,  1239,  1240,  1247,   133,
      70,  1241,  1248,   239,   134,   135,    72,   136,   137,   618,
      51,    52,   138,  1219,  1220,  1221,   894,   895,    74,   139,
     140,   141,   142,   143,   144,   124,   506,   553,   304,   145,
     146,   147,   125,   411,   507,   554,   508,   618,   592,   148,
     411,   128,   149,   150,   126,   698,   128,   700,   701,  1065,
     132,   151,   245,   236,   237,   238,   523,   710,    79,   241,
    1036,  1036,   421,   716,   242,   523,   319,   554,   152,   722,
     605,   593,   313,   243,   244,   517,   729,   730,   605,   153,
    1129,   555,   154,   155,   422,   313,   303,   420,   499,   742,
     743,   744,   156,    76,   246,   509,   412,  1130,   311,   157,
     158,   499,   159,   412,   160,   247,   248,   249,   161,   162,
     250,   251,   317,   555,   318,   252,   253,   254,   320,  1131,
     163,   321,   324,   325,   619,   164,   606,   165,   166,   167,
     529,    77,   168,  -130,   606,  1037,  1037,   607,    78,   326,
     524,   327,   627,    85,   328,   607,   608,   329,   530,   524,
     330,   331,   619,   593,   608,   332,   333,   169,   170,  1038,
    1038,   171,   172,   173,   174,   175,   176,   177,   500,  1092,
     594,   322,   793,  1197,   305,   695,    86,    87,   334,   531,
     797,   500,   266,   836,    88,   616,   601,   689,   768,    89,
      90,    91,   761,   774,   377,   418,   378,   335,   379,   178,
     179,   889,   421,  -130,   628,   520,   532,   479,    79,   336,
     180,   181,   380,    92,    93,    94,    95,   267,   344,   182,
     268,   183,   337,   620,   422,   480,   621,   477,    96,    97,
      98,   338,   339,   340,   345,   346,   341,    99,   100,   101,
     417,   102,   103,   381,   305,   533,   347,  1132,   427,   269,
     428,   620,   594,  1133,   621,   429,   481,   521,   430,   270,
     382,   534,   383,   431,   432,   844,   826,  1181,   433,   434,
     384,   878,   435,   436,   881,   437,   883,   438,   439,   440,
     570,   888,   385,   482,   271,   441,   442,   443,   272,   444,
     629,   445,   446,   447,   348,   448,   273,   274,   449,   906,
     275,   276,   850,   851,   852,   853,   854,   855,   856,   386,
     450,   451,   452,   453,   349,   350,   634,   479,   454,   455,
     456,   457,   351,   535,   458,   459,   352,   460,   277,   387,
    1182,   461,   462,   353,   536,   480,   463,   537,   483,   464,
     465,   354,   355,   356,   466,   484,   485,   538,   388,   467,
     468,   539,   357,   469,   470,  1183,   471,   472,   787,  1231,
    1184,   473,   474,   475,   389,  1185,   481,   486,   505,   476,
     561,   342,   635,   358,   562,   563,   564,   565,   566,   567,
    1186,   632,  1187,  1188,   603,   278,   568,   279,   280,   569,
     281,   282,   283,   482,   572,   573,   390,   574,   391,   392,
     575,  1189,   359,   576,   577,   578,   579,   133,   580,  1190,
     590,   599,   134,   135,   581,   136,   137,   582,   583,   584,
     138,   585,   685,   636,   487,   586,   587,   139,   140,   141,
     142,   143,   144,   588,   506,   757,  1109,   145,   146,   147,
     589,   600,   507,   615,   508,   529,   667,   148,   483,   630,
     149,   150,   631,   632,   637,   484,   485,   638,   642,   151,
     645,   646,   647,   530,   648,   649,   652,   650,   651,   697,
    1244,   653,  1110,   654,   656,   657,   152,   486,   658,   659,
     660,   661,   662,   663,   266,   664,   665,   153,   666,   669,
     154,   155,   670,   671,   531,   672,   673,   674,   675,   245,
     156,   677,   678,   509,  1111,   679,  1143,   157,   158,   680,
     159,   681,   160,   682,   683,   684,   161,   162,   687,   267,
     688,   532,   268,   691,   692,   693,   699,   702,   163,  1144,
    1145,   694,   703,   164,   487,   165,   166,   167,  1112,  1113,
     168,   246,  1146,   706,  1114,   704,   705,   707,   708,   709,
     711,   269,   247,   248,   249,   712,   713,   250,   251,   714,
     533,   270,   252,   253,   254,   169,   170,  1115,   715,   171,
     172,   173,   174,   175,   176,   177,   534,   726,   717,   718,
     719,  1147,  1148,   720,  1149,   721,   271,   377,   723,   378,
     272,   379,   724,   725,   728,   727,   731,   732,   273,   274,
     733,   734,   275,   276,   735,   380,   741,   178,   179,   736,
    1150,   737,   738,   739,  1151,   740,   745,   746,   180,   181,
    1116,   747,   749,  1152,   830,   750,   748,   182,   763,   183,
     277,   770,   752,   753,   795,   754,   381,   755,   535,  1136,
     756,   986,   775,  1153,   759,  1154,  1117,  1155,   760,   536,
     764,   771,   537,   382,   765,   383,   767,     2,     3,   772,
     773,     4,   538,   384,  1156,  1265,   539,  1266,   776,   777,
     796,   778,   780,     5,   789,   385,     6,  1157,   781,  1158,
     782,   783,  1159,   784,  1160,     7,   785,   278,  1161,   279,
     280,  1162,   281,   282,   283,     8,   786,  1163,   790,  1164,
    1165,   791,   386,   344,   792,   798,   799,   800,   801,     9,
     802,   803,   804,  1267,    10,    11,   805,   806,  1166,   345,
     346,   807,   387,   808,   822,   811,  1167,   809,   810,   812,
    1268,   347,   823,    12,   828,   813,  1232,    13,   814,   815,
     816,   388,   817,   818,   819,   820,   821,    14,    15,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1204,   389,   824,  1269,
    1270,   829,   832,   831,   897,   838,   833,   834,   835,   839,
      16,    17,   840,   841,   846,   843,   847,   848,   849,   348,
     859,   860,   861,   862,   863,    18,   864,   865,   866,   390,
     867,   391,   392,   868,   869,   870,   871,   872,   873,   349,
     350,   874,    19,  1271,   875,   876,   877,   351,   880,  1272,
     879,   352,   892,   884,    20,    21,   882,   885,   353,  1205,
     886,   887,   889,   893,   896,   898,   354,   355,   356,    85,
      22,   899,   900,   901,   902,   968,   903,   357,    23,   904,
     905,    24,   907,   908,  1206,    25,   909,    26,   910,  1207,
     911,   912,   914,   913,  1208,   915,   916,   969,   358,   917,
     918,   919,    86,    87,   920,   921,   922,   923,   924,  1209,
      88,  1210,  1211,   925,   926,    89,    90,    91,   927,   928,
     929,   930,   931,   932,   933,   967,   934,   359,   935,   936,
    1212,   937,   938,   939,   940,   941,   942,   943,  1213,    92,
      93,    94,    95,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,    96,    97,    98,   955,   956,   957,
     958,   959,   960,    99,   100,   101,   961,   102,   103,   962,
     981,   963,   964,   965,   966,   970,   975,   971,   972,   973,
     974,   976,   977,   991,   979,   978,   980,   985,   982,   987,
     988,   997,   990,   989,   993,   994,   995,   992,   996,   998,
     999,  1032,  1001,  1000,  1002,  1003,  1256,  1051,  1004,  1005,
    1006,   591,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1254,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1033,  1044,
    1034,  1045,  1046,  1047,  1194,  1253,  1048,  1049,  1050,  1052,
    1195,  1245,  1053,  1061,  1062,  1063,  1068,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1095,  1096,  1097,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1127,  1255,  1128,  1257,  1139,
    1140,  1141,  1137,  1142,  1170,  1171,  1172,  1173,  1174,  1175,
    1176,  1177,  1178,  1179,  1180,  1193,  1199,  1200,  1201,  1202,
    1203,  1216,  1228,  1258,  1230,  1233,  1259,  1242,  1234,  1235,
    1236,  1237,  1246,  1262,  1263,  1264,  1275,   323,  1260,   837,
    1249,   788,  1252,   769,   845,  1198,  1251,  1229,   758,  1274,
     827,  1261,  1250,   794,   419,   686,   762,   478,   696,   343,
     690,     0,     0,     0,     0,   571,     0,     0,     0,   668,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   602,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   617
};

static const yytype_int16 yycheck[] =
{
     665,   666,   325,     1,     1,     1,     1,     1,   331,   332,
     333,     1,   335,   336,   233,     1,     1,     1,     1,     1,
       1,    30,   196,     1,     1,     1,     1,     1,   233,   228,
       1,   233,     1,   232,     1,    63,     1,   233,   228,   228,
     226,    39,   232,   232,     8,    11,    12,    13,    46,   230,
     228,   233,   228,   227,   232,    52,   232,   228,   228,     1,
     233,   232,   232,   231,     6,     7,   233,     9,    10,     1,
     228,   229,    14,  1077,  1078,  1079,   178,   179,   233,    21,
      22,    23,    24,    25,    26,   233,    67,    52,     1,    31,
      32,    33,   233,    75,    75,    92,    77,     1,     1,    41,
      75,    75,    44,    45,   233,   428,    75,   430,   431,   137,
     233,    53,     1,   233,   233,   233,    92,   440,   116,   226,
     116,   116,   116,   446,   233,    92,   230,    92,    70,   452,
     116,   116,   116,   233,   233,   144,   459,   460,   116,    81,
      20,   138,    84,    85,   138,   116,   233,     1,   138,   472,
     473,   474,    94,     1,    43,   136,   138,    37,   233,   101,
     102,   138,   104,   138,   106,    54,    55,    56,   110,   111,
      59,    60,   233,   138,   228,    64,    65,    66,   230,    59,
     122,   230,   230,   230,   116,   127,   172,   129,   130,   131,
       1,    39,   134,   176,   172,   191,   191,   183,    46,   230,
     176,   230,   226,     1,   230,   183,   192,   230,    19,   176,
     230,   230,   116,   116,   192,   230,   230,   159,   160,   215,
     215,   163,   164,   165,   166,   167,   168,   169,   218,   193,
     215,   229,   229,   229,   217,   229,    34,    35,   230,    50,
     563,   218,     1,   229,    42,   229,   229,   229,   229,    47,
      48,    49,   229,   229,     1,   229,     3,   230,     5,   201,
     202,   227,   116,   176,   226,   228,    77,     1,   116,   230,
     212,   213,    19,    71,    72,    73,    74,    36,     1,   221,
      39,   223,   230,   215,   138,    19,   218,   229,    86,    87,
      88,   230,   230,   230,    17,    18,   230,    95,    96,    97,
     230,    99,   100,    50,   217,   116,    29,   187,   230,    68,
     230,   215,   215,   193,   218,   230,    50,   228,   230,    78,
      67,   132,    69,   230,   230,   229,   229,    82,   230,   230,
      77,   654,   230,   230,   657,   230,   659,   230,   230,   230,
     229,   664,    89,    77,   103,   230,   230,   230,   107,   230,
     226,   230,   230,   230,    77,   230,   115,   116,   230,   682,
     119,   120,   148,   149,   150,   151,   152,   153,   154,   116,
     230,   230,   230,   230,    97,    98,   200,     1,   230,   230,
     230,   230,   105,   194,   230,   230,   109,   230,   147,   136,
     145,   230,   230,   116,   205,    19,   230,   208,   132,   230,
     230,   124,   125,   126,   230,   139,   140,   218,   155,   230,
     230,   222,   135,   230,   230,   170,   230,   230,   229,   231,
     175,   230,   230,   230,   171,   180,    50,   161,     1,   230,
     230,   229,   200,   156,   230,   230,   230,   230,   230,   230,
     195,   227,   197,   198,   176,   204,   230,   206,   207,   230,
     209,   210,   211,    77,   228,   230,   203,   230,   205,   206,
     230,   216,   185,   230,   230,   230,   230,     1,   230,   224,
     229,   228,     6,     7,   230,     9,    10,   230,   230,   230,
      14,   230,   229,   200,   218,   230,   230,    21,    22,    23,
      24,    25,    26,   230,    67,   229,    15,    31,    32,    33,
     230,   230,    75,   230,    77,     1,   229,    41,   132,   228,
      44,    45,   227,   227,   200,   139,   140,   227,   227,    53,
     227,   227,   227,    19,   227,   227,   230,   228,   228,   200,
    1195,   230,    51,   230,   230,   230,    70,   161,   230,   230,
     230,   230,   230,   230,     1,   230,   230,    81,   230,   228,
      84,    85,   230,   230,    50,   230,   230,   230,   230,     1,
      94,   230,   230,   136,    83,   230,     4,   101,   102,   230,
     104,   230,   106,   230,   230,   230,   110,   111,   230,    36,
     230,    77,    39,   226,   228,   230,   227,   200,   122,    27,
      28,   230,   227,   127,   218,   129,   130,   131,   117,   118,
     134,    43,    40,   226,   123,   227,   227,   226,   200,   227,
     200,    68,    54,    55,    56,   227,   227,    59,    60,   200,
     116,    78,    64,    65,    66,   159,   160,   146,   200,   163,
     164,   165,   166,   167,   168,   169,   132,   200,   227,   227,
     227,    79,    80,   227,    82,   227,   103,     1,   227,     3,
     107,     5,   227,   227,   200,   226,   200,   200,   115,   116,
     227,   200,   119,   120,   200,    19,   227,   201,   202,   200,
     108,   200,   200,   200,   112,   200,   200,   227,   212,   213,
     199,   228,   230,   121,   233,   230,   228,   221,   228,   223,
     147,   232,   230,   230,   200,   230,    50,   230,   194,   214,
     230,   770,   525,   141,   230,   143,   225,   145,   230,   205,
     230,   228,   208,    67,   230,    69,   230,     0,     1,   230,
     230,     4,   218,    77,   162,    80,   222,    82,   228,   230,
     200,   230,   230,    16,   228,    89,    19,   175,   230,   177,
     230,   230,   180,   230,   182,    28,   230,   204,   186,   206,
     207,   189,   209,   210,   211,    38,   230,   195,   230,   197,
     198,   230,   116,     1,   230,   226,   200,   226,   200,    52,
     200,   200,   228,   128,    57,    58,   227,   226,   216,    17,
      18,   200,   136,   226,   228,   226,   224,   227,   227,   226,
     145,    29,   228,    76,   200,   226,   231,    80,   226,   226,
     226,   155,   226,   226,   226,   226,   226,    90,    91,   850,
     851,   852,   853,   854,   855,   856,    82,   171,   230,   174,
     175,   228,   230,   228,   200,   226,   230,   230,   230,   228,
     113,   114,   228,   230,   228,   230,   228,   228,   228,    77,
     228,   228,   228,   228,   228,   128,   228,   228,   228,   203,
     228,   205,   206,   228,   228,   228,   228,   228,   228,    97,
      98,   228,   145,   218,   228,   227,   227,   105,   227,   224,
     230,   109,   228,   226,   157,   158,   227,   227,   116,   145,
     227,   227,   227,   226,   226,   226,   124,   125,   126,     1,
     173,   226,   230,   226,   226,   200,   227,   135,   181,   226,
     226,   184,   226,   226,   170,   188,   228,   190,   226,   175,
     226,   228,   226,   228,   180,   226,   228,   230,   156,   228,
     228,   228,    34,    35,   228,   228,   228,   228,   228,   195,
      42,   197,   198,   228,   228,    47,    48,    49,   228,   228,
     228,   228,   228,   228,   228,   226,   228,   185,   228,   228,
     216,   228,   228,   228,   228,   228,   228,   228,   224,    71,
      72,    73,    74,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,    86,    87,    88,   228,   228,   228,
     228,   228,   228,    95,    96,    97,   228,    99,   100,   228,
     230,   228,   228,   228,   228,   226,   228,   227,   226,   226,
     226,   226,   226,   200,   226,   228,   226,   228,   227,   226,
     226,   200,   226,   228,   226,   226,   226,   230,   226,   226,
     226,   230,   226,   228,   226,   226,    93,   230,   228,   228,
     228,   284,   228,   228,   228,   228,   228,   228,   228,   145,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   226,   228,   226,
     228,   226,   226,   226,   230,   142,   228,   228,   226,   226,
     230,   230,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   142,   228,   145,   228,
     228,   228,   232,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   227,   142,   228,   231,   142,   226,   231,   231,
     231,   231,   228,   228,   228,   228,   228,    80,  1239,   609,
    1218,   540,  1227,   511,   622,  1039,  1225,  1137,   488,  1248,
     595,  1241,  1223,   556,   129,   393,   501,   184,   423,   104,
     413,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   314
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   235,     0,     1,     4,    16,    19,    28,    38,    52,
      57,    58,    76,    80,    90,    91,   113,   114,   128,   145,
     157,   158,   173,   181,   184,   188,   190,   236,   241,   242,
     246,   266,   272,   278,   286,   299,   316,   338,   352,   367,
     374,   378,   388,   397,   419,   425,   431,   435,   441,   494,
     515,   228,   229,   233,   233,   317,   398,   426,   233,   436,
     233,   353,   420,   339,   226,   230,   273,   300,   368,   233,
     233,   389,   233,   279,   233,   379,     1,    39,    46,   116,
     267,   268,   269,   270,   271,     1,    34,    35,    42,    47,
      48,    49,    71,    72,    73,    74,    86,    87,    88,    95,
      96,    97,    99,   100,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   233,   233,   233,     1,    75,   432,
     433,   434,   233,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    44,
      45,    53,    70,    81,    84,    85,    94,   101,   102,   104,
     106,   110,   111,   122,   127,   129,   130,   131,   134,   159,
     160,   163,   164,   165,   166,   167,   168,   169,   201,   202,
     212,   213,   221,   223,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   233,   233,   233,   231,
     243,   226,   233,   233,   233,     1,    43,    54,    55,    56,
      59,    60,    64,    65,    66,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,     1,    36,    39,    68,
      78,   103,   107,   115,   116,   119,   120,   147,   204,   206,
     207,   209,   210,   211,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   233,     1,   217,   287,   288,   289,   290,
     291,   233,     1,   116,   375,   376,   377,   233,   228,   230,
     230,   230,   229,   268,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   229,   496,     1,    17,    18,    29,    77,    97,
      98,   105,   109,   116,   124,   125,   126,   135,   156,   185,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,     1,     3,     5,
      19,    50,    67,    69,    77,    89,   116,   136,   155,   171,
     203,   205,   206,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   414,   415,   416,   417,   418,
       1,    75,   138,   427,   428,   429,   430,   230,   229,   433,
       1,   116,   138,   437,   438,   439,   440,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   229,   443,     1,
      19,    50,    77,   132,   139,   140,   161,   218,   354,   355,
     356,   357,   358,   359,   360,   364,   365,   366,     1,   138,
     218,   421,   422,   423,   424,     1,    67,    75,    77,   136,
     340,   344,   345,   346,   350,   351,    30,   144,   244,   245,
     228,   228,     1,    92,   176,   274,   275,   276,   277,     1,
      19,    50,    77,   116,   132,   194,   205,   208,   218,   222,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,     1,    52,    92,   138,   369,   370,   371,   372,
     373,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     229,   517,   228,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     229,   248,     1,   116,   215,   390,   391,   392,   393,   228,
     230,   229,   288,   176,     1,   116,   172,   183,   192,   280,
     281,   282,   283,   284,   285,   230,   229,   376,     1,   116,
     215,   218,   380,   381,   382,   383,   384,   226,   226,   226,
     228,   227,   227,   238,   200,   200,   200,   200,   227,   238,
     238,   238,   227,   238,   238,   227,   227,   227,   227,   227,
     228,   228,   230,   230,   230,   335,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   229,   319,   228,
     230,   230,   230,   230,   230,   230,   411,   230,   230,   230,
     230,   230,   230,   230,   230,   229,   400,   230,   230,   229,
     428,   226,   228,   230,   230,   229,   438,   200,   238,   227,
     238,   238,   200,   227,   227,   227,   226,   226,   200,   227,
     238,   200,   227,   227,   200,   200,   238,   227,   227,   227,
     227,   227,   238,   227,   227,   227,   200,   226,   200,   238,
     238,   200,   200,   227,   200,   200,   200,   200,   200,   200,
     200,   227,   238,   238,   238,   200,   227,   228,   228,   230,
     230,   361,   230,   230,   230,   230,   230,   229,   355,   230,
     230,   229,   422,   228,   230,   230,   341,   230,   229,   345,
     232,   228,   230,   230,   229,   275,   228,   230,   230,   313,
     230,   230,   230,   230,   230,   230,   230,   229,   302,   228,
     230,   230,   230,   229,   370,   200,   200,   238,   226,   200,
     226,   200,   200,   200,   228,   227,   226,   200,   226,   227,
     227,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   228,   228,   230,   394,   229,   391,   200,   228,
     233,   228,   230,   230,   230,   230,   229,   281,   226,   228,
     228,   230,   385,   230,   229,   381,   228,   228,   228,   228,
     148,   149,   150,   151,   152,   153,   154,   237,   238,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   227,   227,   238,   230,
     227,   238,   227,   238,   226,   227,   227,   227,   238,   227,
     240,   240,   228,   226,   178,   179,   226,   200,   226,   226,
     230,   226,   226,   227,   226,   226,   238,   226,   226,   228,
     226,   226,   228,   228,   226,   226,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   226,   200,   230,
     226,   227,   226,   226,   226,   228,   226,   226,   228,   226,
     226,   230,   227,   348,   349,   228,   245,   226,   226,   228,
     226,   200,   230,   226,   226,   226,   226,   200,   226,   226,
     228,   226,   226,   226,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   226,   230,   228,   228,     1,   116,   191,   215,   292,
     293,   294,   295,   296,   226,   226,   226,   226,   228,   228,
     226,   230,   226,   228,   237,   237,   237,   237,   237,   237,
     237,   228,   228,   228,    63,   137,   336,   337,   228,   228,
     228,   228,   228,   228,   228,   228,   228,    11,    12,    13,
     239,   240,   228,   228,   228,   228,   228,   228,   228,   228,
     228,     8,   193,   412,   413,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,    15,
      51,    83,   117,   118,   123,   146,   199,   225,   362,   363,
     228,   228,   228,   228,   228,   228,   228,   228,   228,    20,
      37,    59,   187,   193,   342,   343,   214,   232,   347,   228,
     228,   228,   228,     4,    27,    28,    40,    79,    80,    82,
     108,   112,   121,   141,   143,   145,   162,   175,   177,   180,
     182,   186,   189,   195,   197,   198,   216,   224,   314,   315,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,    82,   145,   170,   175,   180,   195,   197,   198,   216,
     224,   395,   396,   228,   230,   230,   297,   229,   293,   228,
     228,   228,   228,   228,    82,   145,   170,   175,   180,   195,
     197,   198,   216,   224,   386,   387,   228,   228,   232,   239,
     239,   239,   228,   232,   228,   232,   228,   232,   227,   349,
     228,   231,   231,   231,   231,   231,   231,   231,   228,   232,
     228,   232,   226,   196,   240,   230,   228,   228,   232,   337,
     413,   363,   343,   142,   145,   142,    93,   145,   142,   142,
     315,   396,   228,   228,   228,    80,    82,   128,   145,   174,
     175,   218,   224,   298,   387,   228
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   234,   235,   235,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   237,
     237,   238,   238,   238,   238,   238,   238,   238,   238,   239,
     239,   240,   240,   240,   240,   241,   242,   243,   243,   244,
     244,   245,   245,   246,   247,   247,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   267,   268,   268,   268,   268,   269,   270,
     271,   273,   272,   274,   274,   275,   275,   275,   276,   277,
     279,   278,   280,   280,   281,   281,   281,   281,   281,   282,
     283,   284,   285,   286,   287,   287,   288,   288,   288,   289,
     291,   290,   292,   292,   293,   293,   293,   293,   294,   295,
     295,   297,   296,   298,   298,   298,   298,   298,   298,   298,
     298,   300,   299,   301,   301,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   313,   312,   314,   314,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   317,   316,
     318,   318,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   335,   334,   336,   336,   337,   337,   339,   338,
     341,   340,   342,   342,   343,   343,   343,   343,   343,   344,
     344,   345,   345,   345,   345,   345,   347,   346,   348,   348,
     349,   349,   350,   351,   353,   352,   354,   354,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   356,   357,   358,
     359,   361,   360,   362,   362,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   364,   365,   366,   368,   367,   369,
     369,   370,   370,   370,   370,   371,   372,   373,   374,   375,
     375,   376,   376,   377,   379,   378,   380,   380,   381,   381,
     381,   381,   382,   383,   385,   384,   386,   386,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   389,   388,
     390,   390,   391,   391,   391,   392,   394,   393,   395,   395,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     398,   397,   399,   399,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   409,
     411,   410,   412,   412,   413,   413,   414,   415,   416,   417,
     418,   420,   419,   421,   421,   422,   422,   422,   423,   424,
     426,   425,   427,   427,   428,   428,   428,   429,   430,   431,
     432,   432,   433,   433,   434,   436,   435,   437,   437,   438,
     438,   438,   439,   440,   441,   442,   442,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     495,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     516,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 397 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3220 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3226 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3232 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3238 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3244 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3250 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3256 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3262 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3268 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 408 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3274 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 409 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3280 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 410 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3286 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 411 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3292 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3298 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 420 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3307 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 430 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3316 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 436 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3324 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 443 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3333 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 447 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3342 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 480 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3354 "conf_parser.c"
    break;

  case 75: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 489 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3366 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 498 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3378 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 507 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3390 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 516 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3402 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 525 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3414 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 534 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3426 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 543 "conf_parser.y"
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
#line 3444 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 558 "conf_parser.y"
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
#line 3462 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 573 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3475 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 583 "conf_parser.y"
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
#line 3492 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 597 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3504 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 606 "conf_parser.y"
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
#line 3530 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 629 "conf_parser.y"
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
#line 3556 "conf_parser.c"
    break;

  case 88: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 652 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 80)
  {
    conf_error_report("max_topic_length too low, setting to 80");
    ConfigServerInfo.max_topic_length = 80;
  }
  else if ((yyvsp[-1].number) > TOPICLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3582 "conf_parser.c"
    break;

  case 89: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 675 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3594 "conf_parser.c"
    break;

  case 90: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3603 "conf_parser.c"
    break;

  case 98: /* admin_name: NAME '=' QSTRING ';'  */
#line 702 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3615 "conf_parser.c"
    break;

  case 99: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 711 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3627 "conf_parser.c"
    break;

  case 100: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 720 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3639 "conf_parser.c"
    break;

  case 101: /* $@1: %empty  */
#line 733 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3648 "conf_parser.c"
    break;

  case 102: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 737 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3665 "conf_parser.c"
    break;

  case 108: /* motd_mask: MASK '=' QSTRING ';'  */
#line 754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3674 "conf_parser.c"
    break;

  case 109: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 760 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3683 "conf_parser.c"
    break;

  case 110: /* $@2: %empty  */
#line 770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3692 "conf_parser.c"
    break;

  case 111: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 774 "conf_parser.y"
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
#line 3710 "conf_parser.c"
    break;

  case 119: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3719 "conf_parser.c"
    break;

  case 120: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 798 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3728 "conf_parser.c"
    break;

  case 121: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 804 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3737 "conf_parser.c"
    break;

  case 122: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 810 "conf_parser.y"
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
#line 3759 "conf_parser.c"
    break;

  case 129: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 839 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3768 "conf_parser.c"
    break;

  case 130: /* $@3: %empty  */
#line 845 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3777 "conf_parser.c"
    break;

  case 131: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 849 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3790 "conf_parser.c"
    break;

  case 138: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 865 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3801 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 873 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3809 "conf_parser.c"
    break;

  case 140: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 876 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3817 "conf_parser.c"
    break;

  case 141: /* $@4: %empty  */
#line 881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3826 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: USER  */
#line 887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3835 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: OPERATOR  */
#line 891 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3844 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: XLINE  */
#line 895 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3853 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: RESV  */
#line 899 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3862 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DLINE  */
#line 903 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3871 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KLINE  */
#line 907 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3880 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: KILL  */
#line 911 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3889 "conf_parser.c"
    break;

  case 150: /* logging_file_type_item: T_DEBUG  */
#line 915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3898 "conf_parser.c"
    break;

  case 151: /* $@5: %empty  */
#line 925 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3910 "conf_parser.c"
    break;

  case 152: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 932 "conf_parser.y"
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
    conf->htype = parse_netmask(conf->host, conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);
  }
}
#line 3972 "conf_parser.c"
    break;

  case 166: /* oper_name: NAME '=' QSTRING ';'  */
#line 1004 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3981 "conf_parser.c"
    break;

  case 167: /* oper_user: USER '=' QSTRING ';'  */
#line 1010 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3990 "conf_parser.c"
    break;

  case 168: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1016 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3999 "conf_parser.c"
    break;

  case 169: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1022 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4008 "conf_parser.c"
    break;

  case 170: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1028 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4022 "conf_parser.c"
    break;

  case 171: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1039 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4031 "conf_parser.c"
    break;

  case 172: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4045 "conf_parser.c"
    break;

  case 173: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1056 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4054 "conf_parser.c"
    break;

  case 174: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1062 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4063 "conf_parser.c"
    break;

  case 175: /* $@6: %empty  */
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4072 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL ':' REMOTE  */
#line 1075 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4081 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: KILL  */
#line 1079 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4090 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1083 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4099 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: CONNECT  */
#line 1087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4108 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1091 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4117 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: SQUIT  */
#line 1095 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4126 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: KLINE  */
#line 1099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4135 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: UNKLINE  */
#line 1103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4144 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_DLINE  */
#line 1107 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4153 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_UNDLINE  */
#line 1111 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4162 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: XLINE  */
#line 1115 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4171 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_UNXLINE  */
#line 1119 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4180 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: DIE  */
#line 1123 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4189 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_RESTART  */
#line 1127 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4198 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4207 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: REHASH  */
#line 1135 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4216 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: ADMIN  */
#line 1139 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4225 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_GLOBOPS  */
#line 1143 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4234 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: T_LOCOPS  */
#line 1147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4243 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: REMOTEBAN  */
#line 1151 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4252 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: T_SET  */
#line 1155 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4261 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: MODULE  */
#line 1159 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4270 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: T_OPME  */
#line 1163 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4279 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: NICK ':' RESV  */
#line 1167 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4288 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: JOIN ':' RESV  */
#line 1171 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4297 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: RESV  */
#line 1175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4306 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: T_UNRESV  */
#line 1179 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4315 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: CLOSE  */
#line 1183 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4324 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1187 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4333 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1197 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4349 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1208 "conf_parser.y"
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
#line 4397 "conf_parser.c"
    break;

  case 228: /* class_name: NAME '=' QSTRING ';'  */
#line 1271 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4406 "conf_parser.c"
    break;

  case 229: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1277 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4415 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1283 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4424 "conf_parser.c"
    break;

  case 231: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1289 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4433 "conf_parser.c"
    break;

  case 232: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1295 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4442 "conf_parser.c"
    break;

  case 233: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1301 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4451 "conf_parser.c"
    break;

  case 234: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1307 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4460 "conf_parser.c"
    break;

  case 235: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1313 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4469 "conf_parser.c"
    break;

  case 236: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1319 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4479 "conf_parser.c"
    break;

  case 237: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1326 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4488 "conf_parser.c"
    break;

  case 238: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1332 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4497 "conf_parser.c"
    break;

  case 239: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1338 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4506 "conf_parser.c"
    break;

  case 240: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1344 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4518 "conf_parser.c"
    break;

  case 241: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1353 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4530 "conf_parser.c"
    break;

  case 242: /* $@8: %empty  */
#line 1362 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4539 "conf_parser.c"
    break;

  case 246: /* class_flags_item: RANDOM_IDLE  */
#line 1369 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4548 "conf_parser.c"
    break;

  case 247: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1373 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4557 "conf_parser.c"
    break;

  case 248: /* $@9: %empty  */
#line 1383 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4566 "conf_parser.c"
    break;

  case 250: /* $@10: %empty  */
#line 1389 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4574 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_TLS  */
#line 1395 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4583 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: HIDDEN  */
#line 1399 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4592 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: T_SERVER  */
#line 1403 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4601 "conf_parser.c"
    break;

  case 257: /* listen_flags_item: CLIENT  */
#line 1407 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4610 "conf_parser.c"
    break;

  case 258: /* listen_flags_item: DEFER  */
#line 1411 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4619 "conf_parser.c"
    break;

  case 266: /* $@11: %empty  */
#line 1419 "conf_parser.y"
                                 { reset_block_state(); }
#line 4625 "conf_parser.c"
    break;

  case 270: /* port_item: NUMBER  */
#line 1424 "conf_parser.y"
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
#line 4643 "conf_parser.c"
    break;

  case 271: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1437 "conf_parser.y"
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
#line 4663 "conf_parser.c"
    break;

  case 272: /* listen_address: IP '=' QSTRING ';'  */
#line 1454 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4672 "conf_parser.c"
    break;

  case 273: /* listen_host: HOST '=' QSTRING ';'  */
#line 1460 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4681 "conf_parser.c"
    break;

  case 274: /* $@12: %empty  */
#line 1470 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4690 "conf_parser.c"
    break;

  case 275: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1474 "conf_parser.y"
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
#line 4737 "conf_parser.c"
    break;

  case 287: /* auth_user: USER '=' QSTRING ';'  */
#line 1529 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4746 "conf_parser.c"
    break;

  case 288: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1535 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4755 "conf_parser.c"
    break;

  case 289: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1541 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4764 "conf_parser.c"
    break;

  case 290: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1547 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4778 "conf_parser.c"
    break;

  case 291: /* $@13: %empty  */
#line 1558 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4787 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: EXCEED_LIMIT  */
#line 1565 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4796 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: KLINE_EXEMPT  */
#line 1569 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4805 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: XLINE_EXEMPT  */
#line 1573 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4814 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: NEED_IDENT  */
#line 1577 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4823 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: CAN_FLOOD  */
#line 1581 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4832 "conf_parser.c"
    break;

  case 300: /* auth_flags_item: NO_TILDE  */
#line 1585 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4841 "conf_parser.c"
    break;

  case 301: /* auth_flags_item: RESV_EXEMPT  */
#line 1589 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4850 "conf_parser.c"
    break;

  case 302: /* auth_flags_item: T_WEBIRC  */
#line 1593 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4859 "conf_parser.c"
    break;

  case 303: /* auth_flags_item: NEED_PASSWORD  */
#line 1597 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4868 "conf_parser.c"
    break;

  case 304: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1603 "conf_parser.y"
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
#line 4885 "conf_parser.c"
    break;

  case 305: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1617 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4897 "conf_parser.c"
    break;

  case 306: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1626 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4909 "conf_parser.c"
    break;

  case 307: /* $@14: %empty  */
#line 1639 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4921 "conf_parser.c"
    break;

  case 308: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1646 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4932 "conf_parser.c"
    break;

  case 315: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1657 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4941 "conf_parser.c"
    break;

  case 316: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1663 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4950 "conf_parser.c"
    break;

  case 317: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4959 "conf_parser.c"
    break;

  case 323: /* service_name: NAME '=' QSTRING ';'  */
#line 1684 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 4974 "conf_parser.c"
    break;

  case 324: /* $@15: %empty  */
#line 1700 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4990 "conf_parser.c"
    break;

  case 325: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1711 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5005 "conf_parser.c"
    break;

  case 332: /* shared_name: NAME '=' QSTRING ';'  */
#line 1726 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5014 "conf_parser.c"
    break;

  case 333: /* shared_user: USER '=' QSTRING ';'  */
#line 1732 "conf_parser.y"
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
#line 5036 "conf_parser.c"
    break;

  case 334: /* $@16: %empty  */
#line 1751 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5045 "conf_parser.c"
    break;

  case 338: /* shared_type_item: KLINE  */
#line 1758 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5054 "conf_parser.c"
    break;

  case 339: /* shared_type_item: UNKLINE  */
#line 1762 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5063 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_DLINE  */
#line 1766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5072 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_UNDLINE  */
#line 1770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5081 "conf_parser.c"
    break;

  case 342: /* shared_type_item: XLINE  */
#line 1774 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5090 "conf_parser.c"
    break;

  case 343: /* shared_type_item: T_UNXLINE  */
#line 1778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5099 "conf_parser.c"
    break;

  case 344: /* shared_type_item: RESV  */
#line 1782 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5108 "conf_parser.c"
    break;

  case 345: /* shared_type_item: T_UNRESV  */
#line 1786 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5117 "conf_parser.c"
    break;

  case 346: /* shared_type_item: T_LOCOPS  */
#line 1790 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5126 "conf_parser.c"
    break;

  case 347: /* shared_type_item: T_ALL  */
#line 1794 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5135 "conf_parser.c"
    break;

  case 348: /* $@17: %empty  */
#line 1804 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5149 "conf_parser.c"
    break;

  case 349: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1813 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5162 "conf_parser.c"
    break;

  case 355: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1826 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5171 "conf_parser.c"
    break;

  case 356: /* $@18: %empty  */
#line 1832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5180 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: KLINE  */
#line 1839 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5189 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: UNKLINE  */
#line 1843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5198 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_DLINE  */
#line 1847 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5207 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_UNDLINE  */
#line 1851 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5216 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: XLINE  */
#line 1855 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5225 "conf_parser.c"
    break;

  case 365: /* cluster_type_item: T_UNXLINE  */
#line 1859 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5234 "conf_parser.c"
    break;

  case 366: /* cluster_type_item: RESV  */
#line 1863 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5243 "conf_parser.c"
    break;

  case 367: /* cluster_type_item: T_UNRESV  */
#line 1867 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5252 "conf_parser.c"
    break;

  case 368: /* cluster_type_item: T_LOCOPS  */
#line 1871 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5261 "conf_parser.c"
    break;

  case 369: /* cluster_type_item: T_ALL  */
#line 1875 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5270 "conf_parser.c"
    break;

  case 370: /* $@19: %empty  */
#line 1885 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5285 "conf_parser.c"
    break;

  case 371: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1895 "conf_parser.y"
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
#line 5356 "conf_parser.c"
    break;

  case 390: /* connect_name: NAME '=' QSTRING ';'  */
#line 1981 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5365 "conf_parser.c"
    break;

  case 391: /* connect_host: HOST '=' QSTRING ';'  */
#line 1987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5374 "conf_parser.c"
    break;

  case 392: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5383 "conf_parser.c"
    break;

  case 393: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5392 "conf_parser.c"
    break;

  case 394: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2005 "conf_parser.y"
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
#line 5408 "conf_parser.c"
    break;

  case 395: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2018 "conf_parser.y"
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
#line 5424 "conf_parser.c"
    break;

  case 396: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2031 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5433 "conf_parser.c"
    break;

  case 397: /* connect_port: PORT '=' NUMBER ';'  */
#line 2037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5442 "conf_parser.c"
    break;

  case 398: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2043 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5451 "conf_parser.c"
    break;

  case 399: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2047 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5460 "conf_parser.c"
    break;

  case 400: /* $@20: %empty  */
#line 2053 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5468 "conf_parser.c"
    break;

  case 404: /* connect_flags_item: AUTOCONN  */
#line 2059 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5477 "conf_parser.c"
    break;

  case 405: /* connect_flags_item: T_TLS  */
#line 2063 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5486 "conf_parser.c"
    break;

  case 406: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5500 "conf_parser.c"
    break;

  case 407: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5509 "conf_parser.c"
    break;

  case 408: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2086 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5518 "conf_parser.c"
    break;

  case 409: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5527 "conf_parser.c"
    break;

  case 410: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2098 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5541 "conf_parser.c"
    break;

  case 411: /* $@21: %empty  */
#line 2113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5550 "conf_parser.c"
    break;

  case 412: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2117 "conf_parser.y"
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
#line 5573 "conf_parser.c"
    break;

  case 418: /* kill_user: USER '=' QSTRING ';'  */
#line 2140 "conf_parser.y"
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
#line 5596 "conf_parser.c"
    break;

  case 419: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2160 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5605 "conf_parser.c"
    break;

  case 420: /* $@22: %empty  */
#line 2170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5614 "conf_parser.c"
    break;

  case 421: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2174 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
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
#line 5638 "conf_parser.c"
    break;

  case 427: /* deny_ip: IP '=' QSTRING ';'  */
#line 2198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5647 "conf_parser.c"
    break;

  case 428: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2204 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5656 "conf_parser.c"
    break;

  case 434: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2219 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (*yylval.string && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = io_strdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5673 "conf_parser.c"
    break;

  case 435: /* $@23: %empty  */
#line 2236 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5682 "conf_parser.c"
    break;

  case 436: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2240 "conf_parser.y"
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
#line 5702 "conf_parser.c"
    break;

  case 442: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5711 "conf_parser.c"
    break;

  case 443: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5720 "conf_parser.c"
    break;

  case 498: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2332 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5728 "conf_parser.c"
    break;

  case 499: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2337 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5736 "conf_parser.c"
    break;

  case 500: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2342 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5744 "conf_parser.c"
    break;

  case 501: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2347 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5752 "conf_parser.c"
    break;

  case 502: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2352 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5760 "conf_parser.c"
    break;

  case 503: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2357 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5768 "conf_parser.c"
    break;

  case 504: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2362 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5776 "conf_parser.c"
    break;

  case 505: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2367 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5784 "conf_parser.c"
    break;

  case 506: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2372 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5792 "conf_parser.c"
    break;

  case 507: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2377 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5800 "conf_parser.c"
    break;

  case 508: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2382 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5808 "conf_parser.c"
    break;

  case 509: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2387 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5816 "conf_parser.c"
    break;

  case 510: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2392 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5824 "conf_parser.c"
    break;

  case 511: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2397 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5832 "conf_parser.c"
    break;

  case 512: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2402 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5840 "conf_parser.c"
    break;

  case 513: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2407 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5848 "conf_parser.c"
    break;

  case 514: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2412 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5856 "conf_parser.c"
    break;

  case 515: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2417 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5864 "conf_parser.c"
    break;

  case 516: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2422 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5872 "conf_parser.c"
    break;

  case 517: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2427 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5880 "conf_parser.c"
    break;

  case 518: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2432 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5888 "conf_parser.c"
    break;

  case 519: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2437 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5896 "conf_parser.c"
    break;

  case 520: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2442 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5904 "conf_parser.c"
    break;

  case 521: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2447 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5912 "conf_parser.c"
    break;

  case 522: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2452 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5920 "conf_parser.c"
    break;

  case 523: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2457 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5928 "conf_parser.c"
    break;

  case 524: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2462 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5936 "conf_parser.c"
    break;

  case 525: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2467 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5944 "conf_parser.c"
    break;

  case 526: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2472 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5952 "conf_parser.c"
    break;

  case 527: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2477 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5960 "conf_parser.c"
    break;

  case 528: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2482 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5968 "conf_parser.c"
    break;

  case 529: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2487 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5976 "conf_parser.c"
    break;

  case 530: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2492 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5984 "conf_parser.c"
    break;

  case 531: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2497 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 5992 "conf_parser.c"
    break;

  case 532: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2502 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6000 "conf_parser.c"
    break;

  case 533: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2507 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6008 "conf_parser.c"
    break;

  case 534: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2512 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6016 "conf_parser.c"
    break;

  case 535: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2517 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6024 "conf_parser.c"
    break;

  case 536: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2522 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6032 "conf_parser.c"
    break;

  case 537: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2527 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6044 "conf_parser.c"
    break;

  case 538: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2536 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6052 "conf_parser.c"
    break;

  case 539: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2541 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6060 "conf_parser.c"
    break;

  case 540: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2546 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6068 "conf_parser.c"
    break;

  case 541: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2551 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6076 "conf_parser.c"
    break;

  case 542: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2556 "conf_parser.y"
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
#line 6096 "conf_parser.c"
    break;

  case 543: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2573 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6107 "conf_parser.c"
    break;

  case 544: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2581 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6118 "conf_parser.c"
    break;

  case 545: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2589 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6129 "conf_parser.c"
    break;

  case 546: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2597 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6142 "conf_parser.c"
    break;

  case 547: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2607 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6155 "conf_parser.c"
    break;

  case 570: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2643 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6163 "conf_parser.c"
    break;

  case 571: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2648 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6172 "conf_parser.c"
    break;

  case 572: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2654 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6181 "conf_parser.c"
    break;

  case 573: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2660 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6189 "conf_parser.c"
    break;

  case 574: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2665 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6197 "conf_parser.c"
    break;

  case 575: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2670 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6205 "conf_parser.c"
    break;

  case 576: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2675 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6213 "conf_parser.c"
    break;

  case 577: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2680 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6221 "conf_parser.c"
    break;

  case 578: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2685 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6229 "conf_parser.c"
    break;

  case 579: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2690 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6237 "conf_parser.c"
    break;

  case 580: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2695 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6245 "conf_parser.c"
    break;

  case 581: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2700 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6253 "conf_parser.c"
    break;

  case 582: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2705 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6261 "conf_parser.c"
    break;

  case 583: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2710 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6269 "conf_parser.c"
    break;

  case 584: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2715 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6277 "conf_parser.c"
    break;

  case 585: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2720 "conf_parser.y"
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
#line 6303 "conf_parser.c"
    break;

  case 586: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2743 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6311 "conf_parser.c"
    break;

  case 587: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2748 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6319 "conf_parser.c"
    break;

  case 601: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6328 "conf_parser.c"
    break;

  case 602: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2777 "conf_parser.y"
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
#line 6347 "conf_parser.c"
    break;

  case 603: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2793 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6359 "conf_parser.c"
    break;

  case 604: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2802 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6368 "conf_parser.c"
    break;

  case 605: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2808 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6377 "conf_parser.c"
    break;

  case 606: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2814 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6386 "conf_parser.c"
    break;

  case 607: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2820 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6398 "conf_parser.c"
    break;

  case 608: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2829 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6407 "conf_parser.c"
    break;

  case 609: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 2835 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6416 "conf_parser.c"
    break;


#line 6420 "conf_parser.c"

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

