#include "menu.h"


int main(int argc, char* argv[]) {
   SDL_Surface* screen;
    SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(1000, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
    if (!screen) {
        printf("Failed to set video mode: %s\n", SDL_GetError());
        return 1;
    }

    //Play playGame;
    //InitMenuInitial(&playGame);

    //SingleMulti singleMulti;
    //InitSingleMulti(&singleMulti);

    menu m ;
    InitMenuEssentials(&m);
InitAnimationNova(&m);
InitMenuInitial(&m.playGame);
        InitAnimationMeta(&m);
InitSettings(&m.settingGame);
InitAnimationCar(&m);
InitSingleMulti(&m.SingleMultiplayer);
int x = -1 ; 

int AnimFinished = 0 ;
int arduino = 0 ; 
// Game loop
    SDL_Event event;
    int running = 1;
    
    while (running) {
       // AfficherAnimation (m , screen);


    //printf("animFinished = %d",m.AnimNovaFinished);
       //if (m.AnimNovaFinished)
       //{
        
        //screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        //freeAnimationNova(&m) ;
        //freeAnimationNova(&m) ;
        //Animation(screen, &m);


        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            //HandleMouseMotion(event, &playGame);
            //HandleInput(event, &playGame,&m);
            //HandleMouseMotionSingleMulti(event, &singleMulti);
            //HandleInputSetting(event,&s,&m);
            
        }
       // printf("\nmenuPlay = %d |settings = %d |game = %d | MouseMotionPlay = %d",m.menuPlay,m.settings,m.game,m.playGame.MouseMotion);
x=AllMenu(&m,screen,event);
        // Render the Play menu
        //AfficherMenuInitial(playGame, screen);
        //AfficherSingleMulti(singleMulti,screen);
        //AfficherSetting(s,screen);
   // }
        printf("\nX = %d ",x);
        
 SDL_Flip(screen);
    }

    // Free memory and quit SDL
    //FreePlay(&playGame);
    //freeSettings(&s);
    //FreeSingleMulti(&singleMulti);

    printf("\nX = %d ",x);
    
    SDL_Quit();
    return 0;









/*SDL_Init(SDL_INIT_VIDEO);
SDL_Event event;
    int running = 1;
    
        char buffer[100];                   // un buffer
    int i;

    // ouverture du port à 9600 bauds
    int fd = serialport_init("/dev/ttyUSB0", 9600);
    if (fd==-1) return -1;
    
while (running) {
while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }

}
        //  lecture d'une ligne
        serialport_read_until(fd, buffer, '\r', 99, 10000);

        // suppression de la fin de ligne
        for (i=0 ; buffer[i]!='\r' && i<100 ; i++);
        buffer[i] = 0;

        // écriture du résultat
        printf("%s", buffer);

//printf("\ntest = %d ",test);
//if (x==1)
//printf("\nX = %d ",x);
}

    // fermeture du port
    serialport_flush(fd);
    serialport_close(fd);


 return 0;*/
}
