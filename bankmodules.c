#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

typedef struct
{
    char nokartu[16];
    char gmail[30];
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

void generatornokartu(char nokartu[16])
{
	int rep1 = 0,batasbawah1 = 0, batasatas1 =9;
    printf("Harap tunggu (Pembuatan nomor kartu)...");
	srand(time(NULL));
	while(rep1 < 16)
	{
		int genkartu = (rand() % (batasatas1 - batasbawah1 + 1)) + batasbawah1;
		char temp[0];
		sprintf(temp, "%d", genkartu);
		nokartu[rep1] = genkartu;
		++rep1;
	}
}

void generatornorek(char norek[10])
{
	int rep2 = 0,batasbawah2 = 0, batasatas2 =9;
    printf("\nHarap tunggu (Pembuatan nomor rekening)...");
    Sleep(2000);
	srand(time(NULL));
	while(rep2 < 10)
	{
		int gennorek = (rand() % (batasatas2 - batasbawah2 + 1)) + batasbawah2;
		char temp[0];
		sprintf(temp, "%d", gennorek);
		norek[rep2] = gennorek;
		++rep2;
	}
}

void buatakun(akun * new)
{
    printf("Masukan nama anda:\n");
    fgets(new->nama, sizeof(new->nama), stdin);
	new->nama[strcspn(new->nama, "\n")] = 0;
    fflush(stdin);
	
	printf("Masukan gmail anda:\n");
    fgets(new->gmail, sizeof(new->gmail), stdin);
	new->gmail[strcspn(new->gmail, "\n")] = 0;
	fflush(stdin);
	
    printf("Masukan pin baru anda (6 digit):\n");
    fgets(new->pin, sizeof(new->pin), stdin);
	new->pin[strcspn(new->pin, "\n")] = 0;
    fflush(stdin);
	
    printf("Pilih tipe kartu anda (Masukan Nomor opsi):\n");
    printf("1.Silver\n");
    printf("2.Gold\n");
    printf("3.Platinum\n");
    scanf("%d", &((* new).tipekartu));
    fflush(stdin);
	
    new->saldo = 50000;
	
    new->statuskartu = true;

    generatornokartu(new->nokartu);
    generatornorek(new->norek);
	
}

void cekstatus(int statuskartu)
{
	char cekstatus[10];

    if(statuskartu == 1)
	{
		strcpy(cekstatus,"Unblocked");
	}
	else if(statuskartu == 0)
	{
		strcpy(cekstatus,"Blocked");
	}
        
}

void cektipe(int tipekartu)
{

    char cektipe[9];
    
    if(tipekartu == 1)
	{
		strcpy(cektipe, "Silver");
	}
	else if (tipekartu == 2)
	{
		strcpy(cektipe, "Gold");
	}
	else if (tipekartu == 3)
	{
		strcpy(cektipe, "Platinum");
	}
    
}

void login()
{
    printf("");
    scanf(""); 
}


int Opsibhs ()
{
    
    char bhs[1];
    printf("Pilih Bahasa\n 1. Inggris\n 2. Indonesia");
    printf("Masukan Pilihan :");
    scanf("%s", bhs);
}
 
void tarikTunai(int *saldo)
{
    int uangDitarik;
    printf("Masukkan Jumlah Uang yang Ingin Ditarik (Kelipatan Rp.50.000): ");
    scanf("%d", &uangDitarik);
    
    if(uangDitarik % 50000 != 0)
    {
        printf("Uang yang dimasukan tidak valid\n");
    }
}

void cekSaldo(int saldo)
{
    printf("Saldo Anda Saat Ini Adalah: Rp.%d", saldo);
}

char OpsiBank()(
    int Opsibank;
    printf("1. Transfer sesama Bank \n 2. Transfer Beda Bank \n");
    printf("Masukkan Pilihan :");
    scanf("%s", Opsibank);
    if(Opsibank == 1){
        transferBCA();
    }else if (Opsibank == 2){
        transferother();
    }else(){
    printf("Input Invalid")
    }

)
int transferBCA(int *saldo)
{

    char norektujuan[20];
    int jumlahTransfer;
    printf("Masukkan Nomor Rekening Tujuan: ");
    scanf("%s",norektujuan);

    printf("Masukkan Jumlah yang Akan Ditransfer: Rp.");
    scanf("%d",&jumlahTransfer);
    
    if(*saldo >= jumlahTransfer)
    {
        *saldo -= jumlahTransfer;
        printf("Transfer Sebesar Rp.%d Ke Rekening %s Berhasil !\n", jumlahTransfer, norektujuan);
        printf("Sisa Saldo Anda Adalah: Rp.%d\n", *saldo);
    } 
    else
    {
            printf("Transfer Gagal. Saldo Anda Tidak Mencukupi");
    }
}

int transferother(int *saldo)
{

    char norektujuan[20];
    int jumlahTransfer;
    printf("Masukkan Nomor Rekening Tujuan: ");
    scanf("%s",norektujuan);

    printf("Masukkan Jumlah yang Akan Ditransfer: Rp.");
    scanf("%d",&jumlahTransfer);
    
    if(*saldo >= jumlahTransfer)
    {
        jumlahTransfer = Jumlah transfer + 2500
        *saldo -= jumlahTransfer;
        printf("Transfer Sebesar Rp.%d Ke Rekening %s Berhasil !\n", jumlahTransfer, norektujuan);
        printf("Sisa Saldo Anda Adalah: Rp.%d\n", *saldo);
    } 
    else
    {
            printf("Transfer Gagal. Saldo Anda Tidak Mencukupi");
    }
}
void setorTunai(int *saldo)
{
    int nominalSetor;

    printf("\nMasukkan Jumlah Uang yang Akan Disetor (Kelipatan Rp.50.000): ");
    scanf("%d",&nominalSetor);

    if(nominalSetor %50000 != 0)
    {
        printf("Jumlah Uang yang Dimasukkan Harus Kelipatan Rp.50.000 !\n");
    }

    *saldo += nominalSetor;
    printf("Setoran Sebesar Rp.%d Berhasil. Saldo Anda Sekarang adalah: Rp.%d\n", nominalSetor, *saldo);
}

int Biayaadmin(int saldo, int tipekartu){
    if(tipekartu == 1){
        saldo = saldo - 10000;
    } 
    else if(tipekartu == 2){
        saldo = saldo - 20000;
    } 
    else
    {
        saldo = saldo - 50000;
    }
    printf("Saldo :", Saldo);
    return saldo;
}

char newPW()
{
    printf("Masukan sandi Baru:");
    scanf("%s", pinbaru);
    printf("Konfirmasi sandi Baru:");
    scanf("%s", pinbaru2);
    int res2 = strcmp(pinbaru, pinbaru2);
    if(res2 == 0){
        strcpy(newpin, pinbaru);
    }
    else
    {
        newPW();
    }
}

char changePW(char pin[6]){
    char pinlama[6];
    char pinbaru[6];
    char pinbaru2[6];
    int i = 1;
    While(i<3){
        printf("Ubah Pin\n");
        printf("Masukan Pin anda  :\n");
        scanf("%s", pinlama);
        int res = strcmp(pinlama, pin);
        if(res == 0){
            printf("Sandi Benar \n");
            i=i+4
        }else(){
            printf("Sandi Salan Masukan Kembali sandi \n");
            i= i+1
        }
        newPW();
    }
}

void pembayaranPDAM(int *saldo)
{
    char nomorPDAM[25];
    int jumlahBayar;
    int biayaAdmin = 2500;

    printf("\n===== Pembayaran PDAM =====\n");
    printf("Masukkan Nomor ID Pelanggan PDAM (Format: PDAMXXXXX):");
    scanf("%s", nomorPDAM);

    if(strncmp(nomorPDAM, "PDAM", 4) != 0)
    {
        printf("Nomor ID Pelanggan Tidak Valid ! Nomor Harus Diawali 'PDAM'\n");
        return;
    }

    printf("Masukkan Jumlah Tagihan yang Akan Dibayar: Rp.");
    scanf("%d", &jumlahBayar);
    
    int totalBayar = jumlahBayar + biayaAdmin;

    if (*saldo >= totalBayar)
    {
        *saldo -= totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : PDAM\n");
        printf("Nomor Tujuan        : %s\n", nomorPDAM);
        printf("Jumlah Tagihan      : Rp.%d\n", jumlahBayar);
        printf("Biaya Administrasi  : Rp.%d\n", biayaAdmin);
        printf("Sisa Saldo Anda     : Rp.%d\n", *saldo);
    }
    else
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Jumlah yang Dibutuhkan  : Rp.%d\n", totalbayar);
        printf("Saldo Anda Saat Ini     : Rp.%d\n", *saldo);
    }
}

