
#include "stdx_includes.h"

#include "IO/uart.h"

// these need to exist in the source files in order to enable the language features.

extern "C" void __cxa_pure_virtual() // enables virtual functions
{
    // Do nothing or print an error message.
}

namespace __cxxabiv1 // These need to implement a mutex like gaurd with test-and-set primitive
{
	/* guard variables */

	/* The ABI requires a 64-bit type.  */
	__extension__ typedef int __guard __attribute__((mode(__DI__)));

	extern "C" int __cxa_guard_acquire(__guard*);
	extern "C" void __cxa_guard_release(__guard*);
	extern "C" void __cxa_guard_abort(__guard*);

	extern "C" int __cxa_guard_acquire(__guard* g)
	{
		return !*(char*)(g);
	}

	extern "C" void __cxa_guard_release(__guard* g)
	{
		*(char*)g = 1;
	}

	extern "C" void __cxa_guard_abort(__guard*)
	{

	}
}

// kernel entry point
int main()
{
    uart1_init();
    uart1_sendString("Hello World!");

	do { asm volatile("nop"); } while (true);

    return 0;
}