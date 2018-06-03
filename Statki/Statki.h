#pragma once
#include <stdio.h>
#include <stdlib.h>

enum pole { puste, pudlo, trafienie, statek }; //0 na polu nic nie ma, 1 na polu jest statek, 2 pudlo, 3 trafienie

typedef struct
{
	char *nazwa;
	int twoja_tura;  //true/fasle w zaleznosci od tego czyja tura
	int t_plansza[12][12]; //plansza gracze
	int p_plansza[12][12]; // plansza przeciwnika
	// liczba dotepnych statkow
	int statek4;
	int statek3;
	int statek2;
	int statek1;
	//-------------------------
	int pozostale_statki;
}gracz;

gracz *nowy_gracz();

void ruch(gracz *g1, gracz *g2);

void rozpoczecie_gry(gracz *gracz1, gracz *gracz2);

void strzelaj(gracz *g, gracz *g2);