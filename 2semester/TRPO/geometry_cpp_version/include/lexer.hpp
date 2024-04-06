#pragma once

#include <geometry.hpp>

#define SYMBOL_IS_NOT_DEFINED -1 // непоятный символ
#define SYMBOL_IS_ALPHABETIC 1   // символ из алфавита
#define SYMBOL_IS_NUMBER 2       // символ является числом
#define SYMBOL_IS_SPECIAL 3      // спецсимвол
#define SYMBOL_IS_SPACE 4        // пробел

class Lexer {
public:
    void create_tokens(std::string& line); // создание массива токенов
    std::vector<std::string>& get_tokens(); // получение массива токенов

private:
    std::vector<std::string> tokens;
    std::string token;

    void add_command(std::string& line, int& col); // добавление
                                                   // команды в массив токенов
    void add_number(std::string& line, int& col); // добавление
                                                  // числа в массив токенов
    void add_spec_symbol(char symbol); // добавление
                                       // спецсимвола в массив токенов

    void print_invalid_symbol(std::string& line, int col); // вывод
                                                           // ошибки при
                                                           // неопределённых
                                                           // символах
};
