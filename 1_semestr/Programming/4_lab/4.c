#include <math.h>
#include <stdio.h>

int main(void) {
  float S = 0, x = 0.1;
  for (int i = 0; i < 10; i++) {
    S += log(x);
    x += 0.2;
    printf("S= %.3f \n", S);
  }
  return 0;
}
