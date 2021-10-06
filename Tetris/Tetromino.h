#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Mino.hpp"
#include <array>
#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H

using Matrix =  std::vector<std::vector<bool>>;

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
    bool falling = true;
    int rotation = 0;
public:
    Tetromino(Shape shape) : shape(shape)
    {
        createShape(shape);
    }
    void createShape(Shape shape);
    std::array<Mino, 4> getTetromino() const {return minos;}
    bool fallDown(const Matrix &playfield);
    void rotate(const Matrix& playfield);
    void moveLeft(const Matrix &playfield);
    void moveRight(const Matrix &playfield);
    void moveDown(const Matrix &playfield);
    void moveCenter();
    void dropDown(const Matrix &playfield);
    sf::Color getColor() const {return color;}
    bool isFalling() const {return falling;}
    void setFall(bool falling) {this->falling = falling;};
};


#endif //TETRIS_TETROMINO_H
