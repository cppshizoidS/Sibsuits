#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int m, n;

    // ввод размерностей массива A
    printf("Введите количество строк m: ");
    scanf("%d", &m);
    printf("Введите количество столбцов n: ");
    scanf("%d", &n);

    // выделение памяти под двумерный массив A[m][n]
    int **A = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }

    // заполнение массива A случайными числами
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100; // случайные числа от 0 до 99
        }
    }

    // выделение памяти под массив D[m+1][n+1]
    int **D = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i < m + 1; i++) {
        D[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    // заполнение массива D и вычисление сумм строк и столбцов
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = A[i][j];
        }
    }

    // вычисление сумм строк
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += A[i][j];
        }
        D[i][n] = rowSum; // сумма элементов строки i
    }

    // вычисление сумм столбцов
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += A[i][j];
        }
        D[m][j] = colSum; // сумма элементов столбца j
    }

    // вычисление суммы всех элементов исходного массива
    int totalSum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            totalSum += A[i][j];
        }
    }
    D[m][n] = totalSum; // сумма всех элементов

    // вывод массива D
    printf("\nМассив D[%d][%d] с элементами и суммами строк и столбцов:\n", m + 1, n + 1);
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }

    // освобождение памяти
    for (int i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);

    for (int i = 0; i < m + 1; i++) {
        free(D[i]);
    }
    free(D);

    return 0;
}
