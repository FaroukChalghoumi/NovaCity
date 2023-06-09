#ifndef PERSO_H
#define PERSO_H
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

    Uint8 *keystate ; 

}Perso;

void initPerso(Perso *P);
void afficherPerso(Perso P,SDL_Surface* screen);
void animePerso(Perso *P);
void deplacerPerso(Perso *P,int dt);
void saut(Perso *P);
//Integration 
//void MajPerso (Perso* P , int event );
void MajPerso (Perso* P );
void UpdatePerso   (Perso* P);

void libererperso(Perso* p);



void loadStage2Perso(Perso *P );
void initPersoMultiplayer(Perso *P , char *ImagePath , SDL_Rect pos);
void MajPerso2 (Perso* P );


#endif