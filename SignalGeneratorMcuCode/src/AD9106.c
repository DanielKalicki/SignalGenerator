/*
 * AD9106.c
 *
 *  Created on: 25-01-2015
 *      Author: lukasz
 *      documentation: http://www.analog.com/en/digital-to-analog-converters/high-speed-da-converters/ad9106/products/product.html?src=ad9106.pdf
 */
#include "AD9106.h"


bool setConfig(void){


	return true;
}


bool writeReg(uint16_t regAddress, uint16_t dataBitMask, uint16_t data)
{

    uint16_t tempVal;
    //if(!read(regAddress,&tempVal,1)) return false;   TODO , wrappers for SPI hardware implementation
    tempVal&=~(dataBitMask);
    tempVal|= data<<getShiftValue(dataBitMask);
    //return write(regAddress, &tempVal,1);

}

bool readReg(uint16_t regAddress, uint16_t dataBitMask, uint16_t *data)
{

    uint16_t tempVal;
   // if(!read(regAddress,&tempVal,1)) return false;
    tempVal&=dataBitMask;
    tempVal>>=getShiftValue(dataBitMask);
    *data= tempVal;
    return true;
}



void AD9106_test(void) {
	static uint16_t counter = 0;
	counter += 1000;
	if (counter >= 30000)
		counter = 0;
	uint16_t i = 0;
	spiWriteWordSoftware((uint16_t) PAT_TYPE, 0);
	Delay(1);

	//spiWriteWordSoftware((uint16_t)WAV4_3CONFIG,0x2121);Delay(1);//noise output test
	spiWriteWordSoftware((uint16_t) WAV4_3CONFIG, 0x1111);
	Delay(1); //sawtooth test

	spiWriteWordSoftware((uint16_t) DAC4_CST, 0xA200);
	Delay(1);
	spiWriteWordSoftware((uint16_t) DAC4_DGAIN, 0xA000);
	Delay(1);
	spiWriteWordSoftware((uint16_t) DAC4RSET, 0x8002);
	Delay(1);
	spiWriteWordSoftware((uint16_t) DACxRANGE, 0x00A0);
	Delay(1);
	spiWriteWordSoftware((uint16_t) PAT_TIMEBASE, 0x0000);
	Delay(1);
	spiWriteWordSoftware((uint16_t) PAT_PERIOD, 0x0100);
	Delay(1);
	spiWriteWordSoftware((uint16_t) PAT_STATUS, 0x0001);
	Delay(1);
	spiWriteWordSoftware((uint16_t) RAMUPDATE, 0x0001);
	Delay(1);

	//sawtooth configuration
	spiWriteWordSoftware((uint16_t) SAW4_3CONFIG, 0x0808);
	Delay(1);

	Delay(500);
	i = spiReadWordSoftware((uint16_t) CFG_ERROR);
	i = spiReadWordSoftware((uint16_t) PAT_STATUS);
	SegmentLCD_Number(i);

}

