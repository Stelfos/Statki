#include <stdio.h>
//#include "Statki.h"
#include "Ukladanie_statkow.h"

#define PUSTE "  "
#define PUDLO " O"
#define STATEK " #"
#define TRAFIENIE " X"

void wyswietl_t_plansze(gracz g)
{
	printf("%s\n\n", g.nazwa);
	printf("Twoja plansza:\n");
	printf("  A B C D E F G H I J\n");
	int i = 0;
	int j = 0;
	for (i = 1; i < 11; i++)
	{
		printf("%d", i-1);
		for (j = 1; j < 11; j++)
		{
			switch (g.t_plansza[i][j])
			{
			case puste:
				printf(PUSTE);
				break;
			case pudlo:
				printf(PUDLO);
				break;
			case trafienie:
				printf(TRAFIENIE);
				break;
			case statek:
				printf(STATEK);
				break;
			}

		}
		printf("\n");
	}
	printf("\n");
}

void wyswietl_p_plansze(gracz g)
{
	printf("\n\nPlansza przeciwnika:\n");
	printf("  A B C D E F G H I J\n");
	int i = 0;
	int j = 0;
	for (i = 1; i < 11; i++)
	{
		printf("%d", i-1);
		for (j = 1; j < 11; j++)
			switch (g.p_plansza[i][j])
			{
			case puste:
				printf(PUSTE);
				break;
			case pudlo:
				printf(PUDLO);
				break;
			case trafienie:
				printf(TRAFIENIE);
				break;
			case statek:
				printf(PUSTE);
				break;
			}
		printf("\n");
	}
	printf("\n");
}

void wyswietl_plansze(gracz g)
{
	system("cls");
	printf("Pozostalo %d pol do trafienia\n\n", g.pozostale_statki);
	wyswietl_t_plansze(g);
	wyswietl_p_plansze(g);

}

void strzelaj(gracz *g, gracz *g2)
{
	char *k, koordynaty[3];
	int true = 1;
	while (true)
	{
		printf("Gdzie chcesz strzelic?\n(podaj koordynaty, najpierw kolumne potem wiersz np. A0)\n");
		k = malloc(sizeof(char*));
		k = fgets(koordynaty, 3 , stdin);
		if (k != NULL)
		{
			int i, j;
			switch (koordynaty[0])
			{
			case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h': case 'I': case 'i':
				koordynaty[0] = tolower(koordynaty[0]);
				j = koordynaty[0] - 'a' + 1;
				i = koordynaty[1] - 48 + 1;
				printf("%d", g->p_plansza[i][j]);
				switch (g->p_plansza[i][j])
				{
				case puste:
					g->p_plansza[i][j] = pudlo;
					g2->t_plansza[i][j] = pudlo;
					true = 0;
					break;
				case statek:
					g->p_plansza[i][j] = trafienie;
					g->pozostale_statki = g->pozostale_statki - 1;
					g2->t_plansza[i][j] = trafienie;
					true = 0;
					break;
				case pudlo: case trafienie:
					printf("Juz tu strzelales\n");
				default:
					printf("Sprubuj ponownie\n");
					break;
				}
			default:
				break;
			}
		}
	}
}

int main()
{
	char m="*";
	gracz gracz1 =
	{
		.nazwa = "GRACZ NR 1",
		.twoja_tura = 1,
		.t_plansza = { puste },
		.p_plansza = { puste },
		.statek4 = 1,
		.statek3 = 2,
		.statek2 = 3,
		.statek1 = 4,
		.pozostale_statki = 19
	};

	gracz gracz2 = {
		.nazwa = "GRACZ NR 2",
		.twoja_tura = 0,
		.t_plansza = { puste },
		.p_plansza = { puste },
		.statek4 = 1,
		.statek3 = 2,
		.statek2 = 3,
		.statek1 = 4,
		.pozostale_statki = 19
	};
	printf("MENU\n");
	printf("1.Gra dwuosobowa\n");
	//printf("2.Gra z komputerem\n");
	scanf_s("%c", &m, sizeof(char));
	switch (m)
	{
	case '1':
		//--------------------------------------------Wypelnianie planszy
		system("cls");
		printf("Tura gracza pierwszego\n");
		system("PAUSE");
		//ustaw_statek4(&gracz1);
		//ustaw_statek3(&gracz1);
		//ustaw_statek2(&gracz1);
		ustaw_statek1(&gracz1);


		system("cls");
		printf("Tura gracza drugiego\n");
		system("PAUSE");
		//ustaw_statek4(&gracz2);
		//ustaw_statek3(&gracz2);
		//ustaw_statek2(&gracz2);
		ustaw_statek1(&gracz2);
		//-----------------------------------------------------------------

		int i = 0;
		int j = 0;
		//--------------Przepisanie tablicy przeciwnik na tablice p_plansza
		for (i = 1; i < 11; i++)
			for (j = 1; j < 11; j++)
				gracz1.p_plansza[i][j] = gracz2.t_plansza[i][j];
		for (i = 1; i < 11; i++)
			for (j = 1; j < 11; j++)
				gracz2.p_plansza[i][j] = gracz1.t_plansza[i][j];
		//-----------------------------------------------------------------
		while (1)
		{
			wyswietl_plansze(gracz1);
			strzelaj(&gracz1, &gracz2);
			if (gracz1.pozostale_statki < 0)
			{
				system("cls");
				printf("Wygral gracz NR 1\n");
				break;
			}
			wyswietl_plansze(gracz2);
			strzelaj(&gracz2, &gracz1);
			if (gracz2.pozostale_statki < 0)
			{
				system("cls");
				printf("Wygral gracz NR 2\n");
				break;
			}
		}
		system("PAUSE");
		break;
	case '2':

	default:
		break;
	}
	return 0;
}