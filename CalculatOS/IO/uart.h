
#pragma once

void uart1_init();
char uart1_getChar();
void uart1_sendChar(const unsigned char c);
void uart1_sendString(const char* s);