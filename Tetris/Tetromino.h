#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Mino.hpp"
#include <array>
#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H


// the seven different shapes a tetromino can have
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

// a tetromino is made up of four squares/minos
class Tetromino {

private:
    Shape shape;
    std::array<Mino, 4> minos;
public:
    Tetromino(Shape shape, sf::Vector2i position) : shape(shape)
    {
        createShape(shape, position);
    }
    void createShape(Shape shape, sf::Vector2i position);
    std::array<Mino, 4> getTetromino() {return minos;}
    bool fallDown(const sf::Vector2i &playfield);
    //void rotate();
    void move(const sf::Vector2i &playfield, char direction);
};


#endif //TETRIS_TETROMINO_H
