#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Constants.h"
#include <vector>
#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H



class Game {
public:
    Game() = default;
    int run();
    void updateDeltaTime();


private:
    sf::Clock clock;
    float deltaTime;
    sf::Time elapsedTime;
};


#endif //TETRIS_GAME_H
