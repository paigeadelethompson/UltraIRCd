# IRCd Hybrid

This repository contains the IRCd Hybrid IRC daemon and its vendored dependencies.

## Purpose

IRCd Hybrid is an advanced, lightweight Internet Relay Chat Daemon (ircd). This package includes vendored dependencies to simplify dependency management using Conan 2.0 for C/C++ dependency management.

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