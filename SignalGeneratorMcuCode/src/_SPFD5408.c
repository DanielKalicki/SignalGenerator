/*
 * _SPFD5408.c
 *
 *  Created on: 02-05-2015
 *      Author: lukasz
 */
#include "SPFD5408.h"
#include "utils.h"
//#include "font.h"
#include "_SPFD5408.h"

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

void _SPFD5408Init(void) {
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

}

void LCD_Write_COM(uint16_t data) {

	/*
	 if (display_transfer_mode!=1)
	 {
	 RS_LOW();
	 LCD_Writ_Bus(0x00,VL,display_transfer_mode);
	 }
	 else
	 LCD_Writ_Bus(0x00,VL,display_transfer_mode);
	 */
	CS_LOW();
	SPFD5408SendCommand(data);
	CS_HIGH();
}

void LCD_Write_DATA(uint16_t data) {
	/*
	 if (display_transfer_mode!=1)
	 {
	 RS_HIGH();
	 LCD_Writ_Bus(VH,VL,display_transfer_mode);
	 }
	 else
	 {
	 LCD_Writ_Bus(0x01,VH,display_transfer_mode);
	 LCD_Writ_Bus(0x01,VL,display_transfer_mode);
	 }
	 */
	CS_LOW();
	SPFD5408SendData(data);
	CS_HIGH();
}
/*
 void LCD_Write_DATA(char VL)
 {
 if (display_transfer_mode!=1)
 {
 RS_HIGH();
 LCD_Writ_Bus(0x00,VL,display_transfer_mode);
 }
 else
 LCD_Writ_Bus(0x01,VL,display_transfer_mode);
 }
 */
void LCD_Write_COM_DATA(uint16_t com1, uint16_t dat1) {
	/*
	 LCD_Write_COM(com1);
	 LCD_Write_DATA(dat1>>8,dat1);
	 */

	CS_LOW();
	SPFD5408SendCommand(com1);
	SPFD5408SendData(dat1);
	CS_HIGH();
}

void setXY(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
	/*if (orient==LANDSCAPE)
	 {
	 swap(word, x1, y1);
	 swap(word, x2, y2);
	 y1=disp_y_size-y1;
	 y2=disp_y_size-y2;
	 swap(word, y1, y2)
	 }
	 */

	LCD_Write_COM_DATA(0x20, x1);
	LCD_Write_COM_DATA(0x21, y1);
	LCD_Write_COM_DATA(0x50, x1);
	LCD_Write_COM_DATA(0x52, y1);
	LCD_Write_COM_DATA(0x51, x2);
	LCD_Write_COM_DATA(0x53, y2);

	LCD_Write_COM(0x22);
}

void clrXY() {
	if (orient == PORTRAIT)
		setXY(0, 0, MAX_X, MAX_Y);
	else
		setXY(0, 0, MAX_Y, MAX_X);
}

/*
 void _fast_fill_16(byte ch, byte cl, long pix)
 {
 long blocks;

 PORTD = ch;
 cport(PORTC, 0xFC);
 sport(PORTC, (cl>>6) & 0x03);
 PORTB =  cl & 0x3F;

 blocks = pix/16;
 for (int i=0; i<blocks; i++)
 {
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 pulse_low(P_WR, B_WR);
 }
 if ((pix % 16) != 0)
 for (int i=0; i<(pix % 16)+1; i++)
 {
 pulse_low(P_WR, B_WR);
 }
 }
 */
void drawHLine(int x, int y, int l, uint16_t color) {
	if (l < 0) {
		l = -l;
		x -= l;
	}
	//cbi(P_CS, B_CS);
	setXY(x, y, x + l, y);
	for (int i = 0; i < l + 1; i++) {
		LCD_Write_DATA(color);
	}
	clrXY();
}

void drawVLine(int x, int y, int l, uint16_t color) {
	if (l < 0) {
		l = -l;
		y -= l;
	}
	//cbi(P_CS, B_CS);
	setXY(x, y, x, y + l);

	for (int i = 0; i < l + 1; i++) {
		LCD_Write_DATA(color);
	}

///sbi(P_CS, B_CS);
	clrXY();
}

void drawLine(int x1, int y1, int x2, int y2, uint16_t color) {
	if (y1 == y2)
		drawHLine(x1, y1, x2 - x1,color);
	else if (x1 == x2)
		drawVLine(x1, y1, y2 - y1,color);
	else {
		unsigned int dx = (x2 > x1 ? x2 - x1 : x1 - x2);
		short xstep = x2 > x1 ? 1 : -1;
		unsigned int dy = (y2 > y1 ? y2 - y1 : y1 - y2);
		short ystep = y2 > y1 ? 1 : -1;
		int col = x1, row = y1;

		//cbi(P_CS, B_CS);
		if (dx < dy) {
			int t = -(dy >> 1);
			while (true) {
				setXY(col, row, col, row);
				LCD_Write_DATA(color);
				if (row == y2)
					return;
				row += ystep;
				t += dx;
				if (t >= 0) {
					col += xstep;
					t -= dy;
				}
			}
		} else {
			int t = -(dx >> 1);
			while (true) {
				setXY(col, row, col, row);
				LCD_Write_DATA(color);
				if (col == x2)
					return;
				col += xstep;
				t += dy;
				if (t >= 0) {
					row += ystep;
					t -= dx;
				}
			}
		}
		//sbi(P_CS, B_CS);
	}
	clrXY();
}

