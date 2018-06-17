#include "Ukladanie_statkow.h"

void rozstaw(gracz *g)
{
	system("cls");
	printf("Tura: %s\n", g->nazwa);
	system("PAUSE");

	ustaw_statek4(g);
	ustaw_statek3(g);
	ustaw_statek2(g);
	ustaw_statek1(g);
}

void ustaw_statek4(gracz *g)
{
	char i = "*";
	int j = 1, licz = 15;
	char k[1] = "*";
	int true = 1;
	while (true)
	{
		system("cls");
		wyswietl_t_plansze(*g);
		printf("Jak chcesz ustawic swoj cztero masztowiec?(Pozostalo %d):\n1.Poziomo\n2.Pionowo\n", (g->statek4));
		scanf_s("%c", &i, sizeof(int));
		switch (i)
		{


		case '1':
			printf("W ktorej kolumie?(Podaj litere A-G)\n");
			scanf_s("%s", &k, 2);

			switch (k[0])
			{
			case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g':
				printf("W ktorym wierszu?(Podaj cyfre 0-9)\n");
				int w;
				scanf_s("%d", &w, sizeof(int));
				switch (w)
				{
				case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
					w = w + 1;
					k[0] = tolower(k[0]);
					licz = k[0] - 'a' + 1;
					for (j = licz; j < licz + 4; j++)
					{
						g->t_plansza[w][j] = statek;
					}
					true = 0;
					break;
				default:
					("Sprobuj ponownie\n");
					break;
				}
				break;
			default:
				printf("Sprobuj ponownie\n");
				break;
			}
			break;



		case '2':
			printf("W ktorej kolumie?(Podaj litere A-J)\n");
			scanf_s("%s", &k, 2);

			switch (k[0])
			{
			case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h': case 'I': case 'i': case 'J': case 'j':
				printf("W ktorym wierszu?(Podaj cyfre 0-6)\n");
				int w;
				scanf_s("%d", &w, sizeof(int));
				switch (w)
				{
				case 0: case 1: case 2: case 3: case 4: case 5: case 6:
					w = w + 1;
					k[0] = tolower(k[0]);
					licz = k[0] - 'a' + 1;
					for (j = w; j < w + 4; j++)
					{
						g->t_plansza[j][licz] = statek;
					}
					true = 0;
					break;
				default:
					("Sprobuj ponownie\n");
					break;
				}
				break;
			default:
				printf("Sprobuj ponownie\n");
				break;
			}
			break;
			break;
		default:
			printf("Sprobuj ponownie\n");
			break;
		}
	}

}

