#include <algorithm>
#include <iostream>
#include <set>

struct Student {
  std::string lastName;
  int grades[4];
};

struct CompareStudents {
  bool operator()(const Student &a, const Student &b) const {
    return a.lastName < b.lastName;
  }
};

auto main() -> int {
  std::set<Student, CompareStudents> studentSet = {
      {"Smith", {90, 85, 88, 92}},
      {"Johnson", {78, 80, 75, 82}},
      {"Williams", {95, 92, 89, 91}}};

  std::cout << "Last names in ascending order:" << std::endl;
  for (const auto &student : studentSet) {
    std::cout << student.lastName << std::endl;
  }

  std::cout << "\nLast names in descending order:" << std::endl;
  for (auto it = studentSet.rbegin(); it != studentSet.rend(); ++it) {
    std::cout << it->lastName << std::endl;
  }

  std::string searchLastName = "Johnson";
  auto foundStudent = studentSet.find({searchLastName, {0, 0, 0, 0}});
  if (foundStudent != studentSet.end()) {
    std::cout << "\nStudent found: " << foundStudent->lastName << std::endl;
  } else {
    std::cout << "\nStudent not found." << std::endl;
  }

  return 0;
}
