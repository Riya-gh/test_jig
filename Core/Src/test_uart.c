/*
 * test_uart.c
 *
 *  Created on: Apr 27, 2026
 *      Author: tiruriya
 */
/*
 * test_uart.c
 */
#include "test_uart.h"

/* ── Variables ── */
volatile uint32_t tx_count   = 0;
volatile uint32_t rx_count   = 0;
volatile uint8_t  dbg_uart_rx = 0;

static uint8_t tx_buf[] = "Hello\r\n";
       uint8_t rx_buf[20] = {0};

void UART_Test_Run(UART_HandleTypeDef *huart)
{
#ifdef RS485_TARGET

    /*─────────────────────────────
      TARGET — Receive then Echo
     ─────────────────────────────*/
    memset(rx_buf, 0, sizeof(rx_buf));

    HAL_StatusTypeDef status = HAL_UART_Receive(
                                    huart,
                                    rx_buf,
                                    strlen((char*)tx_buf),
                                    2000);

    if (status == HAL_OK) {
        dbg_uart_rx = rx_buf[0];  // 🔴 BP1 — check received byte
        rx_count++;

        HAL_Delay(5);             // small gap before TX

        HAL_UART_Transmit(
            huart,
            rx_buf,
            strlen((char*)rx_buf),
            1000);
        tx_count++;               // 🔴 BP2 — echo sent
    }

#else

    /*─────────────────────────────
      MASTER — Send then Receive
     ─────────────────────────────*/
    memset(rx_buf, 0, sizeof(rx_buf));
    uint8_t len = strlen((char*)tx_buf);

    /* TX */
    HAL_UART_Transmit(huart, tx_buf, len, 1000);
    tx_count++;

    /* RX */
    HAL_StatusTypeDef status = HAL_UART_Receive(
                                    huart,
                                    rx_buf,
                                    len,
                                    2000);

    if (status == HAL_OK) {
        rx_count++;
        dbg_uart_rx = rx_buf[0];

        if (memcmp(tx_buf, rx_buf, len) == 0)
            rx_buf[len] = 'P';   // 🔴 BP3 — PASS ✅
        else
            rx_buf[len] = 'F';   // 🔴 BP4 — FAIL ❌
    } else {
        rx_buf[0] = 'T';         // 🔴 BP5 — TIMEOUT ⚠️
    }

#endif
}
