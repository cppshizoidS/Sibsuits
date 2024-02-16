#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @struct DormitoryRoomInfo
 * @brief Структура для представления информации о комнатах общежития.
 */
struct DormitoryRoomInfo {
    int roomNumber;       ///< Номер комнаты.
    float roomArea;       ///< Площадь комнаты в квадратных метрах.
    std::string faculty;  ///< Факультет, к которому относится комната.
    int residentsCount;   ///< Количество жителей комнаты.
};

/**
 * @brief Основная функция для демонстрации обработки информации о комнатах общежития.
 * @return 0 при успешном выполнении.
 */
int main() {
    // Пример данных, представляющих информацию о разных комнатах общежития.
    std::vector<DormitoryRoomInfo> dormRooms = {
        {101, 20.5, "Faculty1", 2},
        {102, 18.0, "Faculty2", 3},
        {103, 22.5, "Faculty1", 1},
    };

    std::vector<std::string> faculties;

    // Создание списка уникальных факультетов.
    for (const auto &room : dormRooms) {
        if (std::find(faculties.begin(), faculties.end(), room.faculty) ==
            faculties.end()) {
            faculties.push_back(room.faculty);
        }
    }

    std::cout << "\nИнформация о комнатах общежития: " << std::endl;
    for (const auto &faculty : faculties) {
        int totalRooms = 0;
        int totalResidents = 0;
        float totalArea = 0.0;

        // Вычисление общей информации о комнатах для каждого факультета.
        for (const auto &room : dormRooms) {
            if (room.faculty == faculty) {
                totalRooms++;
                totalResidents += room.residentsCount;
                totalArea += room.roomArea;
            }
        }
        
        // Вычисление средней площади на студента.
        float averageAreaPerStudent =
            totalResidents > 0 ? (totalArea / totalResidents) : 0.0;

        // Вывод информации о факультете и комнатах общежития.
        std::cout << "Факультет " << faculty << ": Комнаты - " << totalRooms
                  << ", Студенты - " << totalResidents
                  << ", Средняя площадь на студента " << averageAreaPerStudent
                  << " кв. м." << std::endl;
    }

    return 0;
}
