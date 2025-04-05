# Development Notes for IRCd Hybrid

This document provides detailed information for developers working on the IRCd Hybrid codebase, focusing on the XML configuration system.

## XML Configuration System

IRCd Hybrid uses an XML-based configuration format with a schema defined in `etc/ircd.xsd`. The configuration parser is implemented in `src/conf_xml.c`.

### XML Schema (`etc/ircd.xsd`)

The XML schema defines the structure and validation rules for the configuration file. Key aspects include:

1. **Namespace**: The schema uses the namespace `http://www.ultra-ircd.org/ircd`.

2. **Custom Types**:
   - `timeSpec`: For time specifications (e.g., "30 seconds", "5 minutes", "2 hours")
   - `sizeSpec`: For size specifications (e.g., "10 megabytes", "5 kilobytes")
   - `yesNo`: Boolean type that accepts "yes" or "no" as values

3. **Element Structure**: The schema defines various elements for different configuration sections:
   - `module_base_path`: Configuration for module loading
   - `serverinfo`: Server information and limits
   - `admin`: Administrator contact information
   - `class`: Connection class definitions
   - `channel`: Channel-related configuration
   - `serverhide`: Server hiding options
   - `log`: Logging configuration
   - And many more...

4. **Validation Rules**: The schema enforces validation rules for attributes and elements, ensuring that the configuration file is valid.

5. **Build Integration**: The schema is exported by CMake during the build process using the `xxd` utility, which converts the XML schema into a C header file. This allows the schema to be embedded directly in the binary, eliminating the need for external schema files at runtime. The generated header is included in the build and referenced in `src/conf_xml.c`.

### Configuration Parser (`src/conf_xml.c`)

The configuration parser is responsible for loading, validating, and parsing the XML configuration file. Key components include:

1. **Initialization**:
   - `conf_xml_init()`: Initializes the XML parser and loads the schema
   - The schema is embedded in the binary during build time
   - Sets up error handlers and validation options

2. **Parsing**:
   - `conf_xml_parse()`: Parses the configuration file and validates it against the schema
   - Uses `xmlSchemaValidateDoc()` to validate the XML document
   - Calls `parse_xml_config()` to process the validated document

3. **Error Handling**:
   - `handle_xml_validation_error()`: Handles validation errors and provides detailed error information
   - Logs error details including line and column numbers
   - Dumps the XML document for debugging purposes

4. **Configuration Generation**:
   - `conf_generate_default()`: Generates a default configuration file
   - Uses helper functions like `write_xml_header()`, `write_serverinfo()`, etc. to generate different sections

5. **Validation Options**:
   - Uses `XML_SCHEMA_VAL_VC_I_CREATE` to stop validation after the first error
   - Sets up structured error handlers for better error reporting

## Working with the Configuration System

### Adding New Configuration Options

To add a new configuration option:

1. **Update the Schema**:
   - Add the new attribute or element to the appropriate section in `etc/ircd.xsd`
   - Define validation rules for the new option
   - The schema will be automatically converted to a C header during the next build

2. **Update the Parser**:
   - Add parsing logic in the appropriate function in `src/conf_xml.c`
   - Update the configuration generation code if needed

3. **Update Documentation**:
   - Document the new option in the README or other documentation

### Debugging Configuration Issues

When debugging configuration issues:

1. **Enable Debug Logging**:
   - Set the log level to DEBUG to see detailed validation information
   - Look for validation errors in the log output

2. **Check Schema Validation**:
   - The parser will log detailed validation errors
   - Pay attention to line and column numbers in the error messages

3. **Use the `-g` Option**:
   - Generate a default configuration file using `ircd -g > ircd.xml`
   - Use this as a reference for the correct format

## Common Issues

1. **Schema Validation Errors**:
   - Ensure that all attributes and elements match the schema definition
   - Check for typos in attribute names
   - Verify that attribute values are within the allowed ranges

2. **Missing Required Attributes**:
   - The schema defines required attributes for some elements
   - Ensure all required attributes are present in the configuration

3. **Type Mismatches**:
   - Ensure that attribute values match the expected types
   - For example, use "yes" or "no" for boolean attributes

## Best Practices

1. **Keep the Schema Updated**:
   - Update the schema whenever adding new configuration options
   - Ensure that the schema accurately reflects the supported configuration

2. **Validate Early**:
   - Validate the configuration file before starting the server
   - Use the `-g` option to generate a valid default configuration

3. **Document Changes**:
   - Document any changes to the configuration format
   - Update the example configuration in the README 