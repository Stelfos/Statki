#pragma once
#include <stdio.h>
#include "Statki.h"

void zapisz_stan_gry(gracz *g);
int wczytywanie_gry(gracz *g);
int wczytywanie_gry_z_wiersza_polecen(char **argv);
void usuwanie_pliku(gracz *g);