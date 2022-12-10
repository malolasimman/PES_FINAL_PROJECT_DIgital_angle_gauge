
/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : PES_FINAL_PROJECT.c
Created on : 7-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/
#include "Command_Processor.h"
#include "PES_FINAL_PROJECT.h"
#include "PWM.h"
#include "TSI.h"
#include "Systick.h"
#include "sysclock.h"
#include "MMA8451.h"
#include "UART.h"
#include "I2C.h"
#include "State_Machine.h"
#include "GPIO_RESET.h"
#include"TEST_cbfifo.h"
#include "Test_MMA8451.h"
extern __IO uint8_t Switch_pressed;
int ref_x = 0;
int ref_y = 0;
extern int flag;
extern Digital_Angle_guage new_state;
/*
 * @brief   Application entry point.
 */
void Gpio_Init()
{
	// Enable clock to Port B and Port D
		SystemCoreClockUpdate();
		SIM->SCGC5 =  SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;

		// Make 3 pins GPIO
		PORTB->PCR[RED_LED_POS] &= ~PORT_PCR_MUX_MASK;
		PORTB->PCR[GREEN_LED_POS] &= ~PORT_PCR_MUX_MASK;
	    PORTD->PCR[BLUE_LED_POS] &= ~PORT_PCR_MUX_MASK;


		// Set ports to outputs
		PTB->PDDR |= MASK(RED_LED_POS) | MASK(GREEN_LED_POS);
		PTD->PDDR |= MASK(BLUE_LED_POS);

}
void my_getstring()
{
	char c;
	char str[1000];
	int index=0;
	while((c = getchar())!= '\r')			// inputs character
	{
		if(c =='\b' )						// if backspace delete character
		{
			if(index > 0)
			{
				index--;
				str[index] = ' ';
				printf("\b \b" );
			}

		}
		else						// if character is not backspace or carriage return load value to array
		{
			printf("%c",c);
			str[index]= c;
			index++;
		}
   }
   str[index]='\0';
   process_command(str);		// calling process command
   index=0;
}

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    sysclock_init();
    SysTick_Init();
    Gpio_Init();
    Initialize_Interrupts();
    PWM_Init();
    Init_UART0(Baudrate);
    Touch_Init();
    i2c_init();
    printf("\r\nWelcome to Digital Angle Gauge!");
	if (!init_mma()) {										/* init mma peripheral */
		RGB_LED_Control(SET_COLOR,0,0);							/* Light red error LED */
			while (1)										/* not able to initialize mma */
				;
		}
	printf("\r\nAll functions are initialized");
	printf("\r\nStarted Testing");
	test_angle_detect_color();
	test_cbfifo();
	printf("\r\nTesting Completed");

	printf("\r\nRed LED indicate 30˚");
	printf("\r\nGreen LED indicate 45˚");
	printf("\r\nBlue LED indicate 60˚");
	printf("\r\nWhite LED indicate 90˚");

	printf("\r\nWaiting for Board to align then LED will change to green and then turn off");
	printf("\r\nFor button press connect PTD7 pin 19 and ground to reset reference level");

	new_state = INIT_STATE;
	printf("\r\nEnter which mode to calibrate");
	printf("\r\nEnter yes for command processor to calibrate");
	printf("\r\nEnter no for button press to calibrate");
	printf("\n\r?");
	my_getstring();
	digital_angle_FSM();

	while (1)
	{



		if(flag==1){
			printf("\n\r?");
			my_getstring();
		}
		if(flag==0){
			TSI0->DATA |= TSI_DATA_SWTS_MASK;
			digital_angle_FSM();
		}

	}

    return 0 ;
}

