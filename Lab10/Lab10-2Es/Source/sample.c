/*----------------------------------------------------------------------------
 * Name:    sample.c
 * Purpose: to control led through debounced buttons and Joystick
 *        	- key1 switches on the led at the left of the current led on, 
 *					- it implements a circular led effect,
 * 					- joystick UP function returns to initial configuration (led11 on) .
 * Note(s): this version supports the LANDTIGER Emulator
 * Author: 	Paolo BERNARDI - PoliTO - last modified 15/12/2020
 *----------------------------------------------------------------------------
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2017 Politecnico di Torino. All rights reserved.
 *----------------------------------------------------------------------------*/
                  
#include <stdio.h>
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "../sample.h"

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif
/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
volatile uint32_t circular_buffer[N];
volatile uint32_t index=0;

int main (void) {

	SystemInit();  												/* System Initialization (i.e., PLL)  */
  LED_init();                           /* LED Initialization                 */
  BUTTON_init();												/* BUTTON Initialization              */
	
	init_RIT(0x4C4B40);			 // setto il timer RIT per gestire il bouncing a 50ms ( ipotizzando una frequenza di clock di 100Mhz )
	init_timer(0,0,0x9C4);   // setto il timer 0
	init_timer(1,0,0x1F4); 	 // setto il timer 1

	init_timer(2,0,0x1388);   //10% di 1/500 * 25MHz
	init_timer(2,1,0xC350);											/* FreqTimer 25Mhz
																				 Freq a cui noi vogliamo lavorare 500 Hz -> count � = 1/500 * 25MHz */
	
	
	init_timer(3,0,0x2B98B); /* 50% */
	init_timer(3,1,0x57316); /*  periodo scelto 1/70 */
	
	enable_timer(0);
	enable_timer(1);
	enable_timer(2);
	enable_timer(3);

	LED_On(7); //per vedere la differenza di intensit�
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
		
  while (1) {                           /* Loop forever                       */	
		__ASM("wfi");
  }

}
