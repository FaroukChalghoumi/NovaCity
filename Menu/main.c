#include "menu.h"


int main(int argc, char* argv[]) {
    SDL_Surface* screen;
    SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
    if (!screen) {
        printf("Failed to set video mode: %s\n", SDL_GetError());
        return 1;
    }

    //Play playGame;
    //InitMenuInitial(&playGame);

    //SingleMulti singleMulti;
    //InitSingleMulti(&singleMulti);
    Setting s;
    InitSettings(&s);
    menu m ;
    InitAnimationMenu(&m);


int AnimFinished = 0 ;
int arduino = 0 ; 
// Game loop
    SDL_Event event;
    int running = 1;
    while (running) {
       // AfficherAnimation (m , screen);
m.menuPlay =1;
            displayAnimation(screen,&m);
    //printf("animFinished = %d",m.AnimNovaFinished);
       if (m.AnimNovaFinished)
       {
        
        screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        freeAnimationNova(&m) ;
        //freeAnimationNova(&m) ;
        //Animation(screen, &m);


        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            //HandleMouseMotion(event, &playGame);
            //HandleInput(event, &playGame,&m);
            //HandleMouseMotionSingleMulti(event, &singleMulti);
            HandleInputSetting(event,&s,&m);
        }

        // Render the Play menu
        //AfficherMenuInitial(playGame, screen);
        //AfficherSingleMulti(singleMulti,screen);
        AfficherSetting(s,screen);
    }
        
        
 SDL_Flip(screen);
    }

    // Free memory and quit SDL
    //FreePlay(&playGame);
    freeSettings(&s);
    //FreeSingleMulti(&singleMulti);
    
    SDL_Quit();
    return 0;




}
