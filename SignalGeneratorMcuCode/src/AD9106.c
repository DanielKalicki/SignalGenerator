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

