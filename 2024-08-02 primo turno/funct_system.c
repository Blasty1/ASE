#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"


volatile int status=1;
volatile unsigned int VETT[DIM];
volatile unsigned int currentPos=0;
volatile unsigned int VAR=0;
volatile uint8_t LEDval;
// timer0 lo uso per punto 2
//timer1 per la specifica 3

void  printLEDAfterVAR()
{
 int VAR31,VAR23,VAR15,VAR7;

 VAR31 = (VAR & 0xFF000000) >> 24;
 VAR23 = (VAR & 0x00FF0000) >> 16;
 VAR15 = (VAR & 0x0000FF00) >> 8;
 VAR7 = (VAR & 0x000000FF);

 LEDval = (VAR31 | VAR23) ^ (VAR15 & VAR7);
 
 LED_Out(LEDval);
 init_timer(0,0,XXI,0.06*25000000);
 init_timer(0,1,XRI,0.12*25000000);
 enable_timer(0);
}
