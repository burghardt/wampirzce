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
