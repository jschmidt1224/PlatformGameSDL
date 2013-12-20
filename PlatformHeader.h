#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <time.h>
#include <string>
#include <sstream>
#include <list>
#include <math.h>


using namespace std;


SDL_Surface *screen = NULL;
TTF_Font *font = NULL;
TTF_Font *font2 = NULL;
SDL_Color textColor = {128, 128, 0};
SDL_Color SDL_Red = {255, 0, 0};
SDL_Color SDL_Black = {0, 0, 0};
SDL_Color SDL_LtBlue = {100, 100, 255};
SDL_Color SDL_Grey = {125, 125, 125};
SDL_Surface *playerImage = NULL;
SDL_Surface *blockImage = NULL;
SDL_Surface *bullet1Image = NULL;
SDL_Surface *bullet2Image = NULL;
SDL_Surface *bullet3Image = NULL;
SDL_Surface *explosion1 = NULL;
SDL_Surface *explosion2 = NULL;
SDL_Surface *explosion3 = NULL;
SDL_Surface *explosion4 = NULL;
SDL_Surface *inventoryImage = NULL;

const int SCREEN_WIDTH = 640 + 128;
const int SCREEN_HEIGHT = 480;
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int FPS = 30;

SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

void init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    SDL_WM_SetCaption("Platform", NULL);
    TTF_Init();
    font = TTF_OpenFont("arial.ttf", 23);
    font2 = TTF_OpenFont("arial.ttf", 15);
}

SDL_Surface* load_image(std::string filename, bool trans = false, int r = 0, int g = 0, int b = 0)
{
    SDL_Surface* image = NULL;
    SDL_Surface* optimized = NULL;
    image = IMG_Load(filename.c_str()); //loads image
    if (image != NULL)
    {
        optimized = SDL_DisplayFormat(image);
        SDL_FreeSurface(image);
    }
    if (optimized != NULL && trans)
    {
        Uint32 colorkey = SDL_MapRGB(optimized->format, r, g, b);
        SDL_SetColorKey(optimized, SDL_SRCCOLORKEY, colorkey);
    }
    return optimized;
}

void draw_surface(float x, float y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect offset; //creates and set values for offset
    offset.x = x - camera.x;
    offset.y = y - camera.y;
    SDL_BlitSurface(source, NULL, destination, &offset);
}

void draw_rect(int x, int y, int w, int h, int R, int G, int B, SDL_Surface* dest)
{
    SDL_Rect r = {x, y, w, h};
    SDL_FillRect(dest, &r, SDL_MapRGB(screen->format, R, G, B));
}

int sign(float A)
{
    if (A < 0)
        return -1;
    else
        return 1;
}
