// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file watchdog.h
//
// Purpose
//    @brief Node watchdog routines
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: watchdog.h $
//--

/*
 * Watchdog members
 */
uint16_t watchdog_it;
uint8_t uart0_watchdog_flag = 0;
uint8_t empty_flag = 0;

/*
 * Watchdog service routine
 */
ISR (UART_ISR_WATCHDOG_CH_0)
{
    watchdog_it++;
    if (watchdog_it == 10000)
    {
        watchdog_it = 0;
        uart0_watchdog_flag = 1;
    }
}