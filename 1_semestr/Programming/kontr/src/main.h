#ifndef MAIN
#define MAIN

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//определение функций 
void choose_mode(int* mode, sf::Vector2i position, sf::RectangleShape Cube1, sf::RectangleShape Cube2, sf::RectangleShape Cube3);
void animation_buttons(sf::Vector2i position, sf::RectangleShape* Cube1, sf::RectangleShape* Cube2, sf::RectangleShape* Cube3);
void change_mode(int* mode);

void random_move(sf::RectangleShape* Cube, const int SIZE_WINDOW[2]);
void move_45(sf::RectangleShape* Cube, int* direction_cube, const int SIZE_WINDOW[2]);
void move_keyboard(sf::RectangleShape* Cube);

#endif