#include "SPFD5408.h"
#include "utils.h"
#include "font.h"

static uint8_t DisplayDirect = UP2DOWN;
static void exitStandBy(void);

/*hardware dependent functions */
static void pinWrite(GPIO_Port_TypeDef port, uint8_t pin, uint8_t mask) {

	if (!mask) {
		GPIO_PinOutClear(port, pin);
	} else
		GPIO_PinOutSet(port, pin);
}

static uint16_t pinRead(GPIO_Port_TypeDef port, uint8_t pin) {

	return GPIO_PinOutGet(port, pin);
}

/*hardware dependent functions - end*/

static void allDataPinsInput(void) {
	TFT_PIN_D15_INPUT();
	TFT_PIN_D14_INPUT();
	TFT_PIN_D13_INPUT();
	TFT_PIN_D12_INPUT();
	TFT_PIN_D11_INPUT();
	TFT_PIN_D10_INPUT();
	TFT_PIN_D9_INPUT();
	TFT_PIN_D8_INPUT();
#ifdef _16_BIT_MODE
	TFT_PIN_D7_INPUT();
	TFT_PIN_D6_INPUT();
	TFT_PIN_D5_INPUT();
	TFT_PIN_D4_INPUT();
	TFT_PIN_D3_INPUT();
	TFT_PIN_D2_INPUT();
	TFT_PIN_D1_INPUT();
	TFT_PIN_D0_INPUT();
#endif
}

static void allDataPinsOutput(void) {
	TFT_PIN_D15_OUTPUT();
	TFT_PIN_D14_OUTPUT();
	TFT_PIN_D13_OUTPUT();
	TFT_PIN_D12_OUTPUT();
	TFT_PIN_D11_OUTPUT();
	TFT_PIN_D10_OUTPUT();
	TFT_PIN_D9_OUTPUT();
	TFT_PIN_D8_OUTPUT();
#ifdef _16_BIT_MODE
	TFT_PIN_D7_OUTPUT();
	TFT_PIN_D6_OUTPUT();
	TFT_PIN_D5_OUTPUT();
	TFT_PIN_D4_OUTPUT();
	TFT_PIN_D3_OUTPUT();
	TFT_PIN_D2_OUTPUT();
	TFT_PIN_D1_OUTPUT();
	TFT_PIN_D0_OUTPUT();
#endif
}

static void allDataPinsLow(void) {
	pinWrite(TFT_PORT_D15, TFT_PIN_D15, 0);
	pinWrite(TFT_PORT_D14, TFT_PIN_D14, 0);
	pinWrite(TFT_PORT_D13, TFT_PIN_D13, 0);
	pinWrite(TFT_PORT_D12, TFT_PIN_D12, 0);
	pinWrite(TFT_PORT_D11, TFT_PIN_D11, 0);
	pinWrite(TFT_PORT_D10, TFT_PIN_D10, 0);
	pinWrite(TFT_PORT_D9, TFT_PIN_D9, 0);
	pinWrite(TFT_PORT_D8, TFT_PIN_D8, 0);
#ifdef _16_BIT_MODE
	pinWrite(TFT_PORT_D7, TFT_PIN_D7, 0);
	pinWrite(TFT_PORT_D6, TFT_PIN_D6, 0);
	pinWrite(TFT_PORT_D5, TFT_PIN_D5, 0);
	pinWrite(TFT_PORT_D4, TFT_PIN_D4, 0);
	pinWrite(TFT_PORT_D3, TFT_PIN_D3, 0);
	pinWrite(TFT_PORT_D2, TFT_PIN_D2, 0);
	pinWrite(TFT_PORT_D1, TFT_PIN_D1, 0);
	pinWrite(TFT_PORT_D0, TFT_PIN_D0, 0);
#endif
}

