#include "sample.h"
#include "led/led.h"
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "timer/timer.h"

volatile status ModalitaSistema;

volatile int8_t valore_iniziale=-1;
volatile int32_t tempi_variazioni[MAX];
volatile int8_t counterVar=0;
extern unsigned char duty_cycle(unsigned char valore_iniziale, unsigned int tempo_totale, unsigned int tempi_variazioni[], unsigned char numero_variazioni);
void setModalitaMonitor()
{
	ModalitaSistema = Monitor;
	init_timer(0,0,XXI, 25000000);
	init_timer(0,1,XRI,50000000);
	enable_timer(0);
}
void printNumVariazioni()
{
	LED_Out(counterVar);
	LED_On(7);
}
void printDutyCycle()
{
	LED_Out(duty_cycle((int8_t) valore_iniziale,1,(unsigned int *) tempi_variazioni, (int8_t) counterVar));
	LED_Off(7);
}
