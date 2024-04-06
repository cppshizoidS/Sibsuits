#include <parser.hpp>

void Parser::parsing(
        Calculate& calc, std::vector<std::string>& tokens, std::string& line)
{
    auto command = tokens[0];
    for (auto& symbol : command) // перевод в нижний регистр
        symbol = (symbol >= 'A' and symbol <= 'Z') ? symbol + 'a' - 'A'
                                                   : symbol;
    int col = 0;

    if (command.compare(TRIANGLE) == 0) // если треугольник
        parsing_triangle(calc, tokens, line, col);
    else if (command.compare(CIRCLE) == 0) // если круг
        parsing_circle(calc, tokens, line, col);
    else if (command.compare(POLYGON) == 0) // если многоугольник
        parsing_polygon(calc, tokens, line, col);
    else
        print_undefined_command(line, col); // ошибка
}

void Parser::parsing_triangle(
        Calculate& calc,
        std::vector<std::string>& tokens,
        std::string& line,
        int& col) // парсинг треугольника
{
    std::stack<char> brackets;
    number_object = TRIANGLE_NUMBER;
    int point_number = 0;
    int multiplier = 1;
    bool float_part = false;
    int axis = 0;

    col += tokens.front().length();

    for (int i = 0; i < 3; i++) // зануление треугольника
        triangle.points[i] = {0, 0};

    for (int i = 1; (size_t)i < tokens.size(); i++) {
        auto token = tokens[i];

        if (point_number > 2) // если точек больше 3-х
            break;

        if (token.compare("(") == 0)
            brackets.push('(');
        else if (token.compare(")") == 0) {
            if (brackets.empty())
                print_extra_parenthesis(line, tokens[0].length());
            brackets.pop();
        } else if (token.compare(",") == 0) { // обнуляем параметры точки
            point_number++;
            multiplier = 1;
            axis = 0;
            float_part = false;
        } else if (token.compare("-") == 0)
            multiplier = -1;
        else if (token.compare(".") == 0) {
            float_part = true;
            multiplier = 1;
        } else if (is_alphabetic(token)) // буква в аргуменах объекта
            print_undefined_symbol(line, col);
        else if (token.compare(" ") != 0) { // записываем точку
            if (brackets.empty())
                print_extra_token(line, col);

            float number = 0;
            for (auto& symbol : token)
                number = (float_part) ? number + (float)(symbol - '0') / 10.
                                      : number * 10. + symbol - '0';
            number *= multiplier;

            if (!axis) {
                if (tokens[i + 1].compare(".") != 0) {
                    axis++;
                    float_part = false;
                    multiplier = 1;
                }
                triangle.points[point_number].x += number;
            } else
                triangle.points[point_number].y += number;
        }

        col += token.length();
    }

    if (!brackets.empty())
        print_missing_parenthesis(line, col);

    calc.add_triangle(line, triangle, number_object);
}

void Parser::parsing_circle(
        Calculate& calc,
        std::vector<std::string>& tokens,
        std::string& line,
        int& col) // парсинг круга
{
    std::stack<char> brackets;
    number_object = CIRCLE_NUMBER;
    int multiplier = 1;
    bool float_part = false;
    int axis = 0;
    bool point = true;

    col += tokens.front().length();

    circle.point.x = 0;
    circle.point.y = 0;
    circle.radius = 0;

    for (int i = 1; (size_t)i < tokens.size(); i++) {
        auto token = tokens[i];

        if (token.compare("(") == 0)
            brackets.push('(');
        else if (token.compare(")") == 0) {
            if (brackets.empty())
                print_extra_parenthesis(line, tokens[0].length());
            brackets.pop();
        } else if (token.compare(",") == 0) { // обнуляем параметры точки
            multiplier = 1;
            axis = 0;
            float_part = false;
            point = false;
        } else if (token.compare("-") == 0)
            multiplier = -1;
        else if (token.compare(".") == 0) {
            float_part = true;
            multiplier = 1;
        } else if (is_alphabetic(token)) // буква в аргуменах объекта
            print_undefined_symbol(line, col);
        else if (token.compare(" ") != 0) { // записываем точку
            if (brackets.empty())
                print_extra_token(line, col);

            float number = 0;
            for (auto& symbol : token)
                number = (float_part) ? number + (float)(symbol - '0') / 10.
                                      : number * 10. + symbol - '0';
            number *= multiplier;
            if (point) {
                if (!axis) {
                    if (tokens[i + 1].compare(".") != 0) {
                        float_part = false;
                        axis++;
                        multiplier = 1;
                    }
                    circle.point.x += number;
                } else
                    circle.point.y += number;
            } else
                circle.radius += number;
        }

        col += token.length();
    }

    if (!brackets.empty())
        print_missing_parenthesis(line, col);

    calc.add_circle(line, circle, number_object);
}

