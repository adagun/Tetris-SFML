#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Mino.hpp"

#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H

enum Shape
{
    I,
    O,
    T,
    S,
    Z,
    J,
    L,
};

class Tetromino {

private:
    Shape shape;
    std::array<Mino, 4> minos;
public:
    Tetromino(Shape shape) : shape(shape)
    {
        createShape(shape);
    }
    void createShape(Shape shape);
    std::array<Mino, 4> getTetromino() {return minos;}


};


#endif //TETRIS_TETROMINO_H
