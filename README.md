# GOLSerial
This is a serial version of Johm Conway's Game Of Life built in c++ 


## Complie
g++ main.cpp src/Neighbors/Neighbors.cpp src/Rules/Rules.cpp src/Cell/Cell.cpp src/GameOfLife/GameOfLive.cpp -Iincludes/

## Run 
./a.out <rowSize> <columnSize>

### Example
./a.out 15 15

## Future For Project 
Add cmake for easier compliation\
Add the SDL library for the visualization 