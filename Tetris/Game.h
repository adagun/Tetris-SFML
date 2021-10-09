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
    {
        score = 0;
        level = 1;
        gameSpeed = START_GAME_SPEED;
        dt = sf::milliseconds(gameSpeed);

    }
    int run();


private:
    bool gameOver = false;
    sf::Clock clock;
    float deltaTime;
    sf::Time elapsedTime;
    int score;
    int level;
    int gameSpeed;
    sf::Time dt;
    void updateDeltaTime();
    Shape getRandomShape();
    void update(Tetromino tetromino,  Matrix &playfield);
    std::vector<int>  checkRows(Matrix &playfield);
    void removeRows(Matrix &playfield, std::vector<int> rowsToRemove);
    void resetPlayfield(Matrix &playfield);
};
#endif //TETRIS_GAME_H
