
#include "gpio.h"
#include "../board/BCM2837.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SetPullUpDown(const uint64_t pins, const uint8_t enabledState)
{
	// set the pull up down mode, if the enabled state is invalid, disable pull up/down
	switch (enabledState)
	{
	case 1:
	{
		*GPIO_GPPUD = 0b01; // 1 - enable pull down
		break;
	}
	case 2:
	{
		*GPIO_GPPUD = 0b10; // 2 - enable pull up
		break;
	}
	default:
	{
		*GPIO_GPPUD = 0b00; // 0 - diable pull up/down
	}
	}

	// TODO: busy wait clock on background processor/release thread for at least 150 instead
	
	// In order to effect the pull up/down change we must wait at least 150 cycles to set up the control signal
	// then enable to pull up down clock for the pins who's mode we want changed
	// then wait at least another 150 cycles and disable the clock again.
	// see page 101 of BVM2837.pdf

	// busy wait for 150 cycles
	uint32_t r;
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
void SetPinAltFunc(const uint8_t pin, const uint8_t altFunc)
{
	if (pin > 53 || altFunc > 7) // if the chosen pin or alt func is invalid do nothing
		return;

	// ensure we get the correct function select register for the pin we're changing
	volatile uint32_t* funcSelReg;
	uint32_t localPin = pin;
	if (pin < 10)
	{
		funcSelReg = GPIO_GPFSEL0;
	}
	else if (pin < 20)
	{
		funcSelReg = GPIO_GPFSEL1;
		localPin -= 10;
	}
	else if (pin < 30)
	{
		funcSelReg = GPIO_GPFSEL2;
		localPin -= 20;
	}
	else if (pin < 40)
	{
		funcSelReg = GPIO_GPFSEL3;
		localPin -= 30;
	}
	else if (pin < 50)
	{
		funcSelReg = GPIO_GPFSEL4;
		localPin -= 40;
	}
	else if (pin < 54)
	{
		funcSelReg = GPIO_GPFSEL5;
		localPin -= 50;
	}

	char altFuncBits = 0;
	switch (altFunc)
	{
	case 0:
	{
		altFuncBits = GPIO_FSEL_ALT_0;
		break;
	}
	case 1:
	{
		altFuncBits = GPIO_FSEL_ALT_1;
		break;
	}
	case 2:
	{
		altFuncBits = GPIO_FSEL_ALT_2;
		break;
	}
	case 3:
	{
		altFuncBits = GPIO_FSEL_ALT_3;
		break;
	}
	case 4:
	{
		altFuncBits = GPIO_FSEL_ALT_4;
		break;
	}
	case 5:
	{
		altFuncBits = GPIO_FSEL_ALT_5;
		break;
	}
	case 6:
	{
		altFuncBits = GPIO_FSEL_INPUT;
		break;
	}
	case 7:
	{
		altFuncBits = GPIO_FSEL_OUTPUT;
		break;
	}
	default:
		return;
	}

	uint32_t funcSelRegVal;
	funcSelRegVal = *funcSelReg; // get the current function select state
	funcSelRegVal &= ~(0b111<<(localPin *3)); // clear the function select bits for only the pin we're setting
	funcSelRegVal |= (altFuncBits << (localPin * 3)); // set the function select bits for the pin we want
	*funcSelReg = funcSelRegVal; // write the bit vector into the function select register
}