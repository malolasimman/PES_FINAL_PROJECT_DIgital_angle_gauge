/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : cbfifo.c
Created on : 08-DEC-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
Reference  : https://github.com/alexander-g-dean/ESF/tree/master/NXP/Code/Chapter_8/Serial-Demo
*/
/* -------------------------------------------------- /
                    	INCLUDES
/ -------------------------------------------------- */

#include "cbfifo.h"

/* -------------------------------------------------- /
                 FUNCTION DEFINITION
/ -------------------------------------------------- */
/** Initializing circular buffer **/
void cbfifo_Init(CbFifo * queue)		// Initializing the circular buffer  //
{
  unsigned int i;
  for (i=0; i<CBFIFO_MAX_SIZE; i++)
  queue->buffer[i] = '_';
  queue->front=0;
  queue->rear= 0;
  queue->length = 0;
}

/** Checks Whether circular buffer is Empty **/
int cbfifo_Empty(CbFifo * queue)		 // Returns the length as 1 if empty zero if not returns 0 //
{
  return queue->length == 0;
}

/** Checks Whether circular buffer is full **/
int cbfifo_Full(CbFifo * queue) 		// Returns the capacity of the circular buffer //
{
  return queue->length == CBFIFO_MAX_SIZE;
}
/** Returns circular buffer Length **/
int cbfifo_Length(CbFifo * queue)
{
	return queue->length;
}
/** Add Element to the Circular buffer **/
int cbfifo_Enqueue(CbFifo * queue, void * data,size_t nbyte)	// Returns the 1 if successfully enqueue circular buffer or returns zero if fails to enqueue //
{
	uint8_t *ptr = (uint8_t *)data;
	int green_flag=0;
	uint32_t state_mask;
	if (nbyte<=CBFIFO_MAX_SIZE)
	{
		for (size_t i=0; i<(nbyte); i++)
		{                     										// Iterating for nbytes //

			if (!cbfifo_Full(queue))								// If queue is full, don't overwrite data, but do return an error code
			{
				queue->buffer[queue->rear++] = ptr[i]; 				// Storing the values into the buffer //
				queue->rear = (queue->rear % CBFIFO_MAX_SIZE);   	// Reset rear for circular buffer //
				state_mask = __get_PRIMASK(); 						// protect queue->Size++ operation from preemption
																	// and save current masking state

				__disable_irq(); 									// disable interrupts
				__set_PRIMASK(state_mask); 							// restore  interrupt masking state
				green_flag=1;										// successfully enqueued
			}
			else
			{
				green_flag=0;										// failed to enqueue
			}
		}
		queue->length += nbyte;
	}
	return green_flag;

}

/** Dequeue the Element from the Circular buffer **/
uint8_t cbfifo_Dequeue(CbFifo * queue,size_t nbyte)
{
	uint32_t state_mask; // temp variable for mask
	uint8_t temp=0;
	 if (!cbfifo_Empty(queue)) 	// Check to see if queue is empty before dequeuing
	 {
		 if(nbyte < CBFIFO_MAX_SIZE) //checks requested length is less than circular buffer size
		 {
			 for (size_t i=0; i<nbyte; i++)
			 {

				 temp =queue->buffer[queue->front];       // Copy the data to output which were dequeued from the circular buffer //
				 queue->buffer[queue->front++] = '_';
				 queue->front = queue->front % CBFIFO_MAX_SIZE; // Reset front for circular buffer //
				 state_mask = __get_PRIMASK(); // save current state_mask
				 // disable interrupts
				 __disable_irq();
				 // update length
				 queue->length--;
				 // reload interrupt state_mask
				 __set_PRIMASK(state_mask);

			 }

		 }
	 }
	 return temp; // Returns dequeued element
}
