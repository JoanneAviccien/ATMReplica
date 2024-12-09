#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

#define TIPE1 10000000
#define TIPE2 20000000
#define TIPE3 50000000

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

typedef struct
{
    char nokartu[17];
    int tgl;
    int tfhariini;
} limit;

void Logo();

void saveakun(akun write);

void savelimit(limit in);

void sloadlimit(char carikartu[17], limit * output);

void ssavelimit(char carikartu[17], limit input);

void resetlimit(limit in, waktu hariini);

int ceklimit(akun in, limit inlim);

void sloadkartu(char carikartu[17], akun * foundacc);

void ssavekartu(char carikartu[17], akun insertacc);

void blokirakun(char kartu[17]);

void bukablokirakun(char kartu[17]);

void monthlymutasi();

void yearlymutasi();

void getsaatini(int*hari, int* bulan, int* tahun);

void opsimutasi();

void menu(akun loaded, datket out, limit loadedlim);

void generatornokartu(char nokartu[17]);

void generatornorek(char norek[11]);

void buatakun(akun * new);

void login(akun* diload, limit* loadedlim);

void masukKartuATM();

int VA(int* saldo, datket info);

void tarikTunai(akun saldo, datket info, akun * kondisibaru);

void cekSaldo(int saldo);

void OpsiBank(akun loaded, datket out, akun * kondisibaru, limit in, limit* outlim);

void transferBCA(akun saldo, datket out, akun * kondisibaru, limit in, limit* outlim);

void transferother(akun saldo, datket out, akun * kondisibaru, limit in, limit* outlim);

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