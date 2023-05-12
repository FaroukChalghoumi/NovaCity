#ifndef UNTITLED_INIGMETXT_TXT_H
#define UNTITLED_INIGMETXT_TXT_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct{
SDL_Rect pos1,pos2;
SDL_Surface *img;
}IMAGE;

typedef struct{
SDL_Rect postxt;
TTF_Font *font ;
SDL_Surface *windtxt;
SDL_Color col;
}TEXT;
typedef struct 
{
    IMAGE img;
    int count,derec;
    float speed,acc,distance;
    int desacceleration;
    int i;
    int jumt,y;
}Perso;

void initPerso(Perso *P);
void afficherPerso(Perso P,SDL_Surface* screen);
void animePerso(Perso *P);
void deplacerPerso(Perso *P,int dt);
void saut(Perso *P);

#endif