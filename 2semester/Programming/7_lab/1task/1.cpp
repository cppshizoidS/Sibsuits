/**
 * @brief Программа для обнуления элементов между двумя минимальными значениями в массиве.
 */

#include <algorithm>
#include <array>
#include <iostream>

/**
 * @brief Функция обнуления элементов между двумя минимальными значениями в массиве.
 * @tparam N Размер массива.
 * @param arr Массив целых чисел.
 */
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
     for (auto it = std::find(arr.begin(), arr.end(), *min1); it != arr.end(); it = std::find(it + 1, arr.end(), *min1)) {
        *it = 0;
        if (it == min2) {
            break; // Прекратить, если достигнут второй минимальный элемент
        }
    }
}

/**
 * @brief Главная функция программы.
 * @return Возвращает 0 в случае успешного завершения программы.
 */
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
