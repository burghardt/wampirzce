/*
   wampirzec.h - interfejs klasy wampirzec

   This file is part of Wampirzce.
   Copyright (C) 2004, 2023 Krzysztof Burghardt.

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

#ifndef __WAMPIRZEC_H__
#define __WAMPIRZEC_H__

#include <list>
#include <random>
#include "polozenie.h"

using namespace std;

static int
getrandom (int min = 0, int max = std::numeric_limits<int>::max())
{
  static std::random_device rd;
  static std::mt19937 rgen(rd());
  std::uniform_int_distribution<> unidistr(min, max);

  return unidistr(rgen);
}

extern const unsigned int wielkosc_ekosystemu_x;
extern const unsigned int wielkosc_ekosystemu_y;
extern const unsigned int pojemnosc_srodowiska;
extern const unsigned int jurnosc_minimalna;
extern const unsigned int jurnosc_maksymalna;
extern const unsigned int zycie_minimalne;
extern const unsigned int zycie_a_jurnosc;
extern const unsigned int odpoczynek_minimalny;
extern const double odpoczynek_a_jurnosc;
extern const unsigned int prawdopodobienstwo_mutacji;
extern const double prawdopodobienstwo_mutacji_a_jurnosc;
extern const double szybkosc_a_jurnosc;

class Wampirzec:private Polozenie
{
public:
  Wampirzec (const double _x = getrandom (0, wielkosc_ekosystemu_x),
             const double _y = getrandom (0, wielkosc_ekosystemu_y),
             const double _jurnosc =
             getrandom (jurnosc_minimalna, jurnosc_maksymalna),
             const unsigned int _zycie =
             zycie_minimalne + getrandom (0, zycie_minimalne),
             const unsigned int _odpoczynek = odpoczynek_minimalny);
  Wampirzec *ChwilaZycia (const list < Wampirzec * >);
  bool CzyMartwy (void);
  void UstawIloscWampirzcow (const unsigned int);
protected:
  void Przesun (const unsigned char, const double);
  double Odleglosc (Wampirzec *);
  void Odpocznij (void);
  Wampirzec *SzukajPartnera (list < Wampirzec * >);
  Wampirzec *RozmnazajSie (Wampirzec *);
private:
  double jurnosc;
  unsigned int zycie;
  unsigned int odpoczynek;
  static unsigned int ilosc_wampirzcow;
};

#endif
