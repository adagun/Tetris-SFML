
#include "Constants.h"
#ifndef TETRIS_MINO_HPP
#define TETRIS_MINO_HPP


class Mino {
private:
    sf::Vector2f position;
    sf::RectangleShape square;
public:
    Mino()
    {
        square.setSize(sf::Vector2f(SQUARE_SIZE -0.5 , SQUARE_SIZE- 0.5));
    }
    sf::Vector2f getPosition() {return position;} const
    void setPosition(float x, float y)
    {
        position = sf::Vector2f(x*SQUARE_SIZE, y*SQUARE_SIZE);
    }
    sf::RectangleShape getSquare(){return square;}
    void setColor(sf::Color color)
    {
        square.setFillColor(color);
    }
};


#endif //TETRIS_MINO_HPP
