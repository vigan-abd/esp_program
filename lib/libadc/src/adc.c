// Copyright (C) 2017-2018 University of Prishtina - All rights reserved
// Kodra e Diellit, 10000 Prishtina, Kosovo. 
// Author: Dr. SMAILI Idriz   smaili.idriz@gmail.com
//
//++
// Name
//    @file adc.c
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
//    $Log: adc.c $
//--

#include "adc.h"

/***************************************************************************//** 
 * @brief Initialize the ADC 
 *
 * Initializes the ADC by providing the prescaler div factor. The Avcc is used.
 *
 * @param[in] uint8_t  specifies the prescaler div factor
 *
 * @retval void 
 ******************************************************************************/
void adc_init (uint8_t presc_fact)
{
    // specify the Aref=AVcc;
    ADMUX = (1 << REFS0);

    // clear prescaler bits
    ADCSRA &= ~((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2)); 

    /* set the predefined prescaler */
    ADCSRA |= presc_fact;

    /* enables conversion */
    ADCSRA |= (1 << ADEN);
}

/***************************************************************************//** 
 * @brief Reads a raw value from the ADC 
 *
 * Reads the raw value from the specified ADC channel.
 *
 * @param[in] uint8_t  specifies the prescaler div factor
 *
 * @retval ADC_NO_ERROR         if the adc channel has been read successfully
 * @retval ADC_INVALID_CHANNEL  if a wrong adc channel was selected
 * @retval ADC_SHORT_2GND       if a short to ground has been detected
 * @retval ADC_SHORT_2BATTERY   if a short to batery has been detected
 ******************************************************************************/
uint8_t adc_get_raw (uint16_t *const raw_value, uint8_t channel)
{
    uint16_t val = 0;

    if (channel > 7) 
    {
        return (uint8_t) ADC_INVALID_CHANNEL;
    }
  
    /* select the ADC Channel ch must be 0-7 */
    ADMUX |= channel;

    /* start single conversion */
    ADCSRA |= (1 << ADSC);

    /* wait for conversion to complete */
    while (! (ADCSRA & (1 << ADIF)))
        ;

    val = (ADCH << 8) | ADCL;

    /* clear ADIF by writing one to it -> make it ready for the next adc conversion */
    ADCSRA |= (1<<ADIF);

    if (val == 0x000)
    {
        return (uint8_t) ADC_SHORT_2GND;
    }
    else if (val == 0x3FF)
    {
        return (uint8_t) ADC_SHORT_2BATTERY;
    }

    *raw_value = val;

    return (uint8_t) ADC_NO_ERROR;
}