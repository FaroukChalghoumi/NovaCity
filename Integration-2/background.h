#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

typedef struct
{
	SDL_Surface *BgImg; 
	SDL_Rect PositionBg;
	SDL_Rect camera;
	Mix_Music *music; 
	int anim;
	SDL_Surface *anima[50]; 
	SDL_Rect posanim ;
	
	int Time ; 
}Background;

typedef struct 
{
	int left,right,up,down;
}input;

/*
typedef struct 
{
	int ;
}scoreInfo;*/


void initBackground(Background *B);
void afficherBack(Background B, SDL_Surface * screen);
void animation (Background *B,SDL_Surface * screen) ;
void animerBackground(Background *e);
void getinput(input *in,int run);
void getInput(input *in, int dirrection );///Integration
void scrolling(Background *B, input *in);
void scrollingInt(Background *B, Perso P  );
void freeBackground(Background *B);
//void saveScore(scoreInfo s, char *fileName);

#endif
