/**************************************************************************//**
 * @file
 * @brief main SIgnal Generator Uszko_Kalicki
 * @version 0.01
 * @date 25.01.2015
 ******************************************************************************
 ********************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_timer.h"
#include "AD9106.h"
#include "em_emu.h"
#include "bsp.h"
#include "bsp_trace.h"
#include "../drivers/segmentlcd.h"
#include "spi.h"
//#include "oldSPFD5408.h"
#include "SPFD5408.h"
#include "bitmaps.h"
#include "ADS7843.h"
#include "../FreeRtos/FreeRTOS.h"
#include "../FreeRtos/task.h"
#include "../FreeRtos/queue.h"
#include "../FreeRtos/semphr.h"
#include "../FreeRtos/croutine.h"
#include "../FreeRtos/FreeRTOSConfig.h"
#include "../drivers/sleep.h"
#include "../drivers/usb/cdc.h"

#define AD9106_DEMO_ENABLED 1
#define LCD_DEMO_ENABLED 0
#define USB_DEMO_ENABLED 0
#define FREE_RTOS_DEMO_ENABLED 0
#define MAIN_APP 0

#if !FREE_RTOS_DEMO_ENABLED
#include "utils.h"
#endif
//********************************RTOS****************************************
#if FREE_RTOS_DEMO_ENABLED

#define STACK_SIZE_FOR_TASK    (configMINIMAL_STACK_SIZE + 10)
#define TASK_PRIORITY          (tskIDLE_PRIORITY + 1)

typedef struct {
	/* Delay between blink of led */portTickType delay;
	/* Number of led */
	int ledNo;
}TaskParams_t;

static void ledBlinkTask(void *pParameters) {
	TaskParams_t * pData = (TaskParams_t*) pParameters;
	const portTickType delay = pData->delay;

	for (;;) {
		BSP_LedToggle(pData->ledNo);
		vTaskDelay(delay);
	}
}

/* Parameters value for taks*/
static TaskParams_t parametersToTask1 = {1000 / portTICK_RATE_MS, 0};
static TaskParams_t parametersToTask2 = {500 / portTICK_RATE_MS, 1};

#endif

#if LCD_DEMO_ENABLED||MAIN_APP

volatile bool mADS7843ScreenTouched = false;

#endif

int main(void) {

#if AD9106_DEMO_ENABLED

//----------------------- AD9106  working tests -----------------------
#if 0 //1 FOR DEVBOARD
	CHIP_Init();
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);//32MHZ
	//BSP_TraceProfilerSetup();
	CMU_ClockEnable(cmuClock_HFPER, true);
	BSP_LedsInit();
	BSP_LedSet(0);
	BSP_LedSet(1);
	utilsInit();
	SegmentLCD_Init(false);
	SegmentLCD_AllOff();
	SegmentLCD_Number(100);
	//SPFD5408Init();
	//ADS7843Init();
	AD9106Init();
	uint16_t i = 0;
	uint16_t counter = 0;
	while (1) {
		BSP_LedToggle(0);
		BSP_LedToggle(1);
		AD9106Test();
	}
#endif

	CMU_OscillatorEnable(cmuOsc_HFRCO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO); //32MHZ
	CMU_ClockEnable(cmuClock_HFPER, true);
	utilsInit();
	AD9106Init();
	uint16_t i = 0;
	uint16_t counter = 0;
	while (1) {
		AD9106Test();
	}
#elif LCD_DEMO_ENABLED
	CHIP_Init();
	//CMU_OscillatorEnable(cmuOsc_HFRCO, true, true);
	CMU_OscillatorEnable(cmuOsc_HFRCO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO); //32MHZ
	CMU_ClockEnable(cmuClock_HFPER, true);
	//----------------------- SPFD5408 first working tests -----------------------
	//CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	//CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); //32MHZ
	//BSP_TraceProfilerSetup();
	//CMU_ClockEnable(cmuClock_HFPER, true);
	/*BSP_LedsInit();
	 BSP_LedSet(0);
	 BSP_LedSet(1);*/
	utilsInit();
