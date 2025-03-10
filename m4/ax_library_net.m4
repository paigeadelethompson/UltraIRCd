AC_DEFUN([AX_LIBRARY_NET],[
  AC_SEARCH_LIBS([socket],[socket],,[AC_MSG_ERROR([socket library not found])])
])
