/**************************************************************************//**
 * @file
 * @brief main SIgnal Generator Uszko_Kalicki
 * @version 0.01
 * @date 25.01.2015
 ******************************************************************************
 ********************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "utils.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "AD9106.h"
#include "em_emu.h"
#include "bsp.h"
#include "bsp_trace.h"
#include "drivers/segmentlcd.h"
#include "spi.h"
#include "SPFD5408.h"

void AD9106_test(void){
	static uint16_t counter=0;
	counter+=16;
	if(counter >= 64536) counter=0;
	uint16_t i=0;
	//spiWriteWordSoftware((uint16_t)PAT_STATUS,0x0000);Delay(1);
	//spiWriteWordSoftware((uint16_t)DAC4AGAIN,counter);Delay(1); 				//set the gain
	spiWriteWordSoftware((uint16_t)PAT_TYPE,0);Delay(1); 				//pattern runs continiously
	//spiWriteWordSoftware((uint16_t)DAC4DOF,0x0000);Delay(1);			//set the digital offset
	spiWriteWordSoftware((uint16_t)WAV4_3CONFIG,0x2121);Delay(1);			//DAC3 - prestore waveform, DAC3 - constal value held into DAC3 from MSB/LSB register
	spiWriteWordSoftware((uint16_t)DAC4_CST,0x0100);Delay(1);
	spiWriteWordSoftware((uint16_t)DAC4_DGAIN,counter);Delay(1);
	spiWriteWordSoftware((uint16_t)DAC4RSET,0x8007);Delay(1);
	//spiWriteWordSoftware((uint16_t)DACxRANGE,0x00A0);Delay(1);
	spiWriteWordSoftware((uint16_t)PAT_TIMEBASE,0x00F0);Delay(1);
	spiWriteWordSoftware((uint16_t)PAT_PERIOD,0x8000);Delay(1);
	spiWriteWordSoftware((uint16_t)PAT_STATUS,0x0001);Delay(1);

	//sawtooth configuration
	//spiWriteWordSoftware((uint16_t)SAW4_3CONFIG,0xC0C0);Delay(1);


	Delay(500);
	i=spiReadWordSoftware((uint16_t)CFG_ERROR);
	i=spiReadWordSoftware((uint16_t)PAT_STATUS);
	SegmentLCD_Number(i);

}

int main(void) {

	CHIP_Init();

	BSP_TraceProfilerSetup();

	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000))
		while (1)
			;
	CMU_ClockEnable(cmuClock_HFPER, true);
	//SPFD5408Init();
	BSP_LedsInit();
	BSP_LedSet(0);
	SegmentLCD_Init(false);
	SegmentLCD_AllOff();
	//SPFD5408SetOrientation(1) ;//vertical
	//SPFD5408DrawString(100, 100, "AES", 4, BLACK);
	//SPFD5408DrawString(10, 200, "KOL", 3, BLUE);
	SegmentLCD_Number(100);
	//    SegmentLCD_Write(string);
	//spiInit();


	//TESTS !!!!!! software SPIS
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_HFPER, true);
	GPIO_PinModeSet(SPI_PORT_MOSI, SPI_PIN_MOSI, gpioModePushPull, 1);
	GPIO_PinModeSet(SPI_PORT_MISO, SPI_PIN_MISO, gpioModeInput, 0);
	GPIO_PinModeSet(SPI_PORT_CLK, SPI_PIN_CLK, gpioModePushPull, 1);
	// Keep CS high to not activate slave
	GPIO_PinModeSet(SPI_PORT_CS, SPI_PIN_CS, gpioModePushPull, 1);




	uint16_t i=0;
	uint16_t counter=0;
	while (1) {
		BSP_LedToggle(0);
		BSP_LedToggle(1);
		AD9106_test();
	}
}
