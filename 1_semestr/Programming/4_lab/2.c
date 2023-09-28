#include <math.h>
#include <stdio.h>

int main() {
  // S= sin1 + sin 2 +...+ sin25;  (s=-0.058)
  float S = 0;
  for (int i = 1; i < 26; i++) {
    S += sin(i);
  }
  printf("S= %.3f \n", S);
}
