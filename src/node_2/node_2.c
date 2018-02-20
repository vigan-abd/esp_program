// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file node_2.c
//
// Purpose
//    @brief Node 2 main entry
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: node_2.c $
//--

#include "node_2.h"

int main (void)
{
    uint8_t i;
    uint16_t var_16bit;
    bcd_res r_part;
    bcd_res l_part;
    bcd_res_long light_res;

    init_port();
    tmr1_init_ctc(OCR1_VAL, TMR1_PRESCALER_FACT_8);
    uart_init (BAUD0_PRESCALE, UART_CH_0);
    sei();

    while (1)
    {
        _delay_ms(1000);
        rcv_buff[0] = 0;

        uart_rcv(&rcv_buff[0], UART_CH_0, &empty_flag);
        if (rcv_buff[0] == CMD_N2_WR_TEMP_VAL)
        {
            CMD_WR_TEMP_VAL(r_part, l_part, display_buff[7], rcv_buff, UART_CH_0, empty_flag)
        }
        else if (rcv_buff[0] == CMD_N2_WR_LIGHT_VAL)
        {
            CMD_WR_LIGHT_VAL(var_16bit, light_res, rcv_buff, UART_CH_0, empty_flag)
        }
        else
        {
            continue;
        }

        SET_DISPLAY_VALS(i, display_buff, r_part.data, l_part.data, light_res.data);
    }
    
    return 0;
}