#include "menu.h"
void InitAnimationMenu(menu *m)
{
    	m->FrameNumber =0;
	m->PosAnimationMenu.x = 0 ; 
	m->PosAnimationMenu.y = 0 ; 
	int i;
	char ch[20];
	for(i=0;i<19;i++)
	{
		sprintf(ch,"animNova/%d.jpg",i+1);
		m->AnimationMenu[i] = IMG_Load(ch);
	}
    m->game = m->menuPlay = m->settings = m->SingleMulti = m->NewLoad = 0;
    m->Time = 0 ; 
    m->FrameNumber=0;
}

void InitMenuInitial(Play *playGame) {
    // Load play background image
    playGame->PlayBackground = IMG_Load("back.jpg");
    if (playGame->PlayBackground == NULL) {
        printf("Failed to load play background image.\n");
        exit(1);
    }

    // Load play button image
    playGame->ButtonPlay = IMG_Load("PLAY.png");
    if (playGame->ButtonPlay == NULL) {
        printf("Failed to load play button image.\n");
        exit(1);
    }

    // Load setting button image
    playGame->ButtonSetting = IMG_Load("SETTINGS.png");
    if (playGame->ButtonSetting == NULL) {
        printf("Failed to load setting button image.\n");
        exit(1);
    }

    // Load quit button image
    playGame->ButtonQuit = IMG_Load("EXIT1.png");
    if (playGame->ButtonQuit == NULL) {
        printf("Failed to load quit button image.\n");
        exit(1);
    }


        // Load play button image
    playGame->ButtonActivePlay = IMG_Load("PP.png");
    if (playGame->ButtonActivePlay == NULL) {
        printf("Failed to load play button image.\n");
        exit(1);
    }

    // Load setting button image
    playGame->ButtonActiveSetting = IMG_Load("SETTINGS1.png");
    if (playGame->ButtonActiveSetting == NULL) {
        printf("Failed to load setting button image.\n");
        exit(1);
    }

    // Load quit button image
    playGame->ButtonActiveQuit = IMG_Load("EXIT.png");
    if (playGame->ButtonActiveQuit == NULL) {
        printf("Failed to load quit button image.\n");
        exit(1);
    }

    // Set positions
    playGame->PosPlayBackground.x = 0;
    playGame->PosPlayBackground.y = 0;

    playGame->PosButtonPlay.x = 250;
    playGame->PosButtonPlay.y = 200;

    playGame->PosButtonSetting.x = 250;
    playGame->PosButtonSetting.y = 300;

    playGame->PosButtonQuit.x = 250;
    playGame->PosButtonQuit.y = 400;

    playGame->MouseMotion = 0 ;
}

void AfficherMenuInitial(Play playGame, SDL_Surface* screen)
{
    if (playGame.MouseMotion == 0){
    // Blit the background image onto the screen
    SDL_BlitSurface(playGame.PlayBackground, NULL, screen, &playGame.PosPlayBackground);

    // Blit the "play" button onto the screen
    SDL_BlitSurface(playGame.ButtonPlay, NULL, screen, &playGame.PosButtonPlay);

    // Blit the "settings" button onto the screen
    SDL_BlitSurface(playGame.ButtonSetting, NULL, screen, &playGame.PosButtonSetting);

    // Blit the "quit" button onto the screen
    SDL_BlitSurface(playGame.ButtonQuit, NULL, screen, &playGame.PosButtonQuit);

    }
    else if (playGame.MouseMotion == 1)
    {
        // Blit the background image onto the screen
    SDL_BlitSurface(playGame.PlayBackground, NULL, screen, &playGame.PosPlayBackground);

    // Blit the "play" button onto the screen
    SDL_BlitSurface(playGame.ButtonActivePlay, NULL, screen, &playGame.PosButtonPlay);

    // Blit the "settings" button onto the screen
    SDL_BlitSurface(playGame.ButtonSetting, NULL, screen, &playGame.PosButtonSetting);

    // Blit the "quit" button onto the screen
    SDL_BlitSurface(playGame.ButtonQuit, NULL, screen, &playGame.PosButtonQuit);
    }

        else if (playGame.MouseMotion == 2)
    {
        // Blit the background image onto the screen
    SDL_BlitSurface(playGame.PlayBackground, NULL, screen, &playGame.PosPlayBackground);

    // Blit the "play" button onto the screen
    SDL_BlitSurface(playGame.ButtonPlay, NULL, screen, &playGame.PosButtonPlay);

    // Blit the "settings" button onto the screen
    SDL_BlitSurface(playGame.ButtonActiveSetting, NULL, screen, &playGame.PosButtonSetting);

    // Blit the "quit" button onto the screen
    SDL_BlitSurface(playGame.ButtonQuit, NULL, screen, &playGame.PosButtonQuit);
    }


        else if (playGame.MouseMotion == 3)
    {
        // Blit the background image onto the screen
    SDL_BlitSurface(playGame.PlayBackground, NULL, screen, &playGame.PosPlayBackground);

    // Blit the "play" button onto the screen
    SDL_BlitSurface(playGame.ButtonPlay, NULL, screen, &playGame.PosButtonPlay);

    // Blit the "settings" button onto the screen
    SDL_BlitSurface(playGame.ButtonSetting, NULL, screen, &playGame.PosButtonSetting);

    // Blit the "quit" button onto the screen
    SDL_BlitSurface(playGame.ButtonActiveQuit, NULL, screen, &playGame.PosButtonQuit);
    }

   
}

