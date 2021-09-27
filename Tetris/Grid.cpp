//
// Created by adam on 2021-09-24.
//

#include "Grid.h"


void Grid::render()
{
   for(const auto& square : grid)
   {
       window.draw(square);
   }
}

void Grid::createGrid() {

    for (int col = 0; col < gridWidth; col++)
    {
        for(int row = 0; row < gridHeight; row++)
        {
            auto square = sf::RectangleShape(sf::Vector2f(squareSize, squareSize));
            square.setSize(sf::Vector2f(squareSize, squareSize));
            square.setOutlineColor(sf::Color::White);
            square.setFillColor(sf::Color::Black);
            square.setOutlineThickness(1.0f);
            square.setPosition(squareSize*static_cast<float>(col), squareSize*static_cast<float>(row));
            grid.push_back(square);
        }

    }


}
