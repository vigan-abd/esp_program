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
 * Buffer that stores values readon from temperature sensor
 */
uint8_t temp_buff[2]; /* 0 -> r_part, 1 -> l_part */

/*
 * Buffer that stores values readon from light sensor
 */
uint8_t light_buff[2];

/*
 * Buffers that store values readen from GUI interface
 */
uint8_t fan_speed = 0;
uint8_t light_int = 0;

/*
 * Members used for controlling asyncronous reads from GUI interface
 */
uint8_t async_flag = 0;
uint8_t async_rcv_buff[4];
uint8_t async_rcv_idx = 0;
uint8_t async_data = 0;

/*
 * Routines for node 3 commands
 */
#define CMD_READ_TEMP(TEMP_BUFF, RCV_BUFF, CH, FLAG) \
	uart_trm(CMD_N3_RD_TEMP, CH, &FLAG); \
    uart_flush(CH); \
    uart_rcv(&RCV_BUFF[0], CH, &FLAG); \
    uart_rcv(&RCV_BUFF[1], CH, &FLAG); \
    uart_rcv(&RCV_BUFF[2], CH, &FLAG); \
    if (RCV_BUFF[0] == CMD_N3_RES) \
    { \
	    TEMP_BUFF[0] = RCV_BUFF[1]; \
		TEMP_BUFF[1] = RCV_BUFF[2]; \
        PORTB = ~TEMP_BUFF[0]; \
	} \


#define CMD_READ_LIGHT(LIGHT_BUFF, RCV_BUFF, CH, FLAG) \
	uart_trm(CMD_N3_RD_LIGHT, CH, &FLAG); \
    uart_flush(CH); \
    uart_rcv(&RCV_BUFF[0], CH, &FLAG); \
    uart_rcv(&RCV_BUFF[1], CH, &FLAG); \
    uart_rcv(&RCV_BUFF[2], CH, &FLAG); \
    if (RCV_BUFF[0] == CMD_N3_RES) \
    { \
	    LIGHT_BUFF[0] = RCV_BUFF[1]; \
		LIGHT_BUFF[1] = RCV_BUFF[2]; \
        PORTB = ~LIGHT_BUFF[0]; \
	} \

    
#define CMD_SET_FAN_SPEED(FAN_SPEED, RCV_BUFF, CH, FLAG) \
    uart_trm(CMD_N3_SET_FAN_SPEED, CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \
    uart_trm(FAN_SPEED, CH, &FLAG); \
    uart_flush(CH); \
    uart_rcv(&RCV_BUFF[0], CH, &FLAG); \


/*
 * Routines for node 2 commands
 */
 #define CMD_WRITE_TEMP(TEMP_BUFF, RCV_BUFF, CH, FLAG) \
    uart_trm(CMD_N2_WR_TEMP_VAL, CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \
    uart_trm(TEMP_BUFF[0], CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \
    uart_trm(TEMP_BUFF[1], CH, &FLAG); \
    uart_flush(CH); \
    uart_rcv(&RCV_BUFF[0], CH, &FLAG); \
    

/*
 * Routines for node 1 commands
 */
#define CMD_WRITE_LIGHT(LIGHT_BUFF, RCV_BUFF, CH, FLAG) \
    uart_trm(CMD_N2_WR_LIGHT_VAL, CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \
    uart_trm(LIGHT_BUFF[0], CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \
    uart_trm(LIGHT_BUFF[1], CH, &FLAG); \
    uart_flush(CH); \
    uart_rcv(&RCV_BUFF[0], CH, &FLAG); \

    
#define CMD_SET_LIGHT_INT(LIGHT_INT, RCV_BUFF, CH, FLAG) \
    uart_trm(CMD_N1_SET_LIGHT_INT, CH, &FLAG); \
    uart_flush(CH); \
    _delay_ms(100); \
    uart_trm(LIGHT_INT, CH, &FLAG); \
    uart_flush(CH); \
    uart_rcv(&RCV_BUFF[0], CH, &FLAG); \
    

/*
 * Routines for node 0 commands from GUI interface
 */
ISR(UART_ISR_RX1)
{
    async_data = UDR1;
    async_rcv_buff[async_rcv_idx] = async_data;
    async_rcv_idx++;
    if(async_rcv_idx == 4)
    {
        async_flag = 1;
        async_rcv_idx = 0;
    }
}

/*
 * Routine that merges two 4 bit values to one 8 bit value
 */
#define MERGE_NIBBLES(L_NIB, H_NIB) (L_NIB | (H_NIB << 4))

/*
 * Check if all data are red from GUI interface and merge 4 bit values to 2 8bit values
 * GUI interface sends 4 bit values!
 */
#define CMD_CHECK_MASTER(FAN_SPEED, LIGHT_INT, ASYNC_FLAG, RCV_BUFF) \
    if(ASYNC_FLAG == 1) \
    { \
        ASYNC_FLAG = 0; \
 \
        if(MERGE_NIBBLES(RCV_BUFF[0], RCV_BUFF[1]) == CMD_N0_WR_FAN) \
        { \
            FAN_SPEED = MERGE_NIBBLES(RCV_BUFF[2], RCV_BUFF[3]); \
        } \
        else if(MERGE_NIBBLES(RCV_BUFF[0], RCV_BUFF[1]) == CMD_N0_WR_LIGHT) \
        { \
            LIGHT_INT = MERGE_NIBBLES(RCV_BUFF[2], RCV_BUFF[3]); \
        } \
    } \

