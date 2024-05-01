#include <iomanip>
#include <print>
#include <vector>
#include <cmath>

#include "ArrFunc.hpp"
#include "Sorts.hpp"

auto main() -> int {
    std::println("|  N  | M + C teoretic |          M + C factic          |");
    std::println("|     |                | decriment | random | increment |");
    std::println("|-----|----------------|-----------|--------|-----------|");

    for (size_t len = 100; len <= 500; len += 100) {
        std::vector<int> arr(len);

        std::print("|{:5}|{:16}|", len, static_cast<int>(2 * len * std::log2(len) + len + 2 + len * std::log2(len) + 6.5 * len - 4));

        FillDec(arr, len);
        std::print("{:^11}|", QuickSort(arr));
        FillRand(arr, len);
        std::print("{:^8}|", QuickSort(arr));
        FillInc(arr, len);
        std::println("{:^11}|", QuickSort(arr));
    }

    return 0;
}
