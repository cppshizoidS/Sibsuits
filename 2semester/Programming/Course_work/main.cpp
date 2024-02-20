//29 task
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/**
 * @brief Структура, представляющая предмет и оценку студента.
 */
struct Subject {
    std::string name;
    int grade;
};
/**
 * @brief Структура, представляющая данные о студенте.
 */
struct Student {
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    std::vector<Subject> subjects;
};

// Функция для создания файла
void createFile(const std::string& filename) {
    std::ofstream file(filename);
    file.close();
}

/**
 * @brief Добавляет новую запись о студенте в файл.
 * @param filename Имя файла.
 * @param student Студент для добавления.
 */
void addRecord(const std::string& filename, const Student& student) {
    std::ofstream file(filename, std::ios::app);
    file << student.lastName << ' ' << student.firstName << ' ' << student.patronymic << ' ';
    for (const auto& subject : student.subjects) {
        file << subject.name << ' ' << subject.grade << ' ';
    }
    file << '\n';
    file.close();
}

/**
 * @brief Создает индексные файлы для сортировки.
 * @param filename Имя файла.
 */
void createIndexFiles(const std::string& filename) {
    // Считывание всех записей из файла в вектор
    std::vector<std::string> records;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        records.push_back(line);
    }
    file.close();

    // Сортировка вектора записей
    std::sort(records.begin(), records.end());

    // Запись отсортированных записей обратно в файл
    std::ofstream sortedFile(filename);
    for (const auto& record : records) {
        sortedFile << record << '\n';
    }
    sortedFile.close();
}

/**
 * @brief Выводит содержимое файла в консоль.
 * @param filename Имя файла.
 */
void viewFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
const int max_record = 4;
/**
 * @brief Поиск и обновление записи о студенте по фамилии.
 * @param filename Имя файла.
 * @param searchLastName Фамилия для поиска и обновления.
 */
void searchAndUpdateRecord(const std::string& filename, const std::string& searchLastName) {
    std::vector<Student> students;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    // Чтение всех студентов из файла в вектор
    Student student;
    while (file >> student.lastName >> student.firstName >> student.patronymic) {
        for (int i = 0; i < max_record; ++i) {
            Subject subject;
            if(!(file >> subject.name >>subject.grade)){
                std::cerr << "Error reading from file: " << filename << std::endl;
                file.close();
                return;
            }
            file >> subject.name >> subject.grade;
            student.subjects.push_back(subject);
        }
        students.push_back(student);
        student.subjects.clear();
    }

    if (file.fail() && !file.eof()) {
        std::cerr << "Error reading from file: " << filename << std::endl;
        file.close();
        return;
    }

    file.close();
    /**
    * @brief Поиск студента по фамилии и обновление его данных.
    *
    * Ищет студента в векторе по фамилии. Если студент найден, запрашивает у пользователя
    * новые данные (фамилию, имя, отчество и оценки по предметам) и обновляет запись о студенте.
    *
    * @param students Вектор студентов.
    * @param searchLastName Фамилия для поиска и обновления.
    * @return True, если студент найден и обновлен, иначе False.
    */
    bool found = false;
    for (auto& student : students) {
        if (student.lastName == searchLastName) {
            found = true;

            // Обновление всех полей студента
            std::cout << "Введите новую фамилию для " << searchLastName << ": ";
            std::cin >> student.lastName;

            std::cout << "Введите новое имя для " << student.lastName << ": ";
            std::cin >> student.firstName;

            std::cout << "Введите новое отчество для " << student.lastName << ": ";
            std::cin >> student.patronymic;

            for (int i = 0; i < max_record; ++i) {
                std::cout << "Введите новое название предмета и оценку для предмета " << i + 1 << " (через пробел): ";
                std::cin >> student.subjects[i].name >> student.subjects[i].grade;
            }

            std::cout << "Запись успешно обновлена.\n";
            break;
        }
    }

    if (!found) {
        std::cout << "Запись не найдена для фамилии: " << searchLastName << "\n";
    }

    // Запись обновленных записей обратно в файл
    /**
    * @brief Записывает обновленные данные о студентах обратно в файл.
    *
    * Открывает файл для записи и записывает обновленные данные о студентах в него.
    * Каждая строка файла представляет одного студента с его фамилией, именем, отчеством и оценками по предметам.
    *
    * @param filename Имя файла для сохранения обновленных данных.
    * @param students Вектор студентов с обновленными данными.
    */
    std::ofstream updatedFile(filename);
    for (const auto& student : students) {
        updatedFile << student.lastName << ' ' << student.firstName << ' ' << student.patronymic << ' ';
        for (const auto& subject : student.subjects) {
            updatedFile << subject.name << ' ' << subject.grade << ' ';
        }
        updatedFile << '\n';
    }
    updatedFile.close();
}

