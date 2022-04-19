#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//animasi loading
#include <windows.h>
#include <unistd.h>//LIBERALY SLEEP/USLEEP
#include <string.h>
#include <time.h>

/*
TR INI DIRANCANG OLEH:
-OKTOMIGO 672021072
-BILEAM MANGALLA 672021056
-ERNEST GLORIUS DEO 672021074
*/

struct node{
    char nama[50], jenis[50];
    int id, jumlah;
    long harga;
    struct node *next;
}*kepala, *ekor, *sekarang;

int top=0;
char un[50],pw[];

void main(){
    int choice;
    masuk();
    login();
    do{
        system("cls");
        int hours, minutes, seconds, day, month, year;
        time_t now;
        time(&now);
        struct tm *local = localtime(&now);
        hours = local->tm_hour;
        minutes = local->tm_min;
        seconds = local->tm_sec;
        day = local->tm_mday;
        month = local->tm_mon + 1;
        year = local->tm_year + 1900;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        printf("\n\n\t\t\t\t\t\t\t\t\t %02d/%02d/%d\n", day, month, year);
        if (hours < 12) {
            printf("\t\t\t\t\t\t\t\t        %02d:%02d:%02d am\n", hours, minutes, seconds);
        }else {    // after midday
            printf("\t\t\t\t\t\t\t\t        %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        printf("\t\t\t\t  =================================================\n");
        printf("\t\t\t\t  =======  SELAMAT DATANG DI TOKO GOODHAND  =======\n");
        printf("\t\t\t\t  ====  TOKO KHUSUS MAINAN DAN ANEKA PAJANGAN  ====\n");
        printf("\t\t\t\t  =================================================\n");
        printf("\t\t\t\t  = 1. Masukan data\t\t\t\t  =\n");
        printf("\t\t\t\t  = 2. Lihat data\t\t\t\t  =\n");
        printf("\t\t\t\t  = 3. hapus data\t\t\t\t  =\n");
        printf("\t\t\t\t  = 4. Sorting data\t\t\t\t  =\n");
        printf("\t\t\t\t  = 5. Searching data\t\t\t\t  =\n");
        printf("\t\t\t\t  = 6. update data\t\t\t\t  =\n");
        printf("\t\t\t\t  = 7. Keluar\t\t\t\t\t  =\n");
        printf("\t\t\t\t  =================================================\n");
        printf("\t\t\t\t  pilihanmu :");
        scanf("%d",&choice);
        switch(choice){
            case 1: input_Data();getch();break;
            case 2: Lihat_Data();getch();break;
            case 3: deleteData();getch();break;
            case 4: sorting();getch();break;
            case 5: searching();getch();break;
            case 6: update_Data();break;
            case 7: break;
            default : system("cls");printf("\n\n\t\t\t\t  Inputan Salah\n\n");getch();break;
        }
    }while(choice != 7);keluar();getch();
}

void login(){
    int a;
    do{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        system("cls");
        int hours, minutes, seconds, day, month, year;
        time_t now;
        time(&now);
        struct tm *local = localtime(&now);
        hours = local->tm_hour;
        minutes = local->tm_min;
        seconds = local->tm_sec;
        day = local->tm_mday;
        month = local->tm_mon + 1;
        year = local->tm_year + 1900;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        printf("\n\n\n\t\t\t\t\t\t\t\t\t%02d/%02d/%d\n", day, month, year);
        if (hours < 12) {
            printf("\t\t\t\t\t\t\t\t       %02d:%02d:%02d am\n", hours, minutes, seconds);
        }else {    // after midday
            printf("\t\t\t\t\t\t\t\t       %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        printf("\t\t\t\t  ================================================\n");
        printf("\t\t\t\t  ==============  SILAHKAN LOGIN  ================\n");
        printf("\t\t\t\t  ================================================\n");

        printf("\t\t\t\t  => Username : ");scanf(" %[^\n]s",&un);
        printf("\t\t\t\t  => Password : ");scanf(" %s",&pw);
            if(strcmp(un,"goodhand")==0&&strcmp(pw,"fasthand")==0){
                a=2;
                system("cls");
                loding();
                getch();
            }
            else{
                printf("\t\t\t\t  Username dan Password anda salah!");getch();
            }
    }while(a!=2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}

int masuk(){
    int x; double y;
    char salam[]="\t\t\t\t       Selamat datang diprogram toko sederhana kami!!\n\t\t\tSebelum lanjut kemenu utama silahkan anda untuk login terlebih dahulu!!";

    printf("\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    for(x=0; salam[x]!=NULL; x++){
        printf("%c",salam[x]);
        for(y=0; y<=9999999; y++){
        }
    }
    getch();
}

void loding(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("\n\n\n\n\t\t\t\t\t\t\t LOADING...");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    printf("\n\t\t\t\t\t      ");
    for(int i=0; i<30; i++){
        printf("%c",219);
        Sleep(100);
    }
    system("cls");
    printf("\n\n\n\t\t\t\t        ANDA BERHASIL LOGIN, SILAHKAN TEKAN ENTER!");getch();
}

int keluar(){
    int x; double y;

    system ("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    char salam[]="\n\t\t\t\t\tPEMBUAT :";
    char nama[]="\t\t\t\t\tBILEAM MANGALLA\n\t\t\t\t\t672021056\n\n\t\t\t\t\tOKTOMIGO\n\t\t\t\t\t672021072\n\n\t\t\t\t\tERNEST GLORIUS DEO\n\t\t\t\t\t672021074";
    int t; double k;
    char ending[]="\t\t\t\t\t\t      TERIMA KASIH :)\n\t\t\t\t\t    SAMPAI JUMPA LAGI SEASON DEPAN!!";


    printf("\n\n\n");
    for(x=0; salam[x]!=NULL; x++){
        printf("%c",salam[x]);
        for(y=0; y<=9999; y++)
        {
        }
    }
    printf("\n");
    for(x=0; nama[x]!=NULL; x++){
        printf("%c",nama[x]);
        for(y=0; y<=99999995; y++)
        {
        }
    }
    getch();system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    for(t=0; ending[t]!=NULL; t++){
            printf("%c",ending[t]);
            for(k=0; k<=99999997; k++){

            }
        }
    printf("\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    return 0;
}//bileam

void input_Data(){
    char nama [30], nim [10], fakultas [30], hobi [30];
    int ya;
    FILE *out=fopen("goodhand.txt","a");
    sekarang = (struct node*)malloc(sizeof(struct node));
    system("cls");
    printf("\n\n\t\t\t\t    Masukan ID barang   : ");
    scanf(" %d",&(sekarang->id));
    fflush(stdin);
    printf("\t\t\t\t    Masukan nama barang   : ");
    scanf(" %[^\n]",&(sekarang->nama));
    fflush(stdin);
    printf("\t\t\t\t    Masukan jenis barang  : ");
    scanf(" %[^\n]",&(sekarang->jenis));
    fflush(stdin);
    printf("\t\t\t\t    Masukan jumlah barang : ");
    scanf(" %d",&(sekarang->jumlah));
    fflush(stdin);
    printf("\t\t\t\t    Masukan harga barang  : ");
    scanf(" %d",&(sekarang->harga));


    if(kepala == NULL){
        kepala = ekor = sekarang;
    }else{
        ekor->next = sekarang;
        ekor = sekarang;
    }
    top=top+1;
    ekor->next = NULL;
    fprintf(out,"%d      %s        %s       %d      %d\n",sekarang->id,sekarang->nama,sekarang->jenis,sekarang->jumlah,sekarang->harga);
    fclose(out);
    system("cls");
    printf("\n\n\t\t\t\t    Data berhasil diinput!");getch();
}

void update_Data(){//okto
    char nama [30], nim [10], fakultas [30], hobi [30];
    int idd;
    if(kepala == NULL){
        system("cls");
        printf("\n\n\t\t\t\t    Belum ada Data untuk diupdate, silahkan input dulu!");
    }else{
        sekarang = (struct node*)malloc(sizeof(struct node));
        system("cls");
        FILE *out=fopen("goodhand.txt","a+");
         do{
            system("cls");
            printf("\n\n\n\n\t\t\t\t  =================================================\n");
            printf("\t\t\t\t  =================  UPDATE DATA   ================\n");
            printf("\t\t\t\t  =================================================\n");
            printf("\t\t\t\t  = 1.tambah data\t\t\t\t  =\n");
            printf("\t\t\t\t  = 2.format data(khusus database)\t\t  =\n");
            printf("\t\t\t\t  = 3.kembali kemenu utama\t\t\t  =\n");
            printf("\t\t\t\t  =================================================\n");
            printf("\t\t\t\t  Pilihan : ");
            scanf("%d",&idd);
            if(idd==1){
                FILE *out=fopen("goodhand.txt","a+");
                system("cls");
                printf("\n\n\t\t\t\t    Masukan ID barang   : ");
                scanf(" %d",&(sekarang->id));
                fflush(stdin);
                printf("\t\t\t\t    Masukan nama barang   : ");
                scanf(" %[^\n]",&(sekarang->nama));
                fflush(stdin);
                printf("\t\t\t\t    Masukan jenis barang  : ");
                scanf(" %[^\n]",&(sekarang->jenis));
                fflush(stdin);
                printf("\t\t\t\t    Masukan jumlah barang : ");
                scanf(" %d",&(sekarang->jumlah));
                fflush(stdin);
                printf("\t\t\t\t    Masukan harga barang  : ");
                scanf(" %d",&(sekarang->harga));
                if(kepala == NULL){
                    kepala = ekor = sekarang;
                }else{
                    ekor->next = sekarang;
                    ekor = sekarang;
                }
                ekor->next = NULL;
                system("cls");
                fprintf(out,"%d      %s        %s       %d      %d\n",sekarang->id,sekarang->nama,sekarang->jenis,sekarang->jumlah,sekarang->harga);
                fclose(out);
                printf("\n\n\t\t\t\t    Data telah berhasil diupdate!");
                getch();
            }
            else if(idd==2){
                FILE *out=fopen("goodhand.txt","w");
                system("cls");
                printf("\n\n\t\t\t\t    Masukan ID barang   : ");
                scanf(" %d",&(sekarang->id));
                fflush(stdin);
                printf("\t\t\t\t    Masukan nama barang   : ");
                scanf(" %[^\n]",&(sekarang->nama));
                fflush(stdin);
                printf("\t\t\t\t    Masukan jenis barang  : ");
                scanf(" %[^\n]",&(sekarang->jenis));
                fflush(stdin);
                printf("\t\t\t\t    Masukan jumlah barang : ");
                scanf(" %d",&(sekarang->jumlah));
                fflush(stdin);
                printf("\t\t\t\t    Masukan harga barang  : ");
                scanf(" %d",&(sekarang->harga));
                if(kepala == NULL){
                    kepala = ekor = sekarang;
                }else{
                    ekor->next = sekarang;
                    ekor = sekarang;
                }
                ekor->next = NULL;
                system("cls");
                fprintf(out,"%d      %s        %s       %d      %d\n",sekarang->id,sekarang->nama,sekarang->jenis,sekarang->jumlah,sekarang->harga);
                fclose(out);
                printf("\n\n\t\t\t\t    Data telah berhasil diupdate!");
                getch();
            }
            else if(idd==3){
                getch();break;
            }else{
                system("cls");printf("\n\n\n\t\t\t\t    menu tidak ada!");getch();
            }
        }while(idd!=3);
    }
}

void Lihat_Data(){
    if(kepala == NULL){
        system("cls");
        printf("\n\n\t\t\t\t    Belum ada Data, silahkan input dulu!");
    }else{
        system("cls");
        sekarang = kepala;
        int i=0;

        printf("\n\n\t\t\t\t\t\t  ***DAFTAR BARANG***");
        printf("\n\t\t =========================================================================================\n");
        printf("\t\t | No|  id|                nama|              jenis|            jumlah|             harga|\n");
        printf("\t\t =========================================================================================\n");
        while(sekarang != NULL){
            printf("\t\t | %d |%4d|%20s|%19s|%18d|%18d|\n",i+1,sekarang->id,sekarang->nama,sekarang->jenis,sekarang->jumlah,sekarang->harga);
            printf("\t\t =========================================================================================\n");
            sekarang = sekarang->next;
            i++;
        }
        //printf("\n\n\t\t\t\t\tData setelah diupdate()Data dalam text!\n\n");
        //char buff[255];
        /*FILE *fptr=fopen("goodhand.txt","r");
        while(fgets(buff, sizeof(buff), fptr)){
            printf("\n\t\t\t\t\t   %s\n", buff);
        }
        // tutup file
        fclose(fptr);*/
    }
}

void deleteData(){
    if (kepala == NULL){
        system("cls");
        printf("\n\n\t\t\t\t    Belum ada Data, silahkan input dulu!");
    }else{
        struct node *temp = kepala;
        sekarang = kepala;
        int idd;
        system("cls");
        printf("\n\n\t\t\t\t    Cari id data yang mau dihapus : ");
        scanf("%d",&idd);
        int index = 0;
        while (sekarang != NULL) {
            if (sekarang->id==idd){
                break;
            }
            index++;
            sekarang = sekarang->next;
        }
        if (index == 0){
            kepala = temp->next;
            free(temp);
            system("cls");
            printf("\n\n\t\t\t\t    Data berhasil dihapus!");
        }else{
            //nyari dan mindahin posisi temp ke data yang mau dicari
            for (int i=1; temp!=NULL && i<index; i++){
                temp = temp->next;
            }
            if (temp == NULL || temp->next == NULL){
                system("cls");
                printf("\n\n\t\t\t\t    Data tidak ada!");
            }else{
                struct node *next = temp->next->next;
                free(temp->next);
                temp->next = next;
                system("cls");
                printf("\n\n\t\t\t\t    Data berhasil dihapus!");
            }
        }
    }
}


void sorting(){
    char nama[50][50],jenis[50][50];
    int id[50],jumlah[50];
    long harga[50];
    // sorting bubblesort semua
    sekarang = kepala;
    for (int i=0;i<top;i++){
        strcpy( nama[i], sekarang->nama);
        strcpy(jenis[i], sekarang->jenis);
        id[i]=sekarang->id;
        jumlah[i]=sekarang->jumlah;
        harga[i]=sekarang->harga;
        sekarang = sekarang->next;
    }
    int a;
    if(kepala == NULL){
        system("cls");
        printf("\n\n\t\t\t\t    Belum ada Data, silahkan input dulu!");
    }else{
        do{
            system("cls");
            printf("\n\n\n\n\t\t\t\t  =================================================\n");
            printf("\t\t\t\t  ===================  SORTING   ==================\n");
            printf("\t\t\t\t  =================================================\n");
            printf("\t\t\t\t  = 1. urutkan berdasarkan id\t\t\t  =\n");
            printf("\t\t\t\t  = 2. urutkan berdasarkan nama\t\t\t  =\n");
            printf("\t\t\t\t  = 3. urutkan berdasarkan jumlah\t\t  =\n");
            printf("\t\t\t\t  = 4. urutkan berdasarkan harga\t\t  =\n");
            printf("\t\t\t\t  = 5. exit\t\t\t\t\t  =\n");
            printf("\t\t\t\t  =================================================\n");
            printf("\t\t\t\t  Pilihan : ");
            scanf("%d",&a);
            if (a==1){
                system("cls");
                sortbyid(nama,jenis,id,jumlah,harga,top );
                printf("\n\n\t\t\t\t\t\t  *DAFTAR BARANG*");
                printf("\n\t\t =====================================================================================\n");
                printf("\t\t |  id|                nama|              jenis|            jumlah|             harga|\n");
                printf("\t\t =====================================================================================\n");
                for (int i=0; i<top;i++){
                    printf("\t\t |%4d|%20s|%19s|%18d|%18d|\n", id[i],nama[i],jenis[i],jumlah[i],harga[i]);
                }
                printf("\t\t =====================================================================================\n");
                getch();
            }
            else if (a==2){
                system("cls");
                sortbyname (nama,jenis,id,jumlah,harga,top );
                printf("\n\n\t\t\t\t\t\t  *DAFTAR BARANG*");
                printf("\n\t\t =====================================================================================\n");
                printf("\t\t |  id|                nama|              jenis|            jumlah|             harga|\n");
                printf("\t\t =====================================================================================\n");
                for (int i=0; i<top;i++){
                    printf("\t\t |%4d|%20s|%19s|%18d|%18d|\n", id[i],nama[i],jenis[i],jumlah[i],harga[i]);
                }
                printf("\t\t =====================================================================================\n");
                getch();
            }
            else if(a==3) {
                system("cls");
                shortbyjumlah(nama,jenis,id,jumlah,harga,top );
                printf("\n\n\t\t\t\t\t\t  *DAFTAR BARANG*");
                printf("\n\t\t =====================================================================================\n");
                printf("\t\t |  id|                nama|              jenis|            jumlah|             harga|\n");
                printf("\t\t =====================================================================================\n");
                for (int i=0; i<top;i++){
                    printf("\t\t |%4d|%20s|%19s|%18d|%18d|\n", id[i],nama[i],jenis[i],jumlah[i],harga[i]);
                }
                printf("\t\t =====================================================================================\n");
                getch();
            }
            else if (a==4){
                system("cls");
                sortbyharga(nama,jenis,id,jumlah,harga,top );
                printf("\n\n\t\t\t\t\t\t  *DAFTAR BARANG*");
                printf("\n\t\t =====================================================================================\n");
                printf("\t\t |  id|                nama|              jenis|            jumlah|             harga|\n");
                printf("\t\t =====================================================================================\n");
                for (int i=0; i<top;i++){
                    printf("\t\t |%4d|%20s|%19s|%18d|%18d|\n", id[i],nama[i],jenis[i],jumlah[i],harga[i]);
                }
                printf("\t\t =====================================================================================\n");
                getch();
            }else{
                break;
            }
        }while(a!=5);
    }
}

void shortbyjumlah (char nama[50][50],char jenis[50][50],int id[50], int jumlah[50],long harga[50], int n)
{
    int i, j, temp1, temp2;
    char temp3[50],temp4[50];
    long temp5;


    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (jumlah[j] > jumlah[j + 1])
            {
                temp1 = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp1;

                temp2 = jumlah[j];
                jumlah[j] = jumlah[j + 1];
                jumlah[j + 1] = temp2;

                strcpy(temp3,nama[j]);
                strcpy(nama[j],nama[j + 1]);
                strcpy(nama[j + 1], temp3);

                strcpy(temp4,jenis[j]);
                strcpy(jenis[j],jenis[j + 1]);
                strcpy(jenis[j + 1], temp4);

                temp5 = harga[j];
                harga[j] = harga[j + 1];
                harga[j + 1] = temp5;


            }

        }
    }
}


void sortbyharga(char nama[50][50],char jenis[50][50],int id[50], int jumlah[50],long harga[50], int n)
{
    int i, j, temp1, temp2;
    char temp3[50],temp4[50];
    long temp5;


    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (harga[j] > harga[j + 1])
            {
                temp1 = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp1;

                temp2 = jumlah[j];
                jumlah[j] = jumlah[j + 1];
                jumlah[j + 1] = temp2;

                strcpy(temp3,nama[j]);
                strcpy(nama[j],nama[j + 1]);
                strcpy(nama[j + 1], temp3);

                strcpy(temp4,jenis[j]);
                strcpy(jenis[j],jenis[j + 1]);
                strcpy(jenis[j + 1], temp4);

                temp5 = harga[j];
                harga[j] = harga[j + 1];
                harga[j + 1] = temp5;


            }

        }
    }
}

void sortbyid (char nama[50][50],char jenis[50][50],int id[50], int jumlah[50],long harga[50], int n)
{
    int i, j, temp1, temp2;
    char temp3[50],temp4[50];
    long temp5;


    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (id[j] > id[j + 1])
            {
                temp1 = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp1;

                temp2 = jumlah[j];
                jumlah[j] = jumlah[j + 1];
                jumlah[j + 1] = temp2;

                strcpy(temp3,nama[j]);
                strcpy(nama[j],nama[j + 1]);
                strcpy(nama[j + 1], temp3);

                strcpy(temp4,jenis[j]);
                strcpy(jenis[j],jenis[j + 1]);
                strcpy(jenis[j + 1], temp4);

                temp5 = harga[j];
                harga[j] = harga[j + 1];
                harga[j + 1] = temp5;


            }

        }
    }
}


void sortbyname(char nama[50][50],char jenis[50][50],int id[50], int jumlah[50],long harga[50], int n){
    int temp1, temp2;
    char temp3[50],temp4[50];
    long temp5;
    for (int i=1;i<=n;i++){
        for (int j=i;j<n;j++){
            for (int l=0;l<50;l++){
                if (nama[i-1][l]<nama[j][l]){

                    break;}
                else if(nama[i-1][l]>nama[j][l]){

                temp1 = id[i - 1];
                id[i - 1] = id[j];
                id[j] = temp1;

                temp2 = jumlah[i - 1];
                jumlah[1 - 1] = jumlah[j];
                jumlah[j] = temp2;

                strcpy(temp3,nama[i - 1]);
                strcpy(nama[i - 1],nama[j]);
                strcpy(nama[j], temp3);

                strcpy(temp4,jenis[i - 1]);
                strcpy(jenis[i - 1],jenis[j]);
                strcpy(jenis[j], temp4);

                temp5 = harga[i - 1];
                harga[i - 1] = harga[j];
                harga[j] = temp5;

                    break;}
            }
        }
    }
}

void searching(){
    int cari;

    if(kepala == NULL){
        system("cls");
        printf("\n\n\t\t\t\t    Belum ada Data, silahkan input dulu!");
    }else{
        do{
            system("cls");
            printf("\n\n\n\n\t\t\t\t  =================================================\n");
            printf("\t\t\t\t  ==================  SEARCHING   =================\n");
            printf("\t\t\t\t  =================================================\n");
            printf("\t\t\t\t   = 1. cari berdasarkan id  \t\t\t  =\n");
            printf("\t\t\t\t   = 2. cari berdasarkan nama\t\t\t  =\n");
            printf("\t\t\t\t   = 3. keluar\t\t\t                  =\n");
            printf("\t\t\t\t  =================================================\n");
            printf("\t\t\t\t  Pilihan : ");
            scanf("%d",&cari);
            if(cari==1){
                system("cls");
                searchbyid();getch();
            }
            else if(cari==2){
                system("cls");
                searchbynama();getch();
            }
            else if(cari==3){
                break;
            }
            else{
                system("cls");
                printf("\n\n\t\t\t\t    Masukan angka yang benar!");getch();
            }
        }while(cari!=3);
    }
}


void searchbyid(){
    int id;
    printf("\n\n\t\t\t\t    Masukan id yang ingin dicari :");
    scanf("%d",&id);
    sekarang = kepala;
    while (sekarang!=NULL){
        if(id==sekarang->id){
            system("cls");
            printf("\n\n\t\t\t\t\t\tdata telah ditemukan!");
            printf("\n\t\t =====================================================================================\n");
            printf("\t\t |  id|                nama|              jenis|            jumlah|             harga|\n");
            printf("\t\t =====================================================================================\n");
            printf("\t\t |%4d|%20s|%19s|%18d|%18d|\n", sekarang->id,sekarang->nama,sekarang->jenis,sekarang->jumlah,sekarang->harga);
            printf("\t\t =====================================================================================\n");
            getch();
        }
        else{
            printf("\n\n\t\t\t\t    data tidak ditemukan\n");getch();
        }
        sekarang=sekarang->next;
    }
}

void searchbynama()
{
    char nama[30];
    int i;
    printf("\n\n\t\t\t\t    Masukan nama yang ingin dicari :");
    scanf(" %[^\n]",&nama);
    sekarang = kepala;
    while (sekarang!=NULL)
    {
        if(strcmp(sekarang->nama,nama)==0){
            i=1;break;
        }
        sekarang=sekarang->next;
    }
    if(i==1){
        system("cls");
        printf("\n\n\t\t\t\t\t\tdata telah ditemukan!");
        printf("\n\t\t =====================================================================================\n");
        printf("\t\t |  id|                nama|              jenis|            jumlah|             harga|\n");
        printf("\t\t =====================================================================================\n");
        printf("\t\t |%4d|%20s|%19s|%18d|%18d|\n", sekarang->id,sekarang->nama,sekarang->jenis,sekarang->jumlah,sekarang->harga);
        printf("\t\t =====================================================================================\n");getch();
    }else{
         printf("\n\n\t\t\t\t    data tidak ditemukan\n");getch();
    }
}
