// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file node_2.h
//
// Purpose
//    @brief Node 2 general declarations
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: node_2.h $
//--

#include "esp_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "bcd.h"
#include "7seg.h"
#include "tmr.h"
#include "uart.h"
#include "esp_cmd.h"
#include "service/watchdog.h"
#include "service/cmd.h"
#include "service/display.h"

/*
 * Timer 1 compare match value used for displaying data on 7 seg
 */
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
    DDRD = 0xFF;
    DDRB = (1 << DDB0) | (1 << DDB1) | (1 << DDB2);
}