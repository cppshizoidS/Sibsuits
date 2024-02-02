#include <algorithm>
#include <iostream>
#include <vector>

struct SchoolInfo {
    int schoolNumber;
    int graduatesCount;
    int universityEntrantsCount;
};

int main() {
    std::vector<SchoolInfo> schools = {{1, 100, 10}, {2, 120, 90}, {3, 80, 60}};

    std::sort(schools.begin(), schools.end(),
              [](const SchoolInfo &a, const SchoolInfo &b) {
                  return (static_cast<float>(a.universityEntrantsCount) /
                          a.graduatesCount) >
                         (static_cast<float>(b.universityEntrantsCount) /
                          b.graduatesCount);
              });

    std::cout << "SchoolInfo: " << std::endl;
    for (const auto &school : schools) {
        float entrancePercentage =
            (static_cast<float>(school.universityEntrantsCount) /
             school.graduatesCount) *
            100;
        std::cout << "School" << school.schoolNumber << ": Graduates - "
                  << school.graduatesCount << ", University Entrants Count - "
                  << school.universityEntrantsCount
                  << ", Percentage Applicants University " << entrancePercentage << "%"
                  << std::endl;
    }

    return 0;
}