void pembayaranPLN(int *saldo)
{
    char nomorPLN[25];
    int jumlahBayar;
    int biayaAdmin = 2500;

    printf("\n===== Pembayaran PLM =====\n");
    printf("Masukkan Nomor ID Pelanggan PLN (Format: PLNXXXXX):");
    scanf("%s", nomorPLN);

    if(strncmp(nomorPLN, "PLN", 3) != 0)
    {
        printf("Nomor ID Pelanggan Tidak Valid ! Nomor Harus Diawali 'PLN'\n");
        return;
    }

    printf("Masukkan Jumlah Tagihan yang Akan Dibayar: Rp.");
    scanf("%d", &jumlahBayar);
    
    int totalBayar = jumlahBayar + biayaAdmin;

    if (*saldo >= totalBayar)
    {
        *saldo -= totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : PLN\n");
        printf("Nomor Tujuan        : %s\n", nomorPLN);
        printf("Jumlah Tagihan      : Rp.%d\n", jumlahBayar);
        printf("Biaya Administrasi  : Rp.%d\n", biayaAdmin);
        printf("Sisa Saldo Anda     : Rp.%d\n", *saldo);
    }
    else
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Jumlah yang Dibutuhkan  : Rp.%d\n", totalbayar);
        printf("Saldo Anda Saat Ini     : Rp.%d\n", *saldo);
    }
}

