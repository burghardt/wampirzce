#ifndef __KOLONIA_H__
#define __KOLONIA_H__

#include <list>
#include "wampirzec.h"

using namespace std;

extern const unsigned int wampirzcow_na_poczatku;

class Kolonia
{
public:
  Kolonia (void);
  void ChwilaZycia (void);
private:
  list <Wampirzec*> stado;
  unsigned long long int iteracji;
};

#endif
