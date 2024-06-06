/**
 * @file main.cpp
 * @brief Программа, демонстрирующая работу с массивами и реализующая функции
 * для заполнения, обработки и вывода массивов.
 */

#include <iostream>
#include <random>
#include <vector>

/**
 * @brief Заполняет массив элементами, увеличивая их последовательно от 1 до n.
 * @param[out] A Массив, который будет заполнен.
 * @param[in] n Размер массива.
 */
void FillInc(std::vector<int>& A, int n) {
  int i = 1;
  A.resize(n);
  for (auto& element : A) {
    element = i++;
  }
}

/**
 * @brief Заполняет массив элементами, уменьшая их последовательно от n до 1.
 * @param[out] A Массив, который будет заполнен.
 * @param[in] n Размер массива.
 */
void FillDec(std::vector<int>& A, int n) {
  int i = n;
  A.resize(n);
  for (auto& element : A) {
    element = i--;
  }
}

/**
 * @brief Заполняет массив случайными числами в диапазоне от 1 до n.
 * @param[out] A Массив, который будет заполнен.
 * @param[in] n Размер массива.
 */
void FillRand(std::vector<int>& A, int n) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(1, n);

  A.resize(n);
  for (auto& element : A) {
    element = dis(gen);
  }
}

/**
 * @brief Вычисляет контрольную сумму элементов массива.
 * @param[in] A Массив, для которого нужно вычислить контрольную сумму.
 * @return Контрольная сумма.
 */
int CheckSum(const std::vector<int>& A) {
  return std::accumulate(A.begin(), A.end(), 0);
}

/**
 * @brief Вычисляет количество серий в массиве (подряд идущих упорядоченных
 * элементов).
 * @param[in] A Массив, для которого нужно вычислить количество серий.
 * @return Количество серий в массиве.
 */
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

/**
 * @brief Выводит массив на экран.
 * @param[in] A Массив, который нужно вывести.
 */
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
