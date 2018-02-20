// Copyright (C) 2017 University of Prishtina - All rights reserved
// Bregu i Diellit, 10000, Prishtina, Kosova. 
// Author: Dr. Smaili Idriz   smaili.idriz@gmail.com
//         BSc. Beqiri Flamur flamurbeqiri1@gmail.com
//         BSc. Abdurrahmani Vigan vigan.abd@gmail.com
//
//++
// Name
//    @file esp_cmd.h
//
// Purpose
//    @brief Specifies the esp command types
//
// Revision Dates
//    2018-01-27 (flamur): Inital create
//    $Log: esp_cmd.h $
//--

#ifndef __ESP_CMD__H
#define __ESP_CMD__H 1
// REQ FORMAT: |aaa|bbb|cc| a -> OP, b -> DL, c -> A
// RES FORMAT: |a|bbb|cc|dd| a -> MASK, b -> DL, c -> AM, d -> AS

/*
 * Defining node 3 commands
 */
/* OP = 1, DL = 0, A = 3 */
#define CMD_N3_RD_TEMP 0b00100011
/* OP = 2, DL = 0, A = 3 */
#define CMD_N3_RD_LIGHT 0b01000011
/* OP = 3, DL = 1, A = 3 */
#define CMD_N3_SET_FAN_SPEED 0b01100111
/* MASK = 1, DL = 3, AM = 0, AS = 3 */
#define CMD_N3_RES 0b10110011
/* MASK = 1, DL = 0, AM = 0, AS = 3 */
#define CMD_N3_ACK 0b10000011

/*
 * Defining node 2 commands
 */
/* OP = 1, DL = 2, A = 2 */
#define CMD_N2_WR_TEMP_VAL 0b00101010
/* OP = 2, DL = 2, A = 2 */
#define CMD_N2_WR_LIGHT_VAL 0b01001010
/* MASK = 1, DL = 0, AM = 0, AS = 2 */
#define CMD_N2_ACK 0b10000010

/*
 * Defining node 1 commands
 */
/* OP = 1, DL = 2, A = 1 */
#define CMD_N1_WR_LIGHT_VAL 0b00101001
/* OP = 2, DL = 1, A = 1 */
#define CMD_N1_SET_LIGHT_INT 0b01000101
/* MASK = 1, DL = 0, AM = 0, AS = 1 */
#define CMD_N1_ACK 0b10000001

/*
 * Defining node 0 commands
 */
/* OP = 1, DL = 1, A = 0 */
#define CMD_N0_WR_FAN 0b00100100
/* OP = 1, DL = 1, A = 0 */
#define CMD_N0_WR_LIGHT 0b01000100
/* MASK = 1, DL = 0, AM = 1, AS = 0 */
#define CMD_N0_ACK 0b10000100

#endif /* __ESP_CMD__H */ 
