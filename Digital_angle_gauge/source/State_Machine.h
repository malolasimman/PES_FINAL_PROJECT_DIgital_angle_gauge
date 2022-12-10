/*
 * State_Machine.h
 *
 *  Created on: 07-Dec-2022
 *      Author: malolasimman.s.k
 */

typedef enum
{
	INIT_STATE = 0,					/* In this state the calibration for zero is performed */
    CALIBRATE_STATE,				/* In this state the calibration (reference) is performed */
    ANGLE_DISPLAY_STATE 			/* In this state the angles are displayed */
}Digital_Angle_guage;

Digital_Angle_guage calibrate2zero();
Digital_Angle_guage calibrate2state();
Digital_Angle_guage Angle_guage();
void assign_color(int color_assigner);
void change_reference_angle(int ref1_val,int ref2_val );
void digital_angle_FSM();
void print();
void actual_angle();
#define OFF (0)
#define MSEC_500						(4)
#define Wait_time 						(16)
#define SET_COLOR						(255)
