/*
 * SPFD5408.h
 * Library for a TFT display , based on SPFD5408 driver
 * library based on ST7781R TFT 8 bit Library written by Seeed Technology Inc.
 *
 *  Created on: 01-02-2015
 *      Author: lukasz
 */

#ifndef _SPFD5408_H
#define _SPFD5408_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "em_device.h"
#include "em_bitband.h"
#include "em_gpio.h"
#include "em_cmu.h"


#define _8_BIT_MODEx
#define _16_BIT_MODE     //default
#ifdef _8_BIT_MODE
	#undef _16_BIT_MODE
#endif


//Basic Colors
#define RED         0xf800
#define GREEN		0x07e0
#define BLUE		0x001f
#define BLACK		0x0000
#define YELLOW		0xffe0
#define WHITE		0xffff

//Other Colors
#define CYAN		0x07ff
#define BRIGHT_RED	0xf810
#define GRAY1		0x8410
#define GRAY2		0x4208

//TFT resolution 240*320
#define MIN_X	    0
#define MIN_Y	    0
#define MAX_X	    240
#define MAX_Y	    320

/*********************************Hardware dependent part*****************************************/
/*********************************Hardware dependent part*****************************************/

#define CLOCKS_ENABLE() {CMU_ClockEnable(cmuClock_GPIO, true);}  //add more if needed
//==================/CS=====================
#define CS_PIN      9
#define CS_PORT     gpioPortB
#define CS_OUTPUT() GPIO_PinModeSet(CS_PORT, CS_PIN, gpioModePushPull, 1);
#define CS_HIGH_()   GPIO_PinOutSet(CS_PORT , CS_PIN );
#define CS_LOW_()    GPIO_PinOutClear(CS_PORT , CS_PIN );
//------------------RS----------------------

#define RS_PIN      10
#define RS_PORT     gpioPortB
#define RS_OUTPUT() GPIO_PinModeSet(RS_PORT, RS_PIN, gpioModePushPull, 1);
#define RS_HIGH()   GPIO_PinOutSet(RS_PORT , RS_PIN );
#define RS_LOW()    GPIO_PinOutClear(RS_PORT , RS_PIN );

//------------------WR----------------------

#define WR_PIN      11
#define WR_PORT     gpioPortB
#define WR_OUTPUT() GPIO_PinModeSet(WR_PORT, WR_PIN, gpioModePushPull, 1);
#define WR_HIGH()   GPIO_PinOutSet(WR_PORT , WR_PIN );
#define WR_LOW()    GPIO_PinOutClear(WR_PORT , WR_PIN );
#define WR_RISING() {WR_HIGH(); WR_LOW(); }
//------------------RD---------------------

#define RD_PIN      12
#define RD_PORT     gpioPortB
#define RD_OUTPUT() GPIO_PinModeSet(RD_PORT, RD_PIN, gpioModePushPull, 1);
#define RD_HIGH()   GPIO_PinOutSet(RD_PORT , RD_PIN );
#define RD_LOW()    GPIO_PinOutClear(RD_PORT , RD_PIN );
#define RD_RISING() {RD_HIGH(); RD_LOW(); }

//------------------DATA-------------------
#define TFT_PORT_D15 gpioPortD
#define TFT_PIN_D15 15
#define TFT_PIN_D15_OUTPUT() GPIO_PinModeSet(TFT_PORT_D15,TFT_PIN_D15, gpioModePushPull, 1);
#define TFT_PIN_D15_INPUT()  GPIO_PinModeSet(TFT_PORT_D15,TFT_PIN_D15, gpioModeInput, 0);

#define TFT_PORT_D14 gpioPortD
#define TFT_PIN_D14 14
#define TFT_PIN_D14_OUTPUT() GPIO_PinModeSet(TFT_PORT_D14,TFT_PIN_D14, gpioModePushPull, 1);
#define TFT_PIN_D14_INPUT()  GPIO_PinModeSet(TFT_PORT_D14,TFT_PIN_D14, gpioModeInput, 0);

