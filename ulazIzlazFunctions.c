#define _CRT_SECURE_NO_WARNINGS
#include "UlazIzlaz.h"
#include "Standard.h"

void zapisiRezultat(IGRAC* igrac) {
	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);
	podaci = dodajIgracaNaKraj(podaci, igrac);
	zapisiUDatoteku(podaci->igraci, podaci->brojIgraca, SCORE_FILE_NAME);
}

BAZA* ucitajPodatkeIzDatoteke(const char* imeDat) {
	BAZA* podaci = (BAZA*)malloc(sizeof(BAZA));
	podaci->brojIgraca = citajBrojIzDatoteke(imeDat);
	podaci->igraci = citajIzDatoteke(imeDat);
	return podaci;
}

int citajBrojIzDatoteke(char* imeDatoteke) {

	FILE* ljestvica = fopen(imeDatoteke, "rb");

	if (ljestvica == NULL) {
		return 0;
	}

	int brojacIgraca;
	fread(&brojacIgraca, sizeof(int), 1, ljestvica);
	fclose(ljestvica);

	return brojacIgraca;
}

IGRAC* citajIzDatoteke(char* imeDat) {

	FILE* ljestvica = fopen(imeDat, "rb");
	if (ljestvica == NULL) {
		return NULL;
	}

	int brojacIgraca;
	fread(&brojacIgraca, sizeof(int), 1, ljestvica);

	IGRAC* igraci = (IGRAC*)malloc(brojacIgraca * sizeof(IGRAC));
	fread(igraci, sizeof(IGRAC), brojacIgraca, ljestvica);

	fclose(ljestvica);
	return igraci;
}

BAZA* dodajIgracaNaKraj(BAZA* podaci, IGRAC* igrac) {
	BAZA* noviPodaci = (BAZA*)malloc(sizeof(BAZA));
	noviPodaci->brojIgraca = podaci->brojIgraca + 1;
	noviPodaci->igraci = (IGRAC*)malloc(noviPodaci->brojIgraca * sizeof(IGRAC));

	kopirajIgrace(noviPodaci, podaci);

	noviPodaci->igraci[noviPodaci->brojIgraca - 1] = *igrac;

	free(podaci);
	return noviPodaci;
}

void kopirajIgrace(BAZA* novi, BAZA* stari) {
	for (int i = 0; i < stari->brojIgraca; i++) {
		novi->igraci[i] = stari->igraci[i];
	}
}

void zapisiUDatoteku(IGRAC* igraci, int brojacIgraca, char* imeDat) {

	FILE* ljestvica = fopen(imeDat, "wb");
	if (ljestvica == NULL) {
		perror("Nije se mogla otvoriti datoteka!");
		exit(-1);
	}
	fwrite(&brojacIgraca, sizeof(int), 1, ljestvica);
	fwrite(igraci, sizeof(IGRAC), brojacIgraca, ljestvica);


	fclose(ljestvica);

}