#-DGL_FULL_SCREEN
AM_CXXFLAGS = -ffast-math -funroll-loops -O3 -mcpu=athlon -march=athlon -g
AM_LDFLAGS  = -L/usr/X11R6/lib -lGL -lGLU -lglut -lXi -lXmu

bin_PROGRAMS = wampirzce
wampirzce_SOURCES = polozenie.C wampirzec.C kolonia.C main.C \
		    polozenie.h wampirzec.h kolonia.h

indent:
	indent *.C *.h
	rm -f *~
