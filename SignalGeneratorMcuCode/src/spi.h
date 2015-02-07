
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
#define PIN_SPI_TX        0
#define PORT_SPI_TX       gpioPortD
#define PIN_SPI_RX        1
#define PORT_SPI_RX       gpioPortD
#define PIN_SPI_CLK       2
#define PORT_SPI_CLK      gpioPortD
#define PIN_SPI_CS        3
#define PORT_SPI_CS       gpioPortD
#define PIN_SPI_RESET     4
#define PORT_SPI_RESET    gpioPortD


#define USART_READ     1
#define USART_WRITE    0

#define SPI_CS_LOW()        GPIO_PinOutClear(PORT_SPI_CS , PIN_SPI_CS );
#define SPI_CS_HIGH()       GPIO_PinOutSet(PORT_SPI_CS , PIN_SPI_CS );

#define SPI_MOSI_LOW()      GPIO_PinOutClear(PORT_SPI_MOSI , PIN_SPI_MOSI );
#define SPI_MOSI_HIGH()     GPIO_PinOutSet(PORT_SPI_MOSI , PIN_SPI_MOSI );

#define SPI_SCK_LOW()       GPIO_PinOutClear(PORT_SPI_CLK , PIN_SPI_CLK );
#define SPI_SCK_HIGH()      GPIO_PinOutSet(PORT_SPI_CLK , PIN_SPI_CLK );

#define SPI_RESET_LOW()     GPIO_PinOutClear(PORT_SPI_RESET , PIN_SPI_RESET );
#define SPI_RESET_HIGH()    GPIO_PinOutSet(PORT_SPI_RESET , PIN_SPI_RESET );


void spiInit(void);
void spiDisable(void);
uint16_t spiTransfer(uint8_t spiaddr, uint8_t spidata);
uint16_t spiReadWord(uint16_t spiaddr);
void spiSendByte(uint8_t spidata);
void spiSendWord(uint16_t spidata);
uint8_t spiGetByte(uint8_t addr);


#ifdef __cplusplus
}
#endif

#endif /* __SPI_H */
