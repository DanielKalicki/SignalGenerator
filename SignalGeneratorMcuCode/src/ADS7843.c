/*
 * ADS7843.c
 *
 *  Created on: 11-03-2015
 *      Author: lukasz
 */

#include "spi.h"
#include "ADS7843.h"
#include "stdio.h"
#include "utils.h"
#include "drivers/gpiointerrupt.h"

TouchInfo tTouchData;
static TouchPoint mPointCoordinates={0};
extern volatile bool mADS7843ScreenTouched= false;
#define ADS7843_ENABLE_TOUCH_INT


TouchPoint getCoordinates(void){

	return  mPointCoordinates;
}


static void ADS7843SpiWriteByteSoftware(uint8_t data) {
	Delay(1);

	for (int i = 0; i < 8; i++) {

		if (data & 0x80) {
			ADS7843_MOSI_HIGH()
			;
		} else {
			ADS7843_MOSI_LOW()
			;
		}
		ADS7843_CLK_HIGH()
		;

		Delay(1);
		ADS7843_CLK_LOW()
		;
		data <<= 1;
		Delay(1);

	}

}

static uint8_t ADS7843SpiReadByteSoftware(void) {
	uint8_t data = 0;
	ADS7843_CLK_HIGH()
	Delay(1);

	for (int i = 0; i < 8; i++) {
		ADS7843_CLK_LOW()
		Delay(1);
		ADS7843_CLK_HIGH()
		data |=
				((GPIO_PinInGet(ADS7843_PORT_MISO, ADS7843_PIN_MISO) << (8 - i)));

		Delay(1);

	}
	return data;

}

static void ADS7843PenIRQCallback(uint8_t pin) {

	if (pin == ADS7843_PIN_INT) {
		uint16_t x, y;
		ADS7843_INT_IRQ_CONFIG_PIN_DISABLE()
		if (ADS7843_GET_INT_PIN()) {
			// Change to falling trigger edge when pen up
			ADS7843_INT_IRQ_CONFIG_FALLING(true);
			tTouchData.touch_status |= TOUCH_STATUS_PENUP;
			tTouchData.touch_status &= ~TOUCH_STATUS_PENDOWN;
		} else {
			// Modify status
			tTouchData.touch_status |= TOUCH_STATUS_PENDOWN;
			tTouchData.touch_status &= ~TOUCH_STATUS_PENUP;
			// Read x,y coordinate
			ADS7843ReadPointXY(&x, &y);
			 mPointCoordinates.x=x;
			 mPointCoordinates.y=y;

			ADS7843_INT_IRQ_CONFIG_RISING(true);
			mADS7843ScreenTouched=true;
		}

	}

}

//*****************************************************************************
//
//! \brief Initialize ADS7843
//!
//! \param None.
//!
//! This function initialize ADS7843's SPI interface and .
//!
//! \return None.
//
//*****************************************************************************
void ADS7843Init(void) {
	spiInitSoftware(ADS7843_PORT_MOSI, ADS7843_PIN_MOSI, ADS7843_PORT_MISO,
			ADS7843_PIN_MISO, ADS7843_PORT_CLK, ADS7843_PIN_CLK,
			ADS7843_PORT_CS, ADS7843_PIN_CS);

#ifdef ADS7843_ENABLE_TOUCH_INT

	/* Initialize GPIO interrupt dispatcher */
	GPIOINT_Init();
	ADS7843_INT_INPUT()
	;
	ADS7843_INT_IRQ_CONFIG_FALLING(true); //falling edge
	GPIOINT_CallbackRegister(ADS7843_PIN_INT, ADS7843PenIRQCallback);

#endif


	// assign default values
	tTouchData.th_ad_left = TOUCH_AD_X_MIN;
	tTouchData.th_ad_right = TOUCH_AD_X_MAX;
	tTouchData.th_ad_up = TOUCH_AD_Y_MAX;
	tTouchData.th_ad_down = TOUCH_AD_Y_MIN;
	tTouchData.touch_status = 0;
}



uint16_t ADS7843PenInq(void) {
	return (uint16_t) ADS7843_GET_INT_PIN();
}

//*****************************************************************************
//
//! \brief Read the x, y axis ADC convert value once from ADS7843
//!
//! \param x To save the x axis ADC convert value.
//! \param y To save the y axis ADC convert value.
//!
//! \return None.
//
//*****************************************************************************
void ADS7843ReadADXYRaw(uint16_t *x, uint16_t *y) {
// Chip select
	ADS7843_CS_LOW()
	;
	Delay(10);

// Send read x command
	ADS7843SpiWriteByteSoftware(ADS7843_READ_X); //read x command
#ifdef ADS7843_USE_PIN_BUSY

			// wait for conversion complete
			while(xGPIOSPinRead(ADS7843_PIN_BUSY));
#else

// The conversion needs 8us to complete
	Delay(240);
#endif

// Read the high 8bit of the 12bit conversion result
	*x = (uint16_t) ADS7843SpiReadByteSoftware() & 0xFF;
	*x <<= 4;
// Read the low 4bit of the 12bit conversion result
	*x |= (uint16_t) ADS7843SpiReadByteSoftware() >> 4;

// Send read y command
	ADS7843SpiWriteByteSoftware(ADS7843_READ_Y); //read y command
#ifdef ADS7843_USE_PIN_BUSY

			// wait for conversion complete
			while(xGPIOSPinRead(ADS7843_PIN_BUSY));
#else

// The conversion needs 8us to complete
	Delay(240);
#endif

// Read the high 8bit of the 12bit conversion result
	*y = (uint16_t) ADS7843SpiReadByteSoftware() & 0xFF;
	*y <<= 4;

// Read the low 4bit of the 12bit conversion result
	*y |= (uint16_t) ADS7843SpiReadByteSoftware() >> 4;
	ADS7843_CS_HIGH()
	;
}

