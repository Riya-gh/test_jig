/*
 * master_test.c
 *
 *  Created on: May 3, 2026
 *      Author: tiruriya
 */
#include "master_test.h"
#include "main.h"

/* ================= HANDLES ================= */
extern UART_HandleTypeDef huart3;
extern FDCAN_HandleTypeDef hfdcan1;
extern ADC_HandleTypeDef hadc1;

/* ================= RS485 DE PIN ================= */


/* ================= ANALOG CHANNEL LIST ================= */
static uint32_t analog_channels[8] = {
    ADC_CHANNEL_0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7
};

/* ================= DEBUG VARIABLES ================= */
volatile uint8_t dbg_do_state = 0;
volatile uint8_t dbg_di_state = 0;
volatile uint8_t dbg_test_result = 0;
volatile uint32_t dbg_loop_counter = 0;
//volatile uint8_t dbg_uart_tx = 0;
//volatile uint8_t dbg_uart_rx = 0;
extern volatile uint8_t dbg_uart_rx;

/* =========================================================
   ================= DI/DO TEST =============================
   ========================================================= */
void MASTER_Test_DIDO(GPIO_TypeDef *do_port, uint16_t do_pin,
                      GPIO_TypeDef *di_port, uint16_t di_pin)
{
    /* DO LOW */
    HAL_GPIO_WritePin(do_port, do_pin, GPIO_PIN_RESET);
    dbg_do_state = 0;

    HAL_Delay(10);

    dbg_di_state = HAL_GPIO_ReadPin(di_port, di_pin);

    if (dbg_di_state != GPIO_PIN_SET)
    {
        dbg_test_result = 0;
        return;
    }

    /* DO HIGH */
    HAL_GPIO_WritePin(do_port, do_pin, GPIO_PIN_SET);
    dbg_do_state = 1;

    HAL_Delay(10);

    dbg_di_state = HAL_GPIO_ReadPin(di_port, di_pin);

    if (dbg_di_state != GPIO_PIN_RESET)
    {
        dbg_test_result = 0;
        return;
    }

    dbg_test_result = 1;
}

/* =========================================================
   ================= CAN LOOPBACK ===========================
   ========================================================= */
void MASTER_Test_CAN_Loopback(void)
{
    FDCAN_TxHeaderTypeDef txHeader;
    FDCAN_RxHeaderTypeDef rxHeader;
    uint8_t txData[1] = {0x55};
    uint8_t rxData[1];

    txHeader.Identifier = 0x123;
    txHeader.IdType = FDCAN_STANDARD_ID;
    txHeader.TxFrameType = FDCAN_DATA_FRAME;
    txHeader.DataLength = FDCAN_DLC_BYTES_1;

    HAL_FDCAN_Start(&hfdcan1);

    HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &txHeader, txData);

    HAL_Delay(10);

    if (HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &rxHeader, rxData) != HAL_OK)
    {
        dbg_test_result = 0;
        return;
    }

    dbg_test_result = (rxData[0] == 0x55);
}

/* =========================================================
   ================= CAN PHYSICAL ===========================
   ========================================================= */
void MASTER_Test_CAN_Physical(void)
{
    FDCAN_TxHeaderTypeDef txHeader;
    uint8_t txData[1] = {0xA5};

    txHeader.Identifier = 0x321;
    txHeader.IdType = FDCAN_STANDARD_ID;
    txHeader.TxFrameType = FDCAN_DATA_FRAME;
    txHeader.DataLength = FDCAN_DLC_BYTES_1;

    HAL_FDCAN_Start(&hfdcan1);

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &txHeader, txData) != HAL_OK)
    {
        dbg_test_result = 0;
        return;
    }

    dbg_test_result = 1; // verify externally
}

/* =========================================================
   ================= UART TEST ==============================
   ========================================================= */
//void MASTER_Test_UART(void)
//{
//    uint8_t tx = 0x5A;
//    uint8_t rx = 0;
//
//    dbg_uart_tx = tx;
//
//    /* Enable transmitter */
//    HAL_GPIO_WritePin(U6_DE_GPIO_Port, U6_DE_Pin, GPIO_PIN_SET);
//    HAL_Delay(2);
//
//    HAL_UART_Transmit(&huart3, &tx, 1, 100);
//
//    HAL_Delay(2);
//
//    /* Switch to receive */
//    HAL_GPIO_WritePin(U6_DE_GPIO_Port, U6_DE_Pin, GPIO_PIN_RESET);
//    HAL_Delay(5);
//
//    if (HAL_UART_Receive(&huart3, &rx, 1, 100) != HAL_OK)
//    {
//        dbg_test_result = 0;
//        return;
//    }
//
//    dbg_uart_rx = rx;
//    dbg_test_result = (rx == tx);
//
//    HAL_Delay(200);
//}

/* =========================================================
   ================= ANALOG TEST ============================
   ========================================================= */
void MASTER_Test_Analog(void)
{
    ADC_ChannelConfTypeDef sConfig = {0};
    uint16_t value;

    for (uint8_t i = 0; i < 8; i++)
    {
        sConfig.Channel = analog_channels[i];
        sConfig.Rank = ADC_REGULAR_RANK_1;

        HAL_ADC_ConfigChannel(&hadc1, &sConfig);

        HAL_ADC_Start(&hadc1);
        HAL_ADC_PollForConversion(&hadc1, 100);

        value = HAL_ADC_GetValue(&hadc1);
        HAL_ADC_Stop(&hadc1);

        dbg_di_state = value;

        if (value > 4095)
        {
            dbg_test_result = 0;
            return;
        }
    }

    dbg_test_result = 1;
}
