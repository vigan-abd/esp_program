// Copyright (C) 2003-2015 swengLab Technologies - All rights reserved
// Siebenbürgerstrasse 16-26/26/17, A--1220 Vienna, Austria. 
// Author: Abdurrahmani Vigan   vigan.abd@gmail.com
//
//++
// Name
//    @file test.h
//
// Purpose
//    @brief Implements the ring buffer test cases
//
// Author
//    @author: Abdurrahmani Vigan, vigan.abd@gmail.com
//    $Author: vigan.abd $
//
// Revision Dates
//    2017-01-02 (vigan.abd): Initial version
//    $Log: test_r_buffer.h $
//--
uint8_t test_r_buffer_empty ()
{
    uint8_t data = 0xFF;
    r_buffer_t buff;
    
    rbuf_init(&buff);
    dump_r_buffer(&buff);

    if(buff.n_elm == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint8_t test_r_buffer_push ()
{
    uint8_t data = 0xFF;
    r_buffer_t buff;
    
    rbuf_init(&buff);
    rbuf_push(&buff, 33);
    dump_r_buffer(&buff);

    if(buff.buf[0] == 33 && buff.n_elm == 1 && buff.push_idx == 1 && buff.errno == RBUF_NO_ERROR)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint8_t test_r_buffer_pop ()
{
    int res, data;
    uint8_t data = 0xFF;
    r_buffer_t buff;
    
    rbuf_init(&buff);
    
    rbuf_push(&buff, 33);
    rbuf_push(&buff, 23);

    res = rbuf_pop(&buff, &data);
    dump_r_buffer(&buff);
    if(res == RBUF_NO_ERROR && data == 23 && buff.pop_idx == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/***************************************************************************//** 
 * @brief Tests pop on empty buffer
 *
 * Tests the pop function on empty ring buffer
 *
 * @param[in] r_buffer_t  buffer
 *
 * @retval 1    if RBUF_EMPTY is returned as result of pop execution
 * @retval 0    if RBUF_EMPTY is not returned as result of pop execution
 ******************************************************************************/
uint8_t test_r_buffer_empty_pop ()
{
    int i;
    uint8_t data = 0xFF;
    r_buffer_t buff;
    
    rbuf_init(&buff);

    uint8_t res = 0;
    res = rbuf_pop(&buff, &data);

    if (res == RBUF_EMPTY)
      {
        return 1;
      }
    else
      {
        return 0; 
      }
}

/***************************************************************************//** 
 * @brief Tests overflow on buffer
 *
 * Tests the overflow on push in ring buffer
 *
 * @param[in] r_buffer_t  buffer
 *
 * @retval 1    if RBUF_OVERFLOW is returned as result of push execution
 * @retval 0    if RBUF_ERBUF_OVERFLOWMPTY is not returned as result of push execution
 ******************************************************************************/
uint8_t test_r_buffer_overflow ()
{
    uint8_t res = RBUF_NO_ERROR, uint8_t data = 0xFF;
    int i = 0;
    r_buffer_t buff;
    
    rbuf_init(&buff);

    while(i <= RBUF_SIZE)
    {
        rbuf_push(&buff, i);
        if (buff.errno == RBUF_OVERFLOW)
        {
            res = RBUF_OVERFLOW;
        }
        i++;
    }
    dump_r_buffer(&buff);

    if (res == RBUF_OVERFLOW)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/***************************************************************************//** 
 * @brief Tests rotate on buffer
 *
 * Tests whenever the rotate occurs on buffer
 *
 * @param[in] r_buffer_t  buffer
 *
 * @retval 1    if first two elements of buf array are 30 and 31
 * @retval 0    otherwise
 ******************************************************************************/
uint8_t test_r_buffer_rotate ()
{
    int i = 0;
    r_buffer_t buff;

    rbuf_init(&buff);
    for(i = 0; i < RBUF_SIZE + 2; i++)
    {
        rbuf_push(&buff, i);
    }
    dump_r_buffer(&buff);

    if (buff.buf[0] == 30 && buff.buf[1] == 31)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/***************************************************************************//** 
 * @brief Prints ring buffer
 *
 * Prints the content of the ring buffer
 *
 * @param[in] r_buffer_t  buffer
 *
 * @retval void
 ******************************************************************************/
void dump_r_buffer (r_buffer_t *const buff)
{
    int i;
    printf("RBUFF\n");
    printf("push_idx >> %d\n", buff->push_idx);
    printf("pop_idx >> %d\n",  buff->pop_idx);
    printf("errno >> %d\n",    buff->errno);
    printf("n_elm >> %d\n",   buff->n_elm);
    printf("elems >> %d",      buff->buf[0]);

    for (int i = 1; i < RBUF_SIZE; i++)
    {
        printf(",%d", buff->buf[i]);
    }
    printf("\n");
}