#include "Statki.h"
#include "Ukladanie_statkow.h"
#include "Obsluga_plikow.h"

gracz *nowy_gracz()
{
	gracz *nowy;
	nowy = malloc(sizeof(gracz));
	nowy->pozostale_statki = 19;
	int i, j;
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++)
		{
			nowy->t_plansza[i][j] = puste;
		}
	nowy->statek1 = 4;
	nowy->statek2 = 3;
	nowy->statek3 = 2;
	nowy->statek4 = 1;
	return nowy;
}

void rozpoczecie_gry(gracz *gracz1,gracz *gracz2)
{
	gracz1->twoja_tura = 1;
	gracz2->twoja_tura = 0;
	rozstaw(gracz1);
	rozstaw(gracz2);
	//--------------Przepisanie tablicy przeciwnik na tablice t_plansza
	int i, j;
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++)
		{
			gracz1->p_plansza[i][j] = gracz2->t_plansza[i][j];
			gracz2->p_plansza[i][j] = gracz1->t_plansza[i][j];
		}
	zapisz_stan_gry(gracz1);
	zapisz_stan_gry(gracz2);
}

void ruch(gracz *g1, gracz *g2)
{
	g1->twoja_tura = 1;
	g2->twoja_tura = 0;
	system("cls");
	printf("Tura: %s\n", g1->nazwa);
	wyswietl_plansze(g1);
	strzelaj(g1, g2);
	g1->twoja_tura = 0;
	g2->twoja_tura = 1;
	zapisz_stan_gry(g1);
	zapisz_stan_gry(g2);
}

void strzelaj(gracz *g, gracz *g2)
{
	char *k, koordynaty[3];
	int true = 1;
	while (true)
	{
		printf("Gdzie chcesz strzelic?\n(podaj koordynaty, najpierw kolumne potem wiersz np. A0)\n");
		k = malloc(sizeof(char*));
		k = fgets(koordynaty, 3, stdin);
		if (k != NULL)
		{
			int i, j;
			switch (koordynaty[0])
			{
			case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h': case 'I': case 'i':
				koordynaty[0] = tolower(koordynaty[0]);
				j = koordynaty[0] - 'a' + 1;
				i = koordynaty[1] - 48 + 1;
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