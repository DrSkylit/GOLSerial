#include <stdlib.h>
#include <iostream>

#include <Rules.hpp>

Rules::Rules() {
    
}

Rules::~Rules(){
    
}

int Rules::applyRules(int aliveNeighbors){
    int alive = this->rule1(aliveNeighbors);
    alive = this->rule2(aliveNeighbors);
    alive = this->rule3(aliveNeighbors);
    alive = this->rule4(aliveNeighbors);
    return 1;
}

int Rules::rule1(int aliveNeighbors){
    return 0;
}

int Rules::rule2(int aliveNeighbors){
    return 0;
}

int Rules::rule3(int aliveNeighbors){
    return 0;
}

int Rules::rule4(int aliveNeighbors){
    return 0;
}