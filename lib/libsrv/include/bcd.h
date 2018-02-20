// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file bcd.h
//
// Purpose
//    @brief Specifies the binary to decimal module  
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: bcd.h $
//--

#ifndef __BCD__H
#define __BCD__H 1

#include "esp_types.h"

/*
 * Definition of the result data structure 
 */
typedef struct _bcd_res
{
    uint8_t data[3];
} bcd_res;
typedef struct _bcd_res_long
{
    uint8_t data[8];
} bcd_res_long;

/*
 * Declarations of binary to binary coded decimal converter
 */
void bin_2bcd (uint8_t bin, bcd_res *const res);
void bin_2bcd_long (uint16_t bin, bcd_res_long *const res);
void bin_2bcd_signed (uint8_t bin, bcd_res *const res, uint8_t *const sign);
void bin_2bcd_rmv_zeros(uint8_t bin, bcd_res *const res);

#endif /* __BCD__H */ 