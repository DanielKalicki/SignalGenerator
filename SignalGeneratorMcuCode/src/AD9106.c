/*
 * AD9106.c
 *
 *  Created on: 25-01-2015
 *      Author: lukasz
 *      documentation: http://www.analog.com/en/digital-to-analog-converters/high-speed-da-converters/ad9106/products/product.html?src=ad9106.pdf
 */
#include "AD9106.h"

//privates
/* USART used for SPI access */
#define USART_USED        USART2
#define USART_CLK         cmuClock_USART2
#define SPI_SW_ENABLED 0

static const USART_InitSync_TypeDef initSpi = { usartEnable, /* Enable RX/TX when init completed. */
1000000, /* Use 1MHz reference clock */
1000, /* 1 Mbits/s. */
usartDatabits8, /* 8 databits. */
true, /* Master mode. */
true, /* Send most significant bit first. */
usartClockMode0, false, usartPrsRxCh0, false };

static StatusTypeDef spiPeripheralsConfig(void) {

	CMU_ClockEnable(cmuClock_HFPER, true);
	// Enable clock for USART1
	CMU_ClockEnable(USART_CLK, true);
	CMU_ClockEnable(cmuClock_GPIO, true);

	// Reset USART just in case
	USART_Reset(USART_USED );

	USART_InitSync(USART_USED, &initSpi);

	// Module USART1 is configured to location 1
	USART_USED ->ROUTE = (USART_USED ->ROUTE & ~_USART_ROUTE_LOCATION_MASK)
			| USART_ROUTE_LOCATION_LOC1;

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
void ADS9106Init(void) {

#if SPI_SW_ENABLED

	spiInitSoftware(ADS7843_PORT_MOSI, ADS7843_PIN_MOSI, ADS7843_PORT_MISO,
			ADS7843_PIN_MISO, ADS7843_PORT_CLK, ADS7843_PIN_CLK,
			ADS7843_PORT_CS, ADS7843_PIN_CS);

#else
	spiHandle.spiInstance = USART_USED;
	spiHandle.init = &initSpi;
	spiHandle.spiModeHwSw = false;
	spiHandle.spiGpioClockInit = spiPeripheralsConfig;
	spiInit(&spiHandle);
#endif
}

//private variables:

typedef struct {
	GPIO_Port_TypeDef spiPort;
	uint8_t spiPin;
} SpiPio;

static SpiPio mSpiMOSI;
static SpiPio mSpiMISO;
static SpiPio mSpiCLK;
static SpiPio mSpiCS;

#define SPI_CS_LOW()        GPIO_PinOutClear(mSpiCS.spiPort ,mSpiCS.spiPin );
#define SPI_CS_HIGH()       GPIO_PinOutSet(mSpiCS.spiPort , mSpiCS.spiPin );

#define SPI_MOSI_LOW()      GPIO_PinOutClear(mSpiMOSI.spiPort, mSpiMOSI.spiPin );
#define SPI_MOSI_HIGH()     GPIO_PinOutSet(mSpiMOSI.spiPort, mSpiMOSI.spiPin );

#define SPI_SCK_LOW()       GPIO_PinOutClear(mSpiCLK.spiPort , mSpiCLK.spiPin );
#define SPI_SCK_HIGH()      GPIO_PinOutSet(mSpiCLK.spiPort , mSpiCLK.spiPin );

//#define SPI_RESET_LOW()     GPIO_PinOutClear(SPI_PORT_RESET , SPI_PIN_RESET ); not used
//#define SPI_RESET_HIGH()    GPIO_PinOutSet(SPI_PORT_RESET , SPI_PIN_RESET );

/* @brief  init spi*/

void spiInitt(void) {
	USART_InitSync_TypeDef init = USART_INITSYNC_DEFAULT;
	init.refFreq = 16000000;
	init.baudrate = 2000000;
	init.msbf = true;
	/** SPI init structure */
	static const USART_InitSync_TypeDef initSpi = { usartEnable, /* Enable RX/TX when init completed. */
	16000000, /* Use 48MHz reference clock */
	1000000, /* 1 Mbits/s. */
	usartDatabits16, /* 16 databits. */
	true, /* Master mode. */
	true, /* Send most significant bit first. */
	usartClockMode0,
#if defined(_EFM32_GIANT_FAMILY) || defined(_EFM32_TINY_FAMILY) || defined(_EFM32_WONDER_FAMILY)
			false, usartPrsRxCh0, false,
#endif
			};
	/* Enable module clocks */
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_HFPER, true);

	/* To avoid false start, configure output US1_TX as high on PD0 */
	/* GPIO pins used, please refer to DVK user guide. */
	/* Configure SPI pins */
	GPIO_PinModeSet(SPI_PORT_MOSI, SPI_PIN_MOSI, gpioModePushPull, 1);
	GPIO_PinModeSet(SPI_PORT_MISO, SPI_PIN_MISO, gpioModeInput, 0);
	GPIO_PinModeSet(SPI_PORT_CLK, SPI_PIN_CLK, gpioModePushPull, 0);
	/* Keep CS high to not activate slave */
	GPIO_PinModeSet(SPI_PORT_CS, SPI_PIN_CS, gpioModePushPull, 1);

	/* Reset USART just in case */
	USART_Reset(USART_USED );
	/* Enable clock for USART1 */
	CMU_ClockEnable(USART_CLK, true);
	USART_InitSync(USART_USED, &initSpi);

	/* Module USART1 is configured to location 1 */USART_USED ->ROUTE =
			(USART_USED ->ROUTE & ~_USART_ROUTE_LOCATION_MASK)
					| USART_ROUTE_LOCATION_LOC1;

	/* Enable signals TX, RX, CLK, CS */USART_USED ->ROUTE |= USART_ROUTE_TXPEN
			| USART_ROUTE_RXPEN | USART_ROUTE_CLKPEN;

	USART_USED ->CTRL |= USART_CTRL_CLKPOL_IDLEHIGH;
	USART_USED ->CTRL |= USART_CTRL_CLKPHA_SAMPLELEADING;
	USART_USED ->CMD = USART_CMD_TXEN | USART_CMD_RXEN;
	/* Clear previous interrupts */USART_USED ->IFC = _USART_IFC_MASK;
	/*Reset*/
	GPIO_PinModeSet(SPI_PORT_RESET, SPI_PIN_RESET, gpioModePushPull, 0);
}

