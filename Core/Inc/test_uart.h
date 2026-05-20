/*
 * test_uart.h
 *
 *  Created on: Apr 27, 2026
 *      Author: tiruriya
 */
/*
 * test_uart.h
 */
#ifndef TEST_UART_H
#define TEST_UART_H

#include "main.h"
#include <string.h>

/* Uncomment on TARGET board only */
// #define RS485_TARGET

void UART_Test_Run(UART_HandleTypeDef *huart);

extern volatile uint32_t tx_count;
extern volatile uint32_t rx_count;
extern volatile uint8_t  dbg_uart_rx;
extern uint8_t rx_buf[20];

#endif
