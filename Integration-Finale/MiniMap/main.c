#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "minimap.h"
#include <time.h>

int main()
{

//joueur j;

//SDL init 
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();

//Police Init 
TTF_Font *police=NULL;
SDL_Color Color={255,255,255};
police=TTF_OpenFont("pol.ttf",50);



//Init personnage TESTING ... 
Perso personnage ; 
initPerso(&personnage);

// Init Fenetre 
SDL_Surface *screen ;
screen=SDL_SetVideoMode (1000,666,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


SDL_Event event;

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


int continuer=1;
int time = 0 ; 





SDL_EnableKeyRepeat(100,10);

while(continuer)
{

SDL_BlitSurface(back,NULL,screen,&backgpos);
afficherminimap(m,screen);
afficherPerso(personnage,screen);
affichertemp(&temps,screen,police);





SDL_PollEvent(&event);

//MajPerso(personnage , event , &time  );
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
                    //m.positionminijoueur.x+=10;
                    
                            personnage.desacceleration=0;
                            personnage.acc+=0.008;
                            if(personnage.acc>=0.1)
                                personnage.acc=0.1;
                            personnage.derec=1;
                    deplacerPerso(&personnage,10);
                    
                    
                    break;
                    
                    case SDLK_LEFT:
                    //m.positionminijoueur.x-=10;
                    
                        personnage.desacceleration=0;
                        personnage.acc+=0.008;
                            if(personnage.acc>=0.1)
                                personnage.acc=0.1;
                        personnage.derec=2;
                        deplacerPerso(&personnage,10);

                    
                    
                    break;

                    
                    
                    break;
                 
               
                }
                break;
                
             }






animePerso(&personnage);

MAJMinimap(personnage.img.pos1,  &m, camera, 20);

collision(screen,&personnage);

SDL_Flip(screen);


}
liberer(&m);
    return 0;
}





