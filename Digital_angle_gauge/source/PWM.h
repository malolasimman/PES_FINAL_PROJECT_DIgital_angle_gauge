/*
 * 	Author: MalolaSimman Srinivasan Kannan
 *  File name: PWM.h
 *  Created on: 8-DEC-2022
 *  Use: PWM header file
 *  Reference code Author: Alexander G. Dean
 *  Code Reference 1: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 *  Code Reference 2:https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense.
 *  Compiler: GCC -Wall -Werror
 */
//************************************************ Defining Macros ****************************************************

#define PWM_PERIOD 255

//************************************************ Function Declarations *********************************************

void PWM_Init();
void RGB_LED_Control(unsigned int red, unsigned int green, unsigned int blue);
