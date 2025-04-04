ircd-hybrid
&middot;
[![Latest Github release](https://img.shields.io/github/v/tag/ircd-hybrid/ircd-hybrid?color=425158&style=flat-square)](https://github.com/ircd-hybrid/ircd-hybrid/tags)
[![Build status](https://img.shields.io/github/actions/workflow/status/ircd-hybrid/ircd-hybrid/ci.yml?branch=8.2.x&color=425158&style=flat-square)](https://github.com/ircd-hybrid/ircd-hybrid/actions/workflows/ci.yml)
[![Coverity scan](https://img.shields.io/coverity/scan/ircd-hybrid-ircd-hybrid?color=425158&style=flat-square)](https://scan.coverity.com/projects/ircd-hybrid-ircd-hybrid)
=====
A lightweight, high-performance internet relay chat daemon. Designed to be fast and reliable. Powering irc networks since 1997.


## Requirements
ircd-hybrid requires a POSIX compliant operating system like GNU/Linux, GNU/Hurd, *BSD family, or macOS.

## Installation
See the [INSTALL.md](INSTALL.md) document for info on configuring and compiling ircd-hybrid.


## Support
In case you need help or just want to delve deeper, you can join us on irc - #ircd-coders on irc.ircd-hybrid.org


## License
ircd-hybrid is licensed under the **GNU General Public License v2.0**. A complete version of the license is available in the [COPYING.md](COPYING.md) file in this repository.

## Building with CMake

ircd-hybrid now uses CMake as its build system. Here's how to build it:

### Prerequisites

- CMake 3.14 or higher
- C compiler (GCC, Clang, etc.)
- OpenSSL development libraries
- Jansson library (optional, but recommended)

### Building

1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

2. Configure the project:
   ```bash
   cmake ..
   ```

   You can customize the build with various options:
   ```bash
   cmake -DENABLE_DEBUGGING=ON -DWITH_JANSSON=OFF ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

4. Install:
   ```bash
   sudo cmake --install .
   ```

### CMake Options

- `ENABLE_ASSERT`: Enable assertions (default: OFF)
- `ENABLE_DEBUGGING`: Enable debugging (default: OFF)
- `ENABLE_WARNINGS`: Enable warnings (default: ON)
- `ENABLE_EFENCE`: Enable Electric Fence (default: OFF)
- `WITH_TLS`: Enable TLS support (default: ON)
- `WITH_JANSSON`: Enable Jansson support (default: ON)

## Documentation

For more information, see the following files:
- `INSTALL.md`: Installation instructions
- `doc/`: Documentation directory
- `help/`: Help text files
