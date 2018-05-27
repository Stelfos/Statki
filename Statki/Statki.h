#pragma once
#include <stdio.h>

enum pole { puste, pudlo, trafienie, statek }; //0 na polu nic nie ma, 1 na polu jest statek, 2 pudlo, 3 trafienie

typedef struct Gracz
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