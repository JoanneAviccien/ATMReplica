#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bankmodules.h"

int main()
{	
	//Kamus Data
	waktu saatini;
	akun loaded;
	akun input;

	getsaatini(&saatini.tgl, &saatini.bln, &saatini.thn);
	Logo();
	masukKartuATM();
	login(&loaded);
	return 0;
}