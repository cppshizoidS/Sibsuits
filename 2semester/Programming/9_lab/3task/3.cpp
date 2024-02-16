#include <algorithm>
#include <iostream>
#include <set>

/**
 * @struct Student
 * @brief Структура для представления информации о студентах.
 */
struct Student {
  std::string lastName; ///< Фамилия студента.
  int grades[4];        ///< Массив с оценками студента за четыре предмета.
};

/**
 * @struct CompareStudents
 * @brief Функтор для сравнения студентов по фамилии.
 */
struct CompareStudents {
  /**
   * @brief Оператор сравнения для студентов.
   * @param a Первый студент для сравнения.
   * @param b Второй студент для сравнения.
   * @return true, если фамилия первого студента меньше фамилии второго, иначе false.
   */
  bool operator()(const Student &a, const Student &b) const {
    return a.lastName < b.lastName;
  }
};

/**
 * @brief Основная функция для демонстрации использования множества с пользовательским сравнением.
 * @return 0 при успешном выполнении.
 */
auto main() -> int {
  // Пример данных, представляющих информацию о различных студентах.
  std::set<Student, CompareStudents> studentSet = {
      {"Smith", {90, 85, 88, 92}},
      {"Johnson", {78, 80, 75, 82}},
      {"Williams", {95, 92, 89, 91}}};

  // Вывод фамилий студентов в возрастающем порядке.
  std::cout << "Фамилии в алфавитном порядке:" << std::endl;
  for (const auto &student : studentSet) {
    std::cout << student.lastName << std::endl;
  }

  // Вывод фамилий студентов в убывающем порядке.
  std::cout << "\nФамилии в обратном алфавитном порядке:" << std::endl;
  for (auto it = studentSet.rbegin(); it != studentSet.rend(); ++it) {
    std::cout << it->lastName << std::endl;
  }

  // Поиск студента по фамилии "Johnson".
  std::string searchLastName = "Johnson";
  auto foundStudent = studentSet.find({searchLastName, {0, 0, 0, 0}});
  if (foundStudent != studentSet.end()) {
    std::cout << "\nСтудент найден: " << foundStudent->lastName << std::endl;
  } else {
    std::cout << "\nСтудент не найден." << std::endl;
  }

  return 0;
}
