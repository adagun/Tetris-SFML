#include <iostream>
#include "Tetromino.h"


    void Tetromino::createShape(Shape shape)
    {
        switch(shape)
        {
            case I:
            {
                minos[0] = Mino(0, 0);
                minos[1] = Mino(1, 0);
                minos[2] = Mino(2, 0);
                minos[3] = Mino(3, 0);
                color = sf::Color::Cyan;
                break;
            }  case O:
            {
                minos[0] = Mino(2, 1);
                minos[1] = Mino(1, 1);
                minos[2] = Mino(2, 0);
                minos[3] = Mino(1, 0);
                color = sf::Color::Yellow;
                break;
            }  case T:
            {
                minos[0] = Mino(0, 1);
                minos[1] = Mino(1, 1);
                minos[2] = Mino(2,1);
                minos[3] = Mino(1, 0);
                color = sf::Color::Magenta;
                break;
            }  case S:
            {
                minos[0] = Mino(2, 0);
                minos[1] = Mino(1, 0);
                minos[2] = Mino(1,1);
                minos[3] = Mino(0,1);
                color = sf::Color::Green;
                break;
            }  case Z:
            {
                minos[0] = Mino(0, 0);
                minos[1] = Mino(1, 0);
                minos[2] = Mino(1,1);
                minos[3] = Mino(2,1);
                color = sf::Color::Red;
                break;
            }  case J:
            {
                minos[0] = Mino(0, 0);
                minos[1] = Mino(0, 1);
                minos[2] = Mino(1,1);
                minos[3] = Mino(2,1);
                color = sf::Color::Blue;
                break;
            }  case L:
            {
                minos[0] = Mino(0, 1);
                minos[1] = Mino(1, 1);
                minos[2] = Mino(2,1);
                minos[3] = Mino(2,0);
                color = sf::Color(255,150,0); // orange
                break;
            }
            default:
                break;
        }

    }

bool Tetromino::fallDown(const Matrix  &playfield) {

 
    for(auto &mino : minos)
    {
        // if any mino hits the floor it should make the whole tetromino stop
        if (mino.y > ROWS -2)
        {
            falling = false;
            return false;
        }
    }


         for(auto &mino : minos)
    {             // check if there is a occupied square below this minos position
            if(playfield[mino.y+1][mino.x])
            {              
                falling = false;
                return false;
            }
    }


    for (auto &mino : minos)
    {
        // fall to bottom
        if (mino.y < ROWS -1)
            mino.moveDown();
        else
            {
            falling = false;
            return false;
            }
    }
    return true;
}

