/*
Author     : MALOLASIMMAN SRINIVASAN KANNAN
E-Mail     : masr4788@colorado.edu
Subject    : Principles of Embedded Software
File	   : UART.c
Created on : 08-DEC-2022
University : University of Colorado at Boulder
Assignment : PES_FINAL_PROJECT
Reference  : https://github.com/alexander-g-dean/ESF/tree/master/NXP/Code/Chapter_8/Serial-Demo
*/

/* -------------------------------------------------- /
               INCLUDES & DEFINES
/ -------------------------------------------------- */
#include "UART.h"
char ch;

#define Stop_bit_1 (0)		// selecting stop bits as one
#define Stop_bit_2 (1)		// selecting stop bits as two
#define Data_bit_8 (0)		// 8 bit mode
#define Data_bit_9 (1)		// 9 bit mode
#define Parity_bit (1)		// selecting parity
#define Noparity_bit (0)	// selecting no parity


/* -------------------------------------------------- /
                 	 GLOBAL VARIABLES
/ -------------------------------------------------- */
uint8_t TxQ, RxQ;
CbFifo Tx;
CbFifo Rx;
uint8_t* tmp;

struct __FILE
{
  int handle;
};

FILE __stdout;  //Use with printf
FILE __stdin;	//use with fget/sscanf, or scanf

/* -------------------------------------------------- /
               	 FUNCTION DEFINITIONS
/ -------------------------------------------------- */

int __sys_readc(void)
{
	while((cbfifo_Empty(&Rx))==1);
	return cbfifo_Dequeue(&Rx,1);
}
void Init_UART0(uint32_t baud_rate)
{
	uint16_t sbr;

	// Enabling clock gating for UARTO and Port A
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;//Enable clock for UART0
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;//Port A clock enable

	// Making sure that transmitter and receiver are disabled before init
	UART0->C2 &= ~UART0_C2_TE_MASK & ~UART0_C2_RE_MASK; //RE and TE Disable

	// Setting UART clock to 48 MHz clock
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);//Clock source set to MCGFLLCLK or  MCGPLLCLK/2
	SIM->SOPT2 |= 0x00U;//Clock MCGFLLCLK is set

	// Setting pins to UART0 Rx and Tx
	PORTA->PCR[1] = PORT_PCR_ISF_MASK | PORT_PCR_MUX(2); // Rx
	PORTA->PCR[2]=  PORT_PCR_ISF_MASK | PORT_PCR_MUX(2); // Tx

	// Setting baud rate and oversampling ratio
	sbr = (uint16_t) ((SYSCLOCK_FREQUENCY)/(baud_rate * UART_OVERSAMPLE_RATE));
	UART0->BDH &= ~UART0_BDH_SBR_MASK;
	UART0->BDH |= UART0_BDH_SBR(sbr>>8);
	UART0->BDL = UART0_BDL_SBR(sbr);
	UART0->C4 |= UART0_C4_OSR(UART_OVERSAMPLE_RATE-1);

	// Disabling interrupts for RX active edge and LIN break detect, select one stop bit
	UART0->BDH |= UART0_BDH_RXEDGIE(0)|UART0_BDH_SBNS(Stop_bit_2)|UART0_BDH_LBKDIE(0);

	// not enabling loopback mode, use 8 data bit mode,selecting no parity
	UART0->C1= UART0_C1_LOOPS(0) | UART0_C1_M(Data_bit_8) |UART0_C1_PE(Noparity_bit);// Loops= 0 means seperate Rx and Tx. M 0.Start, 8 data bits, stop
																	// Parity bit disabled

	// not inverting transmit data, not enabling interrupts for errors
	UART0->C3 = UART0_C3_TXINV (0) | UART0_C3_ORIE (1)| UART0_C3_NEIE (1) | UART0_C3_FEIE(1)| UART0_C3_PEIE (1);

	// Clearing error flags
	UART0->S1=UART0_S1_OR(1) |UART0_S1_NF(1)|UART0_S1_FE(1)|UART0_S1_PF(1);


	// Send LSB first, not inverting received data
	UART0->S2 = UART0_S2_MSBF(0)|UART0_S2_RXINV(0);

	// Enabling interrupts
	cbfifo_Init(&Tx);
	cbfifo_Init(&Rx);
	NVIC_SetPriority(UART0_IRQn,2);
	NVIC_ClearPendingIRQ(UART0_IRQn);
	NVIC_EnableIRQ(UART0_IRQn);

	// Enabling receive interrupts but not transmit interrupts yet
	UART0->C2 |= UART_C2_RIE(1);

	// Enabling UART receiver and transmitter
	UART0->C2 |= UART0_C2_TE(1)|UART0_C2_RE(1);
}


// UART0 IRQ Handler.
void UART0_IRQHandler(void)
{

	if(UART0->S1 & (UART0_S1_OR_MASK | UART0_S1_NF_MASK | UART0_S1_FE_MASK | UART0_S1_PF_MASK))
	{
			// Enabling the error flags
			UART0->S1 |= UART0_S1_OR_MASK | UART0_S1_NF_MASK |	UART0_S1_FE_MASK | UART0_S1_PF_MASK;
			// reading the data register to clear RDRF
			ch = UART0->D;
	}

	if (UART0->S1 & UART0_S1_RDRF_MASK)
	{
		// received a character
		ch = UART0->D;
		if (!cbfifo_Full(&Rx))
		{
			cbfifo_Enqueue(&Rx,&ch,1);
		}
	}
	if((UART0->C2 & UART0_C2_TIE_MASK) && (UART0->S1 & UART0_S1_TDRE_MASK))// tx buffer empty
	{
		if (!cbfifo_Empty(&Tx))
		{
			UART0->D = cbfifo_Dequeue(&Tx,1);
		}
		else
		{
			// queue is empty so disabling transmitter interrupt
			UART0->C2 &= ~UART0_C2_TIE_MASK;
		}
	}
}



