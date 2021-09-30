# script for building on linux
g++ -o Tetris_linux -I . ./*.cpp -lsfml-graphics -lsfml-window -lsfml-system
./Tetris_linux