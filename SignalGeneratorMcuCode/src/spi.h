#ifndef __SPI_H
#define __SPI_H

#include <stdbool.h>
#include "em_device.h"
#include "em_bitband.h"
#include "em_gpio.h"
#include "em_usart.h"

#ifdef __cplusplus
extern "C" {
#endif

/* USART used for SPI access */
#define USART_USED        USART1
#define USART_CLK         cmuClock_USART1

/* GPIO pins used for SPI communication. */
/*DEFAULT PINOUT USED FOR HARDWARE SPI (USART 1, Location #1) */
#define SPI_PIN_MOSI        0
#define SPI_PORT_MOSI       gpioPortD
#define SPI_PIN_MISO        1
#define SPI_PORT_MISO       gpioPortD
#define SPI_PIN_CLK       	2
#define SPI_PORT_CLK     	gpioPortD
#define SPI_PIN_CS        	3
#define SPI_PORT_CS      	gpioPortD
#define SPI_PIN_RESET     	4
#define SPI_PORT_RESET    	gpioPortD

#define USART_READ     1
#define USART_WRITE    0

/*hardware SPI*/
void spiInitt(void);
void spiDisable(void);
uint16_t spiTransfer(uint8_t spiaddr, uint8_t spidata);
uint16_t spiReadWord(uint16_t spiaddr);
void spiSendByte(uint8_t spidata);
void spiSendWord(uint16_t spidata);
uint8_t spiGetByte(uint8_t addr);

/*Software SPI*/
void spiInitSoftware(GPIO_Port_TypeDef spiPortMOSI, uint8_t spiPinMOSI,
		GPIO_Port_TypeDef spiPortMISO, uint8_t spiPinMISO,
		GPIO_Port_TypeDef spiPortCLK, uint8_t spiPinCLK,
		GPIO_Port_TypeDef spiPortCS, uint8_t spiPinCS);
uint16_t spiWriteWordSoftware(uint16_t addr, uint16_t data);
uint16_t spiReadWordSoftware(uint16_t addr); //


/**************************************SPI ABSTRACT LAYER ********************************************/
typedef enum
{
  SPI_STATE_RESET      = 0x00,  // SPI not yet initialized or disabled
  SPI_STATE_READY      = 0x01,  // SPI initialized and ready for use
  SPI_STATE_BUSY       = 0x02,  // SPI process is ongoing
  SPI_STATE_BUSY_TX    = 0x03,  // Data Transmission process is ongoing
  SPI_STATE_BUSY_RX    = 0x04,  // Data Reception process is ongoing
  SPI_STATE_BUSY_TX_RX = 0x05,  // Data Transmission and Reception process is ongoing
  SPI_STATE_ERROR      = 0x06   // SPI error state

}SpiStateTypeDef;

typedef enum
{
 STATUS_OK      = 0x00,
 STATUS_ERROR    = 0x01,
 STATUS_BUSY    = 0x02

}StatusTypeDef;




/*
 * @brief SPI handle
 */

typedef struct _SpiHandleTypeDef {
	USART_TypeDef *spiInstance;                                                        //---- part depends on hardware
	USART_InitSync_TypeDef *init;  //SPI commucniaction parameters       			   //---- part depends on hardware
	bool spiModeHwSw;  // by setting this flag , you can implement your own software version of spi  ( USART_TypeDef *spiInstance and USART_InitSync_TypeDef *init are skipped )
	void (*spiSwTransfer)(struct _SpiHandleTypeDef* hspi);  // function pointer on software transfer implementation
	uint8_t *pTxBuffPtr; // pointer to SPI Tx Buffer
	uint16_t txXferSize; // SPI Tx transfer size
	uint16_t txXferCount; // SPI Tx transfer Counter
	uint8_t *pRxBuffPtr; // pointer to SPI Tx Buffer
	uint16_t rxXferSize; // SPI Tx transfer size
	uint16_t rxXferCount; // SPI Tx transfer Counter
	SpiStateTypeDef spiState;  //SPI communication state
	StatusTypeDef (*spiGpioClockInit)(void);        // function pointer on init of  gpio , clock , and interrupts hardware part
	StatusTypeDef (*spiGpioClockDeInit)(void);	    // function pointer on deInit of  gpio , clock , and interrupts hardware part
	void (*RxISR)(struct _SpiHandleTypeDef* hspi);  // function pointer on Rx ISR if used
	void (*TxISR)(struct _SpiHandleTypeDef* hspi);  // function pointer on Tx ISR if used

} SpiHandleTypeDef;



/**
  * @brief  Transmit and Receive an amount of data in blocking mode
  * @param  hspi: pointer to a Spi_HandleTypeDef structure that contains
  *                the configuration information for SPI module.
  * @param  pTxData: pointer to transmission data buffer
  * @param  pRxData: pointer to reception data buffer to be
  * @param  Size: amount of data to be sent
  * @param  Timeout: Timeout duration
  * @retval status ok/failed
  */
StatusTypeDef spiTransmitReceive(SpiHandleTypeDef *hSpi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout);
StatusTypeDef spiInit(SpiHandleTypeDef *hSpi);
StatusTypeDef spiDeInit(SpiHandleTypeDef *hSpi);
void spiTxRxCompleteCallback(SpiHandleTypeDef *hSpi);
void spiErrorCallback(SpiHandleTypeDef *hSpi);



#ifdef __cplusplus
}
#endif

#endif /* __SPI_H */
