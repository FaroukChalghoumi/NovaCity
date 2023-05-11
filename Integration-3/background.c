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
	B->PositionBg.y=50;
	B->camera.x=100;
	B->camera.y=288;
	B->camera.w = 1000;
	B->camera.h = 800;
	B->BgImg= IMG_Load("ob4.png");
	B->Time = 0 ; //annimation Background
	B->posanim.x = 50;
	B->posanim.y = 100;
	B->numAnnim1 = 0;
	B->numAnnim2 = 0;
	
	B->anim =0;
	B->posanimFeu[0].x = 100 ; 
	B->posanimFeu[0].y = 500 ; 
	int i;
	char ch[20];
	for(i=0;i<6;i++)
	{
		sprintf(ch,"anim4/%d.png",i+1);
		B->anima[i] = IMG_Load(ch);
	}
char ch2[20];
	for(i=0;i<9;i++)
	{
		sprintf(ch2,"animFeu/%d.png",i+1);
		B->animFeu[i] = IMG_Load(ch2);
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
	SDL_BlitSurface(B.anima[B.numAnnim1],NULL,screen,&(B.posanim));
	SDL_BlitSurface(B.animFeu[B.numAnnim2],NULL,screen,&(B.posanimFeu[0]));
}

/*
void animation(Background *B, SDL_Surface * screen) 
{
	B->anim++;
	if(B->anim==12) 
	{
		B->anim=0;
	}
	//SDL_Delay(100);

}
*/

void Animer(Background *e){
  int frame_Speed_Annim1 = 24 ;
  int frame_Speed_Annim2 = 34 ;
  
   Uint32 currentTime = SDL_GetTicks();
  Uint32 elapsedTime = currentTime - e->Time;
  
  if (elapsedTime >= 1000 / frame_Speed_Annim1 && e->numAnnim1 < 6) {
        // Update the frame index
        e->numAnnim1++;
        
        e->Time = currentTime;

		if (e->posanim.x <= 50)
				e->anim =0;
			else if (e->posanim.x >= 200)
				e->anim = 1 ;

				if (e->anim )
					{
						e->posanim.x -=5 ;
						if (e->numAnnim1>=6)
							e->numAnnim1 = 3 ; 
					} 
					else 
					{
						e->posanim.x +=5 ;
						if (e->numAnnim1>=3)
							e->numAnnim1 = 0 ; 
							
					} 
		
    }

	  if (elapsedTime >= 1000 / frame_Speed_Annim1 && e->numAnnim2 < 10) {
        // Update the frame index
        e->numAnnim2++;
        
        e->Time = currentTime;

		if (e->numAnnim2>=9)
			e->numAnnim2 = 0 ; 
		
    }
    
    
     
  
 
}


void animerBackground(Background *e , Perso P){
	Animer(e);
	//printf("\n pos Feu = %d",e->posanimFeu[0].y);
	if(P.jumt==1)
	e->posanimFeu[0].y+=(P.i)*(P.i)/900;
if(P.derec==1)
	{
		e->posanimFeu[0].y = 500 ; 
		e->posanimFeu[0].x -= ((int)((P.distance)) +5);
	}
	else if (P.derec==2){
		e->posanimFeu[0].y = 500 ; 
		e->posanimFeu[0].x += ((int)((P.distance)) +5);
	}

	if (e->posanimFeu[0].x<=0)
	{
		e->posanimFeu[0].y = 500 ; 
		e->posanimFeu[0].x = e->camera.w +100 ; 
	}
	
}




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
	{	B->camera.y-=30;
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
    Mix_FreeMusic(B->music);
    for (int i = 0; i < 6; i++) {
        SDL_FreeSurface(B->anima[i]);
    }

	for (int i = 0; i < 9; i++) {
        SDL_FreeSurface(B->animFeu[i]);
    }
    Mix_CloseAudio();
    SDL_Quit();
}


void scrollingInt(Background *B, Perso P   )
{
	printf("\ncamera X = %d",B->camera.x);
	if(P.jumt==1)
	B->camera.y=0.06*(P.i)*(P.i)-150+288;

	if(P.derec==1){
		if(P.jumt==1)
        B->camera.x+=((int)((P.distance)) +13);

		B->camera.x+=((int)((P.distance)) +10);
		//e->pos_entite.x -=10 ; 
    }
    else if(P.derec==2){
		if(P.jumt==1)
		B->camera.x-=((int)((P.distance))+13);

        B->camera.x-=((int)((P.distance))+10);
    }
	

	if (B->camera.x<= 0) 
		{
			B->camera.x=0;
		}

		if (B-> camera.y >= 200)
		{
			B->camera.y=200;
		}
		if(B->camera.x >=8800)
		{
			B->camera.x=8800;
			
		}
		if (B->camera.x<= 0) 
		{
			B->camera.x=0;
		}
	//B->camera.y+=P.distance;
}