static void pushData(uint16_t data) {
#ifdef _8_BIT_MODE
	data= (uint8_t)data;
	pinWrite(TFT_PORT_D15,TFT_PIN_D15, (data >> 7) & 0x01);
	pinWrite(TFT_PORT_D14,TFT_PIN_D14, (data >> 6) & 0x01);
	pinWrite(TFT_PORT_D13,TFT_PIN_D13, (data >> 5) & 0x01);
	pinWrite(TFT_PORT_D12,TFT_PIN_D12, (data >> 4) & 0x01);
	pinWrite(TFT_PORT_D11,TFT_PIN_D11, (data >> 3) & 0x01);
	pinWrite(TFT_PORT_D10,TFT_PIN_D10, (data >> 2) & 0x01);
	pinWrite(TFT_PORT_D9,TFT_PIN_D9, (data >> 1) & 0x01);
	pinWrite(TFT_PORT_D8,TFT_PIN_D8, data & 0x01);

#else
	pinWrite(TFT_PORT_D15, TFT_PIN_D15, (data >> 15) & 0x01);
	pinWrite(TFT_PORT_D14, TFT_PIN_D14, (data >> 14) & 0x01);
	pinWrite(TFT_PORT_D13, TFT_PIN_D13, (data >> 13) & 0x01);
	pinWrite(TFT_PORT_D12, TFT_PIN_D12, (data >> 12) & 0x01);
	pinWrite(TFT_PORT_D11, TFT_PIN_D11, (data >> 11) & 0x01);
	pinWrite(TFT_PORT_D10, TFT_PIN_D10, (data >> 10) & 0x01);
	pinWrite(TFT_PORT_D9, TFT_PIN_D9, (data >> 9) & 0x01);
	pinWrite(TFT_PORT_D8, TFT_PIN_D8, (data >> 8) & 0x01);
	pinWrite(TFT_PORT_D7, TFT_PIN_D7, (data >> 7) & 0x01);
	pinWrite(TFT_PORT_D6, TFT_PIN_D6, (data >> 6) & 0x01);
	pinWrite(TFT_PORT_D5, TFT_PIN_D5, (data >> 5) & 0x01);
	pinWrite(TFT_PORT_D4, TFT_PIN_D4, (data >> 4) & 0x01);
	pinWrite(TFT_PORT_D3, TFT_PIN_D3, (data >> 3) & 0x01);
	pinWrite(TFT_PORT_D2, TFT_PIN_D2, (data >> 2) & 0x01);
	pinWrite(TFT_PORT_D1, TFT_PIN_D1, (data >> 1) & 0x01);
	pinWrite(TFT_PORT_D0, TFT_PIN_D0, data & 0x01);

#endif
}

static uint16_t getData(void) {
	uint16_t data = 0;
#ifdef _8_BIT_MODE

	Delay(100);
	data |= pinRead(TFT_PORT_D15, TFT_PIN_D15) << 7;
	data |= pinRead(TFT_PORT_D14, TFT_PIN_D14) << 6;
	data |= pinRead(TFT_PORT_D13, TFT_PIN_D13) << 5;
	data |= pinRead(TFT_PORT_D12, TFT_PIN_D12) << 4;
	data |= pinRead(TFT_PORT_D11, TFT_PIN_D11) << 3;
	data |= pinRead(TFT_PORT_D10, TFT_PIN_D10) << 2;
	data |= pinRead(TFT_PORT_D9, TFT_PIN_D9) << 1;
	data |= pinRead(TFT_PORT_D8, TFT_PIN_D8) << 0;
#else
	Delay(100);
	data |= pinRead(TFT_PORT_D15, TFT_PIN_D15) << 15;
	data |= pinRead(TFT_PORT_D14, TFT_PIN_D14) << 14;
	data |= pinRead(TFT_PORT_D13, TFT_PIN_D13) << 13;
	data |= pinRead(TFT_PORT_D12, TFT_PIN_D12) << 12;
	data |= pinRead(TFT_PORT_D11, TFT_PIN_D11) << 11;
	data |= pinRead(TFT_PORT_D10, TFT_PIN_D10) << 10;
	data |= pinRead(TFT_PORT_D9, TFT_PIN_D9) << 9;
	data |= pinRead(TFT_PORT_D8, TFT_PIN_D8) << 8;
	data |= pinRead(TFT_PORT_D7, TFT_PIN_D7) << 7;
	data |= pinRead(TFT_PORT_D6, TFT_PIN_D6) << 6;
	data |= pinRead(TFT_PORT_D5, TFT_PIN_D5) << 5;
	data |= pinRead(TFT_PORT_D4, TFT_PIN_D4) << 4;
	data |= pinRead(TFT_PORT_D3, TFT_PIN_D3) << 3;
	data |= pinRead(TFT_PORT_D2, TFT_PIN_D2) << 2;
	data |= pinRead(TFT_PORT_D1, TFT_PIN_D1) << 1;
	data |= pinRead(TFT_PORT_D0, TFT_PIN_D0) << 0;

#endif
	return data;

}

