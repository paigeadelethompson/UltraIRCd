# Install documentation files
install(FILES
    who.txt
    resv.txt
    serverhide.txt
    index.txt
    ircd.8
    kline.txt
    modeg.txt
    modes.txt
    monitor.txt
    reference.ircd.conf
    reference.modules.conf
    DESTINATION ${CMAKE_INSTALL_DOCDIR}/ircd-hybrid
)

# Install man page
install(FILES
    ircd.8
    DESTINATION ${CMAKE_INSTALL_MANDIR}/man8
)

# Install technical documentation
install(DIRECTORY
    technical/
    DESTINATION ${CMAKE_INSTALL_DOCDIR}/ircd-hybrid/technical
) 