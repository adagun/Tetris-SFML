#include "Grid.h"


void Grid::render(sf::RectangleShape square)
{
    for (auto i = 0; i <= COLUMNS; i++)
    {
        for (auto j = 0; j <= ROWS; j++)
        {
            if(j == ROWS|| i == COLUMNS || i == 0 || j == 0)
                square.setFillColor(sf::Color(200,200,200));
            else
                square.setFillColor(sf::Color::Transparent);
            square.setOutlineColor(sf::Color::White);
            square.setOutlineThickness(0.85f);
            square.setPosition(static_cast<float>(SQUARE_SIZE * i), static_cast<float>(SQUARE_SIZE * j));
            window.draw(square);
        }
    }

}
