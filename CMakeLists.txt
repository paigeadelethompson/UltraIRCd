cmake_minimum_required(VERSION 3.14)
project(ircd-hybrid VERSION 8.2.47 LANGUAGES C)

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
  find_package(Jansson)
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
    add_compile_options(-Wall -Wextra -Wno-unused-parameter)
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        add_compile_options(-Wno-format-truncation)
    endif()
endif()

if(ENABLE_DEBUGGING)
    add_compile_options(-g -O0)
else()
    add_compile_options(-O2)
endif()

# Define build date
string(TIMESTAMP BUILD_DATE "%Y%m%d")

# Define installation directories
include(GNUInstallDirs)

# Define package information
set(PACKAGE_NAME "ircd-hybrid")
set(PACKAGE_VERSION "8.2.47")

# Add definitions for installation directories
add_definitions(-DPREFIX="${CMAKE_INSTALL_PREFIX}")
add_definitions(-DSYSCONFDIR="${CMAKE_INSTALL_SYSCONFDIR}")
add_definitions(-DLIBDIR="${CMAKE_INSTALL_LIBDIR}")
add_definitions(-DDATADIR="${CMAKE_INSTALL_DATADIR}")
add_definitions(-DLOCALSTATEDIR="${CMAKE_INSTALL_LOCALSTATEDIR}")

# Add package information definitions
add_definitions(-DPACKAGE_NAME="${PACKAGE_NAME}")
add_definitions(-DPACKAGE_VERSION="${PACKAGE_VERSION}")
add_definitions(-DPACKAGE="ircd-hybrid")

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