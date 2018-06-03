#include <stdio.h>
#include "Ukladanie_statkow.h"
#include "Wyswietlanie_planszy.h"
#include "Obsluga_plikow.h"
#include "Statki.h"

int main(int argc, char **argv[])
{
	char m = "*";
	gracz *gracz1 = nowy_gracz();
	gracz *gracz2 = nowy_gracz();
	gracz1->nazwa = "Gracz nr 1";
	gracz2->nazwa = "Gracz nr 2";
	printf("MENU\n");
	int gra = 1;
	printf("%d.Nowa gra\n",gra);
	gra += 1;
	printf("%d.Wczytaj gre\n", gra);
	gra += 1;
	printf("%d.Exit\n", gra);
	gra = 1;
	scanf_s("%c", &m, sizeof(char));
	switch (m)
	{
	case '1':
		//--------------------------------------------Wypelnianie planszy
		rozpoczecie_gry(gracz1, gracz2);
		break;
	case '2':
		wczytywanie_gry(gracz1);
		wczytywanie_gry(gracz2);
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
		break;
	case '3':
		gra = 0;
		break;
	}
	while (gra==1)
	{
		if (gracz1->twoja_tura == 1)
		{
			ruch(gracz1, gracz2);
			if (gracz2->pozostale_statki < 0)
			{
				system("cls");
				printf("Wygral: %s\n", gracz1->nazwa);
				gra = 0;
			}
		}
		ruch(gracz2, gracz1);
		if (gracz1->pozostale_statki < 0)
		{
			system("cls");
			printf("Wygral: %s\n", gracz2->nazwa);
			gra = 0;
		}
	}
	free(gracz1);
	free(gracz2);
	usuwanie_pliku(gracz1);
	usuwanie_pliku(gracz2);
	system("PAUSE");
	return 0;
}