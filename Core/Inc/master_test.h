/*
 * master_test.h
 *
 *  Created on: May 3, 2026
 *      Author: tiruriya
 */


#ifndef MASTER_TEST_H
#define MASTER_TEST_H


#include "stm32g0xx_hal.h"
#include <stdint.h>

/* ================= DI/DO ================= */
void MASTER_Test_DIDO(GPIO_TypeDef *do_port, uint16_t do_pin,
                      GPIO_TypeDef *di_port, uint16_t di_pin);

/* ================= CAN ================= */
void MASTER_Test_CAN_Loopback(void);
void MASTER_Test_CAN_Physical(void);

/* ================= UART ================= */
void MASTER_Test_UART(void);

/* ================= ANALOG ================= */
void MASTER_Test_Analog(void);

/* ================= DEBUG VARIABLES ================= */
extern volatile uint8_t dbg_uart_tx;
extern volatile uint8_t dbg_uart_rx;

extern volatile uint8_t dbg_do_state;
extern volatile uint8_t dbg_di_state;
extern volatile uint8_t dbg_test_result;
extern volatile uint32_t dbg_loop_counter;



#endif /* INC_MASTER_TEST_H_ */
