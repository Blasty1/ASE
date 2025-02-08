#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile uint32_t VETT[DIM];
volatile uint32_t VAR1 =0,VAR2 = 0;
volatile uint32_t current_pos=0;


void addVAR1(int value)
{
	VAR1 += value;
	if(VAR1 > 15 )
	{
		LED_On(7);
		LED_On(6);
		LED_On(5);
		LED_On(4);
		init_timer(0,0,XXI,250000);
		init_timer(0,1,XRI,500000);
		enable_timer(0);
	}else {
		disable_timer(0);
		LED_Out((VAR1<<4 | VAR2) & 0xFF);
	}
}
void addVAR2(int value)
{
	VAR2 += value;
	if(VAR2 > 15 )
	{
		LED_On(0);
		LED_On(1);
		LED_On(2);
		LED_On(3);
		init_timer(1,0,XXI,250000);
		init_timer(1,1,XRI,500000);
		enable_timer(1);
	}else {
		disable_timer(1);
		LED_Out((VAR1<<4 | VAR2) & 0xFF);
	}
}