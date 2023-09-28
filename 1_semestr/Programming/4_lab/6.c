#include <math.h>
#include <stdio.h>

int main() {
  //(n=20, s=-10)
  int n, s = 0;
  printf("Input N: ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    s += pow((-1), (i + 1)) * i;
  }
  printf("S= %d \n", (s));
}
