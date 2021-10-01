
#include <iostream>
#include "Game.h"
#include "Grid.h"
#include "Tetromino.h"
#include "Constants.h"
#include "Mino.hpp"
#include <random>

// TODO check and remove full rows
// TODO implement rotate function
// TODO implement collision with tetrominos at the bottom and sides
// TODO drop down function
// TODO keep and redraw dropped pieces


int Game::run() {
    // Matrix is an alias for std::vector<std::vector<bool>>
    // 2d vector of bool
    // dropped pieces poisition are set as true
    // the minos needs to check if the neighbouring squares
    //are occupied or no in the move and fall functions
   
    Matrix playfield(COLUMNS, std::vector<bool>(ROWS));

    sf::RenderWindow window(sf::VideoMode(SQUARE_SIZE * COLUMNS, SQUARE_SIZE * ROWS), "TETRIS");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    auto grid = Grid(window);
    auto currentTetromino = Tetromino(getRandomShape());
    currentTetromino.moveCenter();
    currentTetromino.setFall(true);
    std::vector<Tetromino> tetrominos;
    sf::Event event{};
    // time for the tetromino to fall one square
    int gameSpeed = 200;
    sf::Time dt = sf::milliseconds(gameSpeed);

    // game loop
    while (window.isOpen())
    {
        elapsedTime += clock.restart();
        while( elapsedTime >= dt ){
            currentTetromino.fallDown(playfield);
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
                currentTetromino.moveLeft(playfield);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            {
                currentTetromino.moveRight(playfield);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                currentTetromino.moveDown(playfield);
            }

        }

            sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE - 1, SQUARE_SIZE -1));

            window.clear();
           
            // draw grid//
            grid.render(square);
               
            //draw the previous minos
           for(auto tetromino : tetrominos)
           {
                for(auto &mino : tetromino.getTetromino())
                 {                    
                    square.setFillColor(tetromino.getColor());
                    square.setPosition(static_cast<float>(mino.x * SQUARE_SIZE), static_cast<float>(mino.y * SQUARE_SIZE));
                    window.draw(square);
                 }
            }
   


             if(!currentTetromino.isFalling())
            {
                 // add minos position to the playfield matrix
                update(currentTetromino, playfield);
                auto tetromino = Tetromino(getRandomShape());
                tetromino.moveCenter();
                tetrominos.emplace_back(tetromino);
                currentTetromino = tetromino;             
             }
              for(auto mino : currentTetromino.getTetromino())
                 {
                    square.setFillColor(currentTetromino.getColor());
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
    return Shape::O;
}


// sets all square as occupied by a dropped piece
void Game::update(Tetromino tetromino, Matrix &playfield)
{
  
    for(auto &mino : tetromino.getTetromino())
    {
       playfield.at(mino.x).at(mino.y) = true;
    }
  
   
}



