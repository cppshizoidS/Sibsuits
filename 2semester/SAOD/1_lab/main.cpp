#include <iostream>
#include <vector>
#include <random>

// заполнение массива возрастающими числами
void FillInc(std::vector<int>& A, int n) {
    int i = 1;
    A.resize(n);
    for (auto& element : A) {
        element = i++;
    }
}

// заполнение массива убывающими числами
void FillDec(std::vector<int>& A, int n) {
    int i = n;
    A.resize(n);
    for (auto& element : A) {
        element = i--;
    }
}

// заполнение массива случайными числами
void FillRand(std::vector<int>& A, int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, n);

    A.resize(n);
    for (auto& element : A) {
        element = dis(gen);
    }
}

// подсчет контрольной суммы элементов массива
int CheckSum(const std::vector<int>& A) {
    return std::accumulate(A.begin(), A.end(), 0);
}

// подсчет количества серий в массиве
int RunNumber(const std::vector<int>& A) {
    int count = 1;
    auto prev = A.begin();

    for (auto it = std::next(A.begin()); it != A.end(); ++it) {
        if (*it < *prev) {
            ++count;
        }
        prev = it;
    }
    return count;
}

// вывод массива на экран
void PrintMas(const std::vector<int>& A) {
    for (const auto& element : A) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

auto main() -> int {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::vector<int> A;

    FillInc(A, n);
    std::cout << "Возрастающий массив: ";
    PrintMas(A);
    std::cout << "Контрольная сумма: " << CheckSum(A) << std::endl;
    std::cout << "Количество серий: " << RunNumber(A) << std::endl << std::endl;

    FillDec(A, n);
    std::cout << "Убывающий массив: ";
    PrintMas(A);
    std::cout << "Контрольная сумма: " << CheckSum(A) << std::endl;
    std::cout << "Количество серий: " << RunNumber(A) << std::endl << std::endl;

    FillRand(A, n);
    std::cout << "Случайный массив: ";
    PrintMas(A);
    std::cout << "Контрольная сумма: " << CheckSum(A) << std::endl;
    std::cout << "Количество серий: " << RunNumber(A) << std::endl << std::endl;

    return 0;
}
