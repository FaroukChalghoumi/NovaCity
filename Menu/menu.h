#ifndef MENU_H
#define MENU_H
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>



typedef struct 
{
    //Play Interface 
    SDL_Surface* PlayBackground;
    SDL_Surface* ButtonPlay;
    SDL_Surface* ButtonSetting;
    SDL_Surface* ButtonQuit;
    SDL_Surface* ButtonActivePlay;
    SDL_Surface* ButtonActiveSetting;
    SDL_Surface* ButtonActiveQuit;
    SDL_Rect PosPlayBackground;
    SDL_Rect PosButtonPlay;
    SDL_Rect PosButtonSetting;
    SDL_Rect PosButtonQuit;



    int MouseMotion;

}Play;

typedef struct 
{
    //Single/Multi palyer Interface 
    SDL_Surface* SingleMultiBackground;
    SDL_Surface* ButtonSingle;
    SDL_Surface* ButtonMulti;
    SDL_Surface* ButtonActiveSingle;
    SDL_Surface* ButtonActiveMulti;
    SDL_Rect PosSingleMultiBackground;
    SDL_Rect PosButtonSingle;
    SDL_Rect PosButtonMulti;

    int MouseMotion;
}SingleMulti;


typedef struct 
{
    //New or LoadGame Interface 
    SDL_Surface* NewLoadBackground;
    SDL_Surface* ButtonNewGame;
    SDL_Surface* ButtonLoadGame;
    SDL_Rect PosNewLoadBackground;
    SDL_Rect PosButtonNewGame;
    SDL_Rect PosButtonLoadGame;

    int MouseMotion;
}NewLoad;

typedef struct 
{
    //Settings Interface 
    SDL_Surface* SettingBackground;
    SDL_Surface* ButtonFullScreen;
    SDL_Surface* ButtonFullScreenActive;
    SDL_Surface* ButtonMute;
    SDL_Surface* ButtonMuteActive;
    SDL_Surface* ReturnPlay;
    SDL_Surface* ReturnPlayActive;
    SDL_Surface* GameVolume;
    SDL_Rect PosSettingBackground;
    SDL_Rect PosButtonFullScreen;
    SDL_Rect PosButtonMute;
    SDL_Rect PosButtonReturnPlay;
    SDL_Rect PosGameVolume;
int MouseMotion;

}Setting;

typedef struct 
{
    //annimation 
    SDL_Surface* AnimationMenu[150];
    SDL_Surface* AnimationNova[20];
    SDL_Surface* AnimationCar[130] ;
    SDL_Rect PosAnimationMenu;
    int FrameNumber;
    int Time;
    int Reverse ; 
    int AnimNovaFinished;

    //Composants Graphique 
    Play playGame;
    Setting settingGame;
    NewLoad SingleMultiplayer;

    int menuPlay ; 
    int settings;
    int SingleMulti;
    int NewLoad;
    int game;
}menu;

void InitMenuEssentials(menu *m);

void InitMenuInitial(Play *playGame);
void InitSingleMulti(SingleMulti *SingleMultiplayer);
void InitNewLoad(NewLoad *NewLoadGame);
void InitSettings(Setting *settingGame);
void InitAnimationMeta (menu *m);
void InitAnimationNova(menu *m);
void InitAnimationCar(menu *m);

void AfficherMenuInitial(Play playGame,SDL_Surface* screen);
void AfficherSingleMulti(SingleMulti SingleMultiplayer,SDL_Surface* screen);
void AfficherPlay(SDL_Surface* screen);
void AfficherSetting(Setting setting, SDL_Surface* screen);
void displayAnimation(SDL_Surface* screen, menu *m) ;

void HandleMouseMotion(SDL_Event event, Play *playGame);
void HandleMouseMotionSingleMulti(SDL_Event event, SingleMulti *singleMultiPlayer);
void HandleInput(SDL_Event event, menu *m);
void HandleInputSetting(SDL_Event event, menu *m);


void Animation(SDL_Surface* screen, menu* m);



void FreePlay(Play* playGame) ;
void FreeSingleMulti(SingleMulti *SingleMultiplayer);
void freeAnimation(menu* m) ;
void freeAnimationNova(menu* m) ;
void freeAnimCar(menu *m,SDL_Surface* screen);
void freeSettings(Setting* setting);

void AllMenu(menu *m,SDL_Surface* screen ,SDL_Event event); 







#endif