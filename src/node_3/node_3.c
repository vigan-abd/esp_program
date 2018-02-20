// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file node_3.c
//
// Purpose
//    @brief Node 3 main entry
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: node_3.c $
//--
#include "node_3.h"

int main (void)
{
    port_init();
    fan_init();
    adc_init(ADC_PRESCALER_FACT_016);
    tmr2_init_ctc(0xFE, TMR2_PRESCALER_FACT_128);
    uart_init (BAUD0_PRESCALE, UART_CH_0);
    sei();
    
    while(1)
    {
        rcv_buff[0] = 0;
        _delay_ms(1000);
 
        uart_rcv(&rcv_buff[0], UART_CH_0, &empty_flag);
        if (rcv_buff[0] == CMD_N3_RD_TEMP)
        {
            CMD_RD_TEMP(temp.r_part, temp.l_part, snd_buff, UART_CH_0, empty_flag)
        }
        else if (rcv_buff[0] == CMD_N3_RD_LIGHT)
        {
            CMD_RD_LIGHT(raw_light, snd_buff, UART_CH_0, empty_flag)
        }
        else if (rcv_buff[0] == CMD_N3_SET_FAN_SPEED)
        {
            CMD_SET_FAN_SPEED(fan_speed, rcv_buff, UART_CH_0, empty_flag)
        }
        else
        {
            continue;
        }
    }
    return 0;
}