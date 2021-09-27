//
// Created by adam on 2021-09-24.
//

#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

// The playfield is the grid into which tetrominoes fall
class Grid {

private:
    sf::RenderWindow &window;
    int gridWidth;
    int gridHeight;
    float squareSize = 50.0f;
    std::vector<sf::RectangleShape> grid;

public:
    Grid(sf::RenderWindow &window, int width, int height) : window(window), gridWidth(width), gridHeight(height)
    {
        createGrid();
    }
    void render();
    void createGrid();




};


#endif //TETRIS_GRID_H
