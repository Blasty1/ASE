/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "sample.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

volatile int down=0;
extern volatile PACMAN game;

void RIT_IRQHandler (void)
{					
	static int status[] = {0,0,0,0};
	static int position=0;
	disable_RIT();	
	if(game.status == Playing){
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	
		/* Joytick UP pressed */
		status[Up]++;
		status[Down]=0;
		status[Left]=0;
		status[Right]=0;
		
		if(status[Up] == 1)
		{
				game.pacmanDirection=Up;
		}
	}else if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytrick Right pressed */
		status[Right]++;
		status[Down]=0;
		status[Left]=0;
		status[Up]=0;
		
		if(status[Right] == 1)
		{
				game.pacmanDirection=Right;
		}
	}else if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytrick Left pressed */
		status[Left]++;
		status[Down]=0;
		status[Right]=0;
		status[Up]=0;
		
		if(status[Left] == 1)
		{
				game.pacmanDirection=Left;
		}
	}else if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	
		/* Joytrick Down pressed */
		status[Down]++;
		status[Left]=0;
		status[Right]=0;
		status[Up]=0;
		
		if(status[Down] == 1)
		{
				game.pacmanDirection=Down;
		}
	}else{
		status[Down]=0;
		status[Left]=0;
		status[Right]=0;
		status[Up]=0;
	}
}
	
	/* button management */
	if(down>=1){ 
		if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){	/* INT0 pressed */
			switch(down){				
				case 2:				/* pay attention here: please see slides 19_ to understand value 2 */
					if(game.status == Playing)
					{
						pause();
					}else if(game.status == Pause)
					{
						resume();
					}
					break;
				default:
					break;
			}
			down++;
		}
		else {	/* button released */
			down=0;			
			NVIC_EnableIRQ(EINT0_IRQn);							 /* enable Button interrupts			*/
			LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection */
		}
	}
/*	else{
			if(down==1)
				down++;
	} */
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	enable_RIT();
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
