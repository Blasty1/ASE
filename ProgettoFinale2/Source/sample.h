#define realMeasureY 240
#define realMeasureX 250
#define sizeCell 5
#define OFFSETY 50
#define groupedX realMeasureX/sizeCell
#define groupedY realMeasureY/sizeCell
#define TimerOfGame 60
#define PillPoint 10
#define SuperPillPoint 50
#define LIFEPOINT 1000
#define NUMOFSUPERPILLS 4


#include "LPC17xx.h"
#include "GLCD/GLCD.h" 


typedef enum { 
		Playing, Pause, Win,GameOver
} STATUSgame;

typedef enum { 
		Right,Left,Up,Down
} Direction;

typedef struct{
	int x;
	int y;
} coordinate;

typedef struct{
	int time;
	coordinate position;
} superPillsHandle;

typedef enum { 
		Ghost = -3,
		Pacman = -2,
		Muro = -1, 
		Background = 0,
	  Pills = 1,
		SuperPills = 2,
		Teleport = 3
} labObject;
typedef enum{
		ChaseMode,FrightendMod
}StatusGhost;

typedef struct 
{
	Direction ghostDirection;
	StatusGhost status;
	coordinate positionOfGhost;
} GhostItem;

typedef struct{
	coordinate positionOfPacman;
	labObject labirinth[groupedX][groupedY];
	int lifes;
	int score;
	int timer;
	int lifesWin;
	Direction pacmanDirection;
	GhostItem ghost;
	STATUSgame status;
	int numOfPillsNotTaken;
	superPillsHandle superPillsGeneration[NUMOFSUPERPILLS];
} PACMAN;

void startGame();
void gameInit();
void printSquare(int x,int y,int size,int color);
