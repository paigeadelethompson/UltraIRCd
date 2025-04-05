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

/*! \file conf_xml.h
 * \brief XML configuration file parser using libxml2.
 */

#ifndef INCLUDED_conf_xml_h
#define INCLUDED_conf_xml_h

#include "stdinc.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlschemas.h>

/* Error codes for XML parsing */
enum xml_error_code {
  XML_PARSE_SUCCESS = 0,
  XML_PARSE_ERROR_SCHEMA_INVALID = -1,
  XML_PARSE_ERROR_FILE_NOT_FOUND = -2,
  XML_PARSE_ERROR_PARSE_FAILED = -3,
  XML_PARSE_ERROR_VALIDATION_FAILED = -4
};

/* Function declarations */
extern int conf_xml_init(void);
extern void conf_xml_cleanup(void);
extern int conf_xml_parse(const char *filename, bool cold);
extern const char *conf_xml_error_str(int error_code);

#endif /* INCLUDED_conf_xml_h */ 