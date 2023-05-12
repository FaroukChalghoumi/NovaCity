
#include <SDL/SDL_mixer.h>
#include "perso.h"


void initPerso(Perso *P){
    //P->img.img=IMG_Load("spritesheet_car.png");spritesheet_voiture_rouge
P->img.img=IMG_Load("spritesheet_voiture_rouge.png");
    P->img.pos1.x=300;
    P->img.pos1.y=520;

    P->img.pos2.x=P->img.img->w;
    P->img.pos2.y=P->img.img->h/2;
    P->img.pos2.w=P->img.img->w/11;
    P->img.pos2.h=P->img.img->h/4 ;

    P->jumt = 0 ; 
    P->i = 0;
    P->count=0;
    P->derec=0;
    P->speed=0.1;
    P->acc=0;
    P->desacceleration=0;
    
}




void afficherPerso(Perso P,SDL_Surface* screen){
    SDL_BlitSurface(P.img.img,&P.img.pos2,screen,&P.img.pos1);
    //SDL_BlitSurface(P.img.img,NULL,screen,&P.img.pos1);
}

void deplacerPerso(Perso *P,int dt){
    P->distance=0.5*(P->acc)*dt*dt+P->speed*dt;
    if(P->derec==1){
        P->img.pos1.x+=P->distance;
    }
    else if(P->derec==2){
        P->img.pos1.x-=P->distance;
    }
}

void animePerso(Perso *P){
    P->count++;
    if(P->count>=400){
        P->count=0;
        //printf("\n nbimage = %d ",P->img.pos2.x/(P->img.img->w/11));
        if(P->derec==1){
            P->img.pos2.y=P->img.img->h/4 ;
            P->img.pos2.x-=P->img.img->w/11;
            
            if(P->img.pos2.x<=0)
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11)  ;
        }
        else if(P->derec==2){
            P->img.pos2.y=0;
            P->img.pos2.x-=P->img.img->w/11;
            
            if(P->img.pos2.x<=0)
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) ;
        }
        else if(P->acc==0){
            P->img.pos2.x=P->img.img->w - P->img.img->w/11;
        }
         if(P->jumt)
        {
            
            if(P->derec==1){
                P->img.pos2.y=P->img.img->h/4 * 2;
                P->img.pos2.x-=P->img.img->w/11;

                if(P->img.pos2.x<=P->img.img->w/11)
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 9 ;
        }

        else if(P->derec==2){
                P->img.pos2.y=P->img.img->h/4 * 3;
                P->img.pos2.x-=P->img.img->w/11;

                if(P->img.pos2.x<=P->img.img->w/11)
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 9;
        }

    }
    }
}


void saut(Perso *P){
    // ax²+b
    // b=-100+
    //-50----->>>50
    P->i+=5;
    P->img.pos1.y=0.04*(P->i)*(P->i)-100+P->y;
    
    P->acc=0.2;
    if(P->i>=50){
        P->jumt=0;
        P->acc=0.1;
    }
}



void MajPerso (Perso* P  )
{


    int right = SDLK_RIGHT;
    int left = SDLK_LEFT;
    int up = SDLK_UP;
    int RUN = SDLK_SPACE ; 

    if (P->keystate[right]){
        P->desacceleration=0;
        P->acc+=0.008;
        if(P->acc>=0.1)
            P->acc=0.1;
        P->derec=1;
        if(P->keystate[up]) {
            if (P->jumt == 0)
            {
                P->jumt=1;
                P->i=-50;
                P->y=P->img.pos1.y;
            
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 8;
            }
    }
    
    }
    else if (P->keystate[left]){
        P->desacceleration=0;
        P->acc+=0.008;
        if(P->acc>=0.1)
            P->acc=0.1;
        P->derec=2;
        if(P->keystate[up]) {
            if (P->jumt == 0)
            {
                P->jumt=1;
                P->i=-50;
                P->y=P->img.pos1.y;
            
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 8;
            }
    }
    }
    else if(P->keystate[up]) {
        if (P->jumt == 0)
        {
                P->jumt=1;
                P->i=-50;
                P->y=P->img.pos1.y;
            
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 8; 
        }
    }
    else    {
        P->desacceleration=1;
    }

     





/*
switch ( event )
{
    case 1 : //SDLK_RIGHT
        P->desacceleration=0;
        P->acc+=0.008;
        if(P->acc>=0.1)
            P->acc=0.1;
        P->derec=1;
    break ; 

    case 2 : //SDLK_LEFT
        P->desacceleration=0;
        P->acc+=0.008;
        if(P->acc>=0.1)
            P->acc=0.1;
        P->derec=2;
    break ; 

    case 3 : //SDLK_SPACE
    if (P->jumt == 0)
    {
        P->jumt=1;
        P->i=-50;
       P->y=P->img.pos1.y;
       
        P->img.pos2.x=0; 
    }
        
    break ; 

    case 4 : 
        P->desacceleration=1;
    break ; 
}
*/



    }


  void UpdatePerso   (Perso* P)
  {
       if(P->jumt){
        
                saut(P);
            }
            if(P->acc>0&&P->jumt==0)
                //Mix_PlayChannel(0,footSteps,0);
            if(P->desacceleration)
                P->acc-=0.01;
            if(P->acc<=0){
                P->acc=0;
                P->desacceleration=0;
                P->derec=0;
            }

  }


  void libererperso(Perso* p) {
    // Free the image surface
    if (p->img.img != NULL) {
        SDL_FreeSurface(p->img.img);
        p->img.img = NULL;
    }

    // Free the text surface
    if (p->img.img != NULL) {
        SDL_FreeSurface(p->img.img);
        p->img.img = NULL;
    }


  }
    


