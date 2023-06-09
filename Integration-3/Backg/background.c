#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

void initBackground(Background *B)
{
	
	B->PositionBg.x=0;
	B->PositionBg.y=0;
	B->camera.x=0;
	B->camera.y=200;
	B->camera.w = 1200;
	B->camera.h = 600;
	B->BgImg= IMG_Load("backg.jpg");
	B->Time = 0 ; //annimation Background
	int i;
	char ch[20];
	for(i=0;i<12;i++)
	{
		sprintf(ch,"%d.jpg",i);
		B->anima[i] = IMG_Load(ch);
	}

	if(SDL_Init(SDL_INIT_AUDIO)==-1)
	{
		printf("SDL_Init: %s\n", SDL_GetError());
	}
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
	}
	B->music=Mix_LoadMUS("musique.mp3");
	Mix_PlayMusic(B->music, -1);
	Mix_AllocateChannels(10);
	Mix_VolumeMusic(MIX_MAX_VOLUME);

}

void afficherBack (Background B,SDL_Surface *screen)
{
	SDL_BlitSurface(B.BgImg,&(B.camera),screen,&(B.PositionBg));
	SDL_BlitSurface(B.anima[B.anim],&B.camera,screen,&(B.PositionBg));
}

void animation(Background *B, SDL_Surface * screen) 
{
	B->anim++;
	if(B->anim==12) 
	{
		B->anim=0;
	}
	//SDL_Delay(100);

}

/*
void animerBackground(Background *e){
  int frame_Speed_Annim1 = 24 ;
  int frame_Speed_Annim2 = 34 ;
  
   Uint32 currentTime = SDL_GetTicks();
  Uint32 elapsedTime = currentTime - e->Time;
  
  if (elapsedTime >= 1000 / frame_Speed_Annim1 && e->anim < 12) {
        // Update the frame index
        e->anim++;
        
        e->Time = currentTime;
    }
    
    if (e->anim >= 12) {
        
        e->numAnnim1 = 0;
    }
     
  
 
}
*/

void getinput(input *in, int run)
{
	run =1;
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{	case SDL_QUIT:
		run =0;
                exit(0);
           	 break;
		case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
			case SDLK_ESCAPE: 
			run =0;
                        exit(0);
                    	break;
                    	case SDLK_UP:
			in->up=1;
			break;
			case SDLK_DOWN:
			in->down=1;
			break;
			case SDLK_LEFT:
			in->left=1;
			break;
			case SDLK_RIGHT:
			in->right=1;
			break;
			default:
			break;
									
		}
		break;
		case SDL_KEYUP:
		switch(event.key.keysym.sym)
		{
			case SDLK_LEFT:
			in->left=0;
			break;
			case SDLK_UP:
			in->up=0;
			break;
			case SDLK_DOWN:
			in->down=0;
			break;
			case SDLK_RIGHT:
			in->right=0;
			break;
			default:
			break;						
		}
		break;
	}
}

void scrolling(Background *B, input *in)
{
	if(in->right==1)
	{
		B->camera.x+=20;
		if(B->camera.x >=8800)
		{
			B->camera.x=8800;
			
		}
	}
	else if(in->left==1)
	{
		B->camera.x-=20;
		if (B->camera.x<= 0) 
		{
			B->camera.x=0;
		}
	}
	if(in->up==1)
	{	B->camera.y-=20;
		if (B-> camera.y <= 0)
		{
			B->camera.y=0;
		}
	}
	else if(in->down==1)
	{
		B->camera.y+=20;
		if (B-> camera.y >= 200)
		{
			B->camera.y=200;
		}
	}
}
/*
void saveScore(scoreInfo s, char *fichier.txt){
    FILE* myfile=NULL;
    myfile=fopen(fichier.txt,"a+");
    if(myfile!=NULL){
        fprintf(myfile,"%s %d %d\n",s.playerName,s.temps,s.score);
    }
    fclose(myfile);
}
*/
void freeBackground(Background *B)
{
	SDL_FreeSurface(B->BgImg);
	Mix_FreeMusic (B->music);
}
