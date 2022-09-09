#include <stdlib.h>
#include <iostream>

#include <Neighbors.hpp>

Neighbors::Neighbors() {
    this->setNeighbors();
}

Neighbors::~Neighbors(){
    
}

int Neighbors::getAliveNeighbors(int** board, Cell cell, int rowSize, int columnSize){
    int neighbors = 0;
    // We use 8 because each cell has 8 neighbors
    for(int i = 0; i < 8; i++){
        int rowDirection = this->directions[i].row;
        int columnDirection = this->directions[i].column;

        int row = rowDirection + cell.getRow();
        if(row < 0){
            row = rowSize-1;
        }
        if(row >= rowSize){
            row = 0;
        }

        int column = columnDirection + cell.getColumn();
        if(column < 0){
            column = columnSize-1;
        }
        if(column >= columnSize){
            column = 0;
        }

        if(board[row][column] == 1){
            neighbors++;
        } 
    }
    return neighbors;   
}

void Neighbors::setNeighbors(){
    // Top Left
    this->directions[0].row = -1;
    this->directions[0].column = -1;
    // Top
    this->directions[1].row = -1;
    this->directions[1].column = 0;
    // Top Right
    this->directions[2].row = -1;
    this->directions[2].column = 1;
    // Left
    this->directions[3].row = 0;
    this->directions[3].column = -1;
    // Right
    this->directions[4].row = 0;
    this->directions[4].column = 1;
    // Botom Left
    this->directions[5].row = 1;
    this->directions[5].column = -1;
    // Bottom
    this->directions[6].row = 1;
    this->directions[6].column = 0;
    // Bottom Right
    this->directions[7].row = 1;
    this->directions[7].column = 1;

}