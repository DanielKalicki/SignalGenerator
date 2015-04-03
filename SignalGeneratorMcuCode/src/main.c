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
#include "em_timer.h"
#include "AD9106.h"
#include "em_emu.h"
#include "bsp.h"
#include "bsp_trace.h"
#include "../drivers/segmentlcd.h"
#include "spi.h"
#include "SPFD5408.h"
#include "ADS7843.h"
#include "../FreeRtos/FreeRTOS.h"
#include "../FreeRtos/task.h"
#include "../FreeRtos/queue.h"
#include "../FreeRtos/semphr.h"
#include "../FreeRtos/croutine.h"
#include "../FreeRtos/FreeRTOSConfig.h"
#include "../drivers/sleep.h"
#include "../drivers/usb/cdc.h"

#define AD9106_DEMO_ENABLED 0
#define LCD_DEMO_ENABLED 1
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

#if LCD_DEMO_ENABLED

volatile bool mADS7843ScreenTouched = false;

#endif

int main(void) {

#if AD9106_DEMO_ENABLED
	CHIP_Init();
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); //32MHZ
	BSP_TraceProfilerSetup();
	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000))
		while (1)
			;
	CMU_ClockEnable(cmuClock_HFPER, true);
//----------------------- AD9106  working tests -----------------------
	BSP_LedsInit();
	BSP_LedSet(0);
	SegmentLCD_Init(false);
	SegmentLCD_AllOff();
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
	uint16_t i = 0;
	uint16_t counter = 0;
	while (1) {
		BSP_LedToggle(0);
		BSP_LedToggle(1);
		AD9106_test();
	}
#elif LCD_DEMO_ENABLED
	CHIP_Init();
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); //32MHZ
	//BSP_TraceProfilerSetup();
	CMU_ClockEnable(cmuClock_HFPER, true);
	//----------------------- SPFD5408 first working tests -----------------------
	BSP_LedsInit();
	BSP_LedSet(0);
	BSP_LedSet(1);
	utilsInit();
	SegmentLCD_Init(false);
	SegmentLCD_AllOff();
	SegmentLCD_Number(100);
	//SPFD5408Init();
	ADS7843Init();
  //USB for Debug

	if (CDC_Init()) { // Initialize the communication class device.
		SegmentLCD_Write("donea");
	}

	else {
		SegmentLCD_Write("fail");
		while (1)
		;
	}

	uint16_t i = 0;
	uint16_t counter = 0;
	char buf[25] = {0};
	while (1) {
		i++;
		if (mADS7843ScreenTouched) {
			SegmentLCD_Number((int) (getCoordinates().x));
			//SPFD5408DrawString(getCoordinates().x, getCoordinates().y, "AA", 1, BLACK);
			sniprintf(buf, 25, "X:%d , Y:%d\r\n", getCoordinates().x, getCoordinates().y);
			USB_DEBUG_PUTS(buf);
			//SPFD5408SetPixel(getCoordinates().x, getCoordinates().y, BLACK);
			BSP_LedToggle(0);
			mADS7843ScreenTouched = false;
		} else
		SegmentLCD_Number(i);
		Delay(1000);
		//SPFD5408PaintScreenBackground(colors[i%10]);
		//counter = snprintf(buf, 10, "N %d", i);
		//if (counter != -1)
		//SPFD5408DrawString(100, 100, buf, 3, BLACK);
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
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); //32MHZ
	BSP_TraceProfilerSetup();
	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000))
	while (1)
	;
	CMU_ClockEnable(cmuClock_HFPER, true);

	for (;;) {

	}
#endif

}

