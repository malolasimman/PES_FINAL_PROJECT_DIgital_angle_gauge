
/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : GPIO_RESET.h
Created on : 8-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/
#ifndef GPIO_RESET_H_
#define GPIO_RESET_H_

#define SW1_POS (7) //on Port D7 pin19
#define MASK(x) (1UL << (x))

void Initialize_Interrupts(void);


#endif /* GPIO_RESET_H_ */
