AC_INIT([Wampirzce], [0.0.1], [einstein@underground.org.pl], [wampirzce])
#AC_PREREQ([2.57])
AC_CONFIG_AUX_DIR(build)
AC_CONFIG_SRCDIR(src/main.C)
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX

# Checks for header files.
AC_CHECK_HEADER(sys/time.h,,AC_MSG_ERROR(No sys/time.h found!))
AC_CHECK_HEADER(GL/freeglut.h,,AC_MSG_ERROR(No GL/freeglut.h found!))

# Checks for library functions.
#AC_CHECK_LIB(Xxf86vm,XF86VidModeSetViewPort,,AC_MSG_ERROR(Xxf86vm))
#AC_CHECK_LIB(freeglut-1.3,glutInit,,AC_MSG_ERROR(freeglut-1.3))

#-DGL_FULL_SCREEN
CXXFLAGS="-Wall -ffast-math -funroll-loops -O3 -mcpu=athlon -march=athlon"
LDFLAGS="-L/usr/X11R6/lib -lfreeglut-1.3 -lXxf86vm"

AC_CONFIG_FILES([Makefile
 src/Makefile
 ])
AC_OUTPUT
