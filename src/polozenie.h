/*
   polozenie.h - interfejs abstrakcyjnej klasy polozenie

   This file is part of Wampirzce.
   Copyright (C) 2004 Krzysztof Burghardt.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __POLOZENIE_H__
#define __POLOZENIE_H__

using namespace std;

extern const unsigned int wielkosc_ekosystemu_x;
extern const unsigned int wielkosc_ekosystemu_y;

class Polozenie
{
protected:
  Polozenie (const double, const double);
  double PobierzPolozenieX (void);
  double PobierzPolozenieY (void);
  void UstawPolozenieXY (const double, const double);
private:
  double x;
  double y;
};

#endif