#if 0
	// DEMO
	CLOCKS_ENABLE();
	while (1) {
		/*TFT_PIN_D0_OUTPUT();
		 TFT_PIN_D1_OUTPUT();
		 TFT_PIN_D2_OUTPUT();
		 TFT_PIN_D3_OUTPUT();
		 TFT_PIN_D4_OUTPUT();
		 TFT_PIN_D5_OUTPUT();
		 TFT_PIN_D6_OUTPUT();
		 TFT_PIN_D7_OUTPUT();

		 TFT_PIN_D8_OUTPUT();
		 TFT_PIN_D9_OUTPUT();
		 TFT_PIN_D10_OUTPUT();
		 TFT_PIN_D11_OUTPUT();
		 TFT_PIN_D12_OUTPUT();
		 TFT_PIN_D13_OUTPUT();
		 TFT_PIN_D14_OUTPUT();
		 TFT_PIN_D15_OUTPUT();

		 CS_OUTPUT();
		 CS_HIGH();

		 RS_OUTPUT();
		 RS_HIGH();

		 WR_OUTPUT();
		 WR_HIGH();

		 RD_OUTPUT();
		 RD_HIGH();
		 */

		ADS7843_CS_OUTPUT();
		ADS7843_CS_HIGH();

		ADS7843_INT_OUTPUT();
		ADS7843_INT_HIGH();

		ADS7843_CLK_OUTPUT();
		ADS7843_CLK_HIGH() ;

		ADS7843_MOSI_OUTPUT();
		ADS7843_MOSI_HIGH();

		ADS7843_MISO_OUTPUT();
		 ADS7843_MISO_HIGH();

		Delay(1000);
		/*
		 TFT_PIN_D0_INPUT();
		 TFT_PIN_D1_INPUT();
		 TFT_PIN_D2_INPUT();
		 TFT_PIN_D3_INPUT();
		 TFT_PIN_D4_INPUT();
		 TFT_PIN_D5_INPUT();
		 TFT_PIN_D6_INPUT();
		 TFT_PIN_D7_INPUT();
		 TFT_PIN_D8_INPUT();
		 TFT_PIN_D9_INPUT();
		 TFT_PIN_D10_INPUT();
		 TFT_PIN_D11_INPUT();
		 TFT_PIN_D12_INPUT();
		 TFT_PIN_D13_INPUT();
		 TFT_PIN_D14_INPUT();
		 TFT_PIN_D15_INPUT();

		 CS_LOW();
		 RS_LOW();
		 WR_LOW();
		 RD_LOW();
		 */
		ADS7843_CS_LOW();
		ADS7843_INT_LOW();
		ADS7843_CLK_LOW();
		ADS7843_MOSI_LOW();
		ADS7843_MISO_LOW() ;
		Delay(1000);
	}
