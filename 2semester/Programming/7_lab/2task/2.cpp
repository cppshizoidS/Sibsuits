/**
 * @brief Программа для вычисления суммы элементов каждой строки в матрице.
 */

#include <array>
#include <iostream>

/**
 * @brief Функция вычисления суммы элементов каждой строки в матрице.
 * @tparam Rows Количество строк в матрице.
 * @tparam Cols Количество столбцов в матрице.
 * @param matrix Матрица целых чисел.
 * @return Массив сумм элементов каждой строки.
 */
template <std::size_t Rows, std::size_t Cols>
std::array<int, Rows> sumOfRows(const std::array<std::array<int, Cols>, Rows> &matrix) {
    std::array<int, Rows> sums{};
    for (std::size_t i = 0; i < Rows; ++i) {
        for (std::size_t j = 0; j < matrix[i][0]; ++j) {
            sums[i] += matrix[i][j + 1];
        }
    }
    return sums;
}

/**
 * @brief Главная функция программы.
 * @return Возвращает 0 в случае успешного завершения программы.
 */
int main() {
    // Задание 2
    std::array<std::array<int, 4>, 3> matrix = {
        {{5, 2, 8, 3}, {7, 1, 4, 6}, {3, 9, 2, 5}}};

    std::cout << "Sum of each row: ";
    for (int sum : sumOfRows(matrix)) {
        std::cout << sum << " ";
    }

    return 0;
}
