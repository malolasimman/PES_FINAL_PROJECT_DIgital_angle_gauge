/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : GPIO_RESET.c
Created on : 8-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/
#include"GPIO_RESET.h"
#include "PES_FINAL_PROJECT.h"


__IO uint8_t Switch_pressed=0;

//************************************************Function Prototypes*********************************************
//Function Description: initializing GPIO Interrupt
void Initialize_Interrupts(void)
{

	/* Enable clock source to the pin */
		SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

		/* Setting up port multiplexing for GPIO */
		PORTD->PCR[SW1_POS] &= ~PORT_PCR_MUX_MASK;
		PORTD->PCR[SW1_POS] |= PORT_PCR_MUX(1);

		/* Enable the pull select and pull enable */
		PORTD->PCR[SW1_POS] |= PORT_PCR_PE(1) | PORT_PCR_PS(1);

		/* Enable the interrupt on any edge */
		PORTD->PCR[SW1_POS] |= PORT_PCR_IRQC(11);

		/* Set direction to input */
		GPIOD->PDDR &= ~(1 << SW1_POS);

		/* Set the priroity of switch */
		NVIC_EnableIRQ(PORTD_IRQn);
}

// IRQ handler function
void PORTD_IRQHandler(void)
{
	Switch_pressed = 0;

	if ((PORTD->ISFR & (1 << SW1_POS)))
	{
		Switch_pressed = 0;

		if(	(GPIOD->PDIR & (1 << SW1_POS)) == 0)
		{
			/* Set the switch flag as the
			 * switch is pressed in reality */
			Switch_pressed = 1;
		}
	}

	/* Clear the switch pin flag*/
	PORTD->ISFR |= (1 << SW1_POS);
}