void Parser::parsing_polygon(
        Calculate& calc,
        std::vector<std::string>& tokens,
        std::string& line,
        int& col) // парсинг полигона
{
    std::stack<char> brackets;
    number_object = POLYGON_NUMBER;
    int point_number = 0;
    int multiplier = 1;
    bool float_part = false;
    int axis = 0;

    col += tokens.front().length();

    polygon.points.push_back({0, 0});

    for (int i = 1; (size_t)i < tokens.size(); i++) {
        auto token = tokens[i];

        if (token.compare("(") == 0)
            brackets.push('(');
        else if (token.compare(")") == 0) {
            if (brackets.empty())
                print_extra_parenthesis(line, tokens[0].length());
            brackets.pop();
        } else if (token.compare(",") == 0) { // обнуляем параметры точки
            multiplier = 1;
            axis = 0;
            float_part = false;
            point_number++;
            polygon.points.push_back({0, 0});
        } else if (token.compare("-") == 0)
            multiplier = -1;
        else if (token.compare(".") == 0) {
            float_part = true;
            multiplier = 1;
        } else if (is_alphabetic(token)) // буква в аргуменах объекта
            print_undefined_symbol(line, col);
        else if (token.compare(" ") != 0) { // записываем точку
            if (brackets.empty())
                print_extra_token(line, col);

            float number = 0;
            for (auto& symbol : token)
                number = (float_part) ? number + (float)(symbol - '0') / 10.
                                      : number * 10. + symbol - '0';
            number *= multiplier;

            if (!axis) {
                if (tokens[i + 1].compare(".") != 0) {
                    float_part = false;
                    axis++;
                    multiplier = 1;
                }
                polygon.points[point_number].x += number;
            } else
                polygon.points[point_number].y += number;
        }

        col += token.length();
    }

    if (!brackets.empty())
        print_missing_parenthesis(line, col);

    calc.add_polygon(line, polygon, number_object);
}

bool Parser::is_alphabetic(std::string& str) // проверка на букву
{
    for (auto& symbol : str)
        if (ALPHABETIC.find(symbol) == std::string::npos)
            return false;
    return true;
}

void Parser::print_undefined_command(std::string& line, int col) // вывод
                                                                 // ошибки
                                                                 // непонятной
                                                                 // команды
{
    std::cout << line << "\n"
              << std::setw(col + 1) << '^' << "\nError at column " << col
              << ": expected 'circle', 'triangle' or 'polygon'" << std::endl;
    exit(INVALID_COMMAND);
}

void Parser::print_missing_parenthesis(
        std::string& line, int col) // вывод
                                    // ошибки
                                    // пропущенной
                                    // скобки
{
    std::cout << line << "\n"
              << std::setw(col + 1) << '^' << "\nError at column " << col
              << ": expected ')'" << std::endl;
    exit(MISSING_PARENTHESIS);
}
void Parser::print_extra_parenthesis(std::string& line, int col) // вывод
                                                                 // ошибки
                                                                 // лишней
                                                                 // скобки
{
    std::cout << line << "\n"
              << std::setw(col + 1) << '^' << "\nError at column " << col
              << ": expected '('" << std::endl;
    exit(EXTRA_PARENTHESIS);
}

void Parser::print_undefined_symbol(
        std::string& line, int col) // вывод ошибки
                                    // неопределённого
                                    // символа
{
    std::cout << line << "\n"
              << std::setw(col + 1) << '^' << "\nError at column " << col
              << ": expected '<double>'" << std::endl;
    exit(INVALID_SYMBOL);
}

void Parser::print_extra_token(std::string& line, int col) // вывод
                                                           // ошибки
                                                           // лишнего
                                                           // токена
{
    std::cout << line << "\n"
              << std::setw(col + 1) << '^' << "\nError at column " << col
              << ": unexpected token" << std::endl;
    exit(INVALID_SYMBOL);
}
