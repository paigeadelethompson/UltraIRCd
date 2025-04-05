# Building ircd-hybrid

This document provides information about building ircd-hybrid, including the compiler options that are enabled by default.

## Default Compiler Options

ircd-hybrid uses several compiler options to ensure security, performance, and compatibility. Here's a summary of the key options:

### Security Options

- `-D_FORTIFY_SOURCE=3`: Enables buffer overflow checks in standard library functions.
- `-fstack-protector-strong`: Adds stack protection against buffer overflows.
- `-fstack-clash-protection`: Protects against stack clash attacks.
- `-fcf-protection=branch`: Adds control flow protection for branches.
- `-fcf-protection=full`: Adds comprehensive control flow protection.
- `-fno-common`: Prevents global variables from being placed in the common section.
- `-fno-ident`: Removes compiler identification information from the binary.
- `-fno-stack-check`: Disables stack checking (redundant with other protections).
- `-fno-strict-aliasing`: Disables strict aliasing rules for better compatibility.
- `-fno-builtin`: Prevents the compiler from replacing functions with built-in versions.
- `-fno-omit-frame-pointer`: Keeps frame pointers for better debugging.
- `-fno-optimize-sibling-calls`: Prevents optimization of sibling calls for better stack traces.
- `-fsanitize=leak`: Enables memory leak detection.
- `-fsanitize=undefined`: Detects undefined behavior.

### Position Independent Code

- `-fPIC`: Generates position-independent code for shared libraries.
- `-fvisibility=default`: Makes symbols visible by default (for shared libraries).

### Warning and Error Options

- `-Wall`: Enables all common warning messages.
- `-Werror`: Treats all warnings as errors.
- `-Wextra`: Enables additional warnings not covered by `-Wall`.
- `-Wno-unused-parameter`: Suppresses warnings about unused parameters.
- `-Wno-format-truncation`: Suppresses warnings about format string truncation.
- `-Wformat-security`: Warns about format strings that might represent security problems.
- `-Wformat=2`: Enables additional format string warnings.

### Optimization and Debugging

- `-g`: Includes debugging information.
- `-O0`: Disables optimization for better debugging.
- `-fwrapv`: Makes signed integer overflow wrap around.
- `-fno-optimize-sibling-calls`: Prevents optimization of sibling calls for better stack traces.

### Linker Options

- `-Wl,-z,noexecstack`: Marks the stack as non-executable.
- `-Wl,-z,separate-code`: Creates separate code and data segments.
- `-Wl,-z,defs`: Reports unresolved references.
- `-Wl,-z,text`: Makes the text section read-only.
- `-Wl,-z,nodlopen`: Prevents the library from being opened with dlopen.
- `-Wl,-z,nodump`: Prevents the library from being dumped.
- `-pie`: Creates a position-independent executable.
- `-Wl,-z,relro`: Makes the global offset table read-only after relocation.
- `-Wl,-z,now`: Resolves all dynamic symbols at load time.

## Exceptions and Special Cases

Due to the complexity of the codebase and the interaction between the shared library and modules, some exceptions to the default compiler options are necessary:

### Shared Library Symbol Visibility

- **Default**: `-fvisibility=hidden` (symbols are hidden by default)
- **Exception**: `-fvisibility=default` (symbols are visible by default)
- **Reason**: The modules need to access symbols from the shared library. When using `-fvisibility=hidden`, the symbols are not exported, causing linking errors. Setting `-fvisibility=default` ensures that all symbols are exported and available to the modules.

### Position Independent Code

- **Default**: Position-independent code is not enabled by default
- **Exception**: `-fPIC` is explicitly enabled for both the shared library and modules
- **Reason**: Shared libraries and modules that are loaded at runtime must be compiled with position-independent code to ensure they can be loaded at any memory address.

### C++-Specific Flags

- **Default**: Some C++-specific flags were initially included
- **Exception**: Removed `-fvisibility-inlines-hidden` and `VISIBILITY_INLINES_HIDDEN`
- **Reason**: These flags are specific to C++ and not applicable to C code, causing compilation errors.

### Module Dependencies

- **Default**: Modules link against the shared library using imported targets
- **Exception**: Modules now use `${LIBXML2_LIBRARIES}` and `${JANSSON_LIBRARIES}` instead of `LibXml2::LibXml2` and `jansson::jansson`
- **Reason**: The imported targets were not found, causing linking errors. Using the variables directly ensures proper linking.

