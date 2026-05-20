/*
 * test_can.c
 *
 *  Created on: Apr 24, 2026
 *      Author: tiruriya
 */

#include "test_can.h"
#include "string.h"
#include "stdio.h"

//#define BOARD_2 // define on the target board

/* ─── Private variables ─── */
static FDCAN_HandleTypeDef  *_hfdcan;
static FDCAN_TxHeaderTypeDef txHeader;
static FDCAN_RxHeaderTypeDef rxHeader;

static uint8_t txData[8] = {0x01,0x22,0x33,0x44,
                             0x55,0x66,0x77,0x88};
static uint8_t rxData[8] = {0};
static volatile uint8_t msgReceived = 0;

/* ─────────────────────────────────────────
   Init — call once after MX_FDCAN1_Init()
   ───────────────────────────────────────── */
void CAN_Test_Init(FDCAN_HandleTypeDef *hfdcan) {
    _hfdcan = hfdcan;

    /* Filter: accept ID 0x123 only */
    FDCAN_FilterTypeDef filter;
    filter.IdType       = FDCAN_STANDARD_ID;
    filter.FilterIndex  = 0;
    filter.FilterType   = FDCAN_FILTER_MASK;
    filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    filter.FilterID1    = 0x123;
    filter.FilterID2    = 0x7FF;
    HAL_FDCAN_ConfigFilter(_hfdcan, &filter);

    HAL_FDCAN_ConfigGlobalFilter(_hfdcan,
        FDCAN_REJECT, FDCAN_REJECT,
        FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE);

    /* TX Header */
    txHeader.Identifier          = 0x123;
    txHeader.IdType              = FDCAN_STANDARD_ID;
    txHeader.TxFrameType         = FDCAN_DATA_FRAME;
    txHeader.DataLength          = FDCAN_DLC_BYTES_8;
    txHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    txHeader.BitRateSwitch       = FDCAN_BRS_OFF;
    txHeader.FDFormat            = FDCAN_CLASSIC_CAN;
    txHeader.TxEventFifoControl  = FDCAN_NO_TX_EVENTS;
    txHeader.MessageMarker       = 0;

    HAL_FDCAN_Start(_hfdcan);
    HAL_FDCAN_ActivateNotification(_hfdcan,
        FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);

    printf("[CAN] Initialized OK\r\n");
}

/* ─────────────────────────────────────────
   Board 1 — Send + Wait + Compare
   ───────────────────────────────────────── */
void CAN_Test_Board1_Run(void) {
    msgReceived = 0;
    memset(rxData, 0, 8);

//    printf("\r\n[CAN] Sending frame ID=0x123...\r\n");
//    printf("[CAN] TX: ");
//    for (int i = 0; i < 8; i++) printf("0x%02X ", txData[i]);
//    printf("\r\n");

    if (HAL_FDCAN_AddMessageToTxFifoQ(_hfdcan,
            &txHeader, txData) != HAL_OK) {
        printf("[CAN] TX ERROR!\r\n");
        return;
    }
    printf("TX REQUEST ADDED\r\n");

       FDCAN_ProtocolStatusTypeDef ps;

       HAL_FDCAN_GetProtocolStatus(_hfdcan, &ps);

       printf("LEC = %lu\r\n", ps.LastErrorCode);
    /* Wait for echo — 500ms timeout */
    uint32_t t = HAL_GetTick();
    while (!msgReceived) {
        if ((HAL_GetTick() - t) > 5000) {
            printf("[CAN] TIMEOUT — No response!\r\n");
            return;
        }
    }

    printf("[CAN] RX: ");
    for (int i = 0; i < 8; i++) printf("0x%02X ", rxData[i]);
    printf("\r\n");


//void CAN_Test_Board1_Run(void) {
//
//    if (HAL_FDCAN_AddMessageToTxFifoQ(_hfdcan,
//            &txHeader, txData) != HAL_OK) {
//        printf("[CAN] TX ERROR!\r\n");
//        return;
//    }
//
//    printf("[CAN] TX: 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n",
//            txData[0], txData[1], txData[2], txData[3],
//            txData[4], txData[5], txData[6], txData[7]);
//
//    FDCAN_ProtocolStatusTypeDef ps;
//    HAL_FDCAN_GetProtocolStatus(_hfdcan, &ps);
//    printf("[CAN] LEC = %lu\r\n", ps.LastErrorCode);
//}
    /* Compare */
    if (memcmp(txData, rxData, 8) == 0)
        printf("[CAN] >>> RESULT: PASS ✓ <<<\r\n");
    else
        printf("[CAN] >>> RESULT: FAIL ✗ <<<\r\n");
}

/* ─────────────────────────────────────────
   Board 2 — Echo node (call in main loop)
   ───────────────────────────────────────── */
void CAN_Test_Board2_Run(void) {
    if (msgReceived) {
        printf("[CAN] Echoed: ");
        for (int i = 0; i < 8; i++) printf("0x%02X ", rxData[i]);
        printf("\r\n");
        msgReceived = 0;
    }
}

/* ─────────────────────────────────────────
   RX Callback — hook this into HAL callback
   ───────────────────────────────────────── */
void CAN_Test_RxCallback(FDCAN_HandleTypeDef *hfdcan,
                         uint32_t RxFifo0ITs) {
    if (RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) {
        HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0,
                               &rxHeader, rxData);

#ifdef BOARD_2
        FDCAN_TxHeaderTypeDef echoHeader;

        echoHeader.Identifier          = rxHeader.Identifier;
        echoHeader.IdType              = rxHeader.IdType;
        echoHeader.TxFrameType         = FDCAN_DATA_FRAME;
        echoHeader.DataLength          = rxHeader.DataLength;
        echoHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
        echoHeader.BitRateSwitch       = FDCAN_BRS_OFF;
        echoHeader.FDFormat            = FDCAN_CLASSIC_CAN;
        echoHeader.TxEventFifoControl  = FDCAN_NO_TX_EVENTS;
        echoHeader.MessageMarker       = 0;

        HAL_FDCAN_AddMessageToTxFifoQ(hfdcan,
                                      &echoHeader,
                                      rxData);
#endif
        msgReceived = 1;
    }
}

/* HAL weak callback override */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan,
                                uint32_t RxFifo0ITs) {
    CAN_Test_RxCallback(hfdcan, RxFifo0ITs);
}
