// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file fan.h
//
// Purpose
//    @brief Specifies the members of fan module 
//
// Revision Dates
//    2018-01-27 (vigan): Inital create
//    $Log: fan.h $
//--

#ifndef __FAN__H
#define __FAN__H 1

#include <avr/io.h> 
#include "esp_types.h"
#include "tmr.h"

/*
 * Fan port members
 */
#define DDR_FAN DDRB
#define DD_FAN DDB5
#define FAN_DUTY_CYCLE OCR1A

/*
 * Fan error values
 */
#define FAN_NO_ERROR 0
#define FAN_INVALID_SPEED 1


/* 
 * Declaration of fan functions
 */
void fan_init(void);
uint8_t fan_set_speed (uint8_t s);

#endif /* __FAN__H */ 
