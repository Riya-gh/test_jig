/*
 * test_analog.c
 *
 *  Created on: Apr 27, 2026
 *      Author: tiruriya
 */

#include "test_analog.h"
#include <math.h>

#define ADC_MAX         4095.0f
#define VREF            3.3f
#define ADC_TOL_PERCENT 10.0f   // ±10%

//--------------------------------------------------
// 🔴 STUB: Voltage Selection (Replace Later)
//--------------------------------------------------
static void select_voltage(float voltage)
{
    // TODO: Replace with GPIO / MUX / Relay control

    if (voltage == 3.3f)
    {
        // select 3.3V
    }
    else if (voltage == 5.0f)
    {
        // select 5V
    }
    else if (voltage == 12.0f)
    {
        // select 12V
    }
}

//--------------------------------------------------
// 🔴 STUB: Read ADC from DUT (Replace Later)
//--------------------------------------------------
static uint16_t read_adc_from_dut(uint8_t channel)
{
    // TODO:
    // Send command via UART/CAN and receive ADC value

    // TEMP: return dummy value for development
    return 2000;
}

//--------------------------------------------------
// Convert Voltage → Expected ADC
//--------------------------------------------------
static float voltage_to_adc(float measured_voltage)
{
    return (measured_voltage / VREF) * ADC_MAX;
}

//--------------------------------------------------
// Check within tolerance
//--------------------------------------------------
static int is_within_range(float measured, float expected)
{
    float tol = (ADC_TOL_PERCENT / 100.0f) * expected;

    if (measured >= (expected - tol) && measured <= (expected + tol))
        return 1;

    return 0;
}

//--------------------------------------------------
// Test ONE voltage level
//--------------------------------------------------
static adc_result_t test_one_level(uint8_t channel, float voltage)
{
    select_voltage(voltage);

    HAL_Delay(10); // settle time

    uint16_t adc_val = read_adc_from_dut(channel);

    // 🔴 IMPORTANT:
    // Here we assume DUT already scaled voltage to 0–3.3V
    float scaled_voltage;

    if (voltage == 12.0f)
        scaled_voltage = 3.0f;   // example divider assumption
    else if (voltage == 5.0f)
        scaled_voltage = 2.5f;
    else
        scaled_voltage = 3.3f;

    float expected_adc = voltage_to_adc(scaled_voltage);

    if (!is_within_range((float)adc_val, expected_adc))
        return ADC_FAIL;

    return ADC_PASS;
}

//--------------------------------------------------
// MAIN ADC TEST (3.3V + 5V + 12V)
//--------------------------------------------------
adc_result_t adc_test_channel(const adc_channel_t *ch)
{
    //--------------------------------------------------
    // 3.3V
    //--------------------------------------------------
    if (test_one_level(ch->channel_id, 3.3f) != ADC_PASS)
        return ADC_FAIL;

    //--------------------------------------------------
    // 5V
    //--------------------------------------------------
    if (test_one_level(ch->channel_id, 5.0f) != ADC_PASS)
        return ADC_FAIL;

    //--------------------------------------------------
    // 12V
    //--------------------------------------------------
    if (test_one_level(ch->channel_id, 12.0f) != ADC_PASS)
        return ADC_FAIL;

    //--------------------------------------------------
    // ALL PASSED
    //--------------------------------------------------
    return ADC_PASS;
}
