#include "entite.h"

int 
	nb_frame=12 ,
	entite_h=195/2,
	entite_w=135/2,
	entite_y=0,
	pos_init_x=50,
	pos_init_y=570,
	entite_x=0;



void init_tab_anim_entite(SDL_Rect *clip,entite *e)
{	
	for (int j=0;j<nb_frame; j++)
	{
		clip[j].h=entite_h;
		clip[j].w=entite_w;
		clip[j].x = j*entite_w;
		clip[j].y = 0;
        }  
}

void initialiser_entite(entite *e)
{
	e->entite = IMG_Load("voiture_test.png");
	e->pos_entite.x = pos_init_x;
	e->pos_entite.y = pos_init_y;
	init_tab_anim_entite(e->anim_entite,e);
	e->frame_entite=0;
	e->direction=0;  
	
}


void afficher_entite(entite * e , SDL_Surface *screen)
{
	//SDL_BlitSurface(e->entite,&e->anim_entite[e->frame_entite], screen, &e->pos_entite);
	SDL_BlitSurface(e->entite,NULL, screen, &e->pos_entite);
}

void mvt_entiteInt(entite *e,Perso *p)
{
	if ( p->derec )
		pos_init_x--;

}
void mvt_entite(entite *e,Perso *p )
{
	int diff_x=e->pos_entite.x-p->img.pos1.x;	
  	//int diff_y=p->img.pos1.y-e->pos_entite.y;

	/*if (diff_x<350 && diff_x>50 )
	{
		e->pos_entite.x+=1;

		if(diff_y<350 && diff_y>50)
	{
		e->pos_entite.y+=3;
	}
	else if (diff_y >350)
	{
		e->pos_entite.y = pos_init_y;
	}


		if (diff_y >-350 && diff_y < 0 )
	{
		e->pos_entite.y-=3;
	} 

	else if (diff_y < -350)
	{
		e->pos_entite.y = pos_init_y;
	}


  	}
	else if (diff_x > 350 )
	{
		e->pos_entite.x += 1;
	}

	if (diff_x >-350 && diff_x < 0)
	{
  		e->pos_entite.x+=2;
	}
		if(diff_y<350 && diff_y>50)
	{
		e->pos_entite.y+=3;
	}
	else if (diff_y >350)
	{
		e->pos_entite.y = pos_init_y;
	}


		if (diff_y >-350 && diff_y < 0 )
	{
		e->pos_entite.y-=3;
	} 

	else if (diff_y < -350)
	{
		e->pos_entite.y = pos_init_y;
	}

  	}
	else if (diff_x <-350 )
	{
		e->pos_entite.x +=1 ;
	}
	
	*/


if (diff_x <= 0)
	e->pos_entite.x +=2;
	else e->pos_entite.x +=1 ;

	
	

}


void anim(entite *e)
{   
	e->count ++ ; 

	if (e->count >=100)
	{
		e->count = 0 ; 
		if (e->frame_entite >=0 && e->frame_entite <(nb_frame-1)) {
 		e->frame_entite++;
		}
		if ( e->frame_entite ==(nb_frame-1)) {
		e->frame_entite=0;
		}
	}

	
}


void update_entite(entite *e,Perso *p)
{	
	if (e->pos_entite.x!=0&&e->pos_entite.y!=0)
	{ 	
		//p->count++;
    
		mvt_entite(e,p);
		anim(e);
	}	
}



int detect_collision(Perso *p, entite* e)
{

	if ((p->img.pos1.x + p->img.pos1. w< e->pos_entite. x) || (p->img.pos1.x> e->pos_entite. x + e->pos_entite. w) ||
		(p->img.pos1.y + p->img.pos1.h< e->pos_entite. y) || (p->img.pos1.y> e->pos_entite. y + e->pos_entite. h ))
		return 0;
	else 
		return 1;
}

int gestion(entite* e)
{ 	
	return 0;
}



/*

void initialiser_perso(personnage *p)
{
	p->perso= IMG_Load("perso1.png");
	p->perso_pos.x = 100;
	p->perso_pos.y = 100;
	p->perso_pos.h = 281;
	p->perso_pos.w = 217;  
}

void afficher_perso(personnage * p , SDL_Surface *screen)
{
	SDL_BlitSurface(p->perso,NULL, screen, &p->perso_pos);
}*/



void PersoRUN (Perso *P , Background *b , entite *e){
	
	if (P->derec==1&&P->keystate[SDLK_SPACE]){
		e->pos_entite.x -=3;
		b->camera.x += 4 ; 
	}

	
	
}






