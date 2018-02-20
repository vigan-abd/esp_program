// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file 7seg.h
//
// Purpose
//    @brief Specifies the members of 7 segment display module
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: 7seg.h $
//--

#ifndef __SEG7__H
#define __SEG7__H 1

#include <avr/io.h> 
#include "esp_types.h"

/*
 * Declarations of 7 Segment Display values
 */
#define SEG7_0 0b11000000
#define SEG7_1 0b11111001
#define SEG7_2 0b10100100
#define SEG7_3 0b10110000
#define SEG7_4 0b10011001
#define SEG7_5 0b10010010
#define SEG7_6 0b10000010
#define SEG7_7 0b11111000
#define SEG7_8 0b10000000
#define SEG7_9 0b10010000
#define SEG7_DOT 0b01111111
#define SEG7_MINUS 0b10111111
#define SEG7_CLEAN 0b11111111
#define SEG7_A 0b10001000
#define SEG7_M 0b10101011
#define SEG7_L 0b11000111

/*
 * Declarations of ADC's members
 */
void seg7_set_seg (uint8_t seg);
void seg7_print_num (uint8_t num);

#endif /* __SEG7__H */ 
