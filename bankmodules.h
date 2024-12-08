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
    int tgl;
    int bln;
    int thn;
} waktu;

typedef struct
{
    char nokartu[17];
    int transaksi[2];
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

void newmonthlymutasi(mutasi inm);

void newyearlymutasi(mutasi iny);

void resettahun(char carikartu[17], mutasi in, waktu saatini);

void resetbulan(char carikartu[17], mutasi in, waktu saatini);

void getsaatini(int*hari, int* bulan, int* tahun);

void gettgl(int * tgl);

void getbln(int * bln);

void getthn(int * thn);

void opsimutasi(mutasi mon, mutasi year);

void menu(akun loaded, limit loadedlim, mutasi monthly, mutasi yearly);

void generatornokartu(char nokartu[17]);

void generatornorek(char norek[11]);

void buatakun(akun * new);

void login(akun* diload, limit* loadedlim, mutasi* monthly, mutasi* yearly);

void masukKartuATM();

int VA(int* saldo);

void tarikTunai(akun saldo, akun * kondisibaru);

void cekSaldo(int saldo);

void OpsiBank(akun loaded, akun * kondisibaru, limit in, limit* outlim);

void transferBCA(akun saldo, akun * kondisibaru, limit in, limit* outlim);

void transferother(akun saldo, akun * kondisibaru, limit in, limit* outlim);

void setorTunai(akun saldo, akun * kondisibaru);

int Biayaadmin(int saldo, int tipekartu);

void newPW();

void changePW(char pin[7]);

void changegmail(char kriteriaemail[50],char emailbaru[50]);

void MenuPelayanan();

void pembayaranPDAM(akun saldo, akun * kondisibaru);

void pembayaranPLN(akun saldo, akun * kondisibaru);

void pembayaranPajak(akun saldo, akun * kondisibaru);

void pembayaranPulsa(akun saldo, akun * kondisibaru);

void pembayaranTagihan(akun saldo, akun * kondisibaru);

void pembayaranTagihan(akun saldo, akun * kondisibaru);

void informasi(akun read);

#endif