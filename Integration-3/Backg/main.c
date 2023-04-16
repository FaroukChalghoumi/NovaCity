#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

int main()
{
	Background B, Back [20];
	char ch[10];
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen=NULL;
	screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode: %s /n",SDL_GetError());
	}
	int running =1;
	input in;
	initBackground(&B);

	while (running)
	{	 
		animation(&B,screen);
		afficherBack (B,screen);
		getinput(&in,running);
		scrolling(&B,&in);
		SDL_Flip(screen);	
	}
	//savescore("scores.txt", 100); 
	freeBackground(&B);
	SDL_Quit();
	return 0;
}
