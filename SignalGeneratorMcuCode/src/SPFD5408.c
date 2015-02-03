#include "SPFD5408.h"
#include "utils.h"
#include "font.h"

static uint8_t DisplayDirect = LEFT2RIGHT;
static void exitStandBy(void);

/*hardware dependent methods*/
static void pinWrite(GPIO_Port_TypeDef port, uint8_t pin, uint8_t mask) {

	if (!mask) {
		GPIO_PinOutClear(port, pin);
	} else
		GPIO_PinOutSet(port, pin);
}



static uint16_t pinRead(GPIO_Port_TypeDef port, uint8_t pin) {

	return GPIO_PinOutGet(port, pin);
}

/*hardware dependent methods - end*/

static void allDataPinsInput(void) {
	TFT_PIN_D15_INPUT()
	TFT_PIN_D14_INPUT()
	TFT_PIN_D13_INPUT()
	TFT_PIN_D12_INPUT()
	TFT_PIN_D11_INPUT()
	TFT_PIN_D10_INPUT()
	TFT_PIN_D9_INPUT()
	TFT_PIN_D8_INPUT()
#ifdef _16_BIT_MODE
	TFT_PIN_D7_INPUT()
	TFT_PIN_D6_INPUT()
	TFT_PIN_D5_INPUT()
	TFT_PIN_D4_INPUT()
	TFT_PIN_D3_INPUT()
	TFT_PIN_D2_INPUT()
	TFT_PIN_D1_INPUT()
	TFT_PIN_D0_INPUT()
#endif

}

static void allDataPinsOutput(void) {
	TFT_PIN_D15_OUTPUT()
	TFT_PIN_D14_OUTPUT()
	TFT_PIN_D13_OUTPUT()
	TFT_PIN_D12_OUTPUT()
	TFT_PIN_D11_OUTPUT()
	TFT_PIN_D10_OUTPUT()
	TFT_PIN_D9_OUTPUT()
	TFT_PIN_D8_OUTPUT()
#ifdef _16_BIT_MODE
	TFT_PIN_D7_OUTPUT()
	TFT_PIN_D6_OUTPUT()
	TFT_PIN_D5_OUTPUT()
	TFT_PIN_D4_OUTPUT()
	TFT_PIN_D3_OUTPUT()
	TFT_PIN_D2_OUTPUT()
	TFT_PIN_D1_OUTPUT()
	TFT_PIN_D0_OUTPUT()
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

void SPFD5408SendCommand(uint16_t index) {
	CS_LOW()
	;
	RS_LOW()
	;
	RD_HIGH()
	;
	WR_HIGH()
	;

	WR_LOW()
	;
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
	WR_HIGH()
	;
	CS_HIGH()
	;
}

void SPFD5408SendData(uint16_t data) {
	CS_LOW()
	;
	RS_HIGH()
	;
	RD_HIGH()
	;

	WR_LOW()
	;
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
	WR_HIGH()
	;

	CS_HIGH()
	;
}

uint16_t SPFD5408ReadRegister(uint16_t index) {
	uint16_t data = 0;

	CS_LOW()
	;
	RS_LOW()
	;

	WR_LOW()
	;
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
	WR_HIGH()
	;

	allDataPinsInput();
	allDataPinsLow();
	RS_HIGH()
	;

	RD_LOW()
	;
	RD_HIGH()
	;
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

	CS_HIGH()
	;
	allDataPinsOutput();
	return data;
}

void SPFD5408Init(void) {
	CLOCKS_ENABLE()
	;

	CS_OUTPUT()
	;
	RD_OUTPUT()
	;
	WR_OUTPUT()
	;
	RS_OUTPUT()
	;
	allDataPinsOutput();
	allDataPinsLow();

	Delay(200);

	SPFD5408SendCommand(0x0001);
	SPFD5408SendData(0x0100);
	SPFD5408SendCommand(0x0002);
	SPFD5408SendData(0x0700);
	SPFD5408SendCommand(0x0003);
	SPFD5408SendData(0x1030);
	SPFD5408SendCommand(0x0004);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0008);
	SPFD5408SendData(0x0302);
	SPFD5408SendCommand(0x000A);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x000C);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x000D);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x000F);
	SPFD5408SendData(0x0000);

	Delay(200);

	SPFD5408SendCommand(0x0030);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0031);
	SPFD5408SendData(0x0405);
	SPFD5408SendCommand(0x0032);
	SPFD5408SendData(0x0203);
	SPFD5408SendCommand(0x0035);
	SPFD5408SendData(0x0004);
	SPFD5408SendCommand(0x0036);
	SPFD5408SendData(0x0B07);
	SPFD5408SendCommand(0x0037);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0038);
	SPFD5408SendData(0x0405);
	SPFD5408SendCommand(0x0039);
	SPFD5408SendData(0x0203);
	SPFD5408SendCommand(0x003c);
	SPFD5408SendData(0x0004);
	SPFD5408SendCommand(0x003d);
	SPFD5408SendData(0x0B07);
	SPFD5408SendCommand(0x0020);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0021);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0050);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0051);
	SPFD5408SendData(0x00ef);
	SPFD5408SendCommand(0x0052);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0053);
	SPFD5408SendData(0x013f);

	Delay(200);

	SPFD5408SendCommand(0x0060);
	SPFD5408SendData(0xa700);
	SPFD5408SendCommand(0x0061);
	SPFD5408SendData(0x0001);
	SPFD5408SendCommand(0x0090);
	SPFD5408SendData(0x003A);
	SPFD5408SendCommand(0x0095);
	SPFD5408SendData(0x021E);
	SPFD5408SendCommand(0x0080);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0081);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0082);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0083);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0084);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x0085);
	SPFD5408SendData(0x0000);
	SPFD5408SendCommand(0x00FF);
	SPFD5408SendData(0x0001);
	SPFD5408SendCommand(0x00B0);
	SPFD5408SendData(0x140D);
	SPFD5408SendCommand(0x00FF);
	SPFD5408SendData(0x0000);
	Delay(200);
	SPFD5408SendCommand(0x0007);
	SPFD5408SendData(0x0133);
	Delay(100);
	exitStandBy();
	SPFD5408SendCommand(0x0022);

	//paint screen black
	SPFD5408PaintScreenBlack();
}

