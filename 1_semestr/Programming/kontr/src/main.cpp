#include "main.h"

int main() {
    // windwow size
    const int SIZE_WINDOW[] = {800, 600};
    int mode = 0;
    // сглаживание
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // отрисовка окна
    sf::RenderWindow window(sf::VideoMode(SIZE_WINDOW[0], SIZE_WINDOW[1]),
                            "kontr", sf::Style::Default, settings);
    // создание свободно движещейся фигуры
    sf::RectangleShape FreeMoveObject(sf::Vector2f(500, 100));
    int position_FreeMoveObject[2] = {150, 100};
    FreeMoveObject.setPosition(position_FreeMoveObject[0],
                               position_FreeMoveObject[1]);
    FreeMoveObject.setOutlineThickness(5);
    FreeMoveObject.setOutlineColor(sf::Color(0, 0, 0));
    sf::Text text_FreeMoveObject;
    sf::Font font_FreeMoveObject;
    font_FreeMoveObject.loadFromFile("../font/PledgeblackRegular.ttf");
    text_FreeMoveObject.setFont(font_FreeMoveObject);
    text_FreeMoveObject.setString("1. Free movement of the object");
    text_FreeMoveObject.setCharacterSize(42);
    text_FreeMoveObject.setFillColor(sf::Color(0, 0, 0));
    text_FreeMoveObject.setPosition(sf::Vector2f(
        position_FreeMoveObject[0], position_FreeMoveObject[1] + 20));

    sf::RectangleShape MoveObjectWithKeyboard(sf::Vector2f(640, 100));
    int position_MoveObjectWithKeyboard[2] = {70, 220};
    MoveObjectWithKeyboard.setPosition(position_MoveObjectWithKeyboard[0],
                                       position_MoveObjectWithKeyboard[1]);
    MoveObjectWithKeyboard.setOutlineThickness(5);
    MoveObjectWithKeyboard.setOutlineColor(sf::Color(0, 0, 0));
    sf::Text text_MoveObjectWithKeyboard;
    sf::Font font_MoveObjectWithKeyboard;
    font_MoveObjectWithKeyboard.loadFromFile("../font/PledgeblackRegular.ttf");
    text_MoveObjectWithKeyboard.setFont(font_MoveObjectWithKeyboard);
    text_MoveObjectWithKeyboard.setString(
        "2. Moving an object using the keyboard");
    text_MoveObjectWithKeyboard.setCharacterSize(42);
    text_MoveObjectWithKeyboard.setFillColor(sf::Color(0, 0, 0));
    text_MoveObjectWithKeyboard.setPosition(
        sf::Vector2f(position_MoveObjectWithKeyboard[0],
                     position_MoveObjectWithKeyboard[1] + 20));
    // exit button
    sf::RectangleShape Exit(sf::Vector2f(362, 100));
    int position_Exit[2] = {221, 340};
    Exit.setPosition(position_Exit[0], position_Exit[1]);
    Exit.setOutlineThickness(5);
    Exit.setOutlineColor(sf::Color(0, 0, 0));
    // menu font
    sf::Text text_Exit;
    sf::Font font_Exit;
    font_Exit.loadFromFile("../font/PledgeblackRegular.ttf");
    text_Exit.setFont(font_Exit);
    text_Exit.setString("3. Exiting the program");
    text_Exit.setCharacterSize(42);
    text_Exit.setFillColor(sf::Color(0, 0, 0));
    text_Exit.setPosition(
        sf::Vector2f(position_Exit[0], position_Exit[1] + 20));
    // loading textures
    sf::Texture texture1;
    texture1.loadFromFile("../textures/texture1.png");
    texture1.setSmooth(true);
    sf::Texture texture2;
    texture2.loadFromFile("../textures/texture2.png");
    texture2.setSmooth(true);

    int position_cube1[] = {350, 250};
    sf::RectangleShape Cube1(sf::Vector2f(100, 100));
    Cube1.setPosition(position_cube1[0], position_cube1[1]);
    Cube1.setTexture(&texture1);

    int position_cube2[] = {350, 250};
    int direction_cube2 = 0;
    sf::RectangleShape Cube2(sf::Vector2f(100, 100));
    Cube2.setPosition(position_cube2[0], position_cube2[1]);
    Cube2.setTexture(&texture2);
    // main loop for draw and handling keyboard and animations
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        window.clear(sf::Color(255, 255, 255));

        switch (mode) {
            case 0:
                window.draw(FreeMoveObject);
                window.draw(MoveObjectWithKeyboard);
                window.draw(Exit);

                window.draw(text_FreeMoveObject);
                window.draw(text_MoveObjectWithKeyboard);
                window.draw(text_Exit);

                choose_mode(&mode, sf::Mouse::getPosition(window),
                            FreeMoveObject, MoveObjectWithKeyboard, Exit);
                animation_buttons(sf::Mouse::getPosition(window),
                                  &FreeMoveObject, &MoveObjectWithKeyboard,
                                  &Exit);

                break;

            case 1:
                random_move(&Cube1, SIZE_WINDOW);
                window.draw(Cube1);
                move_45(&Cube2, &direction_cube2, SIZE_WINDOW);
                window.draw(Cube2);
                change_mode(&mode);
                break;

            case 2:
                move_keyboard(&Cube1);
                window.draw(Cube1);
                change_mode(&mode);
                break;

            case 3:
                window.close();
        }

        window.display();
    }

    return 0;
}
// choose mode
void choose_mode(int* mode, sf::Vector2i position, sf::RectangleShape Cube1,
                 sf::RectangleShape Cube2, sf::RectangleShape Cube3) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) ||
        ((position.x >= Cube1.getPosition().x &&
          position.x <= Cube1.getPosition().x + Cube1.getSize().x) &&
         (position.y >= Cube1.getPosition().y &&
          position.y <= Cube1.getPosition().y + Cube1.getSize().y) &&
         sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        *mode = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) ||
             ((position.x >= Cube2.getPosition().x &&
               position.x <= Cube2.getPosition().x + Cube2.getSize().x) &&
              (position.y >= Cube2.getPosition().y &&
               position.y <= Cube2.getPosition().y + Cube2.getSize().y) &&
              sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        *mode = 2;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) ||
             ((position.x >= Cube3.getPosition().x &&
               position.x <= Cube3.getPosition().x + Cube3.getSize().x) &&
              (position.y >= Cube3.getPosition().y &&
               position.y <= Cube3.getPosition().y + Cube3.getSize().y) &&
              sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        *mode = 3;
}
// animation of buttons in menu
void animation_buttons(sf::Vector2i position, sf::RectangleShape* Cube1,
                       sf::RectangleShape* Cube2, sf::RectangleShape* Cube3) {
    if ((position.x >= (*Cube1).getPosition().x &&
         position.x <= (*Cube1).getPosition().x + (*Cube1).getSize().x) &&
        (position.y >= (*Cube1).getPosition().y &&
         position.y <= (*Cube1).getPosition().y + (*Cube1).getSize().y)) {
        (*Cube1).setSize(sf::Vector2f(510, 110));
        (*Cube1).setPosition(145, 95);
    } else {
        (*Cube1).setSize(sf::Vector2f(500, 100));
        (*Cube1).setPosition(150, 100);
    }

    if ((position.x >= (*Cube2).getPosition().x &&
         position.x <= (*Cube2).getPosition().x + (*Cube2).getSize().x) &&
        (position.y >= (*Cube2).getPosition().y &&
         position.y <= (*Cube2).getPosition().y + (*Cube2).getSize().y)) {
        (*Cube2).setSize(sf::Vector2f(650, 110));
        (*Cube2).setPosition(65, 215);
    } else {
        (*Cube2).setSize(sf::Vector2f(640, 100));
        (*Cube2).setPosition(70, 220);
    }

    if ((position.x >= (*Cube3).getPosition().x &&
         position.x <= (*Cube3).getPosition().x + (*Cube3).getSize().x) &&
        (position.y >= (*Cube3).getPosition().y &&
         position.y <= (*Cube3).getPosition().y + (*Cube3).getSize().y)) {
        (*Cube3).setSize(sf::Vector2f(372, 110));
        (*Cube3).setPosition(221 - 5, 335);
    } else {
        (*Cube3).setSize(sf::Vector2f(362, 100));
        (*Cube3).setPosition(221, 340);
    }
}
// change mode
void change_mode(int* mode) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        *mode = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        *mode = 2;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        *mode = 3;
}
// random moving of figures
void random_move(sf::RectangleShape* Cube, const int SIZE_WINDOW[2]) {
    srand(time(NULL));

    int a = -10, b = 10;

    double vx = (a + rand() % (b * 2 + 1)) / 100.0;
    double vy = (a + rand() % (b * 2 + 1)) / 100.0;
    (*Cube).move(vx, vy);

    if ((*Cube).getPosition().x <= 0)
        (*Cube).move(5, 0);
    else if ((*Cube).getPosition().x + (*Cube).getSize().x >= SIZE_WINDOW[0])
        (*Cube).move(-5, 0);

    if ((*Cube).getPosition().y <= 0)
        (*Cube).move(0, 5);
    else if ((*Cube).getPosition().y + (*Cube).getSize().y >= SIZE_WINDOW[1])
        (*Cube).move(0, -5);
}

