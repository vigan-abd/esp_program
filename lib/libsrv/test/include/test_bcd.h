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

#ifndef __TEST_R_BUFFER__H
#define __TEST_R_BUFFER__H 1

#include "bcd.h"

/*
 * Define test cases
 */
uint8_t test_bcd_conversion ();
uint8_t test_bcd_max_conversion ();
uint8_t test_bcd_min_conversion ();

/*
 * Define logging functionalities
 */
void dump_bcd_res (bcd_res *const res);


#endif /* __TEST_R_BUFFER__H */ 