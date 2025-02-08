#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile int32_t VAR1;
volatile int32_t VETT[MAX];
volatile int16_t numberOfElements=0;
volatile int negativeAndOddElements;
extern int count_negative_and_odd(int* VETT, unsigned int n);
/* where n is the number of VETT elements */
void valueIsReady()
{
	VETT[numberOfElements++] = VAR1;
	VAR1=0;
	if(numberOfElements == MAX)
	{
		numberOfElements = 0;
		negativeAndOddElements= count_negative_and_odd((int * )VETT,MAX);
		
		if(negativeAndOddElements == 0)
		{
			 LED_On(7);
			 init_timer(0,0,XXI,32500000);
			 init_timer(0,1,XRI,52500000);
			 enable_timer(0);
			
		}else{
			LED_Out((int8_t) negativeAndOddElements);
			LED_Off(7);
		}
	}
}