# Find Bison and Flex
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

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
    ircd_signal.c
    ircd_signal.h
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

# Create executable
add_executable(ircd ${IRCD_SOURCES})

# Generate parser files using custom commands
add_custom_command(
    OUTPUT 
        ${CMAKE_CURRENT_BINARY_DIR}/conf_parser.c
        ${CMAKE_CURRENT_BINARY_DIR}/conf_parser.h
    COMMAND ${BISON_EXECUTABLE} -d -o ${CMAKE_CURRENT_BINARY_DIR}/conf_parser.c ${CMAKE_CURRENT_SOURCE_DIR}/conf_parser.y
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/conf_parser.y
    COMMENT "Generating conf_parser.c and conf_parser.h from conf_parser.y"
)

# Generate lexer files using custom commands
add_custom_command(
    OUTPUT 
        ${CMAKE_CURRENT_BINARY_DIR}/conf_lexer.c
    COMMAND ${FLEX_EXECUTABLE} -o ${CMAKE_CURRENT_BINARY_DIR}/conf_lexer.c ${CMAKE_CURRENT_SOURCE_DIR}/conf_lexer.l
    DEPENDS 
        ${CMAKE_CURRENT_SOURCE_DIR}/conf_lexer.l
        ${CMAKE_CURRENT_BINARY_DIR}/conf_parser.h
    COMMENT "Generating conf_lexer.c from conf_lexer.l"
)

# Create a custom target for the generated files
add_custom_target(parser_files
    DEPENDS 
        ${CMAKE_CURRENT_BINARY_DIR}/conf_parser.c
        ${CMAKE_CURRENT_BINARY_DIR}/conf_parser.h
        ${CMAKE_CURRENT_BINARY_DIR}/conf_lexer.c
)

# Add the generated files to the ircd target
target_sources(ircd PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/conf_parser.c
    ${CMAKE_CURRENT_BINARY_DIR}/conf_lexer.c
)

# Add dependency on parser generation
add_dependencies(ircd parser_files)

# Include directories
target_include_directories(ircd PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Link libraries
target_link_libraries(ircd PRIVATE
    ${OPENSSL_LIBRARIES}
    io
    ltdl
    ircd_headers
    crypt
)

# Add Jansson library if found
if(JANSSON_FOUND)
    target_link_libraries(ircd PRIVATE ${JANSSON_LIBRARIES})
endif()

# Install
install(TARGETS ircd
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
) 