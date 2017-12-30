// Copyright (C) 2003-2015 swengLab Technologies - All rights reserved
// Siebenbürgerstrasse 16-26/26/17, A--1220 Vienna, Austria. 
// Author: Dr. SMAILI Idriz   smaili.idriz@gmail.com
//
//++
// Name
//    @file uart.c
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
//    $Log: uart.c $
//--

#include "uart.h"

/***************************************************************************//** 
 * @brief Initialize the usart
 *
 * Initializes the usart by providing the prescaler div factor. Async Mode is used.
 *
 * @param[in] uint16_t  specifies the baud rate
 *
 * @retval void 
 ******************************************************************************/
void usart_init(uint16_t ubrr)
{
    /* Set baud rate */
    UBRRH = (uint8_t) (ubrr >> 8);
    UBRRL = (uint8_t) ubrr;

    /* Enable receiver and transmitter */
    UCSRB = (1 << RXEN) | (1 << TXEN);
    
    /* Set frame format: 8data, 2stop bit */
    UCSRC = (1 << USBS) | (3 << UCSZ0);
}
/***************************************************************************//** 
 * @brief Initialize the usart ISR
 *
 * Initializes the usart Interrupt Service Routine. Readen data is stored in uart_data.
 *
 * @retval void 
 ******************************************************************************/
void usart_int_init()
{
    /* Enable the usart Recieve Complete interrupt (usart_RXC) */
    UCSRB |= (1 << RCXIE);
    sei(); // Enable the Global Interrupt Enable flag so that interrupts can be processed
}
/***************************************************************************//** 
 * @brief Sends the data
 *
 * Sends the data via serial port communication.
 *
 * @param[in] uint8_t  data to be send
 *
 * @retval void
 ******************************************************************************/
void usart_send(uint8_t data)
{
    /* Wait for empty transmit buffer */
    while (!(UCSRA & (1 << UDRE)))
        ;
    
    /* Put data into buffer, sends the data */
    UDR = data;
}
/***************************************************************************//** 
 * @brief Reads data from SP
 *
 * Reads the data from Serial Port. The communication works in blocking receive mode.
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t usart_receive()
{
    /* Wait for data to be received */
    while (!(UCSRA & (1 << RXC)))
        ;
    
    /* Get and return received data from buffer */
    return UDR;
}
