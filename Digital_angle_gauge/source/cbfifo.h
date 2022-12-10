/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : cbfifo.h
Created on : 08-DEC-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/
/* -------------------------------------------------- /
                    INCLUDES & DEFINES
/ -------------------------------------------------- */
#ifndef CBFIFO_H_
#define CBFIFO_H_

#include "PES_FINAL_PROJECT.h"
#define CBFIFO_MAX_SIZE 256
/* -------------------------------------------------- /
                    GLOBAL VARIABLES
/ -------------------------------------------------- */
typedef struct cbfifo  								 // Main Circular Buffer - //
{
	unsigned int length;
	unsigned int front;
	unsigned int rear;
    uint8_t buffer[CBFIFO_MAX_SIZE];
}volatile CbFifo;

extern int cbfifo_Empty(CbFifo * queue);
extern int cbfifo_Full(CbFifo * queue);
extern int cbfifo_Length(CbFifo * queue);
extern int cbfifo_Enqueue(CbFifo * queue, void* data,size_t nbyte);
extern uint8_t cbfifo_Dequeue(CbFifo * queue,size_t nbyte);
extern void cbfifo_Init(CbFifo * queue);

#endif /* CBFIFO_H_ */
