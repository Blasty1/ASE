#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile uint8_t VETT[MAX]={35,20,80,46};
volatile uint8_t VETT2[MAX];
volatile uint8_t RES[MAX];
volatile int currentValue=0;
extern unsigned char analisi_accuratezza(unsigned char VETT[], unsigned char VETT2[], const unsigned int N, char RES[]);
volatile int media;
volatile int indexRES=-1;


void stampaValoreSuiLED()
{
	LED_Out(VETT[currentValue]);
}

void blinkLED(double blinkPeriod,double totalPeriod)
{

	LED_Out(RES[indexRES]);
	init_timer(0,0,XXI,blinkPeriod/2*25000000);
	init_timer(0,1,XRI,blinkPeriod*25000000);
	init_timer(1,0,SRI,totalPeriod*25000000);
	enable_timer(0);
	enable_timer(1);
}
void seeResult()
{
	media = analisi_accuratezza((unsigned char* ) VETT,(unsigned char*) VETT2,MAX,( char *)RES);
	
	if(RES[indexRES] > media)
	{
		blinkLED(0.100,0.5);
	}else
	{
		blinkLED(0.250,1.0);
	}
}
