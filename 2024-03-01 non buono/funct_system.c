#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile uint8_t VETT[MAX];
volatile int8_t current_position=0;
volatile int8_t valueExtracted;
volatile uint8_t firstPush=0;
volatile int counter=0;

extern unsigned char check_fibonacci(unsigned char* VETT, unsigned char N, unsigned char M, unsigned char VAL, unsigned char BOUNDARY);

void storeValue()
{
	 int flagNonValido = 0;	
	 if ( current_position == 0 )
	 {
		 if(((valueExtracted & 1) == 1))
		 {
			 			flagNonValido = 1;
						counter++;
		 }
	 }else{
		 if(VETT[current_position-1] % 2 == 0 && ((valueExtracted & 1) == 0))
		 {
			 flagNonValido = 1;
		 }else if(VETT[current_position-1] % 2 == 1 && ((valueExtracted & 1) == 1))
		 {
			 flagNonValido = 1;
		 }
		 if(flagNonValido == 1)
		 {
			 LED_Out(0xFF);
			 firstPush = 0;
			 current_position++;
			 counter++;
			 return;
		 }		 
	 }
	 
	  if(check_fibonacci((unsigned char*)VETT,MAX,14,valueExtracted,2))
		 {
			 LED_Out(0xFF);
			 init_timer(1,0,XXI, 6125000);
			 init_timer(1,1,XRI, 12250000);
			 init_timer(3,0,SRI, 50000000);
			 enable_timer(1);
			 enable_timer(3);
			 firstPush=2;
			 current_position++;
		 }else{
			 LED_Out(0xFF);
			 firstPush = 0;
			 counter++;
		 }
		 
		if(current_position+1 == MAX)
	 {
		 LED_Out(counter);
		 init_timer(0,0,XXI, 25000000);
		 init_timer(0,1,XRI, 50000000);
		 current_position = 0;
		 firstPush=0;
	
		 
	 }

}