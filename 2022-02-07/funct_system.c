#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile livelloSoddisfazione stats = {0,0,0};
volatile livelloSoddisfazione statsPercentuali = {0,0,0};

volatile int total_number_of_clients;
volatile int statPrinting;

void addStats(int value)
{
	switch(value)
	{
		case 0:
			stats.I++;
			LED_Out(0b100000);
			break;
		case 1:
			stats.S++;
			LED_Out(0b1000);
			break;
		case 2:
			stats.N++;
			LED_Out(0b10000);
			break;
	}
	init_timer(0,0,SRI,25000000);
	enable_timer(0);
}
void printNumberOfClients()
{
		LED_Out(total_number_of_clients);
		init_timer(0,0,SRI,50000000);
		enable_timer(0);
}
void accendiLedCorrispondente(int value)
{
	switch(value)
	{
		case 0:
			LED_Out(0b100000);
			break;
		case 1:
			LED_Out(0b1000);
			break;
		case 2:
			LED_Out(0b10000);
			break;
	}
}
void stampaValoreStatistica(int value)
{
	switch(value)
	{
		case 0:
			LED_Out(statsPercentuali.I);
			break;
		case 1:
			LED_Out(statsPercentuali.S);
			break;
		case 2:
			LED_Out(statsPercentuali.N);
			break;
	}
}
void printStats()
{
	statPrinting=0;
	
	accendiLedCorrispondente(statPrinting);
	init_timer(1,0,XXI,2500000);
	init_timer(1,1,XRI,5000000);
	enable_timer(1);
	
	init_timer(2,0,XRI,50000000);
	enable_timer(2);
	
}