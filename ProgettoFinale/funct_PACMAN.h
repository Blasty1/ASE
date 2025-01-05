#define realMeasureX 240
#define realMeasureY 250
#define sizeCell 5
#define OFFSETY 50
#define groupedX realMeasureX/sizeCell
#define groupedY realMeasureY/sizeCell
#define TimerOfGame 60


#include "LPC17xx.h"
#include "GLCD/GLCD.h" 


typedef enum { 
		Playing, Pause, Win,GameOver, Wait
} STATUSgame;

typedef enum { 
		Muro = -1, 
		Background = 0,
	  Pills = 1,
		SuperPills = 2
} labObject;

typedef struct{
	int x;
	int y;
} coordinate;

typedef struct{
	coordinate positionOfPacman;
	labObject labirinth[groupedX][groupedY];
	int lives;
	int score;
	STATUSgame status;
} PACMAN;

void gameInit();
