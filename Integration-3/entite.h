#ifndef entite_H_INCLUDED
#define entite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include<time.h>
#include "perso.h"
#include "background.h"

typedef struct 
{
	SDL_Surface *entite ;
	SDL_Rect pos_entite;
	SDL_Rect anim_entite[70];
	int frame_entite;
	int direction;
	int maxi_up,maxi_down;
	int count;
	
}entite ;
/*
typedef struct
{
	SDL_Surface *perso; 
	SDL_Rect perso_pos ;
}personnage ;*/

	void init_tab_anim_entite(SDL_Rect* clip,entite *e); 
	void initialiser_entite(entite *e , char *imagePath );
	void initialiser_entite_EnnemieRace(entite *e , char *imagePath );
	void afficher_entite(entite * e , SDL_Surface *screen);
	void anim(entite *e);
	void mvt_entite(entite *e,Perso *p);
	void update_entite(entite *e,Perso *p);
	
	int detect_collision(Perso *p, entite* e);
	int gestion(entite* e);

	void mvt_entiteInt(entite *e,Perso *p);

	void PersoRUN (Perso *P , Background *b , entite *e);

	void EnnemieRace (Perso *P , entite *e , Background *b ,int *nbEnnemie);

void loadStage2Entite(entite *e ,int stage  );
void PowerCollect (Perso *P , entite *e , Background *b ,int *nbEnnemie);

#endif 
