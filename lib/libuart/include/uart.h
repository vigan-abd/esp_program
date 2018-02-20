// Copyright (C) 2017-2018 University of Prishtina - All rights reserved
// Kodra e Diellit, 10000 Prishtina, Kosovo. 
// Author: Dr. SMAILI Idriz   smaili.idriz@gmail.com
//
//++
// Name
//    @file uart.h
//
// Purpose
//    @brief Implements the routines needed to handle the UART communication
//
// Author
//    @author: Dr. Dipl.-Ing. Idriz SMAILI, smaili.idriz@gmail.com
//    $Author: smaili $
//
// Revision Dates
//    2018-01-27 (vigan.abd): Refactoring
//    $Log: uart.h $
//--

#ifndef __UART__H
#define __UART__H 1

#include "esp_types.h"
#include <avr/io.h> 
#include <util/delay.h>
#include "tmr.h"

/*
 * Define uart interrupt service routine constants
 */
#define UART_ISR_RX0 USART0_RX_vect
#define UART_ISR_TX0 USART0_TX_vect
#define UART_ISR_RX1 USART1_RX_vect
#define UART_ISR_TX1 USART1_TX_vect

/*
 * Define uart constants
 */
#define UART_INVALID_CHANNEL 0
#define UART_NO_ERROR 1
#define UART_EMPTY_DATA 2
#define UART_FULL_BUFFER 3
#define UART_CH_0 0
#define UART_CH_1 1

/*
 * Declarations of UART prescaler div factors
 */
#define FREQ 16000000
#define BAUD0 1200
#define BAUD0_PRESCALE ((FREQ / (16 * BAUD0)) - 1)
#define BAUD1 1200
#define BAUD1_PRESCALE ((FREQ / (16 * BAUD1)) - 1)

/*
 * Define uart watchdog service routines
 */
#define UART_ISR_WATCHDOG_CH_0 TMR_ISR_OCR0
#define UART_ISR_WATCHDOG_CH_1 TMR_ISR_OCR2

/*
 * Define uart members
 */
uint8_t uart_init (uint16_t baud, uint8_t ch);
uint8_t uart_set_rcv_int (uint8_t ch);
uint8_t uart_clr_rcv_int (uint8_t ch);
uint8_t uart_set_trm_int (uint8_t ch);
uint8_t uart_clr_trm_int (uint8_t ch);
uint8_t uart_trm (uint8_t data, uint8_t ch, uint8_t *const stop_flag);
uint8_t uart_rcv (uint8_t *const data, uint8_t ch, uint8_t *const stop_flag);
uint8_t uart_flush (uint8_t ch);
uint8_t uart_watchdog_start (uint8_t tmr_top, uint8_t ch);
uint8_t uart_watchdog_stop (uint8_t ch);

#endif /* __UART__H */