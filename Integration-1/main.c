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

    int start=0,end=0,dt; 
    
    SDL_EnableKeyRepeat(100,10);
    
    while(continuer)
    {   
        start=SDL_GetTicks();
        dt=start-end;
        if(dt>60){
        //AFFICHAGE 
        SDL_BlitSurface(back,NULL,screen,&backgpos);
        afficherminimap(m,screen);
        afficherPerso(personnage,screen);
        affichertemp(&temps,screen,police);

        SDL_PollEvent(&event);
        
        switch (event.type) 
        {
            
                case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_RIGHT){
                        MajPerso(&personnage,1);
                        

                    }
                    else if(event.key.keysym.sym==SDLK_LEFT){
                        MajPerso(&personnage,2);
                        
                    }
                    else if(event.key.keysym.sym==SDLK_SPACE){
                        MajPerso(&personnage,3);
                        

                        //Mix_PlayChannel(0,jump,0);
                    }
                    break;

                case SDL_KEYUP:
                    MajPerso(&personnage,4);
                    break;
                }
            UpdatePerso(&personnage ) ; 
            end=start;
            if (start > 100000 ) 
            	start = end = 0 ; 
            deplacerPerso(&personnage,10); 
        }
        

        animePerso(&personnage);

        MAJMinimap(personnage.img.pos1,  &m, camera, 20);

        collision(screen,&personnage);
        
//UpdatePerso(&personnage);
        SDL_Flip(screen);
}


liberer(&m);
libererperso(&personnage);
SDL_Quit();
TTF_Quit();
    return 0 ; 

}
