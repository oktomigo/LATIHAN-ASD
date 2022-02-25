#include <stdio.h>
#include <stdlib.h>

int choice;
int array[8]={23,67,89,5,45,20,15,27};

void selection_sort(){
    int tem_awal, tukar;
    printf("\n");
    printf(" array sebelum diurutkan dengan menggunakan selection sort : ");
    for(int i=0; i<8; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    for(int i=0; i<8; i++){
        tem_awal=i;
        for (int j=i+1; j<8; j++){
            if(array[tem_awal]>array[j]){
            tem_awal=j;
            }
        }
        if(tem_awal!=i){
            tukar=array[i];
            array[i] = array[tem_awal];
            array[tem_awal]=tukar;
        }
    }
    hasil();
}

void insertion_sort(){
    int room,j;
    printf("\n");
    printf(" array sebelum diurutkan dengan insertion sort : ");
    for(int i=0; i<8; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    for (int i=1; i<8; i++){
    j=i;
    while(j>0&&array[j-1]>array[j]){
      room=array[j];
      array[j]=array[j-1];
      array[j-1]=room;
      j--;
    }
  }
  hasil();
}

void hasil(){

    printf("\n");
    printf(" Hasil dari pengurutan array adalah : ");
    for(int i=0; i<8; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    getch();main();
}

void menu(){
    printf("\n1. Selection sort\n2. insertion sort\n3. keluar\n");
    printf("Masukan pilihan anda : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:system("cls");selection_sort();break;
        case 2:system("cls");insertion_sort();break;
        case 3:system("cls");printf("tekan apa saja untuk keluar");getch();break;
        default:
            printf("Menu yang anda pilih tidak tersedia!!\n");menu();
    }
}

void main(){
    system("cls");
    for(int a=1; a<=25; a++){
        printf("=");
    }
    printf("\n=\tMENU UTAMA\t=\n");
    for(int b=1; b<=25; b++){
        printf("=");
    }
    menu();
}
