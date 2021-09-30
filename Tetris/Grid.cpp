#include "Grid.h"


void Grid::render(sf::RectangleShape square)
{
    for (auto i = 0; i < COLUMNS; i++)
    {
        for (auto j = 1; j <= ROWS; j++)
        {
            square.setFillColor(sf::Color::Transparent);
            square.setOutlineColor(sf::Color::White);
            square.setOutlineThickness(0.85f);
            square.setPosition(static_cast<float>(SQUARE_SIZE * i), static_cast<float>(SQUARE_SIZE * j));
            window.draw(square);
        }
    }

}
