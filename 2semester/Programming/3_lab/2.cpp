#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    // выделение памяти под массив a
    double* a = new double[n];

    // заполнение массива a вещественными случайными числами
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        a[i] = (rand() % 10001) / 100.0; // случайные вещественные числа от 0.00 до 100.00
    }

    // выделение памяти под массив указателей b
    double** b = new double*[n];
    for (int i = 0; i < n; ++i) {
        b[i] = &a[i];
    }

    // сортировка массива указателей b
    std::sort(b, b + n, [](const double* x, const double* y) { return *x < *y; });

    // вывод исходного и отсортированного массивов
    std::cout << "Исходный массив a: ";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Отсортированный массив b: ";
    for (int i = 0; i < n; ++i) {
        std::cout << *b[i] << " ";
    }
    std::cout << std::endl;

    // освобождение памяти
    delete[] a;
    delete[] b;

    return 0;
}
