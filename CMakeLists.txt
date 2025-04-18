cmake_minimum_required(VERSION 3.14)

# Include Conan-generated files
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake OPTIONAL RESULT_VARIABLE CONAN_TOOLCHAIN)
if(NOT CONAN_TOOLCHAIN)
    message(WARNING "The file conan_toolchain.cmake was not found. Make sure to run 'conan install' first.")
endif()

project(ultra-ircd VERSION 8.3.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add custom CMake modules path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Options
option(ENABLE_ASSERT "Enable assertions" OFF)
option(ENABLE_DEBUGGING "Enable debugging" OFF)
option(ENABLE_WARNINGS "Enable warnings" ON)
option(ENABLE_EFENCE "Enable Electric Fence" OFF)
option(WITH_TLS "Enable TLS support" ON)
option(WITH_JANSSON "Enable Jansson support" ON)

# Security options
option(ENABLE_SECURITY_HARDENING "Enable security hardening features" ON)
option(ENABLE_STACK_PROTECTOR "Enable stack protection" ON)
option(ENABLE_FORTIFY_SOURCE "Enable FORTIFY_SOURCE" ON)
option(ENABLE_PIE "Enable Position Independent Executable" ON)
option(ENABLE_RELRO "Enable RELRO" ON)
option(ENABLE_CFI "Enable Control Flow Integrity" ON)
option(ENABLE_ASAN "Enable Address Sanitizer" ON)
option(ENABLE_UBSAN "Enable Undefined Behavior Sanitizer" ON)
option(ENABLE_SECURE_ALLOCATOR "Use a secure memory allocator" ON)
option(ENABLE_SECURE_RANDOM "Use a secure random number generator" ON)
option(ENABLE_SECURE_STRING "Use secure string functions" ON)
option(ENABLE_SECURE_MATH "Use secure math functions" ON)

# I/O polling mechanism selection
option(ENABLE_KQUEUE "Force kqueue usage" OFF)
option(ENABLE_EPOLL "Force epoll usage" OFF)
option(ENABLE_POLL "Force poll usage" OFF)

# Define I/O polling mechanism constants
set(AX_IOPOLL_MECHANISM_NONE 0)
set(AX_IOPOLL_MECHANISM_KQUEUE 1)
set(AX_IOPOLL_MECHANISM_EPOLL 2)
set(AX_IOPOLL_MECHANISM_POLL 3)

# Check for available mechanisms
if(ENABLE_KQUEUE)
    if(HAVE_SYS_EVENT_H)
        set(USE_IOPOLL_MECHANISM ${AX_IOPOLL_MECHANISM_KQUEUE})
    else()
        message(FATAL_ERROR "kqueue requested but sys/event.h not found")
    endif()
elseif(ENABLE_EPOLL)
    check_include_files("sys/epoll.h" HAVE_SYS_EPOLL_H)
    if(HAVE_SYS_EPOLL_H)
        set(USE_IOPOLL_MECHANISM ${AX_IOPOLL_MECHANISM_EPOLL})
    else()
        message(FATAL_ERROR "epoll requested but sys/epoll.h not found")
    endif()
elseif(ENABLE_POLL)
    set(USE_IOPOLL_MECHANISM ${AX_IOPOLL_MECHANISM_POLL})
else()
    # Auto-detect best available mechanism
    if(HAVE_SYS_EPOLL_H)
        set(USE_IOPOLL_MECHANISM ${AX_IOPOLL_MECHANISM_EPOLL})
    elseif(HAVE_SYS_EVENT_H)
        set(USE_IOPOLL_MECHANISM ${AX_IOPOLL_MECHANISM_KQUEUE})
    else()
        set(USE_IOPOLL_MECHANISM ${AX_IOPOLL_MECHANISM_POLL})
    endif()
endif()

# Add definitions for I/O polling mechanism
add_definitions(-DUSE_IOPOLL_MECHANISM=${USE_IOPOLL_MECHANISM})
add_definitions(-DAX_IOPOLL_MECHANISM_NONE=${AX_IOPOLL_MECHANISM_NONE})
add_definitions(-DAX_IOPOLL_MECHANISM_KQUEUE=${AX_IOPOLL_MECHANISM_KQUEUE})
add_definitions(-DAX_IOPOLL_MECHANISM_EPOLL=${AX_IOPOLL_MECHANISM_EPOLL})
add_definitions(-DAX_IOPOLL_MECHANISM_POLL=${AX_IOPOLL_MECHANISM_POLL})

# Find required packages
find_package(OpenSSL REQUIRED)
if(WITH_JANSSON)
  find_package(Jansson REQUIRED)
  if(NOT JANSSON_FOUND)
    message(WARNING "Jansson library not found. Some features may be disabled.")
  endif()
endif()

# Check for system features
include(CheckSymbolExists)
include(CheckIncludeFiles)
include(CheckTypeSize)
include(CheckStructHasMember)

# Check for required headers
check_include_files("dirent.h" HAVE_DIRENT_H)
check_include_files("dlfcn.h" HAVE_DLFCN_H)
check_include_files("errno.h" HAVE_ERRNO_H)
check_include_files("inttypes.h" HAVE_INTTYPES_H)
check_include_files("memory.h" HAVE_MEMORY_H)
check_include_files("ndir.h" HAVE_NDIR_H)
check_include_files("stdint.h" HAVE_STDINT_H)
check_include_files("stdlib.h" HAVE_STDLIB_H)
check_include_files("strings.h" HAVE_STRINGS_H)
check_include_files("string.h" HAVE_STRING_H)
check_include_files("sys/dir.h" HAVE_SYS_DIR_H)
check_include_files("sys/dl.h" HAVE_SYS_DL_H)
check_include_files("sys/ndir.h" HAVE_SYS_NDIR_H)
check_include_files("sys/param.h" HAVE_SYS_PARAM_H)
check_include_files("sys/stat.h" HAVE_SYS_STAT_H)
check_include_files("sys/types.h" HAVE_SYS_TYPES_H)
check_include_files("sys/wait.h" HAVE_SYS_WAIT_H)
check_include_files("unistd.h" HAVE_UNISTD_H)
check_include_files("crypt.h" HAVE_CRYPT_H)
check_include_files("socket.h" HAVE_SOCKET_H)
check_include_files("types.h" HAVE_TYPES_H)
check_include_files("sys/event.h" HAVE_SYS_EVENT_H)

# Check for error_t type
check_type_size("error_t" HAVE_ERROR_T)
if(NOT HAVE_ERROR_T)
    add_definitions(-Derror_t=int)
endif()

# Check for endianness
include(TestBigEndian)
test_big_endian(WORDS_BIGENDIAN)

# Define LT_OBJDIR
set(LT_OBJDIR ".libs/")

# Compiler flags
if(ENABLE_WARNINGS)
    add_compile_options(-Wall -Werror -Wextra -Wno-unused-parameter)
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        add_compile_options(-Wno-format-truncation)
    endif()
endif()

if(ENABLE_DEBUGGING)
    add_compile_options(-g -O0)
else()
    add_compile_options(-O2)
endif()

# Security hardening flags
if(ENABLE_SECURITY_HARDENING)
    # Format string protection
    add_compile_options(-Wformat-security -Wformat=2)
    
    # Integer overflow protection
    add_compile_options(-fwrapv)
    
    # Additional compiler flags
    add_compile_options(
        -D_FORTIFY_SOURCE=3
        -fstack-clash-protection
        -fstack-check
        -fcf-protection=branch
        -fno-common
        -fno-ident
        -fno-stack-check
        -fno-strict-aliasing
        -fno-builtin
        -fno-omit-frame-pointer
        -fno-optimize-sibling-calls
    )
    
    # Additional linker flags
    add_link_options(
        -Wl,-z,noexecstack
        -Wl,-z,separate-code
        -Wl,-z,defs
        -Wl,-z,text
        -Wl,-z,nodlopen
        -Wl,-z,nodump
    )
    
    # Check for sanitizer support
    include(CheckCCompilerFlag)
    set(SANITIZER_FLAGS "")
    
    # Check for address sanitizer
    check_c_compiler_flag("-fsanitize=address" HAVE_ASAN)
    if(HAVE_ASAN)
        list(APPEND SANITIZER_FLAGS "address")
    endif()
    
    # Check for leak sanitizer
    check_c_compiler_flag("-fsanitize=leak" HAVE_LSAN)
    if(HAVE_LSAN)
        list(APPEND SANITIZER_FLAGS "leak")
    endif()
    
    # Check for thread sanitizer
    check_c_compiler_flag("-fsanitize=thread" HAVE_TSAN)
    if(HAVE_TSAN)
        list(APPEND SANITIZER_FLAGS "thread")
    endif()
    
    # Check for memory sanitizer
    check_c_compiler_flag("-fsanitize=memory" HAVE_MSAN)
    if(HAVE_MSAN)
        list(APPEND SANITIZER_FLAGS "memory")
    endif()
    
    # Check for safe stack sanitizer
    check_c_compiler_flag("-fsanitize=safe-stack" HAVE_SAFE_STACK)
    if(HAVE_SAFE_STACK)
        list(APPEND SANITIZER_FLAGS "safe-stack")
    endif()
    
    # Apply supported sanitizers
    if(ENABLE_ASAN AND NOT "${SANITIZER_FLAGS}" STREQUAL "")
        string(REPLACE ";" "," SANITIZER_STRING "${SANITIZER_FLAGS}")
        add_compile_options(-fsanitize=${SANITIZER_STRING})
        add_link_options(-fsanitize=${SANITIZER_STRING})
    endif()
    
    # Build options
    add_compile_definitions(
        _GLIBCXX_ASSERTIONS
        _GLIBCXX_SANITIZE_VECTOR
        _GLIBCXX_DEBUG
    )
    
    # Runtime options
    set(ENV{MALLOC_CHECK_} 3)
    set(ENV{MALLOC_TRACE} 1)
    set(ENV{GLIBC_TUNABLES} "glibc.malloc.trim_threshold=131072:glibc.malloc.mmap_threshold=131072")
    
    if(ENABLE_STACK_PROTECTOR)
        add_compile_options(-fstack-protector-strong)
    endif()
    
    if(ENABLE_FORTIFY_SOURCE)
        add_compile_definitions(_FORTIFY_SOURCE=3)
    endif()
    
    if(ENABLE_PIE)
        add_compile_options(-fPIE)
        add_link_options(-pie)
    endif()
    
    if(ENABLE_RELRO)
        add_link_options(-Wl,-z,relro -Wl,-z,now)
    endif()
    
    if(ENABLE_CFI)
        add_compile_options(-fcf-protection=full)
    endif()
    
    if(ENABLE_UBSAN)
        add_compile_options(-fsanitize=undefined)
        add_link_options(-fsanitize=undefined)
    endif()
    
    # Secure features
    if(ENABLE_SECURE_ALLOCATOR)
        add_compile_definitions(USE_SECURE_ALLOCATOR)
    endif()
    
    if(ENABLE_SECURE_RANDOM)
        add_compile_definitions(USE_SECURE_RANDOM)
    endif()
    
    if(ENABLE_SECURE_STRING)
        add_compile_definitions(USE_SECURE_STRING)
    endif()
    
    if(ENABLE_SECURE_MATH)
        add_compile_definitions(USE_SECURE_MATH)
    endif()
endif()

# Define build date
string(TIMESTAMP BUILD_DATE "%Y%m%d")

# Define installation directories
include(GNUInstallDirs)

# Define package information
set(PACKAGE_NAME "ultra-ircd")
set(PACKAGE_VERSION "8.3.0")

# Add definitions for installation directories
add_definitions(-DPREFIX="${CMAKE_INSTALL_PREFIX}")
add_definitions(-DSYSCONFDIR="${CMAKE_INSTALL_SYSCONFDIR}")
add_definitions(-DLIBDIR="${CMAKE_INSTALL_LIBDIR}")
add_definitions(-DDATADIR="${CMAKE_INSTALL_DATADIR}")
add_definitions(-DLOCALSTATEDIR="${CMAKE_INSTALL_LOCALSTATEDIR}")

# Add package information definitions
add_definitions(-DPACKAGE_NAME="${PACKAGE_NAME}")
add_definitions(-DPACKAGE_VERSION="${PACKAGE_VERSION}")
add_definitions(-DPACKAGE="ultra-ircd")

# Configure header
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    @ONLY
)

# Create a target for the headers
add_library(ircd_headers INTERFACE)
target_include_directories(ircd_headers INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/libio/src
    ${CMAKE_BINARY_DIR}
)

# Add subdirectories
add_subdirectory(libio)
add_subdirectory(src)
add_subdirectory(modules)

# Set ENABLE_EXPORTS property for the ircd executable
set_target_properties(ircd PROPERTIES ENABLE_EXPORTS ON)

# Install documentation
install(FILES
    AUTHORS.md
    COPYING.md
    INSTALL.md
    NEWS.md
    README.md
    DESTINATION ${CMAKE_INSTALL_DOCDIR}
)

# Export package
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/ircd-hybrid-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/ircd-hybrid-config-version.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ircd-hybrid
)

if(NOT HAVE_SYS_EVENT_H)
    add_definitions(-DHAVE_SYS_EVENT_H=0)
else()
    add_definitions(-DHAVE_SYS_EVENT_H=1)
endif() 