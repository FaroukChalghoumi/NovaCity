#ifndef enigme_H_INCLUDED
#define enigme_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct 
	{
	SDL_Rect  pos ,animPos, reponse_pos;
	SDL_Surface *enigme,*animation;
	SDL_Surface *reponse, *reponse1,*t,*h;
	char question[200];
	char rep[3];	
	}enigme;

void Init_enigme(enigme *e);
int afficherEnigme(enigme *e,SDL_Surface *screen);
int genererEnigme();
void animerEnigme(enigme *e,SDL_Surface *screen);

void DelayImage (int durationInSeconds);
#endif // DS_H_INCLUDED