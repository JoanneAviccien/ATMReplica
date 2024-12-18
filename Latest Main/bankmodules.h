#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

typedef struct
{
    char nokartu[17];
	char gmail[50];
    char pin[7];
    char norek[11];
    int saldo;
    int tipekartu;
    char nama[50];
    bool statuskartu;
} akun;

typedef struct
{
    char norektujuan[10];
    char namatujuan[25];
} datastruk;

typedef struct
{
    char nokartu[17];
    int keluar;
    int masuk;
    int keterangan;
} mutasi;

void getsaatini(int* bulan, int* tahun);

void getketerangan(int ket, char outket[19]);

void opsimutasi();

void masukKartuATM();

int menu();

void MenuPelayanan();

void generatornokartu(char nokartu[17]);

void generatornorek(char norek[11]);

void buatakun(akun * new);

void getstatus(int statuskartu, char cekstatus[10]);

void gettipe(int tipekartu, char cektipe[9]);

void blokirkartu(akun* kartu);

void login(char *nokartu, char *pin);

int Opsibhs ();
 
void tarikTunai(int *saldo, int* pengeluaran, int* keterangan);

void cekSaldo(int saldo);

char OpsiBank();

void transferBCA(int *saldo, int* pengeluaran, int* keterangan);

void transferother(int *saldo, int* pengeluaran, int* keterangan);

void setorTunai(int *saldo, int* pemasukan, int* keterangan);

int Biayaadmin(int saldo, int tipekartu);

char newPW();

char changePW(char pin[7]);

void pembayaranPDAM(int *saldo, int* pengeluaran, int* keterangan);

void pembayaranPLN(int *saldo, int* pengeluaran, int* keterangan);

void pembayaranPajak(int *saldo, int* pengeluaran, int* keterangan);

void pembayaranPulsa(int *saldo, int* pengeluaran, int* keterangan);

void pembayaranTagihan(int *saldo, int* pengeluaran,int* keterangan);

void cetakStruk(datastruk struk, int jumlahTransaksi);

void VA(int* saldo, int* pengeluaran, int* keterangan);

char NextorNot();
#endif