#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct{
    int data[MAX];
    int head;
    int tail;
}Queue;

Queue antri;

void Awal(){
    antri.head = antri.tail = -1;
}

int Kosong(){
    if(antri.tail==-1){
        return 1;//artinya kosong
    }else{
        return 0;
    }
}

int Penuh(){
    if(antri.tail== MAX-1){
        return 1;//artinya true
    }else{
        return 0;//artinya false
    }
}

void Masuk(int data){
    if(Kosong()==1){
        antri.head = antri.tail = 0;
        antri.data[antri.tail] = data;
        printf(" %d Masuk",antri.data[antri.tail]);getch();
        /*void tampil(){
            if(Kosong()==0){
                for(int i=antri.head; i<=antri.tail; i++){
                    printf("%d\n",antri.data[i]);
                }
            }else{
                printf(" Antrian kosong!");
            }
        }*/
    }else if(Penuh()==0){
        antri.tail++;
        antri.data[antri.tail] = data;
        printf(" %d Masuk",antri.data[antri.tail]);getch();
    }
}

int Keluar(){
    int d = antri.data[antri.head];
	int i;
    for(i=antri.head; i<=antri.tail-1; i++){
        antri.data[i] = antri.data[i+1];
    }
    antri.tail--;
    return d;
}

void tampil(){
	int i;
    if(Kosong()==0){
        for(i=antri.head; i<=antri.tail; i++){
            printf(" %d\n",antri.data[i]);
        }getch();
    }else{
        printf(" Antrian kosong!");getch();
    }
}

void Hapus(){
	antri.head=antri.tail=-1;
    printf(" data dalam antrian sudah terhapus!");getch();
}

int main(){
    int pilih;
    int data;
    Awal();
    do{
        system("cls");
		printf("\n 1. Masukan satu data\n 2. keluar satu data\n 3. Lihat isi data\n 4. Hapus isi antrian\n 5. Keluar\n");
        printf("\n Masukan pilihanmu :");
        scanf("%d",&pilih);

        switch(pilih){
            case 1:
                printf(" Data = ");
                scanf("%d",&data);
                Masuk(data);
            break;
            case 2:
                printf(" Data yang keluar : %d",Keluar());getch();
            break;
            case 3:
                tampil();
            break;
            case 4:
                Hapus();
        }
    }while(pilih!=5);
}
