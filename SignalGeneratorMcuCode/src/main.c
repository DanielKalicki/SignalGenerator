/**************************************************************************//**
 * @file
 * @brief main SIgnal Generator Uszko_Kalicki
 * @version 0.01
 * @date 25.01.2015
 ******************************************************************************
 ********************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "AD9106.h"
#include "em_emu.h"
#include "bsp.h"
#include "bsp_trace.h"

volatile uint32_t msTicks; /* counts 1ms timeTicks */

void Delay(uint32_t dlyTicks);

/**************************************************************************//**
 * @brief SysTick_Handler
 * Interrupt Service Routine for system tick counter
 *****************************************************************************/
void SysTick_Handler(void)
{
  msTicks++;       /* increment counter necessary in Delay()*/
}

/**************************************************************************//**
 * @brief Delays number of msTick Systicks (typically 1 ms)
 * @param dlyTicks Number of ticks to delay
 *****************************************************************************/
void Delay(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) ;
}

/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{

  CHIP_Init();

  BSP_TraceProfilerSetup();

  if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) while (1) ;

  BSP_LedsInit();
  BSP_LedSet(0);

  while (1)
  {
    BSP_LedToggle(0);
    BSP_LedToggle(1);
    Delay(1000);
  }
}
