#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Введите число n для поиска простых чисел от 2 до n: ");
    scanf("%d", &n);

    // выделение памяти под динамический массив размера n
    char* isPrime = (char*)malloc((n + 1) * sizeof(char));

    // инициализация массива
    for (int i = 2; i <= n; ++i) {
        isPrime[i] = 1;
    }

    // алгоритм "решето Эратосфена"
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    // вывод простых чисел
    printf("Простые числа от 2 до %d: ", n);
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // освобождение памяти
    free(isPrime);

    return 0;
}
