/*
   Wampirzce - Symulacja Wampirzcow-Rozpustnikow
   Copyright (C) 2004 Krzysztof Burghardt.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <iostream>
#include <GL/freeglut.h>

#include "config.h"
#include "kolonia.h"

using namespace std;

static char *id = "$Id: main.C,v 1.6 2004-02-05 12:52:41 einstein Exp $";

// ************************************************** //

const unsigned int wielkosc_ekosystemu_x = 800;
const unsigned int wielkosc_ekosystemu_y = 600;

const unsigned int pojemnosc_srodowiska = 90;
const unsigned int wampirzcow_na_poczatku = 8;

const unsigned int jurnosc_minimalna = 2;
const unsigned int jurnosc_maksymalna = 20;

const unsigned int zycie_minimalne = 80;
const unsigned int zycie_a_jurnosc = 5;

const unsigned int odpoczynek_minimalny = 32;
const double odpoczynek_a_jurnosc = 0.05;

const unsigned int prawdopodobienstwo_mutacji = 20; // w %
const double prawdopodobienstwo_mutacji_a_jurnosc = 0.5;

const double szybkosc_a_jurnosc = 0.7;

// ************************************************** //

unsigned int
  Wampirzec::ilosc_wampirzcow = 0;

// ************************************************** //

Kolonia Wampirzcow;

// ************************************************** //

void
BrykajaceWampirzce (void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glClearColor (0.0, 0.0, 0.0, 0.0);

  Wampirzcow.ChwilaZycia ();
  usleep (100000);

  glFlush ();
  glutSwapBuffers ();
}

int
main (int argc, char **argv)
{
  cout << PACKAGE_STRING << endl;
  cout << id << endl << endl;
  clog << "Uruchamiam FreeGLUT..." << endl;
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (wielkosc_ekosystemu_x,
		      wielkosc_ekosystemu_y - ((wielkosc_ekosystemu_y / 50) +
					       5));
  glutInitWindowPosition (50, 50);
  glutCreateWindow (PACKAGE_STRING);
#ifdef GL_FULL_SCREEN
  glutFullScreen ();
#endif
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glOrtho (0.0, wielkosc_ekosystemu_x, 0.0,
	   wielkosc_ekosystemu_y - ((wielkosc_ekosystemu_y / 50) + 5), -1.0,
	   1.0);
  clog << "Rejestruje funkcje obslugi wyswietlania..." << endl;
  glutDisplayFunc (&BrykajaceWampirzce);
  clog << "Rozpoczynam symulacje..." << endl << endl;
  glutMainLoop ();
  return 0;
}
