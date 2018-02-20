// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file node_3.h
//
// Purpose
//    @brief Node 3 general declarations
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: node_3.h $
//--

#include "esp_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "tmr.h"
#include "fan.h"
#include "adc.h"
#include "uart.h"
#include "temp_conv.h"
#include "esp_cmd.h"
#include "service/sensor.h"
#include "service/watchdog.h"
#include "service/cmd.h"

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
    DDRD = 0xFF;
    PORTD = 0xFF;
    PORTD = 0xFF;
    PORTF = 0x00;
}