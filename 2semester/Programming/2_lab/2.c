#include <stdio.h>

void printNegativesAndPositives(int arr[], int n, int i, int negative) {
    if (i == n) {
        return;
    }

    if ((arr[i] < 0) && negative) {
        printf("%d\n", arr[i]);
    }

    if ((arr[i] >= 0) && !negative) {
        printf("%d\n", arr[i]);
    }

    printNegativesAndPositives(arr, n, i + 1, negative);
}

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Отрицательные числа:\n");
    printNegativesAndPositives(arr, n, 0, 1);

    printf("Положительные числа:\n");
    printNegativesAndPositives(arr, n, 0, 0);

    return 0;
}
