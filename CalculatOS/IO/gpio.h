
#pragma once

// 
// pins is a 64 bit vector, bit 0 = pin 0 etc... bits past bit 53 will be ignored
// 
//	enabledState = 0 (disable pull up/down), 1 (enable pull down), 2 (enable pull 3)
//	all other values disable pull up/down
// 
//	This function will take at least 300 cycles, so try to set all the pins at once
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void SetPullUpDown(const unsigned long pins, const unsigned char enabledState);

// 
//	pin the pin we're enabling
// 
//	altFunc values 0 - 5 for alt0 - alt5, 6 = input, 7 = output, other values will have no effect
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void SetPinAltFunc(unsigned char pin, const unsigned char altFunc);