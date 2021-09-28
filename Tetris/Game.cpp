
#include <iostream>
#include "Game.h"
#include "Grid.h"
#include "Tetromino.h"
#include "Constants.h"
#include "Mino.hpp"


// TODO spawn new tetrominos
// TODO fix and finish create all shapes correctly in the Tetromino createShape function
// TODO check and remove full rows
// TODO implement rotate function
// TODO implement collision with tetrominos at the bottom

int Game::run() {


    sf::Vector2i playfield(COLUMNS, ROWS);

    sf::RenderWindow window(sf::VideoMode(SQUARE_SIZE * COLUMNS, SQUARE_SIZE * ROWS), "TETRIS");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    auto grid = Grid(window);
    auto tetromino = Tetromino(O,   sf::Vector2i(COLUMNS/2, ROWS));


    sf::Event event{};
    int gameSpeed = 1000;
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

        }

            sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE - 1, SQUARE_SIZE -1));
            square.setFillColor(sf::Color::Green);

            window.clear();
            // draw grid//
            grid.render(square);

            for(auto mino  : tetromino.getTetromino())
            {
                square.setFillColor(sf::Color::Cyan);
                square.setPosition(static_cast<float>(mino.x * SQUARE_SIZE), static_cast<float>(mino.y * SQUARE_SIZE));

                window.draw(square);
                std::cout << square.getPosition().y << std::endl;
                std::cout << square.getPosition().x << std::endl;
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
