// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file node_0.h
//
// Purpose
//    @brief Node 0 general declarations
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: node_0.h $
//--

#include "esp_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "esp_cmd.h"
#include "uart.h"
#include "service/watchdog.h"
#include "service/cmd.h"

/*
 * Delay between node commands
 */
#define CMD_DELAY 4000

/***************************************************************************//** 
 * @brief Initializes port directions and values
 *
 * Initializes port directions and values
 *
 * @retval void 
 ******************************************************************************/
void port_init (void)
{
    DDRB = 0xFF;
    PORTB = 0xFF;
}