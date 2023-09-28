#include <math.h>
#include <stdio.h>

int main() {
  // enter 5 10
  float S = 1, x, N;
  int F = 1;
  printf("Input x, N: ");
  scanf("%f%f", &x, &N);
  for (int i = 1; i <= N; i++) {
    F *= i;
    S += (pow(x, i) / F);
  }
  printf("S= %.2f \n", S);
}
