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
    sf::Color color;
public:
    Tetromino(Shape shape) : shape(shape)
    {
        createShape(shape);
    }
    void createShape(Shape shape);
    std::array<Mino, 4> getTetromino() const {return minos;}
    bool fallDown(const sf::Vector2i &playfield);
    //void rotate();
    void moveLeft(const sf::Vector2i &playfield);
    void moveRight(const sf::Vector2i &playfield);
    void moveDown(const sf::Vector2i &playfield);
    void moveCenter(const sf::Vector2i &playfield);
    void dropDown(const sf::Vector2i &playfield);
    sf::Color getColor() const {return color;}

};


#endif //TETRIS_TETROMINO_H
