/*
 * test_analog.h
 *
 *  Created on: Apr 27, 2026
 *      Author: tiruriya
 */

#ifndef INC_TEST_ANALOG_H_
#define INC_TEST_ANALOG_H_

#include "main.h"

typedef enum {
    ADC_PASS = 0,
    ADC_FAIL
} adc_result_t;

typedef struct {
    uint8_t channel_id;   // logical channel (AIN1, AIN2 etc.)
} adc_channel_t;

// Test one channel for all voltages
adc_result_t adc_test_channel(const adc_channel_t *ch);

#endif /* INC_TEST_ANALOG_H_ */
