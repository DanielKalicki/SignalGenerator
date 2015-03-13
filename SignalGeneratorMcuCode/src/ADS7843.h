/*
 * ADS7843.h
 *
 *  Created on: 11-03-2015
 *      Author: lukasz
 */

#ifndef ADS7843_H_
#define ADS7843_H_


#include <stdbool.h>
#include "em_device.h"
#include "em_bitband.h"
#include "em_gpio.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************Hardware dependent part*****************************************/
/*********************************Hardware dependent part*****************************************/

//==================CS=====================
#define ADS7843_PIN_CS      0
#define ADS7843_PORT_CS     gpioPortE
#define ADS7843_CS_OUTPUT() GPIO_PinModeSet(ADS7843_PORT_CS, ADS7843_PIN_CS, gpioModePushPull, 1);
#define ADS7843_CS_HIGH()   GPIO_PinOutSet(ADS7843_PORT_CS , ADS7843_PIN_CS );
#define ADS7843_CS_LOW()    GPIO_PinOutClear(ADS7843_PORT_CS , ADS7843_PIN_CS );
//------------------INT_IRQ----------------------

#define ADS7843_PIN_INT      14
#define ADS7843_PORT_INT     gpioPortA
#define ADS7843_INT_OUTPUT() GPIO_PinModeSet(ADS7843_PORT_INT, ADS7843_PIN_INT, gpioModePushPull, 1);
#define ADS7843_INT_INPUT() GPIO_PinModeSet(ADS7843_PORT_INT, ADS7843_PIN_INT, gpioModeInput, 0);
#define ADS7843_INT_IRQ_CONFIG_FALLING(enable) GPIO_IntConfig(ADS7843_PORT_INT, ADS7843_PIN_INT, false, true, enable);
#define ADS7843_INT_IRQ_CONFIG_RISING(enable) GPIO_IntConfig(ADS7843_PORT_INT, ADS7843_PIN_INT, true, false, enable);
#define ADS7843_INT_IRQ_CONFIG_PIN_DISABLE() GPIO_IntConfig(ADS7843_PORT_INT, ADS7843_PIN_INT, false, false, false);
#define ADS7843_INT_HIGH()   GPIO_PinOutSet(ADS7843_PORT_INT , ADS7843_PIN_INT );
#define ADS7843_INT_LOW()    GPIO_PinOutClear(ADS7843_PORT_INT , ADS7843_PIN_INT );
#define ADS7843_GET_INT_PIN() GPIO_PinInGet(ADS7843_PORT_INT, ADS7843_PORT_INT)

//------------------CLK----------------------

#define ADS7843_PIN_CLK      1
#define ADS7843_PORT_CLK     gpioPortE
#define ADS7843_CLK_OUTPUT() GPIO_PinModeSet(ADS7843_PORT_CLK, ADS7843_PIN_CLK, gpioModePushPull, 1);
#define ADS7843_CLK_HIGH()   GPIO_PinOutSet(ADS7843_PORT_CLK , ADS7843_PIN_CLK );
#define ADS7843_CLK_LOW()    GPIO_PinOutClear(ADS7843_PORT_CLK , ADS7843_PIN_CLK );

//------------------MOSI---------------------

#define ADS7843_PIN_MOSI      2
#define ADS7843_PORT_MOSI     gpioPortE
#define ADS7843_MOSI_OUTPUT() GPIO_PinModeSet(ADS7843_PORT_MOSI, ADS7843_PIN_MOSI, gpioModePushPull, 1);
#define ADS7843_MOSI_HIGH()   GPIO_PinOutSet(ADS7843_PORT_MOSI, ADS7843_PIN_MOSI );
#define ADS7843_MOSI_LOW()    GPIO_PinOutClear(ADS7843_PORT_MOSI , ADS7843_PIN_MOSI );

//------------------MIS0---------------------

#define ADS7843_PIN_MISO      3
#define ADS7843_PORT_MISO     gpioPortE
#define ADS7843_MISO_OUTPUT() GPIO_PinModeSet(ADS7843_PORT_MISO, ADS7843_PIN_MISO, gpioModePushPull, 1);
#define ADS7843_MISO_HIGH()   GPIO_PinOutSet(ADS7843_PORT_MISO , ADS7843_PIN_MISO );
#define ADS7843_MISO_LOW()    GPIO_PinOutClear(ADS7843_PORT_MISO , ADS7843_PIN_MISO );

/*********************************Hardware dependent part - END*****************************************/

#ifdef ADS7843_USE_PIN_BUSY
#define ADS7843_PIN_BUSY           PB11
#endif

//
// Enable touch interrupt
//
//#define ADS7843_ENABLE_TOUCH_INT

#define TOUCH_SCREEN_WIDTH         240
#define TOUCH_SCREEN_HEIGHT        320

#define TOUCH_SMAPLE_LEN           8
//#define TOUCH_DISCARD_SAMPLES      1

#define TOUCH_AD_X_MAX             1840
#define TOUCH_AD_X_MIN             200
#define TOUCH_AD_Y_MAX             1830
#define TOUCH_AD_Y_MIN             200//125
//#define TOUCH_AD_Y_MIN_SCREEN      200
#define TOUCH_AD_CALIB_ERROR       80


//*****************************************************************************
//
//! \addtogroup ADS7843_Config ADS7843 Driver Predefines
//! \brief This part defines the slave address and register address of ADS7843.
//! @{
//
//*****************************************************************************
#define ADS7843_READ_X             0xD0
#define ADS7843_READ_Y             0x90
#define ADS7843_READ_IN3           0xA0
#define ADS7843_READ_IN4           0xE0
#define ADS7843_NO_POWERDOWN       0x03

#define TOUCH_STATUS_PENDOWN       0x01
#define TOUCH_STATUS_PENUP         0x02


typedef struct
{
	uint16_t x;
	uint16_t y;
}TouchPoint;

typedef struct
{
	uint16_t th_ad_left;
	uint16_t th_ad_right;
	uint16_t th_ad_up;
	uint16_t th_ad_down;
	uint16_t last_x;
	uint16_t last_y;
	uint16_t cur_x;
	uint16_t cur_y;
	uint8_t touch_status;
}TouchInfo;

extern TouchInfo tTouchData;


extern void ADS7843Init(void);

//
//! Read raw value of x,y axis's AD conversion value.
//
extern void ADS7843ReadADXYRaw(uint16_t *x, uint16_t *y);

//
//! Read x,y axis's AD conversion value with software filter.
//
extern void ADS7843ReadADXY(uint16_t *x, uint16_t *y);

//
//! Read x,y coordinate.
//
uint8_t ADS7843ReadPointXY(uint16_t *x, uint16_t *y);

//
//! Get pen status (pen down or pen up).
//
extern uint16_t ADS7843PenInq(void);

//
//! Touch screen calibration.
//
extern uint8_t ADS7843Calibration(void);

//
//! Read single channel of conversion(x,y,IN3,IN4).
//
uint16_t ADS7843ReadInputChannel( uint8_t ucChannel);

TouchPoint getCoordinates(void);

#ifdef __cplusplus
}
#endif





#endif /* ADS7843_H_ */