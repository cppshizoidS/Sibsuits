#include <math.h>
#include <stdio.h>

int main() {
  // input 12
  // P= 2* 4* 6*...* 12;   (P=46080)
  int P = 1, x;
  printf("Input Number: ");
  scanf("%d", &x);
  for (int i = 2; i <= x; i += 2) {
    P *= i;
  }
  printf("P= %d \n", P);
}
