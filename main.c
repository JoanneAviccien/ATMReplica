#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bankmodules.h"

int main()
{	
	//Kamus Data
	waktu saatini;
	akun loaded;
	limit loadedlim;
	mutasi monthly;
	mutasi yearly;
	char retry;


	system("cls");
	Logo();
	getsaatini(&saatini.tgl, &saatini.bln, &saatini.thn);
	masukKartuATM();
	login(&loaded, &loadedlim, &monthly, &yearly);

	menu:
	if(loaded.statuskartu == 1)
	{
		system("cls");
		menu(loaded, loadedlim, monthly, yearly);
	} else
	{
		exit(1);
	}

	retryinput:
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
		goto retryinput;
	}

	return 0;
}