void HandleMouseMotion(SDL_Event event, Play *playGame)
{
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);

    if (x > playGame->PosButtonPlay.x && x < playGame->PosButtonPlay.x + playGame->ButtonPlay->w &&
        y > playGame->PosButtonPlay.y && y < playGame->PosButtonPlay.y + playGame->ButtonPlay->h) {
        // Mouse is over the "Play" button
        // Perform actions here
        playGame->MouseMotion =1;
    } else if (x > playGame->PosButtonSetting.x && x < playGame->PosButtonSetting.x + playGame->ButtonSetting->w &&
               y > playGame->PosButtonSetting.y && y < playGame->PosButtonSetting.y + playGame->ButtonSetting->h) {
        // Mouse is over the "Settings" button
        // Perform actions here
         playGame->MouseMotion =2;
    } else if (x > playGame->PosButtonQuit.x && x < playGame->PosButtonQuit.x + playGame->ButtonQuit->w &&
               y > playGame->PosButtonQuit.y && y < playGame->PosButtonQuit.y + playGame->ButtonQuit->h) {
        // Mouse is over the "Quit" button
        // Perform actions here
         playGame->MouseMotion =3;
    }
    else {
        playGame->MouseMotion =0;
    }
}


void FreePlay(Play* playGame) {
    SDL_FreeSurface(playGame->PlayBackground);
    SDL_FreeSurface(playGame->ButtonPlay);
    SDL_FreeSurface(playGame->ButtonSetting);
    SDL_FreeSurface(playGame->ButtonQuit);
    //free(playGame);
}










void InitSingleMulti(SingleMulti *SingleMultiplayer) {
    // Load images using IMG_Load
    SingleMultiplayer->SingleMultiBackground = IMG_Load("back.jpg");
    SingleMultiplayer->ButtonSingle = IMG_Load("PLAY.png");
    SingleMultiplayer->ButtonMulti = IMG_Load("EXIT1.png");
    SingleMultiplayer->ButtonActiveSingle = IMG_Load("PP.png");
    SingleMultiplayer->ButtonActiveMulti = IMG_Load("EXIT.png");

    // Set positions for images
    SingleMultiplayer->PosSingleMultiBackground.x = 0;
    SingleMultiplayer->PosSingleMultiBackground.y = 0;

    SingleMultiplayer->PosButtonSingle.x = 200;
    SingleMultiplayer->PosButtonSingle.y = 200;

    SingleMultiplayer->PosButtonMulti.x = 200;
    SingleMultiplayer->PosButtonMulti.y = 400;
}



void HandleMouseMotionSingleMulti(SDL_Event event, SingleMulti *singleMultiPlayer)
{
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);

    if (x > singleMultiPlayer->PosButtonSingle.x && x < singleMultiPlayer->PosButtonSingle.x + singleMultiPlayer->ButtonSingle->w &&
        y > singleMultiPlayer->PosButtonSingle.y && y < singleMultiPlayer->PosButtonSingle.y + singleMultiPlayer->ButtonSingle->h) {
        // Mouse is over the "Single Player" button
        // Perform actions here
        singleMultiPlayer->MouseMotion = 1;
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            printf("im here");
        }
    } else if (x > singleMultiPlayer->PosButtonMulti.x && x < singleMultiPlayer->PosButtonMulti.x + singleMultiPlayer->ButtonMulti->w &&
               y > singleMultiPlayer->PosButtonMulti.y && y < singleMultiPlayer->PosButtonMulti.y + singleMultiPlayer->ButtonMulti->h) {
        // Mouse is over the "Multi Player" button
        // Perform actions here
        singleMultiPlayer->MouseMotion = 2;
    } else {
        singleMultiPlayer->MouseMotion = 0;
    }
}


