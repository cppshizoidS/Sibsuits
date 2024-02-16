/**
 * @file main.cpp
 * @brief Сортировка и отображение информации о школах на основе процента абитуриентов от числа выпускников.
 */

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @struct SchoolInfo
 * @brief Структура для представления информации о школе.
 */
struct SchoolInfo {
    int schoolNumber;            ///< Номер школы.
    int graduatesCount;          ///< Количество выпускников школы.
    int universityEntrantsCount; ///< Количество абитуриентов, поступивших в университет.
};

/**
 * @brief Основная функция для демонстрации сортировки и отображения информации о школах.
 * @return 0 при успешном выполнении.
 */
int main() {
    // Пример данных, представляющих информацию о разных школах.
    std::vector<SchoolInfo> schools = {{1, 100, 10}, {2, 120, 90}, {3, 80, 60}};

    /**
     * @brief Сравнивает школы на основе процента абитуриентов от числа выпускников.
     *
     * Лямбда-выражение, переданное в функцию std::sort, определяет критерий
     * сортировки. Школы сортируются в порядке убывания процента абитуриентов
     * от числа выпускников.
     *
     * @param a Первая школа для сравнения.
     * @param b Вторая школа для сравнения.
     * @return true, если процент абитуриентов от числа выпускников в школе a больше,
     *         чем в школе b, иначе false.
     */
    auto compareSchools = [](const SchoolInfo &a, const SchoolInfo &b) {
        return (static_cast<float>(a.universityEntrantsCount) / a.graduatesCount) >
               (static_cast<float>(b.universityEntrantsCount) / b.graduatesCount);
    };

    // Сортировка школ на основе процента абитуриентов от числа выпускников.
    std::sort(schools.begin(), schools.end(), compareSchools);

    // Отображение информации о каждой школе после сортировки.
    std::cout << "Информация о школах: " << std::endl;
    for (const auto &school : schools) {
        // Вычисление процента абитуриентов от числа выпускников.
        float entrancePercentage =
            (static_cast<float>(school.universityEntrantsCount) /
             school.graduatesCount) * 100;

        // Вывод информации о школе.
        std::cout << "Школа" << school.schoolNumber << ": Выпускники - "
                  << school.graduatesCount << ", Число абитуриентов - "
                  << school.universityEntrantsCount
                  << ", Процент поступивших в университет " << entrancePercentage << "%"
                  << std::endl;
    }

    return 0;
}
