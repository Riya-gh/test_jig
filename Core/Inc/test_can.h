/*
 * test_can.h
 *
 *  Created on: Apr 27, 2026
 *      Author: tiruriya
 */
#ifndef TEST_CAN_H
#define TEST_CAN_H

#include "main.h"

//#define BOARD_2 // define on the target board
/* Call this once at startup */
void CAN_Test_Init(FDCAN_HandleTypeDef *hfdcan);

/* Board 1 — Send, wait, compare */
void CAN_Test_Board1_Run(void);

/* Board 2 — Echo node, call in main loop */
void CAN_Test_Board2_Run(void);

/* Called from stm32g4xx_it.c or HAL callback */
void CAN_Test_RxCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs);

#endif /* CAN_TEST_H */