void loadStage2Perso(Perso *P )
{
    P->img.img=IMG_Load("spritedheet_150.png");

    P->img.pos1.x=300;
    P->img.pos1.y=500;

    P->img.pos2.x=P->img.img->w;
    P->img.pos2.y=P->img.img->h/2;
    P->img.pos2.w=P->img.img->w/11;
    P->img.pos2.h=P->img.img->h/4 ;

    P->jumt = 0 ; 
    P->i = 0;
    P->count=0;
    P->derec=0;
    P->speed=0.1;
    P->acc=0;
    P->desacceleration=0;
}




///////////////Multiplayer Tache Blanche :
void initPersoMultiplayer(Perso *P , char *ImagePath , SDL_Rect pos){
    //P->img.img=IMG_Load("spritesheet_car.png");spritesheet_voiture_rouge
P->img.img=IMG_Load(ImagePath);
    P->img.pos1 = pos ; 

    P->img.pos2.x=P->img.img->w;
    P->img.pos2.y=P->img.img->h/2;
    P->img.pos2.w=P->img.img->w/11;
    P->img.pos2.h=P->img.img->h/4 ;

    P->jumt = 0 ; 
    P->i = 0;
    P->count=0;
    P->derec=0;
    P->speed=0.1;
    P->acc=0;
    P->desacceleration=0;
    
}



void MajPerso2 (Perso* P  )
{


    int right = SDLK_d;
    int left = SDLK_q;
    int up = SDLK_z;
    int RUN = SDLK_LSHIFT ; 

    if (P->keystate[right]){
        P->desacceleration=0;
        P->acc+=0.008;
        if(P->acc>=0.1)
            P->acc=0.1;
        P->derec=1;
        if(P->keystate[up]) {
            if (P->jumt == 0)
            {
                P->jumt=1;
                P->i=-50;
                P->y=P->img.pos1.y;
            
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 8;
            }
    }
    
    }
    else if (P->keystate[left]){
        P->desacceleration=0;
        P->acc+=0.008;
        if(P->acc>=0.1)
            P->acc=0.1;
        P->derec=2;
        if(P->keystate[up]) {
            if (P->jumt == 0)
            {
                P->jumt=1;
                P->i=-50;
                P->y=P->img.pos1.y;
            
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 8;
            }
    }
    }
    else if(P->keystate[up]) {
        if (P->jumt == 0)
        {
                P->jumt=1;
                P->i=-50;
                P->y=P->img.pos1.y;
            
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 8; 
        }
    }
    else    {
        P->desacceleration=1;
    }

     





/*
switch ( event )
{
    case 1 : //SDLK_RIGHT
        P->desacceleration=0;
        P->acc+=0.008;
        if(P->acc>=0.1)
            P->acc=0.1;
        P->derec=1;
    break ; 

    case 2 : //SDLK_LEFT
        P->desacceleration=0;
        P->acc+=0.008;
        if(P->acc>=0.1)
            P->acc=0.1;
        P->derec=2;
    break ; 

    case 3 : //SDLK_SPACE
    if (P->jumt == 0)
    {
        P->jumt=1;
        P->i=-50;
       P->y=P->img.pos1.y;
       
        P->img.pos2.x=0; 
    }
        
    break ; 

    case 4 : 
        P->desacceleration=1;
    break ; 
}
*/



    }