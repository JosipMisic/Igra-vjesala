#ifndef IGRAC_H
#define IGRAC_H

typedef struct igrac {
	char ime[20];
	char prezime[20];
	int bodovi;
}IGRAC;

typedef struct baza {
	IGRAC* igraci;
	int brojIgraca;
}BAZA;

#endif // IGRAC_H

