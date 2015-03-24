/*
 * utils.c
 *
 *  Created on: 01-02-2015
 *      Author: lukasz
 */
#include "utils.h"


volatile uint32_t msTicks; /* counts 1ms timeTicks */

/**************************************************************************//**
 * @brief SysTick_Handler
 * Interrupt Service Routine for system tick counter
 *****************************************************************************/
/*
void SysTick_Handler(void)
{
  msTicks++;       // increment counter necessary in Delay()
}
*/
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
