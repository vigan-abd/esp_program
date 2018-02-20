// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file tmr.c
//
// Purpose
//    @brief Specifies the timer functionalities
//
// Revision Dates
//    2018-01-27 (vigan): Inital create
//    $Log: tmr.c $
//--

#include "tmr.h"

/***************************************************************************//** 
 * @brief Enable timer 0 overflow interrupt
 *
 * Enable timer 0 overflow interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr0_set_toie ()
{
    TIMSK |= (1 << TOIE0);
}

/***************************************************************************//** 
 * @brief Enable timer 0 compare match interrupt
 *
 * Enable timer 0 compare match interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr0_set_ocie ()
{
    TIMSK |= (1 << OCIE0);
}

/***************************************************************************//** 
 * @brief Initializes timer 0 in counter compaer mode
 *
 * Initializes timer 0 in counter compare mode 
 *
 * @param[in] uint8_t  ocr0
 * @param[in] uint8_t  presc
 *
 * @retval void 
 ******************************************************************************/
void tmr0_init_ctc(uint8_t ocr0, uint8_t presc)
{

    /* Init timer counter and output compare */
    TCNT0 = 0;
    OCR0 = ocr0;

    /* Enable interrupt in timer interrupt mask for output compare */
    TIMSK |= (1 << OCIE0);

    /* 
     * Mode CTC with OCR1A: WGM13:0 = 4
     * Clock src is CPU: CS12:0 = 1 and no prescale
     */
    TCCR0 = (1 << WGM01) |  presc;
}

/***************************************************************************//** 
 * @brief Disable timer 0 overflow interrupt
 *
 * Disable timer 0 overflow interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr0_clr_toie ()
{
    TIMSK &= ~(1 << TOIE0);
}

/***************************************************************************//** 
 * @brief Disable timer 0 compare match interrupt
 *
 * Disable timer 0 compare match interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr0_clr_ocie ()
{
    TIMSK &= ~(1 << OCIE0);
}

/***************************************************************************//** 
 * @brief Enable timer 1 overflow interrupt
 *
 * Enable timer 1 overflow interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr1_set_toie ()
{
    TIMSK |= (1 << TOIE1);
}

/***************************************************************************//** 
 * @brief Enable timer 1 compare match interrupt
 *
 * Enable timer 1 compare match interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr1_set_ocie ()
{
    TIMSK |= (1 << OCIE1A);
}

/***************************************************************************//** 
 * @brief Initializes timer 1 in counter compaer mode
 *
 * Initializes timer 1 in counter compare mode 
 *
 * @param[in] uint16_t  ocr1
 * @param[in] uint8_t  presc
 *
 * @retval void 
 ******************************************************************************/
void tmr1_init_ctc(uint16_t ocr1, uint8_t presc)
{
    /* Init timer counter and output compare */
    TCNT1 = 0;
    OCR1A = ocr1;

    /* Enable interrupt in timer interrupt mask for output compare */
    TIMSK |= (1 << OCIE1A);

    /* 
     * Mode CTC with OCR1A: WGM13:0 = 4
     * Clock src is CPU: CS12:0 = 1 and no prescale
     */
    TCCR1A = 0x00;
    TCCR1B = (1 << WGM12) | presc;
}

/***************************************************************************//** 
 * @brief Disable timer 1 overflow interrupt
 *
 * Disable timer 1 overflow interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr1_clr_toie ()
{
    TIMSK &= ~(1 << TOIE1);
}

/***************************************************************************//** 
 * @brief Disable timer 1 compare match interrupt
 *
 * Disable timer 1 compare match interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr1_clr_ocie ()
{
    TIMSK &= ~(1 << OCIE1A);
}

/***************************************************************************//** 
 * @brief Enable timer 2 overflow interrupt
 *
 * Enable timer 2 overflow interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr2_set_toie ()
{
    TIMSK |= (1 << TOIE2);
}

/***************************************************************************//** 
 * @brief Enable timer 2 compare match interrupt
 *
 * Enable timer 2 compare match interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr2_set_ocie ()
{
    TIMSK |= (1 << OCIE2);
}

/***************************************************************************//** 
 * @brief Initializes timer 2 in counter compaer mode
 *
 * Initializes timer 2 in counter compare mode 
 *
 * @param[in] uint8_t  ocr2
 * @param[in] uint8_t  presc
 *
 * @retval void 
 ******************************************************************************/
void tmr2_init_ctc (uint8_t ocr2, uint8_t presc)
{

    /* Init timer counter and output compare */
    TCNT2 = 0;
    OCR2 = ocr2;

    /* Enable interrupt in timer interrupt mask for output compare */
    TIMSK |= (1 << OCIE2);

    /* 
     * Mode CTC with OCR1A: WGM13:0 = 4
     * Clock src is CPU: CS12:0 = 1 and no prescale
     */
    TCCR2 = (1 << WGM21) |  presc;
}

/***************************************************************************//** 
 * @brief Disable timer 2 overflow interrupt
 *
 * Disable timer 2 overflow interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr2_clr_toie ()
{
    TIMSK &= ~(1 << TOIE2);
}

/***************************************************************************//** 
 * @brief Disable timer 2 compare match interrupt
 *
 * Disable timer 2 compare match interrupt
 *
 * @retval void 
 ******************************************************************************/
void tmr2_clr_ocie ()
{
    TIMSK &= ~(1 << OCIE2);
}