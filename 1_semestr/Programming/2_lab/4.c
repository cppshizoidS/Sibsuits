#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define N 8

int main() {
  int a[N], i, neg, pos, zero;
  neg = 0;
  pos = 0;
  zero = 0;
  for (i = 0; i < N; i++) {
    a[i] = rand() % 10 - 5;
    printf("%3d", a[i]);
    if (a[i] > 0)
      pos += 1;
    else if (a[i] < 0)
      neg += 1;
    else
      zero += 1;
  }
  printf("\nPositive: %d\n", pos);
  printf("Negative: %d\n", neg);
  printf("Equal to zero: %d\n", zero);
}
