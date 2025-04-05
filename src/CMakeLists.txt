# Generate schema header using xxd
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/conf_schema.h
    COMMAND xxd -i ${CMAKE_SOURCE_DIR}/etc/ircd.xsd > ${CMAKE_CURRENT_BINARY_DIR}/conf_schema.h
    DEPENDS ${CMAKE_SOURCE_DIR}/etc/ircd.xsd
    COMMENT "Generating schema header"
)

add_custom_target(schema_header DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/conf_schema.h)

# Find required packages
find_package(Python3 REQUIRED)
find_package(LibXml2 REQUIRED)
find_package(jansson REQUIRED)

# Source files
set(IRCD_SOURCES
    accept.c
    accept.h
    aline.c
    aline.h
    cap.c
    cap.h
    channel.c
    channel.h
    channel_invite.c
    channel_invite.h
    channel_mode.c
    channel_mode.h
    client.c
    client.h
    client_svstag.c
    client_svstag.h
    cloak.c
    cloak.h
    command.c
    command.h
    conf.c
    conf.h
    conf_class.c
    conf_class.h
    conf_cluster.c
    conf_cluster.h
    conf_db.c
    conf_db.h
    conf_gecos.c
    conf_gecos.h
    conf_pseudo.c
    conf_pseudo.h
    conf_resv.c
    conf_resv.h
    conf_service.c
    conf_service.h
    conf_shared.c
    conf_shared.h
    conf_xml.c
    conf_xml.h
    defaults.h
    extban.c
    extban.h
    extban_account.c
    extban_channel.c
    extban_fingerprint.c
    extban_gecos.c
    extban_join.c
    extban_knock.c
    extban_mute.c
    extban_nick.c
    extban_operclass.c
    extban_server.c
    extban_tlsinfo.c
    extban_usermode.c
    flatten_links.c
    flatten_links.h
    hash.c
    hash.h
    id.c
    id.h
    info.c
    info.h
    ipcache.c
    ipcache.h
    ircd.c
    ircd.h
    ircd_defs.h
    ircd_exit.c
    ircd_exit.h
    ircd_hook.c
    ircd_hook.h
    isupport.c
    isupport.h
    listener.c
    listener.h
    lookup.c
    lookup.h
    monitor.c
    monitor.h
    motd.c
    motd.h
    nuh.c
    nuh.h
    numeric.c
    numeric.h
    packet.c
    packet.h
    parse.c
    parse.h
    stats.c
    stats.h
    stdinc.h
    send.c
    send.h
    server.c
    server.h
    server_capab.c
    server_capab.h
    user.c
    user.h
    user_mode.c
    user_mode.h
    whowas.c
    whowas.h
)

# Create a shared library with the symbols needed by modules
add_library(ircd_shared SHARED ${IRCD_SOURCES})

# Set position independent code for the shared library
set_target_properties(ircd_shared PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_VISIBILITY_PRESET default
)

# Add -fPIC flag to the compilation of source files for the shared library
target_compile_options(ircd_shared PRIVATE 
    -fPIC
    -fvisibility=default
)

# Make schema generation a dependency of the shared library target
add_dependencies(ircd_shared schema_header)

# Include directories for the shared library
target_include_directories(ircd_shared PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/libio/src
)

# Link libraries for the shared library
target_link_libraries(ircd_shared PUBLIC
    ${OPENSSL_LIBRARIES}
    io
    ltdl
    ircd_headers
    crypt
    LibXml2::LibXml2
    jansson::jansson
)

# Create the IRCd executable
add_executable(ircd ${IRCD_SOURCES})

# Make schema generation a dependency of the ircd target
add_dependencies(ircd schema_header)

# Include directories
target_include_directories(ircd PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/libio/src
)

# Link libraries
target_link_libraries(ircd PRIVATE
    ${OPENSSL_LIBRARIES}
    io
    ltdl
    ircd_headers
    crypt
    LibXml2::LibXml2
    jansson::jansson
)

# Install
install(TARGETS ircd
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
) 