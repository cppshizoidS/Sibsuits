#include <cmath>
#include <cstdio>
#include <vector>

#include "ArrFunc.hpp"
#include "Sorts.hpp"

int main() {
  // clang-format off
    printf("| Size array |        M and h      |           M + C shell            |           M + C insert           |\n");
    printf("|            |                     | decreasing | random | increasing | decreasing | random | increasing |\n");
    printf("|------------|---------------------|------------|--------|------------|------------|--------|------------|\n");
  // clang-format on
  for (size_t len_arr = 100; len_arr <= 500; len_arr += 100) {
    std::vector<int> Amin(len_arr);
    std::vector<int> Amax(len_arr);
    std::vector<int> Arand(len_arr);

    FillDec(Amin, len_arr);
    FillInc(Amax, len_arr);
    FillRand(Arand, len_arr);

    printf("| %10lu ", len_arr);
    printf("| %10lu ", ShellSort(Amin, len_arr));
    printf("| %6lu ", ShellSort(Arand, len_arr));
    printf("| %10lu ", ShellSort(Amax, len_arr));

    FillDec(Amin, len_arr);
    FillInc(Amax, len_arr);
    FillRand(Arand, len_arr);

    printf("| %10lu ", InsertSort(Amin, len_arr));
    printf("| %6lu ", InsertSort(Arand, len_arr));
    printf("| %10lu |\n", InsertSort(Amax, len_arr));

    FillDec(Amin, len_arr);
    FillInc(Amax, len_arr);
    FillRand(Arand, len_arr);

    F = true;
  }

  return 0;
}
