#define _CRT_SECURE_NO_WARNINGS
#include "Igrac.h"
#include "Sortiranje.h"
#include "Standard.h"
#include "UlazIzlaz.h"

void sortiranjeIgraca() {
	system("cls");
	int inputOption;

	do {
		sortMenu();
		scanf("%d", &inputOption); getchar();

		switch (inputOption) {

		case 1: {
			printf("Sortiranje igraca po bodovima (silazno):\n");
			ispisLjestvicePoBodovimaSilazno();
			break;
		}
		case 2: {
			printf("Sortiranje igraca po bodovima (uzlazno):\n");
			ispisLjestvicePoBodovimaUzlazno();
			break;
		}
		case 3: {
			printf("Sortiranje igraca po imenu:\n");
			ispisLjestvicePoImenima();
			break;
		}
		case 4: {
			printf("Sortiranje igraca po prezimenu:\n");
			ispisLjestvicePoPrezimenima();
			break;
		}
		case 5:
			system("cls");
			return;

		default:
			puts("Ta operacija ne postoji!\n");
			break;
		}

	} while (inputOption != 5);
}

void sortMenu() {
	printf("\n");
	printf("----------------MENU------------------\n");
	printf("1: Sortiraj igrace po bodovima silazno\n");
	printf("2: Sortiraj igrace po bodovima uzlazno\n");
	printf("3. Sortiraj igrace po imenu\n");
	printf("4: Sortiraj igrace po prezimenu\n");
	printf("5: Izlaz\n");
	printf("--------------------------------------\n");
	printf("\n");
	printf("Izaberite opciju: ");
}

void swap(IGRAC* a, IGRAC* b) {
	IGRAC temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSortBodoviUzlazno(IGRAC* igraci, int brojIgraca) {
	for (int i = 0; i < brojIgraca - 1; i++) {
		for (int j = 0; j < brojIgraca - i - 1; j++) {
			if (igraci[j].bodovi > igraci[j + 1].bodovi) {
				swap(&igraci[j], &igraci[j + 1]);
			}
		}
	}
}

void bubbleSortBodoviSilazno(IGRAC* igraci, int brojIgraca) {
	for (int i = 0; i < brojIgraca - 1; i++) {
		for (int j = 0; j < brojIgraca - i - 1; j++) {
			if (igraci[j].bodovi < igraci[j + 1].bodovi) {
				swap(&igraci[j], &igraci[j + 1]);
			}
		}
	}
}

void bubbleSortIme(IGRAC* igraci, int brojIgraca) {
	for (int i = 0; i < brojIgraca - 1; i++) {
		for (int j = 0; j < brojIgraca - i - 1; j++) {
			if (strcmp(igraci[j].ime, igraci[j + 1].ime) > 0) {
				swap(&igraci[j], &igraci[j + 1]);
			}
		}
	}
}

void bubbleSortPrezime(IGRAC* igraci, int brojIgraca) {
	for (int i = 0; i < brojIgraca - 1; i++) {
		for (int j = 0; j < brojIgraca - i - 1; j++) {
			if (strcmp(igraci[j].prezime, igraci[j + 1].prezime) > 0) {
				swap(&igraci[j], &igraci[j + 1]);
			}
		}
	}
}

void ispisLjestvicePoBodovimaUzlazno() {

	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);

	bubbleSortBodoviUzlazno(podaci->igraci, podaci->brojIgraca);

	for (int i = 0; i < podaci->brojIgraca; i++) {
		printf("\n%d.  Bodovi: %d\n", i + 1, podaci->igraci[i].bodovi);
		printf("    Ime: %s\n", podaci->igraci[i].ime);
		printf("    Prezime: %s\n", podaci->igraci[i].prezime);
	}
}

void ispisLjestvicePoBodovimaSilazno() {
	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);

	bubbleSortBodoviSilazno(podaci->igraci, podaci->brojIgraca);

	for (int i = 0; i < podaci->brojIgraca; i++) {
		printf("\n%d.  Bodovi: %d\n", i + 1, podaci->igraci[i].bodovi);
		printf("    Ime: %s\n", podaci->igraci[i].ime);
		printf("    Prezime: %s\n", podaci->igraci[i].prezime);
	}
}

void ispisLjestvicePoImenima() {
	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);

	bubbleSortIme(podaci->igraci, podaci->brojIgraca);

	for (int i = 0; i < podaci->brojIgraca; i++) {
		printf("\n%d.  Ime: %s\n", i + 1, podaci->igraci[i].ime);
		printf("    Prezime: %s\n", podaci->igraci[i].prezime);
		printf("    Bodovi: %d\n", podaci->igraci[i].bodovi);
	}
}

void ispisLjestvicePoPrezimenima() {
	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);

	bubbleSortPrezime(podaci->igraci, podaci->brojIgraca);

	for (int i = 0; i < podaci->brojIgraca; i++) {
		printf("\n%d.  Prezime: %s\n", i + 1, podaci->igraci[i].prezime);
		printf("    Ime: %s\n", podaci->igraci[i].ime);
		printf("    Bodovi: %d\n", podaci->igraci[i].bodovi);
	}
}