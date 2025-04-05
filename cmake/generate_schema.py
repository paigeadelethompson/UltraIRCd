#!/usr/bin/env python3

import sys

def escape_for_c_string(s):
    return s.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n')

def main():
    if len(sys.argv) != 3:
        print("Usage: generate_schema.py <input_xsd> <output_c>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    with open(input_file, 'r') as f:
        content = f.read()

    escaped_content = escape_for_c_string(content)

    with open(output_file, 'w') as f:
        f.write('#include "conf_schema.h"\n\n')
        f.write('const char *const ircd_schema_xml = "')
        f.write(escaped_content)
        f.write('";\n')

if __name__ == '__main__':
    main() 