#include <math.h>
#include <stdio.h>

int main() {
  double a, b, c, x, S;
  printf("\n Input c,x \n");
  scanf("%f%f", &c, &x);
  x = x / 180 * 3.14159265; // первод из градусов в радианы
  a = c * sin(x);
  b = c * cos(x);
  S = a * b / 2;
  printf("\n Output: a=%7.2f     b=%7.2f   c=%7.2f      S=%7.2f ", a, b, c, S);
  return 0;
}
