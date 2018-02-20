// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file fan.c
//
// Purpose
//    @brief Specifies the members of fan module
//
// Revision Dates
//    2018-01-27 (vigan): Inital create
//    $Log: fan.c $
//--
#include "fan.h"

/***************************************************************************//** 
 * @brief Initializes the fan pwm generator
 *
 * Initializes the fan pwm generator
 *
 * @retval void 
 ******************************************************************************/
void fan_init()
{
    // PB1 as output for wawe
    DDR_FAN |= (1 << DD_FAN);

    // Non inverting mode for PWM
    TCCR1A |= (1 << COM1A1);

    // PWM phase correct mode (10 bit) in Timer
    TCCR1A |= (1 << WGM11) | (1 << WGM10); //MAX 3FF

    // Prescale factor of 8
    TCCR1B |= (1 << CS11); // 1.84 MHz

    FAN_DUTY_CYCLE = 0x0000;
}

/***************************************************************************//** 
 * @brief Sets the fan speed 
 *
 * Sets the duty cycles in the PWM via timer
 *
 * @param[in] uint8_t  s
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t fan_set_speed (uint8_t s)
{
    if (s > 4)
        return FAN_INVALID_SPEED;
    switch(s)
    {
        case 0: FAN_DUTY_CYCLE = 0x0000; break;
        case 1: FAN_DUTY_CYCLE = 0x012F; break;
        case 2: FAN_DUTY_CYCLE = 0x01FF; break;
        case 3: FAN_DUTY_CYCLE = 0x02FF; break;
        case 4: FAN_DUTY_CYCLE = 0x03FF; break;
    }

    return FAN_NO_ERROR;
}