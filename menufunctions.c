#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Standard.h"
#include "ZapocniVjesala.h"
#include "Sortiranje.h"
#include "Pretrazivanje.h"
#include "UlazIzlaz.h"

void menu() {

	int inputOption;

	do {
		printMenu();

		scanf("%d", &inputOption); getchar();

		switch (inputOption) {

		case 1:
			zapocniVjesala();
			break;
		case 2:
			sortiranjeIgraca();
			break;
		case 3:
			pretrazivanjeIgraca();
			break;
		case 4:
			ispisHighScorea();
			break;
		case 5:
			exit(EXIT_SUCCESS);
			break;
		default:
			puts("Ta operacija ne postoji!\n");
			break;
		}

	} while (inputOption != 5);

}

void printMenu() {
	system("cls");
	printf("\n                   ============================================================================ ");
	printf("\n                   <>    <>     <><>     <>    <>    <>>>>>    <>      <>     <><>     <>    <> ");
	printf("\n                   <>    <>    <>  <>    <>>>  <>   <>    <>   <>>>  <<<>    <>  <>    <>> > <> ");
	printf("\n                   <><<>><>   <><<>><>   <> <> <>   <>         <> <<>> <>   <><<>><>   <> <> <> ");
	printf("\n                   <>    <>   <>    <>   <>  <<<>   <>  <<<<   <>  <>  <>   <>    <>   <>  <<<> ");
	printf("\n                   <>    <>   <>    <>   <>    <>    <>>>>>    <>      <>   <>    <>   <>    <> ");
	printf("\n                   ============================================================================ ");
	printf("\n");
	printf("\n");
	printf("                   -----------------------------------MENU------------------------------------- \n");
	printf("\n");
	printf("                                                1: Start\n");
	printf("                                                2: Sortiranje igraca\n");
	printf("                                                3: Pretrazivanje igraca\n");
	printf("                                                4: Ispis highscorea\n");
	printf("                                                5: Izlaz\n");
	printf("\n");
	printf("                   ---------------------------------------------------------------------------- \n");
	printf("                                                Izaberite opciju: ");
}

void ispisHighScorea() {

	system("cls");

	BAZA* podaci = ucitajPodatkeIzDatoteke(SCORE_FILE_NAME);

	if (podaci->igraci == NULL) {
		perror("Datoteka ne postoji");
		return;
	}

	bubbleSortBodoviSilazno(podaci->igraci, podaci->brojIgraca);
	for (int i = 0; i < 10; i++) {

		printf("%d. Ime: %s\n", i + 1, podaci->igraci[i].ime);
		printf("   Prezime: %s\n", podaci->igraci[i].prezime);
		printf("   Bodovi: %d\n", podaci->igraci[i].bodovi);
		printf("\n");
	}
	printf("Pritisnite bilo koju tipku za povratak u izbornik!");
	getch();

}