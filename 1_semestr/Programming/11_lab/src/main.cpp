#include <math.h>

#include <SFML/Graphics.hpp>

int
main() {
    const int SIZE_WINDOW[2] = {1024, 720};
    const int SCALE          = 20;
    const double CENTER[2]   = {SIZE_WINDOW[0] / 2.0, SIZE_WINDOW[1] / 1.5};
    const int bx = -SCALE, ex = SCALE;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode(SIZE_WINDOW[0], SIZE_WINDOW[1]),
        "lab11",
        sf::Style::Default,
        settings);

    sf::Vertex OX[] = {
        sf::Vertex(sf::Vector2f(CENTER[0], 0)),
        sf::Vertex(sf::Vector2f(CENTER[0], SIZE_WINDOW[1]))};
    sf::Vertex OY[] = {
        sf::Vertex(sf::Vector2f(0, CENTER[1])),
        sf::Vertex(sf::Vector2f(SIZE_WINDOW[0], CENTER[1]))};

    int count_points = 0;
    for (double x = bx; x < ex; x += 0.1) {
        int y = -pow(x - 3, 2) * SCALE + CENTER[1];
        if (y >= -10)
            count_points++;
    }

    sf::ConvexShape f1;
    f1.setPointCount(count_points);
    int i = 0;
    for (double x = bx; x < ex; x += 0.1) {
        int y = -pow(x - 3, 2) * SCALE + CENTER[1];
        if (y >= -10)
            f1.setPoint(i++, sf::Vector2f(x * SCALE + CENTER[0], y));
    }
    f1.setFillColor(sf::Color(0, 0, 0));
    f1.setOutlineThickness(1);
    f1.setOutlineColor(sf::Color(0, 255, 0));

    sf::RectangleShape f2(sf::Vector2f(SIZE_WINDOW[0], 1));
    f2.setPosition(0, -16 * SCALE + CENTER[1]);
    f2.setFillColor(sf::Color(0, 0, 255));

    // get count points
    count_points = 0;
    for (double x = bx; x < ex; x += 0.1)
        if (pow(x - 3, 2) <= 16)
            count_points++;

    sf::ConvexShape convex;
    convex.setPointCount(count_points + 1);
    i         = 0;
    double lx = 0;
    for (double x = bx; x < ex; x += 0.1) {
        double y = pow(x - 3, 2);
        if (y <= 16) {
            convex.setPoint(
                i++,
                sf::Vector2f(x * SCALE + CENTER[0], -y * SCALE + CENTER[1]));
            lx = x;
        }
    }
    convex.setPoint(
        i,
        sf::Vector2f(
            (lx + 0.1) * SCALE + CENTER[0],
            -pow(lx + 0.1 - 3, 2) * SCALE + CENTER[1]));
    convex.setFillColor(sf::Color(66, 7, 7));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();

        window.draw(f1);
        window.draw(convex);
        window.draw(f2);

        window.draw(OX, 2, sf::Lines);
        window.draw(OY, 2, sf::Lines);

        window.display();
    }

    return 0;
}
