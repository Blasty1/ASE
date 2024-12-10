/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "timer.h"
#include "../led/led.h"

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
extern unsigned char led_value;					/* defined in funct_led								*/
unsigned int isONTimer2=0;
unsigned int isONTimer3=0;

void TIMER0_IRQHandler (void)
{
	static uint8_t position = 7;
	static uint8_t sw_count = 0;
	sw_count++;	
	if(sw_count == 10){
		LED_Off(position);
		if(position == 7)
			position = 2;
		else
			position++;
		LED_On(position);
		sw_count = 0;
	}
	/* alternatively to LED_On and LED_off try to use LED_Out */
	//LED_Out((1<<position)|(led_value & 0x3));							
	/* LED_Out is CRITICAL due to the shared led_value variable */
	/* LED_Out MUST NOT BE INTERRUPTED */
  LPC_TIM0->IR |= 1;			/* clear interrupt flag */
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
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}


void TIMER2_IRQHandler (void)
{
	if(isONTimer2)
	{
		LED_Off(0);
	}else{
		LED_On(0);
	}
	isONTimer2 = !isONTimer2;
  LPC_TIM2->IR = 3;			/* clear interrupt flag */ /* 3 perch� utilizzo tutti e 2 i registri MR0 e MR1 e quindi i loro interrupt vanno messi a 0 */
  return;
}


void TIMER3_IRQHandler (void)
{
	if(isONTimer3)
	{
		LED_Off(1);
	}else{
		LED_On(1);
	}
	isONTimer3 = !isONTimer3;

  LPC_TIM3->IR = 3;			/* clear interrupt flag */
  return;
}
/******************************************************************************
**                            End Of File
******************************************************************************/