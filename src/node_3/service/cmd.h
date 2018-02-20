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
//    @brief Node 3 command routines
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: cmd.h $
//--

/*
 * Communication buffers
 */
uint8_t rcv_buff[3];
uint8_t snd_buff[3];

/*
 * Fan members
 */
uint8_t fan_speed = 0;

/*
 * Response routine
 */
#define SEND_RESP(SND_BUFF, CH, FLAG) \
    uart_trm(SND_BUFF[0], CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \
    uart_trm(SND_BUFF[1], CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \
    uart_trm(SND_BUFF[2], CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \


/*
 * Read temperature routine
 */
#define CMD_RD_TEMP(TMP_R_PART, TMP_L_PART, SND_BUFF, CH, FLAG) \
    SND_BUFF[0] = CMD_N3_RES; \
    SND_BUFF[1] = TMP_R_PART; \
    SND_BUFF[2] = TMP_L_PART; \
    SEND_RESP(SND_BUFF, CH, FLAG) \


/*
 * Read light routine
 */
#define CMD_RD_LIGHT(LIGHT, SND_BUFF, CH, FLAG) \
    SND_BUFF[0] = CMD_N3_RES; \
    SND_BUFF[1] = (uint8_t) (LIGHT & 0xFF); \
    SND_BUFF[2] = (uint8_t) (LIGHT >> 8); \
    SEND_RESP(SND_BUFF, CH, FLAG) \


/*
 * Set fan speed routine
 */
#define CMD_SET_FAN_SPEED(FAN_SPEED, RCV_BUFF, CH, FLAG) \
    uart_rcv(&RCV_BUFF[1], CH, &FLAG); \
    FAN_SPEED = RCV_BUFF[1] % 5; \
    PORTD = ~(1 << FAN_SPEED); \
    uart_trm(CMD_N3_ACK, CH, &FLAG); \
    uart_flush(CH); \
    fan_set_speed(FAN_SPEED); \

