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

#line 530 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
