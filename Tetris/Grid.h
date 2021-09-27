#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Constants.h"


#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H

class Grid {

private:
    sf::RenderWindow &window;

public:
    Grid(sf::RenderWindow &window) : window(window)  { }
    void render(sf::RectangleShape square);



};


#endif //TETRIS_GRID_H
