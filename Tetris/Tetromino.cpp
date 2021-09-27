
#include <iostream>
#include "Tetromino.h"


    void Tetromino::createShape(Shape shape, sf::Vector2i position)
    {

        switch(shape)
        {
            case I:
            {

                minos[0] = Mino(1, -1);
                minos[1] = Mino(0, -1);
                minos[2] = Mino(-1,-1);
                minos[3] = Mino(-2,-1);
                break;
            }  case O:
            {
                minos[0] = Mino(1, -1);
                minos[1] = Mino(0, -1);
                minos[2] = Mino(-1,-1);
                minos[3] = Mino(-2,-1);

                break;
            }  case T:
            {
                minos[0] = Mino(-1, 0);
                minos[1] = Mino(0, 0);
                minos[2] = Mino(1,0);
                minos[3] = Mino(0,-1);

                break;
            }  case S:
            {

                break;
            }  case Z:
            {

                break;
            }  case J:
            {

                break;
            }  case L:
            {

                break;
            }
            default:
                break;
        }
        for(auto mino : minos)
        {
           mino.x += position.x;
           mino.y += position.y;
        }
    }

bool Tetromino::fallDown(const sf::Vector2i  &playfield) {
    for (auto &mino : minos)
    {
        if (mino.y < ROWS -1)
            mino.moveDown();
    }
    return true;
}



void Tetromino::move(const sf::Vector2i &playfield, char direction)
{
    switch (direction)
    {
        case'L':
        {
            for(auto &mino : minos)
            {
                // stop it from going outside of the screen
                if(mino.x -1 < 0)
                    return;

                mino.x--;
            }
            break;
        }
        case'R':
        {
            for(auto &mino : minos)
            {
                if(mino.x + 1 >= COLUMNS )
                    return;
                mino.x++;
            }
            break;
        }
    }

}




