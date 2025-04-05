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
 * @file ircd.c
 * @brief Starts up and runs the ircd.
 *
 * This file contains the main entry point and functionality for starting up
 * and running the ircd (Internet Relay Chat Daemon). It initializes various
 * components, sets up event handlers, and manages server configurations.
 */

#include <jansson.h>
#include "stdinc.h"
#include "io_getopt.h"
#include "io_pidfile.h"
#include "io_rlimit.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "module.h"
#include "event.h"
#include "fdlist.h"
#include "comm.h"
#include "res.h"
#include "rng_mt.h"
#include "defaults.h"
#include "user.h"
#include "ircd.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "cloak.h"
#include "hash.h"
#include "id.h"
#include "motd.h"
#include "conf.h"
#include "parse.h"
#include "server.h"
#include "server_capab.h"
#include "send.h"
#include "conf_db.h"
#include "conf_class.h"
#include "ipcache.h"
#include "extban.h"
#include "ircd_exit.h"
#include "ircd_hook.h"
#include "flatten_links.h"
#include <getopt.h>
#include "misc.h"
#include <signal.h>

/**
 * @struct SetOptions
 * @brief Structure for server configuration options.
 *
 * The `SetOptions` structure holds various options related to server configuration,
 * allowing modification through the SET irc command. It includes flags and settings
 * for features such as auto connection, maximum clients, and flood control.
 */
struct SetOptions GlobalSetOptions;

/**
 * @struct Counter
 * @brief Structure holding various server activity counters.
 *
 * The `Counter` structure tracks various server activity metrics, including total
 * client connections, IRC operator count, invisible clients, and peak client counts.
 */
struct Counter Count;

/**
 * @var bool debug_mode
 * @brief Flag indicating whether debug mode is enabled.
 */
static bool debug_mode = false;

/**
 * @var bool foreground_mode
 * @brief Flag indicating whether the server should run in foreground mode.
 */
static bool foreground_mode = true;

/**
 * @var bool dorehash
 * @brief Flag indicating whether configuration rehashing is needed.
 */
static bool dorehash = false;

/**
 * @var bool doremotd
 * @brief Flag indicating whether MOTD reloading is needed.
 */
static bool doremotd = false;

/**
 * @var bool generate_config
 * @brief Flag indicating whether configuration generation is needed.
 */
static bool generate_config = false;

/**
 * @struct ServerStatistics
 * @brief Structure for server communication and connection statistics.
 *
 * The `ServerStatistics` structure contains statistics related to server communication
 * and connections. These metrics provide insights into data transmission, connection
 * durations, and various activities between clients and servers.
 */
struct ServerStatistics ServerStats;

/**
 * @struct Connection
 * @brief Structure representing the connection details for this server.
 *
 * The `Connection` structure encapsulates the connection details for the server,
 * including information such as connection status, socket details, and connection settings.
 */
static struct Connection meConnection;

/**
 * @struct Client
 * @brief Structure representing the client details for this server.
 *
 * The `Client` structure represents the client details for the server, with a connection
 * link pointing to the associated `Connection` structure. This structure provides a
 * comprehensive view of the client's attributes within the context of the server.
 */
struct Client me = { .connection = &meConnection };

/**
 * @var char **myargv
 * @brief Pointer to the command line arguments.
 */
char **myargv;

/**
 * @var const char *logFileName
 * @brief Pointer to the filename for the ircd.log file.
 */
const char *logFileName = LPATH;

/**
 * @var const char *pidFileName
 * @brief Pointer to the filename for the process ID file.
 */
const char *pidFileName = PPATH;

/**
 * @brief Display usage information for the program.
 *
 * Displays the program's usage information, including valid options and their descriptions.
 *
 * @param name The name of the program.
 */
static void
print_usage(const char *name)
{
  fprintf(stderr, "Usage: %s [options]\n", name);
  fprintf(stderr, "Where valid options are:\n");
  fprintf(stderr, "  -c, --configfile FILE    File to use for ircd.conf\n");
  fprintf(stderr, "  -k, --klinefile FILE     File to use for kline database\n");
  fprintf(stderr, "  -d, --dlinefile FILE     File to use for dline database\n");
  fprintf(stderr, "  -x, --xlinefile FILE     File to use for xline database\n");
  fprintf(stderr, "  -r, --resvfile FILE      File to use for resv database\n");
  fprintf(stderr, "  -l, --logfile FILE       File to use for ircd.log\n");
  fprintf(stderr, "  -p, --pidfile FILE       File to use for process ID\n");
  fprintf(stderr, "  -f, --fork               Run in background (fork)\n");
  fprintf(stderr, "  -v, --version            Print version and exit\n");
  fprintf(stderr, "  -g, --generate-config    Generate a new configuration file to stdout\n");
  fprintf(stderr, "  -D, --debug              Enable debug logging\n");
  fprintf(stderr, "  -h, --help               Print this text\n");
}

