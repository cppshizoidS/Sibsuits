#include <algorithm>
#include <iostream>
#include <list>

/**
 * @struct Students
 * @brief Структура для представления информации о студентах.
 */
struct Students {
  std::string lastName; ///< Фамилия студента.
  int grades[4];        ///< Массив с оценками студента за четыре предмета.
};

/**
 * @brief Функция для сравнения студентов по фамилии.
 * @param a Первый студент для сравнения.
 * @param b Второй студент для сравнения.
 * @return true, если фамилия первого студента меньше фамилии второго, иначе false.
 */
bool compareStudents(const Students &a, const Students &b) {
  return a.lastName < b.lastName;
}

/**
 * @brief Основная функция для демонстрации сортировки и вывода информации о студентах.
 * @return 0 при успешном выполнении.
 */
auto main() -> int {
  // Пример данных, представляющих информацию о различных студентах.
  std::list<Students> studentList = {{"Smith", {90, 85, 88, 92}},
                                     {"Johnson", {78, 80, 75, 82}},
                                     {"Williams", {95, 92, 89, 91}}};
  
  // Сортировка списка студентов по фамилии.
  studentList.sort(compareStudents);

  // Вывод информации о студентах после сортировки.
  for (const auto &student : studentList) {
    std::cout << "Фамилия:" << student.lastName << ", Оценки: ";
    for (int grade : student.grades) {
      std::cout << grade << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
