//
// Created by adam on 2021-09-24.
//

#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H

// Tetrimino colors are as follows.
//Cyan I
//Yellow O
//Purple T
//Green S
//Red Z
//Blue J
//Orange L



class Tetromino {

    public:
    void rotate();
    int side;
    // where the tetromino is positioned in the playfield
    int rowOffset;
    int colOffset;






};


#endif //TETRIS_TETROMINO_H
