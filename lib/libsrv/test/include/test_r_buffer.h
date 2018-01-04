// Copyright (C) 2003-2015 swengLab Technologies - All rights reserved
// Siebenbürgerstrasse 16-26/26/17, A--1220 Vienna, Austria. 
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
//    2017-01-02 (vigan.abd): Initial version
//    $Log: test_r_buffer.h $
//--

#ifndef __TEST_R_BUFFER__H
#define __TEST_R_BUFFER__H 1

#include "r_buffer.h"

/*
 * Define test cases
 */
uint8_t test_r_buffer_empty ();
uint8_t test_r_buffer_push ();
uint8_t test_r_buffer_pop ();
uint8_t test_r_buffer_empty_pop	();
uint8_t test_r_buffer_overflow ();
uint8_t test_r_buffer_rotate ();

/*
 * Define logging functionalities
 */
void dump_r_buffer (r_buffer_t *const buff);


#endif /* __TEST_R_BUFFER__H */ 
