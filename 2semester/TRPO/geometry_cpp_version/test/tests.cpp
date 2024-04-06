#include "../thirdparty/ctest.h"
#include <geometry.hpp>

CTEST(lexer, triangle)
{
    std::string str = "triangle(-345 -2, -5 0, -3 20)";

    Lexer lexer;
    lexer.create_tokens(str);
    auto tokens = lexer.get_tokens();

    size_t expected_size = 20;
    ASSERT_EQUAL_U(expected_size, tokens.size());

    std::vector<std::string> expected_tokens
            = {"triangle", "(", "-", "345", " ", "-", "2", ",", " ",  "-",
               "5",        " ", "0", ",",   " ", "-", "3", " ", "20", ")"};
    for (size_t i = 0; i < expected_size; i++)
        ASSERT_STR(expected_tokens[i].c_str(), tokens[i].c_str());
}

CTEST(lexer, circle)
{
    std::string str = "circle(1 0, 1.5)";

    Lexer lexer;
    lexer.create_tokens(str);
    auto tokens = lexer.get_tokens();

    std::vector<std::string> expected_tokens
            = {"circle", "(", "1", " ", "0", ",", " ", "1", ".", "5", ")"};
    ASSERT_EQUAL_U(expected_tokens.size(), tokens.size());

    for (size_t i = 0; i < expected_tokens.size(); i++)
        ASSERT_STR(expected_tokens[i].c_str(), tokens[i].c_str());
}

CTEST(lexer, polygon)
{
    std::string str = "polygon(33 -2, 1 0, 3 2, 3 -33)";

    Lexer lexer;
    lexer.create_tokens(str);
    auto tokens = lexer.get_tokens();

    // clang-format off
    std::vector<std::string> expected_tokens
            = {"polygon", "(", "33", " ", "-", "2", ",", " ", "1", " ", "0", ",", " ", "3", " ", "2", ",", " ", "3", " ", "-", "33",
               ")"};
    ASSERT_EQUAL_U(expected_tokens.size(), tokens.size());
    // clang-format on

    for (size_t i = 0; i < expected_tokens.size(); i++)
        ASSERT_STR(expected_tokens[i].c_str(), tokens[i].c_str());
}

CTEST(parser, triangle)
{
    std::string str = "triangle(-345 -2, -5 0, -3 20)";

    Lexer lexer;
    Calculate calc;
    lexer.create_tokens(str);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str);

    auto triangles = calc.get_triangles();
    ASSERT_EQUAL_U(1, triangles.size());

    Triangle expected_triangle = {{{-345, -2}, {-5, 0}, {-3, 20}}};
    Triangle triangle = triangles[0];
    for (size_t i = 0; i < 3; i++) {
        ASSERT_DBL_NEAR(expected_triangle.points[i].x, triangle.points[i].x);
        ASSERT_DBL_NEAR(expected_triangle.points[i].y, triangle.points[i].y);
    }
}

CTEST(parser, circle)
{
    std::string str = "circle(1 0, 1.5)";

    Lexer lexer;
    Calculate calc;
    lexer.create_tokens(str);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str);

    auto circles = calc.get_circles();
    ASSERT_EQUAL_U(1, circles.size());

    Circle expected_circle = {{1, 0}, 1.5};
    Circle circle = circles[0];
    ASSERT_DBL_NEAR(expected_circle.point.x, circle.point.x);
    ASSERT_DBL_NEAR(expected_circle.point.y, circle.point.y);
    ASSERT_DBL_NEAR(expected_circle.radius, circle.radius);
}

CTEST(parser, polygon)
{
    std::string str = "polygon(33 -2, 1 0, 3 2, 3 -33)";

    Lexer lexer;
    Calculate calc;
    lexer.create_tokens(str);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str);

    auto polygons = calc.get_polygons();
    ASSERT_EQUAL_U(1, polygons.size());

    Polygon expected_polygon = {{{33, -2}, {1, 0}, {3, 2}, {3, -33}}};
    Polygon polygon = polygons[0];
    for (size_t i = 0; i < expected_polygon.points.size(); i++) {
        ASSERT_DBL_NEAR(expected_polygon.points[i].x, polygon.points[i].x);
        ASSERT_DBL_NEAR(expected_polygon.points[i].y, polygon.points[i].y);
    }
}

CTEST(calculate, triangle)
{
    std::string str = "triangle(-345 -2, -5 0, -3 20)";

    Lexer lexer;
    Calculate calc;
    lexer.create_tokens(str);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str);

    float expected_perimeter = 702.8125;
    float expected_area = 3397.9966;
    float perimeter
            = calc.calculate_triangle_perimeter(calc.get_triangles()[0]);
    float area = calc.calculate_triangle_area(calc.get_triangles()[0]);

    ASSERT_DBL_NEAR(expected_perimeter, perimeter);
    ASSERT_DBL_NEAR(expected_area, area);
}

CTEST(calculate, circle)
{
    std::string str = "circle(1 0, 1.5)";

    Lexer lexer;
    Calculate calc;
    lexer.create_tokens(str);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str);

    float expected_perimeter = 9.424778;
    float expected_area = 7.0685835;
    float perimeter = calc.calculate_circle_perimeter(calc.get_circles()[0]);
    float area = calc.calculate_circle_area(calc.get_circles()[0]);

    ASSERT_DBL_NEAR(expected_perimeter, perimeter);
    ASSERT_DBL_NEAR(expected_area, area);
}

