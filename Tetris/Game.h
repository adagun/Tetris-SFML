#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Constants.h"
#include <vector>
#include "Tetromino.h"
#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H



class Game {
public:
    Game()
    { }
    int run();
    void updateDeltaTime();
    Shape getRandomShape();
    void update(Tetromino tetromino,  Matrix &playfield);
    std::vector<int>  checkRows(Matrix &playfield);


private:
    bool gameOver = false;
    sf::Clock clock;
    float deltaTime;
    sf::Time elapsedTime;
  

};
#endif //TETRIS_GAME_H
