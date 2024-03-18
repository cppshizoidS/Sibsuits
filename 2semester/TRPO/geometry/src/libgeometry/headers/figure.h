#pragma once

#include <vector>

#include "point.h"

enum ArgType { POINT, NUMBER };

class Circle;
class Triangle;

class Figure {
 public:
  std::vector<int> type_args;
  std::vector<std::string> str_args;
  std::vector<Point> points;

  bool is_polygon = false;

  int radius = 0;
  std::string original_string;

  virtual bool intersects(const Figure &) const = 0;

  virtual void parse_string(std::string &);
  virtual double get_perimeter();
  virtual double get_area();

  virtual std::string get_name() const = 0;

 protected:
  virtual bool intersects_with_circle(const Circle &) const { return false; }
  virtual bool intersects_with_triangle(const Triangle &) const {
    return false;
  }
};
