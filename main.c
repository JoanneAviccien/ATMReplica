#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "bankmodules.h"

int main()
{	

	akun loaded;
	akun input;

	Logo();
	masukKartuATM();
	login(char *nokartu, char *pin);
	menu(void);
	return 0;
}