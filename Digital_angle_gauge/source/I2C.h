/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : I2C.h
Created on : 7-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/
#ifndef I2C_H_
#define I2C_H_
/* -------------------------------------------------- /
                    	INCLUDE
/ -------------------------------------------------- */
#include "PES_FINAL_PROJECT.h"
/* -------------------------------------------------- /
                    	MACROS
/ -------------------------------------------------- */
#define I2C_M_START 	I2C0->C1 |= I2C_C1_MST_MASK
#define I2C_M_STOP  	I2C0->C1 &= ~I2C_C1_MST_MASK
#define I2C_M_RSTART 	I2C0->C1 |= I2C_C1_RSTA_MASK

#define I2C_TRAN			I2C0->C1 |= I2C_C1_TX_MASK
#define I2C_REC				I2C0->C1 &= ~I2C_C1_TX_MASK

#define BUSY_ACK 	    while(I2C0->S & 0x01)
#define TRANS_COMP		while(!(I2C0->S & 0x80))
#define I2C_WAIT 			i2c_wait();

#define NACK 	        I2C0->C1 |= I2C_C1_TXAK_MASK
#define ACK           I2C0->C1 &= ~I2C_C1_TXAK_MASK
/* -------------------------------------------------- /
                   FUNCTION DECLARATIONS
/ -------------------------------------------------- */
void i2c_init(void);
void i2c_busy(void);
void i2c_wait(void);
void i2c_start();
void i2c_read_setup(uint8_t dev, uint8_t address);
uint8_t i2c_repeated_read(uint8_t isLastRead);
uint8_t i2c_read_byte(uint8_t dev, uint8_t address);
void i2c_write_byte(uint8_t dev, uint8_t address, uint8_t data);

#endif /* I2C_H_ */
