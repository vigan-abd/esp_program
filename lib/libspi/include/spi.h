// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file spi.h
//
// Purpose
//    @brief Specifies the spi module 
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: spi.h $
//--

#ifndef __SPI__H
#define __SPI__H 1

#include <avr/io.h>
#include <avr/interrupt.h>
#include "esp_types.h"

/*
 * SPI Pins
 */
#define DD_MISO DDB3
#define DD_MOSI DDB2
#define DD_SCK DDB1
#define DDR_SPI DDRB

/*
 * Declaration of SPI's constants
 */
#define SPI_LSB_FIRST (1 << DORD)
#define SPI_MSB_FIRST 0
#define SPI_CLK_PRESC_4 0
#define SPI_CLK_PRESC_16 (1 << SPR0)
#define SPI_CLK_PRESC_64 (1 << SPR1)
#define SPI_CLK_PRESC_128 (1 << SPR0) | (1 << SPR1)

/*
 * Declarations of SPI's members
 */
void spi_master_init (uint8_t bit_order, uint8_t clk_presc);
void spi_slave_init (uint8_t bit_order);
void spi_master_trm (uint8_t data);
void spi_slave_rcv (uint8_t *const data);

#endif /* __SPI__H */ 
