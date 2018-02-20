// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file sensor.h
//
// Purpose
//    @brief Node 3 sensor routines
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: sensor.h $
//--

/*
 * Sensor Constants
 */
#define ADC_TEMP_CH 1
#define ADC_TEMP_KV_CH 0
#define ADC_LIGHT_CH 2
#define ADC_FAN_CH 3

/*
 * Sensor members
 */
float_t temp;
uint16_t raw_temp;
uint16_t raw_light;
uint8_t read_adc = ADC_TEMP_CH;

/*
 * Timer compare interrupt used to read ADC channels
 */
ISR (TMR_ISR_OCR2)
{
    if (read_adc == ADC_TEMP_CH)
    {
        adc_get_raw (&raw_temp, ADC_TEMP_CH);
        raw_2temp_val(raw_temp, &temp);
        read_adc = ADC_LIGHT_CH;
    }
    else
    {
        adc_get_raw (&raw_light, ADC_LIGHT_CH);
        read_adc = ADC_TEMP_CH;
    }
}