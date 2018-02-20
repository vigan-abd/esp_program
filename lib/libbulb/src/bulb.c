// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file bulb.c
//
// Purpose
//    @brief Specifies the members of light bulb module 
//
// Revision Dates
//    2018-01-27 (vigan): Inital create
//    $Log: bulb.c $
//--
#include "bulb.h"

/***************************************************************************//** 
 * @brief Initializes the bulb pwm generator
 *
 * Initializes the bulb pwm generator
 *
 * @retval void 
 ******************************************************************************/
void bulb_init()
{
    // PB1 as output for wawe
    DDR_BULB |= (1 << DD_BULB);

    // Non inverting mode for PWM
    TCCR1A |= (1 << COM1A1);

    // PWM phase correct mode (10 bit) in Timer
    TCCR1A |= (1 << WGM11) | (1 << WGM10); //MAX 3FF

    // Prescale factor of 8
    TCCR1B |= (1 << CS11); // 1.84 MHz

    BULB_DUTY_CYCLE = 0x0000;
}

/***************************************************************************//** 
 * @brief Sets the light intensity 
 *
 * Sets the duty cycles in the PWM via timer
 *
 * @param[in] uint8_t  i
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t bulb_set_int (uint8_t i)
{
	if (i > 4)
		return BULB_INVALID_INTENSITY;
	switch(i)
	{
		case 0: BULB_DUTY_CYCLE = 0x0000; break;
		case 1: BULB_DUTY_CYCLE = 0x00FF; break;
		case 2: BULB_DUTY_CYCLE = 0x01FF; break;
		case 3: BULB_DUTY_CYCLE = 0x02FF; break;
		case 4: BULB_DUTY_CYCLE = 0x03FF; break;
	}

	return BULB_NO_ERROR;
}