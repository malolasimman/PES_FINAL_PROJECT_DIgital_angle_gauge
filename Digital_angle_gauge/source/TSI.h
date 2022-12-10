/*
 * 	Author: MalolaSimman Srinivasan Kannan
 *  File name: TSI.h
 *  Created on: 11-OCT-2022
 *  Use: TSI header file
 *  Reference code Author: Alexander G. Dean
 *  Code Reference 1: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 *  Code Reference 2:https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense.
 *  Compiler: GCC -Wall -Werror
 */

//************************************************ Function Declarations *********************************************

void Touch_Init();
int touch_val();

//************************************************ Defining Macros ****************************************************

#define TOUCH_OFFSET 600
#define TOUCH_DATA (TSI0->DATA & 0xFFFF)//macro for extracting the count from data register


