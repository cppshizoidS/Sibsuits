#pragma once
#include <stdio.h>

#define NAME_SIZE 32
#define N_CIRCLE 50
#define N_TRIANGLE 50
#define CIRCLE 1
#define TRIANGLE 2

typedef struct point {
    double x;
    double y;
} Point;

typedef struct circle {
    char name[NAME_SIZE];
    Point point;
    double radius;
    double perimeter;
    double area;
    int number;
} Circle;

typedef struct triangle {
    char name[NAME_SIZE];
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    double perimeter;
    double area;
    int number;
} Triangle;

int read_str(int* column, char ch, char geom[], FILE* file);
void show_info_triangle(Triangle* tr);
void take_info_triangle(Triangle* tr, int* column, int is_file, FILE* file);
void parser(FILE* file, int is_file);
void show_info_circle(Circle* circle);
void take_info_circle(Circle* circle, int* column, int is_file, FILE* file);