/**
 * @brief Удаляет запись о студенте по фамилии.
 * @param filename Имя файла.
 * @param deleteLastName Фамилия для удаления.
 */
void deleteRecord(const std::string& filename, const std::string& deleteLastName) {
    std::vector<std::string> records;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        records.push_back(line);
    }
    file.close();
    /**
    * @brief Удаляет записи о студентах с указанной фамилией из вектора записей.
    *
    * Использует алгоритм std::remove_if для фильтрации записей с заданной фамилией.
    * Записи с указанной фамилией будут перемещены в конец вектора, а затем удалены.
    *
    * @param records Вектор записей студентов.
    * @param deleteLastName Фамилия для удаления.
    * @return Итератор на новый конец вектора после удаления записей.
    */
    auto it = std::remove_if(records.begin(), records.end(), [deleteLastName](const std::string& record) {
        std::string lastName = record.substr(0, record.find(' '));
        return lastName == deleteLastName;
    });

    if (it != records.end()) {
        records.erase(it, records.end());
        std::cout << "Запись успешно удалена.\n";
    } else {
        std::cout << "Запись не найдена для фамилии: " << deleteLastName << "\n";
    }

    // Запись обновленных записей обратно в файл
    std::ofstream updatedFile(filename);
    for (const auto& record : records) {
        updatedFile << record << '\n';
    }
    updatedFile.close();
}

int main() {
    std::string filename = "students.txt";

    int choice;
    do {
        std::cout << "\nМеню:\n"
                  << "1. Создать файл\n"
                  << "2. Добавить запись\n"
                  << "3. Создать индексные файлы\n"
                  << "4. Просмотр файла\n"
                  << "5. Поиск и обновление записи\n"
                  << "6. Удалить запись\n"
                  << "7. Выйти\n"
                  << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
            {
                Student newStudent;
                std::cout << "Введите фамилию, имя, отчество: ";
                std::cin >> newStudent.lastName >> newStudent.firstName >> newStudent.patronymic;

                for (int i = 0; i < max_record; ++i) {
                    Subject subject;
                    std::cout << "Введите название предмета и оценку для предмета " << i + 1 << ": ";
                    std::cin >> subject.name >> subject.grade;
                    newStudent.subjects.push_back(subject);
                }

                addRecord(filename, newStudent);
            }
                break;
            case 3:
                createIndexFiles(filename);
                break;
            case 4:
                viewFile(filename);
                break;
            case 5:
            {
                std::string searchLastName;
                std::cout << "Введите фамилию для поиска и обновления: ";
                std::cin >> searchLastName;
                searchAndUpdateRecord(filename, searchLastName);
            }
                break;
            case 6:
            {
                std::string deleteLastName;
                std::cout << "Введите фамилию для удаления: ";
                std::cin >> deleteLastName;
                deleteRecord(filename, deleteLastName);
            }
                break;
            case 7:
                std::cout << "Выход из программы. До свидания!\n";
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }

    } while (choice != 7);

    return 0;
}
