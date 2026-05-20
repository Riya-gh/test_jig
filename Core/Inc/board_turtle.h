/*
 * board_turtle.h
 *
 *  Created on: Apr 27, 2026
 *      Author: tiruriya
 */

#ifndef INC_BOARD_TURTLE_H_
#define INC_BOARD_TURTLE_H_

#include "main.h"
#include "test_can.h"

typedef enum {
    TURTLE_PASS = 0,
    TURTLE_FAIL
} turtle_result_t;

// Run all Turtle tests
turtle_result_t turtle_run_all_tests(void);

#endif /* INC_BOARD_TURTLE_H_ */
