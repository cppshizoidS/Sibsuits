#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int card, card2, c = 0, res = 0;
  printf("Number card: ");
  scanf("%d", &card);
  card2 = card;
  while (card2) {
    card2 /= 10;
    c++;
  }

  int arr[c];
  for (int i = c - 1; i >= 0; i--) {
    arr[i] = card % 10;
    card /= 10;
  }
  for (int i = 0; i < c; i += 2)
    res += arr[i];
  for (int i = 1; i < c; i += 2)
    res += arr[i] * 2 > 9 ? (arr[i] * 2 - 9) : (arr[i] * 2);
  res % 10 == 0 ? printf("Nomer vernyj\n") : printf("Nomer nevernyj\n");
}
