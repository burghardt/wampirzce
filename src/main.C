#include <iostream>
#include <GL/freeglut.h>

#include "config.h"
#include "kolonia.h"

using namespace std;

// ************************************************** //

const unsigned int wielkosc_ekosystemu_x = 800;
const unsigned int wielkosc_ekosystemu_y = 600;

const unsigned int pojemnosc_srodowiska = 80;
const unsigned int wampirzcow_na_poczatku = 8;

const unsigned int jurnosc_minimalna = 2;
const unsigned int jurnosc_maksymalna = 20;

const unsigned int zycie_minimalne = 80;
const unsigned int zycie_a_jurnosc = 5;

const unsigned int odpoczynek_minimalny = 32;
const double odpoczynek_a_jurnosc = 0.05;

const unsigned int prawdopodobienstwo_mutacji = 20; // w %
const double prawdopodobienstwo_mutacji_a_jurnosc = 0.5;

const double szybkosc_a_jurnosc = 0.3;

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
  clog << "Rozpoczynam symulacje..." << endl;
  glutMainLoop ();
  return 0;
}
