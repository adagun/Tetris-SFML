

#include "Grid.h"


void Grid::render(sf::RectangleShape square)
{
    for (auto i = 0; i < COLUMNS; i++)
    {
        for (auto j = 0; j < ROWS; j++)
        {
            square.setPosition(static_cast<float>(SQUARE_SIZE * i), static_cast<float>(SQUARE_SIZE * j));
            window.draw(square);
        }
    }
}




