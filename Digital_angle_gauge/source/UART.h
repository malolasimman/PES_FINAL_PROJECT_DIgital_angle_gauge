/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : UART.h
Created on : 07-Nov-2022
University : University of Colorado at Boulder
Assignment : 06
Reference  : https://github.com/alexander-g-dean/ESF/tree/master/NXP/Code/Chapter_8/Serial-Demo
*/
#ifndef UART_H_
#define UART_H_

/* -------------------------------------------------- /
              	 INCLUDES & DEFINES
/ -------------------------------------------------- */
#include "PES_FINAL_PROJECT.h"
#include "cbfifo.h"
#include "sysclock.h"
#define UART_OVERSAMPLE_RATE 	(16)	// OVERSAMPLE RATE
#define BUS_CLOCK 				(24e6)	// BUS CLOCK FREQUENCY AS 24MHz
#define SYS_CLOCK				(48e6)	// SYSTEM CLOCK FREQUENCY AS 48MHz
#define Baudrate				(38400)

/* -------------------------------------------------- /
                FUNCTION DECLARATIONS
/ -------------------------------------------------- */
void Init_UART0(uint32_t baud_rate);

/* -------------------------------------------------- /
              	 GLOBAL VARIABLES
/ -------------------------------------------------- */
extern CbFifo Tx, Rx;
#endif /* UART_H_ */
