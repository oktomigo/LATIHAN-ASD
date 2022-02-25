#include <stdio.h>
#include <stdlib.h>

void selection_Sort(int array[], int input){
    int tem_awal, tukar;
    for(int i=0; i<(input-1); i++){
        tem_awal=i;
        for (int j=i+1; j<input; j++){
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
}

void main(){
    int input,array[100];

    printf("Masukan jumlah array yang anda inginkan : ");
    scanf("%d",&input);
    printf("\n");
    for(int i=0; i<input; i++){
        printf("masukan array dengan index %d :",i);
        scanf(" %d",&array[i]);
    }
    selection_Sort(array,input);
    printf("\n");
    printf("Hasil dari pengurutan array adalah : ");
    for(int i=0; i<input; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
