
#include <iostream>
#include "Game.h"
const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 900;
const int SQUARE_SIZE = 50;


class Square{
public:

    float xPos;
    float yPos;
    float downSpeed;
    float xMove = 1.0f;
    Square(float downSpeed, float xMove) : downSpeed(downSpeed), xMove(xMove)
    {
        xPos = 0.f;
        yPos = 0.f;
    }

};



int Game::run() {

    auto square = Square(1.0f, 5.0f);

    // main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TETRIS");

    sf::RectangleShape squareShape(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
    window.setFramerateLimit(60);


    // game loop
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape )

                window.close();
        }

        // delta time
        //sf::Clock gameClock;
        //float dt = gameClock.restart().asSeconds();

        // movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // prevent square from going out of screen
            if(squareShape.getPosition().x > 0)
                squareShape.setPosition(squareShape.getPosition().x - square.xMove, squareShape.getPosition().y);
        }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if(squareShape.getPosition().x < WINDOW_WIDTH - SQUARE_SIZE )
                    squareShape.setPosition(squareShape.getPosition().x + square.xMove, squareShape.getPosition().y);
            }

        if(squareShape.getPosition().y < WINDOW_HEIGHT - SQUARE_SIZE )
        {
            squareShape.setPosition(squareShape.getPosition().x, squareShape.getPosition().y + square.downSpeed);
        }

            // clear before redrawing
            window.clear();

            window.draw(squareShape);

            window.display();

        }
        return EXIT_SUCCESS;
    }

