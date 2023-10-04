#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

int main() {
    int magic_square[N][N];
    int row_sum, col_sum, diag_sum, anti_diag_sum;
    int attempts = 0;
    srand(time(NULL));
    do {
        // Генерация случайных чисел для заполнения матрицы
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                magic_square[i][j] = rand() % (N * N) + 1;
            }
        }
        // Проверка, является ли матрица магическим квадратом
        row_sum = col_sum = diag_sum = anti_diag_sum = 0;
        for (int i = 0; i < N; i++) {
            row_sum += magic_square[0][i];
            col_sum += magic_square[i][0];
            diag_sum += magic_square[i][i];
            anti_diag_sum += magic_square[i][N - i - 1];
        }
        attempts++;
    } while (row_sum != col_sum || col_sum != diag_sum || diag_sum != anti_diag_sum);
    // Вывод магического квадрата и количества попыток
    printf("Magic square:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", magic_square[i][j]);
        }
        printf("\n");
    }
    printf("Number of attempts: %d\n", attempts);
    return 0;
}