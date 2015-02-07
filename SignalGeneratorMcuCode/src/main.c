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
	spiInit();
	uint16_t i=0;
	while (1) {
		BSP_LedToggle(0);
		BSP_LedToggle(1);
		Delay(1000);
		i=spiReadWord(DOUT_START_DLY);
		SegmentLCD_Number((int)i);
	}
}
