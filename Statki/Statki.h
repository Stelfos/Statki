#pragma once
#include <stdio.h>
#include <stdlib.h>

enum pole { puste, pudlo, trafienie, statek }; //0 na polu nic nie ma, 1 na polu jest statek, 2 pudlo, 3 trafienie

typedef struct
{
	char *nazwa;	//nazwa gracza
	int twoja_tura;  //true/fasle(1/0) w zaleznosci od tego czyja tura

	int t_plansza[12][12]; //plansza gracze - twoja plansza
	int p_plansza[12][12]; // plansza przeciwnika

	// liczba dotepnych statkow
	int statek4;
	int statek3;
	int statek2;
	int statek1;
	//-------------------------

	int pozostale_statki; //liczba statkow ktore nalezy zestrzelic
}gracz;

gracz *nowy_gracz(); //innicjalizacja struktury gracza

void ruch(gracz *g1, gracz *g2);  //tura gracza g1

void rozpoczecie_gry(gracz *gracz1, gracz *gracz2);  //rozstawnianie statkow + 

void strzelaj(gracz *g, gracz *g2); //gracz g oddaje strzal na plansze gracza g2