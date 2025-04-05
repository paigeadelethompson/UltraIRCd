# IRCd Hybrid

This repository contains the IRCd Hybrid IRC daemon and its vendored dependencies.

## Purpose

IRCd Hybrid is an advanced, lightweight Internet Relay Chat Daemon (ircd). This package includes vendored dependencies to simplify dependency management using Conan 2.0 for C/C++ dependency management.

## Development Notes

- The configuration file is in XML format with an XSD schema that is injected into the build for validation and modeling purposes, without introspection.
- The build system has been completely rewritten in CMake, utilizing Conan 2 for managing vendored dependencies.
- The current author and maintainer of this project is Paige Thompson (paige@paige.bio).
- This project is a fork of IRCd Hybrid, named Ultra (UltraIRCd).
- The historical AUTHORS.md file is maintained for reference, but this project is not going to be IRCd Hybrid.

## System Dependencies

Before building Ultra-IRCd, you need to install the following system dependencies:

### Debian/Ubuntu
```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake git python3 python3-pip libssl-dev
```

### Fedora/RHEL/CentOS
```bash
sudo dnf install -y gcc gcc-c++ make cmake git python3 python3-pip openssl-devel
```

### Arch Linux
```bash
sudo pacman -S base-devel cmake git python python-pip openssl
```

### macOS
```bash
brew install cmake git python openssl
```

### FreeBSD
```bash
pkg install cmake git python3 py3-pip openssl
```
Note: FreeBSD uses Clang as its default compiler, so GCC is not required.

## Usage

To use this package:

1. Start a Hatch shell:
   ```
   hatch run shell
   ```

2. Create and change to the build directory:
   ```
   mkdir build && cd build
   ```

3. Install dependencies with Conan:

   For Debug build:
   ```
   conan install .. --output-folder=. --build=missing --profile:build=default --profile:host=default -s build_type=Debug
   ```

   For Release build:
   ```
   conan install .. --output-folder=. --build=missing --profile:build=default --profile:host=default -s build_type=Release
   ```

4. Configure with CMake:

   For Debug build:
   ```
   cmake .. -DCMAKE_TOOLCHAIN_FILE=build/Debug/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_DEBUGGING=ON
   ```

   For Release build:
   ```
   cmake .. -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
   ```

## Requirements

- Python 3.8 or higher
- Conan 2.0 or higher

## License

This package is licensed under the same terms as ircd-hybrid. 