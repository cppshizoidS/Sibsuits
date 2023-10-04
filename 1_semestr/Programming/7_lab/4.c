#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int c[20], d[20], e[40];
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Заполнение массивов случайными числами в диапазоне [0, 20]
    for (int i = 0; i < 20; i++) {
        c[i] = rand() % 21;
        d[i] = rand() % 21;
    }

    // Вывод массивов на экран
    printf("Массив C:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    printf("Массив D:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");

    // Сортировка массивов C и D по возрастанию
    mergeSort(c, 0, 19);
    mergeSort(d, 0, 19);

    // Объединение массивов C и D в массив E
    int i = 0, j = 0, k = 0;
    while (i < 20 && j < 20) {
        if (c[i] <= d[j]) {
            e[k] = c[i];
            i++;
        }
        else {
            e[k] = d[j];
            j++;
        }
        k++;
    }

    while (i < 20) {
        e[k] = c[i];
        i++;
        k++;
    }

    while (j < 20) {
        e[k] = d[j];
        j++;
        k++;
    }

    // Вывод массива E на экран
    printf("Массив E:\n");
    for (int i = 0; i < 40; i++) {
        printf("%d ", e[i]);
    }
    printf("\n");

    return 0;
}