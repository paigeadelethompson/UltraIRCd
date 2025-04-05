#!/usr/bin/env python3
"""
XSD Documentation Generator

This script parses an XML Schema (XSD) file and generates Markdown documentation
from the annotations and element/attribute definitions in the schema.
"""

import os
import sys
import argparse
from lxml import etree


# XSD namespace
XSD_NS = "http://www.w3.org/2001/XMLSchema"


def extract_documentation(element):
    """Extract documentation from an element's annotation."""
    annotation = element.find(f"{{{XSD_NS}}}annotation")
    if annotation is not None:
        documentation = annotation.find(f"{{{XSD_NS}}}documentation")
        if documentation is not None and documentation.text:
            return documentation.text.strip()
    return None


def get_element_type(element):
    """Get the type of an element (simple or complex)."""
    if element.find(f"{{{XSD_NS}}}complexType") is not None:
        return "complex"
    elif element.find(f"{{{XSD_NS}}}simpleType") is not None:
        return "simple"
    return "unknown"


def get_attribute_info(complex_type):
    """Extract information about attributes in a complex type."""
    attributes = []
    for attribute in complex_type.findall(f".//{{{XSD_NS}}}attribute"):
        name = attribute.get("name")
        attr_type = attribute.get("type")
        use = attribute.get("use", "optional")
        default = attribute.get("default")
        
        # Handle simple types with restrictions
        if (attr_type is None and 
                attribute.find(f"{{{XSD_NS}}}simpleType") is not None):
            simple_type = attribute.find(f"{{{XSD_NS}}}simpleType")
            restriction = simple_type.find(f"{{{XSD_NS}}}restriction")
            if restriction is not None:
                base = restriction.get("base")
                if base:
                    attr_type = base.split(":")[-1]
        
        # Handle enumerations
        enum_values = []
        if attribute.find(f".//{{{XSD_NS}}}enumeration") is not None:
            for enum in attribute.findall(f".//{{{XSD_NS}}}enumeration"):
                enum_values.append(enum.get("value"))
        
        attributes.append({
            "name": name,
            "type": attr_type,
            "use": use,
            "default": default,
            "enum_values": enum_values
        })
    
    return attributes


def get_simple_type_info(simple_type):
    """Extract information about a simple type."""
    name = simple_type.get("name")
    restriction = simple_type.find(f"{{{XSD_NS}}}restriction")
    
    if restriction is not None:
        base = restriction.get("base")
        if base:
            base = base.split(":")[-1]
        
        # Get pattern if it exists
        pattern = None
        pattern_elem = restriction.find(f"{{{XSD_NS}}}pattern")
        if pattern_elem is not None:
            pattern = pattern_elem.get("value")
        
        # Get enumerations if they exist
        enum_values = []
        for enum in restriction.findall(f"{{{XSD_NS}}}enumeration"):
            enum_values.append(enum.get("value"))
        
        return {
            "name": name,
            "base": base,
            "pattern": pattern,
            "enum_values": enum_values
        }
    
    return {"name": name}


def generate_markdown(xsd_file, output_file):
    """Generate Markdown documentation from an XSD file."""
    try:
        tree = etree.parse(xsd_file)
        root = tree.getroot()
        
        # Extract schema documentation
        schema_doc = extract_documentation(root)
        
        # Find all simple types
        simple_types = {}
        for simple_type in root.findall(f".//{{{XSD_NS}}}simpleType"):
            info = get_simple_type_info(simple_type)
            simple_types[info["name"]] = info
        
        # Find all elements
        elements = {}
        for element in root.findall(f".//{{{XSD_NS}}}element"):
            name = element.get("name")
            if name:
                doc = extract_documentation(element)
                elem_type = get_element_type(element)
                
                attributes = []
                if elem_type == "complex":
                    complex_type = element.find(f"{{{XSD_NS}}}complexType")
                    if complex_type is not None:
                        attributes = get_attribute_info(complex_type)
                
                elements[name] = {
                    "name": name,
                    "documentation": doc,
                    "type": elem_type,
                    "attributes": attributes
                }
        
        # Generate Markdown
        with open(output_file, 'w') as f:
            f.write("# Ultra-IRCd Configuration Schema Documentation\n\n")
            
            if schema_doc:
                f.write(f"{schema_doc}\n\n")
            
            # Document simple types
            f.write("## Simple Types\n\n")
            for name, info in sorted(simple_types.items()):
                f.write(f"### {name}\n\n")
                
                if "base" in info:
                    f.write(f"**Base type:** {info['base']}\n\n")
                
                if "pattern" in info and info["pattern"]:
                    f.write(f"**Pattern:** `{info['pattern']}`\n\n")
                
                if "enum_values" in info and info["enum_values"]:
                    f.write("**Allowed values:**\n")
                    for value in info["enum_values"]:
                        f.write(f"- `{value}`\n")
                    f.write("\n")
                
                # Get documentation for this type
                for simple_type in root.findall(
                        f".//{{{XSD_NS}}}simpleType[@name='{name}']"):
                    doc = extract_documentation(simple_type)
                    if doc:
                        f.write(f"{doc}\n\n")
            
            # Document elements
            f.write("## Elements\n\n")
            for name, info in sorted(elements.items()):
                f.write(f"### {name}\n\n")
                
                if info["documentation"]:
                    f.write(f"{info['documentation']}\n\n")
                
                if info["attributes"]:
                    f.write("#### Attributes\n\n")
                    f.write(
                        "| Name | Type | Required | Default | Description |\n"
                    )
                    f.write(
                        "|------|------|----------|---------|-------------|\n"
                    )
                    
                    for attr in info["attributes"]:
                        required = "Yes" if attr["use"] == "required" else "No"
                        default = attr["default"] or ""
                        
                        # Get documentation for this attribute
                        attr_doc = ""
                        for element in root.findall(
                                f".//{{{XSD_NS}}}element[@name='{name}']"):
                            complex_type = element.find(f"{{{XSD_NS}}}complexType")
                            if complex_type is not None:
                                for attribute in complex_type.findall(
                                        f".//{{{XSD_NS}}}attribute[@name='{attr['name']}']"):
                                    doc = extract_documentation(attribute)
                                    if doc:
                                        attr_doc = doc
                        
                        # Handle enumerations
                        if attr["enum_values"]:
                            attr_type = (
                                f"{attr['type']} (enum: "
                                f"{', '.join(attr['enum_values'])})"
                            )
                        else:
                            attr_type = attr["type"] or ""
                        
                        f.write(
                            f"| {attr['name']} | {attr_type} | {required} | "
                            f"{default} | {attr_doc} |\n"
                        )
                    
                    f.write("\n")
        
        print(f"Documentation generated successfully: {output_file}")
        return 0
    
    except Exception as e:
        print(f"Error generating documentation: {e}", file=sys.stderr)
        return 1


def main():
    parser = argparse.ArgumentParser(
        description="Generate documentation from an XSD file")
    parser.add_argument("xsd_file", help="Path to the XSD file")
    parser.add_argument(
        "--output", "-o",
        help="Output file path (default: docs/xsd_documentation.md)")
    
    args = parser.parse_args()
    
    if not os.path.exists(args.xsd_file):
        print(f"Error: XSD file not found: {args.xsd_file}", file=sys.stderr)
        return 1
    
    output_file = args.output or "docs/xsd_documentation.md"
    
    # Create output directory if it doesn't exist
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    
    return generate_markdown(args.xsd_file, output_file)


if __name__ == "__main__":
    sys.exit(main()) 