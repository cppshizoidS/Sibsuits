#include <stdio.h>
int main() {
  printf("Please enter 3 numbers\n");
  int k, m, n, x1;
  scanf("%d %d %d", &k, &m, &n);
  if (k < m && m < n)
    printf("%d<%d<%d", k, m, n);
  while (!(k < m && m < n)) {
    if (k > m) {
      x1 = m;
      m = k;
      k = x1;
    }
    if (m > n) {
      x1 = n;
      n = m;
      m = x1;
    }
  }
  printf("%d<%d<%d", k, m, n);
}
