#ifndef minimap_H
#define minimap_H
#include <SDL/SDL.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"



typedef struct 
{SDL_Surface *map;
SDL_Surface  *minijoueur;
SDL_Surface *animMiniMap1[6];
SDL_Rect positionmap;
SDL_Rect positionminijoueur;

SDL_Rect PosanimMiniMap1;

int GloablFrame ; 
int numCadre ; 

}minimap;



void init_map (minimap *m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen , SDL_Rect camera);
void affichertemp (int *temps,SDL_Surface *screen,TTF_Font *police);
void liberer(minimap *m);
void annimerminimap (minimap *m  );

SDL_Color getpixel(SDL_Surface *pSurface, int x, int y);
int collisionparfaite(SDL_Surface *psurface, Perso p );
void collision(SDL_Surface *psurface, Perso *p);

#endif

