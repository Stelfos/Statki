#include "Obsluga_plikow.h"

void zapisz_stan_gry(gracz *g)
{
	FILE *plik;
	if(g->nazwa == "Gracz nr 1")
		fopen_s(&plik, "Gracz nr 1.txt", "w");
	else fopen_s(&plik, "Gracz nr 2.txt", "w");
	fprintf(plik, "%1d", g->twoja_tura);
	int i, j;
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++)
		{
			fprintf(plik, "%1d", g->t_plansza[i][j]);
			fprintf(plik, "%1d", g->p_plansza[i][j]);
		}
	fprintf(plik, "%d", g->pozostale_statki);
	fclose(plik);
}


void wczytywanie_gry(gracz *g)
{
	FILE *plik;
	if (g->nazwa == "Gracz nr 1")
		fopen_s(&plik, "Gracz nr 1.txt", "r");
	else fopen_s(&plik, "Gracz nr 2.txt", "r");
	fscanf_s(plik, "%1d", &g->twoja_tura);
	int i, j;
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++)
		{
			fscanf_s(plik, "%1d", &g->t_plansza[i][j]);
			fscanf_s(plik, "%1d", &g->p_plansza[i][j]);
		}
	fscanf_s(plik, "%d", &g->pozostale_statki);
	fclose(plik);
}

void usuwanie_pliku(gracz *g)
{
	remove("%s.txt", g->nazwa);
}