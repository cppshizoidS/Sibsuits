#include <algorithm>
#include <iostream>
#include <vector>

struct SchoolInfo {
  int schoolNumber;
  int grduatesCount;
  int universityEntrantsCount;
};

struct DormitoryRoomInfo {
  int roomNumber;
  float roomArea;
  std::string faculty;
  int residentsCount;
};

auto main() -> int {
  std::vector<SchoolInfo> schools = {{1, 100, 10}, {2, 120, 90}, {3, 80, 60}};

  std::sort(schools.begin(), schools.end(),
            [](const SchoolInfo &a, const SchoolInfo &b) {
              return (static_cast<float>(a.universityEntrantsCount) /
                      a.grduatesCount) >
                     (static_cast<float>(b.universityEntrantsCount) /
                      b.grduatesCount);
            });

  std::cout << "SchoolInfo: " << std::endl;
  for (const auto &school : schools) {
    float entrancePercentage =
        (static_cast<float>(school.universityEntrantsCount) /
         school.grduatesCount) *
        100;
    std::cout << "School" << school.schoolNumber << ": Grduates - "
              << school.grduatesCount << ", universityEntrantsCount - "
              << school.universityEntrantsCount
              << ", PercentageApplicatsUniversity" << entrancePercentage << "%"
              << std::endl;
  }

  std::vector<DormitoryRoomInfo> dormRooms = {
      {101, 20.5, "Faculty1", 2},
      {102, 18.0, "Faculty2", 3},
      {103, 22.5, "Faculty1", 1},
  };

  std::vector<std::string> faculties;

  for (const auto &room : dormRooms) {
    if (std::find(faculties.begin(), faculties.end(), room.faculty) ==
        faculties.end()) {
      faculties.push_back(room.faculty);
    }
  }

  std::cout << "\nInformation about dorm rooms: " << std::endl;
  for (const auto &faculty : faculties) {
    int totalRooms = 0;
    int totalResidents = 0;
    float totalArea = 0.0;

    for (const auto &room : dormRooms) {
      if (room.faculty == faculty) {
        totalRooms++;
        totalResidents += room.residentsCount;
        totalArea += room.roomArea;
      }
    }
    float averageAreaPerStudent =
        totalResidents > 0 ? (totalArea / totalResidents) : 0.0;
    std::cout << "Faculty" << faculty << ": rooms - " << totalRooms
              << ", Students -" << totalResidents
              << ", Average Area Per Student" << averageAreaPerStudent
              << "sq. m." << std::endl;
  }
  return 0;
}
