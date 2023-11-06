#ifndef ULAZ_IZLAZ_H
#define ULAZ_IZLAZ_H

#include "Igrac.h"

void zapisiUDatoteku(IGRAC* igraci, int brojacIgraca, char* imeDat);
BAZA* ucitajPodatkeIzDatoteke(const char* imeDat);
int citajBrojIzDatoteke(char* polje);
IGRAC* citajIzDatoteke(char* polje);
BAZA* dodajIgracaNaKraj(BAZA* podaci, IGRAC* igrac);
void kopirajIgrace(BAZA* novi, BAZA* stari);
void zapisiRezultat(IGRAC* igrac);

#endif // !ULAZ_IZLAZ_H

