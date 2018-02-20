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
//    @brief Node 2 command routines
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
 * Routine that writes temperature value for display
 */
#define CMD_WR_TEMP_VAL(R_PART, L_PART, SIGN, RCV_BUFF, CH, FLAG)\
    uart_rcv(&RCV_BUFF[1], CH, &FLAG); \
    uart_rcv(&RCV_BUFF[2], CH, &FLAG); \
    uart_trm(CMD_N2_ACK, CH, &FLAG); \
    uart_flush(CH); \
    bin_2bcd_rmv_zeros(RCV_BUFF[1], &R_PART); \
    bin_2bcd_signed(RCV_BUFF[2], &L_PART, &SIGN); \


/*
 * Routine that writes light value for display
 */
#define CMD_WR_LIGHT_VAL(VAR_16BIT, LIGHT_RES, RCV_BUFF, CH, FLAG)\
    uart_rcv(&RCV_BUFF[1], CH, &FLAG); \
    uart_rcv(&RCV_BUFF[2], CH, &FLAG); \
    uart_trm(CMD_N2_ACK, CH, &FLAG); \
    uart_flush(CH); \
    VAR_16BIT = 0xFFFF & RCV_BUFF[2]; \
    VAR_16BIT = (VAR_16BIT << 8) | RCV_BUFF[1]; \
    bin_2bcd_long (VAR_16BIT, &LIGHT_RES); \