void SPFD5408PaintScreenBlack(void) {
	uint16_t i, f;
	for (i = 0; i < 320; i++) {
		for (f = 0; f < 240; f++) {
			SPFD5408SendData(BLACK);
		}
	}
}

void exitStandBy(void) {
	SPFD5408SendCommand(0x0010);
	SPFD5408SendData(0x14E0);
	Delay(100);
	SPFD5408SendCommand(0x0007);
	SPFD5408SendData(0x0133);
}

void SPFD5408SetOrientation(uint16_t HV) //horizontal or vertical
{
	SPFD5408SendCommand(0x03);
	if (HV == 1) //vertical
			{
		SPFD5408SendData(0x5038);
	} else //horizontal
	{
		SPFD5408SendData(0x5030);
	}
	SPFD5408SendCommand(0x0022); //Start to write to display RAM
}

void SPFD5408SetDisplayDirect(unsigned char Direction) {
	DisplayDirect = Direction;
}

void SPFD5408SetXY(uint16_t poX, uint16_t poY) {
	SPFD5408SendCommand(0x0020); //X
	SPFD5408SendData(poX);
	SPFD5408SendCommand(0x0021); //Y
	SPFD5408SendData(poY);
	SPFD5408SendCommand(0x0022); //Start to write to display RAM
}

void SPFD5408SetPixel(uint16_t poX, uint16_t poY, uint16_t color) {
	SPFD5408SetXY(poX, poY);
	SPFD5408SendData(color);
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

void SPFD5408DrawLine(uint16_t x0, uint16_t y0, uint16_t x1,
		uint16_t y1, uint16_t color) {
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

void SPFD5408DrawVerticalLine(uint16_t poX, uint16_t poY,
		uint16_t length, uint16_t color) {
	uint16_t i;

	SPFD5408SetXY(poX, poY);
	SPFD5408SetOrientation(1);
	if (length + poY > MAX_Y) {
		length = MAX_Y - poY;
	}

	for (i = 0; i < length; i++) {
		SPFD5408SendData(color);
	}
}

void SPFD5408DrawHorizontalLine(uint16_t poX, uint16_t poY,
		uint16_t length, uint16_t color) {
	uint16_t i;

	SPFD5408SetXY(poX, poY);
	SPFD5408SetOrientation(0);
	if (length + poX > MAX_X) {
		length = MAX_X - poX;
	}
	for (i = 0; i < length; i++) {
		SPFD5408SendData(color);
	}
}

void SPFD5408DrawRectangle(uint16_t poX, uint16_t poY,
		uint16_t length, uint16_t width, uint16_t color) {
	SPFD5408DrawHorizontalLine(poX, poY, length, color);
	SPFD5408DrawHorizontalLine(poX, poY + width, length, color);

	SPFD5408DrawVerticalLine(poX, poY, width, color);
	SPFD5408DrawVerticalLine(poX + length, poY, width, color);
}

void SPFD5408FillRectangle(uint16_t poX, uint16_t poY,
		uint16_t length, uint16_t width, uint16_t color) {
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

	SPFD5408SetXY(poX, poY);

	if ((ascii < 0x20) || (ascii > 0x7e)) //Unsupported char.
			{
		ascii = '?';
	}
	for (i = 0; i < 8; i++) {
		temp = simpleFont[ascii - 0x20][i];
		for (f = 0; f < 8; f++) {
			if ((temp >> f) & 0x01) {
				if (DisplayDirect == LEFT2RIGHT)
					SPFD5408FillRectangle(poX + i * size, poY + f * size, size,
							size, fgcolor);
				else if (DisplayDirect == DOWN2UP)
					SPFD5408FillRectangle(poX + f * size, poY - i * size, size,
							size, fgcolor);
				else if (DisplayDirect == RIGHT2LEFT)
					SPFD5408FillRectangle(poX - i * size, poY - f * size, size,
							size, fgcolor);
				else if (DisplayDirect == UP2DOWN)
					SPFD5408FillRectangle(poX - f * size, poY + i * size, size,
							size, fgcolor);
			}
		}
	}
}

void SPFD5408DrawString(uint16_t poX, uint16_t poY, char *string,
		uint16_t size, uint16_t fgcolor) {
	//unsigned char i;

	while (*string++) {
		//for(i=0;i<8;i++)
		{
			SPFD5408DrawChar(poX, poY, *string, size, fgcolor);
		}
		//*string++;
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
	}
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
			SPFD5408SendData(*buf++);
		}
		ulYs++;
		buf += length_null;
	}
}

