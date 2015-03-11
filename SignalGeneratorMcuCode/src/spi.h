#ifndef __SPI_H
#define __SPI_H

#include <stdbool.h>
#include "em_device.h"
#include "em_bitband.h"
#include "em_gpio.h"

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
void spiInit(void);
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


#ifdef __cplusplus
}
#endif

#endif /* __SPI_H */