void ustaw_statek3(gracz *g)
{
	char i = "*";
	int j = 0, licz = 10, liczba_statkow=0;
	char k[1] = "*";
	for (liczba_statkow = 0; liczba_statkow < g->statek3; liczba_statkow++) 
	{
		int true = 1;
		while (true)
		{
			system("cls");
			wyswietl_t_plansze(*g);
			printf("Jak chcesz ustawic swoj troj masztowiec?(Pozostalo %d):\n1.Poziomo\n2.Pionowo\n", (g->statek3 - liczba_statkow));
			scanf_s("%c", &i, sizeof(int));

			switch (i)
			{


			case '1':
				printf("W ktorej kolumie?(Podaj litere A-H)\n");
				scanf_s("%s", &k, 2);
				switch (k[0])
				{
				case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h':
					printf("W ktorym wierszu?(Podaj cyfre 0-9)\n");
					int w;
					scanf_s("%d", &w, sizeof(int));
					switch (w)
					{
					case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
						w = w + 1;
						k[0] = tolower(k[0]);
						licz = k[0] - 'a' + 1;
						if (g->t_plansza[w][licz] != statek &&
							g->t_plansza[w - 1][licz] != statek &&
							g->t_plansza[w + 1][licz] != statek &&
							g->t_plansza[w][licz - 1] != statek &&
							g->t_plansza[w - 1][licz - 1] != statek &&
							g->t_plansza[w + 1][licz - 1] != statek &&
							g->t_plansza[w][licz + 1] != statek &&
							g->t_plansza[w - 1][licz + 1] != statek &&
							g->t_plansza[w + 1][licz + 1] != statek &&
							g->t_plansza[w][licz + 2] != statek &&
							g->t_plansza[w - 1][licz + 2] != statek &&
							g->t_plansza[w + 1][licz + 2] != statek &&
							g->t_plansza[w][licz + 3] != statek &&
							g->t_plansza[w - 1][licz + 3] != statek &&
							g->t_plansza[w + 1][licz + 3] != statek
							)
						{
							for (j = licz; j < licz + 3; j++)
							{
								g->t_plansza[w][j] = statek;
							}
							true = 0;
						}
						break;
					default:
						("Sprobuj ponownie\n");
						break;
					}
					break;
				default:
					printf("Sprobuj ponownie\n");
					break;
				}
				break;



			case '2':
				printf("W ktorej kolumie?(Podaj litere A-J)\n");
				scanf_s("%s", &k, 2);
				switch (k[0])
				{
				case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h': case 'I': case 'i': case 'J': case 'j':
					printf("W ktorym wierszu?(Podaj cyfre 0-7)\n");
					int w;
					scanf_s("%d", &w, sizeof(int));
					switch (w)
					{
					case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
						w = w + 1;
						k[0] = tolower(k[0]);
						licz = k[0] - 'a' + 1;
						if (g->t_plansza[w][licz] != statek &&
							g->t_plansza[w - 1][licz] != statek &&
							g->t_plansza[w + 1][licz] != statek &&
							g->t_plansza[w][licz - 1] != statek &&
							g->t_plansza[w - 1][licz - 1] != statek &&
							g->t_plansza[w + 1][licz - 1] != statek &&
							g->t_plansza[w][licz + 1] != statek &&
							g->t_plansza[w - 1][licz + 1] != statek &&
							g->t_plansza[w + 1][licz + 1] != statek &&
							g->t_plansza[w + 2][licz] != statek &&
							g->t_plansza[w + 2][licz + 1] != statek &&
							g->t_plansza[w + 2][licz - 1] != statek &&
							g->t_plansza[w + 3][licz] != statek &&
							g->t_plansza[w + 3][licz - 1] != statek &&
							g->t_plansza[w + 3][licz + 1] != statek
							)
						{
							for (j = w; j < w + 3; j++)
							{
								g->t_plansza[j][licz] = statek;
							}
							true = 0;
						}
						break;
					default:
						("Sprobuj ponownie\n");
						break;
					}
					break;
				default:
					printf("Sprobuj ponownie\n");
					break;
				}
				break;
				break;
			default:
				printf("Sprobuj ponownie\n");
				break;
			}
		}
	}

}

