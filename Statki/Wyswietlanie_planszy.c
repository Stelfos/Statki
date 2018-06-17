#include "Wyswietlanie_planszy.h"

void wyswietl_t_plansze(gracz g)
{
	printf("%s\n\n", g.nazwa);
	printf("Twoja plansza:\n");
	printf("  A B C D E F G H I J\n");
	int i = 0;
	int j = 0;
	for (i = 1; i < 11; i++)
	{
		printf("%d", i - 1);
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
		printf("%d", i - 1);
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
	printf("Pozostalo %d pol do trafienia\n\n", g.pozostale_statki+1);
	wyswietl_t_plansze(g);
	wyswietl_p_plansze(g);
}
