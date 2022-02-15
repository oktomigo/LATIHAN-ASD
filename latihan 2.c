#include <stdio.h>

int cariangka(int angka[], int x, int bil_rendah, int bil_tinggi) {
  while (bil_rendah <= bil_tinggi) {
    int bil_tengah = bil_rendah + (bil_tinggi - bil_rendah) / 2;

    if (angka[bil_tengah] == x)
      return bil_tengah;

    if (angka[bil_tengah] < x)
      bil_rendah = bil_tengah + 1;

    else
      bil_tinggi = bil_tengah - 1;
  }

  return -1;
}

int main(void) {
  int angka[] = {3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(angka) / sizeof(angka[0]);
  int x = 7;
  int result = cariangka(angka, x, 0, n - 1);
  if (result == -1)
    printf("angka tidak ditemukan");
  else
    printf("elemen ditemukan pada index %d", result);
  return 0;
}