static void SPFD5408SendCommand(uint16_t index) {
	//CS_LOW()
	RS_LOW();
	RD_HIGH();
	WR_HIGH();
	WR_LOW();
#ifdef _8_BIT_MODE
	pushData(0);
	WR_HIGH()
	;

	WR_LOW()
	;
	pushData(index & 0xff);
#else
	pushData(index);
#endif
	WR_HIGH();
	//CS_HIGH()

}

static void SPFD5408SendData(uint16_t data) {
	//CS_LOW()
	RS_HIGH();
	RD_HIGH();
	WR_LOW();
#ifdef _8_BIT_MODE
	pushData((data & 0xff00) >> 8);
	WR_HIGH()
	;

	WR_LOW()
	;
	pushData(data & 0xff);
#else
	pushData(data);
#endif
	WR_HIGH();
	//CS_HIGH()
}

static void SPFD5408WriteData(uint16_t data) {
	CS_LOW();
	SPFD5408SendData(data);
	CS_HIGH();
}

static void SPFD5408WriteCommand(uint16_t data) {
	CS_LOW();
	SPFD5408SendCommand(data);
	CS_HIGH();
}

/************************************************************************
 * void SPFD5408WriteRegister(uint16_t index, uint16_t data)
 **                                                                    **
 ** CS       ----\__________________________________________/-------  **
 ** RS       ------\____________/-----------------------------------  **
 ** RD       -------------------------------------------------------  **
 ** WR       --------\_______/--------\_____/-----------------------  **
 ** DB[15:0] ---------[index]----------[data]-----------------------  **
 **                                                                    **
 ************************************************************************/
static void SPFD5408WriteRegister(uint16_t index, uint16_t data) {
	CS_LOW();
	SPFD5408SendCommand(index);
	SPFD5408SendData(data);
	CS_HIGH();

}
/***********************************************************************
 * uint16_t SPFD5408ReadRegister(uint16_t index)      (16BIT)          **
 **                                                                    **
 ** nCS       ----\__________________________________________/-------  **
 ** RS        ------\____________/-----------------------------------  **
 ** nRD       -------------------------\_____/---------------------  **
 ** nWR       --------\_______/--------------------------------------  **
 ** DB[15:0]  ---------[index]----------[data]-----------------------  **
 **                                                                    **
 ************************************************************************/
static uint16_t SPFD5408ReadRegister(uint16_t index) {
	uint16_t data = 0;

	CS_LOW();
	RS_LOW();

	WR_LOW();
#ifdef _8_BIT_MODE
	pushData(0);
	WR_HIGH()
	;

	WR_LOW()
	;
	pushData(index & 0xff);
#else
	pushData(index);
#endif
	WR_HIGH();

	allDataPinsInput();
	allDataPinsLow();
	RS_HIGH();

	RD_LOW();
	RD_HIGH();
#ifdef _8_BIT_MODE
	data |= getData() << 8;

	RD_LOW()
	;
	RD_HIGH()
	;
	data |= getData();
#else
	data = getData();
#endif

	CS_HIGH();
	allDataPinsOutput();
	return data;
}