static struct event event_cleanup_tklines =
{
  .name = "cleanup_tklines",
  .handler = cleanup_tklines,
  .when = 30
};

static struct event event_server_connect_auto =
{
  .name = "server_connect_auto",
  .handler = server_connect_auto,
  .when = 15
};

static struct event event_comm_checktimeouts =
{
  .name = "comm_checktimeouts",
  .handler = comm_checktimeouts,
  .when = 1
};

static struct event event_save_all_databases =
{
  .name = "save_all_databases",
  .handler = save_all_databases,
  .when = 300
};

/**
 * @brief Main IO loop for processing events and managing server activities.
 *
 * This function runs continuously, handling various tasks such as
 * processing events, checking for rehash signals, and managing client connections.
 */
static void
io_loop(void)
{
  while (true)
  {
    if (listing_client_list.head)
    {
      list_node_t *node, *node_next;
      LIST_FOREACH_SAFE(node, node_next, listing_client_list.head)
        safe_list_channels(node->data, false);
    }

    /* Run pending events */
    event_run();

    comm_select();
    exit_aborted_clients();
    free_exited_clients();

    /* Check to see whether we have to rehash the configuration. */
    if (dorehash)
    {
      conf_rehash(true);
      dorehash = 0;
    }

    if (doremotd)
    {
      motd_recache();
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Got signal SIGUSR1, reloading motd file(s)");
      doremotd = 0;
    }
  }
}

/**
 * @brief Initializes global server configuration options.
 *
 * This function sets default values for various global server configuration options
 * needed during runtime. It is responsible for initializing the `GlobalSetOptions`
 * structure, which holds key settings that can be modified using the SET irc command.
 */
static void
initialize_global_set_options(void)
{
  GlobalSetOptions.maxclients = ConfigServerInfo.default_max_clients;
  GlobalSetOptions.autoconnect = true;
  GlobalSetOptions.spam_time = MIN_JOIN_LEAVE_TIME;
  GlobalSetOptions.spam_num = MAX_JOIN_LEAVE_COUNT;
  GlobalSetOptions.floodcount = ConfigGeneral.default_floodcount;
  GlobalSetOptions.floodtime = ConfigGeneral.default_floodtime;
  GlobalSetOptions.joinfloodcount = ConfigChannel.default_join_flood_count;
  GlobalSetOptions.joinfloodtime = ConfigChannel.default_join_flood_time;
}

/**
 * @brief Prints startup information including version and process ID.
 *
 * This function prints information about the server version, process ID,
 * and whether it is running in the background or foreground.
 *
 * @param pid Process ID of the ircd server.
 */
static void
print_startup(int pid)
{
  char cwd[PATH_MAX];
  
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    strlcpy(cwd, "unknown", sizeof(cwd));
  }
  
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "ircd: version %s", IRCD_VERSION);
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "ircd: pid %d", pid);
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "ircd: running in %s mode from %s",
           foreground_mode ? "foreground" : "background", cwd);
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "ircd: started at %s", date_iso8601_usec(0));
}

/**
 * @brief Transforms the current process into a daemon for background execution.
 *
 * This function creates a child process using fork(), allowing the parent process
 * to exit. The child becomes a daemon by detaching from the terminal and setting
 * up a new session using setsid(). Standard input, output, and error are redirected
 * to /dev/null to isolate the daemon from the terminal.
 */
static void
make_daemon(void)
{
  int pid = fork();
  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid > 0)
  {
    print_startup(pid);
    exit(EXIT_SUCCESS);
  }

  if (setsid() == -1)
  {
    perror("setsid");
    exit(EXIT_FAILURE);
  }

  /* Connect stdin, stdout, and stderr to /dev/null */
  int fd = open("/dev/null", O_RDWR);
  if (fd == -1)
  {
    perror("open");
    exit(EXIT_FAILURE);
  }

  dup2(fd, STDIN_FILENO);
  dup2(fd, STDOUT_FILENO);
  dup2(fd, STDERR_FILENO);

  if (fd > STDERR_FILENO)
    close(fd);
}

