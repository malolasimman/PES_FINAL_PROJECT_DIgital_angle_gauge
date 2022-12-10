/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : Command_Processor.c
Created on : 8-Dec-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/

/* -------------------------------------------------- /
                    	INCLUDES
/ -------------------------------------------------- */
#include "PES_FINAL_PROJECT.h"
#include "MMA8451.h"
#include <stdlib.h>
#include "UART.h"
#include "cbfifo.h"
#include "Command_Processor.h"
#include "State_Machine.h"
#include "PWM.h"

/* -------------------------------------------------- /
                    GLOBAL VARIABLE
/ -------------------------------------------------- */
extern Digital_Angle_guage new_state ;
extern int roll_degree,pitch_degree;
int i=0,flag;
extern int reference_angle1,reference_angle2;
extern int roll_angle,pitch_angle;
/* -------------------------------------------------- /
                 FUNCTION DEFINITION
/ -------------------------------------------------- */
/** Prints the author name **/
void author_handler()
{
	printf("\r\nMalolaSimman Srinivasan Kannan");
}
/** prints hexdump from start location to length which user as given **/
void calibrate_handler()
{
	printf("\n\r");
	new_state=CALIBRATE_STATE;
	digital_angle_FSM();
}

/** prints help message **/
void help_handler()
{
	printf("\r\n|________________________________________________________________________________________________|");
	printf("\r\n|_______________________________ help wizard ____________________________________________________|");
	printf("\r\n|_____________________________________|__________________________________________________________|");
	printf("\r\n|____ options _____|___ Functions ____|_______________________ Syntax ___________________________|");
	printf("\r\n|______ 1 _________|_____ Author _____|_______________________ (author) _________________________|");
	printf("\r\n|______ 1 _________|_____ angle ______|________________________ (angle) __________________________|");
	printf("\r\n|______ 2 _________|___ calibrate ____|______________________ (calibrate) _______________________|");
	printf("\r\n|______ 3 _________|_____  Help  _____|_______________________ (help) ___________________________|");
	printf("\r\n|______ 4 _________|___ command mode__|_______________________ (yes) ____________________________|");
	printf("\r\n|______ 5 _________|___  button mode _|_______________________ (no) _____________________________|");
	printf("\r\n|_____________________________ Enter the operation ______________________________________________|");
	printf("\r\n|_____________________________________|__________________________________________________________|");
}
// In this function calculates angles
void angle_handler(){
	digital_angle_FSM(); //starts FSM
	printf("\n\r");
	convert_xyz_to_roll_pitch(); // get current position
	roll_degree= (roll_angle-reference_angle1); // calculates roll degree
	pitch_degree= (pitch_angle-reference_angle2); // calculates pitch degree
	if(roll_degree<0){
		roll_degree=roll_degree*(-1);
	}
	if(pitch_degree<0){
		pitch_degree=pitch_degree*(-1);
	}
	printf("%d degree detected\r\n",roll_degree);
}
// This function is for command mode
void yes_handler()
{
	flag=1;
}
// This function is for external button press mode
void no_handler()
{
	flag =0;
}
/** Prints a string with build information that is dynamically
 	generated at build time on the machine **/


/** command structure **/
typedef void (*command_handler_t)(int, char *argv[]);
typedef struct
{
	const char *name;
	command_handler_t handler;
	const char *help_string;
} command_table_t;

/** command Table **/
static const command_table_t commands[] = {
		{"author",author_handler,"author - print the author of the code"},
		{"calibrate", calibrate_handler,"setting the relative reference angle"},
		{"help", help_handler,"help - prints the help message"},
		{"yes", yes_handler,"yes - starts with command processor"},
		{"no", no_handler,"no - starts with push button "},
		{"angle", angle_handler,"angle - prints the current angle "}
};

/** calculating number of commands **/
static const int num_commands = sizeof(commands) / sizeof(command_table_t);

/** process_command function perfoms specific task like calling command
  	handler and decode the command which user has given **/
void process_command(char *input)
{
	char *p = input;
	char *end;
	// find end of string
	for (end = input; *end != '\0'; end++);	// calculates end of the string
	char *argv[10];
	int argc = 0;
	memset(argv, 0, sizeof(argv));
	int space_flag=1;
	for (p = input; p < end; p++)	// loading characters argv
	{
		if(((*p == '\0') || (*p == ' ') ))
		{
			*p='\0';
			space_flag=1;

		}
		else
		{
			if( (space_flag==1) )
			{
				argv[argc]=p;
				argc++;
				space_flag=0;
			}
		}
	}
		argv[argc] = '\0';
		int error_flag = 0;

	for (int i=0; i < num_commands; i++)	// case comparing the commands
	{
		if (strcasecmp(argv[0], commands[i].name) == 0)
		{
			commands[i].handler(argc, argv);		// calls command handler
			error_flag=0;
			break;
		}
		else
		{
			error_flag=1;
		}
	}
	if(error_flag==1)
	{
		error_flag=0;
		printf("\r\nUnknown command:%s",input);		// printing unknown command
		printf("\n\r?");
		my_getstring();
	}
	return;
}



