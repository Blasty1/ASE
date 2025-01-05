#define realMeasureY 240
#define realMeasureX 250
#define sizeCell 5
#define OFFSETY 50
#define groupedX realMeasureX/sizeCell
#define groupedY realMeasureY/sizeCell
#define TimerOfGame 60
#define PillPoint 10
#define SuperPillPoint 50


#include "LPC17xx.h"
#include "GLCD/GLCD.h" 


typedef enum { 
		Playing, Pause, Win,GameOver, Wait
} STATUSgame;

typedef enum { 
		Right,Left,Up,Down
} Direction;

typedef enum { 
		Pacman = -2,
		Muro = -1, 
		Background = 0,
	  Pills = 1,
		SuperPills = 2,
		Teleport = 3
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
	int timer;
	Direction pacmanDirection;
	STATUSgame status;
} PACMAN;

void startGame();
void gameInit();
