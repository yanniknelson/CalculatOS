
#include "IO/uart.h"

void main()
{
    uart1_init();
    uart1_sendString("Hello World!");

    while (1)
    {
        uart1_sendChar(uart1_getChar());
    }
}