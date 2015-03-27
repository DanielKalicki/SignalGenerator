/***************************************************************************//**
 * @file  cdc.h
 * @brief USB CDC (Communication Device Class) driver.
 * @version 3.20.5
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#ifndef __CDC_H
#define __CDC_H

#ifdef __cplusplus
extern "C" {
#endif
#include "emusb/em_usb.h"
#define CDC_BULK_EP_SIZE  USB_MAX_EP_SIZE  /* This is the max. ep size. */

void CDC_Init( void );
int  CDC_SetupCmd(const USB_Setup_TypeDef *setup);
void CDC_StateChangeEvent( USBD_State_TypeDef oldState,
                           USBD_State_TypeDef newState);
bool usbReadData(uint8_t *buf, int timeout_ms);
bool usbWriteData(uint8_t *data,uint8_t len);
#ifdef __cplusplus
}
#endif

#endif /* __CDC_H */
