// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file display.h
//
// Purpose
//    @brief Node 2 display routines
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: display.h $
//--

/*
 * Display flags
 */
#define DISP_TEMP 0
#define DISP_LIGHT 1

/*
 * Display control members
 */
uint8_t display_idx = 0;
uint8_t display_buff[8];
uint16_t switch_it = 0;
uint8_t switch_val = DISP_TEMP;

/*
 * Timer ISR used for data display
 */
ISR (TMR_ISR_OCR1A)
{
    seg7_set_seg(display_idx);
    seg7_print_num(display_buff[display_idx]);   
    display_idx = (display_idx + 1) % 8;
    switch_it++;
}

/*
 * Critical ISR used to transfer data to display buffer
 */
#define SET_DISPLAY_VALS(I, DISP_BUFF, R_PART, L_PART, LIGHT_RES) \
    tmr1_clr_ocie(); \
    /* ENTER CRITICAL SECTION */ \
    if (switch_it > 1000) \
    { \
        switch_val = (switch_val == DISP_TEMP ? DISP_LIGHT : DISP_TEMP); \
        switch_it = 0; \
    } \
 \
    if (switch_val == DISP_TEMP) \
    { \
        for(I = 0; I < 3; I++) \
        { \
            DISP_BUFF[I] = R_PART[I]; \
        } \
        DISP_BUFF[3] = 10; \
        for(I = 0; I < 3; I++) \
        { \
            DISP_BUFF[I + 4] = L_PART[I]; \
        } \
    } \
    else \
    { \
        for(I = 0; I < 5; I++) \
        { \
            DISP_BUFF[I] = LIGHT_RES[I]; \
        } \
        DISP_BUFF[5] = 12; \
        DISP_BUFF[6] = 12; \
        DISP_BUFF[7] = 15; \
    } \
    /* EXIT CRITICAL SECTION */ \
    tmr1_set_ocie(); \

