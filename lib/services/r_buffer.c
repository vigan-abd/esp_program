// Copyright (C) 2003-2015 swengLab Technologies - All rights reserved
// Siebenbürgerstrasse 16-26/26/17, A--1220 Vienna, Austria. 
// Author: Dr. SMAILI Idriz   smaili.idriz@gmail.com
//
//++
// Name
//    @file r_buffer.h
//
// Purpose
//    @brief Implements the ring buffer data structure
//
// Author
//    @author: Dr. Dipl.-Ing. Idriz SMAILI, smaili.idriz@gmail.com
//    $Author: smaili $
//
// Revision Dates
//    2017-01-02 (smaili): Initial version
//    $Log: r_buffer.h $
//--

#include "r_buffer.h"

static uint8_t    errno;
static r_buffer_t r_buf;

/***************************************************************************//** 
 * @brief Initialize the RBUF 
 *
 * Initializes the RBUF 
 * 
 * @retval void 
 ******************************************************************************/
void rbuf_init ()
{
  int idx= 0;

  /* initialize the errno */
  errno = RBUF_NO_ERROR;
  
  /* initialize the ring buffer */
  r_buf.n_elm     = 0;
  r_buf.pop_idx   = 0;
  r_buf.push_idx  = 0;

  for (idx= 0; idx < RBUF_SIZE; idx++)
    {
      r_buf.buf [idx] = 0x0;
    }
}

/***************************************************************************//** 
 * @brief Push an element into the ring buffer
 *
 * Push an element into the ring buffer
 *
 * @param[in] uint8_t  data element to be pushed into the ring
 *
 * @retval void  
 ******************************************************************************/
void rbuf_push (uint8_t data)
{
  r_buf.buf [r_buf.push_idx] = data;
  r_buf.push_idx             = (r_buf.push_idx +1) % RBUF_SIZE;

  if (++r_buf.n_elm > RBUF_SIZE)
    {
      errno         = RBUF_OVERFLOW;
      r_buf.n_elm   = RBUF_SIZE;
      r_buf.pop_idx = (r_buf.pop_idx +1) % RBUF_SIZE;      
    }
}


/***************************************************************************//** 
 * @brief Pop an element from the ring buffer
 *
 * Pop an element from the ring buffer
 *
 * @param[in] uint8_t  data element to be pushed into the ring
 *
 * @retval RBUF_NO_ERROR    if no error was detected
 * @retval RBUF_EMPTY       if no data has been received yet
 * @retval RBUF_OVERFLOW    if an buffer overflow has been detected during 
 *                          last push operation(s)  
 ******************************************************************************/
uint8_t rbuf_pop (uint8_t *const data)
{
  uint8_t res = (uint8_t) RBUF_NO_ERROR;
  
  if (!r_buf.n_elm)
    {
      res = (uint8_t) RBUF_EMPTY;
    }
  else
    {
      *data            = r_buf.buf [r_buf.pop_idx];
      r_buf.pop_idx    = (r_buf.pop_idx +1) % RBUF_SIZE;

      if (--r_buf.n_elm <= 0)
        {
          r_buf.n_elm = 0;
        }      
    }  

  return res;
}
