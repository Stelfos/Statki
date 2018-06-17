#include "Obsluga_plikow.h"

void zapisz_stan_gry(gracz *g)
{
	FILE *plik;
	if(g->nazwa == "Gracz nr 1")
		fopen_s(&plik, "Gracz_nr_1.txt", "w");
	else fopen_s(&plik, "Gracz_nr_2.txt", "w");
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


int wczytywanie_gry(gracz *g)
{
	FILE *plik;
	if (g->nazwa == "Gracz nr 1")
		fopen_s(&plik, "Gracz_nr_1.txt", "r");
	else fopen_s(&plik, "Gracz_nr_2.txt", "r");
	if (plik != NULL)
	{
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
		return 1;
	}
	else
	{
		return 0;
	}
}

int wczytywanie_gry_z_wiersza_polecen(char **argv)
{
	gracz *gracz1 = nowy_gracz();
	gracz *gracz2 = nowy_gracz();
	gracz1->nazwa = "Gracz nr 1";
	gracz2->nazwa = "Gracz nr 2";
	int gra = 1;
	FILE *plik1;
	FILE *plik2;
	fopen_s(&plik1, argv[0] , "r");
	fopen_s(&plik2, argv[1], "r");
	if (plik1 != NULL && plik2 != NULL)
	{
		fscanf_s(plik1, "%1d", &gracz1->twoja_tura);
		fscanf_s(plik2, "%1d", &gracz2->twoja_tura);
		int i, j;
		for (i = 0; i < 12; i++)
			for (j = 0; j < 12; j++)
			{
				fscanf_s(plik1, "%1d", &gracz1->t_plansza[i][j]);
				fscanf_s(plik1, "%1d", &gracz1->p_plansza[i][j]);
				fscanf_s(plik2, "%1d", &gracz2->t_plansza[i][j]);
				fscanf_s(plik2, "%1d", &gracz2->p_plansza[i][j]);
			}
		fscanf_s(plik1, "%d", &gracz1->pozostale_statki);
		fscanf_s(plik2, "%d", &gracz2->pozostale_statki);
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
		usuwanie_pliku(gracz1);
		usuwanie_pliku(gracz2);
		free(gracz1);
		free(gracz2);
	}
	else printf("Brak pliku do wczytania");
	fclose(plik1);
	fclose(plik2);
}

void usuwanie_pliku(gracz *g)
{
	if (g->nazwa == "Gracz nr 1")
		remove("Gracz_nr_1.txt");
	else remove("Gracz_nr_2.txt");
}