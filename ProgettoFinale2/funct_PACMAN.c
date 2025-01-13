#include "sample.h"
#include<stdio.h>
#include<string.h>
#include "RIT/RIT.h"
#include "timer/timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void printWholeMatrix();
void printPacManLifes();
void victory();
void pause();
void printSquare(int,int, int,int );
void printPacman();
void printGhost();
void generateSuperPills();
void gameOver();
void bubbleSortForSuperPillsArray();
int get_pseudo_random(int min, int max);
unsigned int generate_better_seed();
void init_ghost();
coordinate getNextMove(coordinate, int);
void removePacManLifeOnDisplay();
void pacmanIsTaken();

extern volatile unsigned short AD_current;   

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
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  4, 4,  4,  4, 4,  -1,  -1,  -1,  -1,  -1,  0,  0,  0, -1,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,   -1},
				{3, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  -1,  -1,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
				{3, 0 ,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
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
	
	init_ghost();
	printWholeMatrix();//stampiamo la matrice
	printPacManLifes();
	GUI_Text(15, 10, (uint8_t *) "Time", White, Black);
	GUI_Text(40, 25, (uint8_t *) "60", White, Black);
	GUI_Text(190, 10, (uint8_t *) "Score", White, Black);
	GUI_Text(205, 25, (uint8_t *) "00", White, Black);
	
	init_timer(0,0,0x17D7840); //tempo del gioco 1s
	init_timer(1,0,0x2625A0); // aggiornamento movimento pacman , 0.1s
	init_RIT(0x4C4B40); //ogni 50ms

	//per la musica
	init_timer(0,0,0x989680);
	init_timer(3,0,2120);
	
	
	enable_RIT();
	NVIC_SetPriority(RIT_IRQn,0);
	NVIC_SetPriority(TIMER0_IRQn,0);
	NVIC_SetPriority(TIMER1_IRQn,2);
	NVIC_SetPriority(TIMER2_IRQn,1);
	NVIC_SetPriority(TIMER3_IRQn,2);

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
	}else if(objectToPrint == Ghost)
	{
		printGhost();
	}else if(objectToPrint == UscitaBoxGhost)
	{
		printSquare(x,y,5,Red);
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

void printGhost()
{
	int i,j;
	coordinate realCord;
	realCord.x = (game.ghost.positionOfGhost.x) * sizeCell;
	realCord.y =(game.ghost.positionOfGhost.y)*sizeCell + OFFSETY;
	

	for(i=realCord.x; i < realCord.x+sizeCell; i++)
	{
		for(j=realCord.y; j < realCord.y+sizeCell; j++)
		{
		
			if((i-realCord.x == 0  || i-realCord.x == 4 ) && (j-realCord.y == 0)) continue;
			if( ( i-realCord.x == 1 || i-realCord.x == 3) && ( j-realCord.y == 4 ) ) continue;
			
			if((i-realCord.x == 1 || i-realCord.x == 3) && (j-realCord.y == 1))
			{
				LCD_SetPoint(i,j,White);
			}else {
					if(game.ghost.status == FrightendMod)
					{
							LCD_SetPoint(i,j,Blue);
					}else{
							LCD_SetPoint(i,j,Red);
					}
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
void removePacManLifeOnDisplay()
{
		int i,j;
		coordinate realCord;
		realCord.x = 15+13*game.lifes;
		realCord.y =305;

	for(i=realCord.x; i < realCord.x+sizeCell; i++)
		{
			for(j=realCord.y; j < realCord.y+sizeCell; j++)
			{
					LCD_SetPoint(i,j,Black);
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
void moveGhost()
{
	char string[20];
	coordinate newPos;
	
	if(game.labirinth[game.ghost.positionOfGhost.y][game.ghost.positionOfGhost.x] == UscitaBoxGhost)
	{
		game.ghost.status = ChaseMode;
	}
	LCD_setCell(game.ghost.positionOfGhost.x,game.ghost.positionOfGhost.y,game.labirinth[game.ghost.positionOfGhost.y][game.ghost.positionOfGhost.x]);
	
	//aggiorniare posizione del ghost
	if(game.ghost.status == FrightendMod)
	{
				newPos = getNextMove(game.positionOfPacman,0);
	}else if(game.ghost.status == ChaseMode){
		newPos = getNextMove(game.positionOfPacman,1);
	}else if(game.ghost.status == OutOfBox)
	{
		coordinate positionOfOutBox = {22,19};
		newPos = getNextMove(positionOfOutBox,1);
	}

	game.ghost.positionOfGhost.y = newPos.y;
	game.ghost.positionOfGhost.x = newPos.x;
	printGhost();
	
	if(game.ghost.positionOfGhost.x == game.positionOfPacman.x && game.ghost.positionOfGhost.y == game.positionOfPacman.y)
	{
		if(game.ghost.status == ChaseMode)
			{
					pacmanIsTaken();
			}
			return;
	}
	
	game.ghost.historyOfPositions[BeforeBefore]= game.ghost.historyOfPositions[Before];
	game.ghost.historyOfPositions[Before]=newPos;
}
void pacmanIsTaken()
{
		game.lifes--;
		if(game.lifes < 0 )
		{
			gameOver();
			return;
		}
		//bisogna ridurre una vita
		removePacManLifeOnDisplay();
		
		LCD_setCell(game.positionOfPacman.x,game.positionOfPacman.y,Background);
		LCD_setCell(game.ghost.positionOfGhost.x,game.ghost.positionOfGhost.y,Background);
		

		
		init_ghost();
		game.positionOfPacman.x=1;
		game.positionOfPacman.y=23;
		game.pacmanDirection = Right;
				
		printPacman();
		
		pause();
}
void movePacman(int up, int down, int left, int right)
{
	char string[10];
	int newScore = game.score;
	if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] != Muro && game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] != UscitaBoxGhost )
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
			
			game.ghost.status = FrightendMod;
			game.ghost.timeFrightendModStarted = game.timer - TIMEINFRIGHTMOD;
		}
	
		if(game.positionOfPacman.y-up+down == game.ghost.positionOfGhost.y && game.positionOfPacman.x+right-left == game.ghost.positionOfGhost.x )
		{
				disable_timer(1); //se ne occupa l'handler del ghost 
				if(game.ghost.status == FrightendMod)
				{
					game.score += POINTSFORGHOST;
					
					//aggiorno lo score
					sprintf(string,"%d",game.score);
					GUI_Text(205, 25, (uint8_t *) string, White, Black);
					
					//reimposto il fantasma nel rettangolo
					init_ghost();
					game.ghost.timeToWait = game.timer - TIMETOWAITGHOST;
					enable_timer(1);
				}else{
					// se pacman è stato catturato dal ghost allora se ne occupa l'handler del ghost
					return;
				}
		}
		
		
		if(game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x] != Muro && game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x] != Teleport)
		{
			game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x] = Background;
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
	disable_timer(2);
	disable_timer(3);

	
	GUI_Text(65, 158, (uint8_t *) " Game Over!", Red, Black);
	
}
void victory()
{
	game.timer=0;
	game.status = Win;
	disable_timer(0);
	disable_timer(1);
	disable_timer(2);
	disable_timer(3);

	disable_RIT();
	
	GUI_Text(79, 158, (uint8_t *) "Victory!", Yellow, Black);
	
}

void pause()
{
	game.status = Pause;
	disable_timer(0);
	disable_timer(1);
	disable_timer(2);
	disable_timer(3);

	
	GUI_Text(90, 158, (uint8_t *) "Pause", White, Black);
}
void resume()
{
	game.status=Playing;
	enable_timer(0);
	enable_timer(1);
	enable_timer(2);
	enable_timer(3);


	GUI_Text(90, 158, (uint8_t *) "Pause", Black, Black);	
	printGhost();
}

void generateSuperPills()
{
	int i;
	int minX = 3, minY=3, maxX= groupedX-2, maxY=groupedY-2,randomNumberX,randomNumberY;
	srand(generate_better_seed());
	for(i=0; i < NUMOFSUPERPILLS; i++)
	{
		game.superPillsGeneration[i].time = get_pseudo_random(10,60);
			 
			do{
				randomNumberX = get_pseudo_random(minX,maxX);
				randomNumberY =  get_pseudo_random(minY,maxY);
			}while(game.labirinth[randomNumberY][randomNumberX] != 1);	
			
			game.superPillsGeneration[i].position.x = randomNumberX;
			game.superPillsGeneration[i].position.y = randomNumberY;
	}
	bubbleSortForSuperPillsArray();
	
}

void init_ghost()
{
	game.ghost.positionOfGhost.x= 21;
	game.ghost.positionOfGhost.y= 22;	
	game.ghost.timeToWait=-1;
	game.ghost.status = OutOfBox;
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

// Calcola la distanza euclidea tra due punti
double getDistance(coordinate a, coordinate b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Trova la prossima mossa migliore
//con minimizeDistance a 1 lavora cercando il blocco che lo avvicina il più possibile
//cono minimizeDistance a 0 lavora cercando il blocco che più lo allontana
coordinate getNextMove(coordinate destination, int minimizeDistance) {
    // Le 4 possibili direzioni (escluse le diagonali)
		// Su (-1,0)
		// Giù (1,0)
		// Sinistra (0,-1)
		// Destra (0,1)
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0,  0,  -1,1};
		
		int i;
    
    coordinate bestMove = game.ghost.positionOfGhost;
    double minDistance,maxDistance;
		double distance;
		
		if(minimizeDistance == 1 )
		{
			 minDistance = 500000; // virtualmente infinito
		}else
		{
				maxDistance = -1;
		}
    
    // Controlla tutte le possibili mosse
    for(i = 0; i < 4; i++) {
        int newRow = game.ghost.positionOfGhost.y + dr[i];
        int newCol = game.ghost.positionOfGhost.x + dc[i];
        
        // Verifica se la nuova posizione è valida
        if(newRow >= 0 && newRow < groupedY && 
           newCol >= 0 && newCol < groupedX && 
           game.labirinth[newRow][newCol] != Teleport &&
					 game.labirinth[newRow][newCol] != Muro &&
					(game.labirinth[newRow][newCol] != UscitaBoxGhost || game.ghost.status == OutOfBox )
					) {  
						
            coordinate newPos = {newCol,newRow};
            distance = getDistance(newPos, destination);
            
						//se con questa mossa ritorno dove sono stato 2 mosse fa vuoldire che c'è un bug nell'algoritmo, scelgo un altra posizione
						if(game.ghost.historyOfPositions[BeforeBefore].x == newCol && game.ghost.historyOfPositions[BeforeBefore].y == newRow)
						{
							continue;
						}
						if(minimizeDistance == 1 )
						{
						//Aggiorna la migliore mossa se questa è più vicina alla destinazione
							if(distance < minDistance) {
									minDistance = distance;
									bestMove = newPos;
								}						
						}else
						{
							//Aggiorna la migliore mossa se questa è più lontana alla destinazione
							if(distance > maxDistance) {
									maxDistance = distance;
									bestMove = newPos;
								}
						}
           
        }
    }
    
    return bestMove;
}

// Genera un seed più casuale usando più fonti di entropia
unsigned int generate_better_seed() {
    unsigned int seed = 0;
    
    // Usa time() per il timestamp corrente
    seed ^= (unsigned int)time(NULL);
    
    // Usa il process ID
    seed ^= LPC_TIM0->TCR;
	
		seed ^= LPC_TIM1->TCR;
    
    // Usa il clock di CPU
    seed ^= (unsigned int)clock();
	
		seed ^= AD_current;
    
    return seed;
}

// Genera un numero casuale tra min e max (inclusi)
int get_pseudo_random(int min, int max) {
		unsigned long range = (unsigned long)(max - min + 1);
    unsigned long buckets = RAND_MAX / range;
    unsigned long limit = buckets * range;

    
    unsigned long r;
    do {
        r = rand();
        

        
    } while (r >= limit);

    return min + (int)(r / buckets);
}