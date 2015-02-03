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
#include "SPFD5408.h"

int main(void) {

	CHIP_Init();

	BSP_TraceProfilerSetup();

	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000))
		while (1)
			;
	SPFD5408Init();
	BSP_LedsInit();
	BSP_LedSet(0);
	SPFD5408DrawString(100, 100, "TEST", 5, RED);
	while (1) {
		BSP_LedToggle(0);
		BSP_LedToggle(1);
		Delay(1000);
	}
}