void SPFD5408Init(void) {
	CLOCKS_ENABLE();
	Delay(1);
	CS_OUTPUT();
	Delay(1);
	RD_OUTPUT();
	Delay(1);
	WR_OUTPUT();
	Delay(1);
	RS_OUTPUT();
	Delay(1);
	allDataPinsOutput();
	allDataPinsLow();
	Delay(1);
	// NEW SETUP
	SPFD5408WriteRegister(0xe5, 0x8000);
	Delay(500);
	SPFD5408WriteRegister(0x00, 0x0001);
	SPFD5408WriteRegister(0x01, 0x0100);	//Driver Output Contral.
	SPFD5408WriteRegister(0x02, 0x0700);	//LCD Driver Waveform Contral.
	SPFD5408WriteRegister(0x03, 0x1030);	//Entry Mode Set.

	SPFD5408WriteRegister(0x04, 0x0000);	//Scalling Control.
	SPFD5408WriteRegister(0x08, 0x0202);	//Display Control 2.(0x0207)
	SPFD5408WriteRegister(0x09, 0x0000);	//Display Control 3.(0x0000)
	SPFD5408WriteRegister(0x0a, 0x0000);	//Frame Cycle Contal.(0x0000)
	SPFD5408WriteRegister(0x0c, 0x0000); //Extern Display Interface Control 1.(0x0000)
	SPFD5408WriteRegister(0x0d, 0x0000);	//Frame Maker Position.
	SPFD5408WriteRegister(0x0f, 0x0000);   //Extern Display Interface Control 2.
	Delay(200);
	//********Power On sequence*******************
	SPFD5408WriteRegister(0x10, 0x0000);   //Power Control 1
	SPFD5408WriteRegister(0x11, 0x0007);   //Power Control 2
	SPFD5408WriteRegister(0x12, 0x0000);   //Power Control 3
	SPFD5408WriteRegister(0x13, 0x0000);   //Power Control 4
	Delay(50);
	SPFD5408WriteRegister(0x10, 0x17B0);
	SPFD5408WriteRegister(0x11, 0x0007);
	Delay(10);
	SPFD5408WriteRegister(0x12, 0x013A);
	Delay(10);
	SPFD5408WriteRegister(0x13, 0x1A00);
	SPFD5408WriteRegister(0x29, 0x000c);   //Power Control 7
	Delay(10);

	//********Gamma control***********************
	SPFD5408WriteRegister(0x30, 0x0000);
	SPFD5408WriteRegister(0x31, 0x0505);
	SPFD5408WriteRegister(0x32, 0x0004);
	SPFD5408WriteRegister(0x35, 0x0006);
	SPFD5408WriteRegister(0x36, 0x0707);
	SPFD5408WriteRegister(0x37, 0x0105);
	SPFD5408WriteRegister(0x38, 0x0002);
	SPFD5408WriteRegister(0x39, 0x0707);
	SPFD5408WriteRegister(0x3C, 0x0704);
	SPFD5408WriteRegister(0x3D, 0x0807);

	//********Set RAM area************************
	SPFD5408WriteRegister(0x50, 0x0000);   //Set X Start.
	SPFD5408WriteRegister(0x51, 0x00EF);   //Set X End. (239)
	SPFD5408WriteRegister(0x52, 0x0000);   //Set Y Start.
	SPFD5408WriteRegister(0x53, 0x013F);   //Set Y End. (319)
	SPFD5408WriteRegister(0x60, 0x2700);   //Driver Output Control.
	SPFD5408WriteRegister(0x61, 0x0001);   //Driver Output Control.
	SPFD5408WriteRegister(0x6A, 0x0000);   //Vertical Srcoll Control.
	SPFD5408WriteRegister(0x21, 0x0000);
	SPFD5408WriteRegister(0x20, 0x0000);
	//********Partial Display Control*********
	SPFD5408WriteRegister(0x80, 0x0000);  //Display Position? Partial Display 1.
	SPFD5408WriteRegister(0x81, 0x0000); //RAM Address Start? Partial Display 1.
	SPFD5408WriteRegister(0x82, 0x0000);	//RAM Address End-Partial Display 1.
	SPFD5408WriteRegister(0x83, 0x0000);//Displsy Position? Partial Display 2.
	SPFD5408WriteRegister(0x84, 0x0000);//RAM Address Start? Partial Display 2.
	SPFD5408WriteRegister(0x85, 0x0000);//RAM Address End? Partial Display 2.
	//********Panel Control******************
	SPFD5408WriteRegister(0x90, 0x0010);	//Frame Cycle Contral.(0x0013)
	SPFD5408WriteRegister(0x92, 0x0000);	//Panel Interface Contral 2.(0x0000)
	SPFD5408WriteRegister(0x93, 0x0003);	//Panel Interface Contral 3.
	SPFD5408WriteRegister(0x95, 0x0110);	//Frame Cycle Contral.(0x0110)
	SPFD5408WriteRegister(0x97, 0x0000);	//
	SPFD5408WriteRegister(0x98, 0x0000);	//Frame Cycle Contral.
	//********Display On******************
	Delay(100);
	//exitStandBy();
	SPFD5408WriteRegister(0x07, 0x0173);
	Delay(100);
	SPFD5408WriteCommand(0x0022);
	SPFD5408PaintScreenBackground(YELLOW);
	// NEW SETUP _ END

	/*//OLD SETUP
	 SPFD5408WriteRegister(0x0000, 0x0001);
	 Delay(500);
	 SPFD5408WriteRegister(0x00, 0x0000);
	 SPFD5408WriteRegister(0x01, 0x0100);	//Driver Output Contral.
	 SPFD5408WriteRegister(0x02, 0x0700);	//LCD Driver Waveform Contral.
	 SPFD5408WriteRegister(0x03, 0x1018);	//Entry Mode Set.

	 SPFD5408WriteRegister(0x04, 0x0000);	//Scalling Control.
	 SPFD5408WriteRegister(0x08, 0x0202);	//Display Control 2.(0x0207)
	 SPFD5408WriteRegister(0x09, 0x0000);	//Display Control 3.(0x0000)
	 SPFD5408WriteRegister(0x0a, 0x0000);	//Frame Cycle Contal.(0x0000)
	 SPFD5408WriteRegister(0x0c, (1 << 0));//Extern Display Interface Control 1.(0x0000)
	 SPFD5408WriteRegister(0x0d, 0x0000);	//Frame Maker Position.
	 SPFD5408WriteRegister(0x0f, 0x0000);//Extern Display Interface Control 2.

	 Delay(200);
	 SPFD5408WriteRegister(0x07, 0x0101);	//Display Control.
	 Delay(200);
	 SPFD5408WriteRegister(0x10,
	 (1 << 12) | (0 << 8) | (1 << 7) | (1 << 6) | (0 << 4));	//Power Control 1.(0x16b0)
	 SPFD5408WriteRegister(0x11, 0x0007);			//Power Control 2.(0x0001)
	 SPFD5408WriteRegister(0x12, (1 << 8) | (1 << 4) | (0 << 0));//Power Control 3.(0x0138)
	 SPFD5408WriteRegister(0x13, 0x0b00);					//Power Control 4.
	 SPFD5408WriteRegister(0x29, 0x0000);					//Power Control 7.

	 SPFD5408WriteRegister(0x2b, (1 << 14) | (1 << 4));

	 SPFD5408WriteRegister(0x50, 0);		//Set X Start.
	 SPFD5408WriteRegister(0x51, 239);	//Set X End.
	 SPFD5408WriteRegister(0x52, 0);		//Set Y Start.
	 SPFD5408WriteRegister(0x53, 319);	//Set Y End.

	 SPFD5408WriteRegister(0x60, 0x2700);	//Driver Output Control.
	 SPFD5408WriteRegister(0x61, 0x0001);	//Driver Output Control.
	 SPFD5408WriteRegister(0x6a, 0x0000);	//Vertical Srcoll Control.

	 SPFD5408WriteRegister(0x80, 0x0000);//Display Position? Partial Display 1.
	 SPFD5408WriteRegister(0x81, 0x0000);//RAM Address Start? Partial Display 1.
	 SPFD5408WriteRegister(0x82, 0x0000);	//RAM Address End-Partial Display 1.
	 SPFD5408WriteRegister(0x83, 0x0000);//Displsy Position? Partial Display 2.
	 SPFD5408WriteRegister(0x84, 0x0000);//RAM Address Start? Partial Display 2.
	 SPFD5408WriteRegister(0x85, 0x0000);//RAM Address End? Partial Display 2.

	 SPFD5408WriteRegister(0x90, (0 << 7) | (16 << 0));//Frame Cycle Contral.(0x0013)
	 SPFD5408WriteRegister(0x92, 0x0000);	//Panel Interface Contral 2.(0x0000)
	 SPFD5408WriteRegister(0x93, 0x0001);	//Panel Interface Contral 3.
	 SPFD5408WriteRegister(0x95, 0x0110);	//Frame Cycle Contral.(0x0110)
	 SPFD5408WriteRegister(0x97, (0 << 8));	//
	 SPFD5408WriteRegister(0x98, 0x0000);	//Frame Cycle Contral.

	 Delay(100);
	 exitStandBy();
	 SPFD5408WriteCommand(0x0022);
	 SPFD5408PaintScreenBlack();
	 //OLD SETUP _ END
	 */
}

