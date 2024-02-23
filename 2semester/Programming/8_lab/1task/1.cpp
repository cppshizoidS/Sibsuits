/**
 * @file main.cpp
 * @brief Сортировка и отображение информации о школах на основе процента
 * абитуриентов от числа выпускников.
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

/**
 * @struct SchoolInfo
 * @brief Структура для представления информации о школе.
 */
struct SchoolInfo {
  int schoolNumber; ///< Номер школы.
  int graduateCount; ///< Количество выпускников школы.
  int universityEntrantsCount; ///< Количество абитуриентов, поступивших в университет.
};

/**
 * @brief Основная функция для выполнения сортировки и вывода информации о школах.
 * @return Целое число, указывающее на успешное выполнение программы.
 */
auto main() -> int {
  // Пример данных, представляющих информацию о различных школах.
  std::vector<SchoolInfo> schools = {{1, 100, 10}, {2, 120, 90}, {3, 80, 60}};

  // Создание вектора индексов и заполнение его последовательными значениями.
  std::vector<size_t> indices(schools.size());
  std::iota(indices.begin(), indices.end(), 0);

  /**
   * @brief Лямбда-функция для сравнения школ на основе процента абитуриентов
   * от числа выпускников.
   * @param a Индекс первой школы.
   * @param b Индекс второй школы.
   * @return True, если у первой школы выше процент, в противном случае - false.
   */
  auto compareSchools = [&schools](size_t a, size_t b) {
    return (static_cast<float>(schools[a].universityEntrantsCount) /
            schools[a].graduateCount) >
           (static_cast<float>(schools[b].universityEntrantsCount) /
            schools[b].graduateCount);
  };

  // Сортировка индексов на основе функции сравнения.
  std::sort(indices.begin(), indices.end(), compareSchools);

  // Отображение информации о каждой школе после сортировки.
  std::cout << "Информация о школах:" << std::endl;
  for (const auto &index : indices) {
    // Вычисление процента абитуриентов от числа выпускников.
    float entrancePercentage =
        (static_cast<float>(schools[index].universityEntrantsCount) /
        schools[index].graduateCount) * 100;

    // Вывод информации о школе.
    std::cout << "Школа" << schools[index].schoolNumber << ": Выпускники - "
              << schools[index].graduateCount << ", Абитуриенты - "
              << schools[index].universityEntrantsCount
              << ", Процент поступивших в университет " << entrancePercentage
              << "%" << std::endl;
  }

  return 0;
}
