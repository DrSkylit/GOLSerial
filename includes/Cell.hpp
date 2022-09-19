#pragma once

class Cell{
public:
    Cell();
    ~Cell(); // destructor
    void setCell(int row, int column, int isAlive);
    int getRow();
    int getColumn();
    int getIsAlive();

private:
	int row;
	int column;
	int isAlive;
};