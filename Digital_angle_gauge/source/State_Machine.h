/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : State_Machine.h
Created on : 7-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/

/* -------------------------------------------------- /
                  GLOBAL VARIABLE
/ -------------------------------------------------- */
typedef enum
{
	INIT_STATE = 0,					/* In this state the calibration for zero is performed */
    CALIBRATE_STATE,				/* In this state the calibration (reference) is performed */
    ANGLE_DISPLAY_STATE 			/* In this state the angles are displayed */
}Digital_Angle_guage;

/* -------------------------------------------------- /
                  FUNCTION DECLARATION
/ -------------------------------------------------- */
Digital_Angle_guage calibrate2zero();
Digital_Angle_guage calibrate2state();
Digital_Angle_guage Angle_guage();
void assign_color(int color_assigner);
void change_reference_angle(int ref1_val,int ref2_val );
void digital_angle_FSM();
void print();
void actual_angle();

/* -------------------------------------------------- /
                  MACROS
/ -------------------------------------------------- */
#define OFF (0)
#define MSEC_500						(4)
#define Wait_time 						(16)
#define SET_COLOR						(255)
