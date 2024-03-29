#include <Cell.hpp>
#include <Neighbors.hpp>
#include <Rules.hpp>

class GameOfLife{
    public:
        GameOfLife(int rowSize, int columnSize);
        ~GameOfLife(); // destructor
        int** nextBoard();
        int** skipBoard(int step);
        void printBoard();
        int** getBoard();

    private:
        int rowSize;
        int columnSize;
        int** currentBoard;
        Cell cell;
        Neighbors neighbors;
        Rules rules;
 
        void initializeGame();
        int** initializeBoard();
        void fillBoard();
        int** copyBoard(int** board1,int** board2);
};