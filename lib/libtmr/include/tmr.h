// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file tmr.h
//
// Purpose
//    @brief Specifies the timer functionalities
//
// Revision Dates
//    2018-01-27 (vigan): Inital create
//    $Log: tmr.h $
//--

#ifndef __TMR__H
#define __TMR__H 1

#include <avr/io.h> 
#include "esp_types.h"

/*
 * Declaration of ISR flags
 */
#define TMR_ISR_OCR1A SIG_OUTPUT_COMPARE1A
#define TMR_ISR_OCR0 TIMER0_COMP_vect
#define TMR_ISR_OCR2 TIMER2_COMP_vect

/*
 * Declarations of timer 0 prescale factors
 */
#define TMR0_PRESCALER_FACT_NO_SRC (~(1 << CS00)) & (~(1 << CS01)) & (~(1 << CS02))
#define TMR0_PRESCALER_FACT_1 (1 << CS00)
#define TMR0_PRESCALER_FACT_8 (1 << CS01)
#define TMR0_PRESCALER_FACT_32 (1 << CS00) | (1 << CS01)
#define TMR0_PRESCALER_FACT_64 (1 << CS02)
#define TMR0_PRESCALER_FACT_128 (1 << CS00) | (1 << CS02)
#define TMR0_PRESCALER_FACT_256 (1 << CS01) | (1 << CS02)
#define TMR0_PRESCALER_FACT_1024 (1 << CS00) | (1 << CS01) | (1 << CS02)

#define TMR0_PWM_NORMAL (1 << COM01)
#define TMR0_PWM_INVERTED (1 << COM01) | (1 << COM00)

/*
 * Declarations of timer 1 prescale factors
 */
#define TMR1_PRESCALER_FACT_NO_SRC (~(1 << CS10)) & (~(1 << CS11)) & (~(1 << CS12))
#define TMR1_PRESCALER_FACT_1 (1 << CS10)
#define TMR1_PRESCALER_FACT_8 (1 << CS11)
#define TMR1_PRESCALER_FACT_64 (1 << CS10) | (1 << CS11)
#define TMR1_PRESCALER_FACT_256 (1 << CS12)
#define TMR1_PRESCALER_FACT_1024 (1 << CS10) | (1 << CS12)

#define TMR1_PWM_NORMAL (1 << COM1A1)
#define TMR1_PWM_INVERTED (1 << COM1A1) | (1 << COM1A0)

#define TMR2_PRESCALER_FACT_NO_SRC (~(1 << CS20)) & (~(1 << CS21)) & (~(1 << CS22))
#define TMR2_PRESCALER_FACT_1 (1 << CS20)
#define TMR2_PRESCALER_FACT_8 (1 << CS21)
#define TMR2_PRESCALER_FACT_32 (1 << CS20) | (1 << CS21)
#define TMR2_PRESCALER_FACT_64 (1 << CS22)
#define TMR2_PRESCALER_FACT_128 (1 << CS20) | (1 << CS22)
#define TMR2_PRESCALER_FACT_256 (1 << CS21) | (1 << CS22)
#define TMR2_PRESCALER_FACT_1024 (1 << CS20) | (1 << CS21) | (1 << CS22)

#define TMR2_PWM_NORMAL (1 << COM21)
#define TMR2_PWM_INVERTED (1 << COM21) | (1 << COM20)

/*
 * Declarations of timer 0 members
 */
void tmr0_set_toie (void);
void tmr0_set_ocie (void);
void tmr0_init_ctc(uint8_t ocr0, uint8_t presc);
void tmr0_clr_toie (void);
void tmr0_clr_ocie (void);


void tmr2_set_toie (void);
void tmr2_set_ocie (void);
void tmr2_init_ctc(uint8_t ocr2, uint8_t presc);
void tmr2_clr_toie (void);
void tmr2_clr_ocie (void);
/*
 * Declarations of timer 0 members
 */
void tmr1_set_toie (void);
void tmr1_set_ocie (void);
void tmr1_init_ctc(uint16_t ocr1, uint8_t presc);
void tmr1_clr_toie (void);
void tmr1_clr_ocie (void);

#endif /* __TMR__H */ 
