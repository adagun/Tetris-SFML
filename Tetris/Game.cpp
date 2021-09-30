
#include <iostream>
#include "Game.h"
#include "Grid.h"
#include "Tetromino.h"
#include "Constants.h"
#include "Mino.hpp"
#include <random>

// TODO spawn new tetrominos
// TODO check and remove full rows
// TODO implement rotate function
// TODO implement collision with tetrominos at the bottom
// TODO drop down function
// TODO game crashes if mouse hover the first column

int Game::run() {


    sf::Vector2i playfield(COLUMNS, ROWS);

    sf::RenderWindow window(sf::VideoMode(SQUARE_SIZE * COLUMNS, SQUARE_SIZE * ROWS), "TETRIS");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    auto grid = Grid(window);
    auto tetromino = Tetromino(getRandomShape());
    tetromino.moveCenter(playfield);

    sf::Event event{};
    // time for the tetromino to fall one square
    int gameSpeed = 500;
    sf::Time dt = sf::milliseconds(gameSpeed);

    // game loop
    while (window.isOpen())
    {
        elapsedTime += clock.restart();
        while( elapsedTime >= dt ){
            tetromino.fallDown(playfield);
            elapsedTime -= dt;
        }

        updateDeltaTime();
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                break;
            }

            // movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {      
                tetromino.moveLeft(playfield);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            {
                tetromino.moveRight(playfield);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                tetromino.moveDown(playfield);
            }

        }

            sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE - 1, SQUARE_SIZE -1));

            window.clear();
            // draw grid//
            grid.render(square);

            for(auto mino  : tetromino.getTetromino())
            {
                square.setFillColor(tetromino.getColor());
                square.setPosition(static_cast<float>(mino.x * SQUARE_SIZE), static_cast<float>(mino.y * SQUARE_SIZE));
                window.draw(square);
            }

            window.display();
        }

        return EXIT_SUCCESS;
    }

    // updating the delta time for rendering one frame
void Game::updateDeltaTime()
{
    this->deltaTime = this->clock.restart().asSeconds();
}

Shape Game::getRandomShape()
{
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(1,7);
    int shapeNr = distribution(generator);
    Shape shape;
    switch(shapeNr)
    {
        case 1:
        {
            return Shape::I;
        }
        case 2:
        {
            return Shape::J;
        }
        case 3:
        {
            return Shape::L;
        }
        case 4:
        {
            return Shape::O;
        }
        case 5:
        {
            return Shape::S;
        }
        case 6:
        {
            return Shape::T;
        }
        case 7:
        {
            return Shape::Z;
        }
    }
    return shape;
}