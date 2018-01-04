// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file esp_types.h
//
// Purpose
//    @brief Specifies the data types used in the project  
//
// Revision Dates
//    2018-01-27 (vigan.abd): Inital create
//    $Log: esp_types.h $
//--

#include "temp_conv.h"

/**
 * @brief temp = raw_val * 0.14 - 41; 1 -> -40*C, 1022 -> 100*C
 */
void raw_2temp_val(uint16_t raw_val, float_t *const res)
{
    mul_zero_float(raw_val, 14, res);
    res->l_part -= 42;
}