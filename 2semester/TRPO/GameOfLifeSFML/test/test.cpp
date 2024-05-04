#include "../include/gameoflife.hpp"
#include <gtest/gtest.h>

class GameOfLifeTest : public ::testing::Test {
protected:
    GameOfLife game;

    // вспомогательная функция для установки значений сетки
    void setGridValue(int x, int y, bool value) {
        game.grid[y * GRID_WIDTH + x] = value;
    }
};

// тест функции подсчета соседей
TEST(GameOfLifeTest, CountNeighbors) {
    GameOfLife game;

    // тестовый случай без живых соседей
    EXPECT_EQ(game.countNeighbors(5, 5), 0);

    // тестовый случай с одним живым соседом
    game.grid[4 * GRID_WIDTH + 5] = true;
    EXPECT_EQ(game.countNeighbors(5, 5), 1);

    // тестовый случай с восьмью живыми соседями
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            game.grid[(5 + dy) * GRID_WIDTH + (5 + dx)] = true;
        }
    }
    EXPECT_EQ(game.countNeighbors(5, 5), 8);
}

// тест функции обновления
TEST(GameOfLifeTest, Update) {
    GameOfLife game;

    // создаем паттерн "мигающий маяк"
    game.grid[4 * GRID_WIDTH + 5] = true;
    game.grid[5 * GRID_WIDTH + 5] = true;
    game.grid[6 * GRID_WIDTH + 5] = true;

    // обновляем сетку
    game.update();

    // проверяем, изменился ли паттерн после одной итерации
    EXPECT_FALSE(game.grid[4 * GRID_WIDTH + 5]);
    EXPECT_TRUE(game.grid[5 * GRID_WIDTH + 5]);
    EXPECT_FALSE(game.grid[6 * GRID_WIDTH + 5]);

    // снова обновляем сетку
    game.update();

    // проверяем, вернулся ли паттерн к исходному состоянию после двух итераций
    EXPECT_TRUE(game.grid[4 * GRID_WIDTH + 5]);
    EXPECT_TRUE(game.grid[5 * GRID_WIDTH + 5]);
    EXPECT_TRUE(game.grid[6 * GRID_WIDTH + 5]);
}

int GTEST_MAIN();
