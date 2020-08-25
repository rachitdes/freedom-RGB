/**
 * @file    RGB_Led.cpp
 * @brief   Application entry point.
 */
//#include <stdio.h>
//#include "board.h"
//#include "peripherals.h"
//#include "pin_mux.h"
//#include "clock_config.h"
#include "MKL25Z4.h"
//#include "fsl_debug_console.h"
#include "delay.hh"

#define RED_LED_LOC (1<<18)
#define GREEN_LED_LOC (1<<19)
#define BLUE_LED_LOC (1<<1)

#define RED_LED_ON

int main ()
{
	SystemCoreClockUpdate ();
	SIM->SCGC5 |= (1<<10) | (1<<12);

	PORTB->PCR[18] |= (1<<8);
	PORTB->PCR[19] |= (1<<8);
	PORTD->PCR[1] |= (1<<8);

	PTB->PDDR |= RED_LED_LOC;
	PTB->PDDR |= GREEN_LED_LOC;
	PTD->PDDR |= BLUE_LED_LOC;

	while(1)
	{

		PTB->PSOR = RED_LED_LOC;
		delay(1000000);
		PTB->PCOR = RED_LED_LOC;
		delay(1000000);


		PTB->PSOR = GREEN_LED_LOC;
		delay(1000000);
		PTB->PCOR = GREEN_LED_LOC;
		delay(1000000);


		PTD->PSOR = BLUE_LED_LOC;
		delay(1000000);
		PTD->PCOR = BLUE_LED_LOC;
		delay(1000000);
	}

	return 0;
}
