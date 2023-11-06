#ifndef SORTIRANJE_H
#define SORTIRANJE_H

#include "Igrac.h"

void sortiranjeIgraca();
void sortMenu();
void swap(IGRAC* a, IGRAC* b);

void bubbleSortBodoviUzlazno(IGRAC* igraci, int brojIgraca);
void bubbleSortBodoviSilazno(IGRAC* igraci, int brojIgraca);
void bubbleSortIme(IGRAC* igraci, int brojIgraca);
void bubbleSortPrezime(IGRAC* igraci, int brojIgraca);

void ispisLjestvicePoBodovimaUzlazno();
void ispisLjestvicePoBodovimaSilazno();
void ispisLjestvicePoImenima();
void ispisLjestvicePoPrezimenima();

#endif // SORTIRANJE_H


