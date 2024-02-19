#include "ArrFunc.hpp"
#include "Sorts.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);

   std::cout << "| Size array |        Theoretical bubble        |            Theoretical shaker            |           M + C bubble           |           M + C shaker                |           M + C Select               |"<< std::endl;
   std::cout << "|            | decreasing | middle | increasing | decreasing | middle max | increasing max | decreasing | random | increasing | decreasing   | random   | increasing  | decreasing | random   | increasing   |" << std::endl;
   std::cout << "|------------|------------|--------|------------|------------|------------|----------------|------------|--------|------------|--------------|----------|-------------|------------|----------|--------------|" << std::endl;

    for (size_t len_arr = 100; len_arr <= 500; len_arr += 100) {
        std::vector<int> Amin(len_arr);
        std::vector<int> Amax(len_arr);
        std::vector<int> Arand(len_arr);

        FillDec(Amin, len_arr);
        FillInc(Amax, len_arr);
        FillRand(Arand, len_arr);

        std::cout << "| " << std::setw(11) << len_arr;

        std::cout << "| " << std::setw(11) << 4 * (len_arr * len_arr - len_arr) / 2;
        std::cout << "| " << std::setw(7) << 3 * (len_arr * len_arr - len_arr) / 4 + (len_arr * len_arr - len_arr) / 2;
        std::cout << "| " << std::setw(11) << (len_arr * len_arr - len_arr) / 2;

        std::cout << "| " << std::setw(11) << 4 * (len_arr * len_arr - len_arr) / 2;
        std::cout << "| " << std::setw(11) << 3 * (len_arr * len_arr - len_arr) / 4 + (len_arr * len_arr - len_arr) / 2 - 1;
        std::cout << "| " << std::setw(15) << (len_arr * len_arr - len_arr) / 2 - 1;

        std::cout << "| " << std::setw(11) << BubbleSort(Amin);
        std::cout << "| " << std::setw(7) << BubbleSort(Arand);
        std::cout << "| " << std::setw(11) << BubbleSort(Amax);

        FillDec(Amin, len_arr);
        FillInc(Amax, len_arr);
        FillRand(Arand, len_arr);

        std::cout << "| " << std::setw(13) << ShakerSort(Amin);
        std::cout << "| " << std::setw(9) << ShakerSort(Arand);
        std::cout << "| " << std::setw(12) << ShakerSort(Amax);

        FillDec(Amin, len_arr);
        FillInc(Amax, len_arr);
        FillRand(Arand, len_arr);

        std::cout << "| " << std::setw(11) << SelectSort(Amin);
        std::cout << "| " << std::setw(9) << SelectSort(Arand);
        std::cout << "| " << std::setw(12) << SelectSort(Amax) << " |" << std::endl;

    }

    return 0;
}
