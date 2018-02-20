// Copyright (C) 2017-2018 University of Prishtina - All rights reserved
// Kodra e Diellit, 10000 Prishtina, Kosovo. 
// Author: Dr. SMAILI Idriz   smaili.idriz@gmail.com
//
//++
// Name
//    @file uart.c
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
//    $Log: uart.c $
//--

#include "uart.h"

/***************************************************************************//** 
 * @brief Initialize UART 
 *
 * Initialize UART
 *
 * @param[in] uint16_t  baud
 * @param[in] uint8_t  ch
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_init (uint16_t baud, uint8_t ch)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        UBRR0H = (unsigned char) (baud >> 8);
        UBRR0L = (unsigned char) (baud & 0xFF);
        
        UCSR0B = (1 << RXEN0) | (1 << TXEN0);
        UCSR0C = (3 << UCSZ0) | (1 < USBS0);
        // UCSR0C |= (3 << UPM0);
    }
    else
    {
        UBRR1H = (unsigned char) (baud >> 8);
        UBRR1L = (unsigned char) (baud & 0xFF);
        
        UCSR1B = (1 << RXEN1) | (1 << TXEN1);
        UCSR1C = (3 << UCSZ1) | (1 < USBS1);
        // UCSR1C |= (3 << UPM1);
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Transmit data via UART 
 *
 * Transmit data via UART
 *
 * @param[in] uint8_t  data
 * @param[in] uint8_t  ch
 * @param[in] uint8_t*  stop_flag
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_trm (uint8_t data, uint8_t ch, uint8_t *const stop_flag)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        while ( (!(*stop_flag)) && (!(UCSR0A & (1 << UDRE0))) )
            ;
        if (*stop_flag)
            return UART_FULL_BUFFER;
        UDR0 = data;
    }
    else
    {
        while ( !(*stop_flag) && (!(UCSR1A & (1 << UDRE1))) )
            ;
        if (*stop_flag)
            return UART_FULL_BUFFER;
        UDR1 = data;
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Receive data via UART
 *
 * Receive data via UART
 *
 * @param[in] uint8_t*  data
 * @param[in] uint8_t  ch
 * @param[in] uint8_t*  stop_flag
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_rcv (uint8_t *const data, uint8_t ch, uint8_t *const stop_flag)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        while ( (!(*stop_flag)) && (!(UCSR0A & (1 << RXC0))) )
            ;
        if (*stop_flag)
            return UART_EMPTY_DATA;
        *data = UDR0;
    }
    else
    {
        while ( (!(*stop_flag)) && (!(UCSR1A & (1 << RXC1))) )
            ;
        if (*stop_flag)
            return UART_EMPTY_DATA;
        *data = UDR1;
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Flush UART buffer
 *
 * Flush UART buffer
 *
 * @param[in] uint8_t  ch
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_flush (uint8_t ch)
{
    uint8_t dummy;
    _delay_ms(150);
    
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        while(UCSR0A & (1 << RXC0))
            dummy = UDR0;
    }
    else
    {
        while(UCSR1A & (1 << RXC1))
            dummy = UDR1;
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Start Watchdog for UART
 *
 * Start Watchdog for UART
 *
 * @param[in] uint8_t  tmr_top
 * @param[in] uint8_t  ch
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_watchdog_start (uint8_t tmr_top, uint8_t ch)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }
    
    if (ch == UART_CH_0)
    {
        tmr0_init_ctc(tmr_top, TMR0_PRESCALER_FACT_128);
    }
    else
    {
        tmr2_init_ctc(tmr_top, TMR2_PRESCALER_FACT_128);
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Stop watchdog for UART
 *
 * Stop watchdog for UART
 *
 * @param[in] uint8_t  ch
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_watchdog_stop (uint8_t ch)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        TIMSK &= ~(1 << OCIE0);
    }
    else
    {
        TIMSK &= ~(1 << OCIE2);
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Enable recive ISR for UART
 *
 * Enable recive ISR for UART
 *
 * @param[in] uint8_t  ch
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_set_rcv_int (uint8_t ch)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        UCSR0B |= (1 << RXCIE0);
    }
    else
    {
        UCSR1B |= (1 << RXCIE1);
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Disable recive ISR for UART
 *
 * Disable recive ISR for UART
 *
 * @param[in] uint8_t  ch
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_clr_rcv_int (uint8_t ch)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        UCSR0B &= ~(1 << RXCIE0);
    }
    else
    {
        UCSR1B &= ~(1 << RXCIE1);
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Enable transmit ISR for UART
 *
 * Enable transmit ISR for UART
 *
 * @param[in] uint8_t  ch
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_set_trm_int (uint8_t ch)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        UCSR0B |= (1 << TXCIE0);
    }
    else
    {
        UCSR1B |= (1 << TXCIE1);
    }

    return UART_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Disable transmit ISR for UART
 *
 * Disable transmit ISR for UART
 *
 * @param[in] uint8_t  ch
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t uart_clr_trm_int (uint8_t ch)
{
    if (ch != UART_CH_0 && ch != UART_CH_1)
    {
       return UART_INVALID_CHANNEL;
    }

    if (ch == UART_CH_0)
    {
        UCSR0B &= ~(1 << TXCIE0);
    }
    else
    {
        UCSR1B &= ~(1 << TXCIE1);
    }

    return UART_NO_ERROR;
}