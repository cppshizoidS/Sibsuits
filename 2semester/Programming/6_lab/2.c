#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функция для вычисления факториала
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    } else {
        return n * factorial(n - 1);
    }
}

// Функция для вычисления биномиального коэффициента C(n, m)
double binomialCoefficient(int n, int m) {
    return factorial(n) / (factorial(m) * factorial(n - m));
}

// Функция для расчета вероятности
void calculateProbability(int n, int m, double p, double *pd, double *pm) {
    double q = 1.0 - p;

    if (n < 0 || m < 0 || m > n || p < 0 || p > 1) {
        fprintf(stderr, "Ошибка входных данных. Пожалуйста, проверьте входные параметры.\n");
        exit(EXIT_FAILURE);
    }

    *pd = binomialCoefficient(n, m) * pow(p, m) * pow(q, n - m);
    *pm = binomialCoefficient(n, m) * pow(q, m) * pow(p, n - m);
}

int main() {
    int n, m;
    double p = 0.45;  // Заданная вероятность

    // Ввод данных
    printf("Введите количество детей (n): ");
    scanf("%d", &n);
    printf("Введите количество девочек (m): ");
    scanf("%d", &m);

    // Вычисление вероятности
    double pd, pm;
    calculateProbability(n, m, p, &pd, &pm);

    // Вывод результатов
    printf("Вероятность рождения %d девочек из %d детей: %lf\n", m, n, pd);
    printf("Вероятность рождения %d мальчиков из %d детей: %lf\n", m, n, pm);

    return 0;
}
