#include <lexer.hpp>

void Lexer::create_tokens(std::string& line) // создание массива токенов
{
    tokens.clear();
    for (int col = 0; (size_t)col < line.length();
         col++) { // проходимся по каждому символу
        char symbol = line[col];
        token = "";

        if (ALPHABETIC.find(symbol) != std::string::npos) // проверяем если
                                                          // символ из алфавита
            add_command(line, col); // считываем и добавляем команду
        else if (NUMBERS.find(symbol) != std::string::npos) // если символ
                                                            // является числом
            add_number(line, col); // считываем и добовляем число
        else if (
                SPECIAL_SYMBOLS.find(symbol)
                != std::string::npos)     // если спецсимвол
            add_spec_symbol(line[col++]); // добовляем его
        else // при неопределённых символах убиваем программу
            print_invalid_symbol(line, col);
        col--;
    }
}

std::vector<std::string>& Lexer::get_tokens() // получение массива токенов
{
    return tokens;
}

void Lexer::add_command(
        std::string& line, int& col) // добавление команды в массив токенов
{
    while (ALPHABETIC.find(line[col]) != std::string::npos)
        token.push_back(line[col++]);
    tokens.push_back(token);
}

void Lexer::add_number(std::string& line, int& col) // добавление числа
                                                    // в массив токенов
{
    while (NUMBERS.find(line[col]) != std::string::npos)
        token.push_back(line[col++]);
    tokens.push_back(token);
}

void Lexer::add_spec_symbol(char symbol) // добавление
                                         // спецсимвола в массив токенов
{
    token.push_back(symbol);
    tokens.push_back(token);
}

void Lexer::print_invalid_symbol(std::string& line, int col) // вывод
                                                             // ошибки при
                                                             // неопределённых
                                                             // символах
{
    std::cout << line << '\n'
              << std::setw(col + 1) << '^' << "\nInvalid symbol" << std::endl;
    exit(INVALID_SYMBOL);
}