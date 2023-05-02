#include "menu.h"


int main(int argc, char* argv[]) {
    SDL_Surface* screen;
    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (!screen) {
        printf("Failed to set video mode: %s\n", SDL_GetError());
        return 1;
    }

    //Play playGame;
    //InitMenuInitial(&playGame);

    SingleMulti singleMulti;
    InitSingleMulti(&singleMulti);

    menu m ;
    InitAnimationMenu(&m);
int AnimFinished = 0 ;

// Game loop
    SDL_Event event;
    int running = 1;
    while (running) {
       // AfficherAnimation (m , screen);

            displayAnimation(screen,&m,&AnimFinished);
      
       if (AnimFinished)
       {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            //HandleMouseMotion(event, &playGame);
            HandleMouseMotionSingleMulti(event, &singleMulti);
        }

        // Render the Play menu
        //AfficherMenuInitial(playGame, screen);
        AfficherSingleMulti(singleMulti,screen);
    }
        
        
 SDL_Flip(screen);
    }

    // Free memory and quit SDL
    //FreePlay(&playGame);
    FreeSingleMulti(&singleMulti);
    freeAnimation(&m) ;
    SDL_Quit();
    return 0;




}