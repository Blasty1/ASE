#include "sample.h"
#include<stdio.h>
#include<string.h>
#include "RIT/RIT.h"

void printWholeMatrix();
void printPacManLifes();
void victory();
void pause();
void printSquare(int,int, int,int );
void printPacman();
void generateSuperPills();
void bubbleSortForSuperPillsArray();


volatile PACMAN game =  //variabile che contiene tutto ciò che riguarda il gioco
	{
		.labirinth = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-1},
        {-1, -1,  -1,  -1,  -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
        {-1, -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  -1,  -1,  0,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},		
				{-1, -1,  1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 0,  1,  0,  0,  -1,  -1,  -1,  -1,  0,  1,  0,  0,  -1,  -1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  1,  0,  1,  0,  1,  -1, -1},
				{-1, -1,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  -1,  0,  0,  -1,  0,  0,  0,  0,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  1,  0,  0,  -1,  -1,  -1,  -1,  0,  1,  0,  0,  -1,  -1,  0,  1,  0,  1,  0,  1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  1,  0,  1,  0,  1,  -1,   -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  -1, -1,  -1,  0,  0,  0,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  -1,  0,  -1,  0,  1,  0,  -1,  0,  -1,  0,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  0,  0,  0,  0,  -1,  1,  0,  1,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  -1,  -1,  -1,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  -1, -1},
				{-1, -1,  1,  0,  0,  1,  0,  0,  1,  0,  -1,  0, -1,  0,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  0,  0,  0, 0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0, 0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  0,  1,  0,  0,  1,  0,  -1,  0,  -1,  -1,  -1,  -1,  0,  1,  0,  1,  0,  -1,  0,  0,  0,  0,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  0,  1,  0,  0,  1,  0,  -1,  0,  -1,  -1,  -1,  -1,  0,  1,  0,  1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  1,  0,  1,  0,  1,  0,  0,  -1,  0,  -1,  0,  0,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,   -1},
				{-1, -1,  1,  0,  0,  1,  0,  0,  1,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  0,  -1,  0,  0,  0,  0,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  0, -1,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,   -1},
				{3, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  -1,  -1,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
				{3, 0 ,  0,  0,  1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0, 0,  3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1	,  -1,  -1,  -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
				{-1, -1,  0,  -1,  -1,  -1,  0,  0,  0,  0,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1},
				{-1, -1,  1,  -1,  0,  -1,  0,  0,  1,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  -1,  0,  -1,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1},
				{-1, -1,  1,  -1,  0,  -1,  0,  0,  1,  0,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0,  1,  -1, -1},
				{-1, -1,  0,  -1,  0,  -1,  0,  0,  0,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  -1,  0,  -1,  0,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  -1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  0,  0,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  -1, -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1, -1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  0,  0,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  0,  0,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0, 0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  -1, -1},
				{-1, -1,  1,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  1,  0,  1,  0,  1,  0,  -1,  0,  0,  0,  0,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  1,  0,1,  -1, -1},
				{-1, -1,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1},
				{-1, -1,  1,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  1,  0,  1,  0,  1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  1,  -1, -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
				{-1, -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},
        {-1, -1,  -1,  -1,  -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
			  {-1, -1, -1, -1, -1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    }
	};
	
	
void gameInit()
{
	
	game.timer=TimerOfGame;
	game.status = Playing;
	game.pacmanDirection = Right;
	game.lifes=1;
	game.lifesWin=0;
	game.numOfPillsNotTaken=240;
	game.positionOfPacman.y=23;
	game.positionOfPacman.x=1;
	game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x]= Pacman;

	printWholeMatrix();//stampiamo la matrice
	printPacManLifes();
	GUI_Text(15, 10, (uint8_t *) "Time", White, Black);
	GUI_Text(40, 25, (uint8_t *) "60", White, Black);
	GUI_Text(190, 10, (uint8_t *) "Score", White, Black);
	GUI_Text(205, 25, (uint8_t *) "00", White, Black);
	
	init_timer(0,0,0x17D7840); //tempo del gioco 1s
	init_timer(1,0,0x2625A0); // aggiornamento movimento pacman , 0.1s
	init_RIT(0x4C4B40); //ogni 50ms

	enable_RIT();
	NVIC_SetPriority(RIT_IRQn,0);
	NVIC_SetPriority(TIMER0_IRQn,1);
	NVIC_SetPriority(TIMER1_IRQn,1);
	generateSuperPills();

	pause();
}


// scrive una cella, quindi un insieme di pixel
// una cella non è altro che un quadrato
void LCD_setCell(int x, int y,labObject objectToPrint)
{
	int i,j;
	if(objectToPrint == Background	)
	{
			printSquare(x,y,5,Black);
	}else if(objectToPrint == Muro){
			printSquare(x,y,5,Blue);
	}else if(objectToPrint == Pills ){
			printSquare(x,y,3,Yellow);

	} else if(objectToPrint == SuperPills)
	{
			printSquare(x,y,5,Orange);
	}else if(objectToPrint == Pacman)
	{
		printPacman();
	}

}

void printWholeMatrix()
{
	int i,j;

	for(i=0; i < groupedY; i++)
	{
		for(j=0; j < groupedX; j++)
		{
			LCD_setCell(i,j,game.labirinth[j][i]);
		}
	}
}

void printSquare(int x,int y,int size,int color) 
{
	int i,j;
	coordinate realCord;
	realCord.x = (x) * sizeCell;
	realCord.y =(y)*sizeCell + OFFSETY;
	
	int offset = sizeCell - size;
	if(offset >= 0 ) 
	{
			for(i=realCord.x+offset; i < realCord.x+size+offset; i++)
			{
				for(j=realCord.y+offset; j < realCord.y+size+offset; j++)
				{
					LCD_SetPoint(i,j,color);
				}
			}
	}

}

void printPacman()
{
	int i,j;
	coordinate realCord;
	realCord.x = (game.positionOfPacman.x) * sizeCell;
	realCord.y =(game.positionOfPacman.y)*sizeCell + OFFSETY;
	

	for(i=realCord.x; i < realCord.x+sizeCell; i++)
	{
		for(j=realCord.y; j < realCord.y+sizeCell; j++)
		{
			if(game.pacmanDirection == Right)
			{
				if(i-realCord.x == 0 && (j-realCord.y == 0 || j-realCord.y == 4)) continue;
				if(i-realCord.x == 3 && j-realCord.y != 0 && j-realCord.y != 4) continue;
				if(i-realCord.x == 2 && (j-realCord.y == 2)) continue;
				if(i-realCord.x == 4) continue;

			}else if(game.pacmanDirection == Left)
			{
				if(i-realCord.x == 4 && (j-realCord.y == 0 || j-realCord.y == 4)) continue;
				if(i-realCord.x == 1 && j-realCord.y != 0 && j-realCord.y != 4) continue;
				if(i-realCord.x == 2 && (j-realCord.y == 2)) continue;
				if(i-realCord.x == 0) continue;
			}else if(game.pacmanDirection == Up)
			{
				if(j-realCord.y == 4 && (i-realCord.x == 0 || i-realCord.x == 4)) continue;
				if(j-realCord.y == 1 && i-realCord.x != 0 && i-realCord.x != 4) continue;
				if(j-realCord.y == 2 && (i-realCord.x == 2)) continue;
				if(j-realCord.y == 0) continue;
			}else if(game.pacmanDirection == Down)
			{
				if(j-realCord.y == 0 && (i-realCord.x == 0 || i-realCord.x == 4)) continue;
				if(j-realCord.y == 3 && i-realCord.x != 0 && i-realCord.x != 4) continue;
				if(j-realCord.y == 2 && (i-realCord.x == 2)) continue;
				if(j-realCord.y == 4) continue;

			}
			
			LCD_SetPoint(i,j,Orange);
		}
	}
}

void printPacManLifes()
{
	int i,j,life;
	for(life=0; life < game.lifes; life++)
	{
			coordinate realCord;
			realCord.x = 15+13*life;
			realCord.y =305;
	
			for(i=realCord.x; i < realCord.x+sizeCell; i++)
			{
				for(j=realCord.y; j < realCord.y+sizeCell; j++)
				{
						if(i-realCord.x == 0 && (j-realCord.y == 0 || j-realCord.y == 4)) continue;
						if(i-realCord.x == 3 && j-realCord.y != 0 && j-realCord.y != 4) continue;
						if(i-realCord.x == 2 && (j-realCord.y == 2)) continue;
						if(i-realCord.x == 4) continue;	
						LCD_SetPoint(i,j,Orange);
				}
			}
	}
}

void movePacman(int up, int down, int left, int right)
{
	char string[10];
	int newScore = game.score;
	if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] != Muro )
	{
		if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] == Pills)
		{
			game.numOfPillsNotTaken--;
			newScore += PillPoint;
		}
		if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] == SuperPills)
		{
			game.numOfPillsNotTaken--;
			newScore += SuperPillPoint;
		}
	
		
		
		if(game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x] != Muro && game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x] != Teleport)
		{
			LCD_setCell(game.positionOfPacman.x,game.positionOfPacman.y,Background);
		}

		
		if(game.score != newScore)
		{
			if(game.score != 0 && game.score % LIFEPOINT*(game.lifesWin+1) == 0)
			{
				game.lifesWin=1;
				game.lifes++;
				printPacManLifes();
			}
				
				sprintf(string,"%d",newScore);
				GUI_Text(205, 25, (uint8_t *) string, White, Black);
				game.score=newScore;
		}
		if(game.numOfPillsNotTaken == 0)
		{
			 victory();
		}
		
		if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] == Teleport)
		{
			if(game.positionOfPacman.x+right-left == (groupedY -1))
			{
					game.positionOfPacman.x=1;
			}else{
					game.positionOfPacman.x=groupedY-2;
			}
		}else{		
				game.positionOfPacman.x+=+right-left;
				game.positionOfPacman.y+=-up+down;
		}
		
		game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x] = Pacman;

		printPacman();
		
	}
}

