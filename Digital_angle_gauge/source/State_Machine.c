
/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : State_Machine.c
Created on : 7-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/
#include "State_Machine.h"
#include "PES_FINAL_PROJECT.h"
#include "PWM.h"
#include "UART.h"
#include "MMA8451.h"
#include "TSI.h"
#include "Systick.h"
#include "Command_Processor.h"
extern __IO int touch_flag;
extern int flag;
extern __IO uint8_t Switch_pressed;
Digital_Angle_guage new_state ;
int reference_angle1=0,reference_angle2=0,roll_angle=0,pitch_angle=0;
extern float ref_roll,ref_pitch;

#define Wait_time 16
ticktime_t current_time;
typedef enum
{
    ANGLE_30 = 30,
	ANGLE_45 = 45,
	ANGLE_60 = 60,
	ANGLE_90 = 90
}eangles_detected;
int roll_degree,pitch_degree;

void actual_angle(){

	roll_degree= (roll_angle-reference_angle1);
	pitch_degree= (pitch_angle-reference_angle2);

}
Digital_Angle_guage calibrate2zero(){

	RGB_LED_Control(0,0,SET_COLOR);
	read_full_xyz();
	convert_xyz_to_roll_pitch();

	if(roll == 0.0)
	{
		convert_xyz_to_roll_pitch();
		/* set the colors to the desired as per the angle under consideration*/
		RGB_LED_Control(0,0,0);
		if(ref_roll < 0)
				{
					ref_roll = (-1* ref_roll);
				}
				if(ref_pitch < 0)
				{
					ref_pitch = (-1* ref_pitch);
				}
		printf("Reference roll value is %d\r\n",reference_angle1);
		printf("Reference pitch value is %d\r\n",reference_angle2);
		printf("Roll value is %d\r\n",(int)roll);
		printf("Pitch value is %d\r\n",(int)pitch);
		printf("Calibration done for ZERO\r\n");

		change_reference_angle(roll_angle,pitch_angle);

		return ANGLE_DISPLAY_STATE;
	}
	return INIT_STATE;
}
Digital_Angle_guage calibrate2state()
{
	int flag1=0;
	if(touch_val()>20){
		printf("CALIBRATE STATE CAP TAP detected\r\n");
		flag1=1;
	}
	if(flag1==1||flag==1)
	{
		flag1=0;
		read_full_xyz();
		convert_xyz_to_roll_pitch();

		change_reference_angle(roll_angle,pitch_angle);

		return ANGLE_DISPLAY_STATE;
	}
	RGB_LED_Control(OFF,OFF,OFF);
	return CALIBRATE_STATE;
}

void change_reference_angle(int ref1_val, int ref2_val)
{
	reference_angle1 = ref1_val;
	reference_angle2 = ref2_val;
	if(reference_angle1<0){
		reference_angle1=reference_angle1*-(1);
	}
	if(reference_angle2<0){
		reference_angle2=reference_angle2*(-1);
	}
	printf("Reference roll value is %d\r\n",reference_angle1);
}

void digital_angle_FSM()
{

	switch(new_state)
	{
		case INIT_STATE:
		{
			new_state = calibrate2zero();
			break;
		}
		case CALIBRATE_STATE:
		{
			new_state = calibrate2state();
			break;
		}
		case ANGLE_DISPLAY_STATE:
		{
			new_state = Angle_guage();
			break;
		}


	}
}
Digital_Angle_guage Angle_guage()
{
	read_full_xyz();
	convert_xyz_to_roll_pitch();
	roll_degree= fabs(roll_angle-reference_angle1);
		pitch_degree= fabs(pitch_angle-reference_angle2);

		if((roll_degree==0) ||(roll_degree==30) || (roll_degree==45) || (roll_degree==60) || (roll_degree==90))
		{
			printf("%d degree detected\r\n",roll_degree);
			assign_color(roll_degree);
		}
		else{
			RGB_LED_Control(0,0,0);
			printf("%d degree detected\r\n",roll_degree);
		}


	if((pitch_degree==0)||(pitch_degree==30) || (pitch_degree==45) || (pitch_degree==60) || (pitch_degree==90))
		{
			assign_color(pitch_degree);
		}
	else{
		RGB_LED_Control(0,0,0);
	}


	if(Switch_pressed)
	{

		printf("Button press detected\r\n");
		Switch_pressed = 0;

		printf("To confirm press touch slider detected\r\n");
		printf("Waiting for Touch to confirm reset reference level\r\n");

		return CALIBRATE_STATE;
	}
	return ANGLE_DISPLAY_STATE;
}



void assign_color(int color_assigner)
{

	if (color_assigner==30)
	{
		RGB_LED_Control(SET_COLOR,0,0);
	}
	else if (color_assigner==45)
	{
		RGB_LED_Control(0,SET_COLOR,0);
	}
	else if(color_assigner==60)
	{
		RGB_LED_Control(0,0,SET_COLOR);
	}
	else if (color_assigner==90)
	{
		RGB_LED_Control(SET_COLOR,SET_COLOR,SET_COLOR);
	}
	else
	{
		RGB_LED_Control(0,0,0);
	}

}

