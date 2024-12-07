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
    int transaksi;
    char ket[19];
} datket;

typedef struct
{
    int tgl;
    int bln;
    int thn;
} waktu;

typedef struct
{
    char nokartu[17];
    datket datatf;
    waktu timemutasi;
} mutasi;

void Logo();

void saveakun(akun write);

void sloadkartu(char carikartu[17], akun * foundacc);

void ssavekartu(char carikartu[17], akun insertacc);

void blokirakun(char kartu[17]);

void bukablokirakun(char kartu[17]);

void monthlymutasi();

void yearlymutasi();

void getsaatini(int*hari, int* bulan, int* tahun);

void opsimutasi();

void menu(akun loaded, datket out);

void generatornokartu(char nokartu[17]);

void generatornorek(char norek[11]);

void buatakun(akun * new);

void gettipe(int tipekartu, char cektipe[9]);

void login(akun* diload);

void masukKartuATM();

int VA(int* saldo, datket info);

void tarikTunai(akun saldo, datket info, akun * kondisibaru);

void cekSaldo(int saldo);

char OpsiBank();

void transferBCA(akun saldo, datket info, akun * kondisibaru);

void transferother(akun saldo, datket info, akun * kondisibaru);

void setorTunai(akun saldo, datket info, akun * kondisibaru);

int Biayaadmin(int saldo, int tipekartu);

void newPW();

void changePW(char pin[7]);

void changegmail(char kriteriaemail[50],char emailbaru[50]);

void MenuPelayanan();

void pembayaranPDAM(akun saldo, datket info, akun * kondisibaru);

void pembayaranPLN(akun saldo, datket info, akun * kondisibaru);

void pembayaranPajak(akun saldo, datket info, akun * kondisibaru);

void pembayaranPulsa(akun saldo, datket info, akun * kondisibaru);

void pembayaranTagihan(akun saldo, datket info, akun * kondisibaru);

void pembayaranTagihan(akun saldo, datket info, akun * kondisibaru);

void informasi(akun read);

#endif