void SPFD5408PaintScreenBackground(uint16_t color) {
	uint16_t i, f;
	for (i = 0; i < 320; i++) {
		for (f = 0; f < 240; f++) {
			SPFD5408WriteData(color);
		}
	}
}

void exitStandBy(void) {
	SPFD5408WriteRegister(0x0010, 0x14E0);
	Delay(100);
	SPFD5408WriteRegister(0x0007, 0x0133);
}

void SPFD5408SetOrientation(uint16_t HV) //horizontal or vertical
{
	if (HV == 1) //vertical
			{
		SPFD5408WriteRegister(0x03, 0x1038);
	} else //horizontal
	{
		SPFD5408WriteRegister(0x03, 0x1030);
	}
	SPFD5408WriteCommand(0x0022); //Start to write to display RAM
}

void SPFD5408SetDisplayDirect(unsigned char Direction) {
	DisplayDirect = Direction;
}

void SPFD5408SetXY(uint16_t poX, uint16_t poY) {
	if (poX >= MAX_X)
		poX = MAX_X;
	if (poY >= MAX_Y)
		poY = MAX_Y;
	if (poX <= 0)
		poX = 0;
	if (poY <= 0)
		poY = 0;
	SPFD5408WriteRegister(0x0020, poX); //X
	SPFD5408WriteRegister(0x0021, poY);
	//SPFD5408WriteCommand(0x0022); //Start to write to display RAM
}

