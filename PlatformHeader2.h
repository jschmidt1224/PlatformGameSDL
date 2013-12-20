#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

SDL_Surface *screen = NULL;
TTF_Font* font = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int FPS = 30;

int init()
{ 
     font = TTF_OpenFont("arial.ttf", 28);
     SDL_Color textColor = {128, 128, 0};
     SDL_Init(SDL_INIT_EVERYTHING);
     screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
     SDL_WM_SetCaption("Test", NULL);
     TTF_Init();
}

SDL_Surface* load_image(std::string filename, bool transparent = false, int R = 0, int G = 0, int B = 0)
{
     SDL_Surface* image = NULL;
     SDL_Surface* optimized = NULL;
    
     image = IMG_Load(filename.c_str());

     if (image != NULL)
     {
          optimized = SDL_DisplayFormat(image);
          SDL_FreeSurface(image);
     }
     
     if (optimized != NULL && transparent)
     {
          Uint32 color = SDL_MapRGB(optimized->format, R, G, B);
          SDL_SetColorKey(optimized, SDL_SRCCOLORKEY, color);
     }

     return optimized;
}

void draw_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
     SDL_Rect offset;

     offset.x = x;
     offset.y = y;

     SDL_BlitSurface(source, NULL, destination, &offset);
}
