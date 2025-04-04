# ircd-hybrid

ircd-hybrid is a high-performance Internet Relay Chat (IRC) server that features a high degree of configurable IRC features.

## Prerequisites

Before you begin, ensure you have the following installed:

- CMake (version 3.14 or higher)
- C compiler (GCC, Clang, or MSVC)
- Python 3.x
- Conan 2.x package manager
- Make (for Unix-like systems)

### Installing Prerequisites

#### Ubuntu/Debian
```bash
# Install build essentials and CMake
sudo apt-get update
sudo apt-get install build-essential cmake python3 python3-pip make

# Install Conan
pip3 install conan

# Create Conan profile
conan profile detect
```

#### Fedora/RHEL
```bash
# Install build essentials and CMake
sudo dnf install gcc gcc-c++ make cmake python3 python3-pip

# Install Conan
pip3 install conan

# Create Conan profile
conan profile detect
```

#### macOS
```bash
# Using Homebrew
brew install cmake python3 make

# Install Conan
pip3 install conan

# Create Conan profile
conan profile detect
```

## Building from Source

1. Clone the repository:
```bash
git clone https://github.com/ircd-hybrid/ircd-hybrid.git
cd ircd-hybrid
```

2. Create a build directory and navigate to it:
```bash
mkdir build
cd build
```

3. Install dependencies using Conan:
```bash
# Make sure you have created a Conan profile first
conan profile detect

# Install dependencies (Conan 2.x syntax)
conan install .. --output-folder=. --build=missing --profile:build=default --profile:host=default
```

4. Configure the project with CMake:
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
```

5. Build the project:
```bash
cmake --build .
```

### Build Options

You can customize the build using various CMake options:

- `-DWITH_TLS=ON/OFF`: Enable/disable TLS support (default: ON)
- `-DWITH_JANSSON=ON/OFF`: Enable/disable Jansson support (default: ON)
- `-DENABLE_DEBUGGING=ON/OFF`: Enable/disable debugging (default: OFF)
- `-DENABLE_WARNINGS=ON/OFF`: Enable/disable compiler warnings (default: ON)

Example with options:
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DWITH_TLS=ON -DENABLE_DEBUGGING=ON
```

### Building in Debug Mode

To build the project in debug mode:

1. Clean the build directory:
```bash
rm -rf *
```

2. Install dependencies with debug settings:
```bash
# Install dependencies with debug settings
conan install .. --output-folder=. --build=missing --profile:build=default --profile:host=default -s build_type=Debug
```

3. Configure CMake with debug settings:
```bash
# Use the correct toolchain file path
cmake .. -DCMAKE_TOOLCHAIN_FILE=build/Debug/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_DEBUGGING=ON
```

4. Build the project:
```bash
cmake --build .
```

The debug build will:
- Include debug symbols
- Disable optimizations
- Enable debugging features
- Include additional debug logging

Note: If you encounter the "conan_toolchain.cmake not found" error:
1. Make sure you're in the correct build directory
2. Check if the conan install command completed successfully
3. The toolchain file is located at `build/Debug/generators/conan_toolchain.cmake`
4. Alternatively, you can use CMake presets (if CMake 3.23+ is available):
   ```bash
   cmake --preset conan-debug
   ```

### Installation

After building, you can install the server:

```bash
sudo cmake --install .
```

## Development

### Project Structure

- `src/`: Main source code
- `modules/`: Loadable modules
- `libio/`: I/O library
- `cmake/`: CMake modules and configuration
- `doc/`: Documentation
- `help/`: Help files

### Adding Dependencies

To add new dependencies:

1. Update `conanfile.py` with the new dependency:
```python
def requirements(self):
    self.requires("dependency_name/version")
```

2. Re-run Conan install:
```bash
conan install .. --output-folder=. --build=missing --profile:build=default --profile:host=default
```

## Troubleshooting

### Common Issues

1. **Conan not found**
   - Ensure Conan is installed: `pip3 install conan`
   - Verify installation: `conan --version`
   - Check Python path: `which python3`

2. **CMake configuration fails**
   - Check CMake version: `cmake --version`
   - Ensure all prerequisites are installed
   - Verify Conan dependencies are installed
   - Check if conan_toolchain.cmake exists in build directory
   - Verify make is installed: `which make`

3. **Build fails**
   - Check compiler version
   - Ensure all required system libraries are installed
   - Check build logs for specific errors
   - Verify Conan profile exists: `conan profile list`

4. **Conan toolchain not found**
   - Make sure you ran `conan install` with the correct profiles
   - Check if conan_toolchain.cmake exists in the build directory
   - Try cleaning the build directory and running conan install again:
     ```bash
     rm -rf *
     conan install .. --output-folder=. --build=missing --profile:build=default --profile:host=default
     ```

5. **Make not found**
   - Install make: 
     - Ubuntu/Debian: `sudo apt-get install make`
     - Fedora/RHEL: `sudo dnf install make`
     - macOS: `brew install make`

## License

This project is licensed under the GPL-2.0-or-later License - see the [COPYING.md](COPYING.md) file for details. 