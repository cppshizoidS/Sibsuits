//29 task
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Subject {
    std::string name;
    int grade;
};

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

// Функция для добавления новой записи в файл
void addRecord(const std::string& filename, const Student& student) {
    std::ofstream file(filename, std::ios::app);
    file << student.lastName << ' ' << student.firstName << ' ' << student.patronymic << ' ';
    for (const auto& subject : student.subjects) {
        file << subject.name << ' ' << subject.grade << ' ';
    }
    file << '\n';
    file.close();
}

// Функция для создания индексных файлов для сортировки
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

// Функция для вывода содержимого файла
void viewFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
const int max_record = 4;
// Функция для поиска и обновления записи
void searchAndUpdateRecord(const std::string& filename, const std::string& searchLastName) {
    std::vector<Student> students;
    std::ifstream file(filename);

    // Чтение всех студентов из файла в вектор
    Student student;
    while (file >> student.lastName >> student.firstName >> student.patronymic) {
        for (int i = 0; i < max_record; ++i) {
            Subject subject;
            file >> subject.name >> subject.grade;
            student.subjects.push_back(subject);
        }
        students.push_back(student);
        student.subjects.clear();
    }

    file.close();

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

// Функция для удаления записи по фамилии
void deleteRecord(const std::string& filename, const std::string& deleteLastName) {
    std::vector<std::string> records;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        records.push_back(line);
    }
    file.close();

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
