
#include <Cell.hpp>

Cell::Cell(){

}
Cell::~Cell(){

}

void Cell::setCell(int row, int column,int isAlive){
    this->row = row;
    this->column = column;
    this->isAlive = isAlive;
}

int Cell::getRow(){
    return this->row;
}

int Cell::getColumn(){
    return this->column;
}

int Cell::getIsAlive(){
    return this->isAlive;
}

