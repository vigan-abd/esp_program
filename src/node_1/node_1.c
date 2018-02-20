// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file node_1.c
//
// Purpose
//    @brief Node 1 main entry
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: node_1.c $
//--
#include "node_1.h"

int main (void)
{
    init_port();
    bulb_init();
    uart_init (BAUD0_PRESCALE, UART_CH_0);
    sei();
    while (1)
    {
        rcv_buff[0] = 0;
		_delay_ms(1000);

        uart_rcv(&rcv_buff[0], UART_CH_0, &empty_flag);
        if (rcv_buff[0] == CMD_N1_WR_LIGHT_VAL)
        {
            CMD_WR_LIGHT_VAL(display_buff, rcv_buff, UART_CH_0, empty_flag)
        }
        else if (rcv_buff[0] == CMD_N1_SET_LIGHT_INT)
        {
            CMD_SET_LIGHT_INT(light_int, rcv_buff, UART_CH_0, empty_flag)
        }
        else
        {
            continue;
        }
    }
    
    return 0;
}