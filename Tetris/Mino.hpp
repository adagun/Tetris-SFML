
#include "Constants.h"
#ifndef TETRIS_MINO_HPP
#define TETRIS_MINO_HPP

// This class represents one of the four squares that makes up a tetrimino
class Mino {

public:
    int x;
    int y;
    Mino(){}
    Mino(int x, int y) : x(x), y(y) {}
    sf::Vector2i getPosition() const
    {
        return sf::Vector2i(x,y);
    } 
    // moves the mino down a cell in the grid
    void moveDown()
    {
        y++;
    }

};


#endif //TETRIS_MINO_HPP
