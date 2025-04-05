# Find required packages
find_package(OpenSSL REQUIRED)
find_package(LibXml2 REQUIRED)
find_package(jansson REQUIRED)

# Source files
set(MODULE_SOURCES
    umode_flood.c
    umode_hidden.c
    umode_hidechans.c
    umode_hideidle.c
    umode_invisible.c
    umode_locops.c
    umode_nickchange.c
    umode_oper.c
    umode_registered.c
    umode_regonly.c
    umode_reject.c
    umode_secure.c
    umode_secureonly.c
    umode_servnotice.c
    umode_skill.c
    umode_softcallerid.c
    umode_spy.c
    umode_wallops.c
    umode_webirc.c
    m_who.c
    m_whois.c
    m_whowas.c
    m_xline.c
    umode_admin.c
    umode_bot.c
    umode_callerid.c
    umode_cloak.c
    umode_connect.c
    umode_deaf.c
    umode_expiration.c
    umode_external.c
    umode_farconnect.c
    m_stats.c
    m_svinfo.c
    m_svsaccount.c
    m_svshost.c
    m_svsjoin.c
    m_svskill.c
    m_svsmode.c
    m_svsnick.c
    m_svspart.c
    m_svstag.c
    m_tburst.c
    m_time.c
    m_tmode.c
    m_topic.c
    m_trace.c
    m_undline.c
    m_unkline.c
    m_unresv.c
    m_unxline.c
    m_user.c
    m_userhost.c
    m_version.c
    m_webirc.c
    m_part.c
    m_pass.c
    m_ping.c
    m_pong.c
    m_post.c
    m_quit.c
    m_rehash.c
    m_restart.c
    m_resv.c
    m_resync.c
    m_server.c
    m_set.c
    m_sjoin.c
    m_squit.c
    m_links.c
    m_list.c
    m_locops.c
    m_lusers.c
    m_map.c
    m_message.c
    m_metadata.c
    m_mlock.c
    m_mode.c
    m_module.c
    m_monitor.c
    m_motd.c
    m_names.c
    m_nick.c
    m_oper.c
    m_opme.c
    m_dline.c
    m_encap.c
    m_eob.c
    m_error.c
    m_etrace.c
    m_globops.c
    m_hash.c
    m_help.c
    m_info.c
    m_invite.c
    m_ison.c
    m_join.c
    m_kick.c
    m_kill.c
    m_kline.c
)

# Create modules directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/modules)

# Set position independent code for all modules
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Build each module
foreach(MODULE_SOURCE ${MODULE_SOURCES})
    get_filename_component(MODULE_NAME ${MODULE_SOURCE} NAME_WE)
    add_library(${MODULE_NAME} SHARED ${MODULE_SOURCE})
    target_include_directories(${MODULE_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/libio/src
    )
    target_link_libraries(${MODULE_NAME} PRIVATE
        io
        ltdl
        ircd_shared
    )
    set_target_properties(${MODULE_NAME} PROPERTIES
        PREFIX ""
        OUTPUT_NAME "${MODULE_NAME}"
    )
    install(TARGETS ${MODULE_NAME}
        LIBRARY DESTINATION modules
    )
    set_target_properties(${MODULE_NAME} PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        C_VISIBILITY_PRESET default
    )
    target_compile_options(${MODULE_NAME} PRIVATE
        -fPIC
        -fvisibility=default
    )
    target_link_libraries(${MODULE_NAME} PRIVATE
        ircd_shared
        io
        ltdl
        ${OPENSSL_LIBRARIES}
        crypt
        ${LIBXML2_LIBRARIES}
        ${JANSSON_LIBRARIES}
    )
endforeach() 