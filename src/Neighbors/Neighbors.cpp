#include <stdlib.h>
#include <iostream>

#include <Neighbors.hpp>

Neighbors::Neighbors() {
    this->setNeighbors();
}

Neighbors::~Neighbors(){
    
}

int Neighbors::getAliveNeighbors(){
    return 0;
}

void Neighbors::setNeighbors(){
    // Top Left
    this->directions[0].i = -1;
    this->directions[0].j = -1;
    // Top
    this->directions[1].i = -1;
    this->directions[1].j = 0;
    // Top Right
    this->directions[2].i = -1;
    this->directions[2].j = 1;
    // Left
    this->directions[3].i = 0;
    this->directions[3].j = -1;
    // Right
    this->directions[4].i = 0;
    this->directions[4].j = 1;
    // Botom Left
    this->directions[5].i = 1;
    this->directions[5].j = -1;
    // Bottom
    this->directions[6].i = 1;
    this->directions[6].j = 0;
    // Bottom Right
    this->directions[7].i = 1;
    this->directions[7].j = 1;

}