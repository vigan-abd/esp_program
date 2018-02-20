// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file esp_math.c
//
// Purpose
//    @brief Specifies the math library used in solution  
//
// Revision Dates
//    2018-01-27 (vigan.abd): Inital create
//    $Log: esp_math.c $
//--

#ifndef __ESP_MATH__H
#define __ESP_MATH__H 1

#include "esp_types.h"
#include "esp_math.h"

/***************************************************************************//** 
 * @brief Multiplies 16bit integer with double precision float number
 *
 * Multiplies arg1 with floating point that has zero before floating fraction (e.g. 1022 * 0.14)
 *
 * @param[in] uint16_t  arg1
 * @param[in] uint8_t  div_f_part
 * @param[in] float_t*  res
 *
 * @retval void
 ******************************************************************************/
void mul_zero_float(uint16_t arg1, uint8_t div_f_part, float_t *const res)
{
    arg1 *= div_f_part;
    res->l_part = arg1 / 100;
    res->r_part = arg1 % 100;
}

#endif /* __ESP_MATH__H */ 