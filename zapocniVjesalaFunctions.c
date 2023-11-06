#define _CRT_SECURE_NO_WARNINGS
#include "ZapocniVjesala.h"
#include "Menu.h"
#include "Standard.h"
#include "UlazIzlaz.h"

void pokusajPonovno(int brojBodova)
{
	char da[] = "da";
	char ne[] = "ne";

	char odluka[3];
	printf("\n                                          Broj ostvarenih bodova: %d\n", brojBodova);
	printf("Pokusaj ponovno?\nUpisite 'da' ili 'ne':\n\n"); //Opcija da pokusamo ponovno odigrati Hangman ako nismo zadovoljni s dobivenim bodovima

	scanf("%s", &odluka);
	if (_strcmpi(da, odluka) == 0)                            //ako upisemo "da" ponovno se pokrece Hangman
	{
		zapocniVjesala();
	}
	else if (_strcmpi(ne, odluka) == 0) {
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		printf("\nUnos neispravan. Mozete upisati samo 'da' ili 'ne':\n\n");              //ako upisemo nesto sto nije "da" ili "ne" 
		pokusajPonovno(brojBodova);
	}
}

void zapocniVjesala() {
	system("cls");
	IGRAC igrac;

	printf("Upisi ime igraca: ");
	scanf("%s", igrac.ime);
	printf("Upisi prezime igraca: ");
	scanf("%s", igrac.prezime);

	system("cls");
	while ((getchar()) != '\n');

	printf("                                         Dobrodosli u igru vjesala!\n");
	printf("	            Upisite slovo za pogadanje rijeci ili 'izlaz' ako zelite izaci iz igre!\n\n");
	printf("\n ___________.._______ ");
	printf("\n| .__________))______| ");
	printf("\n| | / /      || ");
	printf("\n| |/ /       || ");
	printf("\n| | /        ||_ _ _ ");
	printf("\n| |/         |/  _  \\ ");
	printf("\n| |          ||  `/,| ");
	printf("\n| |          (\\`_.'/");
	printf("\n| |          /Y ..Y\\ ");
	printf("\n| |        // |   | \\\\ ");
	printf("\n| |       //  | . |  \\\\ ");
	printf("\n| |      ')   |   |   (` ");
	printf("\n| |           ||'|| ");
	printf("\n| |           || || ");
	printf("\n| |           || || ");
	printf("\n| |           || || ");
	printf("\n| |          / | | \\ ");
		
	srand(time(NULL));

	char RandomRijeci[][16] = { "riba", "stolica", "osijek", "jazz", "papir", "hrvatska", "more" };        //sve rijeci koje se mogu pojaviti u igri Hangman
	int RandomIndeks = rand() % 7;                                           //random odabir navedenih rijeci
	int BrojZivota = 5;
	int BrojBodova = 0;
	int BrojTocnih = 0;
	int StariTocni = 0;                                                //pomoc pri odredivanju netocnih slova
	int DuljinaRijeci = strlen(RandomRijeci[RandomIndeks]);
	int Pogadanje[7] = { 0, 0, 0, 0, 0, 0, 0 };                       //polje pri kojem se gleda individualno slovo u rijeci
	int Izlaz = 0;
	int i = 0;
	char Pogodak[16];                                                 //Unos
	char UnesenoSlovo;
	while (BrojTocnih < DuljinaRijeci)                      //hangman igra, sve dok je broj pogodenih slova manji od duljine slova rijeci nismo pogodili cijelu rijec
	{
		printf("\n\n\n");
		for (i = 0; i < DuljinaRijeci; i++)
		{
			if (Pogadanje[i] == 1)
			{
				printf("%c ", RandomRijeci[RandomIndeks][i]);         //ako smo pogodili slovo ono ce biti ispisano na konzoli
			}
			else
			{
				printf("_ ");                                         //u suprotnom ostaju prazna mjesta
			}
		}
		printf("\n\nBroj zivota: %d\n", BrojZivota);
		printf("Broj bodova: %d\n\n", BrojBodova);
		printf("Unesite slovo: ");
		fgets(Pogodak, 16, stdin);
		system("cls");
		printf("                                         Dobrodosli u igru vjesala!\n");
		printf("	            Upisite slovo za pogadanje rijeci ili 'izlaz' ako zelite izaci iz igre!\n\n");
		printf("\n ___________.._______ ");
		printf("\n| .__________))______| ");
		printf("\n| | / /      || ");
		printf("\n| |/ /       || ");
		printf("\n| | /        ||_ _ _ ");
		printf("\n| |/         |/  _  \\ ");
		printf("\n| |          ||  `/,| ");
		printf("\n| |          (\\`_.'/");
		printf("\n| |          /Y ..Y\\ ");
		printf("\n| |        // |   | \\\\ ");
		printf("\n| |       //  | . |  \\\\ ");
		printf("\n| |      ')   |   |   (` ");
		printf("\n| |           ||'|| ");
		printf("\n| |           || || ");
		printf("\n| |           || || ");
		printf("\n| |           || || ");
		printf("\n| |          / | | \\ ");

		if (strncmp(Pogodak, "izlaz", 5) == 0)                       //unosenje rijeci "izlaz" izlazimo iz while petlje
		{
			Izlaz = 1;
			break;
		}
		UnesenoSlovo = Pogodak[0];
		StariTocni = BrojTocnih;
		for (i = 0; i < DuljinaRijeci; i++)                          //for petlja vrti za duljinu rijeci
		{
			if (Pogadanje[i] == 1)
			{
				continue;
			}
			if (UnesenoSlovo == RandomRijeci[RandomIndeks][i])        //ako se uneseno slovo podudara sa nekim slovom u rijeci pogodili smo slovo i dobili bodove
			{
				Pogadanje[i] = 1;
				BrojTocnih++;
				BrojBodova += 65;
			}
		}
		if (StariTocni == BrojTocnih)                                 //ako broj pogodenih slova ostane isti to znaci da nismo pogodili slovo i oduzimaju nam se bodovi
		{
			BrojZivota--;
			BrojBodova -= 35;
			if (BrojZivota == 0)                                      //ako nam ponestane zivota izgubili smo
			{
				break;
			}
		}
	}
	if (Izlaz == 1)                                                          //izlazenje iz programa
	{
		system("cls");
	}
	else if (BrojZivota == 0)                                                    //ako nam ponestane pokusaja(zivota) izgubili smo
	{
		system("cls");
		printf("                   ---------------------------------------------------------------------------- \n");
		printf("                                    NAZALOST IZGUBILI STE, RIJEC JE BILA: %s\n", RandomRijeci[RandomIndeks]);
		printf("                   ---------------------------------------------------------------------------- \n");
		igrac.bodovi = BrojBodova;
		zapisiRezultat(&igrac);
		pokusajPonovno(BrojBodova);
	}
	else                                                                              //u suprotnom smo pobijedili
	{
		system("cls");
		printf("                   ---------------------------------------------------------------------------- \n");
		printf("                                   CESTITAM, POBIJEDILI STE!! RIJEC JE BILA: %s\n", RandomRijeci[RandomIndeks]);
		printf("                   ---------------------------------------------------------------------------- \n");
		igrac.bodovi = BrojBodova;
		zapisiRezultat(&igrac);
		pokusajPonovno(BrojBodova);
	}
	return BrojBodova;
}