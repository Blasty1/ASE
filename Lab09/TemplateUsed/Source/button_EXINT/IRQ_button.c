#include "button.h"
#include "lpc17xx.h"

#include "../led/led.h"

extern unsigned char next_state(unsigned char, unsigned char, int* );
void EINT0_IRQHandler (void)	  
{
	LED_On(0);
  LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


//pulsante KEY1
void EINT1_IRQHandler (void)	  
{
	volatile unsigned char result;
	unsigned char taps = 0x1D;
	int bitOutput; 
	
	
	//stiamo scegliendo 00011101 come taps ( bit 0, 2,3,4), come nell immagine
  result = next_state(returnLedValue(),taps,&bitOutput);
	
	LED_Out((unsigned char) result);
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{
	volatile unsigned char result;
	unsigned char taps = 0x1D, initialState=returnLedValue(),currentState;
	int bitOutput;
	unsigned int count=0;		
	
	currentState = initialState;
	do{
		result = next_state(currentState,taps,&bitOutput);
		currentState = result;
		count++;
	}while(currentState != initialState);
	
	LED_Out(count);

  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


