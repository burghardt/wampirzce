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
  virtual void Przesun (unsigned char, const double) = 0;
private:
  double x;
  double y;
};

#endif
