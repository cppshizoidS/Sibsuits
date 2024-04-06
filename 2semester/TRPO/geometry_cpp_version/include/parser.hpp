#pragma once

#include <geometry.hpp>

#define TRIANGLE "triangle"
#define CIRCLE "circle"
#define POLYGON "polygon"

#define OBJECT_NOT_DEFINED 0
#define TRIANGLE_NUMBER 1
#define CIRCLE_NUMBER 2
#define POLYGON_NUMBER 3

class Parser {
public:
    void
    parsing(Calculate& calc,
            std::vector<std::string>& tokens,
            std::string& line); // парсинг

private:
    Triangle triangle;
    Circle circle;
    Polygon polygon;

    size_t number_object = OBJECT_NOT_DEFINED;

    void parsing_triangle(
            Calculate& calc,
            std::vector<std::string>& tokens,
            std::string& line,
            int& col); // парсинг треугольника
    void parsing_circle(
            Calculate& calc,
            std::vector<std::string>& tokens,
            std::string& line,
            int& col); // парсинг круга
    void parsing_polygon(
            Calculate& calc,
            std::vector<std::string>& tokens,
            std::string& line,
            int& col); // парсинг полигона

    bool is_alphabetic(std::string& str);

    void print_undefined_command(std::string& line, int col); // вывод
                                                              // ошибки
                                                              // непонятной
                                                              // команды
    void print_missing_parenthesis(std::string& line, int col); // вывод
                                                                // ошибки
                                                                // пропущенной
                                                                // скобки
    void print_extra_parenthesis(std::string& line, int col); // вывод
                                                              // ошибки
                                                              // лишней
                                                              // скобки
    void print_undefined_symbol(std::string& line, int col);  // вывод
                                                              // ошибки
    // неопределённого
    // символа
    void print_extra_token(std::string& line, int col); // вывод
                                                        // ошибки
                                                        // лишнего
                                                        // токена
};
