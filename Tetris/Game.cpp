#include <iostream>
#include "Game.h"
#include "Grid.h"
#include "Tetromino.h"
#include "Constants.h"
#include "Mino.hpp"
#include <random>

// TODO collision check in the rotation function
// TODO hard drop
// TODO score system
// TODO Game over screen
int Game::run() {
    // Matrix is an alias for std::vector<std::vector<bool>>
    // 2d vector of bool
    // dropped pieces position are set as true
    // the minos checks if the neighbouring squares
    //are occupied or not in the move and fall functions
    Matrix playfield(ROWS, std::vector<bool>(COLUMNS));
    std::vector <int> rowsToRemove;
    sf::RenderWindow window(sf::VideoMode(SQUARE_SIZE * COLUMNS, SQUARE_SIZE * ROWS), "TETRIS");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    auto grid = Grid(window);
    // the tetromino that is currently falling
    auto currentTetromino = Tetromino(getRandomShape());
    currentTetromino.moveCenter();
    currentTetromino.setFall(true);
    // stores the previous dropped tetrominos
    std::vector<Tetromino> tetrominos;
    sf::Event event{};

    // time for the tetromino to fall one square
    int gameSpeed = 500;
    sf::Time dt = sf::milliseconds(gameSpeed);

    // game loop
    while (window.isOpen())
    {

        elapsedTime += clock.restart();
        while( elapsedTime >= dt ){
            currentTetromino.fallDown(playfield);               
            elapsedTime -= dt;
        }
        if(gameOver)
        {
            std::cout << "Game over" << std::endl;
            // make some kind of game over screen
            return EXIT_SUCCESS;


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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                currentTetromino.rotate(playfield);
            }
        }

            sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE - 1, SQUARE_SIZE -1));

            window.clear();
           
            // draw grid//
            grid.render(square);
               
            //draw the previous minos
           for(auto &tetromino : tetrominos)
           {
                for(auto &mino : tetromino.getTetromino())
                 {
                    if (!playfield[mino.y][mino.x])
                    {
                        square.setFillColor(sf::Color::Transparent);
                        square.setPosition(static_cast<float>(mino.x * SQUARE_SIZE), static_cast<float>(mino.y * SQUARE_SIZE));
                        window.draw(square);

                    } else
                    {
                        square.setFillColor(tetromino.getColor());
                        square.setPosition(static_cast<float>(mino.x * SQUARE_SIZE), static_cast<float>(mino.y * SQUARE_SIZE));
                        window.draw(square);
                    }
                 }
            }
   
            // draw the current tetromino
             for(auto mino : currentTetromino.getTetromino())
                 {
                    square.setFillColor(currentTetromino.getColor());
                    square.setPosition(static_cast<float>(mino.x * SQUARE_SIZE), static_cast<float>(mino.y * SQUARE_SIZE));
                    window.draw(square);
                 }
                
             // check if it hit something
             if(!currentTetromino.isFalling())
            {
                 // add it to the vector
                 tetrominos.emplace_back(currentTetromino);
                  // add minos position to the playfield matrix
                 update(currentTetromino, playfield);
                 rowsToRemove = checkRows(playfield);

                // set the full rows to false
                removeRows(playfield, rowsToRemove);


                // display the playfield in the console
                   for(int i = 0; i < ROWS; i++)
                   {
                       for(int j = 0; j < COLUMNS; j++)
                       {
                           std::cout << playfield[i][j] << " ";
                       }
                      std::cout << std::endl;
                    }


                // spawn a new one and make i the current
                auto tetromino = Tetromino(getRandomShape());
                tetromino.moveCenter();                
                currentTetromino = tetromino;   

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

// returns a random shape to be spawned
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
       // if the dropped tetromino is placed above the playfield it's game over
       if(mino.y <= 0)
       {
           gameOver = true;
           return;
       }
        
    }
    for(auto &mino : tetromino.getTetromino())
    {        
       playfield[mino.y][mino.x] = true;
    }

}


// finding and returning a vector of all rows that are full
std::vector<int> Game::checkRows(Matrix &playfield)
{

    bool fullRow;
    std::vector<int> rowsToRemove;
    for(int i = 0; i < ROWS; i++)
    {
        fullRow = true;
        for(int j = 0; j < COLUMNS; j++)
        {
            if(!playfield[i][j])
            {
                fullRow = false;
            }
        }
        if(fullRow)
        {
            rowsToRemove.emplace_back(i);
        }
    }
    return rowsToRemove;

}

void Game::removeRows(Matrix &playfield, std::vector<int> rowsToRemove)
{
    for(auto row : rowsToRemove)
    {
        for(int i = 0; i < COLUMNS; i++)
        {
            playfield[row][i] = false;
        }
    }
            // remove the full rows and create a new one at the top
            // the rows above are moved down a step
            for(auto row : rowsToRemove)
            {
                playfield.insert(playfield.begin(),std::vector<bool>(COLUMNS));
                playfield.erase(playfield.begin()+row+1);
            }


    }







