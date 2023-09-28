#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  double x, y, t, z;

  // 1
  y = 2;
  t = 5 / (1 + pow(y, 2));
  z = 4;
  x = 2 * y + 3 * sinh(t) - z;
  printf("x = %.2lf\n", x);

  // 2
  t = 0.5;
  z = 6;
  y = t + 2 * (1 / tan(z));
  x = 3 * pow(y, 2) / (4 * tan(z) - 2 * pow(t, 2));
  printf("x = %.2lf\n", x);

  // 3
  t = 1;
  z = 3;
  y = sin(t);
  x = 4 * pow(y, 2) / (4 * y * exp(z) - 2 * pow(t, 3));
  printf("x = %.2lf\n", x);

  // 4
  t = 2;
  z = 3;
  y = cos(t + z);
  x = 4 * log(pow(y, 3)) - z / t;
  printf("x = %.2lf\n", x);

  // 5
  y = 2;
  z = 4;
  t = sin(2 + z);
  x = 6 * pow(t, 2) - (1 / tan(z) + 1) / pow(y, 2);
  printf("x = %.4lf\n", x);

  // 6
  t = 2;
  z = 1;
  y = tan(t) + z;
  x = (8 * pow(z, 2) + 1) / (y * exp(t) + pow(t, 2));
  printf("x = %.2lf\n", x);

  return 0;
}
