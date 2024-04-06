#include <geometry.hpp>

void printFileNotFound() // вывод ошибки "файл не найден" с завершением
                         // программы
{
    std::cout << "File isn't found!" << std::endl;
    exit(FILE_NOT_FOUND);
}

void geometry(int argc, char const* argv[])
{
    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i]);
        if (!file.is_open()) // проверка файла на существование
            printFileNotFound();

        std::string line; // текущая строка
        Calculate calc;

        while (getline(file, line)) { // получение строки
            if (line.length() == 0)
                continue;

            Lexer lexer;
            lexer.create_tokens(line); // создание массива токенов

            Parser parser;
            parser.parsing(calc, lexer.get_tokens(), line);

            // std::cout << "stop";
        }

        calc.print_objects();

        file.close();
    }
}
