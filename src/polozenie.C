/*
   polozenie.C - implementacja abstrakcyjnej klasy polozenie

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

// $Id: polozenie.C,v 1.2 2004-02-05 00:14:38 einstein Exp $

#include <iostream>
#include "polozenie.h"

using namespace std;

Polozenie::Polozenie (const double _x, const double _y)
{
  x = _x;
  y = _y;

  return;
}

double
Polozenie::PobierzPolozenieX (void)
{
  return x;
}

double
Polozenie::PobierzPolozenieY (void)
{
  return y;
}

void
Polozenie::UstawPolozenieXY (const double _x = 0, const double _y = 0)
{
  if (_x > 0 && _x < wielkosc_ekosystemu_x)
    x = _x;
  if (_y > 0 && _y < wielkosc_ekosystemu_y)
    y = _y;

  return;
}
