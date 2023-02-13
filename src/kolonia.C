/*
   kolonia.C - implementacja klasy kolonia

   This file is part of Wampirzce.
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

// $Id: kolonia.C,v 1.8 2007-11-01 17:07:20 kb Exp $

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/glut.h>
#include "kolonia.h"

using namespace std;

static void
glDrawText (const char *text)
{
  for (unsigned int i = 0; i < strlen (text); i++)
    {
      glutStrokeCharacter (GLUT_STROKE_MONO_ROMAN, text[i]);
    }
}

Kolonia::Kolonia (void)
{
  iteracji = 0;
  for (unsigned int i = 0; i < wampirzcow_na_poczatku; ++i)
    {
      stado.push_back (new Wampirzec ());
    }
  (*stado.begin())->UstawIloscWampirzcow (wampirzcow_na_poczatku);

  return;
}

Kolonia::~Kolonia (void)
{
  list < Wampirzec * >::iterator poczatek = stado.begin ();
  list < Wampirzec * >::iterator koniec = stado.end ();

  while (poczatek != koniec)
    {
      delete (*poczatek);
      ++poczatek;
    }

  stado.empty ();

  return;
}

void
Kolonia::ChwilaZycia (void)
{
  ++iteracji;
  list < Wampirzec * >::iterator poczatek = stado.begin ();
  list < Wampirzec * >::iterator koniec = stado.end ();
  Wampirzec *nowy = NULL;

  if (poczatek == koniec)
    {
      cout << "Wszystkie Wampirzce wyginely..." << endl;
      exit (0);
    }

  while (poczatek != koniec)
    {
      if ((*poczatek)->CzyMartwy ())
        {
          stado.erase (poczatek++);
          continue;
        }
      if ((nowy = (*poczatek++)->ChwilaZycia (stado)))
        {
          stado.push_back (nowy);
        }
    }

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glOrtho (0.0, wielkosc_okna_x, 0,
           wielkosc_okna_y - ((wielkosc_okna_y / 50.0) + 5), -1.0, 1.0);
  glColor4f (0.7f, 0.6f, 0.5f, 0.4f);
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glBegin (GL_QUADS);
  glVertex2f (0.f, 0.f);
  glVertex2f (wielkosc_okna_x, 0.f);
  glVertex2f (wielkosc_okna_x, 20.f);
  glVertex2f (0.f, 20.f);
  glEnd ();

  glColor3f (1.f, 1.f, 1.f);
  glEnable (GL_LINE_SMOOTH);
  glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);

  char buffer[32];
  glScalef (0.1f, 0.1f, 1.0f);

  glTranslatef (100.f, 50.f, 0.f);
  glDrawText ("Wampirzcow: ");
  sprintf (buffer, "%d", stado.size ());
  glDrawText (buffer);

  glTranslatef (wielkosc_okna_x / 2 + 10, 0.f, 0.f);
  glDrawText ("Iteracji: ");
  sprintf (buffer, "%d", iteracji);
  glDrawText (buffer);

  glTranslatef (wielkosc_okna_x * 3.0 / 4.0 + 10, 0.f, 0.f);
  glDrawText ("Klawiszologia: [R]estart, [W]yjscie");

  glDisable (GL_LINE_SMOOTH);

  return;
}
