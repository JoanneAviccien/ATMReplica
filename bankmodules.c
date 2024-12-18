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
    int keluar;
    int masuk;
    int periode;
} mutasi;

typedef struct
{
    char nokartu[17];
    int tgl;
    int tfhariini;
} limit;

void Logo() {
printf("+______________________________+\n");
printf("| $$$$$$$    $$$$$$    $$$$$$  |\n");
printf("| $$    $$  $$    $$  $$    $$ |\n");
printf("| $$    $$  $$        $$    $$ |\n");
printf("| $$$$$$$   $$        $$$$$$$$ |\n");
printf("| $$    $$  $$        $$    $$ |\n");
printf("| $$    $$  $$    $$  $$    $$ |\n");
printf("| $$$$$$$    $$$$$$   $$    $$ |\n");
printf("+______________________________+\n\n");
}   

void gettgl(int * tgl) //Nilai integer
{
    time_t getwaktu = time(NULL);
	struct tm hariini = *localtime(&getwaktu);
    *tgl = hariini.tm_mday;
}

void getbln(int * bln) //Nilai Integer
{
    time_t getwaktu = time(NULL);
	struct tm hariini = *localtime(&getwaktu);
    *bln = hariini.tm_mon + 1;
}

void getthn(int * thn)
{
    time_t getwaktu = time(NULL);
	struct tm hariini = *localtime(&getwaktu);
    *thn = hariini.tm_year + 1900;
}