/**
 * @brief Main function to initialize and run the IRC server.
 *
 * This is the main entry point for the ircd server. It initializes various
 * components, sets up signal handling, reads configuration files, and runs
 * the main IO loop to handle server activities.
 *
 * @param argc Number of command line arguments.
 * @param argv Array of command line argument strings.
 * @return Returns 0 upon successful execution.
 */
int
main(int argc, char *argv[])
{
  int opt;

  /* Parse command line options */
  while ((opt = getopt(argc, argv, "c:d:f:gh:l:p:r:v:x:D")) != -1)
  {
    switch (opt)
    {
      case 'c':
        ConfigGeneral.configfile = io_strdup(optarg);
        break;
      case 'd':
        ConfigGeneral.dpath = io_strdup(optarg);
        break;
      case 'x':
        ConfigGeneral.xlinefile = io_strdup(optarg);
        break;
      case 'r':
        ConfigGeneral.resvfile = io_strdup(optarg);
        break;
      case 'l':
        logFileName = io_strdup(optarg);
        break;
      case 'p':
        pidFileName = io_strdup(optarg);
        break;
      case 'f':
        foreground_mode = false;  /* -f means run in background */
        break;
      case 'v':
        log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "ircd: version %s", IRCD_VERSION);
        exit(EXIT_SUCCESS);
      case 'g':
        generate_config = true;
        break;
      case 'D':
        debug_mode = true;  /* Enable debug logging */
        break;
      case 'h':
        print_usage(argv[0]);
        exit(EXIT_SUCCESS);
      default:
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  /* Initialize logging based on debug flag */
  if (debug_mode)
  {
    log_add(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, true, 0, "stderr");
    log_add(LOG_TYPE_KILL, LOG_SEVERITY_DEBUG, false, 0, "stderr");
    log_add(LOG_TYPE_KLINE, LOG_SEVERITY_DEBUG, false, 0, "stderr");
    log_add(LOG_TYPE_DLINE, LOG_SEVERITY_DEBUG, false, 0, "stderr");
    log_add(LOG_TYPE_XLINE, LOG_SEVERITY_DEBUG, false, 0, "stderr");
    log_add(LOG_TYPE_RESV, LOG_SEVERITY_DEBUG, false, 0, "stderr");
    log_add(LOG_TYPE_OPER, LOG_SEVERITY_DEBUG, false, 0, "stderr");
    log_add(LOG_TYPE_USER, LOG_SEVERITY_DEBUG, false, 0, "stderr");
  }
  else
  {
    log_add(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, true, 0, "stderr");
    log_add(LOG_TYPE_KILL, LOG_SEVERITY_INFO, false, 0, "stderr");
    log_add(LOG_TYPE_KLINE, LOG_SEVERITY_INFO, false, 0, "stderr");
    log_add(LOG_TYPE_DLINE, LOG_SEVERITY_INFO, false, 0, "stderr");
    log_add(LOG_TYPE_XLINE, LOG_SEVERITY_INFO, false, 0, "stderr");
    log_add(LOG_TYPE_RESV, LOG_SEVERITY_INFO, false, 0, "stderr");
    log_add(LOG_TYPE_OPER, LOG_SEVERITY_INFO, false, 0, "stderr");
    log_add(LOG_TYPE_USER, LOG_SEVERITY_INFO, false, 0, "stderr");
  }

  /* Change to the working directory */
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "ircd: unable to get current working directory: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  ConfigGeneral.dpath = io_strdup(cwd);
  
  /* Initialize the configuration */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Initializing configuration...");
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Configuration file path: %s", ConfigGeneral.configfile);
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Data directory: %s", ConfigGeneral.dpath);
  
   /* Generate default config to stdout and exit */
  if (generate_config)
  {
    if (conf_generate_default(NULL))
    {
      exit(EXIT_SUCCESS);
    }
    else
    {
      log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to generate configuration file to stdout.");
      exit(EXIT_FAILURE);
    }
  }

  if (!foreground_mode)
    make_daemon();
  else
    print_startup(getpid());

  /* We need this to initialise the fd array before anything else */
  fdlist_init();
  
  /* Initialize cloak configuration before loading config */
  cloak_init();

  /* Check if configuration file exists */
  FILE *config_file = fopen(ConfigGeneral.configfile, "r");
  if (config_file == NULL) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Configuration file not found: %s", ConfigGeneral.configfile);
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Error: %s", strerror(errno));
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Exiting due to missing configuration file");
    exit(EXIT_FAILURE);
  }

  /* Check if we can read the configuration file */
  char test_buffer[1];
  if (fread(test_buffer, 1, 1, config_file) != 1 && !feof(config_file)) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Cannot read configuration file: %s", ConfigGeneral.configfile);
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Error: %s", strerror(errno));
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Exiting due to unreadable configuration file");
    fclose(config_file);
    exit(EXIT_FAILURE);
  }
  fclose(config_file);
  
  conf_set_defaults();
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Reading configuration files...");
  
  /* Read configuration files */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Attempting to read configuration file...");
  conf_read_files(true);  /* true for cold start */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Configuration file read attempt completed");
  
  /* Add debug logging to see if we get past this point */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "DEBUG: Checking server name after config read");
  
  /* Check if configuration was loaded successfully by verifying required fields */
  if (string_is_empty(ConfigServerInfo.name)) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to read configuration files");
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Please check your configuration file: %s", ConfigGeneral.configfile);
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Make sure the file exists and is readable");
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Exiting due to configuration error");
    exit(EXIT_FAILURE);
  }
  
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "DEBUG: Server name check passed");
  
  /* Check other critical configuration fields */
  if (string_is_empty(ConfigServerInfo.description)) {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "No server description specified in serverinfo block");
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Exiting due to missing server description");
    exit(EXIT_FAILURE);
  }
  
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_DEBUG, "DEBUG: Server description check passed");
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Configuration loaded successfully");

  /* Check if there is pidfile and daemon already running */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Creating PID file...");
  if (io_pidfile_create(pidFileName))
  {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_ERROR, "Failed to create PID file. Is another instance running?");
    exit(EXIT_FAILURE);
  }

  /* Initialize all subsystems */
  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Initializing subsystems...");

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Communication subsystem");
  comm_select_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- TLS");
  tls_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Hooks");
  ircd_hook_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- IP cache");
  ipcache_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Client subsystem");
  client_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Class subsystem");
  class_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Cloak subsystem");
  cloak_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Resolver");
  resolver_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Modules");
  module_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Channel modes");
  channel_mode_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Extended bans");
  extban_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Server capabilities");
  capab_init();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Global options");
  initialize_global_set_options();

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "- Link flattening");
  flatten_links_init();

  /* Check required configuration */
  if (!ConfigServerInfo.name)
  {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_CRITICAL, "No server name specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.name, ConfigServerInfo.name, sizeof(me.name));

  if (string_is_empty(ConfigServerInfo.description))
  {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_CRITICAL, "No server description specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Using fixed server ID");
  strlcpy(ConfigServerInfo.sid, "10X", sizeof(ConfigServerInfo.sid));
  strlcpy(me.id, ConfigServerInfo.sid, sizeof(me.id));

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Initializing UID system...");
  init_uid();

  me.from = &me;
  me.servptr = &me;
  me.connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);
  me.connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Setting up server identity...");
  SetMe(&me);
  server_make(&me);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Adding server to hash tables...");
  hash_add_id(&me);
  hash_add_client(&me);

  list_add(&me, &me.node, &global_server_list);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Loading databases...");
  load_kline_database(ConfigGeneral.klinefile);
  load_dline_database(ConfigGeneral.dlinefile);
  load_xline_database(ConfigGeneral.xlinefile);
  load_resv_database(ConfigGeneral.resvfile);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Loading all modules...");
  module_load_all(NULL);

  log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Setting up events...");
  event_addish(&event_cleanup_tklines, NULL);
  event_addish(&event_server_connect_auto, NULL);
  event_add(&event_comm_checktimeouts, NULL);
  event_addish(&event_save_all_databases, NULL);

  /* Only switch to configured logging if we have a valid configuration */
  if (foreground_mode)
  {
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Server ready. Running version: %s", IRCD_VERSION);
    log_write(LOG_TYPE_IRCD, LOG_SEVERITY_INFO, "Entering main event loop...");
  }

 
  io_loop();

  return 0;
}
