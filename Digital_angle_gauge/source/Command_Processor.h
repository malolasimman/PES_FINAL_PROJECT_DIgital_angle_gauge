
/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : Command_Processor.h
Created on : 08-DEC-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
*/

#ifndef COMMAND_PROCESSOR_H_
#define COMMAND_PROCESSOR_H_

/* -------------------------------------------------- /
                 FUNCTION DECLARATIONS
/ -------------------------------------------------- */
void process_command(char *input);
void author_handler();
void help();
void calibrate(int argc, char *argv[]);
/* -------------------------------------------------- /
                    GLOBAL VARIABLES
/ -------------------------------------------------- */
extern int hex_flag;
extern char *temp2;
extern int flag ;
extern int i;


#endif /* COMMAND_PROCESSOR_H_ */
