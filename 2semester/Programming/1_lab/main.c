#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// прототипы функций
void calculateEasterDate(int);
double power(double, int );
double calculateCosinus(double, double);

// функция для вычисления даты Пасхи по алгоритму Гаусса
void calculateEasterDate(int year) {
  int a = year % 19;
  int b = year % 4;
  int c = year % 7;
  int d = (19 * a + 15) % 30;
  int e = (2 * b + 4 * c + 6 * d + 6) % 7;
  int f = d + e;

  // определение месяца и дня Пасхи
  int month = (f > 9) ? 4 : 3;
  int day = 22 + f;

  // коррекция даты, если она попадает на апрель и больше 30
  if (month == 4 && day > 30) {
    month = 5;
    day -= 30;
  }

  printf("Пасха в %d году(день месяц): %02d.%02d\n", year, day, month);
}

// Функция для возведения в степень
double power(double x, int n) {
  double result = 1.0;

  for (int i = 0; i < abs(n); ++i) {
    result *= x;
  }

  if (n < 0) {
    return 1.0 / result;
  } else {
    return result;
  }
}

// Функция для вычисления косинуса с использованием ряда Тейлора
double calculateCosinus(double x, double eps) {
  double result = 1.0;
  double term = 1.0;
  int n = 1;

  while (fabs(term) >= eps) {
    term *= -x * x / (2 * n * (2 * n - 1));
    result += term;
    n++;
  }

  return result;
}

int main() {
  int year = 2022;
  calculateEasterDate(year);

  double base = 2.0;
  int exponent = -3;
  printf("%lf^%d = %lf\n", base, exponent, power(base, exponent));

  double angle = 0.5;
  double eps = 0.0001;
  printf("cos(%lf) = %lf\n", angle, calculateCosinus(angle, eps));
  printf("cos(%lf) = %lf\n", angle, cos(angle));

  return 0;
}
