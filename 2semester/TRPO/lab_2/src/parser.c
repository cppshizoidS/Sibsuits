#include "../include/parser.h"
#include <stdio.h>
#include <string.h>

Circle parse_circle(char* input)
{
    Circle circle;
    // int result =
    sscanf(input,
           "circle(%lf %lf, %lf)",
           &circle.center.x,
           &circle.center.y,
           &circle.radius);
    /*
        if (result != 3) {
            fprintf(stderr, "Error in parsing circle at column %d: expected
       '<double> <double> <double>'\n", result); exit(EXIT_FAILURE);
        }
    */
    return circle;
}

Triangle parse_triangle(char* input)
{
    Triangle triangle;
    // int result =
    sscanf(input,
           "triangle((%lf %lf, %lf %lf, %lf %lf))",
           &triangle.vertices[0].x,
           &triangle.vertices[0].y,
           &triangle.vertices[1].x,
           &triangle.vertices[1].y,
           &triangle.vertices[2].x,
           &triangle.vertices[2].y);
    /*
    if (result != 6) {
        fprintf(stderr, "Error in parsing triangle at column %d: expected
    '<double> <double> <double> <double> <double> <double>'\n", result);
        exit(EXIT_FAILURE);
    }
    */
    return triangle;
}

Polygon parse_polygon(char* input)
{
    Polygon polygon;
    polygon.num_vertices = 0;

    char type[8]; // Для хранения типа фигуры
    int result = sscanf(
            input,
            "%7s %*[^((]%*[(](%lf %lf%*[,]%lf %lf%*[,]%lf %lf",
            type,
            &polygon.vertices[0].x,
            &polygon.vertices[0].y,
            &polygon.vertices[1].x,
            &polygon.vertices[1].y,
            &polygon.vertices[2].x,
            &polygon.vertices[2].y);
    /*if (result != 6) {
        fprintf(stderr, "Error in parsing polygon at column %d: expected
    '<double> <double> <double> <double> <double> <double>'\n", result);
        exit(EXIT_FAILURE);
    }*/
    // Узнаем количество вершин в строке
    char* pos = input;
    while ((pos = strchr(pos, ',')) != NULL) {
        polygon.num_vertices++;
        pos++;
    }
    polygon.num_vertices += 1; // В каждой строке точка содержит две координаты

    return polygon;
}
