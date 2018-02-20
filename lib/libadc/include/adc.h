// Copyright (C) 2017-2018 University of Prishtina - All rights reserved
// Kodra e Diellit, 10000 Prishtina, Kosovo. 
// Author: Dr. SMAILI Idriz   smaili.idriz@gmail.com
//
//++
// Name
//    @file adc.h
//
// Purpose
//    @brief Implements the routine needed to handle the ADC  
//
// Author
//    @author: Dr. Dipl.-Ing. Idriz SMAILI, smaili.idriz@gmail.com
//    $Author: smaili $
//
// Revision Dates
//    2018-01-27 (vigan.abd): Refactoring
//    $Log: adc.h $
//--

#ifndef __ADC__H
#define __ADC__H 1

#include "esp_types.h"
#include <avr/io.h> 
#include "util/delay.h"

/*
 * Declarations of ADC's error codes
 */
#define ADC_NO_ERROR 0x01
#define ADC_INVALID_CHANNEL 0x02
#define ADC_SHORT_2GND 0x04
#define ADC_SHORT_2BATTERY 0x10

/*
 * Declarations of ADC's prescaler div factors
 */
#define ADC_PRESCALER_FACT_002 (1 << ADPS0)
#define ADC_PRESCALER_FACT_004 (1 << ADPS1)
#define ADC_PRESCALER_FACT_008 ((1 << ADPS0) | (1 << ADPS1))
#define ADC_PRESCALER_FACT_016 (1 << ADPS2)
#define ADC_PRESCALER_FACT_032 ((1 << ADPS0) | (1 << ADPS2))
#define ADC_PRESCALER_FACT_064 ((1 << ADPS1) | (1 << ADPS2))
#define ADC_PRESCALER_FACT_128 ((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2))

/*
 * Declarations of ADC's members
 */
void adc_init (uint8_t presc_fact);
uint8_t adc_get_raw (uint16_t *const raw_value, uint8_t channel);

#endif /* __ADC__H */ 
