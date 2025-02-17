AC_DEFUN([AX_LIBRARY_JANSSON],[
  AC_SEARCH_LIBS([json_load_file], [jansson], [],
    [AC_MSG_ERROR([jansson library not found. Please install the jansson development package.])],[])
])