void move_45(sf::RectangleShape* Cube, int* direction_cube,
             const int SIZE_WINDOW[2]) {
    if (*direction_cube == 0)
        (*Cube).move(0.1, 0.1);
    else if (*direction_cube == 1)
        (*Cube).move(-0.1, 0.1);
    else if (*direction_cube == 2)
        (*Cube).move(-0.1, -0.1);
    else if (*direction_cube == 3)
        (*Cube).move(0.1, -0.1);

    if ((*Cube).getPosition().x <= 0) {
        if (*direction_cube == 1) {
            *direction_cube = 0;
            (*Cube).setSize(sf::Vector2f((*Cube).getSize().x / 1.5,
                                         (*Cube).getSize().y / 1.5));
        } else if (*direction_cube == 2) {
            *direction_cube = 3;
            (*Cube).setSize(sf::Vector2f((*Cube).getSize().x / 1.5,
                                         (*Cube).getSize().y / 1.5));
        }
    } else if ((*Cube).getPosition().x + (*Cube).getSize().x >=
               SIZE_WINDOW[0]) {
        if (*direction_cube == 0) {
            *direction_cube = 1;
            (*Cube).setSize(sf::Vector2f((*Cube).getSize().x * 1.5,
                                         (*Cube).getSize().y * 1.5));
        } else if (*direction_cube == 3) {
            *direction_cube = 2;
            (*Cube).setSize(sf::Vector2f((*Cube).getSize().x * 1.5,
                                         (*Cube).getSize().y * 1.5));
        }
    }

    if ((*Cube).getPosition().y <= 0) {
        if (*direction_cube == 2) {
            *direction_cube = 1;
            (*Cube).setSize(sf::Vector2f((*Cube).getSize().x * 1.5,
                                         (*Cube).getSize().y * 1.5));
        } else if (*direction_cube == 3) {
            *direction_cube = 0;
            (*Cube).setSize(sf::Vector2f((*Cube).getSize().x * 1.5,
                                         (*Cube).getSize().y * 1.5));
        }
    } else if ((*Cube).getPosition().y + (*Cube).getSize().y >=
               SIZE_WINDOW[1]) {
        if (*direction_cube == 0) {
            *direction_cube = 3;
            (*Cube).setSize(sf::Vector2f((*Cube).getSize().x / 1.5,
                                         (*Cube).getSize().y / 1.5));
        } else if (*direction_cube == 1) {
            *direction_cube = 2;
            (*Cube).setSize(sf::Vector2f((*Cube).getSize().x / 1.5,
                                         (*Cube).getSize().y / 1.5));
        }
    }
}
// keyboard
void move_keyboard(sf::RectangleShape* Cube) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) (*Cube).move(0, -0.25);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) (*Cube).move(0, 0.25);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) (*Cube).move(-0.25, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) (*Cube).move(0.25, 0);
}
