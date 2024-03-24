#include "./include/point.h"

Point Point::from_string(std::string str) {
  Point point = {0, 0};
  int num_cnt = 0;
  std::string _tmp_value;
  for (size_t i = 0; i < str.length(); i++) {
    if ((str[i] == ' ' && str[i + 1] != ' ') || i == str.length() - 1) {
      if (i == str.length() - 1) {
        _tmp_value += str[i];
      }
      if (num_cnt == 0) {
        point.x = stoi(_tmp_value);
      } else {
        point.y = stoi(_tmp_value);
      }
      num_cnt++;
      _tmp_value.clear();
    }

    if (str[i] == ' ') {
      continue;
    }
    _tmp_value += str[i];
  }
  return point;
}

double Point::get_distance(Point p1, Point p2) {
  double a = p1.x - p2.x;
  double b = p1.y - p2.y;
  return std::sqrt(a * a + b * b);
}