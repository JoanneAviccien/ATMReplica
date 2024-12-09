#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bankmodules.h"

int main()
{	
	//Kamus Data
	waktu saatini;
	akun loaded;
	datket transaksi;
	limit loadedlim;
	char retry;


	system("cls");
	Logo();
	getsaatini(&saatini.tgl, &saatini.bln, &saatini.thn);
	masukKartuATM();
	login(&loaded, &loadedlim);

	menu:
	if(loaded.statuskartu == 1)
	{
		system("cls");
		menu(loaded, transaksi, loadedlim);
	} else
	{
		exit(1);
	}
	printf("\nLakukan Transaksi Lagi? (Y/N) ");
	retry = fgetc(stdin);
	fflush(stdin);
	if(retry == 'Y' || retry == 'y' || retry == '\n')
	{

		goto menu;

	} else if(retry == 'N' || retry == 'n')
	{

		exit(1);

	} else
	{
		printf("\nMasukan opsi yang sesuai!\n'Y' Untuk kembali melakukan transaksi\n'N' Untuk keluar");
		exit(1);
	}

	return 0;
}