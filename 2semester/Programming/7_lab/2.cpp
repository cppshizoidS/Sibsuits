#include <array>
#include <iostream>

// Функция вычисления суммы элементов каждой строки
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
