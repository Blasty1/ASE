/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <string.h>
#include "LPC17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include <stdio.h> /*for sprintf*/
#include "sample.h"

extern volatile PACMAN game;
/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/


void TIMER0_IRQHandler (void)
{
	static int  i=0;
	static int numOfPillsGenerated=0;
	int randomNumberY ,randomNumberX;
	char stringa[3];
	game.timer--;
	if(game.timer < 0 && game.numOfPillsNotTaken != 0){
			gameOver();
	}else if(game.timer < 0)
	{
		victory();
	}
	if(game.timer < 10)
	{
			sprintf(stringa,"0%d",game.timer);
	}else{
			sprintf(stringa,"%d",game.timer);
	}
	
	GUI_Text(40, 25,(uint8_t * )stringa , White, Black);

	if(numOfPillsGenerated < NUMOFSUPERPILLS)
	{
		if ( game.superPillsGeneration[numOfPillsGenerated].time == game.timer)
		{
			game.labirinth[\
					game.superPillsGeneration[numOfPillsGenerated].position.y\
			]\
			[
				game.superPillsGeneration[numOfPillsGenerated].position.x\
			] = 2;
			printSquare(game.superPillsGeneration[numOfPillsGenerated].position.y,game.superPillsGeneration[numOfPillsGenerated].position.x,5,Orange);
			numOfPillsGenerated++;
		}
	}
	
		
	LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
	switch(game.pacmanDirection)
	{
		case Right:
			movePacmanRight();
			break;
		case Left:
			movePacmanLeft();
			break;
		case Up:
			movePacmanUp();
			break;
		case Down:
			movePacmanDown();
			break;
	}
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER2_IRQHandler (void)
{
	moveGhost();
	
	//aggiorno la velocit� del timer 2 per far andare pi� o meno veloce il ghost
	switch(game.timer)
	{
		case 45:
			break;
		case 30:
			break;
		case 20:
			break;
		case 10:
			break;
	}		
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
