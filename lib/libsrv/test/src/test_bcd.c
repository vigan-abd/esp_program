// Copyright (C) 2017-2018 University of Prishtina - All rights reserved
// Kodra e Diellit, 10000 Prishtina, Kosovo. 
// Author: Abdurrahmani Vigan   vigan.abd@gmail.com
//
//++
// Name
//    @file test.h
//
// Purpose
//    @brief Implements the ring buffer test cases
//
// Author
//    @author: Abdurrahmani Vigan, vigan.abd@gmail.com
//    $Author: vigan.abd $
//
// Revision Dates
//    2018-01-27 (vigan.abd): Refactoring
//    $Log: test_r_buffer.h $
//--

#include <stdio.h>
#include "test_bcd.h"

/***************************************************************************//** 
 * @brief Tests conversion
 *
 * Tests convertion of byte to BCD
 *
 * @retval void
 ******************************************************************************/
uint8_t test_bcd_conversion ()
{
    bcd_res res;
    
    bin_2bcd (37, &res);
    dump_bcd_res(&res);
    
    if (res.data[0] == 7 && res.data[1] == 3 && res.data[2] == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/***************************************************************************//** 
 * @brief Tests 0xFF input
 *
 * Check if 0xFF is converted to [2, 5, 5]
 *
 * @retval void
 ******************************************************************************/
uint8_t test_bcd_max_conversion ()
{
    bcd_res res;
    
    bin_2bcd (255, &res);
    dump_bcd_res(&res);
    
    if (res.data[0] == 5 && res.data[1] == 5 && res.data[2] == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/***************************************************************************//** 
 * @brief Tests 0x00 input
 *
 * Check if 0x00 is converted to [0, 0, 0]
 *
 * @retval void
 ******************************************************************************/
uint8_t test_bcd_min_conversion ()
{
    bcd_res res;
    
    bin_2bcd (0, &res);
    dump_bcd_res(&res);
    
    if (res.data[0] == 0 && res.data[1] == 0 && res.data[2] == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/***************************************************************************//** 
 * @brief Prints BCD result
 *
 * Prints the content of the BCD result
 *
 * @param[in] dump_bcd_res  res
 *
 * @retval void
 ******************************************************************************/
void dump_bcd_res (bcd_res *const res)
{
    int i;
    for (i = 2; i >= 0; i--)
    {
        printf("%d", res->data[i]);
    }
    printf("\n");
}