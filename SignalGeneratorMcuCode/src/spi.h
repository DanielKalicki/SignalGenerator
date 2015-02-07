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
/*(USART 1, Location #1) */
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

#define SPI_CS_LOW()        GPIO_PinOutClear(SPI_PORT_CS , SPI_PIN_CS );
#define SPI_CS_HIGH()       GPIO_PinOutSet(SPI_PORT_CS , SPI_PIN_CS );

#define SPI_MOSI_LOW()      GPIO_PinOutClear(SPI_PORT_MOSI, SPI_PIN_MOSI  );
#define SPI_MOSI_HIGH()     GPIO_PinOutSet(SPI_PORT_MOSI, SPI_PIN_MOSI );

#define SPI_SCK_LOW()       GPIO_PinOutClear(SPI_PORT_CLK , SPI_PIN_CLK );
#define SPI_SCK_HIGH()      GPIO_PinOutSet(SPI_PORT_CLK , SPI_PIN_CLK );

#define SPI_RESET_LOW()     GPIO_PinOutClear(SPI_PORT_RESET , SPI_PIN_RESET );
#define SPI_RESET_HIGH()    GPIO_PinOutSet(SPI_PORT_RESET , SPI_PIN_RESET );

void spiInit(void);
void spiDisable(void);
uint16_t spiTransfer(uint8_t spiaddr, uint8_t spidata);
uint16_t spiReadWord(uint16_t spiaddr);
void spiSendByte(uint8_t spidata);
void spiSendWord(uint16_t spidata);
uint8_t spiGetByte(uint8_t addr);

uint16_t spiReadWordSoftware(uint16_t addr); //


#ifdef __cplusplus
}
#endif

#endif /* __SPI_H */
