#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

int main(int argc , char *argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);


    SDL_Surface* window;
    window=SDL_SetVideoMode(1200,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

    int run=1;
    SDL_Event event;
    Perso P;
    initPerso(&P);
    int i=0;

    IMAGE bk;
    bk.img=IMG_Load("background.png");


    Mix_Chunk *footSteps,*jump;
    footSteps=Mix_LoadWAV("footstep.wav");
    jump=Mix_LoadWAV("jump.m4a");

    int start=0,end=0,dt;

    while(run){
        SDL_PollEvent(&event);
        start=SDL_GetTicks();
        dt=start-end;
        if(dt>60){
        SDL_BlitSurface(bk.img,NULL,window,NULL);
        afficherPerso(P,window);
        deplacerPerso(&P,10);
        animePerso(&P);

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

                        Mix_PlayChannel(0,jump,0);
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
                Mix_PlayChannel(0,footSteps,0);
            if(P.desacceleration)
                P.acc-=0.01;
            if(P.acc<=0){
                P.acc=0;
                P.desacceleration=0;
                P.derec=0;
            }
                end=start;
        }


    if(event.type==SDL_QUIT)
                    run=0;
                SDL_Flip(window);
    }
    return 0;
}
