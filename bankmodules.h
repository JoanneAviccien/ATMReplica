#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char nokartu[16];
    char pin[6];
    char norek[10];
    int saldo;
    int tipekartu;
    char nama[25];
    bool statuskartu;
} akun;

typedef struct
{
    char norektujuan[10];
    char namatujuan[25];
} datastruk;

typedef struct
{
    int keluar;
    int masuk;
    int saldo;
} mutasi;

#endif