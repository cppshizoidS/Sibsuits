#include "ArrFunc.hpp"
#include "Sorts.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);

    std::cout << "| Size array |        Theoretical shaker        |           M + C shaker           |\n";
    std::cout << "|            | decreasing | middle | increasing | decreasing | random | increasing |\n";
    std::cout << "|------------|------------|--------|------------|------------|--------|------------|\n";

    for (size_t len_arr = 100; len_arr <= 500; len_arr += 100) {
        std::vector<int> Amin(len_arr);
        std::vector<int> Amax(len_arr);
        std::vector<int> Arand(len_arr);

        FillDec(Amin, len_arr);
        FillInc(Amax, len_arr);
        FillRand(Arand, len_arr);

        std::cout << "| " << std::setw(10) << len_arr;

        std::cout << "| " << std::setw(10) << (len_arr * len_arr - len_arr) + 2 * len_arr - 2;
        std::cout << "| " << std::setw(6) << ((len_arr * len_arr - len_arr) + 5 * (len_arr - 1)) / 2;
        std::cout << "| " << std::setw(10) << 3 * (len_arr - 1);

        std::cout << "| " << std::setw(10) << ShakerSort(Amin);
        std::cout << "| " << std::setw(6) << ShakerSort(Arand);
        std::cout << "| " << std::setw(10) << ShakerSort(Amax) << "|\n";

        FillDec(Amin, len_arr);
        FillInc(Amax, len_arr);
        FillRand(Arand, len_arr);

    }

    return 0;
}