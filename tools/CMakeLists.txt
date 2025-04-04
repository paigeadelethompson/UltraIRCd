# Build mkpasswd tool
add_executable(mkpasswd mkpasswd.c)
target_include_directories(mkpasswd PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/libio/src
)
target_link_libraries(mkpasswd PRIVATE
    io
    ltdl
    ${OPENSSL_LIBRARIES}
)

# Install mkpasswd
install(TARGETS mkpasswd
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install README files
install(FILES
    README
    README.mkpasswd
    DESTINATION ${CMAKE_INSTALL_DOCDIR}/ircd-hybrid/tools
) 