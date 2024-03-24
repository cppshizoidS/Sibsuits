#include <ctest.h>
#include <stdio.h>

#include <libgeometry/calculate.h>
#include <libgeometry/geom_parser.h>
#include <libgeometry/intersect.h>
#include <libgeometry/lexer.h>

CTEST(lexer, count_char)
{
    const char ch = '-';
    const char exp_ch = '-';
    int cnt = 0;

    int result = count_char(ch, exp_ch, &cnt);

    int expected = 1;
    ASSERT_EQUAL(expected, result);

    result = count_char(ch, exp_ch, &cnt);
    expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(lexer, to_lower_string)
{
    char string1[] = "Circle";
    char string2[] = "CIRCLE";
    char string3[] = "CirCle";
    char string4[] = "TRIangle";
    const char expected1[] = "circle";
    const char expected2[] = "triangle";

    to_lower_string(string1);
    to_lower_string(string2);
    to_lower_string(string3);
    to_lower_string(string4);

    ASSERT_STR(string1, expected1);
    ASSERT_STR(string2, expected1);
    ASSERT_STR(string3, expected1);
    ASSERT_STR(string4, expected2);
}

CTEST(lexer, read_str_number)
{
    char temp[NUM_LEN] = {0};
    int column = 0;
    FILE* file = fopen("read_str_number.txt", "w+");
    fprintf(file, "3.5 -1.5 0 4545454 12x 321( ");
    fseek(file, 0, SEEK_SET);

    int result = read_str_number(temp, &column, file);
    int expected = 0;
    ASSERT_STR(temp, "3.5");
    ASSERT_EQUAL(expected, result);

    char temp1[NUM_LEN] = {0};
    result = read_str_number(temp1, &column, file);
    expected = 0;
    ASSERT_STR(temp1, "-1.5");
    ASSERT_EQUAL(expected, result);

    char temp2[NUM_LEN] = {0};
    result = read_str_number(temp2, &column, file);
    expected = 0;
    ASSERT_STR(temp2, "0");
    ASSERT_EQUAL(expected, result);

    char temp3[NUM_LEN] = {0};
    result = read_str_number(temp3, &column, file);
    expected = 0;
    ASSERT_STR(temp3, "4545454");
    ASSERT_EQUAL(expected, result);

    char temp4[NUM_LEN] = {0};
    result = read_str_number(temp4, &column, file);
    expected = ER_NOT_DOUBLE;
    ASSERT_EQUAL(expected, result);

    file->_IO_read_ptr++;
    char temp5[NUM_LEN] = {0};
    result = read_str_number(temp5, &column, file);
    expected = ER_R_PARENTNESIS;
    ASSERT_EQUAL(expected, result);
    remove("read_str_number.txt");
}

CTEST(lexer, unexpect_char)
{
    char ch = ',';
    char expected_ch = '(';
    FILE* file = fopen("unexpect_char_test.txt", "w");
    bool result = unexpect_char(ch, expected_ch, file);
    bool expect = false;
    ASSERT_EQUAL(expect, result);

    expected_ch = ',';
    result = unexpect_char(ch, expected_ch, file);
    expect = true;
    ASSERT_EQUAL(expect, result);
    remove("unexpect_char_test.txt");
}

CTEST(calculate, circle_perimetr)
{
    Circle circle = {.radius = 1.5};

    double result = calculate_perimetr_circle(&circle);
    double expect = 9.4247;
    double tol = 1e-4;
    ASSERT_DBL_NEAR_TOL(expect, result, tol);
}

CTEST(calculate, circle_area)
{
    Circle circle = {.radius = 1.5};

    double result = calculate_area_circle(&circle);
    double expect = 7.0686;
    double tol = 1e-4;
    ASSERT_DBL_NEAR_TOL(expect, result, tol);
}

CTEST(calculate, triangle_perimetr)
{
    Triangle triangle = {{-3, -2}, {-1, 0}, {-3, 2}, {-3, -2}};

    double result = calculate_perimetr_triangle(&triangle);
    double expect = 9.657;
    double tol = 1e-3;
    ASSERT_DBL_NEAR_TOL(expect, result, tol);
}

CTEST(calculate, triangle_area)
{
    Triangle triangle = {{-3, -2}, {-1, 0}, {-3, 2}, {-3, -2}};

    double result = calculate_area_triangle(&triangle);
    double expect = 4;
    double tol = 1e-4;
    ASSERT_DBL_NEAR_TOL(expect, result, tol);
}

CTEST(parser, read_geom_name_triangle)
{
    int column = 1;
    char ch = 0;
    char geom[25] = {0};
    FILE* file = fopen("read_geom_name.txt", "w+");
    fprintf(file, "triangle(");
    fseek(file, 0, SEEK_SET);

    ch = getc(file);
    geom[0] = ch;
    int result = read_str(&column, ch, geom, file);
    int expect = END_OF_NAME;
    remove("read_geom_name.txt");
    ASSERT_STR("triangle", geom);
    ASSERT_EQUAL(expect, result);
}

CTEST(parser, read_geom_name_circle)
{
    int column = 1;
    char ch = 0;
    char geom[25] = {0};
    FILE* file = fopen("read_geom_name.txt", "w+");
    fprintf(file, "circle ");
    fseek(file, 0, SEEK_SET);

    ch = getc(file);
    geom[0] = ch;
    int result = read_str(&column, ch, geom, file);
    int expect = END_OF_NAME;
    remove("read_geom_name.txt");
    ASSERT_STR("circle", geom);
    ASSERT_EQUAL(expect, result);
}

CTEST(intersect, circles)
{
    Circle a = {.point.x = 2, .point.y = 3, .radius = 1};
    Circle b = {.point.x = 0, .point.y = 0, .radius = 1};

    bool result = is_intersect_circles(a, b);
    bool expect = false;
    ASSERT_EQUAL(expect, result);

    Circle x = {.point.x = 0, .point.y = 0, .radius = 1};
    Circle y = {.point.x = 0, .point.y = 0, .radius = 1};

    result = is_intersect_circles(x, y);
    expect = true;
    ASSERT_EQUAL(expect, result);

    Circle k = {.point.x = 1, .point.y = 2, .radius = 1};
    Circle m = {.point.x = 0, .point.y = 0, .radius = 5};

    result = is_intersect_circles(k, m);
    expect = true;
    ASSERT_EQUAL(expect, result);
}

CTEST(intersect, triangles)
{
    Triangle a = {.p1 = {1, 1}, .p2 = {2, 4}, .p3 = {3, 3}, .p4 = {1, 1}};
    Triangle b = {.p1 = {2, 3}, .p2 = {4, 5}, .p3 = {4, 2}, .p4 = {2, 3}};

    bool result = is_intersect_triangles(a, b);
    bool expect = true;
    ASSERT_EQUAL(expect, result);

    Triangle x = {.p1 = {-3, -2}, .p2 = {-1, 0}, .p3 = {-3, 2}, .p4 = {-3, -2}};
    Triangle y = {.p1 = {3, -2}, .p2 = {-1, 0}, .p3 = {-3, 2}, .p4 = {3, -2}};

    result = is_intersect_triangles(x, y);
    expect = false;
    ASSERT_EQUAL(expect, result);
}

CTEST(intersect, circle_and_triangle)
{
    Circle circle = {.point = {0, 0}, .radius = 1.5};
    Triangle t = {.p1 = {-3, -2}, .p2 = {-1, 0}, .p3 = {-3, 2}, .p4 = {-3, -2}};

    bool result = is_intersect_circle_triangle(circle, t);
    bool expect = true;
    ASSERT_EQUAL(expect, result);

    Circle circle1 = {.point = {0, 0}, .radius = 1.5};
    Triangle t1 = {.p1 = {3, -2}, .p2 = {3, 2}, .p3 = {1, 0}, .p4 = {3, -2}};

    result = is_intersect_circle_triangle(circle1, t1);
    expect = true;
    ASSERT_EQUAL(expect, result);

    Circle circle2 = {.point = {0, 0}, .radius = 1.5};
    Triangle t2 = {.p1 = {3, -2}, .p2 = {3, 2}, .p3 = {2, 0}, .p4 = {3, -2}};

    result = is_intersect_circle_triangle(circle2, t2);
    expect = false;
    ASSERT_EQUAL(expect, result);
}