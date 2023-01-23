#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sstream>
#include<GameOfLife.hpp>
#include<TextLoader.hpp>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<chrono>
#include<thread>

bool sdlInit(SDL_Window** window, SDL_Renderer** renderer);
void sdlClose(SDL_Window** window, SDL_Renderer** renderer);
void freezeUntil(int x);
void displayGrid(SDL_Renderer** renderer, int rowSize, int columnSize);
void displayText(SDL_Renderer** renderer,TTF_Font* font,SDL_Color textColor, std::string text, int rows);

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
const int MAX_ROW_SIZE = 90;
const int MAX_COLUIMN_SIZE = 125;
int CELL_SIZE = 10;
const SDL_Color SDL_COLOR_BLACK = { 0, 0, 0 };

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
		}else{
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

		if(TTF_Init() == -1 ){
      	printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
         success = false;
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
	TTF_Quit();
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
			SDL_Rect rect = {(j * CELL_SIZE) + (SCREEN_WIDTH/2) - (CELL_SIZE/2) * columnSize, (i * CELL_SIZE) + 15, CELL_SIZE, CELL_SIZE}; 
			SDL_Rect rect1 = {((j * CELL_SIZE) + (SCREEN_WIDTH/2) - (CELL_SIZE/2) * columnSize)+1, ((i * CELL_SIZE) + 15)+1, CELL_SIZE-2, CELL_SIZE-2}; 
			if(cell == 1){
				//Render red filled quad
            SDL_SetRenderDrawColor(*renderer, 114, 162, 241, 0);        
            SDL_RenderFillRect(*renderer, &rect1);
            SDL_SetRenderDrawColor(*renderer, 120, 120, 120, 0);        
         	SDL_RenderDrawRect(*renderer, &rect);
			}else{
				// Render green outlined quad
         	SDL_SetRenderDrawColor(*renderer, 120, 120, 120, 0);        
         	SDL_RenderDrawRect(*renderer, &rect);
      	}
		}
	}

	board = gameOfLife.nextBoard();
}

int main(int argc, char *argv[]){

	// the window we will be rendering too
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	int frame = 0;

	if(!sdlInit(&window,&renderer)){
		printf( "Failed to initialize!\n" );
		return 0;
	}
	// works for cmake
	TTF_Font* font = TTF_OpenFont( "../fonts/alagard.ttf", 20 );
	if(font == NULL){
		// works for g++
		font = TTF_OpenFont( "fonts/alagard.ttf", 20 );
	}

	if(font == NULL){
		font = TTF_OpenFont( "../fonts/alagard.ttf", 20 );
		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
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
		if(rowSize > MAX_ROW_SIZE){
			std::cout << "The max row size is 90, you entered " << rowSize << " defaulting to 90" << std::endl;
			rowSize = MAX_ROW_SIZE;
		}
		if(columnSize > MAX_COLUIMN_SIZE){
			std::cout << "The max column size is 125, you entered " << columnSize << " defaulting to 125" << std::endl;
			columnSize  = MAX_COLUIMN_SIZE;
		}
	}else{
		std::cout << "you entered the wrong amount of command line arguments" << std::endl;
		std::cout << "Using Default of 15" << std::endl;
		rowSize = 15;
		columnSize = 15;
	}

	GameOfLife gameOfLife(rowSize,columnSize);
	// gameOfLife.printBoard();
	int** board;
	board = gameOfLife.getBoard();

	// game loop flags
	bool quit = false;
	bool pause = true;
	bool next = false;
	// event handler
	SDL_Event e;
	displayGrid(gameOfLife, board, &renderer, rowSize, columnSize);
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
		// check if the board is paused
		if(!pause){
			displayGrid(gameOfLife, board, &renderer, rowSize, columnSize);
			frame = frame + 1;
	   }else{
	   	if(next == true){
	   		displayGrid(gameOfLife, board, &renderer, rowSize, columnSize);
	   		frame = frame + 1;
	   		next = false;
	   	}
	   }
	   
	   std::string frame1 = "Frame: " + std::to_string(frame);
	   // create text loader that handles displaying text on the screen 
	   TextLoader frameText(font);
	   frameText.setPosition(20,(((CELL_SIZE) * rowSize) + 20));
	   frameText.render(renderer,SDL_COLOR_BLACK,frame1,rowSize);

	   std::string rowStr = "Row: " + std::to_string(rowSize);
	   TextLoader rowText(font);
	   rowText.setPosition(150,(((CELL_SIZE) * rowSize) + 20));
	   rowText.render(renderer,SDL_COLOR_BLACK,rowStr,rowSize);

	  	std::string columnStr = "Column: " + std::to_string(columnSize);
	   TextLoader columnText(font);
	   columnText.setPosition(250,(((CELL_SIZE) * rowSize) + 20));
	   columnText.render(renderer,SDL_COLOR_BLACK,columnStr,rowSize);

	   std::string desc = "Press Space To play/pause, Once paused you can Press the forward ARROW to move one frame at a time";
	   TextLoader descText(font);
	   descText.setPosition(20,(((CELL_SIZE) * rowSize) + 35));
	   descText.render(renderer,SDL_COLOR_BLACK,desc,rowSize);

	   
	   SDL_RenderPresent(renderer);

	}

	sdlClose(&window,&renderer);
	return 0;
}