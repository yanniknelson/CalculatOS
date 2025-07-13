
#include "gpio.h"
#include "../board/BCM2837.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SetPullUpDown(const unsigned long pins, const unsigned char enabledState)
{
	// set the pull up down mode, if the enabled state is invalid, disable pull up/down
	switch (enabledState)
	{
	case 1:
		*GPIO_GPPUD = 0b01; // 1 - enable pull down
		break;
	case 2:
		*GPIO_GPPUD = 0b10; // 2 - enable pull up
		break;
	default:
		*GPIO_GPPUD = 0b00; // 0 - diable pull up/down
	}

	// TODO: busy wait clock on background processor/release thread for at least 150 instead
	
	// In order to effect the pull up/down change we must wait at least 150 cycles to set up the control signal
	// then enable to pull up down clock for the pins who's mode we want changed
	// then wait at least another 150 cycles and disable the clock again.
	// see page 101 of BVM2837.pdf

	// busy wait for 150 cycles
	register unsigned int r;
	r = 150; while (r--) { asm volatile("nop"); }

	// enable the pull up/down clock for the appropriate pins
	const int lowbits = pins;
	const int highbits = (pins>>32);
	*GPIO_GPPUDCLK0 = lowbits;
	*GPIO_GPPUDCLK1 = highbits;

	// busy wait for 150 cycles
	r = 150; while (r--) { asm volatile("nop"); }

	// stop the pull up/down clocks
	*GPIO_GPPUDCLK0 = 0;
	*GPIO_GPPUDCLK1 = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void SetPinAltFunc(unsigned char pin, const unsigned char altFunc)
{
	if (pin > 53 || altFunc > 7) // if the chosen pin or alt func is invalid do nothing
		return;

	// ensure we get the correct function select register for the pin we're changing
	volatile unsigned int* funcSelReg;
	if (pin < 10)
	{
		funcSelReg = GPIO_GPFSEL0;
	}
	else if (pin < 20)
	{
		funcSelReg = GPIO_GPFSEL1;
		pin -= 10;
	}
	else if (pin < 30)
	{
		funcSelReg = GPIO_GPFSEL2;
		pin -= 20;
	}
	else if (pin < 40)
	{
		funcSelReg = GPIO_GPFSEL3;
		pin -= 30;
	}
	else if (pin < 50)
	{
		funcSelReg = GPIO_GPFSEL4;
		pin -= 40;
	}
	else if (pin < 54)
	{
		funcSelReg = GPIO_GPFSEL5;
		pin -= 50;
	}

	char altFuncBits = 0;
	switch (altFunc)
	{
	case 0:
		altFuncBits = GPIO_FSEL_ALT_0;
	case 1:
		altFuncBits = GPIO_FSEL_ALT_1;
	case 2:
		altFuncBits = GPIO_FSEL_ALT_2;
	case 3:
		altFuncBits = GPIO_FSEL_ALT_3;
	case 4:
		altFuncBits = GPIO_FSEL_ALT_4;
	case 5:
		altFuncBits = GPIO_FSEL_ALT_5;
	case 6:
		altFuncBits = GPIO_FSEL_INPUT;
	case 7:
		altFuncBits = GPIO_FSEL_OUTPUT;
	default:
		return;
	}

	register unsigned int funcSelRegVal;
	funcSelRegVal = *funcSelReg; // get the current function select state
	funcSelRegVal &= ~(0b111<<(pin*3)); // clear the function select bits for only the pin we're setting
	funcSelRegVal |= (altFuncBits << (pin * 3)); // set the function select bits for the pin we want
	*funcSelReg = funcSelRegVal; // write the bit vector into the function select register
}