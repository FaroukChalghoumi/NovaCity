#include "menu.h"
void InitAnimationMenu(menu *m)
{
    	m->FrameNumber =0;
	m->PosAnimationMenu.x = 0 ; 
	m->PosAnimationMenu.y = 0 ; 
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
    m->game = m->menuPlay = m->settings = m->SingleMulti = m->NewLoad = 0;
    m->Time = 0 ; 
    m->FrameNumber=0;
    m->AnimNovaFinished = 0 ;
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
    SingleMultiplayer->SingleMultiBackground = IMG_Load("back.jpg");
    SingleMultiplayer->ButtonSingle = IMG_Load("PLAY.png");
    SingleMultiplayer->ButtonMulti = IMG_Load("EXIT1.png");
    SingleMultiplayer->ButtonActiveSingle = IMG_Load("PP.png");
    SingleMultiplayer->ButtonActiveMulti = IMG_Load("EXIT.png");

    // Set positions for images
    SingleMultiplayer->PosSingleMultiBackground.x = 0;
    SingleMultiplayer->PosSingleMultiBackground.y = 0;

    SingleMultiplayer->PosButtonSingle.x = 500;
    SingleMultiplayer->PosButtonSingle.y = 200;

    SingleMultiplayer->PosButtonMulti.x = 500;
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
        //SDL_BlitSurface(SingleMultiplayer.SingleMultiBackground, NULL, screen, &SingleMultiplayer.PosSingleMultiBackground);

        SDL_BlitSurface(SingleMultiplayer.ButtonSingle, NULL, screen, &SingleMultiplayer.PosButtonSingle);

        SDL_BlitSurface(SingleMultiplayer.ButtonMulti, NULL, screen, &SingleMultiplayer.PosButtonMulti);
    }
    else if (SingleMultiplayer.MouseMotion == 1)
    {
        //SDL_BlitSurface(SingleMultiplayer.SingleMultiBackground, NULL, screen, &SingleMultiplayer.PosSingleMultiBackground);

        SDL_BlitSurface(SingleMultiplayer.ButtonActiveSingle, NULL, screen, &SingleMultiplayer.PosButtonSingle);

        SDL_BlitSurface(SingleMultiplayer.ButtonMulti, NULL, screen, &SingleMultiplayer.PosButtonMulti);
    }
    else if (SingleMultiplayer.MouseMotion == 2)
    {
        //SDL_BlitSurface(SingleMultiplayer.SingleMultiBackground, NULL, screen, &SingleMultiplayer.PosSingleMultiBackground);

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

void AfficherAnimation (menu m , SDL_Surface *screen)
{
    printf("\nFrame = %d ",m.FrameNumber);
        SDL_BlitSurface(m.AnimationMenu[0], NULL, screen, &m.PosAnimationMenu);

    
    
}


void freeAnimation(menu* m) {
    for(int i = 0; i < 140; i++) {
        SDL_FreeSurface(m->AnimationMenu[i]);
        m->AnimationMenu[i] = NULL;
    }
}



void displayAnimation(SDL_Surface* screen, menu *m) {
    Uint32 current_time = SDL_GetTicks();
    if (current_time - m->Time > 50 && m->AnimNovaFinished==0) { // display each frame for 100 milliseconds until animation is finished
       {
        m->FrameNumber++;
        printf("\nframe = %d",m->FrameNumber);
       } 
       if (m->menuPlay )
       {
        if (m->FrameNumber >= 122) { // if last frame is reached, animation is finished
            m->AnimNovaFinished = 1;
        } else {
            m->Time = current_time;
        }
       }else{
    if (m->FrameNumber >= 19) { // if last frame is reached, animation is finished
            m->AnimNovaFinished = 1;
        } else {
            m->Time = current_time;
        }
       }
        
    }
    if (!m->AnimNovaFinished) { // if animation is not finished, display the current frame
     if (m->menuPlay )
     {
        SDL_BlitSurface(m->AnimationCar[m->FrameNumber], NULL, screen, &m->PosAnimationMenu);
        SDL_Flip(screen);
     }else{
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



void HandleInput(SDL_Event event, Play *playGame , menu *m)
{
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);

    // Handle mouse motion
    if (event.type == SDL_MOUSEMOTION) {
        if (x > playGame->PosButtonPlay.x && x < playGame->PosButtonPlay.x + playGame->ButtonPlay->w &&
            y > playGame->PosButtonPlay.y && y < playGame->PosButtonPlay.y + playGame->ButtonPlay->h) {
            // Mouse is over the "Play" button
            playGame->MouseMotion = 1;
        } else if (x > playGame->PosButtonSetting.x && x < playGame->PosButtonSetting.x + playGame->ButtonSetting->w &&
                   y > playGame->PosButtonSetting.y && y < playGame->PosButtonSetting.y + playGame->ButtonSetting->h) {
            // Mouse is over the "Settings" button
            playGame->MouseMotion = 2;
        } else if (x > playGame->PosButtonQuit.x && x < playGame->PosButtonQuit.x + playGame->ButtonQuit->w &&
                   y > playGame->PosButtonQuit.y && y < playGame->PosButtonQuit.y + playGame->ButtonQuit->h) {
            // Mouse is over the "Quit" button
            playGame->MouseMotion = 3;
        } else {
            playGame->MouseMotion = 0;
        }
    }

    // Handle keyboard input
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                // Move selection up
                if (playGame->MouseMotion > 1) {
                    playGame->MouseMotion--;
                } else {
                    playGame->MouseMotion = 3;
                }
                break;
            case SDLK_DOWN:
                // Move selection down
                if (playGame->MouseMotion < 3) {
                    playGame->MouseMotion++;
                } else {
                    playGame->MouseMotion = 1;
                }
                break;
            case SDLK_RETURN:
                // Handle menu item selection
                switch (playGame->MouseMotion) {
                    case 1:
                        // Play button selected
                        // Perform actions here : Goto ==> Single Multi 
                        m->menuPlay = m->settings = m->NewLoad = m->game = 0 ; 
                        m->SingleMulti=1 ; 

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
                break;
            default:
                break;
        }
    }

if (event.button.button == SDL_BUTTON_LEFT) {
        switch (playGame->MouseMotion) {
            

                 case 1:
                        // "Play" button was clicked
                        // Perform actions here : Goto ==> Single Multi 
                        m->menuPlay = m->settings = m->NewLoad = m->game = 0 ; 
                        m->SingleMulti=1 ; 

                        break;
                    case 2:
                        // "Settings" button was clicked
                        // Perform actions here
                        m->menuPlay = m->SingleMulti = m->NewLoad = m->game = 0 ; 
                        m->settings=1 ; 
                        break;
                    case 3:
                        // "Quit" button was clicked
                        // Perform actions here
                        m->menuPlay = m->SingleMulti = m->NewLoad = m->game = 0 ;
                         m->settings=0 ; 
                        break;
                    default:
                        break;
        }
    }




}

void InitSettings(Setting *settingGame)
{
    // Load background image
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

    settingGame->PosButtonFullScreen.x = 100;
    settingGame->PosButtonFullScreen.y = 200;

    settingGame->PosButtonMute.x = 100;
    settingGame->PosButtonMute.y = 300;

    settingGame->PosButtonReturnPlay.x = 100;
    settingGame->PosButtonReturnPlay.y = 400;

    settingGame->PosGameVolume.x = 250;
    settingGame->PosGameVolume.y = 220;


    settingGame->MouseMotion = 0 ; 

}




void HandleInputSetting(SDL_Event event, Setting *setting, menu *m) {
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);

    // Handle mouse motion
    if (event.type == SDL_MOUSEMOTION) {
        if (x > setting->PosButtonFullScreen.x && x < setting->PosButtonFullScreen.x + setting->ButtonFullScreen->w &&
            y > setting->PosButtonFullScreen.y && y < setting->PosButtonFullScreen.y + setting->ButtonFullScreen->h) {
            // Mouse is over the "Fullscreen" button
            setting->MouseMotion = 1;
        } else if (x > setting->PosButtonMute.x && x < setting->PosButtonMute.x + setting->ButtonMute->w &&
                   y > setting->PosButtonMute.y && y < setting->PosButtonMute.y + setting->ButtonMute->h) {
            // Mouse is over the "Mute" button
            setting->MouseMotion = 2;
        } else if (x > setting->PosButtonReturnPlay.x && x < setting->PosButtonReturnPlay.x + setting->ReturnPlay->w &&
                   y > setting->PosButtonReturnPlay.y && y < setting->PosButtonReturnPlay.y + setting->ReturnPlay->h) {
            // Mouse is over the "Return to Play" button
            setting->MouseMotion = 3;
        } else {
            setting->MouseMotion = 0;
        }
    }

    // Handle keyboard input
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                // Move selection up
                if (setting->MouseMotion > 1) {
                    setting->MouseMotion--;
                } else {
                    setting->MouseMotion = 3;
                }
                break;
            case SDLK_DOWN:
                // Move selection down
                if (setting->MouseMotion < 3) {
                    setting->MouseMotion++;
                } else {
                    setting->MouseMotion = 1;
                }
                break;
            case SDLK_RETURN:
                // Handle menu item selection
                switch (setting->MouseMotion) {
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
        switch (setting->MouseMotion) {
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



void freeAnimCar(menu *m)
{
    for (int i = 0; i < 100; i++) {
        if (m->AnimationCar[i] != NULL) {
            SDL_FreeSurface(m->AnimationCar[i]);
            m->AnimationCar[i] = NULL;
        }
    }
}



void AllMenu(menu *m,SDL_Surface* screen)
{
    if (m->menuPlay == m->SingleMulti ==  m->NewLoad  == m->game ==m->settings==0)
    {
        displayAnimation(screen,m);
        if (m->AnimNovaFinished == 0)
            {freeAnimationNova(m) ;
            m->menuPlay == 1 ; 

            }
    }

    if (m->menuPlay)
    {
        //FreeSingleMulti(&m->SingleMultiplayer);
        InitMenuInitial(&m->playGame);
    }

}