#define TFT_PORT_D13 gpioPortD
#define TFT_PIN_D13 13
#define TFT_PIN_D13_OUTPUT() GPIO_PinModeSet(TFT_PORT_D13,TFT_PIN_D13, gpioModePushPull, 1);
#define TFT_PIN_D13_INPUT()  GPIO_PinModeSet(TFT_PORT_D13,TFT_PIN_D13, gpioModeInput, 0);

#define TFT_PORT_D12 gpioPortD
#define TFT_PIN_D12 12
#define TFT_PIN_D12_OUTPUT() GPIO_PinModeSet(TFT_PORT_D12,TFT_PIN_D12, gpioModePushPull, 1);
#define TFT_PIN_D12_INPUT()  GPIO_PinModeSet(TFT_PORT_D12,TFT_PIN_D12, gpioModeInput, 0);

#define TFT_PORT_D11 gpioPortD
#define TFT_PIN_D11 11
#define TFT_PIN_D11_OUTPUT() GPIO_PinModeSet(TFT_PORT_D11,TFT_PIN_D11, gpioModePushPull, 1);
#define TFT_PIN_D11_INPUT()  GPIO_PinModeSet(TFT_PORT_D11,TFT_PIN_D11, gpioModeInput, 0);

#define TFT_PORT_D10 gpioPortD
#define TFT_PIN_D10 10
#define TFT_PIN_D10_OUTPUT() GPIO_PinModeSet(TFT_PORT_D10,TFT_PIN_D10, gpioModePushPull, 1);
#define TFT_PIN_D10_INPUT()  GPIO_PinModeSet(TFT_PORT_D10,TFT_PIN_D10, gpioModeInput, 0);

#define TFT_PORT_D9 gpioPortD
#define TFT_PIN_D9  9
#define TFT_PIN_D9_OUTPUT() GPIO_PinModeSet(TFT_PORT_D9,TFT_PIN_D9, gpioModePushPull, 1);
#define TFT_PIN_D9_INPUT()  GPIO_PinModeSet(TFT_PORT_D9,TFT_PIN_D9, gpioModeInput, 0);

#define TFT_PORT_D8 gpioPortD
#define TFT_PIN_D8  8
#define TFT_PIN_D8_OUTPUT() GPIO_PinModeSet(TFT_PORT_D8,TFT_PIN_D8, gpioModePushPull, 1);
#define TFT_PIN_D8_INPUT()  GPIO_PinModeSet(TFT_PORT_D8,TFT_PIN_D8, gpioModeInput, 0);

#ifdef _16_BIT_MODE

#define TFT_PORT_D7 gpioPortD
#define TFT_PIN_D7 7
#define TFT_PIN_D7_OUTPUT() GPIO_PinModeSet(TFT_PORT_D7,TFT_PIN_D7, gpioModePushPull, 1);
#define TFT_PIN_D7_INPUT()  GPIO_PinModeSet(TFT_PORT_D7,TFT_PIN_D7, gpioModeInput, 0);

#define TFT_PORT_D6 gpioPortD
#define TFT_PIN_D6 6
#define TFT_PIN_D6_OUTPUT() GPIO_PinModeSet(TFT_PORT_D6,TFT_PIN_D6, gpioModePushPull, 1);
#define TFT_PIN_D6_INPUT()  GPIO_PinModeSet(TFT_PORT_D6,TFT_PIN_D6, gpioModeInput, 0);

#define TFT_PORT_D5 gpioPortD
#define TFT_PIN_D5 5
#define TFT_PIN_D5_OUTPUT() GPIO_PinModeSet(TFT_PORT_D5,TFT_PIN_D5, gpioModePushPull, 1);
#define TFT_PIN_D5_INPUT()  GPIO_PinModeSet(TFT_PORT_D5,TFT_PIN_D5, gpioModeInput, 0);

