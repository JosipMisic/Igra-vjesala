#define _CRT_SECURE_NO_WARNINGS
#include "Pretrazivanje.h"
#include "Standard.h"
#include "UlazIzlaz.h"

void pretrazivanjeIgraca() {
	system("cls");
	int inputOption;

	do {

		pretraziMeni();

		scanf("%d", &inputOption); getchar();

		switch (inputOption) {

		case 1: {

			int bodovi;
			printf("Upisi broj bodova igraca: ");
			scanf("%d", &bodovi);

			IGRAC* igracsnajvisebodova = pretrazivanjeIgracaPoBodovima(bodovi);

			if (igracsnajvisebodova == NULL) {
				printf("Igrac ne postoji.\n");
			}
			else {
				printf("Igrac s imenom %s ima %d bodova.\n", igracsnajvisebodova->ime, igracsnajvisebodova->bodovi);
			}

			break;
		}
		case 2: {

			char imeIgraca[20];
			printf("Upisi ime igraca: ");
			scanf("%s", imeIgraca);

			IGRAC* igracsimenom = pretrazivanjeIgracaPoImenu(imeIgraca);

			if (igracsimenom == NULL) {
				printf("Igrac ne postoji.\n");
			}
			else {
				printf("Igrac s imenom %s ima %d bodova.\n", igracsimenom->ime, igracsimenom->bodovi);
			}

			break;
		}
		case 3: {
			char prezimeIgraca[20];
			printf("Upisi prezime igraca: ");
			scanf("%s", prezimeIgraca);

			IGRAC* igracsprezimenom = pretrazivanjeIgracaPoPrezimenu(prezimeIgraca);

			if (igracsprezimenom == NULL) {
				printf("Igrac ne postoji.\n");
			}
			else {
				printf("Igrac s prezimenom %s ima %d bodova.\n", igracsprezimenom->prezime, igracsprezimenom->bodovi);
			}

			break;
		}
		case 4:
			system("cls");
			return;

		default:
			puts("Ta operacija ne postoji!\n");
			break;
		}

	} while (inputOption != 4);
}

void pretraziMeni() {
	printf("\n");
	printf("-------------MENU--------------\n");
	printf("1. Pretrazi igrace po bodovima\n");
	printf("2. Pretrazi igrace po imenu\n");
	printf("3. Pretrazi igrace po prezimenu\n");
	printf("4. Izlaz\n");
	printf("-------------------------------\n");
	printf("\n");
	printf("Izaberite opciju: ");
}

IGRAC* pretrazivanjeIgracaPoBodovima(int bodovi) {
	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);

	for (int i = 0; i < podaci->brojIgraca; i++) {
		if (podaci->igraci[i].bodovi == bodovi) {
			return &podaci->igraci[i];
		}
	}

	return NULL;

}

IGRAC* pretrazivanjeIgracaPoImenu(char* imeIgraca) {

	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);

	for (int i = 0; i < podaci->brojIgraca; i++) {
		if (strcmp(podaci->igraci[i].ime, imeIgraca) == 0) {
			return &podaci->igraci[i];
		}
	}

	return NULL;

}

IGRAC* pretrazivanjeIgracaPoPrezimenu(char* prezimeIgraca) {

	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);

	for (int i = 0; i < podaci->brojIgraca; i++) {
		if (strcmp(podaci->igraci[i].prezime, prezimeIgraca) == 0) {
			return &podaci->igraci[i];
		}
	}

	return NULL;

}