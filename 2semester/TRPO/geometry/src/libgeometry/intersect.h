#pragma once
#include <stdbool.h>

#include <libgeometry/geom_parser.h>

double distance(Circle a, Circle b);
bool is_intersect_circles(Circle a, Circle b);
bool is_intersect_triangles(Triangle a, Triangle b);
bool is_intersect_circle_triangle(Circle circle, Triangle tr);