void SPFD5408SetPixel(uint16_t poX, uint16_t poY, uint16_t color) {
	SPFD5408SetXY(poX, poY);
	SPFD5408WriteData(color);
}

void SPFD5408DrawCircle(int poX, int poY, int r, uint16_t color) {
	int x = -r, y = 0, err = 2 - 2 * r, e2;
	do {
		SPFD5408SetPixel(poX - x, poY + y, color);
		SPFD5408SetPixel(poX + x, poY + y, color);
		SPFD5408SetPixel(poX + x, poY - y, color);
		SPFD5408SetPixel(poX - x, poY - y, color);
		e2 = err;
		if (e2 <= y) {
			err += ++y * 2 + 1;
			if (-x == y && e2 <= x)
				e2 = 0;
		}
		if (e2 > x)
			err += ++x * 2 + 1;
	} while (x <= 0);
}

void SPFD5408FillCircle(int poX, int poY, int r, uint16_t color) {
	int x = -r, y = 0, err = 2 - 2 * r, e2;
	do {
		SPFD5408DrawVerticalLine(poX - x, poY - y, 2 * y, color);
		SPFD5408DrawVerticalLine(poX + x, poY - y, 2 * y, color);

		e2 = err;
		if (e2 <= y) {
			err += ++y * 2 + 1;
			if (-x == y && e2 <= x)
				e2 = 0;
		}
		if (e2 > x)
			err += ++x * 2 + 1;
	} while (x <= 0);
}

void SPFD5408DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,
		uint16_t color) {
	int x = x1 - x0;
	int y = y1 - y0;
	int dx = abs(x), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */
	for (;;) { /* loop */
		SPFD5408SetPixel(x0, y0, color);
		e2 = 2 * err;
		if (e2 >= dy) { /* e_xy+e_x > 0 */
			if (x0 == x1)
				break;
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) { /* e_xy+e_y < 0 */
			if (y0 == y1)
				break;
			err += dx;
			y0 += sy;
		}
	}
}

void SPFD5408DrawVerticalLine(uint16_t poX, uint16_t poY, uint16_t length,
		uint16_t color) {
	uint16_t i;

	SPFD5408SetXY(poX, poY);
	SPFD5408SetOrientation(1);
	if (length + poY > MAX_Y) {
		length = MAX_Y - poY;
	}

	for (i = 0; i < length; i++) {
		SPFD5408WriteData(color);
	}
}

void SPFD5408DrawHorizontalLine(uint16_t poX, uint16_t poY, uint16_t length,
		uint16_t color) {
	uint16_t i;

	SPFD5408SetXY(poX, poY);
	SPFD5408SetOrientation(0);
	if (length + poX > MAX_X) {
		length = MAX_X - poX;
	}
	for (i = 0; i < length; i++) {
		SPFD5408WriteData(color);
	}
}

