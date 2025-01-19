/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 526 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
