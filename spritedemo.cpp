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
    SDL_Surface* screen = SDL_SetVideoMode(800, 600, 16,
            SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption( "Sprite Example", "Sprite Example" );
    if ( !screen ) {
        printf("Unable to set video: %s\n", SDL_GetError());
        running = false;
    }
    SDL_Event keyevent;

    Sprite* run_left = new Sprite("sprites/boatman_run.bmp", 6, 100);
    run_left->setTransparency(255, 255, 255);

    Sprite* run_right = new Sprite("sprites/boatman_run.bmp", 6, 100);
    run_right->flipHorizontal()->reverseAnimation()->setTransparency(255, 255, 255);

    float posx = 400;
    int direction = -1;

    // Timing variables
    Uint32 old_time, current_time;
    float ftime;

    current_time = SDL_GetTicks();

    while(running) {
        Sprite *boatman_run;
        // clear background
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        old_time = current_time;
        current_time = SDL_GetTicks();
        ftime = (current_time - old_time) / 1000.0f;

        posx += ((50.0f * direction) * ftime);

        if (-1 == direction)
            boatman_run = run_left;
        else
            boatman_run = run_right;

        boatman_run->animate()->draw(screen, floor(posx), 35);

        SDL_Flip(screen);

        SDL_PollEvent(&keyevent);
        switch(keyevent.type) {
            case SDL_KEYDOWN:
                switch(keyevent.key.keysym.sym) {
                    case SDLK_LEFT:
                        direction = -1;
                        break;
                    case SDLK_RIGHT:
                        direction = 1;
                        break;
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

    delete run_left;
    delete run_right;

    return 0;
}
