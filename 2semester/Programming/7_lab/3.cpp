#include <iostream>
#include <vector>
#include <algorithm>

// функция сортировки в порядке убывания
void sortDescending(std::vector<int>& arr) {
    std::sort(arr.rbegin(), arr.rend());
}

// функция поиска элемента перебором
int linearSearch(const std::vector<int>& arr, int target, int& comparisons) {
    comparisons = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        comparisons++;
        if (arr[i] == target) {
            return i;  // возвращаем индекс найденного элемента
        }
    }
    return -1;  // элемент не найден
}

// функция бинарного поиска
int binarySearch(const std::vector<int>& arr, int target, int& comparisons) {
    comparisons = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Возвращаем индекс найденного элемента
        } else if (arr[mid] > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // элемент не найден
}

int main() {
    // создаем массивы
    std::vector<int> arr100(100);
    std::vector<int> arr1000(1000);

    // заполняем массивы случайными значениями
    for (int i = 0; i < 100; ++i) {
        arr100[i] = rand() % 1000;
    }

    for (int i = 0; i < 1000; ++i) {
        arr1000[i] = rand() % 1000;
    }

    // сортируем массивы в порядке убывания
    sortDescending(arr100);
    sortDescending(arr1000);

    // поиск элемента в массиве размером 100 с использованием линейного и бинарного поиска
    int target100 = arr100[rand() % 100];
    int comparisonsLinear100, comparisonsBinary100;

    linearSearch(arr100, target100, comparisonsLinear100);
    binarySearch(arr100, target100, comparisonsBinary100);

    std::cout << "Linear Search (N=100), Comparisons: " << comparisonsLinear100 << std::endl;
    std::cout << "Binary Search (N=100), Comparisons: " << comparisonsBinary100 << std::endl;

    // поиск элемента в массиве размером 1000 с использованием линейного и бинарного поиска
    int target1000 = arr1000[rand() % 1000];
    int comparisonsLinear1000, comparisonsBinary1000;

    linearSearch(arr1000, target1000, comparisonsLinear1000);
    binarySearch(arr1000, target1000, comparisonsBinary1000);

    std::cout << "Linear Search (N=1000) Comparisons: " << comparisonsLinear1000 << std::endl;
    std::cout << "Binary Search (N=1000) Comparisons: " << comparisonsBinary1000 << std::endl;

    return 0;
}
