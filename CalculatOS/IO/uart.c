
#include "uart.h"

#include "gpio.h"
#include "../board/BCM2837.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void uart1_init()
{
	// turn off uart0 and uart1
	*AUX_ENABLE = ~1; // clear bit 0
	*UART_CR = 0;

	*AUX_ENABLE |= 1; // enable uart1 by setting bit 0
	*AUX_MU_CNTRL_REG = 0; // disable read and write through UART
	*AUX_MU_LCR_REG = 3; // 8-bit mode
	*AUX_MU_MCR_REG = 0; // clear UART1_RTS line
	*AUX_MU_IER_REG = 0; // diable uart interrupts
	*AUX_MU_IIR_REG = 0xc6; // rese the FIFO bits, set the read write interrupt bits to their invalid state
	*AUX_MU_BAUD_REG = 270; // 115200 baud

	// init GPIO pins
	SetPinAltFunc(14, 5); // set pin 14 to alt5
	SetPinAltFunc(15, 5); // set pin 15 to alt5
	SetPullUpDown(((1 << 14) | (1 << 15)), 0); // disable pull up/down on pins 14 and 15

	*AUX_MU_CNTRL_REG = 3; // enable read and write through UART
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char uart1_getChar()
{
	do { asm volatile("nop"); } while (!(*AUX_MU_LSR_REG & 0x01)); // do nothing until bit 1 is set (data ready)
	char r = (char)(*AUX_MU_IO_REG); // read the data
	return r == '\r' ? '\n' : r; // replace carriage returns with newlines
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void uart1_sendChar(const unsigned  char c)
{
	do { asm volatile("nop"); } while (!(*AUX_MU_LSR_REG & 0x20)); // do nothing until bit 6 is set (transmitter idle)
	*AUX_MU_IO_REG = c; // set the send data
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void uart1_sendString(const char* s)
{
	while (*s)
	{
		// send both carriage return and newline on newlines
		if (*s == '\n')
			uart1_sendChar('\r');
		uart1_sendChar(*s++);
	}
}