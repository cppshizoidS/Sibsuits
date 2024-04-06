#include <geometry.hpp>

int main(int argc, char const* argv[])
{
    switch (argc) {
    case 1:
        printFileNotFound(); // если не указали файл
        break;

    default:
        geometry(argc, argv); // вызываем геометрию
        break;
    }

    return 0;
}
