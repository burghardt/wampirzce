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

// $Id: kolonia.C,v 1.2 2004-02-05 00:14:38 einstein Exp $

#include <iostream>
#include "kolonia.h"

using namespace std;

Kolonia::Kolonia (void)
{
  iteracji = 0;
  for (unsigned int i = 0; i < wampirzcow_na_poczatku; ++i)
    {
      stado.push_back (new Wampirzec ());
    }

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

  if ( iteracji % 25 == 0 ) {
    cout << "[ ----------------------------- ]" << endl;
    cout << "[ Iteracji: \t\t" << iteracji <<"\t]" << endl;
    cout << "[ Liczba Wampirzcow: \t" << stado.size() << "\t]" << endl;
  }

  return;
}
