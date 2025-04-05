# Read the XML file
file(READ "${CMAKE_SOURCE_DIR}/etc/ircd.xsd" SCHEMA_CONTENT)

# Escape special characters
string(REGEX REPLACE "\\\\+" "\\\\\\\\" SCHEMA_CONTENT "${SCHEMA_CONTENT}")  # Escape backslashes
string(REGEX REPLACE "\"" "\\\\\"" SCHEMA_CONTENT "${SCHEMA_CONTENT}")       # Escape quotes
string(REGEX REPLACE "\n" "\\\\n\"\n\"" SCHEMA_CONTENT "${SCHEMA_CONTENT}")  # Handle newlines

# Write the escaped content
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/conf_schema.c" "${SCHEMA_CONTENT}") 