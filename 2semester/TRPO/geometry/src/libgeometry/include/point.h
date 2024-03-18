#pragma once

#include "math.h"
#include "utils.h"

struct Point {
  int x;
  int y;
  static Point from_string(std::string str);
  static double get_distance(Point p1, Point p2);
};