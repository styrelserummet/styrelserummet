#include "spritedemo.h"

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
    SDL_Surface* screen = SDL_SetVideoMode(200, 200, 16,
            SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption( "Sprite Example", "Sprite Example" );
    if ( !screen ) {
        printf("Unable to set video: %s\n", SDL_GetError());
        running = false;
    }
    SDL_Event keyevent;

    Sprite* s1 = new Sprite("sprites/samus_normal_run.bmp", 10, 60);
    s1->setTransparency(255, 0, 255);

    Sprite* s2 = new Sprite("sprites/samus_normal_run.bmp", 10, 60);
    s2->rotate90()->setTransparency(255, 0, 255);

    while(running) {
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        s1->animate()->draw(screen, 50, 50);
        s2->animate()->draw(screen, 100, 50);

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
