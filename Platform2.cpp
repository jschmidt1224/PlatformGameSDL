#include "PlatformHeader.h"
#include "sprite.h"


int main( int argc, char* args[] )
{
     bool loop = true;
     SDL_Event event;
     int ticks;
     Sprite sprite;
     init();
     
     while (loop)
     {
          loop = sprite.check_collision();
          ticks = SDL_GetTicks();
          //Handle Events
          while (SDL_PollEvent(&event))
          {
               if (event.type == SDL_QUIT)
               {
                    loop = false;
               }
          }
          //Game Logic
          Uint8 *keyStates = SDL_GetKeyState(NULL);
          
          
          //if (keyStates[SDLK_UP])
          //{
               //x += 1;
          //}
          
          //Clear screen
          SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 255, 255, 255));
          //Draw to screen
          
          //Show screen
          SDL_Flip(screen);
          
          if (SDL_GetTicks() - ticks < 1000 / FPS)
          {
               SDL_Delay((1000 / FPS) - (SDL_GetTicks() - ticks));
          }
     }
     
     TTF_CloseFont(font);

     //Free the surface and quit SDL
     TTF_Quit();
     SDL_Quit();
     return 0;
}
