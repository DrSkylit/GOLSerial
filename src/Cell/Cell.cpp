
#include <Cell.hpp>

Cell::Cell(){

}
Cell::~Cell(){

}

void Cell::setCell(int row, int column){
    this->row = row;
    this->column = column;
}

int Cell::getRow(){
    return this->row;
}
int Cell::getColumn(){
    return this->column;
}
