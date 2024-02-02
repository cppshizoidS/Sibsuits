#include <algorithm>
#include <iostream>
#include <list>

struct Students {
  std::string lastName;
  int grades[4];
};

bool compareStudents(const Students &a, const Students &b) {
  return a.lastName < b.lastName;
}

auto main() -> int {
  std::list<Students> studentList = {{"Smith", {90, 85, 88, 92}},
                                     {"Johnson", {78, 80, 75, 82}},
                                     {"Williams", {95, 92, 89, 91}}};
  studentList.sort(compareStudents);

  for (const auto &student : studentList) {
    std::cout << "Last Name:" << student.lastName << ", Grades: ";
    for (int grade : student.grades) {
      std::cout << grade << std::endl;
    }
  }
  return 0;
}
