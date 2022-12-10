/*
Author       	: MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     	    : masr4788@colorado.edu
Subject   	    : Principles of Embedded Software
File	  	    : Systick.h
Created on 		: 21-Nov-2022
University 		: University of Colorado at Boulder
Assignment 		: 07
Code Reference 1: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
Code Reference 2:https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense.
Compiler        : GCC -Wall -Werror
*/

#ifndef SYSTICK_H_
#define SYSTICK_H_

/* -------------------------------------------------- /
                FUNCTION DECLARATION
/ -------------------------------------------------- */
void SysTick_Init(void);
void reset_timer();

/* -------------------------------------------------- /
                    GLOBAL VARIABLES
/ -------------------------------------------------- */
typedef uint32_t ticktime_t; // time since boot, in sixteenth of a second
ticktime_t now();
ticktime_t get_timer();

#endif /* SYSTICK_H_ */