void ustaw_statek2(gracz *g)
{
	char i = "*";
	int j = 0, licz = 10, liczba_statkow = 0;
	char k[1] = "*";
	for (liczba_statkow = 0; liczba_statkow < g->statek2; liczba_statkow++)
	{
		int true = 1;
		while (true)
		{
			system("cls");
			wyswietl_t_plansze(*g);
			printf("Jak chcesz ustawic swoj dwu masztowiec?(Pozostalo %d):\n1.Poziomo\n2.Pionowo\n", (g->statek2 - liczba_statkow));
			scanf_s("%c", &i, sizeof(char));
			switch (i)
			{


			case '1':
				printf("W ktorej kolumie?(Podaj litere A-I)\n");
				scanf_s("%s", &k, 2);
				switch (k[0])
				{
				case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h': case 'I': case 'i':
					printf("W ktorym wierszu?(Podaj cyfre 0-9)\n");
					int w;
					scanf_s("%d", &w, sizeof(int));
					switch (w)
					{
					case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
						w = w + 1;
						k[0] = tolower(k[0]);
						licz = k[0] - 'a' + 1;
						if (g->t_plansza[w][licz] != statek &&
							g->t_plansza[w - 1][licz] != statek &&
							g->t_plansza[w + 1][licz] != statek &&
							g->t_plansza[w][licz - 1] != statek &&
							g->t_plansza[w - 1][licz - 1] != statek &&
							g->t_plansza[w + 1][licz - 1] != statek &&
							g->t_plansza[w][licz + 1] != statek &&
							g->t_plansza[w - 1][licz + 1] != statek &&
							g->t_plansza[w + 1][licz + 1] != statek &&
							g->t_plansza[w][licz + 2] != statek &&
							g->t_plansza[w - 1][licz + 2] != statek &&
							g->t_plansza[w + 1][licz + 2] != statek 
							)
						{
							for (j = licz; j < licz + 2; j++)
							{
								g->t_plansza[w][j] = statek;
							}
							true = 0;
						}
						break;
					default:
						("Sprobuj ponownie\n");
						break;
					}
					break;
				default:
					printf("Sprobuj ponownie\n");
					break;
				}
				break;



			case '2':
				printf("W ktorej kolumie?(Podaj litere A-J)\n");
				scanf_s("%s", &k, 2);
				switch (k[0])
				{
				case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h': case 'I': case 'i': case 'J': case 'j':
					printf("W ktorym wierszu?(Podaj cyfre 0-8)\n");
					int w;
					scanf_s("%d", &w, sizeof(int));
					switch (w)
					{
					case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
						w = w + 1;
						k[0] = tolower(k[0]);
						licz = k[0] - 'a' + 1;
						if (g->t_plansza[w][licz] != statek &&
							g->t_plansza[w - 1][licz] != statek &&
							g->t_plansza[w + 1][licz] != statek &&
							g->t_plansza[w][licz - 1] != statek &&
							g->t_plansza[w - 1][licz - 1] != statek &&
							g->t_plansza[w + 1][licz - 1] != statek &&
							g->t_plansza[w][licz + 1] != statek &&
							g->t_plansza[w - 1][licz + 1] != statek &&
							g->t_plansza[w + 1][licz + 1] != statek &&
							g->t_plansza[w + 2][licz] != statek &&
							g->t_plansza[w + 2][licz + 1] != statek &&
							g->t_plansza[w + 2][licz - 1] != statek 
							)
						{
							for (j = w; j < w + 2; j++)
							{
								g->t_plansza[j][licz] = statek;
							}
							true = 0;
						}
						break;
					default:
						("Sprobuj ponownie\n");
						break;
					}
					break;
				default:
					printf("Sprobuj ponownie\n");
					break;
				}
				break;
				break;
			default:
				printf("Sprobuj ponownie\n");
				break;
			}
		}
	}

}

void ustaw_statek1(gracz *g)
{
	int i = 0, j = 0, licz = 10, liczba_statkow = 0;
	char k[1] = "*";
	for (liczba_statkow = 0; liczba_statkow < g->statek1; liczba_statkow++)
	{
		int true = 1;
		while (true)
		{
			system("cls");
			wyswietl_t_plansze(*g);
			printf("Gdzie chcesz ustawic swoj jednomasztowiec? (Pozostalo %d)\n", (g->statek1-liczba_statkow));
			printf("W ktorej kolumie?(Podaj litere A-J)\n");
			scanf_s("%s", &k, 2);

			switch (k[0])
			{
			case 'A': case 'a': case 'B': case 'b': case 'C':case 'c': case 'D': case 'd': case 'E': case 'e': case 'F': case 'f': case 'G': case 'g': case 'H': case 'h': case 'I': case 'i': case 'J': case 'j':
				printf("W ktorym wierszu?(Podaj cyfre 0-9)\n");
				int w;
				scanf_s("%d", &w, sizeof(int));
				switch (w)
				{
				case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
					w = w + 1;
					k[0] = tolower(k[0]);
					licz = k[0] - 'a' + 1;
					if (g->t_plansza[w][licz] != statek && 
						g->t_plansza[w][licz - 1] != statek &&
						g->t_plansza[w][licz + 1] != statek &&
						g->t_plansza[w-1][licz] != statek && 
						g->t_plansza[w-1][licz-1] != statek && 
						g->t_plansza[w-1][licz+1] != statek && 
						g->t_plansza[w+1][licz] != statek && 
						g->t_plansza[w+1][licz-1] != statek && 
						g->t_plansza[w+1][licz+1] != statek)
					{
						g->t_plansza[w][licz] = statek;
						true = 0;
					}
					break;
				default:
					("Sprobuj ponownie\n");
					break;
				}
				break;
			default:
				printf("Sprobuj ponownie\n");
				break;
			}
		}
	}

}