
#include <iostream>
#include "Game.h"
#include "Grid.h"
#include "Tetromino.h"
#include "Constants.h"
#include "Mino.hpp"



int Game::run() {


    std::vector<std::vector<int>> playfield(COLUMNS, std::vector<int>(ROWS));


    sf::Clock gameClock;

    sf::RenderWindow window(sf::VideoMode(SQUARE_SIZE * COLUMNS, SQUARE_SIZE * ROWS), "TETRIS");
    window.setSize(sf::Vector2u(500, 800));
    auto grid = Grid(window);
    auto tetromino = Tetromino(I);
    sf::Event event{};

    // game loop
    while (window.isOpen()) {

        auto dt = gameClock.restart().asSeconds();

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE - 0.5, SQUARE_SIZE -0.5));

            square.setFillColor(sf::Color::Green);

            window.clear();
            // draw grid
            grid.render(square);
            for(auto mino  : tetromino.getTetromino())
            {
                std::cout << mino.getSquare().getPosition().x << std::endl;
                mino.getSquare().setFillColor(sf::Color::Cyan);
                window.draw(mino.getSquare());
            }


        }

            window.display();
        }


            // movement
            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                // prevent square from going out of screen
                if (squareShape.getPosition().x > 0)
                    squareShape.setPosition(squareShape.getPosition().x - square.xMove, squareShape.getPosition().y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if (squareShape.getPosition().x < WINDOW_WIDTH - SQUARE_SIZE)
                    squareShape.setPosition(squareShape.getPosition().x + square.xMove, squareShape.getPosition().y);
            }

            if (squareShape.getPosition().y < WINDOW_HEIGHT - SQUARE_SIZE) {
                squareShape.setPosition(squareShape.getPosition().x, squareShape.getPosition().y + square.downSpeed);
            }

            // clear before redrawing
            window.clear();

            // very laggy
           // grid.render();
            tetromino.draw(window);
            window.draw(squareShape);*/


        return EXIT_SUCCESS;
    }
