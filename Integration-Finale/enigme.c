#include "enigme.h"
#include "input.h" 

//-----------------------------------Fonction generer enigme-------------------------------------------
int genererEnigme()
{
int i ;
srand(time(NULL));
i=(rand()%2);
 return i;
}
//----------------------------Fonction init enigme-----------------------------------------
void Init_enigme(enigme *g ) 
{ 
char quest1[100],choix1[100],choix2[100],win[100],lose[100],rep1[3],line[500],text[150];
int i,j;
    FILE *fichier = NULL;
    fichier= fopen("text.txt","r");
    i=genererEnigme();
    if(fichier!=NULL)

    {
      
      for(j=0;j<i+1;j++)
      {
         fgets(line,500,fichier) ;
      }
     
    char * token = strtok(line, "#"); 
 
   

    strcpy(choix1,token);
    token = strtok(NULL, "#"); 

    strcpy(choix2,token);
    token = strtok(NULL, "#");

    strcpy(rep1,token);
    token = strtok(NULL, "#");
 
    strcpy(quest1,token);
     token = strtok(NULL, "#");

    strcpy(win,token);
    token = strtok(NULL, "#");
 
    strcpy(lose,token);
    token = strtok(NULL, "#");

    strcpy(text,token);
      
    }

g->pos.x=370;
g->pos.y=280;
g->animPos.x=0;
g->animPos.y=0;
g->reponse= IMG_Load(choix1);
g->reponse1= IMG_Load(choix2); 
g->enigme= IMG_Load(quest1);
g->animation= IMG_Load("Assets/chrono/chrono1.png");
strcpy(g->question,text);

g->reponse_pos.x = 0;
g->reponse_pos.y = 0;


g->t=IMG_Load(win);
g->h = IMG_Load(lose);
strcpy(g->rep,rep1);
  
}
//---------------------------------------Animate Enigme---------------------------------
void animerEnigme(enigme *e, SDL_Surface *screen)
{
    int i;
    char filename[50];   
    for (i = 1; i <= 10; i++)
    {
        sprintf(filename, "Assets/chrono/chrono%d.png", i);
        e->animation = IMG_Load(filename);
        SDL_BlitSurface(e->animation, NULL, screen, &e->animPos);
        SDL_Flip(screen);
        SDL_Delay(20);
    }  
 } 
//---------------------------Fonction afficher enigme-------------------------------------------
int afficherEnigme(enigme *e,SDL_Surface *screen)
{ 

   //declare simple variables
    bool running=true;
	int i,quit,anim = 0;
    Input I;
    SDL_Surface *questaff;
    TTF_Font *police;
    I.Return=0;
    quit = 0;
    //-----------

    int result = -1 ; 
  
   
   police = TTF_OpenFont("DelaGothicOne-Regular.ttf", 20);
   SDL_Color white={0, 0, 0};
   questaff = TTF_RenderText_Blended(police, e->question, white);
   //declare the event
	SDL_Event event;

SDL_EnableKeyRepeat(200,0);
while(running)
{

while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
        case SDL_QUIT:
        running = false;
        quit = 1;
        break;
        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_ESCAPE:
                    running = false;
                    I.Return = 1;
                break;

				case SDLK_y:
                if (strcmp(e->rep,"y")==0)
                {
                    SDL_BlitSurface(e->t, NULL, screen, &e->reponse_pos);
                    SDL_Flip(screen);
                    //return 1 ; 
                    //SDL_Delay(16);
                    DelayImage(3);
                    result = 1 ; 
                }
                else
                {
                   SDL_BlitSurface(e->h, NULL, screen, &e->reponse_pos);
                   SDL_Flip(screen);
                   //SDL_Delay(16);  
                   DelayImage(3);
                   result = 0 ;     
                }
                
                break;

            case SDLK_n:
            if (strcmp(e->rep,"n")==0)
                {
                    SDL_BlitSurface(e->t, NULL, screen, &e->reponse_pos);
                    SDL_Flip(screen);
                    //SDL_Delay(16);
                    DelayImage(3);
                    result = 1 ; 
                }
                else
                {
                   SDL_BlitSurface(e->h, NULL, screen, &e->reponse_pos);
                   SDL_Flip(screen);
                   //SDL_Delay(16);
                   DelayImage(3);
                   result = 0 ;  
                }
               
                break;
			}  
		break;

	    }
    }

if (result >= 0 ){
    SDL_Quit();
    return result;
}
    if(I.Return != 1)
      {
    while(anim == 0)
    {
         animerEnigme(e,screen);
         anim =1;
    }
     //SDL_BlitSurface(e->enigme,NULL,screen,&e->pos);
     SDL_BlitSurface(questaff, NULL, screen, &e->pos);
     SDL_BlitSurface(e->reponse,NULL,screen,&e->reponse_pos);  
     SDL_BlitSurface(e->reponse1,NULL,screen,&e->reponse_pos);  
      }

SDL_Flip(screen);
SDL_Delay(16); 
} 
if(quit == 1)
{
    SDL_Quit();
    return 0; 
}
SDL_Quit();
return result ; 


}

void DelayImage (int durationInSeconds){
     int startTime = SDL_GetTicks();
    int displayTime = durationInSeconds * 1000;  // Convert seconds to milliseconds
    int elapsedTime = 0;
    int imageVisible = 1;

    while (elapsedTime < displayTime) {
        

                int currentTime = SDL_GetTicks();
                elapsedTime = currentTime - startTime;
            }
    
}


