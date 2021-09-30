
#include <iostream>
#include "Tetromino.h"


    void Tetromino::createShape(Shape shape)
    {

        switch(shape)
        {
            case I:
            {
                minos[0] = Mino(-1, -1);
                minos[1] = Mino(0, -1);
                minos[2] = Mino(1,-1);
                minos[3] = Mino(2,-1);
                color = sf::Color::Cyan;
                break;
            }  case O:
            {
                minos[0] = Mino(1, 0);
                minos[1] = Mino(0, 0);
                minos[2] = Mino(1, -1);
                minos[3] = Mino(0, -1);
                color = sf::Color::Yellow;
                break;
            }  case T:
            {
                minos[0] = Mino(-1, 0);
                minos[1] = Mino(0, 0);
                minos[2] = Mino(1,0);
                minos[3] = Mino(0,-1);
                color = sf::Color::Magenta;
                break;
            }  case S:
            {
                minos[0] = Mino(1, -1);
                minos[1] = Mino(0, -1);
                minos[2] = Mino(0,0);
                minos[3] = Mino(-1,0);
                color = sf::Color::Green;
                break;
            }  case Z:
            {
                minos[0] = Mino(-1, -1);
                minos[1] = Mino(0, -1);
                minos[2] = Mino(0,0);
                minos[3] = Mino(1,0);
                color = sf::Color::Red;
                break;
            }  case J:
            {
                minos[0] = Mino(-1, -1);
                minos[1] = Mino(-1, 0);
                minos[2] = Mino(0,0);
                minos[3] = Mino(1,0);
                color = sf::Color::Blue;
                break;
            }  case L:
            {
                minos[0] = Mino(-1, -1);
                minos[1] = Mino(-1, 0);
                minos[2] = Mino(0,0);
                minos[3] = Mino(1,0);
                color = sf::Color(255,150,0); // orange
                break;
            }
            default:
                break;
        }

    }

bool Tetromino::fallDown(const sf::Vector2i  &playfield) {
    for (auto &mino : minos)
    {
        // fall to bottom
        if (mino.y < ROWS -1)
            mino.moveDown();
    }
    return true;
}

void Tetromino::moveLeft(const sf::Vector2i& playfield)
{
     for(auto &mino : minos)
     {             
          
         //check all minos before moving so it doesn't go out of screen
         if(mino.x -1 < 0)         
            return;     
     }    
     for(auto &mino : minos)
     {
                 mino.x--;
     }
            

}

void Tetromino::moveRight(const sf::Vector2i& playfield)
{
     for(auto &mino : minos)
            {
                if(mino.x + 1 >= COLUMNS )
                    return;
               
            }

       for(auto &mino : minos)
     {
                 mino.x++;
     }

}

void Tetromino::moveCenter(const sf::Vector2i& playfield)
{
     for(auto &mino : minos)
            {
               mino.x += COLUMNS/2;               
             }


}






