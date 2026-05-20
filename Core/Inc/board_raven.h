/*
 * board_raven.h
 *
 *  Created on: Apr 24, 2026
 *      Author: tiruriya
 */

#ifndef INC_BOARD_RAVEN_H_
#define INC_BOARD_RAVEN_H_


#include "main.h"
#include "test_can.h"

typedef enum {
    RAVEN_PASS = 0,
    RAVEN_FAIL
} raven_result_t;

raven_result_t raven_run_all_tests(void);


#endif /* INC_BOARD_RAVEN_H_ */
