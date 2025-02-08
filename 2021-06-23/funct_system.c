#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile unsigned char VAR=0;
volatile unsigned char VETT[DIM];
volatile int status=1;
volatile int currentPos=0;
extern unsigned int sopra_la_media(unsigned char VETT[], unsigned int n); 	
/* dove n è numero attuale elementi usati in VETT */
volatile unsigned int count;
void setVAR(int value)
{
	if(value > 255)
	{
		VAR=255;
	}else if(value < 0 )
	{
		VAR = 0;
	}else{
		VAR = value;
	}
	
	LED_Out_inv(VAR);
}


void showResults()
{
	count= sopra_la_media((unsigned char * )VETT,currentPos);
	status=0;
	if(count <= 255)
	{
		LED_Out(count);
	}else{
		LED_Out(0xAA);
		init_timer(0,0,XXI,0.005*25000000);
		init_timer(0,1,XRI,0.01*25000000);
		enable_timer(0);
	}
	
}
