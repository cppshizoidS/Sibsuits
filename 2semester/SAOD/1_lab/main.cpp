#include <iostream>
#include <array>
#include <random>

const int max_size = 100;

//заполнение массива возрастающими числами
void FillInc(std::array<int, max_size>& A) {
    int i = 1;
    for (auto& element : A) {
        element = i++;
    }
}

// заполнение массива убывающими числами
void FillDec(std::array<int, max_size>& A) {
    int i = A.size();
    for (auto& element : A) {
        element = i--;
    }
}

// заполнение массива случайными числами
void FillRand(std::array<int, max_size>& A) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, max_size);

    for (auto& element : A) {
        element = dis(gen);
    }
}
    
//подсчет контрольной суммы элементов массива
int CheckSum(const std::array<int, max_size>& A) {
    int sum = 0;
    for (const auto& element : A) {
        sum += element;
    }
    return sum;
}

// подсчет количества серий в массиве
int RunNumber(const std::array<int, max_size>& A) {
    int count = 1;
    for (auto it = A.begin() + 1; it != A.end(); ++it) {
        if (*it < *(it - 1)) {
            ++count;
        }
    }
    return count;
}

// вывод массива на экран
void PrintMas(const std::array<int, max_size>& A) {
    for (const auto& element : A) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

auto main() -> int {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::array<int, max_size> A;

    FillInc(A);
    std::cout << "Возрастающий массив: ";
    PrintMas(A);
    std::cout << "Контрольная сумма: " << CheckSum(A) << std::endl;
    std::cout << "Количество серий: " << RunNumber(A) << std::endl << std::endl;

    FillDec(A);
    std::cout << "Убывающий массив: ";
    PrintMas(A);
    std::cout << "Контрольная сумма: " << CheckSum(A) << std::endl;
    std::cout << "Количество серий: " << RunNumber(A) << std::endl << std::endl;

    FillRand(A);
    std::cout << "Случайный массив: ";
    PrintMas(A);
    std::cout << "Контрольная сумма: " << CheckSum(A) << std::endl;
    std::cout << "Количество серий: " << RunNumber(A) << std::endl << std::endl;

    return 0;
}
