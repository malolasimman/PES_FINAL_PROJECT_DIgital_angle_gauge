/*
 * 	Author: MalolaSimman Srinivasan Kannan
 *  File name: PWM.C
 *  Created on: 8-DEC-2022
 *  Use: PWM initialization
 *  Reference code Author: Alexander G. Dean
 *  Code Reference 1: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 *  Code Reference 2:https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense.
 *  Compiler: GCC -Wall -Werror
 */

//************************************************ Headers ***********************************************************

#include "PES_FINAL_PROJECT.h"
#include "PWM.h"
__IO int start_red_val,end_red_val,start_green_val,end_green_val,start_blue_val,end_blue_val;
__IO int red,green,blue;
//************************************************Function Prototypes*********************************************

//Function Description : PWM Initialization
void PWM_Init()
{
	//Enabling Clock to Port D, TPM0 and Port C, TPM2
	SIM->SCGC6 |=SIM_SCGC6_TPM2_MASK;
	SIM->SCGC6 |=SIM_SCGC6_TPM0_MASK;

	//Set Pin to FTM
	// Green FTM2_ch1 MUX ALT 3, Blue FTM0_ch1 MUXALT 4 ,Red FTM3_ch0 MUXALT 3
	PORTB->PCR[GREEN_LED_POS] |= PORT_PCR_MUX(3);
	PORTD->PCR[BLUE_LED_POS] |= PORT_PCR_MUX(4);
	PORTB->PCR[RED_LED_POS] |= PORT_PCR_MUX(3);

	//Configure TPM
	// Set clock source for TPM: 48 MHz
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK);
	//Load the counter and mod
	TPM2->MOD = PWM_PERIOD-1;
	TPM0->MOD = PWM_PERIOD-1;
	// Set TPM count direction to up with a divide by 2 prescaler
	TPM2->SC = TPM_SC_PS(1);
	TPM0->SC = TPM_SC_PS(1);
	// continue operation in debug mode
	TPM2->CONF |= TPM_CONF_DBGMODE(3);
	TPM0->CONF |= TPM_CONF_DBGMODE(3);
	// Set channel 1 to edge-aligned low - true PWM
	TPM2->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
	TPM0->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
	// Set channel 0 to edge-aligned low - true PWM
	TPM2->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
	// set initial duty cycle
	TPM2->CONTROLS[1].CnV=0;
	TPM0->CONTROLS[1].CnV=0;
	TPM2->CONTROLS[0].CnV=0;
	// Start TPM
	TPM2->SC |= TPM_SC_CMOD(1);
	TPM0->SC |= TPM_SC_CMOD(1);
}
// setting pwm color
void RGB_LED_Control(unsigned int red, unsigned int green, unsigned int blue){

	TPM2->CONTROLS[0].CnV=red;

	TPM2->CONTROLS[1].CnV=green;

	TPM0->CONTROLS[1].CnV=blue;

}

