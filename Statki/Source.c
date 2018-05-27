#include <stdio.h>
//#include "Statki.h"
#include "Ukladanie_statkow.h"

#define PUSTE "  "
#define PUDLO " ○"
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
	int i = 0;
	int j = 0;
	printf("\n\nPlansza przeciwnika:\n");
	printf("  A B C D E F G H I J\n");
	for (i = 1; i < 11; i++)
	{
		printf("%d", i-1);
		for (j = 1; j < 11; j++)
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
				printf(PUSTE);
				break;
			}
		printf("\n");
	}
	printf("\n");
}



int main()
{
	gracz gracz1 = {
	.nazwa = "GRACZ NR 1",
	.twoja_tura = 1,
	.t_plansza = { puste },
	.p_plansza = { puste },
	.statek4 = 1,
	.statek3 = 2,
	.statek2 = 3,
	.statek1 = 4
	};

	gracz gracz2 = {
		.nazwa = "GRACZ NR 2",
		.twoja_tura = 0,
		.t_plansza = { puste },
		.p_plansza = { puste },
		.statek4 = 1,
		.statek3 = 2,
		.statek2 = 3,
		.statek1 = 4
	};
	//Wypelnianie planszy
	system("cls");
	printf("Tura gracza pierwszego\n");
	system("PAUSE");
	ustaw_statek4(&gracz1);
	ustaw_statek3(&gracz1);
	ustaw_statek2(&gracz1);
	ustaw_statek1(&gracz1);


	system("cls");
	printf("Tura gracza drugiego\n");
	system("PAUSE");
	ustaw_statek4(&gracz2);
	ustaw_statek3(&gracz2);
	ustaw_statek2(&gracz2);
	ustaw_statek1(&gracz2);
	//-----------------------------------------------------------------

	int i = 0;
	int j = 0;
	//Przepisanie tablicy przeciwnik na tablice p_plansza
	for (i = 1; i < 11; i++)
		for (j = 1; j < 11; j++)
			gracz1.p_plansza[i][j] = gracz2.t_plansza[i][j];
	for (i = 1; i < 11; i++)
		for (j = 1; j < 11; j++)
			gracz2.p_plansza[i][j] = gracz1.t_plansza[i][j];
	//-----------------------------------------------------------------
	wyswietl_plansze(gracz1);
	system("PAUSE");
	return 0;
}