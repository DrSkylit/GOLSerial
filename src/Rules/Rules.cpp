#include <stdlib.h>
#include <iostream>

#include <Rules.hpp>

Rules::Rules() {
    
}

Rules::~Rules(){
    
}

int Rules::applyRules(Cell cell, int aliveNeighbors){
    int isAlive = cell.getIsAlive();
    int alive = 0;
    alive = this->rule1(alive, isAlive, aliveNeighbors);
    alive = this->rule2(alive, isAlive, aliveNeighbors);
    alive = this->rule3(alive, isAlive, aliveNeighbors);
    alive = this->rule4(alive, isAlive, aliveNeighbors);
    return alive;
}

int Rules::rule1(int alive, int isAlive, int aliveNeighbors){
    if(isAlive){
        if(aliveNeighbors < 2){
            return 0;
        }
    }
    return alive;
}

int Rules::rule2(int alive, int isAlive, int aliveNeighbors){
    if(isAlive){
        if(aliveNeighbors == 2 || aliveNeighbors == 3){
            return 1;
        }
    }
    return alive;
}

int Rules::rule3(int alive, int isAlive, int aliveNeighbors){
    if(isAlive){
        if(aliveNeighbors > 3){
            return 0;
        }
    }
    return alive;
}

int Rules::rule4(int alive, int isAlive, int aliveNeighbors){
    if(!isAlive){
        if(aliveNeighbors == 3){
            return 1;
        }
    }
    return alive;
}