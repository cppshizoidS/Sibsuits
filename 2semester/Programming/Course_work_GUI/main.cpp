#include <QApplication>
#include "studentapp.hpp"

/**
 * @brief Точка входа для приложения.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код выхода приложения.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StudentApp studentApp;
    studentApp.show();

    return app.exec();
}
