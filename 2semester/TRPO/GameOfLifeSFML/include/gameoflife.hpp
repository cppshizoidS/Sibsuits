#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr int CELL_SIZE = 10;
constexpr int GRID_WIDTH = WINDOW_WIDTH / CELL_SIZE;
constexpr int GRID_HEIGHT = WINDOW_HEIGHT / CELL_SIZE;
/**
 * @brief Класс GameOfLife представляет собой симуляцию "Игра Жизнь".
 */
class GameOfLife {
public:
    /**
     * @brief Создает новый объект GameOfLife.
     */
    GameOfLife();

    /**
     * @brief Запускает основной цикл симуляции.
     */
    void run();

    /**
     * @brief Обновляет состояние сетки в соответствии с правилами "Игры Жизнь".
     */
    void update();

    /**
     * @brief Отрисовывает текущее состояние сетки на окне.
     */
    void draw();

    /**
     * @brief Подсчитывает количество живых соседей клетки в заданных координатах.
     * @param x Координата x клетки.
     * @param y Координата y клетки.
     * @return Количество живых соседей.
     */
    int countNeighbors(int x, int y);

    std::vector<bool> grid; /**< Сетка, представляющая текущее состояние симуляции. */
    std::vector<bool> nextGrid; /**< Сетка, представляющая следующее состояние симуляции. */
    sf::RenderWindow window; /**< Окно SFML, используемое для визуализации. */
    bool paused; /**< Флаг, указывающий на то, находится ли симуляция на паузе. */
    std::mt19937 randomEngine; /**< Генератор случайных чисел для инициализации клеток. */
};

#endif // GAMEOFLIFE_HPP
