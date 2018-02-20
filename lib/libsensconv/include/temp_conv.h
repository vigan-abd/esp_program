// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file temp_conv.h
//
// Purpose
//    @brief Specifies the members of temperature parser module
//
// Revision Dates
//    2018-01-27 (vigan.abd): Inital create
//    $Log: temp_conv.h $
//--

#ifndef __TEMP_CONV__H
#define __TEMP_CONV__H 1

#include "esp_types.h"

/*
 * Declarations of temperature parser members
 */
void raw_2temp_val(uint16_t raw_val, float_t *const res);

#endif /* __TEMP_CONV__H */ 