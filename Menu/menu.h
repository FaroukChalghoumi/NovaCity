#ifndef MENU_H
#define MENU_H
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

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


}NewLoad;

typedef struct 
{
    //Settings Interface 
    SDL_Surface* SettingBackground;
    SDL_Surface* ButtonFullScreen;
    SDL_Surface* ButtonMute;
    SDL_Rect PosSettingBackground;
    SDL_Rect PosButtonFullScreen;
    SDL_Rect PosButtonMute;


}Setting;

typedef struct 
{
    //annimation 
    SDL_Surface* AnimationMenu[20];
    SDL_Rect PosAnimationMenu;
    int FrameNumber;
    int Time;

    int menuPlay ; 
    int settings;
    int SingleMulti;
    int NewLoad;
    int game;
}menu;

void InitAnimationMenu(menu *m);

void InitMenuInitial(Play *playGame);
void InitSingleMulti(SingleMulti *SingleMultiplayer);
void InitNewLoad(NewLoad *NewLoadGame);
void InitSettings(Setting *settingGame);



void AfficherMenuInitial(Play playGame,SDL_Surface* screen);
void AfficherSingleMulti(SingleMulti SingleMultiplayer,SDL_Surface* screen);
void AfficherPlay(SDL_Surface* screen);
void AfficherSetting(SDL_Surface* screen);
void AfficherAnimation (menu m , SDL_Surface *screen);
void displayAnimation(SDL_Surface* screen, menu* m, int* animationFinished) ;

void HandleMouseMotion(SDL_Event event, Play *playGame);
void HandleMouseMotionSingleMulti(SDL_Event event, SingleMulti *singleMultiPlayer);


void Animation(menu *m);



void FreePlay(Play* playGame) ;
void FreeSingleMulti(SingleMulti *SingleMultiplayer);
void freeAnimation(menu* m) ;









#endif