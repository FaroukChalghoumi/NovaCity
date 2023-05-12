#include "menu.h"


void InitMenuEssentials(menu *m)
{
    	m->FrameNumber =0;
	m->PosAnimationMenu.x = 0 ; 
	m->PosAnimationMenu.y = 0 ; 


    	
    m->game = m->menuPlay = m->settings = m->SingleMulti = m->NewLoad = 0;
    m->Time = 0 ; 
    m->FrameNumber=0;
    m->AnimNovaFinished = 0 ;
}
void InitAnimationMeta (menu *m)
{
	int i;
	char ch[200];

	for(i=0;i<140;i++)
	{
        if (i<9)
		sprintf(ch,"Meta/ezgif-frame-00%d.png",i+1);
        else if (i>=9 && i<99)
        sprintf(ch,"Meta/ezgif-frame-0%d.png",i+1);
        else if (i>=99)
        sprintf(ch,"Meta/ezgif-frame-%d.png",i+1);
		m->AnimationMenu[i] = IMG_Load(ch);
        if (m->AnimationMenu[i]  == NULL) {
        printf("Failed to load image %d .\n",i+1);
        exit(1);
    }
    }
}

void InitAnimationNova(menu *m){
	int i;
	char ch[200];
    	for(i=0;i<19;i++)
	{
		sprintf(ch,"animNova/%d.jpg",i+1);
		m->AnimationNova[i] = IMG_Load(ch);
        if (m->AnimationNova[i]  == NULL) {
        printf("Failed to load image %d .\n",i+1);
        exit(1);}
	}

}
void InitAnimationCar(menu *m){
    int i;
	char ch[200];
    for(i=0;i<124;i++)
	{
        if (i<9)
		sprintf(ch,"CarAnim/ezgif-frame-00%d.png",i+1);
        else if (i>=9 && i<99)
        sprintf(ch,"CarAnim/ezgif-frame-0%d.png",i+1);
        else if (i>=99)
        sprintf(ch,"CarAnim/ezgif-frame-%d.png",i+1);
		m->AnimationCar[i] = IMG_Load(ch);
        if (m->AnimationCar[i]  == NULL) {
        printf("Failed to load image %d .\n",i+1);
        exit(1);
    }

	}
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

    playGame->PosButtonPlay.x = 500;
    playGame->PosButtonPlay.y = 200;

    playGame->PosButtonSetting.x = 500;
    playGame->PosButtonSetting.y = 350;

    playGame->PosButtonQuit.x = 500;
    playGame->PosButtonQuit.y = 500;

    playGame->MouseMotion = 0 ;
}

