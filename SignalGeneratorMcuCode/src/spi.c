
#include <stdio.h>
#include "em_device.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "spi.h"


 /* @brief  init spi*/

void spiInit(void)
{
  USART_InitSync_TypeDef init = USART_INITSYNC_DEFAULT;

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
  USART_Reset(USART_USED);

  /* Enable clock for USART1 */
  CMU_ClockEnable(USART_CLK, true);

  /* Configure to use SPI master with manual CS */
  /* For now, configure SPI for worst case 32MHz clock in order to work for all */
  /* configurations. */
  init.refFreq  = 16000000;
  init.baudrate = 2000000;
  init.msbf     = true;
  USART_InitSync(USART_USED, &init);  
  
  /* Module USART1 is configured to location 1 */
  USART_USED->ROUTE = (USART_USED->ROUTE & ~_USART_ROUTE_LOCATION_MASK) |
                      USART_ROUTE_LOCATION_LOC1;

  /* Enable signals TX, RX, CLK, CS */
  USART_USED->ROUTE |= USART_ROUTE_TXPEN | USART_ROUTE_RXPEN |
                       USART_ROUTE_CLKPEN;

  USART_USED->CTRL |= USART_CTRL_CLKPOL;
  USART_USED->CTRL |= USART_CTRL_CLKPHA;

  /*Reset*/
  GPIO_PinModeSet(PORT_SPI_RESET, PIN_SPI_RESET, gpioModePushPull, 0);
}

/* @brief disables all SPI peripherals*/
void spiDisable(void)
{
  USART_Reset(USART_USED);
  USART_USED->ROUTE = _USART_ROUTE_RESETVALUE;

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

uint16_t spiTransfer(uint8_t spiaddr, uint8_t spidata)
{
  uint16_t readData;

  /* Write SPI address */
  USART_Tx(USART_USED, spiaddr);

  /* Wait for transmission to finish */
  while (!(USART_USED->STATUS & USART_STATUS_TXC)) ;

  /* Just ignore data read back */
  readData   = USART_Rx(USART_USED);
  readData <<= 8;

  /* Write SPI data */
  USART_Tx(USART_USED, spidata);

  /* Wait for transmission to finished */
  while (!(USART_USED->STATUS & USART_STATUS_TXC)) ;

  readData |= USART_Rx(USART_USED);

  return(readData);
}


 ///

void spiSendByte(uint8_t spidata)
{
  /* Write SPI address */
  USART_Tx(USART_USED, spidata);

  /* Wait for transmission to finish */
  while (!(USART_USED->STATUS & USART_STATUS_TXC)) ;

  /* Just ignore data read back */
  USART_Rx(USART_USED);
}

//
uint8_t spiGetByte(void)
{
  /* Write SPI address */
  USART_Tx(USART_USED, 0x00);

  /* Wait for transmission to finish */
  while (!(USART_USED->STATUS & USART_STATUS_TXC)) ;

  /* Return the data read from SPI buffer */
  return(USART_Rx(USART_USED));
}
