#include <math.h>
#include <stdio.h>

int main() {
  // m=5, P=120
  int P = 1, m;
  printf("Input M: ");
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    P *= i;
  }
  printf("P= %d \n", P);
}
