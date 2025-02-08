#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile int status = 1; //status = 1 significa fase di acquisizione

volatile uint8_t vett_input[DIM];
volatile uint8_t vett_output[DIM];
volatile uint8_t currentPos=0;
extern int traduzione_morse(char* vett_input, char* vett_output);
volatile int RES;
void insertValue(CodiceMorse value)
{
	if(currentPos < DIM)
	{
			vett_input[currentPos++] = value;
	}else{
		vett_input[currentPos-1] = TERMINE;
		value = TERMINE;
	}
	
	switch(value)
	{
		case PUNTO:
			LED_On(7);
			init_timer(0,0,SRI,25000000);
			enable_timer(0);
			break;
		case TRATTINO:
			LED_On(7);
			LED_On(6);
			LED_On(5);
			LED_On(4);
			init_timer(0,0,SRI,25000000);
			enable_timer(0);
			break;
		case TERMINE:
			LED_Out(0xFF);
			init_timer(0,0,SRI,3*25000000);
			enable_timer(0);
			status=0;
		
			RES = traduzione_morse((char * ) vett_input,(char *) vett_output);
			
			break;
	}
}
