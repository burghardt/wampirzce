/*
   wampirzec.C - implementacja klasy wampirzec

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

// $Id: wampirzec.C,v 1.6 2004-06-30 13:02:06 einstein Exp $

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "wampirzec.h"

using namespace std;

inline void
glPutPixel (double x, double y, double z, double r, double g, double b)
{
  glColor3f (r, g, b);
  glRectf (x - z, y + z, x + z, y - z);
}

Wampirzec::Wampirzec (const double _x, const double _y, const double _jurnosc,
		      const unsigned int _zycie,
		      const unsigned int _odpoczynek):
Polozenie (_x, _y)
{
  jurnosc = _jurnosc;
  zycie = _zycie + (int) (zycie_a_jurnosc * jurnosc);
  odpoczynek = _odpoczynek - (int) (odpoczynek_a_jurnosc * jurnosc);

  return;
}

Wampirzec *
Wampirzec::ChwilaZycia (const deque < Wampirzec * >wszystkie_wampirzce)
{
  Wampirzec *nowy = NULL;
  if (zycie)
    {
      glPutPixel (PobierzPolozenieX (), PobierzPolozenieY ()
		  - ((wielkosc_ekosystemu_y / 50) + 5), 5,
		  1, jurnosc / 20, jurnosc / 10);
      if (odpoczynek)
	{
	  Odpocznij ();
	}
      else
	{
	  Wampirzec *ZnalezionyPartner = NULL;
	  if ((ZnalezionyPartner = SzukajPartnera (wszystkie_wampirzce)) != 0)
	    {
	      nowy = RozmnazajSie (ZnalezionyPartner);
	    }
	}
      --zycie;
    }

  return nowy;
}

bool Wampirzec::CzyMartwy (void)
{
  if (zycie <= 0)
    {
      --ilosc_wampirzcow;
      return 1;
    }
  else
    {
      return 0;
    }
}

void
Wampirzec::UstawIloscWampirzcow (const unsigned int nowa_ilosc_wampirzcow)
{
  ilosc_wampirzcow = nowa_ilosc_wampirzcow;
}

void
Wampirzec::Przesun (unsigned char kierunek = 5, const double _odleglosc = 1)
{
  double odleglosc = _odleglosc + getrandom (0, szybkosc_a_jurnosc * jurnosc);
  switch (kierunek)
    {
    case 1:
      UstawPolozenieXY (PobierzPolozenieX () - odleglosc,
			PobierzPolozenieY () - odleglosc);
      break;
    case 2:
      UstawPolozenieXY (PobierzPolozenieX (),
			PobierzPolozenieY () - odleglosc);
      break;
    case 3:
      UstawPolozenieXY (PobierzPolozenieX () + odleglosc,
			PobierzPolozenieY () - odleglosc);
      break;
    case 4:
      UstawPolozenieXY (PobierzPolozenieX () - odleglosc,
			PobierzPolozenieY ());
      break;
    case 5:
      UstawPolozenieXY (PobierzPolozenieX (), PobierzPolozenieY ());
      break;
    case 6:
      UstawPolozenieXY (PobierzPolozenieX () + odleglosc,
			PobierzPolozenieY ());
      break;
    case 7:
      UstawPolozenieXY (PobierzPolozenieX () - odleglosc,
			PobierzPolozenieY () + odleglosc);
      break;
    case 8:
      UstawPolozenieXY (PobierzPolozenieX (),
			PobierzPolozenieY () + odleglosc);
      break;
    case 9:
      UstawPolozenieXY (PobierzPolozenieX () + odleglosc,
			PobierzPolozenieY () + odleglosc);
      break;
    default:
      clog << "BUG: " << __FILE__ << ":" << __LINE__ <<
	" Wampirzec::Przesun() - nieznany kierunek!" << endl;
    }

  return;
}

double
Wampirzec::Odleglosc (Wampirzec * partner)
{
  return sqrt (pow (PobierzPolozenieX () - partner->PobierzPolozenieX (), 2)
	       + pow (PobierzPolozenieY () - partner->PobierzPolozenieY (),
		      2));
}

void
Wampirzec::Odpocznij (void)
{
  Przesun (getrandom (1, 9), getrandom (1, 3));
  --odpoczynek;
  return;
}

Wampirzec *
Wampirzec::SzukajPartnera (deque < Wampirzec * >cale_stado)
{
  Wampirzec *najblizszy = NULL;
  deque < Wampirzec * >::iterator poczatek = cale_stado.begin ();
  deque < Wampirzec * >::iterator koniec = cale_stado.end ();
  najblizszy = (*poczatek++);

  while (poczatek != koniec)
    {
      if (*poczatek != this &&	// sam z soba sie nie rozmnozy
	  Odleglosc (*poczatek) < Odleglosc (najblizszy))
	{
	  najblizszy = (*poczatek);
	}
      ++poczatek;
    }

  if (Odleglosc (najblizszy) <= 3)	// sex na odleglosc? ;-P
    {
      return najblizszy;
    }
  else
    {
      unsigned char kierunek = getrandom (1, 9);
      if (PobierzPolozenieX () < najblizszy->PobierzPolozenieX ())
	{
	  if (PobierzPolozenieY () < najblizszy->PobierzPolozenieY ())
	    {
	      kierunek = 9;
	    }
	  else if (PobierzPolozenieY () == najblizszy->PobierzPolozenieY ())
	    {
	      kierunek = 6;
	    }
	  else
	    {
	      kierunek = 3;
	    }
	}
      else if (PobierzPolozenieX () == najblizszy->PobierzPolozenieX ())
	{
	  if (PobierzPolozenieY () < najblizszy->PobierzPolozenieY ())
	    {
	      kierunek = 8;
	    }
	  else
	    {
	      kierunek = 2;
	    }
	}
      else
	{
	  if (PobierzPolozenieY () < najblizszy->PobierzPolozenieY ())
	    {
	      kierunek = 7;
	    }
	  else if (PobierzPolozenieY () == najblizszy->PobierzPolozenieY ())
	    {
	      kierunek = 4;
	    }
	  else
	    {
	      kierunek = 1;
	    }
	}
      Przesun (kierunek);
    }

  return NULL;
}

Wampirzec *
Wampirzec::RozmnazajSie (Wampirzec * partner)
{
  Wampirzec *nowy = NULL;
  if (partner != this && ilosc_wampirzcow <= pojemnosc_srodowiska)
    {
      // dojdzie do mutacji kodu genetycznego?
      if (getrandom (0, 100) <
	  prawdopodobienstwo_mutacji -
	  (prawdopodobienstwo_mutacji_a_jurnosc * jurnosc))
	{
	  nowy = new Wampirzec (PobierzPolozenieX (), PobierzPolozenieY ());
	}
      else
	{			// nie, dziedzicza po jednym z rodzicow
	  double j = getrandom (0, 1) ? jurnosc : partner->jurnosc;
	  unsigned int z = getrandom (0, 1) ? zycie : partner->zycie;
	  unsigned int o =
	    getrandom (0, 1) ? odpoczynek : partner->odpoczynek;
	  nowy =
	    new Wampirzec (PobierzPolozenieX (), PobierzPolozenieY (), j, z,
			   o);
	}
      ++ilosc_wampirzcow;
    }

  odpoczynek =
    odpoczynek_minimalny +
    (int) (odpoczynek_minimalny * odpoczynek_a_jurnosc * jurnosc);
  partner->odpoczynek =
    odpoczynek_minimalny +
    (int) (odpoczynek_minimalny * odpoczynek_a_jurnosc * jurnosc);

  return nowy;
}
