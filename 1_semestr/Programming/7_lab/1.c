#include <stdio.h>
#include <math.h>
//input 1 2 3 0 2 0.5
int main() {
    double a, b, c, x_start, x_end, h;
    printf("Введите значения a, b, c, x_start, x_end, h: ");
    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &x_start, &x_end, &h);

    int n = (int) ((x_end - x_start) / h) + 1;
    double x[n], y[n];

    for (int i = 0; i < n; i++) {
        x[i] = x_start + i * h;
        y[i] = a * pow(x[i], 2) * sin(x[i]) + b * x[i] + c;
    }

    // Сортировка массива методом пузырька
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (y[j] < y[j + 1]) {
                double temp = y[j];
                y[j] = y[j + 1];
                y[j + 1] = temp;

                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }

    // Вывод отсортированного массива
    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.2lf, y[%d] = %.2lf\n", i, x[i], i, y[i]);
    }

    return 0;
}