/*
   kolonia.h - interfejs klasy kolonia

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

// $Id: kolonia.h,v 1.4 2004-02-24 00:13:18 einstein Exp $

#ifndef __KOLONIA_H__
#define __KOLONIA_H__

#include <list>
#include "wampirzec.h"

using namespace std;

extern unsigned int wielkosc_okna_x;
extern unsigned int wielkosc_okna_y;
extern const unsigned int wielkosc_ekosystemu_x;
extern const unsigned int wielkosc_ekosystemu_y;
extern const unsigned int wampirzcow_na_poczatku;

class Kolonia
{
public:
  Kolonia (void);
  void ChwilaZycia (void);
private:
    list < Wampirzec * >stado;
  unsigned long long int iteracji;
};

#endif
