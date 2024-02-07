#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

struct Passenger {
  std::string fullName;
  int numberOfSeats;
  double totalWeight;

  // Перегруженный оператор для вывода информации о пассажире
  friend std::ostream &operator<<(std::ostream &os,
                                  const Passenger &passenger) {
    os << passenger.fullName << " " << passenger.numberOfSeats << " "
       << passenger.totalWeight;
    return os;
  }
};

// Функция для создания файла из N записей
void createFile(const std::string &filename,
                const std::vector<Passenger> &passengers) {
  std::ofstream file(filename);
  if (file.is_open()) {
    for (const auto &passenger : passengers) {
      file << passenger << std::endl;
    }
    file.close();
    std::cout << "Файл успешно создан.\n";
  } else {
    std::cerr << "Ошибка открытия файла.\n";
  }
}

// Функция для просмотра файла
void viewFile(const std::string &filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Ошибка открытия файла.\n";
  }
}

// Функция для добавления новой записи в конец файла
void addRecord(const std::string &filename, const Passenger &newPassenger) {
  std::ofstream file(filename, std::ios::app);
  if (file.is_open()) {
    file << newPassenger << std::endl;
    file.close();
    std::cout << "Новая запись успешно добавлена.\n";
  } else {
    std::cerr << "Ошибка открытия файла.\n";
  }
}

// Функция для удаления записей с весом вещей менее 10 кг
void deleteRecords(const std::string &filename, double thresholdWeight) {
  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    std::cerr << "Ошибка открытия файла.\n";
    return;
  }

  std::vector<Passenger> passengers;
  Passenger tempPassenger;
  while (inFile >> tempPassenger.fullName >> tempPassenger.numberOfSeats >>
         tempPassenger.totalWeight) {
    if (tempPassenger.totalWeight >= thresholdWeight) {
      passengers.push_back(tempPassenger);
    }
  }
  inFile.close();

  std::ofstream outFile(filename);
  if (!outFile.is_open()) {
    std::cerr << "Ошибка открытия файла для записи.\n";
    return;
  }

  for (const auto &passenger : passengers) {
    outFile << passenger << std::endl;
  }
  outFile.close();

  std::cout << "Записи с весом менее " << thresholdWeight
            << " кг успешно удалены.\n";
}

// Функция для изменения веса вещей по заданной фамилии
void modifyWeight(const std::string &filename, const std::string &lastName,
                  double newWeight) {
  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    std::cerr << "Ошибка открытия файла.\n";
    return;
  }

  std::vector<Passenger> passengers;
  Passenger tempPassenger;
  while (inFile >> tempPassenger.fullName >> tempPassenger.numberOfSeats >>
         tempPassenger.totalWeight) {
    if (tempPassenger.fullName == lastName) {
      tempPassenger.totalWeight = newWeight;
    }
    passengers.push_back(tempPassenger);
  }
  inFile.close();

  std::ofstream outFile(filename);
  if (!outFile.is_open()) {
    std::cerr << "Ошибка открытия файла для записи.\n";
    return;
  }

  for (const auto &passenger : passengers) {
    outFile << passenger << std::endl;
  }
  outFile.close();

  std::cout << "Вес вещей для пассажира с фамилией " << lastName
            << " успешно изменен.\n";
}

int main() {
  const std::string filename = "passengers.txt";

  // Пример данных для тестирования
  std::vector<Passenger> initialPassengers = {
      {"Иванов", 2, 15.5}, {"Петров", 1, 8.7}, {"Сидоров", 3, 12.2}};

  int choice;
  do {
    std::cout << "\nМеню:\n";
    std::cout << "1 - Создание нового файла\n";
    std::cout << "2 - Просмотр файла\n";
    std::cout << "3 - Добавление в файл\n";
    std::cout << "4 - Поиск и изменение\n";
    std::cout << "0 - Выход\n";
    std::cout << "Выберите действие: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      createFile(filename, initialPassengers);
      break;
    case 2:
      std::cout << "\nПросмотр файла:\n";
      viewFile(filename);
      break;
    case 3: {
      Passenger newPassenger;
      std::cout << "Введите данные нового пассажира (ФИО, количество мест, "
                   "общий вес): ";
      std::cin >> newPassenger.fullName >> newPassenger.numberOfSeats >>
          newPassenger.totalWeight;
      addRecord(filename, newPassenger);
      break;
    }
    case 4: {
      double thresholdWeight;
      std::cout << "Введите пороговый вес для удаления записей: ";
      std::cin >> thresholdWeight;
      deleteRecords(filename, thresholdWeight);

      std::string lastName;
      double newWeight;
      std::cout << "Введите фамилию и новый вес для изменения записи: ";
      std::cin >> lastName >> newWeight;
      modifyWeight(filename, lastName, newWeight);
      break;
    }
    case 0:
      std::cout << "Выход из программы.\n";
      break;
    default:
      std::cerr << "Некорректный выбор. Попробуйте снова.\n";
      break;
    }
  } while (choice != 0);

  return 0;
}
