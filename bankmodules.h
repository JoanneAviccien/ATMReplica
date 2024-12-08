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

void sloadkartu(char carikartu[17], akun * foundacc);

void ssavekartu(char carikartu[17], akun insertacc);

void blokirakun(char kartu[17]);

void bukablokirakun(char kartu[17]);

void printtahun(mutasi display);

void printbulan(mutasi display);

void newmonthlymutasi(mutasi inm);

void newyearlymutasi(mutasi iny);

void sloadperbulan(char carikartu[17], mutasi* outm);

void sloadpertahun(char carikartu[17], mutasi* outy);

void ssavepertahunmasuk(char carikartu[17], mutasi iny);

void ssaveperbulanmasuk(char carikartu[17], mutasi inm);

void ssavepertahunkeluar(char carikartu[17], mutasi iny);

void ssaveperbulankeluar(char carikartu[17], mutasi inm);

void resettahun(char carikartu[17], mutasi in, waktu saatini);

void resetbulan(char carikartu[17], mutasi in, waktu saatini);

void getsaatini(int*hari, int* bulan, int* tahun);

void opsimutasi(mutasi mon, mutasi year);

void tarikTunai(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monthly, mutasi* yearly);

int VA(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout);

void cekSaldo(int saldo);

void savelimit(limit in);

void sloadlimit(char carikartu[17], limit * output);

void ssavelimit(char carikartu[17], limit input);

void resetlimit(char carikartu[17], limit in, waktu hariini);

int ceklimit(akun in, limit inlim);

void transferBCA(akun saldo, akun * kondisibaru, limit in, limit* outlim, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout);

void transferother(akun saldo, akun * kondisibaru, limit in, limit* outlim, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout);

void OpsiBank(akun loaded, akun * kondisibaru, limit in, limit* outlim, mutasi monin, mutasi yearin, mutasi* monthly, mutasi* yearly);

void pembayaranPDAM(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout);

void pembayaranPLN(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin,mutasi* monout , mutasi* yearout);

void pembayaranPajak(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin,mutasi* monout , mutasi* yearout);

void pembayaranPulsa(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout);

void pembayaranTagihan(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout);

void setorTunai(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monthly, mutasi* yearly);

void newPW(akun edit);

void changePW(akun edit);

void changegmail(akun edit);

void MenuPelayanan(akun in);

void informasi(akun read);

void menu(akun loaded, limit loadedlim, mutasi monthly, mutasi yearly);

void gettgl(int * tgl);

void getbln(int * bln);

void getthn(int * thn);

void generatornokartu(char nokartu[17]);

void generatornorek(char norek[11]);

void buatakun(akun * new);

void login(akun* diload, limit* loadedlim, mutasi* monthly, mutasi* yearly);

void masukKartuATM();

int Biayaadmin(int saldo, int tipekartu);

#endif