/* @brief disables all SPI peripherals*/
void spiDisable(void) {
	USART_Reset(USART_USED );
	USART_USED ->ROUTE = _USART_ROUTE_RESETVALUE;

	/* Disable SPI pins */
	GPIO_PinModeSet(SPI_PORT_MOSI, SPI_PIN_MOSI, gpioModeDisabled, 0);
	GPIO_PinModeSet(SPI_PORT_MISO, SPI_PIN_MISO, gpioModeDisabled, 0);
	GPIO_PinModeSet(SPI_PORT_CLK, SPI_PIN_CLK, gpioModeDisabled, 0);
	GPIO_PinModeSet(SPI_PORT_CS, SPI_PIN_CS, gpioModeDisabled, 0);

	/* Disable USART clock - we can't disable GPIO or HFPER as we don't know who else
	 * might be using it */
	CMU_ClockEnable(USART_CLK, false);
}

/* @brief  Perform SPI Transfer*/

uint16_t spiTransfer(uint8_t spiaddr, uint8_t spidata) {
	uint16_t readData;

	/* Write SPI address */
	USART_Tx(USART_USED, spiaddr);

	/* Wait for transmission to finish */
	while (!(USART_USED ->STATUS & USART_STATUS_TXC))
		;

	/* Just ignore data read back */
	readData = USART_Rx(USART_USED );
	readData <<= 8;

	/* Write SPI data */
	USART_Tx(USART_USED, spidata);

	/* Wait for transmission to finished */
	while (!(USART_USED ->STATUS & USART_STATUS_TXC))
		;

	readData |= USART_Rx(USART_USED );

	return (readData);
}

///

void spiSendByte(uint8_t spidata) {
	USART_Tx(USART_USED, spidata);
	while (!(USART_USED ->STATUS & USART_STATUS_TXC))
		;
	USART_Rx(USART_USED );
}

//
uint8_t spiGetByte(uint8_t addr) {
	USART_Tx(USART_USED, addr);
	while (!(USART_USED ->STATUS & USART_STATUS_TXC))
		;
	return (USART_Rx(USART_USED ));
}

/*
 void spiSendWord(uint8_t spidata)
 {

 USART_Tx(USART_USED, spidata);
 while (!(USART_USED->STATUS & USART_STATUS_TXC)) ;
 USART_Rx(USART_USED);
 }
 */

uint16_t spiReadWord(uint16_t addr) {
	uint16_t data = 0;
	//SPI_CS_HIGH()
	SPI_CS_LOW()
	//USART_Tx(USART_USED, addr);
	//while (!(USART_USED ->STATUS & USART_STATUS_TXC))
	//	;
	//return (USART_Rx(USART_USED ));

	/*
	 USART_Tx(USART_USED, spiaddr);
	 while (!(USART_USED ->STATUS & USART_STATUS_TXC))
	 ;
	 readData = USART_Rx(USART_USED );
	 readData <<= 8;

	 USART_Tx(USART_USED, spidata);

	 while (!(USART_USED ->STATUS & USART_STATUS_TXC))
	 ;

	 readData |= USART_Rx(USART_USED );
	 */

	USART_TxDouble(USART_USED, addr | 0x8000);
	while (!(USART_USED ->STATUS & USART_STATUS_TXC))
		;

	data = USART_RxDouble(USART_USED );
	SPI_CS_HIGH()
	return data;

}

