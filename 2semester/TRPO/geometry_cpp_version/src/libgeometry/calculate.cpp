#include <geometry.hpp> // без него не компилиться

float Calculate::get_distance(
        Point p1, Point p2) // получить дистанцию между двумя точками
{
    return std::sqrt(
            (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float Calculate::calculate_triangle_perimeter(
        Triangle obj) // вычислить периметер треугольника
{
    return get_distance(obj.points[0], obj.points[1])
            + get_distance(obj.points[1], obj.points[2])
            + get_distance(obj.points[2], obj.points[0]);
}

float Calculate::calculate_triangle_area(
        Triangle obj) // вычислить площадь треугольника
{
    float a = get_distance(obj.points[0], obj.points[1]);
    float b = get_distance(obj.points[1], obj.points[2]);
    float c = get_distance(obj.points[2], obj.points[0]);
    float perimeter = a + b + c;
    float p = perimeter / 2.;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

float Calculate::calculate_circle_perimeter(
        Circle obj) // вычислить периметер круга
{
    return 2. * M_PI * obj.radius;
}

float Calculate::calculate_circle_area(Circle obj) // вычислить площадь круга
{
    return M_PI * obj.radius * obj.radius;
}

float Calculate::calculate_polygon_perimeter(
        Polygon obj) // вычислить периметер многоугольника
{
    float perimeter = 0;
    for (size_t i = 0; i < obj.points.size() - 1; i++)
        perimeter += std::sqrt(
                (obj.points[i].x - obj.points[i + 1].x)
                        * (obj.points[i].x - obj.points[i + 1].x)
                + (obj.points[i].y - obj.points[i + 1].y)
                        * (obj.points[i].y - obj.points[i + 1].y));
    perimeter += std::sqrt(
            (obj.points.back().x - obj.points[0].x)
                    * (obj.points.back().x - obj.points[0].x)
            + (obj.points.back().y - obj.points[0].y)
                    * (obj.points.back().y - obj.points[0].y));
    return perimeter;
}

float Calculate::calculate_polygon_area(
        Polygon obj) // вычислить площадь многоугольника
{
    float area = 0;
    for (size_t i = 0; i < obj.points.size(); i++) {
        float y1, y2;
        if (i + 1 >= obj.points.size())
            y1 = obj.points[0].y;
        else
            y1 = obj.points[i + 1].y;
        if (i == 0)
            y2 = obj.points.back().y;
        else
            y2 = obj.points[i - 1].y;
        area += obj.points[i].x * (y1 - y2);
    }
    return std::abs(area) / 2.;
}

void Calculate::print_objects() // вывод
{
    size_t triangle_number = 0;
    size_t circle_number = 0;
    size_t polygon_number = 0;

    for (size_t i = 0; i < order_of_objects.size(); i++) {
        switch (order_of_objects[i]) {
        case TRIANGLE_NUMBER:
            print_triangle(i, triangle_number++);
            break;

        case CIRCLE_NUMBER:
            print_circle(i, circle_number++);
            break;

        case POLYGON_NUMBER:
            print_polygon(i, polygon_number++);
            break;
        }
    }
}

void Calculate::add_triangle(
        std::string& line,
        Triangle& triangle,
        size_t object_number) // добавить треугольник
{
    this->triangles.push_back(triangle);
    order_of_objects.push_back(object_number);
    order_of_lines.push_back(line);
}

void Calculate::add_circle(
        std::string& line,
        Circle& circle,
        size_t object_number) // добавить круг
{
    this->circles.push_back(circle);
    order_of_objects.push_back(object_number);
    order_of_lines.push_back(line);
}

void Calculate::add_polygon(
        std::string& line,
        Polygon& polygon,
        size_t object_number) // добавить многоугольник
{
    this->polygons.push_back(polygon);
    order_of_objects.push_back(object_number);
    order_of_lines.push_back(line);
}

bool Calculate::is_intersect(
        Point p11,
        Point p12,
        Point p21,
        Point p22) // пересекаются ли две прямые
{
    float dx1 = p11.x - p12.x;
    float dx2 = p21.x - p22.x;
    if (dx1 == 0. and dx2 == 0) {
        if (p11.x == p21.x
            and ((std::max(p11.y, p12.y) <= std::max(p21.y, p22.y)
                  and std::max(p11.y, p12.y) >= std::min(p21.y, p22.y))
                 or (std::min(p11.y, p12.y) <= std::max(p21.y, p22.y)
                     and std::min(p11.y, p12.y) >= std::min(p21.y, p22.y))))
            return true;
    } else if (p11.y - p12.y == 0. and p21.y - p22.y == 0.) {
        if (p11.y == p21.y
            and ((std::max(p11.x, p12.x) <= std::max(p21.x, p22.x)
                  and std::max(p11.x, p12.x) >= std::min(p21.x, p22.x))
                 or (std::min(p11.x, p12.x) <= std::max(p21.x, p22.x)
                     and std::min(p11.x, p12.x) >= std::min(p21.x, p22.x))))
            return true;
    } else if (dx1 == 0. and dx2 != 0.)
        return is_intersect_vertical_with_line(p11, p12, p21, p22);
    else if (dx1 != 0. and dx2 == 0.)
        return is_intersect_vertical_with_line(p21, p22, p11, p12);
    else {
        float k1 = (p11.y - p12.y) / dx1;
        float b1 = p11.y - k1 * p11.x;
        float k2 = (p21.y - p22.y) / dx2;
        float b2 = p21.y - k2 * p21.x;
        if (k1 - k2 == 0.) {
            if ((std::max(p11.x, p12.x) >= std::min(p21.x, p22.x)
                 and std::max(p11.x, p12.x) <= std::max(p21.x, p22.x)
                 and std::min(p11.x, p12.x) >= std::min(p21.x, p22.x)
                 and std::min(p11.x, p12.x) <= std::max(p21.x, p22.x))
                or (std::max(p21.x, p22.x) >= std::min(p11.x, p12.x)
                    and std::max(p21.x, p22.x) <= std::max(p11.x, p12.x)
                    and std::min(p21.x, p22.x) >= std::min(p11.x, p12.x)
                    and std::min(p21.x, p22.x) <= std::max(p11.x, p12.x)))
                return true;
        } else {
            float x = (b2 - b1) / (k1 - k2);
            float y = k1 * x + b1;
            if (x >= std::min(p11.x, p12.x) and x <= std::max(p11.x, p12.x)
                and y >= std::min(p11.y, p12.y) and y <= std::min(p11.y, p12.y)
                and x >= std::min(p21.x, p22.x) and x <= std::max(p21.x, p22.x)
                and y >= std::min(p21.y, p22.y) and y <= std::min(p21.y, p22.y))
                return true;
        }
    }
    return false;
}

bool Calculate::is_intersect_vertical_with_line(
        Point p11,
        Point p12,
        Point p21,
        Point p22) // пересекаются ли вертикальная и диагональная линии
{
    float k2 = (p21.y - p22.y) / (p21.x - p22.x);
    float b2 = p21.y - k2 * p21.x;
    float x = p11.x;
    float y = k2 * x + b2;
    if (x >= std::min(p21.x, p22.x) and x <= std::max(p21.x, p22.x)
        and y >= std::min(p21.y, p22.y) and y <= std::max(p21.y, p22.y)
        and y >= std::min(p11.y, p12.y) and y <= std::max(p11.y, p12.y))
        return true;
    return false;
}

bool Calculate::is_intersect_triangle_with_triangle(
        Triangle obj1,
        Triangle obj2) // пересекается ли треугольник с другим треугольником
{
    for (size_t i = 0; i < 3; i++) {
        size_t ii = i + 1 == 3 ? 0 : i + 1;
        Point p11 = obj1.points[i];
        Point p12 = obj1.points[ii];
        for (size_t j = 0; j < 3; j++) {
            size_t jj = j + 1 == 3 ? 0 : j + 1;
            Point p21 = obj2.points[j];
            Point p22 = obj2.points[jj];
            if (is_intersect(p11, p12, p21, p22))
                return true;
        }
    }
    return false;
}

bool Calculate::is_intersect_triangle_with_circle(
        Triangle obj1, Circle obj2) // пересекается ли треугольник с кругом
{
    bool res1 = is_intersect_circle_line(obj2, obj1.points[0], obj1.points[1]);
    bool res2 = is_intersect_circle_line(obj2, obj1.points[1], obj1.points[2]);
    bool res3 = is_intersect_circle_line(obj2, obj1.points[0], obj1.points[2]);

    if (res1 || res2 || res3)
        return true;
    return false;
}

bool Calculate::is_intersect_triangle_with_polygon(
        Triangle obj1,
        Polygon obj2) // пересекается ли треугольник с многоугольником
{
    for (size_t i = 0; i < 3; i++) {
        size_t ii = i + 1 == 3 ? 0 : i + 1;
        Point p11 = obj1.points[i];
        Point p12 = obj1.points[ii];

        for (size_t j = 0; j < obj2.points.size(); j++) {
            size_t jj = j + 1 == obj2.points.size() ? 0 : j + 1;
            Point p21 = obj2.points[j];
            Point p22 = obj2.points[jj];
            if (is_intersect(p11, p12, p21, p22))
                return true;
        }
    }
    return false;
}

bool Calculate::is_intersect_circle_with_circle(
        Circle obj1, Circle obj2) // пересекается ли круг с другим кругом
{
    double d
            = sqrt(pow(obj2.point.x - obj1.point.x, 2)
                   + pow(obj2.point.y - obj1.point.y, 2));
    if (d > obj1.radius + obj2.radius)
        return false;
    return true;
}

bool Calculate::is_intersect_circle_with_polygon(
        Circle obj1, Polygon obj2) // пересекается ли круг с многоугольником
{
    for (size_t i = 0; i < obj2.points.size(); i++) {
        size_t ii = i + 1 == obj2.points.size() ? 0 : i + 1;
        Point p21 = obj2.points[i];
        Point p22 = obj2.points[ii];
        float dx2 = p21.x - p22.x;
        float a, b = 1, c;
        if (dx2 == 0.) {
            if (p21.x >= obj1.point.x - obj1.radius
                and p21.x <= obj1.point.x + obj1.radius
                and p21.x * p21.x
                                + std::max(p21.y, p22.y)
                                        * std::max(p21.y, p22.y)
                        <= obj1.radius * obj1.radius)
                return true;
        } else if (p21.y - p22.y == 0.) {
            if (p21.y >= obj1.point.y - obj1.radius
                and p21.y <= obj1.point.y + obj1.radius
                and p21.y * p21.y
                                + std::max(p21.x, p22.x)
                                        * std::max(p21.x, p22.x)
                        <= obj1.radius * obj1.radius)
                return true;
        } else {
            a = (p21.y - p22.y) / dx2;
            c = p21.y - a * p21.x;
            if (obj1.radius * obj1.radius * (a * a + b * b) - c * c >= 0)
                return true;
        }
    }
    return false;
}

bool Calculate::is_intersect_polygon_with_polygon(
        Polygon obj1,
        Polygon obj2) // пересекается ли многоугольник с другим многоугольником
{
    for (size_t i = 0; i < obj1.points.size(); i++) {
        size_t ii = i + 1 == obj1.points.size() ? 0 : i + 1;
        Point p11 = obj1.points[i];
        Point p12 = obj1.points[ii];
        for (size_t j = 0; j < obj2.points.size(); j++) {
            size_t jj = j + 1 == obj1.points.size() ? 0 : j + 1;
            Point p21 = obj2.points[j];
            Point p22 = obj2.points[jj];
            if (is_intersect(p11, p12, p21, p22))
                return true;
        }
    }
    return false;
}

bool Calculate::is_intersect_circle_line(
        Circle circle, Point p1, Point p2) // пересекаются ли круг и линия
{
    double x01 = p1.x - circle.point.x;
    double y01 = p1.y - circle.point.y;
    double x02 = p2.x - circle.point.x;
    double y02 = p2.y - circle.point.y;

    double dx = x02 - x01;
    double dy = y02 - y01;

    double a = dx * dx + dy * dy;
    double b = 2. * (x01 * dx + y01 * dy);
    double c = x01 * x01 + y01 * y01 - circle.radius * circle.radius;

    if (-b < 0.)
        return (c < 0.);
    if (-b < (2. * a))
        return (4. * a * c - b * b < 0.);
    return (a + b + c < 0.);
}

void Calculate::print_triangle(
        size_t i, size_t triangle_number) // вывести треугольник
{
    auto line = order_of_lines[i];
    Triangle obj = triangles[triangle_number];
    float perimeter = calculate_triangle_perimeter(obj);
    float area = calculate_triangle_area(obj);
    std::cout << i + 1 << ". " << line << "\n\tperimeter = " << perimeter
              << "\n\tarea = " << area << "\n\tintersects:" << std::endl;
    size_t triangle_number2 = 0;
    size_t circle_number = 0;
    size_t polygon_number = 0;
    for (size_t j = 0; j < order_of_objects.size(); j++) {
        if (triangle_number2 == triangle_number) // если текущий треугольник
            triangle_number2++;
        if (j != i) {
            if (order_of_objects[j] == TRIANGLE_NUMBER
                and is_intersect_triangle_with_triangle(
                        obj, triangles[triangle_number2])) {
                std::cout << "\t\t" << j + 1 << ": triangle" << std::endl;
                triangle_number2++;
            } else if (
                    order_of_objects[j] == CIRCLE_NUMBER
                    and is_intersect_triangle_with_circle(
                            obj, circles[circle_number])) {
                std::cout << "\t\t" << j + 1 << ": circle" << std::endl;
                circle_number++;
            } else if (
                    order_of_objects[j] == POLYGON_NUMBER
                    and is_intersect_triangle_with_polygon(
                            obj, polygons[polygon_number])) {
                std::cout << "\t\t" << j + 1 << ": polygon" << std::endl;
                polygon_number++;
            }
        }
    }
    std::cout << std::endl;
}

void Calculate::print_circle(size_t i, size_t circle_number) // вывести круг
{
    auto line = order_of_lines[i];
    Circle obj = circles[circle_number];
    float perimeter = calculate_circle_perimeter(obj);
    float area = calculate_circle_area(obj);
    std::cout << i + 1 << ". " << line << "\n\tperimeter = " << perimeter
              << "\n\tarea = " << area << "\n\tintersects:" << std::endl;
    size_t triangle_number = 0;
    size_t circle_number2 = 0;
    size_t polygon_number = 0;
    for (size_t j = 0; j < order_of_objects.size(); j++) {
        if (circle_number2 == circle_number) // если текущий круг
            circle_number2++;
        if (j != i) {
            if (order_of_objects[j] == TRIANGLE_NUMBER
                and is_intersect_triangle_with_circle(
                        triangles[triangle_number], obj)) {
                std::cout << "\t\t" << j + 1 << ": triangle" << std::endl;
                triangle_number++;
            } else if (
                    order_of_objects[j] == CIRCLE_NUMBER
                    and is_intersect_circle_with_circle(
                            obj, circles[circle_number2])) {
                std::cout << "\t\t" << j + 1 << ": circle" << std::endl;
                circle_number2++;
            } else if (
                    order_of_objects[j] == POLYGON_NUMBER
                    and is_intersect_circle_with_polygon(
                            obj, polygons[polygon_number])) {
                std::cout << "\t\t" << j + 1 << ": polygon" << std::endl;
                polygon_number++;
            }
        }
    }
    std::cout << std::endl;
}

void Calculate::print_polygon(
        size_t i, size_t polygon_number) // вывести многоугольник
{
    auto line = order_of_lines[i];
    Polygon obj = polygons[polygon_number];
    float perimeter = calculate_polygon_perimeter(obj);
    float area = calculate_polygon_area(obj);
    std::cout << i + 1 << ". " << line << "\n\tperimeter = " << perimeter
              << "\n\tarea = " << area << "\n\tintersects:" << std::endl;
    size_t triangle_number = 0;
    size_t circle_number = 0;
    size_t polygon_number2 = 0;
    for (size_t j = 0; j < order_of_objects.size(); j++) {
        if (polygon_number2 == polygon_number) // если текущий многоугольник
            polygon_number2++;
        if (j != i) {
            if (order_of_objects[j] == TRIANGLE_NUMBER
                and is_intersect_triangle_with_polygon(
                        triangles[triangle_number], obj)) {
                std::cout << "\t\t" << j + 1 << ": triangle" << std::endl;
                triangle_number++;
            } else if (
                    order_of_objects[j] == CIRCLE_NUMBER
                    and is_intersect_circle_with_polygon(
                            circles[circle_number], obj)) {
                std::cout << "\t\t" << j + 1 << ": circle" << std::endl;
                circle_number++;
            } else if (
                    order_of_objects[j] == POLYGON_NUMBER
                    and is_intersect_polygon_with_polygon(
                            obj, polygons[polygon_number2])) {
                std::cout << "\t\t" << j + 1 << ": polygon" << std::endl;
                polygon_number2++;
            }
        }
    }
    std::cout << std::endl;
}

std::vector<Triangle>& Calculate::get_triangles() // получить все треугольники
{
    return triangles;
}

std::vector<Circle>& Calculate::get_circles() // получить все круги
{
    return circles;
}

std::vector<Polygon>& Calculate::get_polygons() // получить все многоугольники
{
    return polygons;
}
