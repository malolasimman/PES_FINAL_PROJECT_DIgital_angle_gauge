/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : MMA8451.h
Created on : 7-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/
/* -------------------------------------------------- /
                    	INCLUDE
/ -------------------------------------------------- */
#ifndef MMA8451_H_
#define MMA8451_H_
#include "PES_FINAL_PROJECT.h"
/* -------------------------------------------------- /
                    	MACROS
/ -------------------------------------------------- */
#define MMA_ADDR 0x3A
#define REG_XHI 0x01
#define REG_XLO 0x02
#define REG_YHI 0x03
#define REG_YLO 0x04
#define REG_ZHI	0x05
#define REG_ZLO 0x06
#define REG_WHOAMI 0x0D
#define REG_CTRL1  0x2A
#define REG_CTRL4  0x2D
#define WHOAMI 0x1A
#define COUNTS_PER_G (4096.0)
#define M_PI (3.14159265)
/* -------------------------------------------------- /
               FUNCTION DECLARATIONS
/ -------------------------------------------------- */
int init_mma(void);
void read_full_xyz(void);
void read_xyz(void);
void convert_xyz_to_roll_pitch(void);
void Delay (uint32_t dly);
/* -------------------------------------------------- /
               GLOBAL VARIABLES
/ -------------------------------------------------- */
extern float roll, pitch;
extern int16_t acc_X, acc_Y, acc_Z;
typedef struct guage_axis{
	int roll;
	int pitch;
	int yaw;
}accelerometer_axis;


#endif /* MMA8451_H_ */
