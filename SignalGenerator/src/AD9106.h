/*
 * AD9106.h
 *
 *  Created on: 25-01-2015
 *      Author: lukasz
 *      documentation: http://www.analog.com/en/digital-to-analog-converters/high-speed-da-converters/ad9106/products/product.html?src=ad9106.pdf
 */

#ifndef AD9106_H_
#define AD9106_H_

#include "em_usart.h"

typedef enum {
	SPICONFIG_ADDR,
	POWERCONFIG,
	CLOCKCONFIG,
	REFADJ,
	DAC4AGAIN,
	DAC3AGAIN,
	DAC2AGAIN,
	DAC1AGAIN,
	DACxRANGE,
	DAC4RSET,
	DAC3RSET,
	DAC2RSET,
	DAC1RSET,
	CALCONFIG,
	COMPOFFSET,
	RAMUPDATE,
	PAT_STATUS,
	PAT_TYPE,
	PATTERN_DLY,
	DAC4DOF,
	DAC3DOF,
	DAC2DOF,
	DAC1DOF,
	WAV4_3CONFIG,
	WAV2_1CONFIG,
	PAT_TIMEBASE,
	PAT_PERIOD,
	DAC4_3PATx,
	DAC2_1PATx,
	DOUT_START_DLY,
	DOUT_CONFIG,
	DAC4_CST,
	DAC3_CST,
	DAC2_CST,
	DAC1_CST,
	DAC4_DGAIN,
	DAC3_DGAIN,
	DAC2_DGAIN,
	DAC1_DGAIN,
	SAW4_3CONFIG,
	SAW2_1CONFIG,
	DDS_TW32 = 0x3E,
	DDS_TW1,
	DDS4_PW,
	DDS3_PW,
	DDS2_PW,
	DDS1_PW,
	TRIG_TW_SEL,
	DDSx_CONFIG,
	TW_RAM_CONFIG = 0x47,
	START_DLY4 = 0x50,
	START_ADDR4,
	STOP_ADDR4,
	DDS_CYC4,
	START_DLY3,
	START_ADDR3,
	STOP_ADDR3,
	DDS_CYC3,
	START_DLY2,
	START_ADDR2,
	STOP_ADDR2,
	DDS_CYC2,
	START_DLY1,
	START_ADDR1,
	STOP_ADDR1,
	DDS_CYC1,
	CFG_ERROR,
	SRAMDATA = 0x6000,   //0x6000 to 0x6FFF

} AD9106RegAddress;

//Proper BITMASKS for each register, allows us to write/ read to/from device in easy way , not overwriting whole register
//4564	    112	     36	   4712	   1268	SignalGenerator.axf
typedef enum {

	LSBFIRST = 0x8000,
	SPI3WIRE = 0x4000,
	RESET = 0x2000,
	DOUBLESPI = 0x1000,
	SPI_DRV = 0x0800,
	DOUT_EN = 0x0400,
	DOUT_ENM = 0x0020,
	SPI_DRVM = 0x0010,
	DOUBLESPIM = 0x0008,
	RESETM = 0x0004,
	SPI3WIREM = 0x0002,
	LSBFIRSTM = 0x0001
} SPICONFIG_Reg;

typedef enum {

	CLK_LDO_STAT = 0x0800,  //Read only
	DIG1_LDO_STAT = 0x0400, //Read only
	DIG2_LDO_STAT = 0x0200, //Read only
	PDN_LDO_CLK = 0x0100,
	PDN_LDO_DIG1 = 0x0080,
	PDN_LDO_DIG2 = 0x0040,
	REF_PDN = 0x0020,
	REF_EXT = 0x0010,
	DAC1_SLEEP = 0x0008,
	DAC2_SLEEP = 0x0004,
	DAC3_SLEEP = 0x0002,
	DAC4_SLEEP = 0x0001
} POWERCONFIG_Reg;

typedef enum {

	DIS_CLK1 = 0x0800,
	DIS_CLK2 = 0x0400,
	DIS_CLK3 = 0x0200,
	DIS_CLK4 = 0x0100,
	DIS_DCLK = 0x0080,
	CLK_SLEEP = 0x0040,
	CLK_PDN = 0x0020,
	EPS = 0x0010,
	DAC1_INV_CLK = 0x0008,
	DAC2_INV_CLK = 0x0004,
	DAC3_INV_CLK = 0x0002,
	DAC4_INV_CLK = 0x0001
} CLOCKCONFIG_Reg;

typedef enum {
	BGDR = 0x003F
} REFADJ_Reg;

typedef enum {
	DACx_GAIN_CAL = 0x7F00,  //Read only
	DACx_GAIN = 0x007F
} DACxAGAIN_Reg;

typedef enum {
	DAC4_GAIN_RNG = 0xC0,
	DAC3_GAIN_RNG = 0x30,
	DAC2_GAIN_RNG = 0x0C,
	DAC1_GAIN_RNG = 0x03
} DACxRANGE_Reg;

