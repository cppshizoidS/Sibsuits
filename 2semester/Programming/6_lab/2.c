/**
 * @brief Программа для расчета вероятности рождения определенного числа девочек и мальчиков из заданного общего числа детей.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Функция для вычисления факториала.
 * @param n Число, для которого вычисляется факториал.
 * @return Значение факториала n.
 */
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    } else {
        return n * factorial(n - 1);
    }
}

/**
 * @brief Функция для вычисления биномиального коэффициента C(n, m).
 * @param n Общее количество элементов.
 * @param m Количество выбранных элементов.
 * @return Значение биномиального коэффициента.
 */
double binomialCoefficient(int n, int m) {
    return factorial(n) / (factorial(m) * factorial(n - m));
}

/**
 * @brief Функция для расчета вероятности рождения девочек и мальчиков.
 * @param n Общее количество детей.
 * @param m Количество девочек.
 * @param p Заданная вероятность рождения девочки.
 * @param pd Указатель на переменную, в которую будет записана вероятность рождения m девочек.
 * @param pm Указатель на переменную, в которую будет записана вероятность рождения m мальчиков.
 */
void calculateProbability(int n, int m, double p, double *pd, double *pm) {
    double q = 1.0 - p;

    if (n < 0 || m < 0 || m > n || p < 0 || p > 1) {
        fprintf(stderr, "Ошибка входных данных. Пожалуйста, проверьте входные параметры.\n");
        exit(EXIT_FAILURE);
    }

    *pd = binomialCoefficient(n, m) * pow(p, m) * pow(q, n - m);
    *pm = binomialCoefficient(n, m) * pow(q, m) * pow(p, n - m);
}

/**
 * @brief Главная функция программы.
 * @return Возвращает 0 в случае успешного завершения программы.
 */
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
