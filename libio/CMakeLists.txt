# Source files
set(IO_SOURCES
    src/sha3.c
    src/tls.h
    src/tls_gnutls.c
    src/tls_none.c
    src/tls_openssl.c
    src/tls_wolfssl.c
    src/module.c
    src/patricia.c
    src/res.c
    src/reslib.c
    src/rng_mt.c
    src/io_time.c
    src/list.c
    src/log.c
    src/match.c
    src/memory.c
    src/misc.c
    src/address.c
    src/base32.c
    src/comm.c
    src/comm_epoll.c
    src/comm_kqueue.c
    src/comm_poll.c
    src/dbuf.c
    src/event.c
    src/fdlist.c
    src/hook.c
    src/ident.c
    src/io_getopt.c
    src/io_pidfile.c
    src/io_rlimit.c
    src/io_signal.c
    src/io_string.c
)

# Create library
add_library(io STATIC ${IO_SOURCES})

# Add position-independent code flag
set_target_properties(io PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# Explicitly add -fPIC flag
target_compile_options(io PRIVATE -fPIC)

# Include directories
target_include_directories(io PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OPENSSL_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(io PUBLIC
    ${OPENSSL_LIBRARIES}
    ircd_headers
)

# Add Jansson if found
if(JANSSON_FOUND)
    target_include_directories(io PUBLIC ${JANSSON_INCLUDE_DIRS})
    target_link_libraries(io PUBLIC ${JANSSON_LIBRARIES})
endif()

# Install
install(TARGETS io
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install headers
install(FILES
    src/io.h
    src/tls.h
    src/module.h
    src/patricia.h
    src/res.h
    src/reslib.h
    src/rng_mt.h
    src/io_time.h
    src/list.h
    src/log.h
    src/memory.h
    src/misc.h
    src/address.h
    src/base32.h
    src/comm.h
    src/dbuf.h
    src/event.h
    src/fdlist.h
    src/hook.h
    src/ident.h
    src/io_getopt.h
    src/io_pidfile.h
    src/io_rlimit.h
    src/io_signal.h
    src/io_string.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ircd-hybrid
) 