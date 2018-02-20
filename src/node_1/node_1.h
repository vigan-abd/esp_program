// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file node_1.h
//
// Purpose
//    @brief Node 1 general declarations
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: node_1.h $
//--

#include "esp_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "tmr.h"
#include "bulb.h"
#include "uart.h"
#include "esp_cmd.h"
#include "service/display.h"
#include "service/watchdog.h"
#include "service/cmd.h"


#define OCR1_VAL 4500

/***************************************************************************//** 
 * @brief Initializes port directions and values
 *
 * Initializes port directions and values
 *
 * @retval void 
 ******************************************************************************/
void init_port (void)
{
    // DDRB = 0xFF;
    // DDRD = 0xFF;
    // PORTD = 0x7F;
}