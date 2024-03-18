#include "./headers/utils.h"

void print_error(std::string str, int index, std::string err_msg) {
  std::cerr << str << std::endl;
  for (int i = 0; i < index - 1; i++) {
    std::cout << " ";
  }
  std::cout << "^" << std::endl
            << "Error at column " << index << ": " + err_msg << std::endl;
}

void str_tolower(std::string &s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
}

void trim_string(std::string &str) {
  // Trim leading spaces
  size_t start = str.find_first_not_of(' ');
  if (start != std::string::npos) {
    str.erase(0, start);
  }

  // Trim trailing spaces
  size_t end = str.find_last_not_of(' ');
  if (end != std::string::npos) {
    str.erase(end + 1);
  }
}