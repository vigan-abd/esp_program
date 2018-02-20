// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file spi.c
//
// Purpose
//    @brief Specifies the spi module 
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: spi.c $
//--

#include "spi.h"

/***************************************************************************//** 
 * @brief Initializes SPI in master mode
 *
 * Initializes SPI in master mode
 *
 * @param[in] uint8_t  bit_order
 * @param[in] uint8_t  clk_presc
 *
 * @retval void 
 ******************************************************************************/
void spi_master_init (uint8_t bit_order, uint8_t clk_presc)
{
    /* Set MOSI and SCK output */
    /* DDRB = (1 << 2) | (1 << 1) */
    DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK);

    /* Enable SPI, Master and set clock rate */
    SPCR = (1 << SPE) | (1 << MSTR) | clk_presc | bit_order;
}


/***************************************************************************//** 
 * @brief Initializes SPI in slave mode
 *
 * Initializes SPI in slave mode
 *
 * @param[in] uint8_t  bit_order
 *
 * @retval void 
 ******************************************************************************/
void spi_slave_init (uint8_t bit_order)
{
    /* Set MISO as output */
    DDR_SPI = (1 << DD_MISO);

    /* Enable SPI */
    SPCR = (1 << SPE) | bit_order;
}

/***************************************************************************//** 
 * @brief Transmits data via SPI
 *
 * Transmits data via SPI
 *
 * @param[in] uint8_t  data
 *
 * @retval void 
 ******************************************************************************/
void spi_master_trm (uint8_t data)
{
    /* Send data to shift register */
    SPDR = data;

    /* Wait for transmission complete */
    while(!(SPSR & (1 << SPIF)))
        ;
}

/***************************************************************************//** 
 * @brief Receives data via SPI
 *
 * Receives data via SPI
 *
 * @param[in] uint8_t*  data
 *
 * @retval void 
 ******************************************************************************/
void spi_slave_rcv (uint8_t *const data)
{
    /* Wait for receive */
    while(!(SPSR & (1 << SPIF)))
        ;

    /* Fetch data from shifr register */
    *data = SPDR;
}