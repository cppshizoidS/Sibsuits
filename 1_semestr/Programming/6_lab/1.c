#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int randoom(int N) { return rand() % N; }
int main() {
  // 1. Сформировать с помощью датчика случайных чисел в диапазоне [-10,10]
  // массив из 20 элементов целого типа. Вывести его на экран.  Затем вывести на
  // экран  все положительные элементы массива, и все отрицательные элементы.
  int arr[20], a = -10, b = 10;
  for (int i = 0; i < 20; i++)
    arr[i] = randoom(b - a + 1) + a;
  printf("\nArray:\n");
  for (int i = 0; i < 20; i++)
    printf("%3d  ", arr[i]);
  printf("\n-");
  printf("\n'+' chisla:  \n");
  for (int i = 0; i < 20; i++)
    if (arr[i] > 0)
      printf("%3d  ", arr[i]);
  printf("\n-");
  printf("\n'-' chisla:  \n");
  for (int i = 0; i < 20; i++)
    if (arr[i] < 0)
      printf("%3d  ", arr[i]);
  printf("\n");
}

long int fac(int n) {
  long int fac = 1;
  for (int i = 1; i <= n; i++)
    fac *= i;
  return fac;
}
