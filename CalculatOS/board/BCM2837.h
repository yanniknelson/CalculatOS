
#pragma once

#include "../stdx_includes.h"

#define MMU_BASE_ADDRESS            0x3F000000

// 
// AUZILIARIES: UART1(mini UART), SPI1 & SPI2
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
#define AUX_BASE_ADDRESS            MMU_BASE_ADDRESS + 0x215000
#define AUX_IRQ                     ((volatile uint32_t*)AUX_BASE_ADDRESS)              // Aux interrupt status
#define AUX_ENABLE                  ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x04))     // Aux enable
#define AUX_MU_IO_REG               ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x40))     // Mini Uart I/O Data
#define AUX_MU_IER_REG              ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x44))     // Mini Uart interrupt enable
#define AUX_MU_IIR_REG              ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x48))     // Mini Uart interrupt identify
#define AUX_MU_LCR_REG              ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x4C))     // Mini Uart line control
#define AUX_MU_MCR_REG              ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x50))     // Mini Uart modem control
#define AUX_MU_LSR_REG              ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x54))     // Mini Uart line status
#define AUX_MU_MSR_REG              ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x58))     // Mini Uart modem status
#define AUX_MU_SCRATCH              ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x5C))     // Mini Uart scratch
#define AUX_MU_CNTRL_REG            ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x60))     // Mini Uart extra control
#define AUX_MU_STAT_REG             ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x64))     // Mini Uart extra status
#define AUX_MU_BAUD_REG             ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x68))     // Mini Uart baudrate
#define AUX_SPI0_CNTL0_REG          ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x80))     // SPI 1 control register 0
#define AUX_SPI0_CNTL1_REG          ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x84))     // SPI 1 control register 1
#define AUX_SPI0_STAT_REG           ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x88))     // SPI 1 status
#define AUX_SPI0_IO_REG             ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x90))     // SPI 1 data
#define AUX_SPI0_PEEK_REG           ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0x94))     // SPI 1 peek
#define AUX_SPI1_CNTL0_REG          ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0xC0))     // SPI 2 control register 0
#define AUX_SPI1_CNTL1_REG          ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0xC4))     // SPI 2 control register 1
#define AUX_SPI1_STAT_REG           ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0xC8))     // SPI 2 status
#define AUX_SPI1_IO_REG             ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0xD0))     // SPI 2 data
#define AUX_SPI1_PEEK_REG           ((volatile uint32_t*)(AUX_BASE_ADDRESS + 0xD4))     // SPI 2 peek