#define TFT_PORT_D4 gpioPortD
#define TFT_PIN_D4 4
#define TFT_PIN_D4_OUTPUT() GPIO_PinModeSet(TFT_PORT_D4,TFT_PIN_D4, gpioModePushPull, 1);
#define TFT_PIN_D4_INPUT()  GPIO_PinModeSet(TFT_PORT_D4,TFT_PIN_D4, gpioModeInput, 0);

#define TFT_PORT_D3 gpioPortD
#define TFT_PIN_D3 3
#define TFT_PIN_D3_OUTPUT() GPIO_PinModeSet(TFT_PORT_D3,TFT_PIN_D3, gpioModePushPull, 1);
#define TFT_PIN_D3_INPUT()  GPIO_PinModeSet(TFT_PORT_D3,TFT_PIN_D3, gpioModeInput, 0);

#define TFT_PORT_D2 gpioPortD
#define TFT_PIN_D2 2
#define TFT_PIN_D2_OUTPUT() GPIO_PinModeSet(TFT_PORT_D2,TFT_PIN_D2, gpioModePushPull, 1);
#define TFT_PIN_D2_INPUT()  GPIO_PinModeSet(TFT_PORT_D2,TFT_PIN_D2, gpioModeInput, 0);


#define TFT_PORT_D1 gpioPortD
#define TFT_PIN_D1  1
#define TFT_PIN_D1_OUTPUT() GPIO_PinModeSet(TFT_PORT_D1,TFT_PIN_D1, gpioModePushPull, 1);
#define TFT_PIN_D1_INPUT()  GPIO_PinModeSet(TFT_PORT_D1,TFT_PIN_D1, gpioModeInput, 0);

#define TFT_PORT_D0 gpioPortD
#define TFT_PIN_D0 0
#define TFT_PIN_D0_OUTPUT() GPIO_PinModeSet(TFT_PORT_D0,TFT_PIN_D0, gpioModePushPull, 1);
#define TFT_PIN_D0_INPUT()  GPIO_PinModeSet(TFT_PORT_D0,TFT_PIN_D0, gpioModeInput, 0);

#endif
//========================================

/**Macro definitions for char display direction**/
#define LEFT2RIGHT  0
#define DOWN2UP     1
#define RIGHT2LEFT  2
#define UP2DOWN     3

void SPFD5408Init(void);
void SPFD5408PaintScreenBlack(void);
void SPFD5408SendCommand(uint16_t index);
void SPFD5408SendData(uint16_t data);
uint16_t SPFD5408ReadRegister(uint16_t index);

void SPFD5408SetXY(uint16_t poX, uint16_t poY);
void SPFD5408SetPixel(uint16_t poX, uint16_t poY, uint16_t color);
void SPFD5408DrawLine(uint16_t x0, uint16_t y0, uint16_t x1,
		uint16_t y1, uint16_t color);
void SPFD5408DrawVerticalLine(uint16_t poX, uint16_t poY,
		uint16_t length, uint16_t color);
void SPFD5408DrawHorizontalLine(uint16_t poX, uint16_t poY,
		uint16_t length, uint16_t color);
void SPFD5408DrawRectangle(uint16_t poX, uint16_t poY,
		uint16_t length, uint16_t width, uint16_t color);
void SPFD5408FillRectangle(uint16_t poX, uint16_t poY,
		uint16_t length, uint16_t width, uint16_t color);
void SPFD5408DrawCircle(int poX, int poY, int r, uint16_t color);
void SPFD5408FillCircle(int poX, int poY, int r, uint16_t color);
void SPFD5408DrawChar(uint16_t poX, uint16_t poY, unsigned char ascii,
		uint16_t size, uint16_t fgcolor);
void SPFD5408DrawString(uint16_t poX, uint16_t poY, char *string,
		uint16_t size, uint16_t fgcolor);
void SPFD5408DrawBmp(unsigned short ulXs, unsigned short ulYs,
		unsigned short length, unsigned short height, unsigned short *buf);

void SPFD5408SetOrientation(uint16_t HV);
void SPFD5408SetDisplayDirect(unsigned char Direction);

#endif /*_SPFD5408_H*/

