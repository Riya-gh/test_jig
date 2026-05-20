/*
 * test_dio.c
 *
 *  Created on: Apr 24, 2026
 *      Author: tiruriya
 */
#include "test_dio.h"

#define DIO_DELAY 5

static dio_result_t dio_single(GPIO_TypeDef* do_port, uint16_t do_pin,
                               GPIO_TypeDef* di_port, uint16_t di_pin)
{
    // OFF → expect HIGH
    HAL_GPIO_WritePin(do_port, do_pin, GPIO_PIN_RESET);
    HAL_Delay(DIO_DELAY);

    if (HAL_GPIO_ReadPin(di_port, di_pin) != GPIO_PIN_SET)
        return DIO_FAIL;

    // ON → expect LOW
    HAL_GPIO_WritePin(do_port, do_pin, GPIO_PIN_SET);
    HAL_Delay(DIO_DELAY);

    if (HAL_GPIO_ReadPin(di_port, di_pin) != GPIO_PIN_RESET)
        return DIO_FAIL;

    // RESET
    HAL_GPIO_WritePin(do_port, do_pin, GPIO_PIN_RESET);
    HAL_Delay(DIO_DELAY);

    return DIO_PASS;
}

dio_result_t dio_self_test(void)
{
    if (dio_single(DO1_GPIO_Port, DO1_Pin, DI1_GPIO_Port, DI1_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO2_GPIO_Port, DO2_Pin, DI2_GPIO_Port, DI2_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO3_GPIO_Port, DO3_Pin, DI3_GPIO_Port, DI3_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO4_GPIO_Port, DO4_Pin, DI4_GPIO_Port, DI4_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO5_GPIO_Port, DO5_Pin, DI5_GPIO_Port, DI5_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO6_GPIO_Port, DO6_Pin, DI6_GPIO_Port, DI6_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO7_GPIO_Port, DO7_Pin, DI7_GPIO_Port, DI7_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO8_GPIO_Port, DO8_Pin, DI8_GPIO_Port, DI8_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO9_GPIO_Port, DO9_Pin, DI9_GPIO_Port, DI9_Pin) != DIO_PASS) return DIO_FAIL;
    if (dio_single(DO10_GPIO_Port, DO10_Pin, DI10_GPIO_Port, DI10_Pin) != DIO_PASS) return DIO_FAIL;

    return DIO_PASS;
}
