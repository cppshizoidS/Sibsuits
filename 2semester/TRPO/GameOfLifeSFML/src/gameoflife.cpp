#include "../include/gameoflife.hpp"

/**
 * @brief Конструктор класса GameOfLife.
 * 
 * Инициализирует игровое окно и сетку, а также случайным образом заполняет некоторые клетки.
 */
GameOfLife::GameOfLife() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Conway's Game of Life") {
    grid.resize(GRID_WIDTH * GRID_HEIGHT, false);
    nextGrid.resize(GRID_WIDTH * GRID_HEIGHT, false);
    paused = true;

    // Инициализация генератора случайных чисел
    randomEngine.seed(std::random_device{}());

    // Случайное заполнение некоторых клеток
    std::uniform_int_distribution<int> distX(0, GRID_WIDTH - 1);
    std::uniform_int_distribution<int> distY(0, GRID_HEIGHT - 1);
    for (int i = 0; i < 1000; ++i) {
        int x = distX(randomEngine);
        int y = distY(randomEngine);
        grid[y * GRID_WIDTH + x] = true;
    }
}
/**
 * @brief Основной цикл для запуска симуляции игры Жизнь.
 * 
 * Обрабатывает пользовательский ввод, обновляет сетку и рисует сетку на окне.
 */
void GameOfLife::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
                paused = !paused;
        }

        if (!paused) {
            update();
        }

        draw();
    }
}
/**
 * @brief Подсчитывает количество живых соседей вокруг клетки.
 * 
 * @param x Координата x клетки.
 * @param y Координата y клетки.
 * @return Количество живых соседей.
 */
int GameOfLife::countNeighbors(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0)
                continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < GRID_WIDTH && ny >= 0 && ny < GRID_HEIGHT && grid[ny * GRID_WIDTH + nx])
                count++;
        }
    }
    return count;
}
/**
 * @brief Обновляет сетку на основе правил игры Жизнь.
 * 
 * Применяет правила игры Жизнь для обновления текущей сетки.
 */
void GameOfLife::update() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            int neighbors = countNeighbors(x, y);
            int index = y * GRID_WIDTH + x;
            if (grid[index]) {
                nextGrid[index] = (neighbors == 2 || neighbors == 3);
            } else {
                nextGrid[index] = (neighbors == 3);
            }
        }
    }
    grid.swap(nextGrid);
}
/**
 * @brief Отрисовывает текущее состояние сетки на окне.
 * 
 * Очищает окно, рисует живые клетки и отображает обновленное окно.
 */
void GameOfLife::draw() {
    window.clear();

    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    cell.setFillColor(sf::Color::White);

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[y * GRID_WIDTH + x]) {
                cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                window.draw(cell);
            }
        }
    }

    window.display();
}
