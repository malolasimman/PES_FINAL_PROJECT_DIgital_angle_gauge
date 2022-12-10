/*
 * 	Author: MalolaSimman Srinivasan Kannan
 *  File name: TSI_Init.c
 *  Created on: 8-DEC-2022
 *  Use: Touch initialization and its interrupt handler
 *  Reference code Author: Alexander G. Dean
 *  Code Reference 1: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 *  Code Reference 2:https://github.com/alexander-g-dean/ESF/tree/master/NXP/Misc/Touch%20Sense.
 *  Compiler: GCC -Wall -Werror
 */

//************************************************ Headers ***********************************************************

#include "PES_FINAL_PROJECT.h"
#include "TSI.h"

//************************************************ Global Variables *****************************************************

int touch;
__IO int touch_flag;

//************************************************Function Prototypes*********************************************

//Function Description : Initializing the Touch Slider
void Touch_Init()
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK; // enabling the clock
	TSI0->GENCS = TSI_GENCS_MODE(0u)| //operating in non-noise mode
				  TSI_GENCS_REFCHRG(0u)| //reference oscillator charge and discharge value 500nA
			      TSI_GENCS_DVOLT(0u)| //oscillator voltage rails set to default
			      TSI_GENCS_EXTCHRG(0u)| //electrode oscillator charge and discharge value 500nA
			      TSI_GENCS_PS(0u)| // frequency clcok divided by one
			      TSI_GENCS_NSCN(31u) | //scanning the electrode 32 times
			      TSI_GENCS_TSIEN_MASK|  //enabling the TSI module
			      TSI_GENCS_STPE_MASK |  // enabling the TSI in low power modes
			      TSI_GENCS_EOSF_MASK | // writing one to clear the end of scan flag
			      TSI_GENCS_ESOR_MASK | //enabling interrupt using end of scan
			      TSI_GENCS_TSIIEN_MASK; //enabling the TSI interrupt
	    TSI0->DATA =  TSI_DATA_TSICH(10u); // selecting channel 10
	     //enaling interrupt in NVIC
	    NVIC_SetPriority(TSI0_IRQn, 2);
	    NVIC_ClearPendingIRQ(TSI0_IRQn);
	    NVIC_EnableIRQ(TSI0_IRQn);
	    // Allow low leakage stop mode
	    SMC->PMPROT = SMC_PMPROT_ALLS_MASK; //
	    // Enable low-leakage stop mode and regular run mode
	    SMC->PMCTRL = SMC_PMCTRL_STOPM(3) | SMC_PMCTRL_RUNM(0);
	    SMC->STOPCTRL = SMC_STOPCTRL_PSTOPO(0) | SMC_STOPCTRL_VLLSM(3);
	    // Enable LLWU
	    // allow TSI0 to wake LLWU
	    LLWU->ME |= LLWU_ME_WUME4_MASK;

}

//Function Description : Touch Interrupt
void TSI0_IRQHandler (void)
{

	touch = TOUCH_DATA-TOUCH_OFFSET;
	if (TOUCH_DATA>TOUCH_OFFSET)
	{
		touch_flag=1;
	}
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; 	//writing one to clear the flag
}

int touch_val()
{
	if (touch_flag==1) // touch_flag is set if touch is there
	{
		touch_flag=0;
		return touch;
	}
	else return 0;

}







