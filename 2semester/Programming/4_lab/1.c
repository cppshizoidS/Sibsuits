#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int m, n;

    // ввод размерностей массива B
    printf("Введите количество строк m: ");
    scanf("%d", &m);
    n = 5; // фиксированное количество столбцов

    // выделение памяти под двумерный массив B[m][n]
    int **B = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        B[i] = (int *)malloc(n * sizeof(int));
    }

    // заполнение массива B случайными числами
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = rand() % 100; // случайные числа от 0 до 99
        }
    }

    // индексы максимального элемента
    int maxRow = 0, maxCol = 0, maxElement = B[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i][j] > maxElement) {
                maxElement = B[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // новая матрица C[m-1][n-1] без строки и столбца с максимальным элементом
    int **C = (int **)malloc((m - 1) * sizeof(int *));
    for (int i = 0; i < m - 1; i++) {
        C[i] = (int *)malloc((n - 1) * sizeof(int));
    }

    // копирование элементов из B в C, исключая строку и столбец с максимальным элементом
    for (int i = 0, new_i = 0; i < m; i++) {
        if (i == maxRow) continue; // пропускаем строку с максимальным элементом
        for (int j = 0, new_j = 0; j < n; j++) {
            if (j == maxCol) continue; // пропускаем столбец с максимальным элементом
            C[new_i][new_j] = B[i][j];
            new_j++;
        }
        new_i++;
    }

    // вывод матрицы C
    printf("\nМатрица C[%d][%d] после удаления строки и столбца с максимальным элементом:\n", m - 1, n - 1);
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    // освобождение памяти
    for (int i = 0; i < m; i++) {
        free(B[i]);
    }
    free(B);

    for (int i = 0; i < m - 1; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}
