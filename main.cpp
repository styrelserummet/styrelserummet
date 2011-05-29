#include "Main.h"

using namespace std;

int main (int argc, char* argv[])
{
    bool running = true;
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "Unable to init SDL: %s\n", SDL_GetError());
        running = false;
    }
    // ensure a clean exit
    atexit(SDL_Quit);
    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(800, 600, 16,
            SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption( "Sprite Example", "Sprite Example" );
    if ( !screen ) {
        printf("Unable to set 400x300 video: %s\n", SDL_GetError());
        running = false;
    }
    SDL_Event keyevent;

    Sprite* s1 = new Sprite("sprites/tile_0.bmp", 14, 60); // load a BMP that contains 14 frames
    // set the animation speed to 60 milliseconds
    s1->setTransparency(0, 0, 0);      // set RGB(255,0,255) as transparent
    // NOTE: setTransparency(SDL_Surface->format->colorkey) also works

    while(running) {
        // clear background to green
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 255, 0));

        s1->animate()->draw(screen,0,0);

        SDL_Flip(screen);

        SDL_PollEvent(&keyevent);
        switch(keyevent.type) {
            case SDL_KEYDOWN:
                printf("key down\n");
                switch(keyevent.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }

    return 0;
}
