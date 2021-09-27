
#include "Tetromino.h"


    void Tetromino::createShape(Shape shape)
    {

        switch(shape)
        {
            case I:
            {
                minos[0].setPosition(1, -1);
                minos[1].setPosition(0, -1);
                minos[2].setPosition(-1,-1);
                minos[3].setPosition(-2,-1);
                for(auto mino : minos)
                {
                    mino.setColor(sf::Color::Cyan);
                }
                break;
            }  case O:
            {

                break;
            }  case T:
            {

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
    }




