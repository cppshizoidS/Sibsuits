#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
/**
 * @brief Выводит элементы заданного множества.
 *
 * @param set Множество, элементы которого будут выведены.
 */
void printSet(const std::vector<char> &set) {
  std::cout << "{ ";
  for (char element : set) {
    std::cout << element << " ";
  }
  std::cout << "}";
}
/**
 * @brief Удаляет дубликаты из входного множества и сортирует его.
 *
 * @param inputSet Входное множество для обработки.
 * @return Обработанное множество без дубликатов и отсортированное.
 */
std::vector<char> removeDuplicatesAndSort(std::vector<char> &inputSet) {
  sort(inputSet.begin(), inputSet.end());
  inputSet.erase(unique(inputSet.begin(), inputSet.end()), inputSet.end());
  return inputSet;
}
/**
 * @brief Вычисляет объединение двух множеств, удаляя дубликаты и сортируя
 * результат.
 *
 * @param setA Первое множество.
 * @param setB Второе множество.
 * @return Объединение множеств setA и setB.
 */
std::vector<char> unionSets(const std::vector<char> &setA,
                            const std::vector<char> &setB) {
  std::vector<char> result;
  merge(setA.begin(), setA.end(), setB.begin(), setB.end(),
        back_inserter(result));
  return removeDuplicatesAndSort(result);
}
/**
 * @brief Вычисляет пересечение двух множеств, удаляя дубликаты и сортируя
 * результат.
 *
 * @param setA Первое множество.
 * @param setB Второе множество.
 * @return Пересечение множеств setA и setB.
 */
std::vector<char> intersectionSets(const std::vector<char> &setA,
                                   const std::vector<char> &setB) {
  std::vector<char> result;
  set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                   back_inserter(result));
  return removeDuplicatesAndSort(result);
}
/**
 * @brief Вычисляет разность множеств (A - B), удаляя дубликаты и сортируя
 * результат.
 *
 * @param setA Первое множество.
 * @param setB Второе множество.
 * @return Разность множеств setA и setB.
 */
std::vector<char> differenceSets(const std::vector<char> &setA,
                                 const std::vector<char> &setB) {
  std::vector<char> result;
  set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                 back_inserter(result));
  return removeDuplicatesAndSort(result);
}
/**
 * @brief Проверяет, содержит ли множество setA все элементы множества setB.
 *
 * @param setA Первое множество.
 * @param setB Второе множество.
 * @return True, если setA содержит все элементы setB, в противном случае -
 * false.
 */
bool containsSets(const std::vector<char> &setA,
                  const std::vector<char> &setB) {
  return includes(setA.begin(), setA.end(), setB.begin(), setB.end());
}

auto main() -> int {
   std::vector<char> setA, setB;

    std::cout << "Введите элементы множества A через пробел (латинские буквы): ";
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::istringstream issA(inputLine);
    char elementA;
    while (issA >> elementA) {
        setA.push_back(elementA);
    }

    setA = removeDuplicatesAndSort(setA);

    std::cout << "Введите элементы множества B через пробел (латинские буквы): ";
    std::getline(std::cin, inputLine);
    std::istringstream issB(inputLine);
    char elementB;
    while (issB >> elementB) {
        setB.push_back(elementB);
    }

    setB = removeDuplicatesAndSort(setB);

  char choice;
  do {
    std::cout << "\nВыберите операцию:\n";
    std::cout << "1. Проверка вхождения A в B\n";
    std::cout << "2. Объединение A и B\n";
    std::cout << "3. Пересечение A и B\n";
    std::cout << "4. Разность A и B\n";
    std::cout << "5. Выйти\n";
    std::cout << "Введите номер операции: ";
    std::cin >> choice;

    switch (choice) {
      case '1':
        std::cout << "A "
                  << (containsSets(setA, setB) ? "включает" : "не включает")
                  << " B\n";
        break;
      case '2':
        std::cout << "A ∪ B = ";
        printSet(unionSets(setA, setB));
        std::cout << std::endl;
        break;
      case '3':
        std::cout << "A ∩ B = ";
        printSet(intersectionSets(setA, setB));
        std::cout << std::endl;
        break;
      case '4':
        std::cout << "A \\ B = ";
        printSet(differenceSets(setA, setB));
        std::cout << std::endl;
        break;
      case '5':
        std::cout << "Программа завершена.\n";
        break;
      default:
        std::cout << "Некорректный ввод. Попробуйте еще раз.\n";
    }
  } while (choice != '5');

  return 0;
}
