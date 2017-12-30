// Copyright (C) 2003-2015 swengLab Technologies - All rights reserved
// Siebenbürgerstrasse 16-26/26/17, A--1220 Vienna, Austria. 
// Author: Dr. SMAILI Idriz   smaili.idriz@gmail.com
//
//++
// Name
//    @file uart.h
//
// Purpose
//    @brief Implements the routine needed to handle the ADC  
//
// Author
//    @author: Dr. Dipl.-Ing. Idriz SMAILI, smaili.idriz@gmail.com
//    $Author: smaili $
//
// Revision Dates
//    2017-12-28 (smaili): Initial version
//    $Log: uart.h $
//--

#ifndef __UART__H
#define __UART__H 1

#include <avr/io.h> 

/*
 * Declarations of UART prescaler div factors
 */
#define FOSC 1843200
#define BAUD 9600
#define BAUD_PRESCALE FOSC / 16 / BAUD - 1

/*
 * Declarations of ADC's members
 */
uint8_t uart_data;
void    USART_Init     (uint16_t ubrr);
void    USART_INT_init ();
void    USART_Transmit (uint8_t  data);
uint8_t USART_Receive  ();

/*
 * Declaration of Interrupt Service Routine
 */
ISR(USART0_RX_vect)
{
    uart_data = UDR0;
}

#endif /* __UART__H */