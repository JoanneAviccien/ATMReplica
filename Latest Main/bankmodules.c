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

void saveakun(akun write)
{
    FILE* save = fopen("datakartu.bin", "ab+");
    if(save == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
        
    fwrite(&write, sizeof(akun), 1, save);
    fclose(save);
}

void write

void getsaatini(int* bulan, int* tahun)
{
	time_t getwaktu = time(NULL);
	struct tm hariini = *localtime(&getwaktu);
	*bulan = hariini.tm_mon + 1;
	*tahun = hariini.tm_year + 1900;
}

void Logo() {
    printf("     ################                                                           \n");
    printf(" ###      #####      ##          #############         ##########    ###########\n");
    printf(" #      #########      #        ################   ################ ############\n");
    printf("##      #########      ##      ################# ################  #############\n");
    printf("#    ##############     #      #######   ###### ################   #############\n");
    printf("#   #################   #      ############### #######            ##############\n");
    printf("#   #################   ##    ############### #######            ####### #######\n");
    printf("#  ##################   ##    #######################           ################\n");
    printf("#  *#################   #    #######   *##############*      ###################\n");
    printf("##        #####   *    ##    ################# #################################\n");
    printf(" #   ##           #    #    ################    #####################    #######\n");
    printf("  ## ######## ######  ##    ##############        ##################     #######\n");
    printf("     ################                       \n");
}   
           
void getketerangan(int ket, char outket[19])
{
        if(ket == 1)
		{
            strcpy(outket, "Tarik Tunai");
		}
        else if(ket == 2)
		{
            strcpy(outket, "Transfer BCA");
		}
        else if(ket == 3)
		{
            strcpy(outket, "Transfer Bank lain");
		}
        else if(ket == 4)
		{
            strcpy(outket, "Setor Tunai");
		}
        else if(ket == 5)
		{
            strcpy(outket, "PDAM");
		}
        else if(ket == 6)
		{
            strcpy(outket, "PLN");
		}
        else if(ket == 7)
		{
            strcpy(outket, "Pajak");
		}
        else if(ket == 8)
		{
            strcpy(outket, "Pulsa");
		}
        else if(ket == 9)
		{
            strcpy(outket, "Tagihan");
		}
        else if(ket == 10)
		{
            strcpy(outket, "VA");
		}
        else
		{
            strcpy(outket, "-");
		}
}

void opsimutasi()
{
    char opsi;
    printf("1. Pengeluaran\n");
    printf("2. Pemasukan\n");
    printf("3. Kembali\\n");
    printf("Masukkan pilihan :");
    scanf("%c", opsi);
}

void masukKartuATM()
{
	char masukKartu;
	printf("SELAMAT DATANG DI ATM BANK BAWA CUAN AMAN\n\n");
	printf("SILAHKAN MASUKKAN KARTU ANDA...\n");
	
	masukKartu:	
	printf("TEKAN 'ENTER' UNTUK MEMASUKKAN KARTU...\n");

	masukKartu = getchar();

	if (masukKartu == '\n') 
	{
		printf("KARTU BERHASIL DIMASUKKAN. SELAMAT DATANG DI LAYANAN ATM BCA\n");
	} 
	else 
	{
		printf("ANDA BELUM MEMASUKKAN KARTU. SILAHKAN COBA LAGI.\n");
		
		while (getchar() != '\n');
		
		goto masukKartu;
	}
	
}

int menu(void)
{
    int width = 80;
    char str[] = "MENU";
    char opsi[1];
	    
    int length = sizeof(str) - 1;
    int pad = (length >= width) ? 0 : (width - length) / 2;

    printf("%*.*s%s\n", pad, pad, " ", str);
 	printf("\n1. Cek Saldo\n");
 	printf("2. Tarik Tunai\n");
 	printf("3. Setor Tunai\n");
 	printf("4. Transfer\n");
	printf("5. Pembayaran\n");
	printf("6. Virtual Account\n");
    prtinf("7. Pelayanan\n");
    printf("8. Mutasi rekening");
	printf("Masukan Pilihanmu :");
	scanf("%s", opsi);
    if(opsi == 1){
        cekSaldo(int saldo);
    }else if(opsi == 2){
        tarikTunai(int *saldo);
    }else if(opsi == 3){
        setorTunai(int *saldo);
    }else if(opsi == 4){
        OpsiBank();
    }else if(opsi == 5){
        pembayaranTagihan(int *saldo);
    }else if(opsi == 6 ){
        VA();
    }else if(opsi == 7 ){
        MenuPelayanan();
    }else if (opsi == 8)
    {
        opsimutasi();
    }else(){
        printf("Input tidak valid");
        Menu(void);
    }
    return(0);
}

void MenuPelayanan(){
    char Opsi[1];
    printf("1. Ubah PIN\n2. Ubah email");
    printf("Masukan Pilihan :, %s", Opsi);
    if(Opsi == 1){
        changePW();
    }else if(){
        changeEmail();
    }else(){
        printf("Input tidak valid");
        MenuPelayanan();
    }
}


void generatornokartu(char nokartu[17])
{
	printf("\nHarap tunggu (Pembuatan nomor kartu)...");
    srand(time(NULL));
    for (int rep = 0; rep < 16; rep++) {
        nokartu[rep] = '0' + (rand() % 10); 
    }
    nokartu[16] = '\0';
}

void generatornorek(char norek[11])
{
	printf("\nHarap tunggu (Pembuatan nomor rekening)...");
    Sleep(2000);
    srand(time(NULL));
    for (int rep = 0; rep < 10; rep++) {
        norek[rep] = '0' + (rand() % 10); 
    }
    norek[10] = '\0';
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
	
	printf("===========================================\n");
    printf("1.Silver\n");
    printf("2.Gold\n");
    printf("3.Platinum\n");
    printf("Pilih tipe kartu anda (Masukan Nomor opsi): ");
    scanf("%d", &new->tipekartu);
    fflush(stdin);
	
    new->saldo = 50000;
	
    new->statuskartu = true;

    generatornokartu(new->nokartu);
    generatornorek(new->norek);
	
}


void getstatus(int statuskartu, char cekstatus[10])
{

	if(statuskartu == 1)
	{
		strcpy(cekstatus, "Unblocked");
	}
	else if(statuskartu == 0)
	{
		strcpy(cekstatus, "Blocked");
	}

}

void gettipe(int tipekartu, char cektipe[9])
{
    
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

void blokirkartu(akun* kartu)
{
    akun->statuskartu = false;
}   

void login(char *nokartu, char *pin)
{
    char nokartuisi[17];
    char pininput[7];
    int i = 1;
    
    isikartu:
    printf("Masukan Nomor Kartu..... (16 digit)\n");
    fgets(nokartuisi, sizeof(nokartu), stdin);
    nokartu[strcspn(nokartu, "\n")] = 0;
    fflush(stdin);
    if(strcmp(Nokartuisi, nokartu) == 0)
    {
        printf("Masukan Pin..... (6 digit)\n");   
        while ()
        {
            while(i<=3)
            {
                fgets(pininput, sizeof(pininput), stdin);
                pininput[strcspn(pininput, "\n")] = 0;
                fflush(stdin);
                if(strcmp(pininput, pin) == 0)
                {
                    printf("Pin Benar");
                    menu(void);
                    goto
                } else
                prinf("Pin Salah!, Masukan Pin kembali!\n")
                ++i;
            }
            blokirkartu(akun* kartu);
            getstatus("");
            exit(1);
        }
    }
    else
    {
        goto isikartu;
    }
    
}

int Opsibhs ()
{

    char bhs[1];
    printf("Pilih Bahasa\n 1. Inggris\n 2. Indonesia");
    printf("Masukan Pilihan :");
    scanf("%s", bhs);

}
 
void tarikTunai(int *saldo, int* pengeluaran, int* keterangan)
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
void transferBCA(int *saldo, int* pengeluaran, int* keterangan)
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

void transferother(int *saldo, int* pengeluaran, int* keterangan)
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

void setorTunai(int *saldo, int* pemasukan, int* keterangan)
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

char changePW(char pin[7]){
    char pinlama[7];
    char pinbaru[7];
    char pinbaru2[7];
    int i = 1;
    While(i<3){
        printf("Ubah Pin\n");
        printf("Masukan Pin anda  :\n");
        scanf("%s", pinlama);
        int res = strcmp(pinlama, pin);
        if(res == 0){
            printf("Sandi Benar \n");
            i=i+4;
        }else(){
            printf("Sandi Salah! Masukan Kembali sandi! \n");
            i= i+1;
        }
        newPW();
    }
}

void pembayaranPDAM(int *saldo, int* pengeluaran, int* keterangan)
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

void pembayaranPLN(int *saldo, int* pengeluaran, int* keterangan)
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

void pembayaranPajak(int *saldo, int* pengeluaran, int* keterangan)
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

void pembayaranPulsa(int *saldo, int* pengeluaran, int* keterangan)
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

    printf("Masukkan Nominal Pulsa yang Akan Dibeli: Rp.%d", &jumlahBayar);
    int totalBayar = jumlahBayar + biayaAdmin;

    if(*saldo >= totalBayar)
    {
        *saldo -= totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : Pajak\n");
        printf("Nomor Telepon       : %s\n", nomorHp);
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
*keterangan = 8;
}

void pembayaranTagihan(int *saldo, int* pengeluaran,int* keterangan)
{
    int pilihan;
    char nomorPDAM[25];
    char nomorPLN[25];
    char nomorNPWP[25];
    char nomorHP[25];
    int jumlahBayar;
    int biayaAdmin = 2500;

    printf("\n=====  Pilih Jenis Tagihan/Pembayaran =====\n");
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
}

void VA(int* saldo, int* pengeluaran, int* keterangan)
{
    char VirtualAccount[20];
    int Nominaldibayar;
    printf("Masukan No. Virtual Account \n");
    scanf("%s", VirtualAccount);
    printf("Masukkan Jumlah Nominal :");
    scanf("%s", Nominaldibayar);
    Printf("Transaksi  berhasil");
    *saldo = *saldo - Nominaldibayar;
}

char NextorNot(){
    char Opsi[1];
    printf("Apakah anda ingin melanjutkan transaksi :\n");
    printf("1. Ya\n");
    printf("2. No");
    scanf("%c", Opsi);
    if(Opsi == 1){
        menu(void);
    }else if (Opsi == 2)
    {
        cetakStruk(datastruk struk, int jumlahTransaksi);
        exit(1);   
    }else(){
        NextorNot();
    }

}
#endif