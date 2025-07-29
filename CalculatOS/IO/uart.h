
#pragma once

#include "../stdx_includes.h"

void uart1_init();
char uart1_getChar();
void uart1_sendChar(const char c);
void uart1_sendString(const char* s);