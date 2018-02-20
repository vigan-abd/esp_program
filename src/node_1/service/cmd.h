// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file cmd.h
//
// Purpose
//    @brief Node 1 command routines
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: cmd.h $
//--

/*
 * Communication buffers
 */
uint8_t rcv_buff[3];

/*
 * Light intensity duty cycle
 */
uint8_t light_int = 0;

/*
 * Routine used to write light sensor value to LCD
 */
#define CMD_WR_LIGHT_VAL(DISP_BUFF, RCV_BUFF, CH, FLAG) \
uart_rcv(&RCV_BUFF[1], CH, &FLAG); \
    uart_rcv(&RCV_BUFF[2], CH, &FLAG); \
    uart_trm(CMD_N1_ACK, CH, &FLAG); \
    uart_flush(CH); \
    DISP_BUFF[0] = RCV_BUFF[1]; \
    DISP_BUFF[1] = RCV_BUFF[2]; \
    SET_LCD_VALS(DISP_BUFF) \


/*
 * Routine used to set pwm duty cycle for light intensity
 */
#define CMD_SET_LIGHT_INT(LIGHT_INT, RCV_BUFF, CH, FLAG) \
    uart_rcv(&RCV_BUFF[1], CH, &FLAG); \
    LIGHT_INT = RCV_BUFF[1] % 5; \
    uart_trm(CMD_N1_ACK, CH, &FLAG); \
    uart_flush(CH); \
    bulb_set_int(LIGHT_INT); \