//software

void spiInitSoftware(GPIO_Port_TypeDef spiPortMOSI, uint8_t spiPinMOSI,
		GPIO_Port_TypeDef spiPortMISO, uint8_t spiPinMISO,
		GPIO_Port_TypeDef spiPortCLK, uint8_t spiPinCLK,
		GPIO_Port_TypeDef spiPortCS, uint8_t spiPinCS) {
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(spiPortMOSI, spiPinMOSI, gpioModePushPull, 1);
	GPIO_PinModeSet(spiPortMISO, spiPinMISO, gpioModeInput, 0);
	GPIO_PinModeSet(spiPortCLK, spiPinCLK, gpioModePushPull, 1);
	// Keep CS high to not activate slave
	GPIO_PinModeSet(spiPortCS, spiPinCS, gpioModePushPull, 1);
	GPIO_PinOutClear(spiPortCLK, spiPinCLK);
	GPIO_PinOutClear(spiPortMOSI, spiPortMOSI);

	mSpiMOSI.spiPort = spiPortMOSI;
	mSpiMOSI.spiPin = spiPinMOSI;
	mSpiMISO.spiPort = spiPortMISO;
	mSpiMISO.spiPin = spiPinMISO;
	mSpiCLK.spiPort = spiPortCLK;
	mSpiCLK.spiPin = spiPinCLK;
	mSpiCS.spiPort = spiPortCS;
	mSpiCS.spiPin = spiPinCS;

}

uint16_t spiWriteWordSoftware(uint16_t addr, uint16_t data) {
	SPI_SCK_HIGH()
	Delay(1);
	addr &= ~0x8000; //writing
	SPI_CS_LOW()

	for (int i = 0; i < 16; i++) {

		if (addr & 0x8000)
			SPI_MOSI_HIGH()
		else
			SPI_MOSI_LOW()
		SPI_SCK_LOW()
		Delay(1);
		SPI_SCK_HIGH()
		addr <<= 1;
		Delay(1);

	}

	for (int i = 0; i < 16; i++) {

		if (data & (1 << (15 - i)))
			SPI_MOSI_HIGH()
		else
			SPI_MOSI_LOW()
		SPI_SCK_LOW()
		Delay(1);
		SPI_SCK_HIGH()
		addr <<= 1;
		Delay(1);

	}

	SPI_CS_HIGH()
	return data;

}

uint16_t spiReadWordSoftware(uint16_t addr) {
	uint16_t data = 0;
	SPI_SCK_HIGH()
	Delay(1);
	addr |= 0x8000; //reading
	SPI_CS_LOW()

	for (int i = 0; i < 16; i++) {

		if (addr & 0x8000)
			SPI_MOSI_HIGH()
		else
			SPI_MOSI_LOW()
		SPI_SCK_LOW()
		Delay(1);
		SPI_SCK_HIGH()
		addr <<= 1;
		Delay(1);

	}

	for (int i = 0; i < 16; i++) {
		SPI_SCK_LOW()
		Delay(1);
		SPI_SCK_HIGH()
		data |= ((GPIO_PinInGet(SPI_PORT_MISO, SPI_PIN_MISO) << (15 - i)));

		Delay(1);

	}
	SPI_CS_HIGH()
	return data;

}




bool setConfig(void) {

	return true;
}

bool writeReg(uint16_t regAddress, uint16_t dataBitMask, uint16_t data) {

	uint16_t tempVal;
	//if(!read(regAddress,&tempVal,1)) return false;   TODO , wrappers for SPI hardware implementation
	tempVal &= ~(dataBitMask);
	tempVal |= data << getShiftValue(dataBitMask);
	//return write(regAddress, &tempVal,1);

}

bool readReg(uint16_t regAddress, uint16_t dataBitMask, uint16_t *data) {

	uint16_t tempVal;
	// if(!read(regAddress,&tempVal,1)) return false;
	tempVal &= dataBitMask;
	tempVal >>= getShiftValue(dataBitMask);
	*data = tempVal;
	return true;
}

void AD9106_test(void) {
	static uint16_t counter = 0;
	counter += 1000;
	if (counter >= 30000)
		counter = 0;
	uint16_t i = 0;
	spiWriteWordSoftware((uint16_t) PAT_TYPE, 0);
	Delay(1);

	//spiWriteWordSoftware((uint16_t)WAV4_3CONFIG,0x2121);Delay(1);//noise output test
	spiWriteWordSoftware((uint16_t) WAV4_3CONFIG, 0x1111);
	Delay(1); //sawtooth test

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

}

