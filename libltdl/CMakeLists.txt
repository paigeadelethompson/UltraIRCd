# Source files
set(LTDL_SOURCES
    ltdl.c
    lt__alloc.c
    lt__argz.c
    lt__dirent.c
    lt__strl.c
    lt_dlloader.c
    lt_error.c
    slist.c
)

# Copy lt__argz_.h to lt__argz.h in build directory
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libltdl)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/libltdl/lt__argz_.h
    ${CMAKE_CURRENT_BINARY_DIR}/libltdl/lt__argz.h
    COPYONLY
)

# Create library
add_library(ltdl STATIC ${LTDL_SOURCES})

# Add position-independent code flag
set_target_properties(ltdl PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# Include directories
target_include_directories(ltdl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/libltdl
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/libltdl
    ${CMAKE_BINARY_DIR}
)

# Add compile definitions
target_compile_definitions(ltdl PRIVATE
    HAVE_CONFIG_H
    LTDL
    LT_CONFIG_H="config.h"
)

# Install
install(TARGETS ltdl
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install headers
install(FILES
    ltdl.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ircd-hybrid
)

# Install license
install(FILES
    COPYING.LIB
    DESTINATION ${CMAKE_INSTALL_DOCDIR}
) 