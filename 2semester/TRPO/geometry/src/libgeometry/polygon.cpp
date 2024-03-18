#include "./headers/polygon.h"

#include <cmath>

#include "./headers/circle.h"
#include "./headers/triangle.h"

Polygon::Polygon(std::string &wkt) {
  this->type_args = {POINT, POINT,
                     POINT};  // Update this based on your polygon type
  this->parse_string(wkt);
}

bool Polygon::intersects(const Figure &other) const {
  const Triangle *other_triangle = dynamic_cast<const Triangle *>(&other);
  if (other_triangle) {
    return intersects_with_triangle(*other_triangle);
  }

  const Circle *other_circle = dynamic_cast<const Circle *>(&other);
  if (other_circle) {
    return intersects_with_circle(*other_circle);
  }

  const Polygon *other_polygon = dynamic_cast<const Polygon *>(&other);
  if (other_polygon) {
    return intersects_with_polygon(*other_polygon);
  }

  return false;
}

std::string Polygon::get_name() const {
  return "polygon";  // Update with the actual name of the polygon type
}

double Polygon::get_area() {
  double area = 0;
  for (size_t i = 0; i < points.size(); i++) {
    size_t j = (i + 1) % points.size();
    area += points[i].x * points[j].y - points[j].x * points[i].y;
  }
  return std::fabs(area) / 2;
}

double Polygon::get_perimeter() {
  double perimeter = 0;
  for (size_t i = 0; i < points.size(); i++) {
    size_t j = (i + 1) % points.size();
    perimeter += Point::get_distance(points[i], points[j]);
  }
  return perimeter;
}

bool Polygon::intersects_with_triangle(const Triangle &other) const {
  // Implement intersection checking with a Triangle
  return false;  // Placeholder return
}

bool Polygon::intersects_with_circle(const Circle &other) const {
  // Implement intersection checking with a Circle
  return false;  // Placeholder return
}

bool Polygon::intersects_with_polygon(const Polygon &other) const {
  // Implement intersection checking with another Polygon
  return false;  // Placeholder return
}