void pembayaranPajak(int *saldo)
{
    char nomorNPWP[25];
    int jumlahBayar;
    int biayaAdmin = 2500;

    printf("\n===== Pembayaran Pajak =====\n");
    printf("Masukkan Nomor Objek Pajak: ");
    scanf("%s", nomorNPWP);

    printf("Masukkan Jumlah Tagihan yang Akan Dibayar: Rp.");
    scanf("%d", &jumlahBayar);
    
    int totalBayar = jumlahBayar + biayaAdmin;

    if (*saldo >= totalBayar)
    {
        *saldo -= totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : Pajak\n");
        printf("Nomor Tujuan        : %s\n", nomorNPWP);
        printf("Jumlah Tagihan      : Rp.%d\n", jumlahBayar);
        printf("Biaya Administrasi  : Rp.%d\n", biayaAdmin);
        printf("Sisa Saldo Anda     : Rp.%d\n", *saldo);
    }
    else
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Jumlah yang Dibutuhkan  : Rp.%d\n", totalbayar);
        printf("Saldo Anda Saat Ini     : Rp.%d\n", *saldo);
    }
}

void pembayaranPulsa(int *saldo)
{
    char nomorHP[13];
    int jumlahBayar;
    int biaAdmin = 2500;

    printf("\n===== Pembayaran Pulsa ======\n");
    printf("Masukkan Nomor Telepon (Format: 08XXXXXXXXXX): ");
    scanf("%s", nomorHP);

    if(strncmp(nomorHP, "08", 2) != 0)
    {
        printf("Nomor Telepon Tidak Valid! Nomor Harus Diawali '08' dan Maksimal 13 Digit.\n");
        return;
    }

    printf("Masukkan Nominal Pulsa yang Akan Dibeli: Rp.");
    scanf("%d", &jumlahBayar);
    int totalBayar = jumlahBayar + biayaAdmin;

    if(*saldo >= totalBayar)
    {
        *saldo -= totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : Pajak\n");
        printf("Nomor Telepon        : %s\n", nomorHp);
        printf("Jumlah Tagihan      : Rp.%d\n", jumlahBayar);
        printf("Biaya Administrasi  : Rp.%d\n", biayaAdmin);
        printf("Sisa Saldo Anda     : Rp.%d\n", *saldo);
    }
    else
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Jumlah yang Dibutuhkan  : Rp.%d\n", totalbayar);
        printf("Saldo Anda Saat Ini     : Rp.%d\n", *saldo);
    }
}

void pembayaranTagihan(int *saldo)
{
    int pilihan;
    char nomorPDAM[25];
    char nomorPLN[25];
    char nomorNPWP[25];
    char nomorHP[25];
    int jumlahBayar;
    int biayaAdmin = 2500;

    printf("\n=====  Pilih Jenis Tagihan =====\n");
    printf("1. PDAM\n");
    printf("2. PLN\n");
    printf("3. Pajak\n");
    printf("4. Pulsa\n");
    printf("Masukkan Pilihan Anda: \n");
    scanf("%d",&pilihan);
    
    switch(pilihan)
    {
        case 1:
            pembayaranPDAM(saldo);
            break;
        case 2:
            pembayaranPLN(saldo);
            break;
        case 3:
            pembayaranPajak(saldo);
            break;
        case 4:
            pembayaranPulsa(saldo);
            break;
        default:
            printf("Pilihan Tidak Valid. Silahkan coba lagi !\n");
    }
}    

void cetakStruk(datastruk struk, int jumlahTransaksi)
{
    printf
}

int VA(int saldo){
    char VirtualAccount[20];
    int Nominaldibayar;
    printf("Masukan No. Virtual Account \n");
    scanf("%s", VirtualAccount);
    printf("Masukkan Jumlah Nominal :");
    scanf("%s", Nominaldibayar);
    Printf("Transaksi  berhasil");
    saldo = saldo - Nominaldibayar;
    return saldo;
}

#endif