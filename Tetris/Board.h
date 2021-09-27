//
// Created by adam on 2021-09-27.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H


class Board {

public:

    int width = 10;
    // two invisible spaces above the play field for the new spawning tetromino
    int height = 22;
    int visibleHeight = 20;
    int playField = [width * height];

};


#endif //TETRIS_BOARD_H