void AfficherSingleMulti(SingleMulti SingleMultiplayer,SDL_Surface* screen) {
    // Blit images onto the screen surface
    if (SingleMultiplayer.MouseMotion == 0)
    {
        SDL_BlitSurface(SingleMultiplayer.SingleMultiBackground, NULL, screen, &SingleMultiplayer.PosSingleMultiBackground);

        SDL_BlitSurface(SingleMultiplayer.ButtonSingle, NULL, screen, &SingleMultiplayer.PosButtonSingle);

        SDL_BlitSurface(SingleMultiplayer.ButtonMulti, NULL, screen, &SingleMultiplayer.PosButtonMulti);
    }
    else if (SingleMultiplayer.MouseMotion == 1)
    {
        SDL_BlitSurface(SingleMultiplayer.SingleMultiBackground, NULL, screen, &SingleMultiplayer.PosSingleMultiBackground);

        SDL_BlitSurface(SingleMultiplayer.ButtonActiveSingle, NULL, screen, &SingleMultiplayer.PosButtonSingle);

        SDL_BlitSurface(SingleMultiplayer.ButtonMulti, NULL, screen, &SingleMultiplayer.PosButtonMulti);
    }
    else if (SingleMultiplayer.MouseMotion == 2)
    {
        SDL_BlitSurface(SingleMultiplayer.SingleMultiBackground, NULL, screen, &SingleMultiplayer.PosSingleMultiBackground);

        SDL_BlitSurface(SingleMultiplayer.ButtonSingle, NULL, screen, &SingleMultiplayer.PosButtonSingle);

        SDL_BlitSurface(SingleMultiplayer.ButtonActiveMulti, NULL, screen, &SingleMultiplayer.PosButtonMulti);
    }
    


}

void FreeSingleMulti(SingleMulti *SingleMultiplayer) {
    // Free loaded images
    SDL_FreeSurface(SingleMultiplayer->SingleMultiBackground);
    SDL_FreeSurface(SingleMultiplayer->ButtonSingle);
    SDL_FreeSurface(SingleMultiplayer->ButtonMulti);
    SDL_FreeSurface(SingleMultiplayer->ButtonActiveSingle);
    SDL_FreeSurface(SingleMultiplayer->ButtonActiveMulti);

}


void Animation(menu *m){
  int frame_Speed_Annim= 24 ;
  //int frame_Speed_Annim2 = 34 ;
  
   Uint32 currentTime = SDL_GetTicks();
  Uint32 elapsedTime = currentTime - m->Time;
  
  if (elapsedTime >= 1000 / frame_Speed_Annim && m->FrameNumber < 19) {
        // Update the frame index
        m->FrameNumber++;
        
        m->Time = currentTime;


		 
							
					
		
    }
    /*else  if (m->FrameNumber>=19)
			m->FrameNumber = 0 ;*/

	  
}

void AfficherAnimation (menu m , SDL_Surface *screen)
{
    printf("\nFrame = %d ",m.FrameNumber);
        SDL_BlitSurface(m.AnimationMenu[0], NULL, screen, &m.PosAnimationMenu);

    
    
}


void freeAnimation(menu* m) {
    for(int i = 0; i < 19; i++) {
        SDL_FreeSurface(m->AnimationMenu[i]);
        m->AnimationMenu[i] = NULL;
    }
}



void displayAnimation(SDL_Surface* screen, menu* m, int* animationFinished) {
    Uint32 current_time = SDL_GetTicks();
    if (current_time - m->Time > 100 && !*animationFinished) { // display each frame for 100 milliseconds until animation is finished
        m->FrameNumber++;
        if (m->FrameNumber >= 20) { // if last frame is reached, animation is finished
            *animationFinished = 1;
        } else {
            m->Time = current_time;
        }
    }
    if (!*animationFinished) { // if animation is not finished, display the current frame
        SDL_BlitSurface(m->AnimationMenu[m->FrameNumber], NULL, screen, &m->PosAnimationMenu);
        SDL_Flip(screen);
    }
}




