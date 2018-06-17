#include "Menu.h"

void menu()
{
	char m;
	gracz *gracz1 = nowy_gracz();
	gracz *gracz2 = nowy_gracz();
	gracz1->nazwa = "Gracz nr 1";
	gracz2->nazwa = "Gracz nr 2";
	int gra;			//warunek zakonczenia gry gra==0
	int menu = 1;
	do {
		//-----MENU-----------------------
		printf("MENU\n");
		gra = 1;
		printf("%d.Nowa gra\n", gra);
		gra += 1;
		printf("%d.Wczytaj gre\n", gra);
		gra += 1;
		printf("%d.Exit\n", gra);
		gra = 1;
		//--------------------------------
		scanf_s("%c", &m, sizeof(char));
		switch (m)
		{
		case '1':
			//--------------------------------------------Wypelnianie planszy
			rozpoczecie_gry(gracz1, gracz2);
			gra = 1;
			break;
		case '2':
			if (wczytywanie_gry(gracz1) == 1 && wczytywanie_gry(gracz2) == 1) //sprawdza czy jest jakas gra ktora mozna wczytac
			{
				if (gracz1->twoja_tura == 1)
				{
					system("cls");
					printf("Tura: %s\n", gracz1->nazwa);
					system("PAUSE");
				}
				else
				{
					system("cls");
					printf("Tura: %s\n", gracz2->nazwa);
					system("PAUSE");
				}
				gra = 1;
			}
			else
			{
				system("cls");
				printf("Brak gry do wczytania\n");
				Sleep(1000);
				system("cls");
				gra = 0;
			}
			break;
		case '3':
			gra = 0;
			menu = 0;
			break;
		default:
			gra = 0;
			break;
		}

		while (gra == 1)
		{
			if (gracz1->twoja_tura == 1)
			{
				ruch(gracz1, gracz2);
				if (gracz1->pozostale_statki < 0)
				{
					system("cls");
					printf("Wygral: %s\n", gracz1->nazwa);
					gra = 0;
					break;
				}
			}
			ruch(gracz2, gracz1);
			if (gracz2->pozostale_statki < 0)
			{
				system("cls");
				printf("Wygral: %s\n", gracz2->nazwa);
				gra = 0;
			}
		}
		scanf_s("%c", &m, sizeof(char)); // "czyszczenie" bufora
		usuwanie_pliku(gracz1);
		usuwanie_pliku(gracz2);
	} while (menu == 1);
	free(gracz1);
	free(gracz2);
}