// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file 7seg.c
//
// Purpose
//    @brief Specifies the members of 7 segment display module  
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: 7seg.c $
//--

#include "7seg.h"

/***************************************************************************//** 
 * @brief Selects the corresponding segment 
 *
 * Selects the corresponding segment
 *
 * @param[in] uint8_t  seg
 *
 * @retval void 
 ******************************************************************************/
void seg7_set_seg (uint8_t seg)
{
    PORTB = ~seg;
}


/***************************************************************************//** 
 * @brief Prints the number in display 
 *
 * Prints the number converted in 7 segment display
 *
 * @param[in] uint8_t  num
 *
 * @retval void 
 ******************************************************************************/
void seg7_print_num (uint8_t num)
{
    switch(num)
    {
        case 0: PORTD = SEG7_0; break;
        case 1: PORTD = SEG7_1; break;
        case 2: PORTD = SEG7_2; break;
        case 3: PORTD = SEG7_3; break;
        case 4: PORTD = SEG7_4; break;
        case 5: PORTD = SEG7_5; break;
        case 6: PORTD = SEG7_6; break;
        case 7: PORTD = SEG7_7; break;
        case 8: PORTD = SEG7_8; break;
        case 9: PORTD = SEG7_9; break;
        case 10: PORTD = SEG7_DOT; break;
        case 11: PORTD = SEG7_MINUS; break;
        case 12: PORTD = SEG7_CLEAN; break;
        case 13: PORTD = SEG7_A; break;
        case 14: PORTD = SEG7_M; break;
        case 15: PORTD = SEG7_L; break;
    }
}