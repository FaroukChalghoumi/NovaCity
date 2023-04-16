
#include "minimap.h"

void init_map (minimap *m)
{ 
	m -> map = IMG_Load("minimap2.png");
	m->positionmap.x =250;
  	m->positionmap.y =115;
  
  m-> minijoueur = IMG_Load("playermap.png");
  m->positionminijoueur.x =250;
  m->positionminijoueur.y =100;

  m->collisionPP=IMG_Load("ob.png");
  m->PoscollisionPP.x = 0; 
  m->PoscollisionPP.y = 0 ;

}

void MAJMinimap(SDL_Rect posJoueur,  minimap *m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
  posJoueurABS.x = 0;
  posJoueurABS.y = 0;
  posJoueurABS.x = posJoueur.x + camera.x;
  posJoueurABS.y = posJoueur.y + camera.y;
  m->positionminijoueur.x=(posJoueurABS.x * redimensionnement/100)+250;
  m->positionminijoueur.y=(posJoueurABS.y * redimensionnement/100)+95;
}


void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  //SDL_BlitSurface(m.collisionPP, NULL, screen , &m.PoscollisionPP );
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
	
}


void affichertemp (int *temps,SDL_Surface *screen,TTF_Font *police)
{
SDL_Surface *chrono = NULL;
SDL_Rect positionChrono;
SDL_Color couleur = {0,0,0};

int min=0,sec=0;
char texteChrono [10] = "";

positionChrono.x = 40;
positionChrono.y = 50;
(*temps)=SDL_GetTicks();
(*temps)/=1000;
min=((*temps)/60);
sec=(*temps) - (60*min);

sprintf(texteChrono,"%02d:%02d",min,sec);

chrono = TTF_RenderText_Solid(police,texteChrono,couleur);
SDL_BlitSurface(chrono,NULL,screen,&positionChrono);
}



SDL_Color getpixel(SDL_Surface *pSurface, int x, int y)
{
	SDL_Color color;
	Uint32 col = 0;
	char *pPosition = (char *)pSurface->pixels;
	pPosition += (pSurface->pitch * y);
	pPosition += (pSurface->format->BytesPerPixel * x);
	memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
	SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
int collisionparfaite(SDL_Surface *psurface, Perso p)
{
	int tabx[7], taby[7], i;
	SDL_Color color1, color , color2;

	color1.r = 32; // RED 
	color1.g = 35; // GREEN
	color1.b = 38; // BLUE

	color2.r = 238; // RED 
	color2.g = 33; // GREEN
	color2.b = 37; // BLUE
	
	//capteur 1 : 
	tabx[0] = p.img.pos1.x -20;
	taby[0] = p.img.pos1.y -20;

	//capteur 2 : 
	tabx[1] = (p.img.pos1.x) + ((p.img.pos2.w) / 2) -20;
	taby[1] = p.img.pos1.y-20;

	tabx[2] = (p.img.pos1.x + p.img.pos2.w)-20;
	taby[2] = p.img.pos1.y-20;

	tabx[3] = p.img.pos1.x-20;
	taby[3] = (p.img.pos1.y) + ((p.img.pos2.h) / 2) -20;

	tabx[4] = p.img.pos1.x;
	taby[4] = (p.img.pos1.y + p.img.pos2.h)-20;

	tabx[5] = (p.img.pos1.x) + ((p.img.pos2.w) / 2);
	taby[5] = (p.img.pos1.y + p.img.pos2.h)-20;

	tabx[6] = (p.img.pos1.x + p.img.pos2.w)-20;
	taby[6] = (p.img.pos1.y + p.img.pos2.h);

	tabx[7] = (p.img.pos1.x + p.img.pos2.w)-20;
	taby[7] = (p.img.pos1.y) + ((p.img.pos2.h) / 2);
	
	
	
	
	
	
	//color = getpixel(psurface, tabx[6], taby[6]);
		//printf("\nred = %d , green = %d , blue = %d" ,color.r,color.b,color.g);

	for (i = 0; i < 8; i++)
	{
		color = getpixel(psurface, tabx[i], taby[i]);
		//printf("\n tab [%d] = red = %d , green = %d , blue = %d" ,i,color.r,color.g,color.b);
		
		if ((color.r == color1.r && color.b == color1.b && color.g == color1.g ) 
				|| (color.r == color2.r && color.b == color2.b && color.g == color2.g ) )
		{
			//printf("\n tab [%d] = red = %d , green = %d , blue = %d" ,i,color.r,color.g,color.b);
			//printf("\nhello");
			return i;
		}
	}
	return 10;
}

void collision(SDL_Surface *psurface, Perso *p)
{
	int i;
	i = collisionparfaite(psurface, *p);
	//printf("\n colision = %d",i);

	switch (i)
	{
	case 0:
		p->img.pos1.y = p->img.pos1.y + 5;
		break;
	case 1:
		p->img.pos1.y = p->img.pos1.y + 5;
		break;
	case 2:
		p->img.pos1.y = p->img.pos1.y + 5;
		break;
	case 3:
		p->img.pos1.x = p->img.pos1.x + 5;
		break;
	case 4:
		p->img.pos1.y = p->img.pos1.y - 5;
		break;
	case 5:
		//p->img.pos1.y = p->img.pos1.y - 5;
		p->img.pos1.y = p->img.pos1.y - 10;
		break;
	case 6:
		p->img.pos1.x = p->img.pos1.x - 5;
		
		break;
	case 7:
		p->img.pos1.x = p->img.pos1.x - 5;
		break;

		case 10 : 
			//p->img.pos1.x=300;
    		p->img.pos1.y=450;
			break;
	}
}

void liberer(minimap *m)
{
SDL_FreeSurface(m->minijoueur);
SDL_FreeSurface(m->map);
}
