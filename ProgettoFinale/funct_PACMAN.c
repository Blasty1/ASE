#include "sample.h"
#include<stdio.h>
#include<string.h>


void printWholeMatrix();
void printSquare(int,int, int,int );
void printPacman();

volatile PACMAN game =  //variabile che contiene tutto ciò che riguarda il gioco
	{
		.labirinth = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-1},
        {-1, -1,  -1,  -1,  -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
        {-1, -1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  -1,  -1,  0,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  -1,  -1},
				{-1, -1,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1},		
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
				{-1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1,  0,  0,  0,  0, -1,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  -1,   -1},
				{3, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  -1,  -1,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
				{3, 0 ,  0,  0,  1,  0,  1,  0,  2,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0, 0,  3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
				{3, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1	,  -1,  -1,  0,  0,  0,  0,  0,  0,  -1,  0,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 3},
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
	game.pacmanDirection = Right;
	
	game.positionOfPacman.y=23;
	game.positionOfPacman.x=1;
	game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x]= Pacman;

	printWholeMatrix();//stampiamo la matrice
	GUI_Text(15, 10, (uint8_t *) "Time", White, Black);
	GUI_Text(40, 25, (uint8_t *) "60", White, Black);
	GUI_Text(190, 10, (uint8_t *) "Score", White, Black);
	GUI_Text(205, 25, (uint8_t *) "00", White, Black);
	
	startGame();
}

void startGame()
{
		game.status = Playing;
	
		init_timer(0,0,0x17D7840); //tempo del gioco 1s
		init_timer(1,0,0x2625A0); // aggiornamento movimento pacman , 0.1s
		init_RIT(0x4C4B40); //ogni 50ms
	
		NVIC_SetPriority(RIT_IRQn,0);
		NVIC_SetPriority(TIMER0_IRQn,1);
		NVIC_SetPriority(TIMER1_IRQn,1);

		
		enable_timer(0);
		enable_timer(1);
		enable_RIT();

		
	
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

void movePacman(int up, int down, int left, int right)
{
	char string[10];
	int newScore = game.score;
	if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] != Muro )
	{
		if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] == Pills)
		{
			newScore += PillPoint;
		}
		if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] == SuperPills)
		{
			newScore += SuperPillPoint;
		}
	
		
		
		if(game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x] != Muro && game.labirinth[game.positionOfPacman.y][game.positionOfPacman.x] != Teleport)
		{
			LCD_setCell(game.positionOfPacman.x,game.positionOfPacman.y,Background);
		}

		
		if(game.score != newScore)
		{
				sprintf(string,"%d",newScore);
				GUI_Text(205, 25, (uint8_t *) string, White, Black);
				game.score=newScore;
		}
		
		if(game.labirinth[game.positionOfPacman.y-up+down][game.positionOfPacman.x+right-left] == Teleport)
		{
			if(game.positionOfPacman.x+right-left == (groupedY -1))
			{
					game.positionOfPacman.x=1;
					game.positionOfPacman.y+=-up+down;
			}else{
					game.positionOfPacman.x=groupedY-2;
					game.positionOfPacman.y+=-up+down;
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
}


