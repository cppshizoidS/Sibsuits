#include <math.h>
#include <stdio.h>

int main() {
  float S, s, x, n = 0.02;
  // x=1, s=0.236
  printf("Input X: ");
  scanf("%f", &x);
  for (int i = 1; i < 11; i++) {
    s = ((0.16 + n) * x);
    S += pow(s, i);
    n += 0.02;
  }
  printf("S= %.3f \n", S);
}
