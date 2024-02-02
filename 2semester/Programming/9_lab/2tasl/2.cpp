#include <algorithm>
#include <iostream>
#include <list>
#include <ostream>

struct Students {
  std::string lastName;
  int grades[4];
};

bool hasUnsatisfactoryGrade(const Students &students) {
  for (int grade : students.grades) {
    if (grade < 60) {
      return true;
    }
  }
  return false;
}

auto main() -> int {
  std::list<Students> studentsList = {{"Smith", {90, 85, 89, 92}},
                                      {"Johnson", {40, 80, 75, 82}},
                                      {"Williams", {95, 92, 89, 72}}};

  std::cout << "List before removal" << std::endl;

  for (const auto &students : studentsList) {
    std::cout << "Last Name: " << students.lastName << ", Grades: ";
    for (int grade : students.grades) {
      std::cout << grade << " ";
    }
    std::cout << std::endl;
  }

  studentsList.remove_if(hasUnsatisfactoryGrade);

  std::cout << "\n List after removal:" << std::endl;
  for (const auto &students : studentsList) {
    std::cout << "Last Name: " << students.lastName << ", Grades: ";
    for (int grade : students.grades) {
      std::cout << grade << " ";
    }
    std::cout << std::endl;
  }
}
