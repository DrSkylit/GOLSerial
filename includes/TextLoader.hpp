#include <stdlib.h>
#include<sstream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>

class TextLoader{
    public:
        TextLoader(TTF_Font* font);
        ~TextLoader(); // destructor
        void setPosition(int x, int y);
        void render(SDL_Renderer* renderer,SDL_Color textColor, std::string text, int rows);

    private:
    	//Top left position
        SDL_Point position;
        TTF_Font* font;
};