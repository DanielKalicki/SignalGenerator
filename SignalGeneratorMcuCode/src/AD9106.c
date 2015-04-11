/*
 * AD9106.c
 *
 *  Created on: 25-01-2015
 *      Author: lukasz
 *      documentation: http://www.analog.com/en/digital-to-analog-converters/high-speed-da-converters/ad9106/products/product.html?src=ad9106.pdf
 */
#include "AD9106.h"
#include "em_cmu.h"
#include "utils.h"
//privates
#define SPI_SW_ENABLED 0

static const USART_InitSync_TypeDef initSpi = { usartEnable, /* Enable RX/TX when init completed. */
1000000, /* Use 1MHz reference clock */
1000, /* 1 Mbits/s. */
usartDatabits16, /* 16 databits. */
true, /* Master mode. */
true, /* Send most significant bit first. */
usartClockMode0, false, usartPrsRxCh0, false };

static StatusTypeDef spiPeripheralsConfig(void) {

	CMU_ClockEnable(cmuClock_HFPER, true);
	// Enable clock for USART2
	CMU_ClockEnable(USART_CLK, true);
	CMU_ClockEnable(cmuClock_GPIO, true);

	// Reset USART just in case
	USART_Reset(USART_USED );

	USART_InitSync(USART_USED, &initSpi);

	// Module USART2 is configured to location 0
	USART_USED ->ROUTE = (USART_USED ->ROUTE & ~_USART_ROUTE_LOCATION_MASK)
			| USART_ROUTE_LOCATION_LOC0;

	// Enable signals TX, RX, CLK, CS
	USART_USED ->ROUTE |= USART_ROUTE_TXPEN | USART_ROUTE_RXPEN
			| USART_ROUTE_CLKPEN;

	//USART_USED ->CTRL |= USART_CTRL_CLKPOL_IDLEHIGH;
	//USART_USED ->CTRL |= USART_CTRL_CLKPHA_SAMPLELEADING;
	USART_USED ->CMD = USART_CMD_TXEN | USART_CMD_RXEN;
	// Clear previous interrupts
	USART_USED ->IFC = _USART_IFC_MASK;

	GPIO_PinModeSet(AD9106_PORT_MOSI, AD9106_PIN_MOSI, gpioModePushPull, 1);
	GPIO_PinModeSet(AD9106_PORT_MISO, AD9106_PIN_MISO, gpioModeInput, 0);
	GPIO_PinModeSet(AD9106_PORT_CLK, AD9106_PIN_CLK, gpioModePushPull, 0);
	// Keep CS high to not activate slave
	GPIO_PinModeSet(AD9106_PORT_CS, AD9106_PIN_CS, gpioModePushPull, 1);
	return STATUS_OK;
}

static SpiHandleTypeDef spiHandle;
//*****************************************************************************
//
//! \brief Initialize ADS9106Init
//!
//! \param None.
//!
//! This function initializes ADS7843's SPI interface and .
//!
//! \return None.
//
//*****************************************************************************
void AD9106Init(void) {

#if SPI_SW_ENABLED

	spiInitSoftware();

#else
	spiHandle.spiInstance = USART_USED;
	spiHandle.init = &initSpi;
	spiHandle.spiModeHwSw = false;
	//spiHandle.spiSwTransfer=(struct _SpiHandleTypeDef* hspi);
	spiHandle.spiGpioClockInit = spiPeripheralsConfig;
	if (spiInit(&spiHandle) != STATUS_OK)
		while (1)
			;
#endif
}

//private variables:

/* @brief disables all SPI peripherals*/
void spiDisable(void) {
	USART_Reset(USART_USED );
	USART_USED ->ROUTE = _USART_ROUTE_RESETVALUE;

	/* Disable SPI pins */AD9106_MOSI_DISABLED();
	AD9106_MISO_DISABLED();
	AD9106_CLK_DISABLED();
	AD9106_CS_DISABLED();

	/* Disable USART clock - we can't disable GPIO or HFPER as we don't know who else
	 * might be using it */
	CMU_ClockEnable(USART_CLK, false);
}

/* @brief  Perform SPI Transfer*/
static uint16_t ADS7843SpiReadReg(AD9106RegAddress regAddress,
		uint16_t dataBitMask) {
	uint8_t txBuf[4] = { regAddress, ((regAddress >> 8) & 0xFF) | 0x80 };
	uint8_t rxBuf[4] = { 0 };
	AD9106_CS_LOW();
	if (spiTransmitReceive(&spiHandle, txBuf, rxBuf, 2, 0) == STATUS_OK) {

		uint16_t retVal = ((rxBuf[3] << 8) | (rxBuf[2])) & 0xFFFF;
		if (dataBitMask != 0) {
			retVal &= dataBitMask;
			retVal >>= getShiftValue(dataBitMask);
		}
		AD91063_CS_HIGH();
		return retVal;
	} else {
		AD91063_CS_HIGH();
		return 0xffff;
	}
}

static bool ADS7843SpiWriteReg(AD9106RegAddress regAddress,
		uint16_t dataBitMask, uint16_t data) {

	if (dataBitMask != 0) {

		uint16_t tempVal = ADS7843SpiReadReg(regAddress, 0);
		tempVal &= ~(dataBitMask);
		tempVal |= data << getShiftValue(dataBitMask);
		data = tempVal;

	}
	uint8_t txBuf[4] = { regAddress, ((regAddress >> 8) & 0xFF) & (~0x80), data,
			data >> 8 };
	uint8_t rxBuf[4] = { 0 };
	AD9106_CS_LOW();

	if (spiTransmitReceive(&spiHandle, txBuf, rxBuf, 2, 0) == STATUS_OK) {
		AD91063_CS_HIGH();
		return true;
	} else {
		AD91063_CS_HIGH();
		return false;
	}
}






