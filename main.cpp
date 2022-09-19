#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sstream>
#include<GameOfLife.hpp>

int main(int argc, char *argv[]){
	std::stringstream stream1;
	std::stringstream stream2;
	int rowSize = 0;
	int columnSize = 0;

	if(argc == 3 ){
		stream1 << argv[1];
		stream1 >> rowSize;
		stream2 << argv[2];
		stream2 >> columnSize;
	}else{
		std::cout << "you entered the wrong amount of command line arguments" << std::endl;
		std::cout << "Using Default of 15" << std::endl;
		rowSize = 15;
		columnSize = 15;
	}
	std::cout << rowSize << std::endl;
	std::cout << columnSize << std::endl;
	GameOfLife gameOfLife(rowSize,columnSize);
	gameOfLife.printBoard();
	sleep(1);
	for (int i = 0; i < 20; ++i){
		int** board;
		board = gameOfLife.nextBoard();
		gameOfLife.printBoard();
		sleep(1);

		// TODO use sdl to display board 
	}
}
