/*
 * test_dio.h
 *
 *  Created on: Apr 24, 2026
 *      Author: tiruriya
 */

#ifndef INC_TEST_DIO_H_
#define INC_TEST_DIO_H_

#include "main.h"

typedef enum {
    DIO_PASS = 0,
    DIO_FAIL
} dio_result_t;

dio_result_t dio_self_test(void);

#endif
