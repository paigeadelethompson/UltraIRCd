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
 * @file log.h
 * @brief Defines the logging system for ircd-hybrid.
 *
 * This file contains declarations and documentation for the logging
 * system used in the ircd-hybrid Internet Relay Chat Daemon. It includes
 * constants, structures, and functions related to logging messages,
 * log file rotation, and managing log entries.
 */

#ifndef INCLUDED_log_h
#define INCLUDED_log_h

#include "io.h"
#include "list.h"

/**
 * @enum log_type
 * @brief Enumerates different log types for classifying log entries.
 */
enum log_type
{
  LOG_TYPE_IRCD,  /**< IRC daemon-related log entries (main log). */
  LOG_TYPE_KILL,  /**< Log entries related to KILL events. */
  LOG_TYPE_KLINE,  /**< Log entries related to KLINE events. */
  LOG_TYPE_DLINE,  /**< Log entries related to DLINE events. */
  LOG_TYPE_XLINE,  /**< Log entries related to XLINE events. */
  LOG_TYPE_RESV,  /**< Log entries related to RESV events. */
  LOG_TYPE_OPER,  /**< Log entries related to operator actions. */
  LOG_TYPE_USER,  /**< Log entries related to general user actions. */
  LOG_TYPE_DEBUG,  /**< Log entries for debugging information. */
};

/**
 * @brief Enumeration of log severity levels.
 */
enum log_severity
{
  LOG_SEVERITY_DEBUG,     /**< Debug messages */
  LOG_SEVERITY_INFO,      /**< Informational messages */
  LOG_SEVERITY_NOTICE,    /**< Notice messages */
  LOG_SEVERITY_WARN,      /**< Warning messages */
  LOG_SEVERITY_ERROR,     /**< Error messages */
  LOG_SEVERITY_CRITICAL,  /**< Critical messages */
};

/**
 * @brief Structure representing a log configuration.
 */
struct Log
{
  enum log_type type;           /**< Type of log */
  enum log_severity severity;   /**< Severity level for log entries */
  bool main;                    /**< Whether this is the main log */
  char *file_name;             /**< Name of the log file */
  FILE *file;                  /**< File pointer for the log */
  size_t max_file_size;        /**< Maximum size of the log file */
  bool flush_immediately;      /**< Whether to flush after each write */
  const char *(*time_provider)(uintmax_t); /**< Function to provide timestamp */
};

extern void log_destroy(struct Log *);
extern void log_clear(void);
extern void log_write(enum log_type, enum log_severity, const char *, ...) IO_AFP(3,4);
extern struct Log *log_add(enum log_type, enum log_severity, bool, size_t, const char *);
#endif  /* INCLUDED_log_h */
