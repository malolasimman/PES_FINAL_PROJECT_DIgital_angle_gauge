
/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : PES_FINAL_PROJECT.h
Created on : 7-Dec-2022
University : University of Colorado at Boulder
Assignment : 06
*/
/* -------------------------------------------------- /
                    	INCLUDES
/ -------------------------------------------------- */
#ifndef PES_FINAL_PROJECT_H_
#define PES_FINAL_PROJECT_H_
#include <MKL25Z4.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "i2c.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"

/* -------------------------------------------------- /
                      MACROS
/ -------------------------------------------------- */
#define RED_LED_POS 18
#define BLUE_LED_POS 1
#define GREEN_LED_POS 19
#define MASK(x) (1UL << (x))
#define MAINTAIN_REF_LEVEL							(0)

/* -------------------------------------------------- /
                FUNCTION DECLARATION
/ -------------------------------------------------- */
void my_getstring();

#endif /* PES_FINAL_PROJECT_H_ */