void SPFD5408DrawRectangle(uint16_t poX, uint16_t poY, uint16_t length,
		uint16_t width, uint16_t color) {
	SPFD5408DrawHorizontalLine(poX, poY, length, color);
	SPFD5408DrawHorizontalLine(poX, poY + width, length, color);

	SPFD5408DrawVerticalLine(poX, poY, width, color);
	SPFD5408DrawVerticalLine(poX + length, poY, width, color);
}

void SPFD5408FillRectangle(uint16_t poX, uint16_t poY, uint16_t length,
		uint16_t width, uint16_t color) {
	uint16_t i;

	for (i = 0; i < width; i++) {
		if (DisplayDirect == LEFT2RIGHT)
			SPFD5408DrawHorizontalLine(poX, poY + i, length, color);
		else if (DisplayDirect == DOWN2UP)
			SPFD5408DrawHorizontalLine(poX, poY - i, length, color);
		else if (DisplayDirect == RIGHT2LEFT)
			SPFD5408DrawHorizontalLine(poX, poY - i, length, color);
		else if (DisplayDirect == UP2DOWN)
			SPFD5408DrawHorizontalLine(poX, poY + i, length, color);
	}
}

void SPFD5408DrawChar(uint16_t poX, uint16_t poY, unsigned char ascii,
		uint16_t size, uint16_t fgcolor) {
	unsigned char i, f, temp = 0;
	uint8_t tempPoX, tempPoY;
		SPFD5408SetXY(poX, poY);

	if ((ascii < 0x20) || (ascii > 0x7e)) //Unsupported char.
			{
		ascii = '?';
	}
	for (i = 0; i < 8; i++) {
		temp = simpleFont[ascii - 0x20][i];
		for (f = 0; f < 8; f++) {
			if ((temp >> f) & 0x01) {
				if (DisplayDirect == LEFT2RIGHT) {
					tempPoX = poX + i * size;
					tempPoY = poY + f * size;
				} else if (DisplayDirect == DOWN2UP) {
					tempPoX = poX + f * size;
					tempPoY = poY - i * size;
				} else if (DisplayDirect == RIGHT2LEFT) {
					tempPoX = poX - i * size;
					tempPoY = poY - f * size;
				} else if (DisplayDirect == UP2DOWN) {
					tempPoX = poX - f * size;
					tempPoY = poY + i * size;
				} else
					return;
					SPFD5408FillRectangle(tempPoX, tempPoY, size, size,
							fgcolor);
			}
		}
	}
}

void SPFD5408DrawString(uint16_t poX, uint16_t poY, char *string, uint16_t size,
		uint16_t fgcolor) {
	//USB_DEBUG_PUTS(string);
	do {
		SPFD5408DrawChar(poX, poY, *string, size, fgcolor);

		if (DisplayDirect == LEFT2RIGHT) {
			if (poX < MAX_X) {
				poX += 8 * size; // Move cursor right
			}
		} else if (DisplayDirect == DOWN2UP) {
			if (poY > 0) {
				poY -= 8 * size; // Move cursor right
			}
		} else if (DisplayDirect == RIGHT2LEFT) {
			if (poX > 0) {
				poX -= 8 * size; // Move cursor right
			}
		} else if (DisplayDirect == UP2DOWN) {
			if (poY < MAX_Y) {
				poY += 8 * size; // Move cursor right
			}
		}
	} while (*string++);
}

void SPFD5408DrawBmp(unsigned short ulXs, unsigned short ulYs,
		unsigned short length, unsigned short height, unsigned short *buf) {
	unsigned short i, j;
	unsigned short length_null = 0;

	if (ulXs + length > MAX_X) {
		length_null = ulXs + length - MAX_X;
	}

	if (ulYs + height > MAX_Y) {
		height -= ulYs + height - MAX_Y;
	}

	for (j = 0; j < height; j++) {
		SPFD5408SetXY(ulXs, ulYs);
		for (i = 0; i < length; i++) {
			SPFD5408WriteData(*buf++);
		}
		ulYs++;
		buf += length_null;
	}
}


/////////////////////////////////////////////////////

