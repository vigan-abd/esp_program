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
#define FOSC          1843200
#define BAUD          9600
#define BAUD_PRESCALE FOSC / 16 / BAUD - 1

/*
 * Declarations of UART prescaler div factors
 */
#define UART_ENABLE_INT () \
  do \
    { \
      UCSRB |= (1 << RXCIE) | (1 << TXCIE);\
    } \
  while (0);

#define UART_DISABLE_INT () \
  do \
    { \
      UCSRB &= ~(1 << RXCIE) | (1 << TXCIE); \
    } \
  while (0);

/*
 * Declarations of ADC's members
 */
uint8_t uart_data;
void    usart_init     (uint16_t ubrr);
void    usart_int_init ();
void    usart_send     (uint8_t  data);
uint8_t usart_receive  ();

 /* Declaration of Interrupt Service Routine
 */
ISR (USART0_RX_vect)
{
    uart_data = UDR0;
}

#endif /* __UART__H */