//*****************************************************************************
//
//! \brief read the x, y axis ADC convert value from ADS7843(with software filter)
//!
//! \param x To save the x axis ADC convert value.
//! \param y To save the y axis ADC convert value.
//!
//! This function Reads the x,y axis's ADC value from ADS7843 with software
//! filter. The function first read out TOUCH_SMAPLE_LEN samples. Then discard
//! the first data and the last data and sort the remained data. Then discard
//! the first and the last one of the remained data and compute the average
//! value of the final remained data.
//!
//! \return None.
//
//*****************************************************************************
void ADS7843ReadADXY(uint16_t *x, uint16_t *y) {
	uint16_t usXYArray[2][TOUCH_SMAPLE_LEN];
	uint8_t i, j;
	uint16_t temp;

	for (i = 0; i < TOUCH_SMAPLE_LEN; i++) {
		ADS7843ReadADXYRaw(&usXYArray[0][i], &usXYArray[1][i]);
	}

// Discard the first and the last one of the data and sort remained data
	for (i = 1; i < TOUCH_SMAPLE_LEN - 2; i++) {
		for (j = i + 1; j < TOUCH_SMAPLE_LEN - 1; j++) {
			if (usXYArray[0][i] > usXYArray[0][j]) {
				temp = usXYArray[0][i];
				usXYArray[0][i] = usXYArray[0][j];
				usXYArray[0][j] = temp;
			}

			if (usXYArray[1][i] > usXYArray[1][j]) {
				temp = usXYArray[1][i];
				usXYArray[1][i] = usXYArray[1][j];
				usXYArray[1][j] = temp;
			}
		}
	}
	usXYArray[0][0] = 0;
	usXYArray[1][0] = 0;

//
// Discard the first and the last one of the sorted data
// and compute the average value of the remained data.
//
	for (i = 2; i < TOUCH_SMAPLE_LEN - 2; i++) {
		usXYArray[0][0] += usXYArray[0][i];
		usXYArray[1][0] += usXYArray[1][i];
	}
	*x = usXYArray[0][0] / (TOUCH_SMAPLE_LEN - 4);
	*y = usXYArray[1][0] / (TOUCH_SMAPLE_LEN - 4);
}




uint16_t ADS7843ReadInputChannel(unsigned char ucChannel) {
	uint16_t res;

	if ((ucChannel != ADS7843_READ_IN4) || (ucChannel != ADS7843_READ_IN3)
			|| (ucChannel != ADS7843_READ_X) || (ucChannel != ADS7843_READ_Y)) {
		return 0;
	}
	ADS7843_CS_LOW()
	;
	Delay(10);
	ADS7843SpiWriteByteSoftware(ucChannel);
#ifdef ADS7843_USE_PIN_BUSY

// Waiting for conversion complete
	while(xGPIOSPinRead(ADS7843_PIN_BUSY));
#else
	Delay(240);
#endif
	res = (uint16_t) ADS7843SpiReadByteSoftware() & 0x00FF;
	res <<= 4;
	res |= (uint16_t) ADS7843SpiReadByteSoftware() >> 4;
	ADS7843_CS_HIGH()
	;

	return res;
}

