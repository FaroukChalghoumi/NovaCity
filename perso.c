#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


void initPerso(Perso *P){
    P->img.img=IMG_Load("perso1.png");

    P->img.pos1.x=0;
    P->img.pos1.y=500;

    P->img.pos2.x=0;
    P->img.pos2.y=P->img.img->h/2;
    P->img.pos2.w=P->img.img->w/4;
    P->img.pos2.h=P->img.img->h/2;

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
    if(P->count>=2){
        P->count=0;
        if(P->derec==1){
            P->img.pos2.y=P->img.img->h/2;
            P->img.pos2.x+=P->img.img->w/4;
            if(P->img.pos2.x>=P->img.img->w)
                P->img.pos2.x=0;
        }
        else if(P->derec==2){
            P->img.pos2.y=0;
            P->img.pos2.x-=P->img.img->w/4;
            if(P->img.pos2.x<=0)
                P->img.pos2.x=P->img.img->w/4*3;
        }
        else if(P->acc==0){
            P->img.pos2.x=P->img.img->w/4*2;
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



void MajPerso (Perso P , SDL_Event event , int *end )
{
int start=0,dt;
start=SDL_GetTicks();
        dt=start- *(end);
        if(dt>60){
    switch (event.type)
                    {
                    case SDL_KEYDOWN:
                        if(event.key.keysym.sym==SDLK_RIGHT){
                            P.desacceleration=0;
                            P.acc+=0.008;
                            if(P.acc>=0.1)
                                P.acc=0.1;
                            P.derec=1;

                        }
                        else if(event.key.keysym.sym==SDLK_LEFT){
                            P.desacceleration=0;
                            P.acc+=0.008;
                            if(P.acc>=0.1)
                                P.acc=0.1;
                            P.derec=2;
                        }
                        else if(event.key.keysym.sym==SDLK_SPACE){
                            P.jumt=1;
                            P.i=-60;
                            P.y=P.img.pos1.y;

                            //Mix_PlayChannel(0,jump,0);
                        }
                        break;

                    case SDL_KEYUP:
                        if(event.key.keysym.sym==SDLK_RIGHT){
                            P.desacceleration=1;
                        }
                        else if(event.key.keysym.sym==SDLK_LEFT){
                            P.desacceleration=1;
                        }
                        break;
                    }
                if(P.jumt){
                    saut(&P);
                }
                if(P.acc>0&&P.jumt==0)
                    //Mix_PlayChannel(0,footSteps,0);
                if(P.desacceleration)
                    P.acc-=0.01;
                if(P.acc<=0){
                    P.acc=0;
                    P.desacceleration=0;
                    P.derec=0;
                }
                   
            }
             *(end)=start;
    }

