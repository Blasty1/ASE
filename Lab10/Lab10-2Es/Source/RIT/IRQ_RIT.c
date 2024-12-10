/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../sample.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
extern uint32_t circular_buffer[N];
extern uint32_t index;

void bubbleSort(uint32_t* arr, uint32_t numberOfElements);
float average(uint32_t*, uint32_t );
void cleanVector(uint32_t*,uint32_t,uint32_t);


void RIT_IRQHandler (void)
{					
	static int position=0;	
	static down=0;
	
	down++;
	if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){   //key1
		reset_RIT(); 
		switch(down){
			case 1:
					bubbleSort(circular_buffer,N);
					average(circular_buffer,N);
					cleanVector(circular_buffer,N,0xCAFECAFE);
				break;
			default:
				break;
		}
	}
	else {	/* button released */
		down=0;			
		disable_RIT();
		reset_RIT();
		NVIC_EnableIRQ(EINT1_IRQn);							 /* disable Button interrupts			*/
		LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 0 pin selection */
	}

			
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

void bubbleSort(uint32_t* arr, uint32_t numberOfElements)
{
	int i,tmp,j;
	int swapped;
	for(i=0; i < numberOfElements-1; i++)
	{
		swapped=0;
		for(j=0;i < numberOfElements - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				swapped = 1;
			}
			
			if(swapped == 0 )
			{
				return;
			}
		}	
	}
}

float average(uint32_t* arr, uint32_t numberOfElements)
{
	int i;
	int sumOfElements=0;
	float avg;
	
	for(i=0; i < numberOfElements; i++)
	{
		sumOfElements += arr[i];
	}	
	
	avg = sumOfElements / numberOfElements;

	return avg;
}

void cleanVector(uint32_t* arr,uint32_t numberOfElements,uint32_t mask)
{
	
	int i;
	for(i=0; i < numberOfElements; i++)
	{
		circular_buffer[i] &= mask;
	}
}



/******************************************************************************
**                            End Of File
******************************************************************************/
