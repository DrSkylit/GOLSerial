#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sstream>
#include<GameOfLife.hpp>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <chrono>
#include <thread>

bool sdlInit(SDL_Window** window, SDL_Renderer** renderer);
void sdlClose(SDL_Window** window, SDL_Renderer** renderer);
void freezeUntil(int x);
void displayGrid(SDL_Renderer** renderer, int rowSize, int columnSize);

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

bool sdlInit(SDL_Window** window, SDL_Renderer** renderer){
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		*window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		
		if( *window == NULL ){
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else{
			//Create renderer for window
			*renderer = SDL_CreateRenderer( *window, -1, SDL_RENDERER_ACCELERATED );
			if(*renderer == NULL ){
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else{
				//Initialize renderer color
				SDL_SetRenderDrawColor( *renderer, 0xFF, 0xFF, 0xFF, 0xFF );
			}
		}
	}

	return success;
}

void sdlClose(SDL_Window** window, SDL_Renderer** renderer){
	//Destroy window	
	SDL_DestroyRenderer( *renderer );
	SDL_DestroyWindow( *window );
	*window = NULL;
	*renderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void freezeUntil(int x){
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void displayGrid(GameOfLife gameOfLife, int** board, SDL_Renderer** renderer, int rowSize, int columnSize){
	freezeUntil(150);
	SDL_SetRenderDrawColor(*renderer,255, 255, 255, 0);
	SDL_RenderClear(*renderer);
	for (int i = 0; i < rowSize; ++i){
		for (int j = 0; j < columnSize; ++j){
			int cell = board[i][j];
			SDL_Rect rect = {(j * columnSize) + (j*((SCREEN_WIDTH/columnSize)-columnSize)), (i * rowSize) + (i * ((SCREEN_HEIGHT/rowSize) - rowSize)), (SCREEN_WIDTH/columnSize), (SCREEN_HEIGHT/rowSize) }; 
			if(cell == 1){
				//Render red filled quad
            SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 0);        
            SDL_RenderFillRect(*renderer, &rect);
			}else{
				//Render green outlined quad
         	SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 0);        
         	SDL_RenderDrawRect(*renderer, &rect);
      	}
		}
	}

	board = gameOfLife.nextBoard();
	// gameOfLife.printBoard();
	//Update screen
   SDL_RenderPresent(*renderer);
}

int main(int argc, char *argv[]){

	// the window we will  be rendering too
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	if(!sdlInit(&window,&renderer)){
		printf( "Failed to initialize!\n" );
		return 0;
	}

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
	// gameOfLife.printBoard();
	int** board;
	board = gameOfLife.getBoard();

	// game loop flags
	bool quit = false;
	bool pause = false;
	bool next = false;
	// event handler
	SDL_Event e;

	while(!quit){
		// Handle events on queue 
		while(SDL_PollEvent(&e) != 0){
			// User requests quit
			if(e.type == SDL_QUIT){
				quit = true;
			}
			// handle keydown events
			if(e.type == SDL_KEYDOWN){
				switch(e.key.keysym.sym){
					case SDLK_SPACE:
						if(pause == false){
							pause = true;
						}else{
							pause = false;
						}
						break;
					case SDLK_RIGHT:
						next = true;
						break;
					default:
						break;
				}
			}
		}
		// check if the board should be paused
		if(!pause){
			displayGrid(gameOfLife, board, &renderer, rowSize, columnSize);
	   }else{
	   	if(next == true){
	   		displayGrid(gameOfLife, board, &renderer, rowSize, columnSize);
	   		next = false;
	   	}
	   }
	}

	sdlClose(&window,&renderer);
	return 0;
}