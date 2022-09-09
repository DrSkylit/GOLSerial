#include <stdlib.h>
#include <iostream>

#include <GameOfLife.hpp>

GameOfLife::GameOfLife(int rowSize, int columnSize) {
    this->rowSize = rowSize;
    this->columnSize = columnSize;
    this->cell = Cell();
    this->neighbors = Neighbors();
    this->rules = Rules();
    this->initializeGame();
    this->printBoard();

}

GameOfLife::~GameOfLife(){
    
}

int** GameOfLife::nextBoard(){
    int** nextBoard = this->initializeBoard(); 
    nextBoard = this->copyBoard(nextBoard, this->currentBoard);

    for(int i = 0; i < this->rowSize; i++){
        for (int j = 0; j < this->columnSize; ++j){
            this->cell.setCell(i,j,this->currentBoard[i][j]);
            int aliveNeighbors = this->neighbors.getAliveNeighbors(this->currentBoard,this->cell,this->rowSize,this->columnSize);
            this->rules.applyRules(cell,aliveNeighbors);
        }
    }
    //  for(int i = 0; i < MAX_SIZE; i++){
    //      for(int j = 0; j < MAX_SIZE; j++){
    //          int cell = currCells[i][j];
    //          int neighbors = getNeighbors(currCells,i,j,MAX_SIZE,nDirections);

    //          // program rules
    //          if(cell == 1){
    //              if(neighbors == 2 || neighbors == 3){
    //                  succCells[i][j] = 1;
    //                  continue;
    //              }
    //          }

    //          if(cell == 0){
    //              if(neighbors == 3){
    //                  succCells[i][j] = 1;
    //                  continue;
    //              }
    //          }
    //          succCells[i][j] = 0;
    //      }
    return this->currentBoard;
}

int** GameOfLife::skipBoard(int step){
    return this->currentBoard;
}

void GameOfLife::printBoard(){
    std::cout << "" << std::endl;
    for(int i = 0; i < this->rowSize; i++){
        for(int j = 0; j < this->columnSize; j++){
           std::cout << this->currentBoard[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}

void GameOfLife::initializeGame(){
    this->currentBoard = this->initializeBoard();
    this->fillBoard();
}

int** GameOfLife::initializeBoard(){
    int** board;
    board = new int*[this->rowSize];
    for(int i = 0; i < this->rowSize; i++){
        board[i] = new int[this->columnSize];
    }
    return board;
}


void GameOfLife::fillBoard(){
    srand(time(NULL));
    for(int i = 0; i < this->rowSize; i++){
        for(int j = 0; j < this->columnSize; j++){
            this->currentBoard[i][j] = rand()%2;
        }
    }
}

int** GameOfLife::copyBoard(int** board1,int** board2){
    for(int i = 0; i < this->rowSize; i++){
        for(int j = 0; j < this->columnSize; j++){
            board1[i][j] = board2[i][j];
        }
    }
    return board2;
}