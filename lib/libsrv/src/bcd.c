// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file bcd.c
//
// Purpose
//    @brief Specifies the binary to decimal module
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: bcd.c $
//--

#include "bcd.h"

/***************************************************************************//** 
 * @brief Binary to BCD 
 *
 * Convert binary value to binary coded decimal value 
 *
 * @param[in] uint8_t  bin
 * @param[in] bcd_res*  res
 *
 * @retval void 
 ******************************************************************************/
void bin_2bcd (uint8_t bin, bcd_res *const res)
{
    uint8_t i;
    /* Clear result */
    for(i = 0; i < 3; i++)
        res->data[i] = 0;

    i = 0;
    while(bin > 0)
    {
        res->data[i] = bin % 10;
        bin /= 10;
        i++;
        if(i == 3)
            break;
    }
}

/***************************************************************************//** 
 * @brief Binary to BCD Long
 *
 * Convert binary value to binary coded long decimal value 
 *
 * @param[in] uint16_t  bin
 * @param[in] bcd_res_long*  res
 *
 * @retval void 
 ******************************************************************************/
void bin_2bcd_long (uint16_t bin, bcd_res_long *const res)
{
    uint8_t i;
    /* Clear result */
    for(i = 0; i < 7; i++)
        res->data[i] = 0;

    i = 0;
    while(bin > 0)
    {
        res->data[i] = bin % 10;
        bin /= 10;
        i++;
        if(i == 7)
            break;
    }
}

/***************************************************************************//** 
 * @brief Binary to BCD signed
 *
 * Convert binary value to binary coded signed decimal value 
 *
 * @param[in] uint8_t  bin
 * @param[in] bcd_res*  res
 * @param[in] uint8_t*  sign
 *
 * @retval void 
 ******************************************************************************/
void bin_2bcd_signed (uint8_t bin, bcd_res *const res, uint8_t *const sign)
{
    uint8_t i;
    *sign = 12; //7SEG CLEAR SIGN
    /* Clear result */
    for(i = 0; i < 3; i++)
        res->data[i] = 0;

    if (bin > 0x7F)
    {
        bin += 1;
        bin ^= 0xFF;
        *sign = 11; //7SEG MINUS SIGN
    }

    i = 0;
    while(bin > 0)
    {
        res->data[i] = bin % 10;
        bin /= 10;
        i++;
        if(i == 3)
            break;
    }
}


/***************************************************************************//** 
 * @brief Binary to BCD by removing leading zeros
 *
 * Convert binary value to binary coded decimal value by removing leading zeros
 *
 * @param[in] uint8_t  bin
 * @param[in] bcd_res*  res
 *
 * @retval void 
 ******************************************************************************/
void bin_2bcd_rmv_zeros (uint8_t bin, bcd_res *const res)
{
    uint8_t i;
    /* Clear result */
    for(i = 0; i < 3; i++)
        res->data[i] = 0;

    i = 0;
    while(bin > 0)
    {
        res->data[i] = bin % 10;
        bin /= 10;
        i++;
        if(i == 3)
            break;
    }

    if (res->data[2] == 0 && res->data[1] == 0 && res->data[0] != 0)
    {
        res->data[1] = res->data[0];
        res->data[0] = 0;
    }
    else if (res->data[2] == 0 && res->data[1] != 0)
    {
        res->data[2] = res->data[1];
        res->data[1] = res->data[0];
        res->data[0] = 0;
    }

}