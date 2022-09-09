#include <Cell.hpp>

class Neighbors{
public:
    Neighbors();
    ~Neighbors(); // destructor
    int getAliveNeighbors(int** board, Cell cell, int rowSize, int columnSize);

private:
	struct Direction{
		int row;
		int column;
	};
	struct Direction directions[8];
	void setNeighbors();
};