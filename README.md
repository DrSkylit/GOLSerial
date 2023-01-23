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

The Max Row size is 90

The Max Column size is 125

If no Row or Column is selected a default of 15 by 15 will be selected

### Example
./GOLSerial 15 15

### Video Examples
[Screencast from 01-22-2023 06:06:13 PM.webm](https://user-images.githubusercontent.com/29786223/213950922-74ff39d7-dcbf-4307-92c1-27aa3f86774e.webm)

[Screencast from 01-22-2023 06:07:12 PM.webm](https://user-images.githubusercontent.com/29786223/213950938-453813fe-3225-40a5-b5b6-9c1f4ecb56d4.webm)

## Future For Project 
- [x] Add cmake for easier compliation\
- [x]Add the SDL library for the visualization 