typedef enum {
	DACx_RSET_EN = 0x8000, DACx_RSET_CAL = 0x1F00, DACx_RSET = 0x1F
} DACxRSET_Reg;

typedef enum {

	COMP_OFFSET_OF = 0x4000,   //Read only
	COMP_OFFSET_UF = 0x2000,   //Read only
	RSET_CAL_OF = 0x1000,      //Read only
	RSET_CAL_UF = 0x0800,      //Read only
	GAIN_CAL_OF = 0x0400,      //Read only
	GAIN_CAL_UF = 0x0200,      //Read only
	CAL_RESET = 0x0100,
	CAL_MODE = 0x0080,         //Read only
	CAL_MODE_EN = 0x0040,
	COMP_CAL_RNG = 0x0030,
	CAL_CLK_EN = 0x0008,
	CAL_CLK_DIV = 0x0007
} CALCONFIG_Reg;

typedef enum {

	COMP_OFFSET_CAL = 0x7F00, //Read only
	CAL_FIN = 0x0002,         //Read only
	START_CAL = 0x0001
} COMPOFFSET_Reg;

typedef enum {
	RAMPUPDATE = 0x0001
} RAMUPDATE_Reg;

typedef enum {

	BUF_READ = 0x0008, MEM_ACCESS = 0x0004, PATTERN = 0x0002,        //Read only
	RUN = 0x0001
} PAT_STATUS_Reg;

typedef enum {
	PATTERN_RPT = 0x0001
} PAT_TYPE_Reg;

typedef enum {
	PATTERN_DELAY = 0xFFFF
} PATTERN_DLY_Reg;

typedef enum {
	DACx_DIG_OFFSET = 0xFFF0
} DACxDOF_Reg;

typedef enum {
	PRESTORE_SEL4 = 0x3000,
	WAVE_SEL4 = 0x0300,
	PRESTORE_SEL3 = 0x30,
	WAVE_SEL3 = 0x03,
} WAV4_3CONFIG_Reg;

typedef enum {
	PRESTORE_SEL2 = 0x3000,
	MASK_DAC4 = 0x0800,
	CH2_ADD = 0x0400,
	WAVE_SEL2 = 0x0300,
	PRESTORE_SEL1 = 0x30,
	MASK_DAC3 = 0x08,
	CH1_ADD = 0x04,
	WAVE_SEL1 = 0x03,
} WAV2_1CONFIG_Reg;

typedef enum {
	HOLD = 0x0F00, PAT_PERIOD_BASE = 0xF0, START_DELAY_BASE = 0x0F,
} PAT_TIMEBASE_Reg;

typedef enum {
	PATTERN_PERIOD = 0xFFFF
} PAT_PERIOD_Reg;

typedef enum {
	DAC4_REPEAT_CYCLE = 0xFF00, DAC3_REPEAT_CYCLE = 0xFF
} DAC4_3PATx_Reg;

typedef enum {
	DAC2_REPEAT_CYCLE = 0xFF00, DAC1_REPEAT_CYCLE = 0xFF
} DAC2_1PATx_Reg;

typedef enum {
	DOUT_START = 0xFFFF,
} DOUT_START_DLY_Reg;

typedef enum {
	DOUT_VAL = 0x20, DOUT_MODE = 0x10, DOUT_STOP = 0x0F
} DOUT_CONFIG_Reg;

typedef enum {
	DACx_CONST = 0xFFF0
} DACx_CST_Reg;

typedef enum {
	DACx_DIG_GAIN = 0xFFF0
} DACx_DGAIN_Reg;

typedef enum {
	SAW_STEP4 = 0xFC00,  //Number of samples per step for DAC4.
	SAW_TYPE4 = 0x0300,  //0- Ramp up saw wave. 1- Ramp down saw wave. 2- Triangle saw wave. 3- No wave, zero.
	SAW_STEP3 = 0x00FC,
	SAW_TYPE3 = 0x0003
} SAW4_3CONFIG_Reg;

typedef enum {
	SAW_STEP2 = 0xFC00,  //Number of samples per step for DAC2.
	SAW_TYPE2 = 0x0300,  //0- Ramp up saw wave. 1- Ramp down saw wave. 2- Triangle saw wave. 3- No wave, zero.
	SAW_STEP1 = 0x00FC,
	SAW_TYPE1 = 0x0003
} SAW2_1CONFIG_Reg;

//TODO  DDS_TW32_Reg  43page


/** Helper method for writeReg and readReg methods
 * @param uint16_t dataBitMask
 * @returns  ShiftValue
 */

inline uint8_t getShiftValue(uint8_t dataBitMask) {
	uint8_t shiftVal = 0;
	while (!(dataBitMask & 1)) {
		dataBitMask >>= 1;
		shiftVal++;
	}
	return shiftVal;
}

bool writeReg(uint16_t regAddress, uint16_t dataBitMask, uint16_t data);

bool readReg(uint16_t regAddress, uint16_t dataBitMask, uint16_t *data);

#endif /* AD9106_H_ */
