#include <iomanip>
#include <iostream>
#include <vector>

#include "ArrFunc.hpp"
#include "Sorts.hpp"

int main() {
    std::cout << "|  N  | M + C teoretic |          M + C factic          |" << std::endl;
    std::cout << "|     |                | decriment | random | increment |" << std::endl;
    std::cout << "|-----|----------------|-----------|--------|-----------|" << std::endl;

    for (size_t len = 100; len <= 500; len += 100) {
        std::vector<int> arr(len);

        std::cout << "|" << std::setw(5) << len;
        std::cout << "|" << std::setw(16) << static_cast<int>(2 * len * std::log2(len) + len + 2 + len * std::log2(len) + 6.5 * len - 4);

        FillDec(arr, len);
        std::cout << "|" << std::setw(11) << HeapSort(arr, len);
        FillRand(arr, len);
        std::cout << "|" << std::setw(8) << HeapSort(arr, len);
        FillInc(arr, len);
        std::cout << "|" << std::setw(10) << HeapSort(arr, len) << " |" << std::endl;
    }

    return 0;
}
