#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"


extern volatile uint8_t VAR;
extern volatile uint8_t PRINTING_RES;
extern volatile int8_t RES[MAX-1];
extern volatile uint8_t vett[MAX];
extern volatile KeyType lastKeyPressed;

void printVAROnLED()
{
	 LED_Out(VAR);
	 init_timer(0,0,1,6250000);
	 init_timer(0,1,7,12500000);
	 enable_timer(0);
}
void printRES()
{
	init_timer(1,0,7,7500000);
	enable_timer(1);
	PRINTING_RES=1;
}
void resetALL()
{
	int i=0;
	VAR = 0;
	LED_Out(0);
	for(i=0; i < MAX; i++)
	{
		vett[i]=0;
		RES[i%MAX]=0;
	}
	lastKeyPressed = NotSet;
	PRINTING_RES=0;

}