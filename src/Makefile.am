AM_CXXFLAGS = -DGL_FULL_SCREEN -O2
AM_LDFLAGS  = -L/usr/X11R6/lib

bin_PROGRAMS = wampirzce
wampirzce_SOURCES = polozenie.C wampirzec.C kolonia.C main.C \
		    polozenie.h wampirzec.h kolonia.h

indent:
	indent *.C *.h
	rm -f *~
