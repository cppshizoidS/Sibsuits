#include <algorithm>
#include <array>
#include <iostream>

// Функция обнуления элементов между двумя минимальными значениями
template <std::size_t N>
void zeroBetweenMin(std::array<int, N> &arr) {
    auto minMaxPair = std::minmax_element(arr.begin(), arr.end());
    auto min1 = minMaxPair.first;
    auto min2 = minMaxPair.second;

    // Обработка случая, когда min2 находится слева от min1
    if (min1 > min2) {
        std::swap(min1, min2);
    }

    // Изменения для обработки не уникальных минимальных элементов
    auto nextMin1 = std::find(min1 + 1, arr.end(), *min1);
    auto nextMin2 = std::find(nextMin1 + 1, arr.end(), *min2);

    std::for_each(nextMin1, nextMin2, [](int &element) { element = 0; });
}
int main() {
    // Задание 1
    std::array<int, 8> arr1 = {5, 2, 10, 10, 10, 1, 6, 1};
    std::cout << "Before zeroing: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }

    zeroBetweenMin(arr1);

    std::cout << "\nAfter zeroing: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }

    return 0;
}
