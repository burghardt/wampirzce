AC_INIT([Symulacja Wampirzcow-Rozpustnikow],[1.0.2],[krzysztof@burghardt.pl],[wampirzce])
AC_CONFIG_AUX_DIR(build)
AC_CONFIG_SRCDIR(src/main.C)
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX

# Checks for header files.
AC_CHECK_HEADER(sys/time.h,,AC_MSG_ERROR([sys/time.h not found!]))
AC_CHECK_HEADER(GL/glut.h,,AC_MSG_ERROR([GL/glut.h not found!]))
AC_CHECK_HEADER(SDL/SDL.h,,AC_MSG_ERROR([SDL/SDL.h not found!]))
AC_CHECK_HEADER(SDL/SDL_opengl.h,,AC_MSG_ERROR([SDL/SDL_opengl.h not found!]))

# Checks for library functions.
AC_CHECK_LIB(GL,main,LIBS="$LIBS -lGL",AC_MSG_ERROR([libGL not found!]))
LIBS="$LIBS -L/usr/X11R6/lib -lglut"

# Check for SDL (via sdl-config)
AC_MSG_CHECKING(for SDL)
if test -x "`which sdl-config 2>/dev/null`"; then
    CXXFLAGS="$CXXFLAGS `sdl-config --cflags`"
    LIBS="$LIBS `sdl-config --libs`"
    AC_MSG_RESULT(yes)
else
    AC_MSG_ERROR(SDL not found!)
fi

# Set additional CPPFLAGS and LDFLAGS.
CPPFLAGS="$CPPFLAGS -Wall -Werror -Wextra -Wdate-time"
CPPFLAGS="$CPPFLAGS -Wformat -Wformat-security -D_FORTIFY_SOURCE=2"
CPPFLAGS="$CPPFLAGS -Wcast-align -Wcast-qual -Wchar-subscripts"
CPPFLAGS="$CPPFLAGS -Wformat-nonliteral -Wpointer-arith -Wredundant-decls"
CPPFLAGS="$CPPFLAGS -Wreturn-type -Wshadow -Wswitch -Wunused-parameter -Wwrite-strings"
CPPFLAGS="$CPPFLAGS -fstack-protector-strong -fPIC -fPIE"
LDFLAGS="$LDFLAGS -pie -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -Wl,--as-needed -Wl,-Bsymbolic-functions -Wl,--fatal-warnings"

AC_CONFIG_FILES([Makefile
 src/Makefile
 ])
AC_OUTPUT