void AfficherMenuInitial(Play playGame, SDL_Surface* screen)
{
    if (playGame.MouseMotion == 0){
    // Blit the background image onto the screen
    //SDL_BlitSurface(playGame.PlayBackground, NULL, screen, &playGame.PosPlayBackground);
    //Replaced with animation Metaverse 

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
    //SDL_BlitSurface(playGame.PlayBackground, NULL, screen, &playGame.PosPlayBackground);
    //Replaced with animation Metaverse 

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
    //SDL_BlitSurface(playGame.PlayBackground, NULL, screen, &playGame.PosPlayBackground);
    //Replaced with animation Metaverse 

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
    //SDL_BlitSurface(playGame.PlayBackground, NULL, screen, &playGame.PosPlayBackground);
    //Replaced with animation Metaverse 

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
    SingleMultiplayer->SingleMultiBackground = IMG_Load("backMeta.jpg");
    SingleMultiplayer->ButtonSingle = IMG_Load("solo1.png");
    SingleMultiplayer->ButtonMulti = IMG_Load("multi1.png");
    SingleMultiplayer->ButtonActiveSingle = IMG_Load("solo2.png");
    SingleMultiplayer->ButtonActiveMulti = IMG_Load("multi2.png");

    // Set positions for images
    SingleMultiplayer->PosSingleMultiBackground.x = 0;
    SingleMultiplayer->PosSingleMultiBackground.y = 0;

    SingleMultiplayer->PosButtonSingle.x = 200;
    SingleMultiplayer->PosButtonSingle.y = 350;

    SingleMultiplayer->PosButtonMulti.x = 500;
    SingleMultiplayer->PosButtonMulti.y = 350;
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
void HandleInputSingleMulti(SDL_Event event , menu *m)
{
switch ( m->SingleMultiplayer.MouseMotion) {
            

                 case 1:
                 
                        // "Play" button was clicked
                        // Perform actions here : Goto ==> Single Multi 
                       if (event.button.button == SDL_BUTTON_LEFT && m->SingleMulti == 1)
                        {
                            printf("\nmenuPlay = %d |settings = %d |game = %d | MouseMotionPlay = %d",m->menuPlay,m->settings,m->game,m->playGame.MouseMotion);

                            m->menuPlay = 0;
                            m->settings = m->NewLoad  ; 
                            m->SingleMulti =0 ; 
                            m->game=1 ; 
                            m->FrameNumber = 0; 
                            m->AnimNovaFinished = 0 ; 
                        }

                        break;
                    case 2:
                        // "Settings" button was clicked
                        // Perform actions here
                        if (event.button.button == SDL_BUTTON_LEFT && m->SingleMulti == 1)
                        {
                            m->menuPlay = 0;
                            m->settings = m->NewLoad ; 
                            m->SingleMulti =0 ; 
                            m->game=2 ; 
                            m->FrameNumber = 0; 
                            m->AnimNovaFinished = 0 ; 
                        }
                        break;
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


void Animation(SDL_Surface* screen, menu* m){
    Uint32 current_time = SDL_GetTicks();
    if (current_time - m->Time > 20) { // display each frame for 100 milliseconds
        if (m->FrameNumber == 0) { // if first frame is reached, switch to forward direction
            m->FrameNumber = 1;
            m->Reverse = 0 ; 
            m->Time = current_time;
        } else if (m->FrameNumber == 139) { // if last frame is reached, switch to reverse direction
            m->Reverse = 1;
            m->FrameNumber--;
            m->Time = current_time;
        } else if (m->FrameNumber > 0 && m->FrameNumber < 139 && !m->Reverse) { // if not first or last frame and going forward, update frame normally
            m->FrameNumber++;
            m->Time = current_time;
        } else if (m->FrameNumber > 0 && m->FrameNumber < 139 && m->Reverse) { // if not first or last frame and going in reverse, update frame normally
            m->FrameNumber--;
            m->Time = current_time;
        } else if (m->FrameNumber == 1) { // if first frame is reached and going in reverse, switch to forward direction
            m->Reverse = 0;
            m->FrameNumber++;
            m->Time = current_time;
        }
    }
    SDL_BlitSurface(m->AnimationMenu[m->FrameNumber], NULL, screen, &m->PosAnimationMenu);
	  
}




void freeAnimation(menu* m) {
    for(int i = 0; i < 140; i++) {
        SDL_FreeSurface(m->AnimationMenu[i]);
        m->AnimationMenu[i] = NULL;
    }
}



void displayAnimation(SDL_Surface* screen, menu *m) {
    Uint32 current_time = SDL_GetTicks();
    int frameSpeed = 80 ;
    if (m->game ==1 || m->game == 2)
         frameSpeed = 50;
    if (current_time - m->Time > frameSpeed && m->AnimNovaFinished==0) { // display each frame for 100 milliseconds until animation is finished
       {
        m->FrameNumber++;
        printf("\nframe = %d",m->FrameNumber);
       } 
       if (m->game ==1  || m->game == 2)
       {
        if (m->FrameNumber >= 122) { // if last frame is reached, animation is finished
            m->AnimNovaFinished = 1;
        } else {
            m->Time = current_time;
        }
       }

        if (m->menuPlay ==0 && m->game == 0){
    if (m->FrameNumber >= 20) { // if last frame is reached, animation is finished
            m->AnimNovaFinished = 1;
        } else {
            m->Time = current_time;
        }
       }
        
    }
    if (m->AnimNovaFinished==0) { // if animation is not finished, display the current frame
     if (m->game ==1 || m->game == 2)
     {
        SDL_BlitSurface(m->AnimationCar[m->FrameNumber], NULL, screen, &m->PosAnimationMenu);
        SDL_Flip(screen);
     }
      if (m->menuPlay ==0 && m->game == 0){
SDL_BlitSurface(m->AnimationNova[m->FrameNumber], NULL, screen, &m->PosAnimationMenu);
        SDL_Flip(screen);
     }
        
    }
}



void freeAnimationNova(menu* m) {
    for(int i = 0; i < 19; i++) {
        //if (m->AnimationNova[i] != NULL )
        //{
            SDL_FreeSurface(m->AnimationNova[i]);
            m->AnimationNova[i] = NULL;
        //}
    }
}



void HandleInput(SDL_Event event , menu *m)
{
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);

    // Handle mouse motion
    if (event.type == SDL_MOUSEMOTION) {
        if (x >  m->playGame.PosButtonPlay.x && x <  m->playGame.PosButtonPlay.x + m->playGame.ButtonPlay->w &&
            y >  m->playGame.PosButtonPlay.y && y <  m->playGame.PosButtonPlay.y + m->playGame.ButtonPlay->h) {
            // Mouse is over the "Play" button
             m->playGame.MouseMotion = 1;
        } else if (x >  m->playGame.PosButtonSetting.x && x <  m->playGame.PosButtonSetting.x +  m->playGame.ButtonSetting->w &&
                   y >  m->playGame.PosButtonSetting.y && y <  m->playGame.PosButtonSetting.y +  m->playGame.ButtonSetting->h) {
            // Mouse is over the "Settings" button
             m->playGame.MouseMotion = 2;
        } else if (x >  m->playGame.PosButtonQuit.x && x <  m->playGame.PosButtonQuit.x +  m->playGame.ButtonQuit->w &&
                   y >  m->playGame.PosButtonQuit.y && y <  m->playGame.PosButtonQuit.y +  m->playGame.ButtonQuit->h) {
            // Mouse is over the "Quit" button
             m->playGame.MouseMotion = 3;
        } else {
             m->playGame.MouseMotion = 0;
        }
    }

    // Handle keyboard input
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            /*case SDLK_UP:
                // Move selection up
                if ( m->playGame.MouseMotion > 1) {
                     m->playGame.MouseMotion--;
                } else {
                     m->playGame.MouseMotion = 3;
                }
                break;
            case SDLK_DOWN:
                // Move selection down
                if ( m->playGame.MouseMotion < 3) {
                     m->playGame.MouseMotion++;
                } else {
                     m->playGame.MouseMotion = 1;
                }
                break;*/
            /*case SDLK_RETURN:
                // Handle menu item selection
                switch ( m->playGame.MouseMotion) {
                    case 1:
                        // Play button selected
                        // Perform actions here : Goto ==> Single Multi 
                        m->menuPlay = m->settings = m->NewLoad = m->SingleMulti = 0 ; 
                        m->game=1 ; 

                        break;
                    case 2:
                        // Settings button selected
                        // Perform actions here
                        m->menuPlay = m->SingleMulti = m->NewLoad = m->game = 0 ; 
                        m->settings=1 ; 
                        break;
                    case 3:
                        // Quit button selected
                        // Perform actions here
                        m->menuPlay = m->SingleMulti = m->NewLoad = m->game = 0 ;
                         m->settings=0 ; 
                        break;
                    default:
                        break;
                }
                break;*/
            default:
                break;
        }
    }

//if (event.button.button == SDL_MOUSEBUTTONDOWN &&  event.button.button == SDL_BUTTON_LEFT) {
        switch ( m->playGame.MouseMotion) {
            

                 case 1:
                 
                        // "Play" button was clicked
                        // Perform actions here : Goto ==> Single Multi 
                       if (event.button.button == SDL_BUTTON_LEFT)
                        {
                            //printf("\nmenuPlay = %d |settings = %d |game = %d | MouseMotionPlay = %d",m->menuPlay,m->settings,m->game,m->playGame.MouseMotion);

                            m->menuPlay = 0;
                            m->settings = m->NewLoad = m->game = 0 ; 
                            m->SingleMulti =1 ; 
                            m->game=0 ; 
                            m->FrameNumber = 0; 
                            m->AnimNovaFinished = 0 ; 
                        }

                        break;
                    case 2:
                        // "Settings" button was clicked
                        // Perform actions here
                        if (event.button.button == SDL_BUTTON_LEFT)
                        {
                            m->menuPlay = m->SingleMulti = m->NewLoad = m->game = 0 ; 
                            m->settings=1 ; 
                        }
                        break;
                    case 3:
                        // "Quit" button was clicked
                        // Perform actions here
                        m->menuPlay = m->SingleMulti = m->NewLoad = m->game = 0 ;
                         m->settings=0 ; 
                         exit(0);
                        break;
                    default:
                        break;
        //}
    }




}

void InitSettings(Setting *settingGame)
{
    // Load background image
    if ( settingGame->SettingBackground  && 
            settingGame->ButtonFullScreen &&
            settingGame->ButtonFullScreenActive &&
            settingGame->ButtonMute &&
            settingGame->ButtonMuteActive&&
            settingGame->ReturnPlay&&
            settingGame->ReturnPlayActive&&
            settingGame->GameVolume)
            {
                 printf("\nAlready INITIALIZED");
            } 
            else 
            {
                 settingGame->SettingBackground = IMG_Load("back.jpg");
            if (settingGame->SettingBackground == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n", "back.jpg", SDL_GetError());
                return;
            }

            // Load fullscreen button images
            settingGame->ButtonFullScreen = IMG_Load("modescreen.png");
            if (settingGame->ButtonFullScreen == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n", "modescreen.png", SDL_GetError());
                return;
            }
            settingGame->ButtonFullScreenActive = IMG_Load("modescreen1.png");
            if (settingGame->ButtonFullScreenActive == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n", "modescreen1.png", SDL_GetError());
                return;
            }

            // Load mute button images
            settingGame->ButtonMute = IMG_Load("son.png");
            if (settingGame->ButtonMute == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n", "son2.png", SDL_GetError());
                return;
            }
            settingGame->ButtonMuteActive = IMG_Load("son1.png");
            if (settingGame->ButtonMuteActive == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n", "son1.png", SDL_GetError());
                return;
            }

            // Load return-to-play button images
            settingGame->ReturnPlay = IMG_Load("retour.png");
            if (settingGame->ReturnPlay == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n", "retour.png", SDL_GetError());
                return;
            }
            settingGame->ReturnPlayActive = IMG_Load("retour1.png");
            if (settingGame->ReturnPlayActive == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n", "retour1.png", SDL_GetError());
                return;
            }

            // Load game volume image
            settingGame->GameVolume = IMG_Load("PLAY.png");
            if (settingGame->GameVolume == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n", "PLAY.png", SDL_GetError());
                return;
            }

            // Set positions of images and buttons
            settingGame->PosSettingBackground.x = 0;
            settingGame->PosSettingBackground.y = 0;

            settingGame->PosButtonFullScreen.x = 300;
            settingGame->PosButtonFullScreen.y = 100;

            settingGame->PosButtonMute.x = 300;
            settingGame->PosButtonMute.y = 300;

            settingGame->PosButtonReturnPlay.x = 300;
            settingGame->PosButtonReturnPlay.y = 400;

            settingGame->PosGameVolume.x = 300;
            settingGame->PosGameVolume.y = 550;


            settingGame->MouseMotion = 0 ; 


            }
           
}




void HandleInputSetting(SDL_Event event, menu *m) {
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);

    // Handle mouse motion
    if (event.type == SDL_MOUSEMOTION) {
        if (x > m->settingGame.PosButtonFullScreen.x && x < m->settingGame.PosButtonFullScreen.x + m->settingGame.ButtonFullScreen->w &&
            y > m->settingGame.PosButtonFullScreen.y && y < m->settingGame.PosButtonFullScreen.y + m->settingGame.ButtonFullScreen->h) {
            // Mouse is over the "Fullscreen" button
            m->settingGame.MouseMotion = 1;
        } else if (x > m->settingGame.PosButtonMute.x && x < m->settingGame.PosButtonMute.x + m->settingGame.ButtonMute->w &&
                   y > m->settingGame.PosButtonMute.y && y < m->settingGame.PosButtonMute.y + m->settingGame.ButtonMute->h) {
            // Mouse is over the "Mute" button
            m->settingGame.MouseMotion = 2;
        } else if (x > m->settingGame.PosButtonReturnPlay.x && x < m->settingGame.PosButtonReturnPlay.x + m->settingGame.ReturnPlay->w &&
                   y > m->settingGame.PosButtonReturnPlay.y && y < m->settingGame.PosButtonReturnPlay.y + m->settingGame.ReturnPlay->h) {
            // Mouse is over the "Return to Play" button
            m->settingGame.MouseMotion = 3;
        } else {
            m->settingGame.MouseMotion = 0;
        }
    }

    // Handle keyboard input
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                // Move selection up
                if (m->settingGame.MouseMotion > 1) {
                    m->settingGame.MouseMotion--;
                } else {
                    m->settingGame.MouseMotion = 3;
                }
                break;
            case SDLK_DOWN:
                // Move selection down
                if (m->settingGame.MouseMotion < 3) {
                    m->settingGame.MouseMotion++;
                } else {
                    m->settingGame.MouseMotion = 1;
                }
                break;
            case SDLK_RETURN:
                // Handle menu item selection
                switch (m->settingGame.MouseMotion) {
                    case 1:
                        // Fullscreen button selected
                        // Perform actions here
                        break;
                    case 2:
                        // Mute button selected
                        // Perform actions here
                        break;
                    case 3:
                        // Return to Play button selected
                        // Perform actions here
                        m->settings = 0;
                        //freeSettings(&m->settingGame);
                        m->settingGame.MouseMotion=0;
                        m->menuPlay = 1;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    if (event.button.button == SDL_BUTTON_LEFT) {
        switch (m->settingGame.MouseMotion) {
            case 1:
                // Fullscreen button was clicked
                // Perform actions here
                break;
            case 2:
                // Mute button was clicked
                // Perform actions here
                break;
            case 3:
                // Return to Play button was clicked
                // Perform actions here
                m->settings = 0;
                m->settingGame.MouseMotion=0;
                m->menuPlay = 1;
                break;
            default:
                break;
        }
    }
}





    void AfficherSetting(Setting setting, SDL_Surface* screen)
{
    if (setting.MouseMotion == 0){
        // Blit the background image onto the screen
        SDL_BlitSurface(setting.SettingBackground, NULL, screen, &setting.PosSettingBackground);

        // Blit the "full screen" button onto the screen
        SDL_BlitSurface(setting.ButtonFullScreen, NULL, screen, &setting.PosButtonFullScreen);

        // Blit the "mute" button onto the screen
        SDL_BlitSurface(setting.ButtonMute, NULL, screen, &setting.PosButtonMute);

        // Blit the "return to play" button onto the screen
        SDL_BlitSurface(setting.ReturnPlay, NULL, screen, &setting.PosButtonReturnPlay);

        // Blit the game volume onto the screen
        SDL_BlitSurface(setting.GameVolume, NULL, screen, &setting.PosGameVolume);
    }
    else if (setting.MouseMotion == 1)
    {
        // Blit the background image onto the screen
        SDL_BlitSurface(setting.SettingBackground, NULL, screen, &setting.PosSettingBackground);

        // Blit the "full screen" button onto the screen
        SDL_BlitSurface(setting.ButtonFullScreenActive, NULL, screen, &setting.PosButtonFullScreen);

        // Blit the "mute" button onto the screen
        SDL_BlitSurface(setting.ButtonMute, NULL, screen, &setting.PosButtonMute);

        // Blit the "return to play" button onto the screen
        SDL_BlitSurface(setting.ReturnPlay, NULL, screen, &setting.PosButtonReturnPlay);

        // Blit the game volume onto the screen
        SDL_BlitSurface(setting.GameVolume, NULL, screen, &setting.PosGameVolume);
    }
    else if (setting.MouseMotion == 2)
    {
        // Blit the background image onto the screen
        SDL_BlitSurface(setting.SettingBackground, NULL, screen, &setting.PosSettingBackground);

        // Blit the "full screen" button onto the screen
        SDL_BlitSurface(setting.ButtonFullScreen, NULL, screen, &setting.PosButtonFullScreen);

        // Blit the "mute" button onto the screen
        SDL_BlitSurface(setting.ButtonMuteActive, NULL, screen, &setting.PosButtonMute);

        // Blit the "return to play" button onto the screen
        SDL_BlitSurface(setting.ReturnPlay, NULL, screen, &setting.PosButtonReturnPlay);

        // Blit the game volume onto the screen
        SDL_BlitSurface(setting.GameVolume, NULL, screen, &setting.PosGameVolume);
    }
    else if (setting.MouseMotion == 3)
    {
        // Blit the background image onto the screen
        SDL_BlitSurface(setting.SettingBackground, NULL, screen, &setting.PosSettingBackground);

        // Blit the "full screen" button onto the screen
        SDL_BlitSurface(setting.ButtonFullScreen, NULL, screen, &setting.PosButtonFullScreen);

        // Blit the "mute" button onto the screen
        SDL_BlitSurface(setting.ButtonMute, NULL, screen, &setting.PosButtonMute);

        // Blit the "return to play" button onto the screen
        SDL_BlitSurface(setting.ReturnPlayActive, NULL, screen, &setting.PosButtonReturnPlay);

        // Blit the game volume onto the screen
        SDL_BlitSurface(setting.GameVolume, NULL, screen, &setting.PosGameVolume);
    }
}


void freeSettings(Setting* setting)
{
    if (setting) {
        // Free the SDL surfaces
        SDL_FreeSurface(setting->SettingBackground);
        SDL_FreeSurface(setting->ButtonFullScreen);
        SDL_FreeSurface(setting->ButtonFullScreenActive);
        SDL_FreeSurface(setting->ButtonMute);
        SDL_FreeSurface(setting->ButtonMuteActive);
        SDL_FreeSurface(setting->ReturnPlay);
        SDL_FreeSurface(setting->ReturnPlayActive);
        SDL_FreeSurface(setting->GameVolume);
    }
}



void freeAnimCar(menu *m,SDL_Surface* screen)
{
    //if ()
    for (int i = 0; i < 100; i++) {
        displayAnimation(screen,m);
        if (m->AnimationCar[i] != NULL) {
            SDL_FreeSurface(m->AnimationCar[i]);
            m->AnimationCar[i] = NULL;
        }
    }
}



int AllMenu(menu *m,SDL_Surface* screen ,SDL_Event event)
{
    if (m->menuPlay == m->SingleMulti ==  m->NewLoad  == m->game ==m->settings==0)
    {
        //InitMenuEssentials(m);
        //InitAnimationNova(m);
        //if (m->AnimationNova == 0 )
            displayAnimation(screen,m);
        if (m->AnimNovaFinished)
            {
                //printf("hello %d",m->menuPlay);
              //  freeAnimationNova(m) ;
            m->menuPlay = 1 ; 
            //printf("initmenu %d",m->menuPlay);
            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
            //FreePlay(&m->playGame);
            }
    }

    if (m->menuPlay == 1)
    {
        
        //FreeSingleMulti(&m->SingleMultiplayer);
        //freeSettings(&m->settingGame);
        InitMenuInitial(&m->playGame);
        InitAnimationMeta(m);
        m->menuPlay = 2 ; 
    }
     if (m->menuPlay == 2)
    {
        //printf("initmenu");
        Animation(screen, m);
        HandleInput(event,m);
        AfficherMenuInitial(m->playGame, screen);
    }

    if (m->settings ==1){
        //FreePlay(&m->playGame);
        //freeAnimation(m);
        printf("\nsettings= %d",m->settings);
        InitSettings(&m->settingGame);
        printf("\nmouse Settings = %d",m->settingGame.MouseMotion);
        //m->settings =2 ;
        //InitSettings(&m->settingGame);
        AfficherSetting(m->settingGame,screen);
        HandleInputSetting(event,m);
        
    }
    if (m->SingleMulti ==1)
    {
        
        AfficherSingleMulti(m->SingleMultiplayer,screen);
        HandleMouseMotionSingleMulti(event,&m->SingleMultiplayer);
        HandleInputSingleMulti(event,m);
    }
    if (m->game == 1 || m->game == 2)
    {
        
        //printf("\n game= %d",m->game);
        //printf("\n menu= %d",m->menuPlay);
        screen = SDL_SetVideoMode(1200, 660, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        displayAnimation(screen,m);
        //m->game = 0;
        if (m->AnimNovaFinished)
        {
            freeAnimCar(m,screen);
            return m->game  - 1  ;
        }
    }
    return 0 ; 

}






