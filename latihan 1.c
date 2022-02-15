#include <stdio.h>
#include <stdlib.h>

void main(){

    int input,posisi;
    int i,angka[i],dicari1,dicari2;

    printf("Berapa banyak data yang ingin disimpan : ");
    scanf("%d",&input);
    printf("Masukan data :\n");
    for(i=1; i<=input; i++){
        scanf(" %d",&angka[i]);
    }
    printf("\nData yang mau dicari? ");
    scanf("%d",&dicari1);
    printf("\nData yang mau dicari? ");
    scanf("%d",&dicari2);

    for(i=0; i<input; i++){
        if(angka[i]==dicari1){
            printf("\nData %d ditemukan di lokasi %d",dicari1,i);
        }
        if(angka[i]==dicari2){
            printf("\nData %d ditemukan di lokasi %d\n",dicari2,i);
        }
    }

}
