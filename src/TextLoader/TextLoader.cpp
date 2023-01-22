// #include <stdlib.h>
// #include<sstream>
// #include<SDL2/SDL.h>
// #include<SDL2/SDL_ttf.h>
#include <TextLoader.hpp>

TextLoader::TextLoader(TTF_Font* font) {
    this->position.x = 0;
    this->position.y = 0;
    this->font = font;
}

TextLoader::~TextLoader(){
    
}

void TextLoader::setPosition(int x, int y){
	this->position.x = x;
    this->position.y = y;
}

void TextLoader::render(SDL_Renderer* renderer,SDL_Color textColor, std::string text, int rows = 0){
    int w;
    int h;
    // create a new text  surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( this->font, text.c_str(), textColor );
    if( textSurface == NULL ){
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
   }
   // create texture from surface
   SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

   // gets the corrct width and height of the font given the text 
   TTF_SizeText(font,text.c_str(),&w,&h);

   SDL_Rect textPosition; 
    textPosition.x = this->position.x;  
    textPosition.y = this->position.y;
    textPosition.w = w; 
    textPosition.h = h;

    // copys texture to the renderer
    SDL_RenderCopy(renderer, textTexture, NULL, &textPosition);

    // free up space 
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    textSurface = NULL;
    textTexture = NULL;
}