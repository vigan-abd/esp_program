// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file node_0.c
//
// Purpose
//    @brief Node 0 main entry
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: node_0.c $
//--
#include "node_0.h"

int main (void)
{
    port_init();
    uart_init(BAUD0_PRESCALE, UART_CH_0);
    uart_init(BAUD1_PRESCALE, UART_CH_1);
    uart_set_rcv_int(UART_CH_1);
    sei();

    // Wait for all nodes to set up
    _delay_ms(10000);
    while (1)
    {
        /* Node 0 Commands */
        CMD_CHECK_MASTER(fan_speed, light_int, async_flag, async_rcv_buff)


        /* Node 3 Commands */
        CMD_READ_TEMP(temp_buff, rcv_buff, UART_CH_0, empty_flag)
        _delay_ms(CMD_DELAY);

        CMD_READ_LIGHT(light_buff, rcv_buff, UART_CH_0, empty_flag)
        _delay_ms(CMD_DELAY);

        CMD_SET_FAN_SPEED(fan_speed, rcv_buff, UART_CH_0, empty_flag)
        _delay_ms(CMD_DELAY);
        


        /* Node 2 Commands */
        CMD_WRITE_TEMP(temp_buff, rcv_buff, UART_CH_0, empty_flag)
        _delay_ms(CMD_DELAY);

        CMD_WRITE_LIGHT(light_buff, rcv_buff, UART_CH_0, empty_flag)
        _delay_ms(CMD_DELAY);


        /* Node 1 Commands */
        CMD_SET_LIGHT_INT(light_int, rcv_buff, UART_CH_0, empty_flag)
        _delay_ms(CMD_DELAY);
    }
	return 0;
}
