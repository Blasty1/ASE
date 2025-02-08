#include "LPC17xx.h"                    /* LPC17xx definitions                */

typedef struct
{
	uint32_t S;
	uint32_t N;
	uint32_t I;

} livelloSoddisfazione;

void addStats(int);
void printNumberOfClients();
void printStats();
void accendiLedCorrispondente(int value);
void stampaValoreStatistica(int value);
