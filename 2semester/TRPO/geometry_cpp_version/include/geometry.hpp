#pragma once

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define OK 0                  // всё хорошо
#define FILE_NOT_FOUND 1      // файл не найден
#define INVALID_SYMBOL 2      // непонятный символ
#define INVALID_COMMAND 3     // непонятная команда
#define MISSING_PARENTHESIS 4 // пропущенная скобка
#define EXTRA_PARENTHESIS 5   // лишняя скобка
#define UNEXPECTED_TOKEN 6    // лишний токен

struct Point {
    float x, y;
};

struct Triangle {
    Point points[3];
};

struct Circle {
    Point point;
    float radius;
};

struct Polygon {
    std::vector<Point> points;
};

const std::string ALPHABETIC
        = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"; // алфавит
const std::string NUMBERS = "0123456789";                         // цифры
const std::string SPECIAL_SYMBOLS = "(),.- "; // спецсимволы

void printFileNotFound(); // вывод ошибки "файл не найден" с завершением
                          // программы

#include <calculate.hpp>
#include <lexer.hpp>
#include <parser.hpp>

void geometry(int argc, char const* argv[]); // основная функция
