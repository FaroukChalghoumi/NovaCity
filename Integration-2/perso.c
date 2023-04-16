
#include <SDL/SDL_mixer.h>
#include "perso.h"


void initPerso(Perso *P){
    P->img.img=IMG_Load("robotrouge_jump_run.png");

    P->img.pos1.x=0;
    P->img.pos1.y=480;

    P->img.pos2.x=P->img.img->w;
    P->img.pos2.y=P->img.img->h/2;
    P->img.pos2.w=P->img.img->w/11;
    P->img.pos2.h=P->img.img->h/4;

    P->count=0;
    P->derec=0;
    P->speed=0.1;
    P->acc=0;
    P->desacceleration=0;
    
}

void afficherPerso(Perso P,SDL_Surface* screen){
    SDL_BlitSurface(P.img.img,&P.img.pos2,screen,&P.img.pos1);
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
    if(P->count>=100){
        P->count=0;
        if(P->derec==1){
            P->img.pos2.y=P->img.img->h/4;
            P->img.pos2.x-=P->img.img->w/11;
            
            if(P->img.pos2.x<=P->img.img->w/11)
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) * 3 ;
        }
        else if(P->derec==2){
            P->img.pos2.y=0;
            P->img.pos2.x-=P->img.img->w/11;
            
            if(P->img.pos2.x<=P->img.img->w/10)
                P->img.pos2.x=P->img.img->w - (P->img.img->w/11) *3;
        }
        else if(P->acc==0){
            P->img.pos2.x=P->img.img->w - P->img.img->w/11;
        }
    }
}


void saut(Perso *P){
    // ax²+b
    // b=-100+
    //-50----->>>50
    P->i+=10;
    P->img.pos1.y=0.04*(P->i)*(P->i)-100+P->y;
    P->acc=0.2;
    if(P->i>=50){
        P->jumt=0;
        P->acc=0.1;
    }
}



void MajPerso (Perso* P , int event )
{

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
        P->jumt=1;
        P->i=-60;
        P->y=P->img.pos1.y;
    break ; 

    case 4 : 
        P->desacceleration=1;
    break ; 
}



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
    

