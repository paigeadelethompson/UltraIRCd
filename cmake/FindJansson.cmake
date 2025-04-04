# FindJansson.cmake
#
# Finds the Jansson library
#
# This will define the following variables:
#   JANSSON_FOUND        - True if Jansson was found
#   JANSSON_INCLUDE_DIRS - Jansson include directory
#   JANSSON_LIBRARIES    - Jansson library path

# Try to find pkg-config first
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
  pkg_check_modules(PC_JANSSON QUIET jansson)
  if(PC_JANSSON_FOUND)
    set(JANSSON_INCLUDE_DIRS ${PC_JANSSON_INCLUDE_DIRS})
    set(JANSSON_LIBRARIES ${PC_JANSSON_LIBRARIES})
    set(JANSSON_VERSION ${PC_JANSSON_VERSION})
    set(JANSSON_FOUND TRUE)
    return()
  endif()
endif()

# If pkg-config failed, try to find the library manually
find_path(JANSSON_INCLUDE_DIR
  NAMES jansson.h
  PATHS
    /usr/include
    /usr/local/include
    /opt/local/include
    /sw/include
)

find_library(JANSSON_LIBRARY
  NAMES jansson
  PATHS
    /usr/lib
    /usr/local/lib
    /opt/local/lib
    /sw/lib
)

# Handle the QUIETLY and REQUIRED arguments
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Jansson
  REQUIRED_VARS JANSSON_LIBRARY JANSSON_INCLUDE_DIR
  VERSION_VAR JANSSON_VERSION
)

# Set output variables
if(JANSSON_FOUND)
  set(JANSSON_LIBRARIES ${JANSSON_LIBRARY})
  set(JANSSON_INCLUDE_DIRS ${JANSSON_INCLUDE_DIR})
endif()

# Mark as advanced
mark_as_advanced(JANSSON_INCLUDE_DIR JANSSON_LIBRARY) 