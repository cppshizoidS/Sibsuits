#pragma once

#include "figure.h"

class Polygon : public Figure {
 public:
  Polygon(std::string &wkt);

  bool intersects(const Figure &figure) const override;

  double get_area();       // Method to calculate the area
  double get_perimeter();  // Method to calculate the perimeter

  bool intersects_with_circle(
      const Circle &other) const;  // Method to check intersection with a Circle
  bool intersects_with_triangle(const Triangle &other)
      const;  // Method to check intersection with a Triangle
  bool intersects_with_polygon(const Polygon &other) const;

  std::string get_name() const override;
};
