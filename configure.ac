AC_INIT([Symulacja Wampirzcow-Rozpustnikow], [0.0.1], [einstein@underground.org.pl], [wampirzce])
#AC_PREREQ([2.57])
AC_CONFIG_AUX_DIR(build)
AC_CONFIG_SRCDIR(src/main.C)
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX

# Checks for header files.
AC_CHECK_HEADER(sys/time.h,,AC_MSG_ERROR(No sys/time.h found!))
AC_CHECK_HEADER(GL/glut.h,,AC_MSG_ERROR(No GL/glut.h found!))

# Checks for library functions.
#AC_CHECK_LIB(Xxf86vm,XF86VidModeSetViewPort,,AC_MSG_ERROR(Xxf86vm))

AC_CONFIG_FILES([Makefile
 src/Makefile
 ])
AC_OUTPUT
