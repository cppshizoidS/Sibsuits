#include "../libgeometry/headers/parser.h"

int main(int argc, char *argv[]) {
  if (argc != 2 || std::string(argv[1]).empty()) {
    std::cout << "First argument should be filename!" << std::endl;
    return 1;
  }

  const std::string file_name = argv[1];
  std::vector<Figure *> figures = read_from_file(file_name);

  for (size_t i = 0; i < figures.size(); i++) {
    Figure *figure = figures[i];

    std::cout << i + 1 << ". " << figure->original_string << std::endl;
    std::cout << '\t' << "perimeter = " << figure->get_perimeter() << std::endl;
    std::cout << '\t' << "area = " << figure->get_area() << std::endl;
    std::cout << '\t' << "intersects: " << std::endl;
    for (size_t j = 0; j < figures.size(); j++) {
      if (i != j && figures[j]->intersects(*figure)) {
        std::cout << "\t\t" << j + 1 << ". " << figures[j]->get_name()
                  << std::endl;
      }
    }
  }

  return 0;
}
