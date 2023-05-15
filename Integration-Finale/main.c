#include "minimap.h"
#include "background.h"
#include "entite.h"
#include "tic.h"
#include "ENG.h"
#include "menu.h"

int main()
{
    //SDL init 
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    //Police Init 
    TTF_Font *police=NULL;
    SDL_Color Color={255,255,255};
    police=TTF_OpenFont("pol.ttf",50);

    // Init Fenetre 
    SDL_Surface *screen ;
    screen=SDL_SetVideoMode (1000,666,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    // Init personnage  
    Perso personnage ; 
    initPerso(&personnage);
    int start=0,end=0,dt; 
    
    // Init MINIMAP 
    minimap m;
    SDL_Rect camera,backgpos;
    int temps;
    init_map(&m);
    
    //Init Background
    Background B;
    initBackground(&B);
    Background B2;
    initBackground(&B2);

    

    //Init Entite 
    entite e;
	initialiser_entite (&e,"voiture_test.png") ;

    entite ennemie1;
    initialiser_entite_EnnemieRace(&ennemie1,"obstacle1.png");
    int nbEnnemie = 0 ; 

    entite collectPower ; 
    initialiser_entite_EnnemieRace(&collectPower,"antivirus.png");
    int nbPower = 0 ; 


int multiplayer = -1 ; 


SDL_Surface *test =  IMG_Load("health2.png");
SDL_Rect posTest ; 

posTest.x = 200 ; 
posTest.y = 100 ; 

    SDL_Event event;
    int continuer=1;
    int time = 0 ;

    int stage = 1 ; 
 multiplayer = menuAlll() ;
 Perso P1;
Perso P2;
    SDL_Rect pos ; 
    pos.x = 50;
    pos.y = 500; 
    
    initPersoMultiplayer(&P1,"spritesheet_voiture_rouge.png",pos);
    
    pos.x = 50+490;
    initPersoMultiplayer(&P2,"spritesheet_car.png",pos);

if (multiplayer){
    B.camera.w /= 2 ;
    B2.camera.w /= 2 ;
    B2.PositionBg.x = 505; 
}
 screen=SDL_SetVideoMode (1000,666,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  /*INIT ARDUINOOOOOOO;
   char buffer[100];
   int i;
   int fd=serialport_init("/dev/ttyUSB0",9600);
   if(fd==-1) return -1;*/
	
    //SDL_EnableKeyRepeat(100,10);
    
    while(continuer)
    {   //printf("\ny= %f",personnage.distance);
       // multiplayer = AllMenu(&menu,screen,event);
       // multiplayer = menuAlll() ;
      // screen=SDL_SetVideoMode (1000,666,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
       
    if (multiplayer == 0)
    {
                personnage.keystate = SDL_GetKeyState(NULL);
                start=SDL_GetTicks();
                dt=start-end;
                if(dt>60){
                //AFFICHAGE 
                afficherBack (B,screen);
                afficherminimap(m,screen , B.camera);
                annimerminimap (&m  );
                afficherPerso(personnage,screen);
                if (stage == 1)
                afficher_entite(&e ,screen);
                affichertemp(&temps,screen,police);
                // SDL_BlitSurface(test,NULL,screen,&posTest);


/*
                //  lecture d'une ligne
                serialport_read_until(fd, buffer, '\r', 99, 10000);

                // suppression de la fin de ligne
                for (i=0 ; buffer[i]!='\r' && i<100 ; i++);
                buffer[i] = 0;

                // écriture du résultat
                printf("%s", buffer);

                if (strcmp(buffer,"1")){
                    personnage.derec=1;
                    deplacerPerso(&personnage,5); 
                    scrollingInt(&B,personnage);
                }
*/

                
                SDL_PollEvent(&event);
                

                switch (event.type) 
                {
                    
                    case SDL_QUIT:
                        continuer = 0;
                        break;

                /* case SDL_KEYDOWN:
                        if(event.key.keysym.sym==SDLK_RIGHT){
                                MajPerso(&personnage,1);
                                

                            }
                            else if(event.key.keysym.sym==SDLK_LEFT){
                                MajPerso(&personnage,2);
                                
                            }
                            else if(event.key.keysym.sym==SDLK_SPACE){
                                MajPerso(&personnage,3);
                                
                                //Mix_PlayChannel(0,jump,0);
                            }
                            else if(event.key.keysym.sym==SDLK_ESCAPE){
                                continuer = 0;
                            }
                            break;

                        case SDL_KEYUP:
                            MajPerso(&personnage,4);
                            break;*/
                        }
                        MajPerso(&personnage);
                        
                    UpdatePerso(&personnage ) ; 
                    end=start;
                    if (start > 100000 ) 
                        start = end = 0 ; 
                    
                if (stage == 1)
                {
                    PersoRUN(&personnage,&B,&e);
                    update_entite(&e,&personnage);
                    mvt_entiteInt(&e,&personnage);
                }
                

                    deplacerPerso(&personnage,5); 
                    scrollingInt(&B,personnage);
                    
                    animerBackground(&B,personnage);

                    EnnemieRace (&personnage,&ennemie1,&B,&nbEnnemie);
                    PowerCollect(&personnage,&collectPower,&B,&nbPower,stage);


                    if (detect_collision(&personnage,&ennemie1) && personnage.jumt ==0 ){
                        
                        if (B.camera.x >= 5000 && stage == 1 )
                        {
                            int x  = enigmeFuul();
                            if (x)
                            {
                                loadStage2Background(&B);
                                loadStage2MiniMap(&m);
                                loadStage2Perso(&personnage);
                            }
                            else continuer = 0 ; 
                            screen=SDL_SetVideoMode (1000,666,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

                            nbEnnemie = 0 ; 
                            nbPower = 0 ; 
                            ennemie1.pos_entite.x = 0; 
                            collectPower.pos_entite.x = 0 ; 
                            stage ++ ;
                        }
                        else {
                                int x  = TicToeAll();
                            //int x  = enigmeFuul();
                                printf("\nx= %d",x);
                                    screen=SDL_SetVideoMode (1000,666,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
                                    ennemie1.pos_entite.x = 0 ; 
                                    personnage.img.pos1.x = 150 ;
                                    e.pos_entite.x = 200; 
                                    if (nbPower>0)
                                    nbPower--;
                        }
                                            
                        

                    }
                    if (detect_collision(&personnage,&collectPower))
                    {
                        nbPower++;
                        collectPower.pos_entite.x = 0 ; 
                    }

                    if (stage >=2){
                        afficherVirus(nbPower,B,screen);
                    }
                    //afficherVirus(nbPower,B,screen);


                    
                        
                    
                    //
                    //printf("\npos ennemie = %d",ennemie1.pos_entite.x);
                }
                

        afficher_entite(&ennemie1 ,screen);
        afficher_entite(&collectPower ,screen);
                animePerso(&personnage);

                MAJMinimap(personnage.img.pos1,  &m, B.camera, 4);

                if (collisionparfaite(screen,personnage) != 10)
                {

                }
                    //printf("\nhello");
                    
                //collision(screen,&personnage);
                
                //animation(&B,screen);
                
                SDL_Flip(screen);
                //printf("\ncontinuer= %d",continuer);
            }

            else if (multiplayer == 1) {
                start=SDL_GetTicks();
                dt=start-end;
                if(dt>60){
                       P1.keystate = SDL_GetKeyState(NULL);
                       P2.keystate = SDL_GetKeyState(NULL);

                afficherBack (B,screen);
                afficherBack (B2,screen);
                        afficherPerso(P1,screen);
                        afficherPerso(P2,screen);

                         SDL_PollEvent(&event);
                

                    switch (event.type) 
                    {
                        
                        case SDL_QUIT:
                            continuer = 0;
                            break;
                    }
                    
                    end=start;
                    if (start > 100000 ) 
                        start = end = 0 ; 

            MajPerso(&P1);
                    MajPerso2(&P2);
                    UpdatePerso(&P1 ) ; 
                    UpdatePerso(&P2 ) ; 
                    deplacerPerso(&P1,0); 
                         deplacerPerso(&P2,0);
                         scrollingInt(&B,P1);
                         scrollingInt(&B2,P2);

                }
                
                 animePerso(&P1);
                 animePerso(&P2);
                 SDL_Flip(screen);


            }
        //printf("\nmulti= %d",multiplayer);
}

printf("\ncontinuer= %d",continuer);
liberer(&m);
libererperso(&personnage);
freeBackground(&B);
SDL_Quit();
TTF_Quit();
    return 0 ; 

}
