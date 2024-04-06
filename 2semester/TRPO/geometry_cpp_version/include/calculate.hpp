#pragma once

#include <geometry.hpp>

class Calculate {
public:
    void print_objects(); // вывод

    void add_triangle(
            std::string& line,
            Triangle& triangle,
            size_t object_number); // добавить треугольник
    void add_circle(
            std::string& line,
            Circle& circle,
            size_t object_number); // добавить круг
    void add_polygon(
            std::string& line,
            Polygon& polygon,
            size_t object_number); // добавить многоугольник

    std::vector<Triangle>& get_triangles(); // получить все треугольники
    std::vector<Circle>& get_circles(); // получить все круги
    std::vector<Polygon>& get_polygons(); // получить все многоугольники

    float calculate_triangle_perimeter(
            Triangle obj); // вычислить периметер треугольника
    float
    calculate_triangle_area(Triangle obj); // вычислить площадь треугольника
    float calculate_circle_perimeter(Circle obj); // вычислить периметер круга
    float calculate_circle_area(Circle obj); // вычислить площадь круга
    float calculate_polygon_perimeter(
            Polygon obj); // вычислить периметер многоугольника
    float
    calculate_polygon_area(Polygon obj); // вычислить площадь многоугольника

    bool is_intersect_triangle_with_triangle(
            Triangle obj1,
            Triangle
                    obj2); // пересекается ли треугольник с другим треугольником
    bool is_intersect_triangle_with_circle(
            Triangle obj1, Circle obj2); // пересекается ли треугольник с кругом
    bool is_intersect_triangle_with_polygon(
            Triangle obj1,
            Polygon obj2); // пересекается ли треугольник с многоугольником
    bool is_intersect_circle_with_circle(
            Circle obj1, Circle obj2); // пересекается ли круг с другим кругом
    bool is_intersect_circle_with_polygon(
            Circle obj1,
            Polygon obj2); // пересекается ли круг с многоугольником
    bool is_intersect_polygon_with_polygon(
            Polygon obj1, Polygon obj2); // пересекается ли многоугольник с
                                         // другим многоугольником

private:
    std::vector<Triangle> triangles;
    std::vector<Circle> circles;
    std::vector<Polygon> polygons;
    std::vector<size_t> order_of_objects;
    std::vector<std::string> order_of_lines;

    float
    get_distance(Point p1, Point p2); // получить дистанцию между двумя точками

    bool is_intersect(
            Point p11,
            Point p12,
            Point p21,
            Point p22); // пересекаются ли две прямые
    bool is_intersect_vertical_with_line(
            Point p11,
            Point p12,
            Point p21,
            Point p22); // пересекаются ли вертикальная и диагональная линии

    bool is_intersect_circle_line(
            Circle circle, Point p1, Point p2); // пересекаются ли круг и линия

    void
    print_triangle(size_t i, size_t triangle_number); // вывести треугольник
    void print_circle(size_t i, size_t circle_number); // вывести круг
    void
    print_polygon(size_t i, size_t polygon_number); // вывести многоугольник
};
