# GOLSerial
This is a serial version of Johm Conway's Game Of Life built in c++ 


## Complie g++ or cmake
### g++
g++ -o GOLSerial main.cpp src/Neighbors/Neighbors.cpp src/Rules/Rules.cpp src/Cell/Cell.cpp src/GameOfLife/GameOfLife.cpp -Iincludes/

### cmake
```
cd GOLSerial
mkdir build
cmake ..
make
```
make sure cmake is installed and the correct version is being pointed to in the CMakeLists.txt file
## Run 
./GOLSerial <rowSize> <columnSize>

### Example
./GOLSerial 15 15

## Future For Project 
- [x] Add cmake for easier compliation\
Add the SDL library for the visualization 
