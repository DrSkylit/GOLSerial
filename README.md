# GOLSerial
This is a serial version of John Conway's Game Of Life built in c++ and visualized using the SDL library

## Complie g++ or cmake
### g++
g++ -o GOLSerial main.cpp src/Neighbors/Neighbors.cpp src/Rules/Rules.cpp src/Cell/Cell.cpp src/TextLoader/TextLoader.cpp src/GameOfLife/GameOfLife.cpp -Iincludes/ -lSDL2 -lSDL2_ttf

### cmake
```
cd GOLSerial
mkdir build
cmake ..
make
```
### Libraries

* SDL (https://github.com/libsdl-org/SDL)
* SDL_ttf (https://github.com/libsdl-org/SDL_ttf)

Make sure SDL and SDL_ttf is installed and you are pointed to the correct versions in the CMakeLists.txt file

./GOLSerial <rowSize> <columnSize>

### Example
./GOLSerial 15 15

## Future For Project 
- [x] Add cmake for easier compliation\
- [x]Add the SDL library for the visualization 
