#include "minimap.h"


int main()
{
    //SDL init 
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    //Police Init 
    TTF_Font *police=NULL;
    SDL_Color Color={255,255,255};
    police=TTF_OpenFont("pol.ttf",50);

    // Init Fenetre 
    SDL_Surface *screen ;
    screen=SDL_SetVideoMode (1000,666,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    //Init personnage  
    Perso personnage ; 
    initPerso(&personnage);

    // Init MINIMAP 
    minimap m;
    SDL_Rect camera,backgpos;
    int temps;
    init_map(&m);


    /////////////////////////////////////////////
    //Init Background  & perso for TESTING ...
    //perso=IMG_Load("hero.png");
    SDL_Surface *back;
    back=IMG_Load("backg.png");
    camera.x=0;
    camera.y=0;
    camera.w=1300;
    camera.h=700;
    //posperso.x=0;
    //posperso.y=400;
    backgpos.x=0;
    backgpos.y=0;
///////////////////////////////////////////


    SDL_Event event;
    int continuer=1;
    int time = 0 ;
    int key = 0 ; 
    SDL_EnableKeyRepeat(100,10);
    
    while(continuer)
    {   
        //AFFICHAGE 
        SDL_BlitSurface(back,NULL,screen,&backgpos);
        afficherminimap(m,screen);
        afficherPerso(personnage,screen);
        affichertemp(&temps,screen,police);

        SDL_PollEvent(&event);
         //MajPerso(&personnage,event);
        switch (event.type) 
        {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    continuer = 0;
                    break;

                    case SDLK_RIGHT:
                    //MajPerso(&personnage,1);
                    key = 1 ; 
                    deplacerPerso(&personnage,10);
                    break;
                    
                    case SDLK_LEFT:
                        //MajPerso(&personnage,2);
                        key = 2 ; 
                        deplacerPerso(&personnage,10);                    
                    break;

                    case SDLK_SPACE:
                        MajPerso(&personnage,3);
                        deplacerPerso(&personnage,10);                    
                    break;

        }

        animePerso(&personnage);

        MAJMinimap(personnage.img.pos1,  &m, camera, 20);
            MajPerso(&personnage,key);
        UpdatePerso(&personnage);
        collision(screen,&personnage);

        SDL_Flip(screen);
    }





    return 0 ; 

}