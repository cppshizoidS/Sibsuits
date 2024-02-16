#include <algorithm>
#include <iostream>
#include <list>
#include <ostream>

/**
 * @struct Students
 * @brief Структура для представления информации о студентах.
 */
struct Students {
  std::string lastName; ///< Фамилия студента.
  int grades[4];        ///< Массив с оценками студента за четыре предмета.
};

/**
 * @brief Проверяет, есть ли у студента неудовлетворительные оценки.
 * @param students Студент для проверки.
 * @return true, если у студента есть хотя бы одна неудовлетворительная оценка, иначе false.
 */
bool hasUnsatisfactoryGrade(const Students &students) {
  for (int grade : students.grades) {
    if (grade < 60) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Основная функция для демонстрации удаления студентов с неудовлетворительными оценками.
 * @return 0 при успешном выполнении.
 */
auto main() -> int {
  // Пример данных, представляющих информацию о различных студентах.
  std::list<Students> studentsList = {{"Smith", {90, 85, 89, 92}},
                                      {"Johnson", {40, 80, 75, 82}},
                                      {"Williams", {95, 92, 89, 72}}};

  std::cout << "Список до удаления" << std::endl;

  // Вывод информации о студентах до удаления.
  for (const auto &students : studentsList) {
    std::cout << "Фамилия: " << students.lastName << ", Оценки: ";
    for (int grade : students.grades) {
      std::cout << grade << " ";
    }
    std::cout << std::endl;
  }

  // Удаление студентов с неудовлетворительными оценками.
  studentsList.remove_if(hasUnsatisfactoryGrade);

  std::cout << "\nСписок после удаления:" << std::endl;

  // Вывод информации о студентах после удаления.
  for (const auto &students : studentsList) {
    std::cout << "Фамилия: " << students.lastName << ", Оценки: ";
    for (int grade : students.grades) {
      std::cout << grade << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
