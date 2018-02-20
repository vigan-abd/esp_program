// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file bulb.h
//
// Purpose
//    @brief Specifies the members of light bulb module
//
// Revision Dates
//    2018-01-27 (vigan): Inital create
//    $Log: bulb.h $
//--

#ifndef __BULB__H
#define __BULB__H 1

#include <avr/io.h> 
#include "esp_types.h"
#include "tmr.h"

/*
 * Bulb ports
 */
#define DDR_BULB DDRB
#define DD_BULB DDB5
#define BULB_DUTY_CYCLE OCR1A

/*
 * Bulb error values
 */
#define BULB_NO_ERROR 0
#define BULB_INVALID_INTENSITY 1

/* 
 * Declaration of bulb functions
 */
void bulb_init (void);
uint8_t bulb_set_int (uint8_t i); 

#endif /* __BULB__H */ 
