#include <cstdio>
#include <vector>

#include "ArrFunc.hpp"
#include "Sorts.hpp"

int main() {
    // clang-format off
    printf("| Size array |          M and h        |        M + C shell               |       M + C quick                |\n");
    printf("|            |                         | decreasing | random | increasing | decreasing | random | increasing |\n");
    printf("|------------|-------------------------|----------------------------------|----------------------------------|\n");
    // clang-format on
    for (size_t len_arr = 100; len_arr <= 500; len_arr += 100) {
        std::vector<int> Amin(len_arr);
        std::vector<int> Amax(len_arr);
        std::vector<int> Arand(len_arr);

        FillDec(Amin, len_arr);
        FillInc(Amax, len_arr);
        FillRand(Arand, len_arr);

        printf("| %10lu | ", len_arr);

        printf("%7lu %12lu | ", ShellSort(Amin, len_arr), ShellSort(Arand, len_arr));
        printf("%9lu %6lu  | ", ShellSort(Amax, len_arr));

        printf("%9lu %6lu |\n", QuickSort(Amin, len_arr), QuickSort(Amax, len_arr));

        FillDec(Amin, len_arr);
        FillInc(Amax, len_arr);
        FillRand(Arand, len_arr);
    }

    return 0;
}
