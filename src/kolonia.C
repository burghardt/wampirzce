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
