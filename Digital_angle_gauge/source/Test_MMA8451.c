/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : Test_MMA8451.c
Created on : 9-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/
/* -------------------------------------------------- /
                    INCLUDES
/ -------------------------------------------------- */
#include "Test_MMA8451.h"
#include "fsl_debug_console.h"
#include "State_Machine.h"
#include "PWM.h"
#include "Systick.h"

/* -------------------------------------------------- /
              FUNCTION DEFINITIONS
/ -------------------------------------------------- */
// assigning color wrt to angle
void test_color_assign(int roll_color,int pitch_color)
{
	if(roll_color==30||pitch_color==30)
		{
			RGB_LED_Control(255,0,0);
		}
	else if(roll_color==45||pitch_color==45)
		{
			RGB_LED_Control(0,255,0);
		}
	else if(roll_color==60||pitch_color==60)
		{
			RGB_LED_Control(0,0,255);
		}
	else if(roll_color==90||pitch_color==90)
		{
	        RGB_LED_Control(255,255,255);
		}
	}

// testing angles
void test_angle_detect_color()
{
	/* angle 0 test case */
	test_color_assign(0,0);
	reset_timer();
	while(get_timer() <MSEC_500);
	PRINTF("\n\r0 degree not detected as not present. No color on.\r\n");

	/* angle 30 test case */
	test_color_assign(30,30);
	reset_timer();
	while(get_timer() < MSEC_500);
	PRINTF("30 degree detected. Red color on.\r\n");

	/* angle 45 test case */
	test_color_assign(45,45);
	reset_timer();
	while(get_timer() < MSEC_500);
	PRINTF("45 degree detected. Green color on.\r\n");

	/* angle 60 test case */
	test_color_assign(60,60);
	reset_timer();
	while(get_timer() < MSEC_500);
	PRINTF("60 degree detected. Blue color on.\r\n");

	/* angle 90 test case */
	test_color_assign(90,90);
	reset_timer();
	while(get_timer() < MSEC_500);
	PRINTF("90 degree detected. White color on.\r\n");

	/* angle -1 test case */
	test_color_assign(-1,-1);
	reset_timer();
	while(get_timer() < MSEC_500);
	PRINTF("Invalid angle. No color on.\r\n");

}