#endif
	SPFD5408init();
	/*SegmentLCD_Init(false);
	 SegmentLCD_AllOff();
	 SegmentLCD_Number(100);
	 */
	ADS7843Init();
	//USB for Debug
	/*
	 if (CDC_Init()) { // Initialize the communication class device.
	 SegmentLCD_Write("donea");
	 }

	 else {
	 SegmentLCD_Write("fail");
	 while (1)
	 ;
	 }
	 */
	uint16_t i = 0;
	uint16_t counter = 0;
	char buf[25] = { 0 };

	//while (1) {
	for (int i = 1; i < 318; i++) {
		SPFD5408drawPixel(i, 119 + (sin(((i * 1.13) * 3.14) / 180) * 95),
				BLACK);
		Delay(1);

	}
	/*
	 SPFD5408printChar('H', 10, 10, BLACK);
	 SPFD5408printChar('E', 25, 10, BLACK);
	 SPFD5408printChar('L', 40, 10, BLACK);
	 SPFD5408printChar('L', 55, 10, BLACK);
	 SPFD5408printChar('O', 70, 10, BLACK);
	 SPFD5408printChar('!', 85, 10, BLACK);
	 SPFD5408print("*TFTLibrary- TEST*", 10, 50, 0, RED);
	 Delay(2000);
	 */
	SPFD5408drawBitmap(11, 10, 299, 210, mainPage, 1);

	/*Delay(2000);
	 SPFD5408clrScr();
	 //SPFD5408drawBitmap(5, 5, 199, 199, thunder, 1);

	 SPFD5408fillCircle(40 + (1 * 20), 40 + (1 * 20), 30, GREEN);
	 Delay(2000);
	 SPFD5408fillRect(100, 15, 200, 200, RED);
	 Delay(2000);
	 SPFD5408fillRoundRect(190 - (1 * 20), 30 + (1 * 20), 250 - (1 * 20),
	 90 + (1 * 20), BLUE);

	 while (1) {
	 i++;
	 SPFD5408drawLine(i, 50, 200, 100, BLACK);
	 SPFD5408drawLine(i, 200, 100, 200, RED);
	 Delay(1000);
	 if (i == 50)
	 break;
	 }
	 }
	 */
	while (1) {
		i++;
		if (mADS7843ScreenTouched) {
			//SegmentLCD_Number((int) (getCoordinates().x));
			//SPFD5408DrawString(getCoordinates().x, getCoordinates().y, "AA", 1, BLACK);
			//sniprintf(buf, 25, "X:%d,Y:%d\r\n", getCoordinates().x,
			//.,		getCoordinates().y);
			//USB_DEBUG_PUTS(buf);
			SPFD5408drawPixel(getCoordinates().x/100,
					getCoordinates().y/100,RED);
			//BSP_LedToggle(0);
			SPFD5408print(buf, 10, 50, 0, RED);
		}/* else
		 SegmentLCD_Number(i);
		 */
	}

#elif USB_DEMO_ENABLED
	BSP_TraceProfilerSetup();
	CHIP_Init();
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); //32MHZ

	/* Initialize LCD driver */
	SegmentLCD_Init(false);
	SegmentLCD_Write("usbcomp");
	SegmentLCD_Symbol(LCD_SYMBOL_GECKO, true);

	/* Initialize LED driver */
	BSP_LedsInit();

	if (CDC_Init()) { /* Initialize the communication class device. */
		SegmentLCD_Write("donea");
	}

	else {
		SegmentLCD_Write("fail");
		while (1)
		;
	}
	/*
	 // When using a debugger it is practical to uncomment the following three
	 // lines to force host to re-enumerate the device.

	 USBD_Disconnect();
	 USBTIMER_DelayMs(1000);
	 USBD_Connect();
	 */
	uint8_t buf[100] = {0};

	for (;;) {
		if (usbReadData(buf, 0)) {
			SegmentLCD_Write("gotten");
			USB_DEBUG_PUTS((char*)buf);
		} else
		SegmentLCD_Write("None");
	}
#elif FREE_RTOS_DEMO_ENABLED
	CHIP_Init();
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); //32MHZ
	BSP_TraceProfilerSetup();
	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000))
	while (1)
	;
	CMU_ClockEnable(cmuClock_HFPER, true);
	//********************************RTOS****************************************
	/* Initialize SLEEP driver, no calbacks are used */
	SLEEP_Init(NULL, NULL );
	/*Create two task for blinking leds*/
	xTaskCreate(ledBlinkTask, (const char * const ) "Led1", STACK_SIZE_FOR_TASK,
			&parametersToTask1, TASK_PRIORITY, NULL);
	xTaskCreate(ledBlinkTask, (const char * const ) "Led2", STACK_SIZE_FOR_TASK,
			&parametersToTask2, TASK_PRIORITY, NULL);

	/*Start FreeRTOS Scheduler*/
	vTaskStartScheduler();

#elif MAIN_APP

	CHIP_Init();
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); //48MHZ
	//BSP_TraceProfilerSetup();
	CMU_ClockEnable(cmuClock_HFPER, true);

	BSP_LedsInit();
	BSP_LedSet(0);
	BSP_LedSet(1);
	utilsInit();
	SegmentLCD_Init(false);
	SegmentLCD_AllOff();
	SegmentLCD_Number(100);
	//SPFD5408Init();
	_SPFD5408Init();
	ADS7843Init();
	drawBitmap(11,10,299,210,mainPage,1);
	for (;;) {

	}
#endif

}