//software SPI

void spiInitSoftware(void) {
	CMU_ClockEnable(cmuClock_GPIO, true);
	AD9106_MOSI_OUTPUT();
	AD9106_MISO_INPUT();
	AD9106_CLK_OUTPUT();
	// Keep CS high to not activate slave
	AD9106_CS_OUTPUT();
	AD9106_CLK_LOW();
	AD9106_MOSI_LOW();
}

uint16_t spiWriteWordSoftware(uint16_t addr, uint16_t data) {
	AD9106_CLK_HIGH();
	Delay(1);
	addr &= ~0x8000; //writing
	AD9106_CS_LOW();

	for (int i = 0; i < 16; i++) {

		if (addr & 0x8000)
			AD9106_MOSI_HIGH();
		else
			AD9106_MOSI_LOW();
		AD9106_CLK_LOW();
		Delay(1);
		AD9106_CLK_HIGH();
		addr <<= 1;
		Delay(1);

	}

	for (int i = 0; i < 16; i++) {

		if (data & (1 << (15 - i)))
			AD9106_MOSI_HIGH();
		else
			AD9106_MOSI_LOW();
		AD9106_CLK_LOW();
		Delay(1);
		AD9106_CLK_HIGH();
		addr <<= 1;
		Delay(1);

	}

	AD91063_CS_HIGH();
	return data;

}

uint16_t spiReadWordSoftware(uint16_t addr) {
	uint16_t data = 0;
	AD9106_CLK_HIGH();
	Delay(1);
	addr |= 0x8000; //reading
	AD9106_CS_LOW();

	for (int i = 0; i < 16; i++) {

		if (addr & 0x8000)
			AD9106_MOSI_HIGH();
		else
			AD9106_MOSI_LOW();
		AD9106_CLK_LOW();
		Delay(1);
		AD9106_CLK_HIGH();
		addr <<= 1;
		Delay(1);

	}

	for (int i = 0; i < 16; i++) {
		AD9106_CLK_LOW();
		Delay(1);
		AD9106_CLK_HIGH();
		data |= ((AD9106_MISO_GET_PIN()) << (15 - i));

		Delay(1);

	}
	AD91063_CS_HIGH();
	return data;

}

static bool writeReg(uint16_t regAddress, uint16_t dataBitMask, uint16_t data) {

	uint16_t tempVal;
	//if(!read(regAddress,&tempVal,1)) return false;   TODO , wrappers for SPI hardware implementation
	tempVal &= ~(dataBitMask);
	tempVal |= data << getShiftValue(dataBitMask);
	//return write(regAddress, &tempVal,1);
	return true;

}

void AD9106Test(void) {
	static uint16_t counter = 0;
	counter += 1000;
	if (counter >= 30000)
		counter = 0;
	uint16_t i = 0;
#if !SPI_SW_ENABLED
	/*i = ADS7843SpiReadReg(PATTERN_DLY, 0);
	SegmentLCD_Number(i);
	Delay(2000);

	i = ADS7843SpiReadReg(DAC4_3PATx, 0);
	SegmentLCD_Number(i);
	Delay(2000);
	//Delay(1);
	ADS7843SpiWriteReg(PATTERN_DLY, 0, counter / 1000);
	*/
	Delay(2000);
	//Clock
	//ADS7843SpiWriteReg(CLOCKCONFIG, 0, 0);
	i = ADS7843SpiReadReg(CLOCKCONFIG, 0);
		SegmentLCD_Number(i);
	ADS7843SpiWriteReg(CLOCKCONFIG, DAC1_INV_CLK, 1);

	/*Delay(2000);
	//Clock
	i = ADS7843SpiReadReg(POWERCONFIG, 0);
		SegmentLCD_Number(i);
	ADS7843SpiWriteReg(POWERCONFIG, DAC1_SLEEP, 1);
	*/
#else SPI_SW_ENABLED
	i = spiReadWordSoftware((uint16_t) PATTERN_DLY);
	SegmentLCD_Number(i);
	Delay(3000);
	i = spiReadWordSoftware(DAC1RSET);
	SegmentLCD_Number(i);
	Delay(3000);

	//spiWriteWordSoftware((uint16_t)WAV4_3CONFIG,0x2121);Delay(1);//noise output test
	spiWriteWordSoftware((uint16_t) WAV4_3CONFIG, 0x1111);
	Delay(1);//sawtooth test

	spiWriteWordSoftware((uint16_t) DAC4_CST, 0xA200);
	Delay(1);
	spiWriteWordSoftware((uint16_t) DAC4_DGAIN, 0xA000);
	Delay(1);
	spiWriteWordSoftware((uint16_t) DAC4RSET, 0x8002);
	Delay(1);
	spiWriteWordSoftware((uint16_t) DACxRANGE, 0x00A0);
	Delay(1);
	spiWriteWordSoftware((uint16_t) PAT_TIMEBASE, 0x0000);
	Delay(1);
	spiWriteWordSoftware((uint16_t) PAT_PERIOD, 0x0100);
	Delay(1);
	spiWriteWordSoftware((uint16_t) PAT_STATUS, 0x0001);
	Delay(1);
	spiWriteWordSoftware((uint16_t) RAMUPDATE, 0x0001);
	Delay(1);

	//sawtooth configuration
	spiWriteWordSoftware((uint16_t) SAW4_3CONFIG, 0x0808);
	Delay(1);

	Delay(500);
	i = spiReadWordSoftware((uint16_t) CFG_ERROR);
	i = spiReadWordSoftware((uint16_t) PAT_STATUS);
	SegmentLCD_Number(i);
	Delay(2000);
#endif
}

