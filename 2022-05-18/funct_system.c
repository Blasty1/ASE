#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

#define MAX 3
#define MIN 1

volatile int status = 1;
volatile uint8_t VETT[DIM];
volatile uint8_t currentPos=0;
volatile uint8_t VAR;
volatile int32_t result;
volatile int flag=0;

extern unsigned int totale_pressioni_con_filtro(unsigned char VETT[], unsigned int  numero_misure, unsigned char MAX1, unsigned char MIN1);
//timer 0 per blink showVARonLED
//timer 1 per stampare il risultato

void endProcess()
{
	result = totale_pressioni_con_filtro((unsigned char*) VETT, currentPos,MAX,MIN);
	status=0;
	init_timer(1,0,XRI,1.5*25000000);
	enable_timer(1);
}
void showVARonLED()
{
	if(VAR != 0xFF )
	{
		LED_Out(VAR);
	}else{
		LED_Out(0xFF);
		init_timer(0,0,XXI,25000000);
		init_timer(0,1,XRI,50000000);
		enable_timer(0);
	}
}

void fillVETT()
{
	disable_timer(0);
	LED_Out(0);
	if(VAR < 10 )
	{
		VETT[currentPos++]=VAR;
	}else{
		currentPos = 0;
		VAR = 0;
	}
	if(currentPos == DIM)
	{
		endProcess();
	}
}