CTEST(calculate, polygon)
{
    std::string str = "polygon(33 -2, 1 0, 3 2, 3 -33)";

    Lexer lexer;
    Calculate calc;
    lexer.create_tokens(str);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str);

    float expected_perimeter = 113.03018;
    float expected_area = 491;
    float perimeter = calc.calculate_polygon_perimeter(calc.get_polygons()[0]);
    float area = calc.calculate_polygon_area(calc.get_polygons()[0]);

    ASSERT_DBL_NEAR(expected_perimeter, perimeter);
    ASSERT_DBL_NEAR(expected_area, area);
}

CTEST(intersect, triangle_with_triangle_true)
{
    std::string str1 = "triangle(-3 -2, -1 0, -3 2)";
    std::string str2 = "triangle(-5 0, -1 1, -4 4)";

    Calculate calc;
    Lexer lexer1;
    lexer1.create_tokens(str1);
    Parser parser1;
    parser1.parsing(calc, lexer1.get_tokens(), str1);
    Lexer lexer2;
    lexer2.create_tokens(str2);
    Parser parser2;
    parser2.parsing(calc, lexer2.get_tokens(), str2);

    ASSERT_TRUE(calc.is_intersect_triangle_with_triangle(
            calc.get_triangles()[0], calc.get_triangles()[1]));
}

CTEST(intersect, triangle_with_triangle_false)
{
    std::string str1 = "triangle(-3 -2, -1 0, -3 2)";
    std::string str2 = "triangle(3 -2, 1 0, 3 2)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_FALSE(calc.is_intersect_triangle_with_triangle(
            calc.get_triangles()[0], calc.get_triangles()[1]));
}

CTEST(intersect, triangle_with_circle_true)
{
    std::string str1 = "triangle(-3 -2, -1 0, -3 2)";
    std::string str2 = "circle(0 0, 1.5)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_TRUE(calc.is_intersect_triangle_with_circle(
            calc.get_triangles()[0], calc.get_circles()[0]));
}

CTEST(intersect, triangle_with_circle_false)
{
    std::string str1 = "triangle(-3 -2, -5 0, -3 2)";
    std::string str2 = "circle(0 0, 1.5)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_FALSE(calc.is_intersect_triangle_with_circle(
            calc.get_triangles()[0], calc.get_circles()[0]));
}

CTEST(intersect, triangle_with_polygon_true)
{
    std::string str1 = "triangle(-3 -2, -1 0, -3 2)";
    std::string str2 = "polygon(-3 -2, -5 0, -3 2)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_TRUE(calc.is_intersect_triangle_with_polygon(
            calc.get_triangles()[0], calc.get_polygons()[0]));
}

CTEST(intersect, triangle_with_polygon_false)
{
    std::string str1 = "triangle(-3 -2, -1 0, -3 2)";
    std::string str2 = "polygon(3 -2, 1 0, 3 2)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_FALSE(calc.is_intersect_triangle_with_polygon(
            calc.get_triangles()[0], calc.get_polygons()[0]));
}

CTEST(intersect, circle_with_cirlce_true)
{
    std::string str1 = "circle(0 0, 1.5)";
    std::string str2 = "circle(1 1, 2)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_TRUE(calc.is_intersect_circle_with_circle(
            calc.get_circles()[0], calc.get_circles()[1]));
}

CTEST(intersect, circle_with_cirlce_false)
{
    std::string str1 = "circle(0 0, 1.5)";
    std::string str2 = "circle(10 10, 1)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_FALSE(calc.is_intersect_circle_with_circle(
            calc.get_circles()[0], calc.get_circles()[1]));
}

CTEST(intersect, circle_with_polygon_true)
{
    std::string str1 = "circle(0 0, 1.5)";
    std::string str2 = "polygon(3 -2, 1 0, 3 2)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_TRUE(calc.is_intersect_circle_with_polygon(
            calc.get_circles()[0], calc.get_polygons()[0]));
}

CTEST(intersect, circle_with_polygon_false)
{
    std::string str1 = "circle(0 0, 1.5)";
    std::string str2 = "polygon(-3 -2, -5 0, -3 2)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_FALSE(calc.is_intersect_circle_with_polygon(
            calc.get_circles()[0], calc.get_polygons()[0]));
}

CTEST(intersect, polygon_with_polygon_true)
{
    std::string str1 = "polygon(-3 -2, 10 0, -3 2)";
    std::string str2 = "polygon(3 -2, 1 0, 3 2)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_TRUE(calc.is_intersect_polygon_with_polygon(
            calc.get_polygons()[0], calc.get_polygons()[1]));
}

CTEST(intersect, polygon_with_polygon_false)
{
    std::string str1 = "polygon(-3 -2, -1 0, -3 2)";
    std::string str2 = "polygon(3 -2, 1 0, 3 2)";

    Calculate calc;
    Lexer lexer;
    lexer.create_tokens(str1);
    Parser parser;
    parser.parsing(calc, lexer.get_tokens(), str1);
    lexer.create_tokens(str2);
    parser.parsing(calc, lexer.get_tokens(), str2);

    ASSERT_FALSE(calc.is_intersect_polygon_with_polygon(
            calc.get_polygons()[0], calc.get_polygons()[1]));
}
