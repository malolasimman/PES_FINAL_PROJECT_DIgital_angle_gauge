/*
Author       	: MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     	    : masr4788@colorado.edu
Subject   	    : Principles of Embedded Software
File	  	    : Systick.c
Created on 		: 8-DEC-2022
University 		: University of Colorado at Boulder
Assignment 		: PES_FINAL_PROJECT
Code Reference 1: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
Code Reference 2:https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense.
Compiler        : GCC -Wall -Werror
*/

/* -------------------------------------------------- /
                    INCLUDES
/ -------------------------------------------------- */
#include "PES_FINAL_PROJECT.h"
#include "Systick.h"

/* -------------------------------------------------- /
                    GLOBAL VARIABLES
/ -------------------------------------------------- */
__IO uint32_t count; // counter since last call
__IO uint32_t Real_count; // system time since startup

/* -------------------------------------------------- /
                FUNCTION DEFINITION
/ -------------------------------------------------- */
//Function Description :initialize the Systick timer
void  SysTick_Init(void)
{
	uint32_t ticks= (SystemCoreClock/100); //using system clock 48MHz setting ticks for every 10msec
	SysTick->LOAD  = (uint32_t)(ticks - 1UL);                         /* set reload register */
	NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
	SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
	                 SysTick_CTRL_TICKINT_Msk   |
	                 SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
}

//Function Description : Systick interrupt handler, increments counters every 62.5msec
void SysTick_Handler(void)
{
	Real_count++; //count from startup
	count++; //counter for delay

}

//Function Description : resets timer to 0; doesn't affect now() values
void reset_timer()
{
	count=0;
}

//Function Description : returns time since startup, in sixteenths of a second
ticktime_t now()
{
	return Real_count;
}

//Function Description : returns ticks since the last call to reset_timer()
ticktime_t get_timer()
{
	return count;
}
