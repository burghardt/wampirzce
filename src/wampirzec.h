#ifndef __WAMPIRZEC_H__
#define __WAMPIRZEC_H__

#include <list>
#include <sys/time.h>
#include "polozenie.h"

using namespace std;

inline int
rnd(void)
{
        static struct timeval tv;
        gettimeofday(&tv, 0);
        srandom(tv.tv_sec * tv.tv_usec);
        return random() % (RAND_MAX + 1);
}

#define getrandom(min, max) ((rnd() % (int)(((max)+1) - (min))) + (min))

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

class Wampirzec : private Polozenie
{
public:
  Wampirzec (const double _x = getrandom(0, wielkosc_ekosystemu_x),
	     const double _y = getrandom(0, wielkosc_ekosystemu_y),
	     const double _jurnosc = getrandom(jurnosc_minimalna, jurnosc_maksymalna),
	     const unsigned int _zycie = zycie_minimalne + getrandom(0, zycie_minimalne),
	     const unsigned int _odpoczynek = odpoczynek_minimalny);
  Wampirzec* ChwilaZycia ( const list < Wampirzec * >);
  bool CzyMartwy (void);
protected:
  void Przesun ( const unsigned char, const double);
  double Odleglosc (Wampirzec *);
  void Odpocznij (void);
  Wampirzec* SzukajPartnera (list < Wampirzec * >);
  Wampirzec* RozmnazajSie (Wampirzec *);
private:
  double jurnosc;
  unsigned int zycie;
  unsigned int odpoczynek;
  static unsigned int ilosc_wampirzcow;
};

#endif
