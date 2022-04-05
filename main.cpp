#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sstream>

struct Neighbors{
	int i;
	int j;
};

int** initBoard(int **arr,int size){
	arr = new int*[size];
    for(int i = 0; i < size; i++){
        arr[i] = new int[size];
    }
	return arr;
}

int** fillBoard(int **arr,int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			arr[i][j] = rand()%2;
    	}
    }
	return arr;
}

int** copyBoard(int **copyTo, int **copyFrom,int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			copyTo[i][j] = copyFrom[i][j];
		}
	}
	return copyTo;
}

void printBoard(int **board,int size){
	std::cout << "" << std::endl;
	for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
           std::cout << board[i][j] << " ";
        }
		std::cout << "" << std::endl;
    }
}

int getNeighbors(int **board,int i, int j, int max, struct Neighbors directions[8]){
	int neighbors = 0;
	
	for(int k = 0; k < 8; k ++){
		int di = directions[k].i;
		int dj = directions[k].j;

		int row = di + i;
		if(row < 0){
			row = max-1;
		}
		if(row >= max){
			row = 0;
		}

		int column = dj + j;
        if(column < 0){
            column = max-1;
        }
        if(column >= max){
            column = 0;
        }
		if(board[row][column] == 1){
			neighbors++;
		}			
	}
	return neighbors;	
}

int main(int argc, char *argv[]){
	std::stringstream str;
	srand(time(NULL));
	int **currCells;
	int **succCells;
	
	int cell = 0;
	
	int currStep = 0;
	
	int MAX_STEP = 40;
	int MAX_SIZE;
	int MAX_NEIGHBORS = 8;

	int neighbors = 0;

	struct Neighbors nDirections[8];
	if(argc == 2 ){
		MAX_SIZE = 3;
		str << argv[1];
		str >> MAX_SIZE;
	}else{
		std::cout << "you entered the wrong amount of command line arguments" << std::endl;
		std::cout << "Using Default of 15" << std::endl;
		MAX_SIZE = 15;
	}


	// Top Left
	nDirections[0].i = -1;
	nDirections[0].j = -1;
	// Top
	nDirections[1].i = -1;
    nDirections[1].j = 0;
	// Top Right
	nDirections[2].i = -1;
    nDirections[2].j = 1;
	// Left
	nDirections[3].i = 0;
    nDirections[3].j = -1;
	// Right
    nDirections[4].i = 0;
    nDirections[4].j = 1;
	// Botom Left
    nDirections[5].i = 1;
    nDirections[5].j = -1;
    // Bottom
    nDirections[6].i = 1;
    nDirections[6].j = 0;
    // Bottom Right
    nDirections[7].i = 1;
    nDirections[7].j = 1;


	currCells = initBoard(currCells,MAX_SIZE);
	succCells = initBoard(succCells,MAX_SIZE);

	currCells = fillBoard(currCells,MAX_SIZE);
	succCells = copyBoard(succCells,currCells,MAX_SIZE);
	printBoard(succCells,MAX_SIZE);
	sleep(1);

	for(int k = 0; k < MAX_STEP; k++){
		for(int i = 0; i < MAX_SIZE; i++){
			for(int j = 0; j < MAX_SIZE; j++){
				int cell = currCells[i][j];
				int neighbors = getNeighbors(currCells,i,j,MAX_SIZE,nDirections);

				// program rules
				if(cell == 1){
					if(neighbors == 2 || neighbors == 3){
						succCells[i][j] = 1;
						continue;
					}
				}

				if(cell == 0){
					if(neighbors == 3){
						succCells[i][j] = 1;
						continue;
					}
				}
				succCells[i][j] = 0;
			}
		}
		printBoard(succCells,MAX_SIZE);
		currCells = copyBoard(currCells,succCells,MAX_SIZE);
		sleep(1);
	}
}
