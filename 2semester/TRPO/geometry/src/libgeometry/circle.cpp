#include "./headers/circle.h"

#include "./headers/figure.h"
#include "./headers/triangle.h"

std::string Circle::get_name() const { return "circle"; }

Circle::Circle(std::string &wkt) {
  this->name = "circle";
  this->type_args = {POINT, NUMBER};
  this->parse_string(wkt);

  this->center = Point::from_string(str_args[0]);
  this->radius = stod(str_args[1]);
}

double Circle::get_perimeter() { return 2 * M_PI * this->radius; }

double Circle::get_area() { return M_PI * this->radius * this->radius; }

bool Circle::intersects(const Figure &other) const {
  const Triangle *other_triangle = dynamic_cast<const Triangle *>(&other);
  if (other_triangle) {
    return intersects_with_triangle(*other_triangle);
  }

  const Circle *other_circle = dynamic_cast<const Circle *>(&other);
  if (other_circle) {
    return intersects_with_circle(*other_circle);
  }

  return false;
}

bool Circle::intersects_with_circle(const Circle &other) const {
  const double distance = Point::get_distance(this->center, other.center);
  if (distance < other.radius + this->radius) {
    return true;
  }
  return false;
}

bool Circle::intersects_with_triangle(const Triangle &other) const {
  for (std::size_t i = 0; i < other.points.size(); i++) {
    const double distance = Point::get_distance(other.points[i], this->center);

    if (distance < this->radius) return true;
  }
  return false;
}