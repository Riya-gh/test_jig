/*
 * board_octopus.h
 *
 *  Created on: Apr 27, 2026
 *      Author: tiruriya
 */

#ifndef INC_BOARD_OCTOPUS_H_
#define INC_BOARD_OCTOPUS_H_

#include "main.h"
#include "test_can.h"
#include "test_uart.h"
#include "test_dio.h"

typedef enum {
    OCTOPUS_PASS = 0,
    OCTOPUS_FAIL
} octopus_result_t;

octopus_result_t octopus_run_all_tests(void);


#endif /* INC_BOARD_OCTOPUS_H_ */
