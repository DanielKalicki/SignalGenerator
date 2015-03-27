/*
 * utils.c
 *
 *  Created on: 01-02-2015
 *      Author: lukasz
 */
#include "utils.h"
#include "em_system.h"
#include "em_timer.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "bsp.h"

volatile uint32_t msTicks; /* counts 1ms timeTicks */
/* Setting TOP value to CMU_ClockFreqGet(cmuClock_HFPER)/1000 gives us overlow every 1s
 *  HFRCO = 14MHz
 */

#define TIMER0_UP_TOP_VAL 31250//312500//156250//31250//CMU_ClockFreqGet(cmuClock_HFPER)/1000

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

static void timerInit(void){
	CMU_ClockEnable(cmuClock_TIMER0, true);
/*
	TIMER_InitCC_TypeDef timerCCInit =
	  {
	    .cufoa      = timerOutputActionNone,
	    .cofoa      = timerOutputActionToggle,
	    .cmoa       = timerOutputActionNone,
	    .mode       = timerCCModeCompare,
	    .filter     = true,
	    .prsInput   = false,
	    .coist      = false,
	    .outInvert  = false,
	  };

	  // Configure CC channel 0
	  TIMER_InitCC(TIMER0, 0, &timerCCInit);
*/

	  /* Set Top Value */
	  TIMER_TopSet(TIMER0, TIMER0_UP_TOP_VAL);

	  /* Select timer parameters */
	  TIMER_Init_TypeDef timerInit =
	  {
	    .enable     = true,
	    .debugRun   = true,
	    .prescale   = timerPrescale1024,
	    .clkSel     = timerClkSelHFPerClk,
	    .fallAction = timerInputActionNone,
	    .riseAction = timerInputActionNone,
	    .mode       = timerModeUp,
	    .dmaClrAct  = false,
	    .quadModeX4 = false,
	    .oneShot    = false,
	    .sync       = false,
	  };

	  /* Enable overflow interrupt */
	  TIMER_IntEnable(TIMER0, TIMER_IF_OF);

	  /* Enable TIMER0 interrupt vector in NVIC */
	  NVIC_EnableIRQ(TIMER0_IRQn);

	  /* Configure timer */
	  TIMER_Init(TIMER0, &timerInit);


}
void initUtils(void){
	timerInit();

}


/**************************************************************************//**
 * @brief TIMER0_IRQHandler
 * Interrupt Service Routine TIMER0 Interrupt Line
 *****************************************************************************/
void TIMER0_IRQHandler(void) {
	static uint32_t compareValue;
	//SegmentLCD_Number(compareValue++);

	/* Clear flag for TIMER0 overflow interrupt */
	TIMER_IntClear(TIMER0, TIMER_IF_OF);
	BSP_LedToggle(1);
	/*
	 compareValue = TIMER_CaptureGet(TIMER0, 0);
	 // increment duty-cycle or reset if reached TOP value
	 if( compareValue == TIMER_TopGet(TIMER0))
	 TIMER_CompareBufSet(TIMER0, 0, 0);
	 else
	 TIMER_CompareBufSet(TIMER0, 0, ++compareValue);
	 */
}



/**************************************************************************//**
 * @brief USB_DEBUG_PUTS(char *s); -string should be a NULL terminated string
 * sends string onto usb port
 *****************************************************************************/

void USB_DEBUG_PUTS(char *s){
	if(!s)
		return;
    usbWriteData(s, strlen((const char *) s));

}
