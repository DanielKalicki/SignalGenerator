#include <stdio.h>
#include "em_device.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "spi.h"

/* @brief  init spi*/

void spiInit(void) {
	USART_InitSync_TypeDef init = USART_INITSYNC_DEFAULT;
	init.refFreq = 16000000;
	init.baudrate = 2000000;
	init.msbf = true;
	/** SPI init structure */
	static const USART_InitSync_TypeDef initSpi =
	{ usartEnable,    /* Enable RX/TX when init completed. */
	  48000000,       /* Use 48MHz reference clock */
	  1000000,        /* 1 Mbits/s. */
	  usartDatabits16, /* 8 databits. */
	  true,           /* Master mode. */
	  true,           /* Send most significant bit first. */
	  usartClockMode0,
	#if defined(_EFM32_GIANT_FAMILY) || defined(_EFM32_TINY_FAMILY) || defined(_EFM32_WONDER_FAMILY)
	  false,
	  usartPrsRxCh0,
	  false,
	#endif
	};
	/* Enable module clocks */
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_HFPER, true);

	/* To avoid false start, configure output US1_TX as high on PD0 */
	/* GPIO pins used, please refer to DVK user guide. */
	/* Configure SPI pins */
	GPIO_PinModeSet(PORT_SPI_TX, PIN_SPI_TX, gpioModePushPull, 1);
	GPIO_PinModeSet(PORT_SPI_RX, PIN_SPI_RX, gpioModeInput, 0);
	GPIO_PinModeSet(PORT_SPI_CLK, PIN_SPI_CLK, gpioModePushPull, 0);
	/* Keep CS high to not activate slave */
	GPIO_PinModeSet(PORT_SPI_CS, PIN_SPI_CS, gpioModePushPull, 1);

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

	//USART_USED ->CTRL |=/* USART_CTRL_CLKPOL|*/USART_CTRL_CLKPOL_DEFAULT;
	//USART_USED ->CTRL |= /*USART_CTRL_CLKPHA */USART_CTRL_CLKPHA_DEFAULT;
	USART_USED ->CMD = USART_CMD_TXEN | USART_CMD_RXEN;
	  /* Clear previous interrupts */
	USART_USED ->IFC = _USART_IFC_MASK;
	/*Reset*/
	GPIO_PinModeSet(PORT_SPI_RESET, PIN_SPI_RESET, gpioModePushPull, 0);
}

/* @brief disables all SPI peripherals*/
void spiDisable(void) {
	USART_Reset(USART_USED );
	USART_USED ->ROUTE = _USART_ROUTE_RESETVALUE;

	/* Disable SPI pins */
	GPIO_PinModeSet(PORT_SPI_TX, PIN_SPI_TX, gpioModeDisabled, 0);
	GPIO_PinModeSet(PORT_SPI_RX, PIN_SPI_RX, gpioModeDisabled, 0);
	GPIO_PinModeSet(PORT_SPI_CLK, PIN_SPI_CLK, gpioModeDisabled, 0);
	GPIO_PinModeSet(PORT_SPI_CS, PIN_SPI_CS, gpioModeDisabled, 0);

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