// 
// GPIO
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
#define GPIO_BASE_ADDRESS           MMU_BASE_ADDRESS + 0x200000
#define GPIO_GPFSEL0                ((volatile uint32_t*)GPIO_BASE_ADDRESS)             // GPIO function select 0 (pins 0 - 9; each pin gets 3 bits starting from bit 0)
#define GPIO_GPFSEL1                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x04))    // GPIO function select 1 (pins 10 - 19; each pin gets 3 bits starting from bit 0)
#define GPIO_GPFSEL2                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x08))    // GPIO function select 2 (pins 20 - 29; each pin gets 3 bits starting from bit 0)
#define GPIO_GPFSEL3                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x0C))    // GPIO function select 3 (pins 30 - 39; each pin gets 3 bits starting from bit 0)
#define GPIO_GPFSEL4                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x10))    // GPIO function select 4 (pins 40 - 49; each pin gets 3 bits starting from bit 0)
#define GPIO_GPFSEL5                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x14))    // GPIO function select 5 (pins 50 - 53; each pin gets 3 bits starting from bit 0)
#define GPIO_GPSET0                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x1C))    // GPIO pin output set 0 (pins 0-31)
#define GPIO_GPSET1                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x20))    // GPIO pin output set 1 (pins 32-53)
#define GPIO_GPCLR0                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x28))    // GPIO pin output clear 0 (pins 0-31)
#define GPIO_GPCLR1                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x2C))    // GPIO pin output clear 1 (pins 32-53)
#define GPIO_GPLEV0                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x34))    // GPIO pin level 0 (pins 0-31)
#define GPIO_GPLEV1                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x38))    // GPIO pin level 1 (pins 32-53)
#define GPIO_GPEDS0                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x40))    // GPIO pin even detect status 0 (pins 0-31)
#define GPIO_GPEDS1                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x44))    // GPIO pin even detect status 1 (pins 32-53)
#define GPIO_GPREN0                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x4C))    // GPIO pin rising edge detect enable 0 (pins 0-31)
#define GPIO_GPREN1                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x50))    // GPIO pin rising edge detect enable 1 (pins 32-53)
#define GPIO_GPFEN0                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x58))    // GPIO pin falling edge detect enable 0 (pins 0-31)
#define GPIO_GPFEN1                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x5C))    // GPIO pin falling edge detect enable 1 (pins 32-53)
#define GPIO_GPHEN0                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x64))    // GPIO pin high detect enable 0 (pins 0-31)
#define GPIO_GPHEN1                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x68))    // GPIO pin high detect enable 1 (pins 32-53)
#define GPIO_GPLEN0                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x70))    // GPIO pin low detect enable 0 (pins 0-31)
#define GPIO_GPLEN1                 ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x74))    // GPIO pin low detect enable 1 (pins 32-53)
#define GPIO_GPAREN0                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x7C))    // GPIO pin async rising edge detect 0 (pins 0-31)
#define GPIO_GPAREN1                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x80))    // GPIO pin async rising edge detect 1 (pins 32-53)
#define GPIO_GPAFEN0                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x88))    // GPIO pin async falling edge detect 0 (pins 0-31)
#define GPIO_GPAFEN1                ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x8C))    // GPIO pin async falling edge detect 1 (pins 32-53)
#define GPIO_GPPUD                  ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x94))    // GPIO pin pull-up/down enable
#define GPIO_GPPUDCLK0              ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x98))    // GPIO pin pull-up/down enable clock 0 (pins 0-31)
#define GPIO_GPPUDCLK1              ((volatile uint32_t*)(GPIO_BASE_ADDRESS + 0x9C))    // GPIO pin pull-up/down enable clock 1 (pins 32-53)

#define GPIO_FSEL_INPUT             0b000                       // 0
#define GPIO_FSEL_OUTPUT            0b001                       // 1
#define GPIO_FSEL_ALT_0             0b100                       // 4
#define GPIO_FSEL_ALT_1             0b101                       // 5
#define GPIO_FSEL_ALT_2             0b110                       // 6
#define GPIO_FSEL_ALT_3             0b111                       // 7
#define GPIO_FSEL_ALT_4             0b011                       // 3
#define GPIO_FSEL_ALT_5             0b010                       // 2

#define GPIO_PULL_UP_DOWN_OFF       0x0
#define GPIO_ENABLE_PULL_UP         0x1
#define GPIO_ENABLE_PULL_DOWN       0x2

// 
// UART
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
#define UART_BASE_ADDRESS           MMU_BASE_ADDRESS + 0x201000
#define UART_DR                     ((volatile uint32_t*)UART_BASE_ADDRESS)             // UART data register
#define UART_RSRECR                 ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x04))    // UART receive status register/error clear register
#define UART_FR                     ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x18))    // UART flag register
#define UART_IBRD                   ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x24))    // UART integer buad rate divisor
#define UART_FBRD                   ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x28))    // UART fractional buad rate divisor
#define UART_LCRH                   ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x2c))    // UART line control register
#define UART_CR                     ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x30))    // UART control register
#define UART_IFLS                   ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x34))    // UART interupt fifo level select register
#define UART_IMSC                   ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x38))    // UART interupt mask set clear register
#define UART_RIS                    ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x3c))    // UART raw interupt status register
#define UART_MIS                    ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x40))    // UART masked interupt status register
#define UART_ICR                    ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x44))    // UART interupt clear register
#define UART_DMACR                  ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x48))    // UART dma control register
#define UART_ITCR                   ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x80))    // UART test control register
#define UART_ITIP                   ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x84))    // UART integration test input reg
#define UART_ITOP                   ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x88))    // UART integration test output reg
#define UART_TDR                    ((volatile uint32_t*)(UART_BASE_ADDRESS + 0x8c))    // UART test data reg
