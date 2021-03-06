#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_i2c.h"
#include "em_emu.h"
#include <stdio.h>
#include "uart_connection.h"
#include "i2c_connection.h"

//------DEFINES-----
#define LED_LOAD_PORT	gpioPortC
#define LED_LOAD_PIN	1
#define LED_IN_PORT		gpioPortB
#define LED_IN_PIN		7
#define LED_CLK_PORT	gpioPortB
#define LED_CLK_PIN		8

#define BUT_LOAD_PORT	gpioPortB
#define BUT_LOAD_PIN	11
#define BUT_IN_PORT		gpioPortB
#define BUT_IN_PIN		13
#define BUT_CLK_PORT	gpioPortB
#define BUT_CLK_PIN		14

#define LED_LOAD_HIGH() 	GPIO_PinOutSet  (LED_LOAD_PORT,LED_LOAD_PIN)
#define LED_LOAD_LOW() 		GPIO_PinOutClear(LED_LOAD_PORT,LED_LOAD_PIN)
#define LED_IN_HIGH() 		GPIO_PinOutSet  (LED_IN_PORT,  LED_IN_PIN)
#define LED_IN_LOW() 		GPIO_PinOutClear(LED_IN_PORT,  LED_IN_PIN)
#define LED_CLK_HIGH() 		GPIO_PinOutSet  (LED_CLK_PORT, LED_CLK_PIN)
#define LED_CLK_LOW() 		GPIO_PinOutClear(LED_CLK_PORT, LED_CLK_PIN)

#define BUT_LOAD_HIGH() 	GPIO_PinOutSet  (BUT_LOAD_PORT,BUT_LOAD_PIN)
#define BUT_LOAD_LOW() 		GPIO_PinOutClear(BUT_LOAD_PORT,BUT_LOAD_PIN)
#define BUT_IN_READ() 		GPIO_PinInGet   (BUT_IN_PORT,  BUT_IN_PIN)
#define BUT_CLK_HIGH() 		GPIO_PinOutSet  (BUT_CLK_PORT, BUT_CLK_PIN)
#define BUT_CLK_LOW() 		GPIO_PinOutClear(BUT_CLK_PORT, BUT_CLK_PIN)

//------INIT-----
void initOscillators(void){
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(cmuClock_GPIO, true);
}
void initShiftRegisters(){
	GPIO_PinModeSet(LED_LOAD_PORT, 	LED_LOAD_PIN, 	gpioModePushPull, 1);
	GPIO_PinModeSet(LED_IN_PORT, 	LED_IN_PIN, 	gpioModePushPull, 1);
	GPIO_PinModeSet(LED_CLK_PORT, 	LED_CLK_PIN, 	gpioModePushPull, 1);

	GPIO_PinModeSet(BUT_LOAD_PORT, 	BUT_LOAD_PIN, 	gpioModePushPull, 1);
	GPIO_PinModeSet(BUT_IN_PORT, 	BUT_IN_PIN, 	gpioModeInput,    1);
	GPIO_PinModeSet(BUT_CLK_PORT, 	BUT_CLK_PIN, 	gpioModePushPull, 1);
}

//-------LEDS-------
enum eLeds{
	SIN_LED_R = 0,
	SIN_LED_G,
	SIN_LED_B,
	SQUARE_LED_R,
	SQUARE_LED_G,
	SQUARE_LED_B,
	RAMP_LED_R,
	RAMP_LED_G,
	RAMP_LED_B,
	PULSE_LED_R,
	PULSE_LED_G,
	PULSE_LED_B,
	NOISE_LED_R,
	NOISE_LED_G,
	NOISE_LED_B,
	ARB_LED_R,
	ARB_LED_G,
	ARB_LED_B,

	FREQ_LED,
	AMP_LED,
	UTILITY_LED,
	PHASE_LED,
	OFFSET_LED,
	QUEST_LED,
	CH1_LED,
	CH2_LED,
	EXT_TRIG_LED,
	TRIG_OPT_LED,
	CH1_CH2_OPT_LED
};

#define LED_SIZE 32
uint8_t leds[LED_SIZE];

void updateLeds(){
	LED_CLK_LOW();
	for (int i=LED_SIZE-1;i>=0;i--){
		LED_CLK_LOW();
		if(leds[i]>0)
			LED_IN_HIGH();
		else{
			LED_IN_LOW();
		}
		LED_CLK_HIGH();
	}
	LED_CLK_LOW();

	LED_LOAD_LOW();
	LED_LOAD_HIGH();
}

