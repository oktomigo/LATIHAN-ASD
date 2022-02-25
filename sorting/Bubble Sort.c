#include <stdio.h>
#include <stdlib.h>

void bubble_Sort(int arr[], int input){
  int i, j, tmp;
  for(i = 0; i < input; i++){
    for(j=0; j<input-i-1; j ++){
      if(arr[j] > arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}

void cetak(int array[],int input){
    for(int i=0; i<input; i++){
        printf("%d ", array[i]);
    }
}

void main(){
    int array[100],input;
    printf("Masukkan banyak elemen array yang anda inginkan: ");
    scanf("%d", &input);printf("\n");

    for(int i=0; i<input; i++){
        printf("Masukkan nilai array %d:",i);
        scanf("%d", &array[i]);
    }
    bubble_Sort(array,input);
    printf("\nHasil pengurutan array:\n");
    cetak(array,input);
    printf("\n");
}
