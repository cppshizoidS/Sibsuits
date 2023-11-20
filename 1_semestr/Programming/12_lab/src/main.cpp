#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>

int
main() {
    const int SIZE_WINDOW[] = {800, 600};
    const int COUNT_STARS   = 100;
    srand(time(NULL));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode(SIZE_WINDOW[0], SIZE_WINDOW[1]),
        "lab12",
        sf::Style::Default,
        settings);

    sf::ConvexShape stars[COUNT_STARS];

    for (int i = 0; i < COUNT_STARS; i++) {
        stars[i].setPointCount(32);
        int j = 0;

        stars[i].setPoint(j++, sf::Vector2f(0, 20));
        stars[i].setPoint(j++, sf::Vector2f(20, 20));
        stars[i].setPoint(j++, sf::Vector2f(20, 0));
        stars[i].setPoint(j++, sf::Vector2f(50, 50));

        stars[i].setPoint(j++, sf::Vector2f(30, 0));
        stars[i].setPoint(j++, sf::Vector2f(50, 20));
        stars[i].setPoint(j++, sf::Vector2f(70, 0));
        stars[i].setPoint(j++, sf::Vector2f(50, 50));

        stars[i].setPoint(j++, sf::Vector2f(80, 0));
        stars[i].setPoint(j++, sf::Vector2f(80, 20));
        stars[i].setPoint(j++, sf::Vector2f(100, 20));
        stars[i].setPoint(j++, sf::Vector2f(50, 50));

        stars[i].setPoint(j++, sf::Vector2f(100, 30));
        stars[i].setPoint(j++, sf::Vector2f(80, 50));
        stars[i].setPoint(j++, sf::Vector2f(100, 70));
        stars[i].setPoint(j++, sf::Vector2f(50, 50));

        stars[i].setPoint(j++, sf::Vector2f(100, 80));
        stars[i].setPoint(j++, sf::Vector2f(80, 80));
        stars[i].setPoint(j++, sf::Vector2f(80, 100));
        stars[i].setPoint(j++, sf::Vector2f(50, 50));

        stars[i].setPoint(j++, sf::Vector2f(70, 100));
        stars[i].setPoint(j++, sf::Vector2f(50, 80));
        stars[i].setPoint(j++, sf::Vector2f(30, 100));
        stars[i].setPoint(j++, sf::Vector2f(50, 50));

        stars[i].setPoint(j++, sf::Vector2f(20, 100));
        stars[i].setPoint(j++, sf::Vector2f(20, 80));
        stars[i].setPoint(j++, sf::Vector2f(0, 80));
        stars[i].setPoint(j++, sf::Vector2f(50, 50));

        stars[i].setPoint(j++, sf::Vector2f(0, 70));
        stars[i].setPoint(j++, sf::Vector2f(20, 50));
        stars[i].setPoint(j++, sf::Vector2f(0, 30));
        stars[i].setPoint(j++, sf::Vector2f(50, 50));

        stars[i].setFillColor(
            sf::Color(rand() % 256, rand() % 256, rand() % 256));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();

        for (int i = 0; i < COUNT_STARS; i++) {
            stars[i].setPosition(
                rand() % (SIZE_WINDOW[0] - 100),
                rand() % (SIZE_WINDOW[1] - 100));
            window.draw(stars[i]);
        }

        sf::sleep(sf::milliseconds(500));

        window.display();
    }

    return 0;
}