void movePacmanRight()
{
	movePacman(0,0,0,1);
}
void movePacmanLeft()
{
	movePacman(0,0,1,0);
}
void movePacmanUp()
{
	movePacman(1,0,0,0);
}
void movePacmanDown()
{
	movePacman(0,1,0,0);
}

void gameOver()
{
	game.timer=0;
	game.status = GameOver;
	disable_timer(0);
	disable_timer(1);
	disable_RIT();
	
	GUI_Text(65, 158, (uint8_t *) " Game Over!", Red, Black);
	
}
void victory()
{
	game.timer=0;
	game.status = Win;
	disable_timer(0);
	disable_timer(1);
	disable_RIT();
	
	GUI_Text(79, 158, (uint8_t *) "Victory!", Yellow, Black);
	
}

void pause()
{
	game.status = Pause;
	disable_timer(0);
	disable_timer(1);
	
	GUI_Text(90, 158, (uint8_t *) "Pause", White, Black);
}
void resume()
{
	game.status=Playing;
	enable_timer(0);
	enable_timer(1);
	
	GUI_Text(90, 158, (uint8_t *) "Pause", Black, Black);	
}

void generateSuperPills()
{
	int i;
	int minX = 3, minY=3, maxX= groupedX-2, maxY=groupedY-2,randomNumberX,randomNumberY;
	srand(LPC_RIT->RICOUNTER & LPC_TIM0->TCR);
	
	for(i=0; i < NUMOFSUPERPILLS; i++)
	{
		game.superPillsGeneration[i].time = rand()% 60 +1 ;
			 
			do{
				randomNumberX = (rand() % (maxX - minX + 1)) + minX;
				randomNumberY = (rand() % (maxY - minY + 1)) + minY;

			}while(game.labirinth[randomNumberX][randomNumberY] != 1);	
			
			game.superPillsGeneration[i].position.x = randomNumberX;
			game.superPillsGeneration[i].position.y = randomNumberY;
	}
	bubbleSortForSuperPillsArray();
	
}


void bubbleSortForSuperPillsArray() {
    int i, j;
		superPillsHandle temp;
    for (i = 0; i < NUMOFSUPERPILLS-1; i++) {
        for (j = 0; j < NUMOFSUPERPILLS - i - 1; j++) {
            if (game.superPillsGeneration[j].time < game.superPillsGeneration[j+1].time) {
                // Scambia gli elementi
                temp = game.superPillsGeneration[j];
                game.superPillsGeneration[j] = game.superPillsGeneration[j+1];
                game.superPillsGeneration[j+1] = temp;
            }
        }
    }
}