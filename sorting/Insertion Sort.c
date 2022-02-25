#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int array[], int jumlah){
    int room,j;
    for (int i=1; i<=jumlah; i++){
    j=i;
    while(j>0&&array[j-1]>array[j]){
      room=array[j];
      array[j]=array[j-1];
      array[j-1]=room;
      j--;
    }
  }
}
void hasil(int array[],int jumlah){
    printf("\nHasil pengurutan sebagai berikut:\n");
    for (int i=0; i<jumlah; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void main(){
    int jumlah,array[100];
    printf("Masukkan jumlah array yang anda inginkan : ");
    scanf("%d",&jumlah);
    printf("\n");

    for(int i=0; i<jumlah; i++){
        printf("Masukkan array pada index %d :",i);
        scanf("%d",&array[i]);
    }
    insertion_sort(array, jumlah);
    hasil(array, jumlah);
}
