cmake_minimum_required(VERSION 3.22.1)
project(GOLSerial VERSION 1.0)

set(
    SOURCES
    main.cpp
    src/Cell/Cell.cpp
    src/Rules/Rules.cpp
    src/Neighbors/Neighbors.cpp
    src/GameOfLife/GameOfLife.cpp
)

add_executable(GOLSerial ${SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/includes)

include_directories(usr/local/include/SDL2)
target_link_directories(GOLSerial PRIVATE usr/local/lib)
target_link_libraries(GOLSerial PRIVATE SDL2)