//*****************************************************************************
//
//! \brief Touch screen calibration.
//!
//! \param None.
//!
//! This function is to calibrate the touch screen. If the read out coordinate
//! is not accurate, you can use this function to calibrate it. After this
//! function is called, you must touch the screen in about 10 seconds or the
//! function will return with no effect. After you touch the screen, the counter
//! will be zeroed and restart counting. If the calibration is not over and the
//! touch is always applied on the screen, the counter will not increase, so you
//! don't have to worry about the calibrate time.
//!     All you need to do with the calibration is to use a touch pen or other
//! object which is a little sharp but will not damage the touch screen to touch
//! the screen and slide the pen from top edge of the screen to the bottom edge.
//! Then slide the pen from left edge to right edge. Make sure that the pen should
//! not leave the screen until it slides to the edge or the calibrate may be
//! inaccurate. The direction or sequence is optional. If __DEBUG_PRINT__ is defined
//! you can see the calibration result. The calibration will calibrate both x axis
//! and y axis. Also you can calibration only one axis. the axis which is not
//! calibrated will retain its original value.
//!
//! \return None.
//
//*****************************************************************************
uint8_t ADS7843Calibration(void) {
	uint16_t adx, ady;
	uint16_t adxmin = TOUCH_AD_X_MAX;
	uint16_t adxmax = TOUCH_AD_X_MIN;
	uint16_t adymin = TOUCH_AD_X_MAX;
	uint16_t adymax = TOUCH_AD_X_MIN;
	uint16_t calibrationFlag = 0;
	uint32_t timeout = 0;

#ifdef ADS7843_ENABLE_TOUCH_INT
//  disable touch interrupt
	ADS7843_INT_IRQ_CONFIG_PIN_DISABLE()
	;
#endif
	while (1) {
		if (!ADS7843_GET_INT_PIN()) {
			//
			// If pen down continuously read the x,y value and record the
			// maximum and minimum value
			//
			while (!ADS7843_GET_INT_PIN()) {
				ADS7843ReadADXY(&adx, &ady);
				if (adx < adxmin) {
					adxmin = adx;
				} else if (adx > adxmax) {
					adxmax = adx;
				}

				if (ady < adymin) {
					adymin = ady;
				} else if (ady > adymax) {
					adymax = ady;
				}
			}
			// Counter clear.
			timeout = 0;
		}

		// If x axis calibration is not complete
		if (!(calibrationFlag & 1)) {
			//  If x axis calibrate over
			if ((adxmax > (TOUCH_AD_X_MAX - TOUCH_AD_CALIB_ERROR))
					&& (adxmax < (TOUCH_AD_X_MAX + TOUCH_AD_CALIB_ERROR))
					&& (adxmin > (TOUCH_AD_X_MIN - TOUCH_AD_CALIB_ERROR))
					&& (adxmin < (TOUCH_AD_X_MIN + TOUCH_AD_CALIB_ERROR))) {
#ifdef __DEBUG_PRINT__
				printf("x coordinate calibrate over\n\r");
#endif
				tTouchData.th_ad_left = adxmin;
				tTouchData.th_ad_right = adxmax;
				calibrationFlag |= 1;
			}
		}

		// If y axis calibration is not complete
		if (!(calibrationFlag & 2)) {
			//  If y axis calibrate over
			if ((adymax > (TOUCH_AD_Y_MAX - TOUCH_AD_CALIB_ERROR))
					&& (adymax < (TOUCH_AD_Y_MAX + TOUCH_AD_CALIB_ERROR))
					&& (adymin > (TOUCH_AD_Y_MIN - TOUCH_AD_CALIB_ERROR))
					&& (adymin < (TOUCH_AD_Y_MIN + TOUCH_AD_CALIB_ERROR))) {
#ifdef __DEBUG_PRINT__
				printf("y coordinate calibrate over\n\r");
#endif
				tTouchData.th_ad_up = adymax;
				tTouchData.th_ad_down = adymin;
				calibrationFlag |= 2;
			}
		}

		// If two coordinates calibrate over or timer out
		if ((calibrationFlag == 3) || (timeout++ > 100000)) {
#ifdef ADS7843_ENABLE_TOUCH_INT
			ADS7843_INT_IRQ_CONFIG_FALLING(true);
#endif
			return calibrationFlag;
		}
		Delay(1000);
	}
}

//*****************************************************************************
//
//! \brief Read the XY coordinate of touch point.
//!
//! \param x To save the x coordinate
//! \param y To save the y coordinate
//!
//! This function is to read current touch point. The x,y coordinates will be
//! read out from the input parameters. If the screen is not touched, it will
//! return last value, after the last value is read out, additional read will
//! return fail information and nothing will be read out.
//!
//! \return None.
//
//*****************************************************************************
uint8_t ADS7843ReadPointXY(uint16_t *x, uint16_t *y) {
	uint16_t usADX;
	uint16_t usADY;
	uint32_t temp = 0;

	if (!ADS7843_GET_INT_PIN()) {
		//  If pen down
		ADS7843ReadADXY(&usADX, &usADY);

		//  calculate the difference
		temp = usADX - tTouchData.th_ad_left;

		//  limit the left edge
		if (temp > tTouchData.th_ad_right)
			temp = 0;

		//  calculate the x coordinate
		*x = temp * TOUCH_SCREEN_WIDTH
				/ (tTouchData.th_ad_right - tTouchData.th_ad_left);
		tTouchData.last_x = tTouchData.cur_x;
		tTouchData.cur_x = *x;

		temp = tTouchData.th_ad_up - usADY;

		//  limit the top edge
		if (temp > tTouchData.th_ad_up)
			temp = 0;

		//  calculate the y coordinate
		*y = temp * TOUCH_SCREEN_HEIGHT
				/ (tTouchData.th_ad_up - tTouchData.th_ad_down);
		tTouchData.last_y = tTouchData.cur_y;
		tTouchData.cur_y = *y;
		return 0;
	} else {
		//  if pen up
		if (tTouchData.touch_status & TOUCH_STATUS_PENUP) {
			tTouchData.last_x = tTouchData.cur_x;
			*x = tTouchData.cur_x;
			tTouchData.last_y = tTouchData.cur_y;
			*y = tTouchData.cur_y;
			tTouchData.touch_status = 0;
			return 0;
		}
		return 1;
	}
}
