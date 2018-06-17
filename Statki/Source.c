#include "Menu.h"
#include <vld.h>

int main(int argc, char **argv[])
{
	if (argc == 1)
		menu();
	else if (argc == 3)
		wczytywanie_gry_z_wiersza_polecen(argv);
	else printf("Blad podczas otwierania gry");
	system("PAUSE");
	return 0;
}