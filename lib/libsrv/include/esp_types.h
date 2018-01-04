// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//		   BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//		   BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file esp_types.h
//
// Purpose
//    @brief Specifies the data types used in the project  
//
// Revision Dates
//    2018-01-27 (vigan.abd): Refactoring
//    $Log: esp_types.h $
//--

#ifndef __ESP_TYPES__H
#define __ESP_TYPES__H 1

typedef unsigned char uint8_t;

#if !defined (__linux__)
/*
 * Declarations of the data types
 */
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

// typedef char int8_t;
typedef int int16_t;
typedef long int32_t;
typedef long long int64_t;

typedef struct _float_t 
{
	uint8_t l_part;
	uint8_t r_part;
} float_t;
#endif

#endif /* __ESP_TYPES__H */ 
