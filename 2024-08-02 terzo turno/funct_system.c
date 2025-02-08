#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile unsigned char VETT[DIM] = {1,1,1,2,0,2,1,3,2};
volatile unsigned char VETT2[DIM];
volatile int8_t currentPos=0;
volatile int status=1;
volatile int numDiff;
extern unsigned int compare (unsigned char VETT[], unsigned char VETT2[], const unsigned int N);


//timer 0 per punto 2 e punto 4
//timer 1 per punto 2 
//timer 2 per punto 4
void 	handleLastVisualization()
{
	numDiff = compare((unsigned char*) VETT,(unsigned char *) VETT2,DIM);
	LED_Out(numDiff);
}
void 	sequenceCompleted()
{
   status = 0;
	 init_timer(0,0,XXI,0.125/2*25000000);
	 init_timer(0,1,XRI,0.125*25000000);
	 enable_timer(0);
	

	 init_timer(2,0,SRI,3*25000000);
	 enable_timer(2);

}
void printLEDCombinatino()
{
	while( VETT[currentPos] != 1 && VETT[currentPos] != 2 && currentPos < DIM)
	{
			VETT[currentPos]=0;
			VETT2[currentPos]=0;
			currentPos++;
	}
	if(currentPos < DIM)
	{
		 switch(VETT[currentPos])
		 {
			 case ((unsigned char)0x01):
				 LED_Out(0x01);
				 break;
			 case ((unsigned char) 0x02):
				 LED_Out(0x02);
				 break;
				 
		 }
	}else{
		sequenceCompleted();
	}
}
void newValue(unsigned char value)
{
	if(currentPos < DIM)
	{
		VETT2[currentPos] = value;
		currentPos++;
		LED_Out(0xFF);
		init_timer(0,0,XXI,0.125*25000000);
		init_timer(0,1,XRI,0.25*25000000);
		enable_timer(0);
	
		init_timer(1,0,SRI,25000000);
		enable_timer(1);
		
	}else{
				sequenceCompleted();
	}
}