void saveakun(akun write)
{
    FILE* save = fopen("datakartu.bin", "ab+");
    if(save == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
            //Variable yang mau ditulis             //Ukuran bit var yang akan ditulis      //Pengulangan Penulisan brp kali        //File yang akan ditulis
    fwrite(             &write,                       sizeof(akun),                                 1,                                  save);
    fclose(save);
}

void sloadnorek(char carinorek[11], akun * foundacc)
{
    akun temp;
	
	FILE* load = fopen("datakartu.bin", "rb+");
    if(load == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(!feof(load))
    {
        fread(&temp, sizeof(akun), 1, load);
        if(strcmp(temp.norek, carinorek) == 0 )
        {
            *foundacc = temp;
            break;
        }
    }  

    fclose(load);
}

void sloadkartu(char carikartu[17], akun * foundacc)
{
    akun temp;
	
	FILE* load = fopen("datakartu.bin", "rb+");
    if(load == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(!feof(load))
    {
        fread(&temp, sizeof(akun), 1, load);
        if(strcmp(temp.nokartu, carikartu) == 0 )
        {
            *foundacc = temp;
            break;
        }
    }  

    fclose(load);
}

void ssavekartu(char carikartu[17], akun insertacc)
{
    int countline = 0;
    akun temp;
	
	FILE* save = fopen("datakartu.bin", "rb+");
    if(save == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
	
	while(strcmp(temp.nokartu, carikartu) != 0)
    {
        fread(&temp, sizeof(akun), 1, save);
		countline++;
    }  
	fseek(save, 0, SEEK_SET);
	fseek(save, (countline-1)*sizeof(akun), SEEK_SET);
	fwrite(&insertacc, sizeof(akun), 1, save);
	fflush(save);	

    fclose(save);
}   

void blokirakun(char kartu[17])
{
	akun temp;
	akun load;
	int countline = 0;
	printf("Kartu anda diblokir, harap kunjungi KCP terdekat\nUntuk membuka blokir!");
	sloadkartu(kartu, &temp);
	temp.statuskartu = false;
	
	FILE* blokir = fopen("datakartu.bin", "rb+");
	if(blokir == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
	
	while(strcmp(load.nokartu, kartu) != 0)
    {
        fread(&load, sizeof(akun), 1, blokir);
		countline++;
    }  
	fseek(blokir, 0, SEEK_SET);
	fseek(blokir, (countline-1)*sizeof(akun), SEEK_SET);
	fwrite(&temp, sizeof(akun), 1, blokir);
	fflush(blokir);	
}

void bukablokirakun(char kartu[17])
{
	akun temp;
	akun load;
	int countline = 0;
	printf("Akun sudah tidak terblokir!");
	sloadkartu(kartu, &temp);
	temp.statuskartu = true;
	
	FILE* blokir = fopen("datakartu.bin", "rb+");
	if(blokir == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
	
	while(strcmp(load.nokartu, kartu) != 0)
    {
        fread(&load, sizeof(akun), 1, blokir);
		countline++;
    }  
	fseek(blokir, 0, SEEK_SET);
	fseek(blokir, (countline-1)*sizeof(akun), SEEK_SET);
	fwrite(&temp, sizeof(akun), 1, blokir);
	fflush(blokir);
}

void printtahun(mutasi display)
{
    printf("[Mutasi Pertahun Untuk %s]\n\n", display.nokartu);
    printf("Pengeluaran:    Rp.%d\n", display.keluar);
    printf("Pemasukan:      Rp.%d\n", display.masuk);
}

void printbulan(mutasi display)
{
    printf("[Mutasi Perbulan Untuk %s]\n\n", display.nokartu);
    printf("Pengeluaran:    Rp.%d\n", display.keluar);
    printf("Pemasukan:      Rp.%d\n", display.masuk);
}

void newmonthlymutasi(mutasi inm)
{
    FILE* mon = fopen("mutasiperbulan.bin","ab");
    if(mon == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
    fwrite(&inm, sizeof(mutasi), 1, mon);
    fclose(mon);
}

void newyearlymutasi(mutasi iny)
{
    FILE* year = fopen("mutasipertahun.bin","ab");
    if(year == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
    fwrite(&iny, sizeof(mutasi), 1, year);
    fclose(year);
}

void sloadperbulan(char carikartu[17], mutasi* outm)
{
    mutasi temp;
    FILE* perbulan = fopen("mutasiperbulan.bin","rb+");
    if(perbulan == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(!feof(perbulan))
    {
        fread(&temp, sizeof(mutasi), 1, perbulan);
        if(strcmp(temp.nokartu, carikartu) == 0 )
        {
            *outm = temp;
            break;
        }
    }      

    fclose(perbulan);
}


void sloadpertahun(char carikartu[17], mutasi* outy)
{
    mutasi temp;
    FILE* pertahun = fopen("mutasipertahun.bin","rb+");
    if(pertahun == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(!feof(pertahun))
    {
        fread(&temp, sizeof(mutasi), 1, pertahun);
        if(strcmp(temp.nokartu, carikartu) == 0 )
        {
            *outy = temp;
            break;
        }
    }  

    fclose(pertahun);
}

void ssavepertahunmasuk(char carikartu[17], mutasi iny)
{
    mutasi temp;
    mutasi combined = iny;
    int countline = 0;
    FILE* pertahun = fopen("mutasipertahun.bin","rb+");
    if(pertahun == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(strcmp(temp.nokartu, carikartu) != 0)
    {
        fread(&temp, sizeof(mutasi), 1, pertahun);
		countline++;
    }
    combined.masuk += temp.masuk;
	fseek(pertahun, 0, SEEK_SET);
	fseek(pertahun, (countline-1)*sizeof(mutasi), SEEK_SET);
	fwrite(&combined, sizeof(mutasi), 1, pertahun);
	fflush(pertahun);	

    fclose(pertahun);
}

void ssaveperbulanmasuk(char carikartu[17], mutasi inm)
{
    mutasi temp;
    mutasi combined = inm;
    int countline = 0;
    FILE* perbulan = fopen("mutasiperbulan.bin","rb+");
    if(perbulan == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(strcmp(temp.nokartu, carikartu) != 0)
    {
        fread(&temp, sizeof(mutasi), 1, perbulan);
		countline++;
    }
    combined.masuk += temp.masuk;
    fseek(perbulan, 0, SEEK_SET);
	fseek(perbulan, (countline-1)*sizeof(mutasi), SEEK_SET);
	fwrite(&combined, sizeof(mutasi), 1, perbulan);
	fflush(perbulan);

    fclose(perbulan);
}

void ssavepertahunkeluar(char carikartu[17], mutasi iny)
{
    mutasi temp;
    mutasi combined = iny;
    int countline = 0;
    FILE* pertahun = fopen("mutasipertahun.bin","rb+");
    if(pertahun == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(strcmp(temp.nokartu, carikartu) != 0)
    {
        fread(&temp, sizeof(mutasi), 1, pertahun);
		countline++;
    }
    combined.keluar += temp.keluar;
	fseek(pertahun, 0, SEEK_SET);
	fseek(pertahun, (countline-1)*sizeof(mutasi), SEEK_SET);
	fwrite(&combined, sizeof(mutasi), 1, pertahun);
	fflush(pertahun);	

    fclose(pertahun);
}

void ssaveperbulankeluar(char carikartu[17], mutasi inm)
{
    mutasi temp;
    mutasi combined = inm;
    int countline = 0;
    FILE* perbulan = fopen("mutasiperbulan.bin","rb+");
    if(perbulan == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(strcmp(temp.nokartu, carikartu) != 0)
    {
        fread(&temp, sizeof(mutasi), 1, perbulan);
		countline++;
    }
    combined.keluar += temp.keluar;
    fseek(perbulan, 0, SEEK_SET);
	fseek(perbulan, (countline-1)*sizeof(mutasi), SEEK_SET);
	fwrite(&combined, sizeof(mutasi), 1, perbulan);
	fflush(perbulan);

    fclose(perbulan);
}

void resettahun(char carikartu[17], mutasi year, int saatini)
{
    if (saatini > year.periode)
    {
        mutasi out;
        strcpy(out.nokartu, year.nokartu);
        out.periode = saatini;
        out.keluar = 0;
        out.masuk = 0;

        mutasi temp;
        int countline = 0;

        FILE* reset = fopen("mutasipertahun.bin","rb+");
        if(reset == NULL)
        {
            perror("Data tidak berhasil diakses!");
        }
        
        while(strcmp(temp.nokartu, carikartu) != 0)
        {
            fread(&temp, sizeof(mutasi), 1, reset);
            countline++;
        }

        fseek(reset, 0, SEEK_SET);
        fseek(reset, (countline-1)*sizeof(mutasi), SEEK_SET);
        fwrite(&out, sizeof(mutasi), 1, reset);
        fflush(reset);
        fclose(reset);
    }
    else{}
}

void resetbulan(char carikartu[17], mutasi mon, int saatini)
{
    if (saatini > mon.periode)
    {
        mutasi out;
        strcpy(out.nokartu, mon.nokartu);
        out.periode = saatini;
        out.masuk = 0;
        out.keluar = 0;

        mutasi temp;
        int countline = 0;

        FILE* reset = fopen("mutasiperbulan.bin","rb+");
        if(reset == NULL)
        {
            perror("Data tidak berhasil diakses!");
        }
        
        while(strcmp(temp.nokartu, carikartu) != 0)
        {
            fread(&temp, sizeof(mutasi), 1, reset);
            countline++;
        }
        fseek(reset, 0, SEEK_SET);
        fseek(reset, (countline-1)*sizeof(mutasi), SEEK_SET);
        fwrite(&out, sizeof(mutasi), 1, reset);
        fflush(reset);
        fclose(reset);	
    }
    else{}
}

void getsaatini(int*hari, int* bulan, int* tahun)
{
	time_t getwaktu = time(NULL);
	struct tm hariini = *localtime(&getwaktu);
    *hari = hariini.tm_mday;
	*bulan = hariini.tm_mon + 1;
	*tahun = hariini.tm_year + 1900;
}

void opsimutasi(mutasi mon, mutasi year)
{
    retry:
    system("cls");
    char opsi;
    printf("-----------[Pilih Periode Mutasi]-----------\n");
    printf("1. Perbulan\n");
    printf("2. Pertahun\n");
    printf("Masukkan pilihan: ");
    opsi = fgetc(stdin);
    fflush(stdin);

    if(opsi == '1')
    {
        printbulan(mon);
    }
    else if (opsi == '2')
    {
        printtahun(year);
    }
    else
    {
        printf("Opsi invalid!");
        Sleep(2500);
        goto retry;
    }
}

void tarikTunai(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monthly, mutasi* yearly)
{
    int uangDitarik;
    *monthly = monin;
    *yearly = yearin;
    retry:
    printf("Masukkan Jumlah Uang yang Ingin Ditarik (Kelipatan Rp.50.000): ");
    scanf("%d", &uangDitarik);
    fflush(stdin);
    if(saldo.saldo >= uangDitarik)
    {
        if(uangDitarik % 50000 != 0)
        {
            printf("Uang yang dimasukan tidak valid\n");
        }
        else{
            saldo.saldo = saldo.saldo - uangDitarik;
            kondisibaru->saldo = saldo.saldo;
            monthly->keluar = uangDitarik;
            yearly->keluar = uangDitarik;
        }
    }else
    {
        printf("Saldo anda kurang!\n");
        Sleep(1500);
        goto retry;
    }
}

int VA(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout)
{
    char VirtualAccount[20];
    int Nominaldibayar;
    *monout = monin;
    *yearout = yearin;
    VirtualA:
    printf("Masukan No. Virtual Account \n");
    fgets(VirtualAccount, sizeof(VirtualAccount), stdin);
    VirtualAccount[strcspn(VirtualAccount, "\n")] = 0;
    fflush(stdin);
    printf("Masukkan Jumlah Nominal :");
    scanf("%d", &Nominaldibayar);
    fflush(stdin);
    if(Nominaldibayar > saldo.saldo)
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Nominal yang dibayarkan     : Rp.%d\n", Nominaldibayar);
        printf("Saldo Anda Saat Ini         : Rp.%d\n", saldo.saldo);
        goto VirtualA;
    }
    else
    {
        printf("Transaksi berhasil");
        saldo.saldo = saldo.saldo - Nominaldibayar;
        kondisibaru->saldo = saldo.saldo;
        monout->keluar = Nominaldibayar;
        yearout->keluar = Nominaldibayar;
    }
    
}

void cekSaldo(int saldo)
{
    printf("Saldo Anda Saat Ini Adalah: Rp.%d", saldo);
}

void savelimit(limit in)
{
    FILE* save = fopen("datalimit.bin", "ab+");
    if(save == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
        
    fwrite(&in, sizeof(limit), 1, save);
    fclose(save);
}

void sloadlimit(char carikartu[17], limit * output)
{	
    limit temp;

	FILE* load = fopen("datalimit.bin", "rb+");
    if(load == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }

    while(!feof(load))
    {
        fread(&temp, sizeof(limit), 1, load);
        if(strcmp(temp.nokartu, carikartu) == 0 )
        {
            *output = temp;
            break;
        }
    }

    fclose(load);
}

void ssavelimit(char carikartu[17], limit input)
{
    int countline = 0;
    limit temp;
    limit combined = input;
	
	FILE* save = fopen("datalimit.bin", "rb+");
    if(save == NULL)
    {
        perror("Data tidak berhasil diakses!");
    }
	
	while(strcmp(temp.nokartu, carikartu) != 0)
    {
        fread(&temp, sizeof(limit), 1, save);
		countline++;
    }
    combined.tfhariini += temp.tfhariini;
	fseek(save, 0, SEEK_SET);
	fseek(save, (countline-1)*sizeof(limit), SEEK_SET);
	fwrite(&combined, sizeof(limit), 1, save);
	fflush(save);	

    fclose(save);
}

void resetlimit(char carikartu[17], limit in, waktu hariini)
{
    if (hariini.tgl != in.tgl)
    {
        limit out;
        strcpy(out.nokartu, in.nokartu);
        out.tgl = hariini.tgl;
        out.tfhariini = 0;

        limit temp;
        int countline = 0;

        FILE* reset = fopen("datalimit.bin","rb+");
        if(reset == NULL)
        {
            perror("Data tidak berhasil diakses!");
        }
        
        while(strcmp(temp.nokartu, carikartu) != 0)
        {
            fread(&temp, sizeof(limit), 1, reset);
            countline++;
        }
        fseek(reset, 0, SEEK_SET);
        fseek(reset, (countline-1)*sizeof(limit), SEEK_SET);
        fwrite(&out, sizeof(limit), 1, reset);
        fflush(reset);
        fclose(reset);	
    }

}

int ceklimit(akun in, limit inlim)
{
    if(in.tipekartu == 1)
    {
        if(inlim.tfhariini >= TIPE1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else if(in.tipekartu == 2)
    {
        if(inlim.tfhariini >= TIPE2)
        {
            
        }
        else
        {
            return 0;
        }
    }

    else if(in.tipekartu == 3)
    {
        if(inlim.tfhariini >= TIPE3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void transferBCA(akun saldo, akun * kondisibaru, limit in, limit* outlim, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout)
{
    akun tujuan;
    mutasi tujuanbln;
    mutasi tujuanthn;
    char norektujuan[11];
    int jumlahTransfer;
    retry:
    printf("\nMasukkan Nomor Rekening Tujuan: ");
    fgets(norektujuan, sizeof(norektujuan), stdin);
    norektujuan[strcspn(norektujuan, "\n")] = 0;
    fflush(stdin);
    sloadnorek(norektujuan, &tujuan);
    sloadperbulan(tujuan.nokartu, &tujuanbln);
    sloadpertahun(tujuan.nokartu, &tujuanthn);
    if(strcmp(norektujuan, tujuan.norek) == 0)
    {
        printf("\nMasukkan Jumlah yang Akan Ditransfer: Rp.");
        scanf("%d", &jumlahTransfer);
        fflush(stdin);
        
        if(saldo.saldo >= jumlahTransfer)
        {
            saldo.saldo -= jumlahTransfer;
            *kondisibaru = saldo;
            *outlim = in;
            *monout = monin;
            *yearout = yearin;
            kondisibaru->saldo = saldo.saldo;
            tujuan.saldo += jumlahTransfer;
            outlim->tfhariini = jumlahTransfer;
            monout->keluar += jumlahTransfer;
            yearout->keluar += jumlahTransfer;
            tujuanbln.masuk += jumlahTransfer;
            tujuanthn.masuk += jumlahTransfer;


            printf("Transfer Sebesar Rp.%d Ke Rekening %s Berhasil !\n", jumlahTransfer, norektujuan);
            printf("Sisa Saldo Anda Adalah: Rp.%d\n", saldo.saldo);
            ssavepertahunmasuk(tujuan.nokartu, tujuanthn);
            ssaveperbulanmasuk(tujuan.nokartu, tujuanbln);
            ssavekartu(tujuan.nokartu, tujuan);
        } 
        else
        {
            printf("\nTransfer Gagal. Saldo Anda Tidak Mencukupi");
        }
    }
    else
    {
        printf("\nNomor Tidak Terdaftar dalam database!");
        Sleep(3000);
        goto retry;
    }
}

void transferother(akun saldo, akun * kondisibaru, limit in, limit* outlim, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout)
{

    char norektujuan[20];
    int jumlahTransfer;
    printf("Masukkan Nomor Rekening Tujuan: ");
    fgets(norektujuan, sizeof(norektujuan), stdin);
    norektujuan[strcspn(norektujuan, "\n")] = 0;
    fflush(stdin);

    printf("Masukkan Jumlah yang Akan Ditransfer: Rp.");
    scanf("%d", &jumlahTransfer);
    fflush(stdin);
    
    
    if(saldo.saldo >= jumlahTransfer)
    {
        jumlahTransfer = jumlahTransfer + 5000;
        *kondisibaru = saldo;
        *outlim = in;
        *monout = monin;
        *yearout = yearin;
        saldo.saldo -= jumlahTransfer;
        outlim->tfhariini = jumlahTransfer - 5000;
        kondisibaru->saldo = saldo.saldo;
        monout->keluar += jumlahTransfer;
        yearout->keluar += jumlahTransfer;
        printf("Transfer Sebesar Rp.%d Ke Rekening %s Berhasil !\n", jumlahTransfer-(5000), norektujuan);
        printf("Sisa Saldo Anda Adalah: Rp.%d\n", saldo.saldo);
    } 
    else
    {
            printf("Transfer Gagal. Saldo Anda Tidak Mencukupi");
    }
}

void OpsiBank(akun loaded, akun * kondisibaru, limit in, limit* outlim, mutasi monin, mutasi yearin, mutasi* monthly, mutasi* yearly)
{
    retry:
    sloadkartu(loaded.nokartu, &loaded);
    akun temp;
    limit templim;
    mutasi tempmon;
    mutasi tempyear;
    *kondisibaru = temp;
    *outlim = templim;
    *monthly = tempmon;
    *yearly = tempyear;
    
    char Opsibank;
    printf("1. Transfer sesama Bank \n2. Transfer Beda Bank \n");
    printf("Masukkan Pilihan: ");
    Opsibank = fgetc(stdin);
    fflush(stdin);
    if(Opsibank == '1')
    {
        transferBCA(loaded, &temp, in, &templim, monin, yearin, &tempmon, &tempyear);
        ssavekartu(loaded.nokartu, temp);
        ssavelimit(loaded.nokartu, templim);
        ssaveperbulankeluar(loaded.nokartu, tempmon);
        ssavepertahunkeluar(loaded.nokartu, tempyear);
    }
    else if (Opsibank == '2')
    {
        transferother(loaded, &temp, in, &templim, monin, yearin, &tempmon, &tempyear);
        ssavekartu(loaded.nokartu, temp);
        ssavelimit(loaded.nokartu, templim);
        ssaveperbulankeluar(loaded.nokartu, tempmon);
        ssavepertahunkeluar(loaded.nokartu, tempyear);
    }
    else
    {
        printf("Input Invalid");
        goto retry;
    }
}

void pembayaranPDAM(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout)
{
    char nomorPDAM[25];
    int jumlahBayar[10] = {25000, 50000, 75000, 100000, 125000, 150000, 175000, 200000, 225000, 250000};
    int biayaAdmin = 2500;
    srand(time(NULL));
    int angka_acak = (rand() % 10);
    printf("\n===== Pembayaran PDAM =====\n");
    printf("Masukkan Nomor ID Pelanggan PDAM (Format: PDAMXXXXX):");
    fgets(nomorPDAM, sizeof(nomorPDAM), stdin);
    nomorPDAM[strcspn(nomorPDAM, "\n")] = 0;
    fflush(stdin);

    if(strncmp(nomorPDAM, "PDAM", 4) != 0)
    {
        printf("Nomor ID Pelanggan Tidak Valid ! Nomor Harus Diawali 'PDAM'\n");
        return;
    }

    printf("Jumlah Tagihan yang Akan Dibayar: Rp. %d", jumlahBayar[angka_acak]);
    int totalBayar = jumlahBayar[angka_acak] + biayaAdmin;

    if (saldo.saldo >= totalBayar)
    {
        saldo.saldo -= totalBayar;
        kondisibaru->saldo = saldo.saldo;
        *monout = monin;
        *yearout = yearin;
        monout->keluar = totalBayar;
        yearout->keluar = totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : PDAM\n");
        printf("Nomor Tujuan        : %s\n", nomorPDAM);
        printf("Jumlah Tagihan      : Rp.%d\n", jumlahBayar[angka_acak]);
        printf("Biaya Administrasi  : Rp.%d\n", biayaAdmin);
        printf("Sisa Saldo Anda     : Rp.%d\n", saldo.saldo);
        goto done;
    }
    else
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Jumlah yang Dibutuhkan  : Rp.%d\n", totalBayar);
        printf("Saldo Anda Saat Ini     : Rp.%d\n", saldo.saldo);
    }
    done:
}

void pembayaranPLN(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin,mutasi* monout , mutasi* yearout)
{
    char nomorPLN[25];
    int jumlahBayar[10] = {25000, 50000, 75000, 100000, 125000, 150000, 175000, 200000, 225000, 25000};
    int biayaAdmin = 2500;

    srand(time(NULL));
    int angka_acak = (rand() % 10);
    printf("\n===== Pembayaran PLM =====\n");
    printf("Masukkan Nomor ID Pelanggan PLN (Format: PLNXXXXX):");
    fgets(nomorPLN, sizeof(nomorPLN), stdin);
    nomorPLN[strcspn(nomorPLN, "\n")] = 0;
    fflush(stdin);

    if(strncmp(nomorPLN, "PLN", 3) != 0)
    {
        printf("Nomor ID Pelanggan Tidak Valid ! Nomor Harus Diawali 'PLN'\n");
        return;
    }

    printf("Masukkan Jumlah Tagihan yang Akan Dibayar: Rp.");
    printf("Nominal yang dibayar : %d", jumlahBayar[angka_acak]);
    
    int totalBayar = jumlahBayar[angka_acak] + biayaAdmin;

    if (saldo.saldo >= totalBayar)
    {
        saldo.saldo -= totalBayar;
        kondisibaru->saldo = saldo.saldo;
        *monout = monin;
        *yearout = yearin;
        monout->keluar = totalBayar;
        yearout->keluar = totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : PLN\n");
        printf("Nomor Tujuan        : %s\n", nomorPLN);
        printf("Jumlah Tagihan      : Rp.%d\n", jumlahBayar[angka_acak]);
        printf("Biaya Administrasi  : Rp.%d\n", biayaAdmin);
        printf("Total Bayar         : Rp. %d\n", totalBayar);
        printf("Sisa Saldo Anda     : Rp.%d\n", saldo.saldo);
        goto done;
    }
    else
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Jumlah yang Dibutuhkan  : Rp.%d\n", totalBayar);
        printf("Saldo Anda Saat Ini     : Rp.%d\n", saldo.saldo);
    }
    done:
}

void pembayaranPajak(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin,mutasi* monout , mutasi* yearout)
{
    char nomorNPWP[25];
    int jumlahBayar[10] = {25000, 50000, 75000, 100000, 125000, 150000, 175000, 200000, 225000, 25000};
    int biayaAdmin = 2500;

    srand(time(NULL));
    int angka_acak= (rand() % 10);
    printf("\n===== Pembayaran Pajak =====\n");
    printf("Masukkan Nomor Objek Pajak: ");
    fgets(nomorNPWP, sizeof(nomorNPWP), stdin);
    nomorNPWP[strcspn(nomorNPWP, "\n")] = 0;
    fflush(stdin);

    printf("Masukkan Jumlah Tagihan yang Akan Dibayar: Rp. %d", jumlahBayar[angka_acak]);
    
    int totalBayar = jumlahBayar[angka_acak] + biayaAdmin;

    if (saldo.saldo >= totalBayar)
    {
        saldo.saldo -= totalBayar;
        kondisibaru->saldo = saldo.saldo;
        *monout = monin;
        *yearout = yearin;
        monout->keluar = totalBayar;
        yearout->keluar = totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : Pajak\n");
        printf("Nomor Tujuan        : %s\n", nomorNPWP);
        printf("Jumlah Tagihan      : Rp. %d\n", jumlahBayar[angka_acak]);
        printf("Biaya Administrasi  : Rp. %d\n", biayaAdmin);
        printf("Total Bayar         : Rp. %d\n", totalBayar);
        printf("Sisa Saldo Anda     : Rp.%d\n", saldo.saldo);
        goto done;
        //info.transaksi = totalBayar;
        //strcpy(info.ket, "Pajak");
    }
    else
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Jumlah yang Dibutuhkan  : Rp.%d\n", totalBayar);
        printf("Saldo Anda Saat Ini     : Rp.%d\n", saldo.saldo);
    }
    done:
}

void pembayaranPulsa(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout)
{
    char nomorHP[14];
    int jumlahBayar;
    int biayaAdmin = 2500;

    printf("\n===== Pembayaran Pulsa ======\n");
    printf("Masukkan Nomor Telepon (Format: 08XXXXXXXXXX): ");
    fgets(nomorHP, sizeof(nomorHP), stdin);
    nomorHP[strcspn(nomorHP, "\n")] = 0;
    fflush(stdin);

    if(strncmp(nomorHP, "08", 2) != 0)
    {
        printf("Nomor Telepon Tidak Valid! Nomor Harus Diawali '08' dan Maksimal 13 Digit.\n");
        return;
    }

    printf("Masukkan Nominal Pulsa yang Akan Dibeli: Rp.");
    scanf("%d", &jumlahBayar);
    fflush(stdin);
    int totalBayar = jumlahBayar + biayaAdmin;

    if(saldo.saldo >= totalBayar)
    {
        saldo.saldo -= totalBayar;
        kondisibaru->saldo = saldo.saldo;
        *monout = monin;
        *yearout = yearin;
        monout->keluar = totalBayar;
        yearout->keluar = totalBayar;
        printf("\nPembayaran Berhasil.\n");
        printf("Jenis Tagihan       : Pulsa\n");
        printf("Nomor Telepon       : %s\n", nomorHP);
        printf("Jumlah Tagihan      : Rp.%d\n", jumlahBayar);
        printf("Biaya Administrasi  : Rp.%d\n", biayaAdmin);
        printf("Sisa Saldo Anda     : Rp.%d\n", saldo.saldo);
        goto done;
        //info.transaksi = totalBayar;
        //strcpy(info.ket, "Pulsa");
    }
    else
    {
        printf("\nPembayaran Gagal. Saldo Anda Tidak Mencukupi.\n");
        printf("Jumlah yang Dibutuhkan  : Rp.%d\n", totalBayar);
        printf("Saldo Anda Saat Ini     : Rp.%d\n", saldo.saldo);
    }
    done:
}

void pembayaranTagihan(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monout , mutasi* yearout)
{
    retry:
    akun temp;
    sloadkartu(saldo.nokartu, &temp);
    mutasi tempmon;
    mutasi tempyear;
    *kondisibaru = temp;
    *monout = tempmon;
    *yearout = tempmon;
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
    fflush(stdin);
    
    if(pilihan == 1){
        pembayaranPDAM(saldo, &temp, monin, yearin, &tempmon, &tempyear);
        ssavekartu(saldo.nokartu,temp);
        ssaveperbulankeluar(saldo.nokartu, tempmon);
        ssavepertahunkeluar(saldo.nokartu, tempyear);
    }
    else if (pilihan == 2){
        pembayaranPLN(saldo, &temp, monin, yearin, &tempmon, &tempyear);
        ssavekartu(saldo.nokartu,temp);
        ssaveperbulankeluar(saldo.nokartu, tempmon);
        ssavepertahunkeluar(saldo.nokartu, tempyear);
    }
    else if (pilihan == 3){
        pembayaranPajak(saldo, &temp, monin, yearin, &tempmon, &tempyear);
        ssavekartu(saldo.nokartu,temp);
        ssaveperbulankeluar(saldo.nokartu, tempmon);
        ssavepertahunkeluar(saldo.nokartu, tempyear);
    }
    else if (pilihan == 4){
        pembayaranPulsa(saldo, &temp, monin, yearin, &tempmon, &tempyear);
        ssavekartu(saldo.nokartu,temp);
        ssaveperbulankeluar(saldo.nokartu, tempmon);
        ssavepertahunkeluar(saldo.nokartu, tempyear);
    }
    else
    {
        printf("input invalid\n");
        goto retry;
    }
}    

void setorTunai(akun saldo, akun * kondisibaru, mutasi monin, mutasi yearin, mutasi* monthly, mutasi* yearly)
{
    int nominalSetor;
    *monthly = monin;
    *yearly = yearin;

    printf("\nMasukkan Jumlah Uang yang Akan Disetor (Kelipatan Rp.50.000): ");
    retry:
    scanf("%d", &nominalSetor);
    fflush(stdin);
    if(nominalSetor %50000 != 0)
    {
        printf("Jumlah Uang yang Dimasukkan Harus Kelipatan Rp.50.000 !\n");
        goto retry;
    }

    saldo.saldo += nominalSetor;
    kondisibaru->saldo = saldo.saldo;
    monthly->masuk = nominalSetor;
    yearly->masuk = nominalSetor;
    printf("Setoran Sebesar Rp.%d Berhasil. Saldo Anda Sekarang adalah: Rp.%d\n", nominalSetor, saldo.saldo);
}

void newPW(akun edit)
{
    char pinbaru[7], pinbaru2[7];
    lagi:
    printf("Masukan sandi Baru:\n");
    fgets(pinbaru, sizeof(pinbaru), stdin);
    pinbaru[strcspn(pinbaru, "\n")] = 0;
    fflush(stdin);
    printf("Konfirmasi sandi Baru, Ketikan Sandi baru anda kembali:\n");
    fgets(pinbaru2, sizeof(pinbaru2), stdin);
    pinbaru2[strcspn(pinbaru2, "\n")] = 0;
    fflush(stdin);
    int res2 = strcmp(pinbaru, pinbaru2);
    if(res2 == 0){
        strcpy(edit.pin, pinbaru);
        ssavekartu(edit.nokartu, edit);
    }
    else
    {
        goto lagi;
    }
}

void changePW(akun edit){
    char pinlama[7];
    int i = 1;
    while(i<3){
        printf("Ubah Pin\n");
        printf("Masukan Pin lama anda  :\n");
        fgets(pinlama, sizeof(pinlama), stdin);
        pinlama[strcspn(pinlama, "\n")] = 0;
        fflush(stdin);
        int res = strcmp(pinlama, edit.pin);
        if(res == 0){
            printf("Sandi Benar \n");
            i=i+4;
        }
        else{
            printf("Sandi Salah! Masukan Kembali sandi! \n");
            i= i+1;
        }
        newPW(edit);
    }
}

void changegmail(akun edit){
    char emailbaru[50];
    printf("Masukan email baru anda :\n");
    fgets(emailbaru, sizeof(emailbaru), stdin);
    emailbaru[strcspn(emailbaru, "\n")] = 0;
    fflush(stdin);
    strcpy(edit.gmail, emailbaru);
    ssavekartu(edit.nokartu, edit);
}

void MenuPelayanan(akun in){
    fflush(stdin);
    char Opsi;
    akun out;
    retry:
    printf("\n1. Ubah PIN\n2. Ubah email\n3. Blokir akun\n4. Buka Blokir akun\n");
    printf("Masukan Pilihan :");
    Opsi = fgetc(stdin);
    fflush(stdin);
    if(Opsi == '1'){
        changePW(in);
    }else if(Opsi == '2'){
        changegmail(in);
    }else if(Opsi == '3'){
        blokirakun(in.nokartu);
    }else if(Opsi == '4')
    {
        bukablokirakun(in.nokartu);
    }
    else{
        printf("Input tidak valid");
        goto retry;
    }
}

void informasi(akun read)
{
    printf("\n|=======================(Informasi Kartu)======================|");
    printf("\nNomor kartu anda adalah %s", read.nokartu);
	printf("\nNomor rekening anda adalah %s", read.norek);
	printf("\nSaldo anda adalah %d", read.saldo);
	printf("\nNama anda dalam kartu adalah %s", read.nama);
	printf("\nPin anda %s", read.pin);
	printf("\nTipe kartu anda adalah %d", read.tipekartu);
	printf("\nStatus kartu anda adalah %d", read.statuskartu);
	printf("\nGmail kartu anda adalah %s", read.gmail);
}

void menu(akun loaded, limit loadedlim, mutasi monthly, mutasi yearly)
{
    waktu saatini;
    int thncmp;
    int blncmp;
    sloadkartu(loaded.nokartu, &loaded);
    sloadlimit(loaded.nokartu, &loadedlim);
    if(loaded.statuskartu == 1)
    {
        retry:
        system("cls");
        akun temp = loaded;
        limit templim = loadedlim;
        mutasi tempmon = monthly;
        mutasi tempyear = yearly;
        int statuslimit = ceklimit(loaded, loadedlim);
        getsaatini(&saatini.tgl, &saatini.bln, &saatini.thn);
        getbln(&blncmp);
        getthn(&thncmp);
        resetbulan(loaded.nokartu, tempmon, blncmp);
        resettahun(loaded.nokartu, tempyear, thncmp);
        resetlimit(loaded.nokartu, templim, saatini);

        sloadperbulan(loaded.nokartu, &monthly);
        sloadpertahun(loaded.nokartu, &yearly);
        sloadlimit(loaded.nokartu, &loadedlim);
        sloadkartu(loaded.nokartu, &loaded);

        int width = 80;
        char str[] = "MENU";
        char opsi;
        
        int length = sizeof(str) - 1;
        int pad = (length >= width) ? 0 : (width - length) / 2;
        
        printf("%*.*s%s\n", pad, pad, " ", str);
        printf("\n1. Cek Saldo\n");
        printf("2. Tarik Tunai\n");
        printf("3. Setor Tunai\n");
        printf("4. Transfer\n");
        printf("5. Pembayaran\n");
        printf("6. Virtual Account\n");
        printf("7. Pelayanan\n");
        printf("8. Mutasi rekening\n");
        printf("9. Informasi Akun\n");
        printf("0. Keluar\n");
        printf("Masukan Pilihanmu :");
        opsi = fgetc(stdin);
        fflush(stdin);
        if(opsi == '1'){
            cekSaldo(loaded.saldo);
        }
        else if(opsi == '2')
        {
            tarikTunai(loaded, &temp, monthly, yearly, &tempmon, &tempyear);
            ssavekartu(loaded.nokartu, temp);
            ssaveperbulankeluar(loaded.nokartu, tempmon);
            ssavepertahunkeluar(loaded.nokartu, tempyear);
        }
        else if(opsi == '3')
        {
            setorTunai(loaded, &temp, monthly, yearly, &tempmon, &tempyear);
            ssavekartu(loaded.nokartu, temp);
            ssaveperbulanmasuk(loaded.nokartu, tempmon);
            ssavepertahunmasuk(loaded.nokartu, tempyear);
        }
        else if(opsi == '4')
        {
            if(statuslimit == 0)
            {
                OpsiBank(loaded, &temp, loadedlim, &templim, monthly, yearly, &tempmon, &tempyear);
            }
            else
            {
                printf("\nAnda sudah melebihi batas transfer perhari!\n");
                Sleep(3500);
                goto retry;
            }
        }
        else if(opsi == '5')
        {
            pembayaranTagihan(loaded, &temp, monthly, yearly, &tempmon, &tempyear);
        }
        else if(opsi == '6')
        {
            VA(loaded, &temp, monthly, yearly, &tempmon, &tempyear);
            ssavekartu(loaded.nokartu, temp);
            ssaveperbulankeluar(loaded.nokartu, tempmon);
            ssavepertahunkeluar(loaded.nokartu, tempyear);
        }
        else if(opsi == '7' )
        {
            MenuPelayanan(loaded);
        }
        else if (opsi == '8')
        {
            opsimutasi(monthly, yearly);
        }
        else if (opsi == '9')
        {
            informasi(loaded);
        }
        else if (opsi == '0')
        {
            exit(1);
        }
        else
        {
            printf("Input tidak valid");
            Sleep(1500);
            system("cls");
            goto retry;
        }
    }
    else
    {
        printf("KARTU ANDA TELAH TERBLOKIR!\n");
        Sleep(3000);
        exit(1);
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
    limit newlim;
    mutasi monthly;
    mutasi yearly;
    int tahun;
    int bulan;
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
    
    strcpy(newlim.nokartu, new->nokartu);
    gettgl(&newlim.tgl);
    newlim.tfhariini = 0;

    savelimit(newlim);

    memcpy(monthly.nokartu, new->nokartu, sizeof(monthly.nokartu));
    getbln(&bulan);
    monthly.periode = bulan;
    monthly.masuk = 0;
    monthly.keluar = 0;
    newmonthlymutasi(monthly);

    memcpy(yearly.nokartu, new->nokartu, sizeof(yearly.nokartu));
    getthn(&tahun);
    yearly.periode = tahun;
    yearly.masuk = 0;
    yearly.keluar = 0;
    newyearlymutasi(yearly);
	
	printf("\nNomor kartu anda adalah %s", new->nokartu);
	printf("\nNomor rekening anda adalah %s", new->norek);
	printf("\nSaldo anda adalah %d", new->saldo);
	printf("\nNama anda dalam kartu adalah %s", new->nama);
	printf("\nPin anda %s", new->pin);
	printf("\nTipe kartu anda adalah %d", new->tipekartu);
	printf("\nStatus kartu anda adalah %d", new->statuskartu);
	printf("\nGmail kartu anda adalah %s", new->gmail);
}

void login(akun* diload, limit* loadedlim, mutasi* monthly, mutasi* yearly)
{
    char nokartuisi[17];
    char pininput[7];
    akun temp;
    limit templim;
    mutasi tempmon;
    mutasi tempyear;
    int i = 1;
    
    isikartu:
    printf("\nMasukan Nomor Kartu..... (16 digit)\n");
    fgets(nokartuisi, sizeof(nokartuisi), stdin);
    nokartuisi[strcspn(nokartuisi, "\n")] = 0;
    fflush(stdin);
    sloadkartu(nokartuisi, &temp);
    sloadlimit(nokartuisi, &templim);
    sloadperbulan(nokartuisi, &tempmon);
    sloadpertahun(nokartuisi, &tempyear);
    if(strcmp(nokartuisi, temp.nokartu) == 0)
    {
		if(temp.statuskartu == 0)
		{
			printf("Kartu anda diblokir, harap kunjungi KCP terdekat\nUntuk membuka blokir!");
			exit(1);
		}
		printf("Masukan Pin..... (6 digit)\n");   
        while(i<=3)
            {
                fgets(pininput, sizeof(pininput), stdin);
                pininput[strcspn(pininput, "\n")] = 0;
                fflush(stdin);
                if(strcmp(pininput, temp.pin) == 0)
                {
                    printf("\nPin Benar");
					*diload = temp;
                    *loadedlim = templim;
                    *monthly = tempmon;
                    *yearly = tempyear;
                    goto done;
                } else
                printf("Pin Salah!, Masukan Pin kembali!\n");
                ++i;
            }
		blokirakun(nokartuisi);
    }
    else
    {
        goto isikartu;
    }
    done:
}


void masukKartuATM()
{
	char masukKartu;
    akun regis;
    waktu sekarang;

    getsaatini(&sekarang.tgl, &sekarang.bln, &sekarang.thn);
    printf("\n%d/%02d/%d\n", sekarang.tgl, sekarang.bln, sekarang.thn);
	printf("SELAMAT DATANG DI ATM BANK BAWA CUAN AMAN\n\n");
	printf("SILAHKAN MASUKKAN KARTU ANDA...\n");
	
	masukKartu:	
	printf("TEKAN 'ENTER' UNTUK MEMASUKKAN KARTU\nTEKAN 'N' UNTUK REGISTRASI\nUNTUK BANTUAN TEKAN 'Y'\nUNTUK KELUAR TEKAN 'X'\nOpsi: ");

	masukKartu = fgetc(stdin);
    fflush(stdin);

	if (masukKartu == '\n') 
	{
		printf("KARTU BERHASIL DIMASUKKAN. SELAMAT DATANG DI LAYANAN ATM BCA\n");
	} 
    else if (masukKartu == 'n' || masukKartu == 'N')
    {
        buatakun(&regis);
        saveakun(regis);
        exit(1);
    }
    else if (masukKartu == 'y' || masukKartu == 'Y')
    {
        char helpkartu[17];
        akun help;
        printf("Masukan nomor kartu anda!\n");
        fgets(helpkartu, sizeof(helpkartu), stdin);
        helpkartu[strcspn(helpkartu, "\n")] = 0;
        fflush(stdin);
        sloadkartu(helpkartu, &help);
        MenuPelayanan(help);
    }
    else if (masukKartu == 'X' || masukKartu == 'x')
    {
        exit(1);
    }
	else 
	{
		printf("ANDA BELUM MEMASUKKAN KARTU. SILAHKAN COBA LAGI.\n");
		
		while (getchar() != '\n');
		
		goto masukKartu;
	}
	
}

#endif