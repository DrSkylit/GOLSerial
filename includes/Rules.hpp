#include <Cell.hpp>

class Rules{
    public:
        Rules();
        ~Rules(); // destructor
        int applyRules(Cell cell, int aliveNeighbors);

    private:
        int rule1(int aliveNeighbors);
        int rule2(int aliveNeighbors);
        int rule3(int aliveNeighbors);
        int rule4(int aliveNeighbors);
};