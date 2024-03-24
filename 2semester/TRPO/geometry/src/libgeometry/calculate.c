#include <math.h>
#include <stdlib.h>

#include <libgeometry/calculate.h>

double calculate_perimetr_circle(Circle* circle)
{
    return 2 * M_PI * circle->radius;
}

double calculate_area_circle(Circle* circle)
{
    return M_PI * circle->radius * circle->radius;
}

void circle_calculate(Circle* circle)
{
    circle->perimeter = calculate_perimetr_circle(circle);
    circle->area = calculate_area_circle(circle);
}

double calculate_perimetr_triangle(Triangle* tr)
{
    double len_1, len_2, len_3;
    len_1 = sqrt(pow(tr->p1.x - tr->p2.x, 2) + pow(tr->p1.y - tr->p2.y, 2));
    len_2 = sqrt(pow(tr->p1.x - tr->p3.x, 2) + pow(tr->p1.y - tr->p3.y, 2));
    len_3 = sqrt(pow(tr->p2.x - tr->p3.x, 2) + pow(tr->p2.y - tr->p3.y, 2));
    return len_1 + len_2 + len_3;
}

double calculate_area_triangle(Triangle* tr)
{
    double area_l, area_r;
    area_l = (tr->p2.x - tr->p1.x) * (tr->p3.y - tr->p1.y);
    area_r = (tr->p3.x - tr->p1.x) * (tr->p2.y - tr->p1.y);
    return 0.5 * fabs(area_l - area_r);
}

void triangle_calculate(Triangle* tr)
{
    tr->area = calculate_area_triangle(tr);
    tr->perimeter = calculate_perimetr_triangle(tr);
}