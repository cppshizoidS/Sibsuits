#include "../include/geometry.h"
#include <math.h>

double distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double circle_perimeter(Circle circle)
{
    return 2 * M_PI * circle.radius;
}

double circle_area(Circle circle)
{
    return M_PI * circle.radius * circle.radius;
}

double triangle_perimeter(Triangle triangle)
{
    double perimeter = 0.0;
    for (int i = 0; i < 3; ++i) {
        perimeter += distance(
                triangle.vertices[i], triangle.vertices[(i + 1) % 3]);
    }
    perimeter += distance(triangle.vertices[2], triangle.vertices[0]);
    return perimeter;
}

double triangle_area(Triangle triangle)
{
    double a = distance(triangle.vertices[0], triangle.vertices[1]);
    double b = distance(triangle.vertices[1], triangle.vertices[2]);
    double c = distance(triangle.vertices[2], triangle.vertices[0]);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double polygon_perimeter(Polygon polygon)
{
    double perimeter = 0.0;
    for (int i = 0; i < polygon.num_vertices - 1; ++i) {
        perimeter += distance(polygon.vertices[i], polygon.vertices[i + 1]);
    }
    perimeter += distance(
            polygon.vertices[polygon.num_vertices - 1], polygon.vertices[0]);
    return perimeter;
}

double polygon_area(Polygon polygon)
{
    double area = 0.0;
    for (int i = 0; i < polygon.num_vertices; ++i) {
        int j = (i + 1) % polygon.num_vertices;
        area += polygon.vertices[i].x * polygon.vertices[j].y
                - polygon.vertices[j].x * polygon.vertices[i].y;
    }
    area = fabs(area) / 2.0;
    return area;
}