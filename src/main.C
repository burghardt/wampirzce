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
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "config.h"
#include "kolonia.h"

using namespace std;

static char *id = "$Id: main.C,v 1.13 2004-06-30 13:02:06 einstein Exp $";

unsigned int wielkosc_okna_x = 1024;
unsigned int wielkosc_okna_y = 768;

const unsigned int wielkosc_ekosystemu_x = 1800;
const unsigned int wielkosc_ekosystemu_y = 1400;

const unsigned int pojemnosc_srodowiska = 120;
const unsigned int wampirzcow_na_poczatku = 12;

const unsigned int jurnosc_minimalna = 2;
const unsigned int jurnosc_maksymalna = 20;

const unsigned int zycie_minimalne = 80;
const unsigned int zycie_a_jurnosc = 5;

const unsigned int odpoczynek_minimalny = 32;
const double odpoczynek_a_jurnosc = 0.05;

const unsigned int prawdopodobienstwo_mutacji = 20;	// w %
const double prawdopodobienstwo_mutacji_a_jurnosc = 0.5;

const double szybkosc_a_jurnosc = 0.7;

unsigned int
  Wampirzec::ilosc_wampirzcow = 0;

Kolonia *
  KoloniaWampirzcow;

int
main (int argc, char **argv)
{
  cout << PACKAGE_STRING << endl << id << endl;

  SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER);
  SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, true);
  SDL_GL_SetAttribute (SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute (SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute (SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute (SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute (SDL_GL_STENCIL_SIZE, 1);
  SDL_Surface *
    surface = SDL_SetVideoMode (wielkosc_okna_x,
				wielkosc_okna_y,
				32,
				SDL_OPENGL | SDL_DOUBLEBUF | SDL_FULLSCREEN);
  SDL_WM_SetCaption (PACKAGE_STRING, PACKAGE_STRING);

  SDL_Event event;
  bool go_quit = false;
  unsigned int
    startTime = 0;
  unsigned int
    endTime = 0;

  KoloniaWampirzcow = new Kolonia;

  while (!go_quit)
    {
      startTime = SDL_GetTicks ();
      while (SDL_PollEvent (&event))
	{
	  switch (event.type)
	    {
	    case SDL_KEYDOWN:
	      break;
	    case SDL_KEYUP:
	      switch (event.key.keysym.sym)
		{
		case SDLK_r:	// restart symulacji
		  delete KoloniaWampirzcow;
		  KoloniaWampirzcow = new Kolonia;
		  (*KoloniaWampirzcow)[0]->
		    UstawIloscWampirzcow (wampirzcow_na_poczatku);
		  break;
		case SDLK_ESCAPE:	// koniec symulacji
		case SDLK_q:
		case SDLK_w:
		  go_quit = true;
		  break;
		}
	      break;
	    case SDL_QUIT:
	      go_quit = true;
	      break;
	    }
	}
      glMatrixMode (GL_PROJECTION);
      glLoadIdentity ();
      glOrtho (0.0, wielkosc_ekosystemu_x, 0,
	       wielkosc_ekosystemu_y - ((wielkosc_ekosystemu_y / 50) + 5),
	       -1.0, 1.0);
      glClearColor (0.0, 0.0, 0.0, 0.0);
      glClear (GL_COLOR_BUFFER_BIT);
      KoloniaWampirzcow->ChwilaZycia ();
      glFlush ();
      SDL_GL_SwapBuffers ();
      endTime = SDL_GetTicks ();
      if (endTime - startTime < 5)
	SDL_Delay (5 - (startTime - endTime));
    }

  delete KoloniaWampirzcow;
  SDL_Quit ();
  return 0;
}