## Security Optics

ircd-hybrid implements a comprehensive set of security measures, but like any complex software, it has both strengths and weaknesses. This section provides an overview of the security posture of ircd-hybrid.

### Security Strengths

1. **Compile-Time Protections**:
   - Stack protection mechanisms (`-fstack-protector-strong`, `-fstack-clash-protection`)
   - Control flow integrity (`-fcf-protection=branch`, `-fcf-protection=full`)
   - Buffer overflow detection (`-D_FORTIFY_SOURCE=3`)
   - Undefined behavior detection (`-fsanitize=undefined`)
   - Memory leak detection (`-fsanitize=leak`)

2. **Runtime Protections**:
   - Non-executable stack (`-Wl,-z,noexecstack`)
   - Read-only text segments (`-Wl,-z,text`)
   - Position-independent executable (`-pie`)
   - Relocation read-only (`-Wl,-z,relro`)
   - Immediate symbol resolution (`-Wl,-z,now`)

3. **Code Quality**:
   - Strict warning enforcement (`-Wall`, `-Wextra`, `-Werror`)
   - Format string security checks (`-Wformat-security`, `-Wformat=2`)
   - Integer overflow protection (`-fwrapv`)

4. **Module System**:
   - Dynamic loading of modules with controlled interfaces
   - Separation of core functionality from extensions
   - Ability to disable potentially dangerous modules

### Security Weaknesses

1. **Legacy Code**:
   - Some parts of the codebase date back to the early days of IRC
   - Legacy code may contain patterns that are less secure by modern standards
   - Historical compatibility requirements may limit security improvements

2. **C Language Limitations**:
   - Manual memory management increases risk of buffer overflows and use-after-free
   - Lack of type safety compared to modern languages
   - Pointer manipulation can lead to security vulnerabilities

3. **Symbol Visibility**:
   - The need to export symbols for module compatibility (`-fvisibility=default`)
   - This increases the attack surface by making more symbols available
   - Could potentially be mitigated with more granular export controls

4. **Dependency Chain**:
   - Reliance on external libraries (OpenSSL, LibXml2, jansson)
   - Security is only as strong as the weakest dependency
   - Vulnerabilities in dependencies may affect ircd-hybrid

5. **Configuration Complexity**:
   - Complex configuration options may lead to misconfiguration
   - Default settings may not be optimal for all security requirements
   - Balancing security with usability can be challenging

### Security Recommendations

1. **Regular Updates**:
   - Keep ircd-hybrid and all dependencies updated to the latest versions
   - Monitor security advisories for both ircd-hybrid and its dependencies
   - Apply security patches promptly

2. **Configuration Hardening**:
   - Review and customize the default configuration
   - Disable unnecessary modules and features
   - Use strong authentication mechanisms
   - Implement proper access controls

3. **Network Security**:
   - Use TLS for all connections
   - Implement proper firewall rules
   - Consider running in a restricted environment

4. **Monitoring and Logging**:
   - Enable comprehensive logging
   - Monitor logs for suspicious activity
   - Implement intrusion detection systems

5. **Code Review and Testing**:
   - Conduct regular security audits
   - Use static analysis tools
   - Perform penetration testing
   - Consider fuzzing for vulnerability discovery

## Building from Source

To build ircd-hybrid from source:

1. Clone the repository:
   ```
   git clone https://github.com/ircd-hybrid/ircd-hybrid.git
   cd ircd-hybrid
   ```

2. Create a build directory and run CMake:
   ```
   mkdir build
   cd build
   cmake ..
   ```

3. Build the project:
   ```
   make
   ```

4. Install the IRCd:
   ```
   sudo make install
   ```

## Customizing the Build

You can customize the build by passing options to CMake:

```
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..
```

Common build types include:
- `Debug`: Includes debugging information and minimal optimization.
- `Release`: Optimizes for performance and removes debugging information.
- `RelWithDebInfo`: Optimizes for performance but includes debugging information.
- `MinSizeRel`: Optimizes for size and removes debugging information.

## Troubleshooting

If you encounter build issues:

1. Make sure you have all required dependencies installed.
2. Check the CMake output for error messages.
3. Try building with verbose output: `make VERBOSE=1`
4. Check the logs for specific error messages. 