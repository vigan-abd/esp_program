// Copyright (C) 2003-2015 swengLab Technologies - All rights reserved
// Siebenbürgerstrasse 16-26/26/17, A--1220 Vienna, Austria. 
// Author: Dr. SMAILI Idriz   smaili.idriz@gmail.com
//
//++
// Name
//    @file uart.c
//
// Purpose
//    @brief Implements the routine needed to handle the ADC  
//
// Author
//    @author: Dr. Dipl.-Ing. Idriz SMAILI, smaili.idriz@gmail.com
//    $Author: smaili $
//
// Revision Dates
//    2017-12-28 (smaili): Initial version
//    $Log: uart.c $
//--

#include "uart.h"

static volatile r_buffer_t r_bufs [UART_NO_CHANNELS];

/***************************************************************************//** 
 * @brief Initialize the uart
 *
 * Initializes the uart by providing the prescaler div factor. Async Mode is used.
 *
 * @param[in] uint16_t  specifies the baud rate
 *
 * @retval void 
 ******************************************************************************/
void uart_init (uint16_t ubrr0, uint16_t ubrr1)
{
  UART_INIT_CHANNEL (ubrr0, 0);
  
#if defined (UART_USE_CH1)
  UART_INIT_CHANNEL (ubrr1, 1);
#endif
  
  /* Enable the Global Interrupt Enable flag so that interrupts
   * can be processedinclude
   */
  sei(); 
}
/***************************************************************************//** 
 * @brief Returns the uart ring buffer
 *
 * Returns the uart ring buffer for the specified channel.
 *
 * @retval void 
 ******************************************************************************/
volatile
r_buffer_t *const uart_get_rbuf (uint8_t channel)
{
  if (channel <0 || channel >= UART_NO_CHANNELS)
    {
      return (r_buffer_t *const) 0;
    }
  
  return &r_bufs [channel];
}
/***************************************************************************//** 
 * @brief Sends the data
 *
 * Sends the data via serial port communication.
 *
 * @param[in] uint8_t  data to be send
 *
 * @retval RBUF_NO_ERROR
 * @retval UART_INVALID_CHANNEL
 ******************************************************************************/
uint8_t uart_send (uint8_t channel, uint8_t data)
{
  if (channel <0 || channel >= UART_NO_CHANNELS)
    {
      return (uint8_t) UART_INVALID_CHANNEL;
    }

  if (channel == UART_CHANNEL_0)
    {
      UART_SEND(0, data);
    }
#if defined (UART_USE_CH1)
  else
    {
      UART_SEND(1, data);
    }
#endif

  return (uint8_t) RBUF_NO_ERROR;
}

/***************************************************************************//** 
 * @brief Reads data from SP
 *
 * Reads the data from Serial Port. The communication works in blocking receive mode.
 *
 * @retval uint8_t 
 ******************************************************************************/
uint8_t
uart_receive  (uint8_t  chan, uint8_t *buf, uint8_t b_len,
                uint8_t *const rx_len)
{
  register uint8_t idx =0;
  register uint8_t res =RBUF_NO_ERROR;

  *rx_len              = 0;
  
  volatile r_buffer_t *const r_buf = uart_get_rbuf (chan);
  if (r_buf == 0)
    {
      return (uint8_t) UART_INVALID_CHANNEL;
    }

  if (!r_buf->n_elm)
    {
      return (uint8_t) RBUF_EMPTY;
    }

  for (idx= 0; idx < b_len; idx++)
    {
      res = rbuf_pop (r_buf, &buf [idx]);

      if (res == RBUF_EMPTY)
        {
          res = RBUF_NO_ERROR;
          *rx_len = idx;
          break;
        }
    }

  return res;
}

void ISR(USART0_RX_vect)
{
  /* disable interrupts */
  UART_DISABLE_INT(0);

  /* read the data (a byte) and push it into the ring-buffer */
  rbuf_push (uart_get_rbuf (UART_CHANNEL_0), (uint8_t) UDR0);

  /* enable interrupts */
  UART_ENABLE_INT(0);
}

#if defined (UART_USE_CH1)
void ISR(USART1_RX_vect)
{
  /* disable interrupts */
  UART_DISABLE_INT("1");

  /* read the data (a byte) and push it into the ring-buffer */
  /* read the data (a byte) and push it into the ring-buffer */
  rbuf_push (uart_get_rbuf (UART_CHANNEL_1), (uint8_t) UDR1);

  /* enable interrupts */
  UART_ENABLE_INT("1");
}
#endif
