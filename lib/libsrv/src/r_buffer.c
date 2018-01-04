// Copyright (C) 2017-2018 University of Prishtina - All rights reserved
// Kodra e Diellit, 10000 Prishtina, Kosovo. 
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
//    2018-01-27 (vigan.abd): Refactoring
//    $Log: r_buffer.h $
//--

#include "r_buffer.h"

/***************************************************************************//** 
 * @brief Initialize the RBUF 
 *
 * Initializes the RBUF 
 * 
 * @retval void 
 ******************************************************************************/
void rbuf_init (volatile r_buffer_t *const r_buf)
{
    int idx = 0;
  
    /* initialize the ring buffer */
    r_buf->n_elm = 0;
    r_buf->pop_idx = 0;
    r_buf->push_idx = 0;
    r_buf->errno = RBUF_NO_ERROR;

    for (idx= 0; idx < RBUF_SIZE; idx++)
    {
        r_buf->buf[idx] = 0x0;
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
void rbuf_push (volatile r_buffer_t *const r_buf, uint8_t data)
{
    r_buf->buf[r_buf->push_idx] = data;
    r_buf->push_idx = (r_buf->push_idx + 1) % RBUF_SIZE;

    if (++r_buf->n_elm > RBUF_SIZE)
    {
        r_buf->errno = RBUF_OVERFLOW;
        r_buf->n_elm = RBUF_SIZE;
        r_buf->pop_idx = (r_buf->pop_idx +1) % RBUF_SIZE;      
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
uint8_t rbuf_pop (volatile r_buffer_t *const r_buf, uint8_t *const data)
{
    uint8_t res = (uint8_t) RBUF_NO_ERROR;
  
    if (!r_buf->n_elm)
    {
        return (uint8_t) RBUF_EMPTY;
    }
  
    *data = r_buf->buf[r_buf->pop_idx];
    r_buf->pop_idx = (r_buf->pop_idx + 1) % RBUF_SIZE;

    if (--r_buf->n_elm <= 0)
    {
        r_buf->n_elm = 0;
    }      

    if (r_buf->errno == RBUF_OVERFLOW)
    {
        res = RBUF_OVERFLOW;
        r_buf->errno = RBUF_NO_ERROR;
    }

    return res;
}