void Tetromino::rotate(const Matrix& playfield)
{
    // TODO make sure it doesn't go into another tetrominno


    if(shape == Shape::O)
    {
        return;
    }

    else if(shape == Shape::I)
    {       
        // dont rotate it above the playfield matrix
        if(minos[0].y < 2)
            return;

        if(rotation == 0 || rotation == 2)
        {
             for(auto i = 0; i < 4; i++)
            {
               minos[i].x = minos[0].x;
               minos[i].y = minos[0].y-i;
            }
        }
        else if(rotation == 1)
        {
             for(auto i = 0; i < 4; i++)
            {
               minos[i].x = minos[0].x-i;
               minos[i].y = minos[0].y;
            }
            // move if out of bounds
             while(minos[3].x < 0)
             {
                   minos[0].x++;
                   minos[1].x++;
                   minos[2].x++;
                   minos[3].x++;
             }
        }
        else if(rotation == 3)
        {
            for(auto i = 0; i < 4; i++)
            {
                minos[i].x = minos[0].x+i;
                minos[i].y = minos[0].y;
            }
               // move if out of bounds
             while(minos[3].x > COLUMNS)
             {
                   minos[0].x--;
                   minos[1].x--;
                   minos[2].x--;
                   minos[3].x--;
             }
        }

        

       
       
    }

    else if(shape == Shape::T)
    {
        if(rotation == 0)
        {
            minos[0].y--;
            minos[1].x--;
            minos[2].x-=2;
            minos[2].y++;
            minos[3].y++;

        }
        else if(rotation == 1)
        {
            minos[0].x+=2;
            minos[1].x++;
            minos[1].y--;
            minos[2].y-=2;

        }
        if(rotation == 2)
        {
            minos[0].y+=2;
            minos[1].x++;
            minos[1].y++;
            minos[2].x+=2;

        }
        else if(rotation == 3)
        {
            minos[0].x-=2;
            minos[1].x--;
            minos[1].y++;
            minos[2].y+=2;
        }
    }
   else if(shape == Shape::S) {
        // S shape has two states
        if (rotation == 0 || rotation == 2) {

            minos[0].y += 2;
            minos[1].x++;
            minos[1].y++;
            minos[3].x++;
            minos[3].y--;

        }
            // reverse
        else if (rotation == 1 || rotation == 3) {
            minos[0].y -= 2;
            minos[1].x--;
            minos[1].y--;
            minos[3].x--;
            minos[3].y++;
        }
    }

   else if(shape == Shape::Z)
    {
        if(rotation == 0 || rotation == 2)
        {

            minos[0].x+=2;
            minos[1].x++;
            minos[1].y++;
            minos[3].x--;
            minos[3].y++;

        }
            // reverse
        else if(rotation == 1 || rotation == 3)
        {
            minos[0].x-= 2;
            minos[1].x--;
            minos[1].y--;
            minos[3].x++;
            minos[3].y--;
        }
    }
   else if(shape == Shape::J)
    {
        if(rotation == 0)
        {
            minos[0].x++;
            minos[1].y--;
            minos[2].x--;
            minos[3].x-=2;
            minos[3].y++;

        }
        else if(rotation == 1)
        {
            minos[0].y++;
            minos[1].x++;
            minos[2].y--;
            minos[3].x--;
            minos[3].y-=2;

        }
        if(rotation == 2)
        {
            minos[0].x--;
            minos[0].y++;
            minos[1].y+=2;
            minos[2].x++;
            minos[2].y++;
            minos[3].x+=2;

        }
        else if(rotation == 3)
        {
            minos[0].y--;
            minos[1].x--;
            minos[2].y++;
            minos[3].x++;
            minos[3].y+=2;

        }
    }

   else if(shape == Shape::L)
    {
        if(rotation == 0)
        {
            minos[0].y--;
            minos[1].x--;
            minos[2].x-=2;
            minos[2].y++;
            minos[3].x--;
            minos[3].y+=2;

        }
        else if(rotation == 1)
        {
            minos[0].x+=2;
            minos[1].x++;
            minos[1].y--;
            minos[2].y-=2;
            minos[3].x--;
            minos[3].y--;


        }
        if(rotation == 2)
        {
            minos[0].y+=2;
            minos[1].x++;
            minos[1].y++;
            minos[2].x+=2;
            minos[3].x++;
            minos[3].y--;

            // fix minos moving right when rotating here
            for(auto &mino: minos)
            {
                mino.x--;
            }
        }
        else if(rotation == 3)
        {
            minos[0].x--;
            minos[0].y--;
            minos[2].x++;
            minos[2].y++;
            minos[3].x+=2;

        }
    }

    // fixing rotations going out of bounds
    bool outOfBoundsLeft = false;
    bool outOfBoundsRight = false;
    for(auto &mino : minos)
    {
        if (mino.x < 0)
        {
            outOfBoundsLeft = true;
        }
        else if(mino.x >= COLUMNS)
        {
            outOfBoundsRight = true;
        }
    }

    if(outOfBoundsLeft)
    {
        minos[0].x++;
        minos[1].x++;
        minos[2].x++;
        minos[3].x++;
    }
    if(outOfBoundsRight)
    {
         minos[0].x--;
         minos[1].x--;
         minos[2].x--;
         minos[3].x--;
    }







     rotation++;
     if(rotation > 3)
         rotation = 0;
}

void Tetromino::moveLeft(const Matrix& playfield)
{
     for(auto &mino : minos)
     {
        //check all minos before moving so it doesn't go out of screen
         if(mino.x -1 < 0)         
            return;     
     }    


    for(auto &mino : minos)
    {  // check if there is a occupied square to the left
        if(playfield[mino.y][mino.x-1])
        {
            return;
        }
    }

     for(auto &mino : minos)
     {
           mino.x--;
     }
}

void Tetromino::moveRight(const Matrix& playfield)
{
     for(auto &mino : minos)
        {
            if(mino.x + 1 >= COLUMNS )
                return;
        }

    for(auto &mino : minos)
    {        // check if there is a occupied square to the right
        if(playfield[mino.y][mino.x+1])
        {
            return;
        }
    }

       for(auto &mino : minos)
       {
           mino.x++;
       }

}
// to move the new spawning tetromino
void Tetromino::moveCenter()
{
     for(auto &mino : minos)
        {
           mino.x += COLUMNS/2;
        }
}

void Tetromino::moveDown(const Matrix &playfield)
{
    fallDown(playfield);
}






