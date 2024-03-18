#include "../thirdparty/ctest.h"

#include <string>
#include <vector>

#include "../src/libgeometry/headers/figure.h"
#include "../src/libgeometry/headers/parser.h"

CTEST(ctest, CHECK_SIZE) {
  std::vector<Figure *> figures = read_from_file("geometry.txt");
  ASSERT_EQUAL(3, (int)(figures.size()));
}

CTEST(ctest, CHECK_DATA) {
  std::vector<std::string> expected = {"triangle", "circle", "triangle"};
  std::vector<Figure *> figures = read_from_file("geometry.txt");

  for (size_t i = 0; i < figures.size(); i++) {
    ASSERT_STR(expected[i].c_str(), figures[i]->get_name().c_str());
  }
}