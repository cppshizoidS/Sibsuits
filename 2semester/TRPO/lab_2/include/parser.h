#ifndef PARSER_H
#define PARSER_H

#include "geometry.h"

Circle parse_circle(char* input);
Triangle parse_triangle(char* input);
Polygon parse_polygon(char* input);

#endif
