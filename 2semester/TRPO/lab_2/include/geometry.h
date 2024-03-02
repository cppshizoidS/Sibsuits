#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

typedef struct {
    Point vertices[3];
} Triangle;

typedef struct {
    Point vertices[10];
    int num_vertices;
} Polygon;

typedef enum {
    CIRCLE,
    TRIANGLE,
    POLYGON,
} FigureType;

typedef struct {
    FigureType type;
    union {
        Circle circle;
        Triangle triangle;
        Polygon polygon;
    } shape;
} Figure;

double distance(Point a, Point b);
double circle_perimeter(Circle circle);
double circle_area(Circle circle);
double triangle_perimeter(Triangle triangle);
double triangle_area(Triangle triangle);
double polygon_perimeter(Polygon polygon);
double polygon_area(Polygon polygon);

#endif