void updateLedsToggle(){
	LED_CLK_LOW();
	for (int i=LED_SIZE-1;i>=0;i--){
		LED_CLK_LOW();
		if(leds[i])
			LED_IN_HIGH();
		else{
			LED_IN_LOW();
		}
		LED_CLK_HIGH();
	}
	LED_CLK_LOW();

	LED_LOAD_LOW();
	LED_LOAD_HIGH();
}

//------BUTTONS------
enum eButton{
	SIN_BUTTON=0,
	SQUARE_BUTTON,
	RAMP_BUTTON,
	NOISE_BUTTON,
	ARB_BUTTON,
	AMPLITUDE_BUTTON,
	FREQUENCY_BUTTON,
	UTILITY_BUTTON,
	PHASE_BUTTON,
	OFFSET_BUTTON,
	QUEST_BUTTON,
	TRIG_OPT_BUTTON,
	EXT_TRIG_BUTTON,
	CH2_BUTTON,
	CH1_BUTTON,
	CANCEL_BUTTON,
	SIX_BUTTON,
	FIVE_BUTTON,
	FOUR_BUTTON,
	THREE_BUTTON,
	TWO_BUTTON,
	ONE_BUTTON,
	DOT_BUTTON,
	SEVEN_BUTTON,
	EIGHT_BUTTON,
	NINE_BUTTON,
	OK_BUTTON,
	RIGHT_BUTTON,
	LEFT_BUTTON,
	ZERO_BUTTON,
	SIGN_BUTTON,
	DISP_ESC_BUTTON,
	DISP_1_BUTTON,
	DISP_2_BUTTON,
	DISP_3_BUTTON,
	DISP_4_BUTTON,
	DISP_5_BUTTON,
	CH1_CH2_OPT_BUTTON
};

#define BUT_SIZE 40
uint8_t buttons[BUT_SIZE];

void readButtons(){
	//the read data is save in buttons[] array.
	BUT_LOAD_HIGH();

	for(uint8_t i=0;i<BUT_SIZE;i++){
		BUT_CLK_LOW();

		if (!BUT_IN_READ())	//DATA = 0 button is pressed
			buttons[i]=1;
		else
			buttons[i]=0;

		BUT_CLK_HIGH();
	}
	BUT_LOAD_LOW();
}
void printButtons(){
	for (int i=0;i<BUT_SIZE;i++){
		char buff[30];
		sprintf(buff,"%d",i);
		uart_sendText(buff);
		uart_sendText(":");
		if(buttons[i]) uart_sendText("##");
		else uart_sendText(" ");
		uart_sendChar('\t');
	}
	uart_sendChar('\n');
}

//----ENCODER----
uint8_t encoder[4];

void readEncoder(){

}

//----TEST FUN----
void delayF() {
	long int i=0;
	for(;i<120001L;++i) {
	  if(i==120000L)
		  GPIO_PinOutSet(gpioPortF, 2);
	  if(i==60000L)
		  GPIO_PinOutClear(gpioPortF, 2);
	}
}

void test(){
	readButtons();

	printButtons();

	static uint8_t counter=0;
	counter++;
	if(counter==LED_SIZE) counter=0;

	for (int i=0;i<LED_SIZE;i++){
		if (counter==i)
			leds[i]=1;
		else
			leds[i]=0;
	}
	updateLedsToggle();

	for (int i=0;i<1;i++){
		delayF();
	}
}

//------MAIN------
int main(void) {

  CHIP_Init();
  initOscillators();
  initShiftRegisters();

  for (int i=0;i<10;i++) i2c_registers[i]=0;

  /*initUART();
  uart_sendText("Front pannel startup...");
  uart_sendText("done\n");*/

  while (1) {
	  //registers 0-5 contains buttons status
	  readButtons();
	  for (int i=0;i<5;i++){
		  uint8_t data=0;
		  for (int ii=0;ii<8;ii++){
			  data+=(buttons[i+ii]<<ii);
		  }
		  i2c_registers[i]=data;
	  }
	  //registers 6-10 reads led status and refresh the front panel
	  for (int i=0;i<5;i++){
		  for (int ii=0;ii<8;ii++){
			  if(i2c_registers[i]&(1<<ii)){
				  leds[i*8+ii]=1;
			  }
			  else {
				  leds[i*8+ii]=0;
			  }
		  }
	  }
	  //registers 11-14 contain encoder number
	  readEncoder();
	  i2c_registers[11]=encoder[0];
	  i2c_registers[12]=encoder[1];
	  i2c_registers[13]=encoder[2];
	  i2c_registers[14]=encoder[3];
  }
}
