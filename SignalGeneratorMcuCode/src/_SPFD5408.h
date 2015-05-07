/*
 * _SPFD5408.h
 *
 *  Created on: 02-05-2015
 *      Author: lukasz
 */

#ifndef SPFD5408_H_
#define SPFD5408_H_

#define PORTRAIT 0
#define LANDSCAPE 1
#define LEFT 0
#define RIGHT 9999
#define CENTER 9998

#define fontbyte(x) (cfont.font[x])

struct CurrentFont {
	uint8_t* font;
	uint8_t xSize;
	uint8_t ySize;
	uint8_t offset;
	uint8_t numchars;
};
void _SPFD5408Init(void);
//void InitLCD(uint8_t orientation = LANDSCAPE);
void clrScr();
void drawPixel(int x, int y, uint16_t color);
void drawLine(int x1, int y1, int x2, int y2, uint16_t color);
void fillScr(uint8_t r, uint8_t g, uint8_t b);
//void fillScr(uint16_t color);
void drawRect(int x1, int y1, int x2, int y2, uint16_t color);
void drawRoundRect(int x1, int y1, int x2, int y2, uint16_t color);
void fillRect(int x1, int y1, int x2, int y2, uint16_t color);
void fillRoundRect(int x1, int y1, int x2, int y2, uint16_t color);
void drawCircle(int x, int y, int radius, uint16_t color);
void fillCircle(int x, int y, int radius, uint16_t color);
void setColor(uint8_t r, uint8_t g, uint8_t b);
void setFont(uint8_t* font);
uint8_t* getFont();
uint8_t getFontXsize();
uint8_t getFontYsize();
void drawBitmap(int x, int y, int sx, int sy, uint16_t* data, int scale);
//void drawBitmap(int x, int y, int sx, int sy, bitmapdatatype data, int deg,
//	int rox, int roy);
void lcdOff();
void lcdOn();
void setContrast(char c);
int getDisplayXSize();
int getDisplayYSize();

/*
 The functions and variables below should not normally be used.
 They have been left publicly available for use in add-on libraries
 that might need access to the lower level functions of UTFT.

 Please note that these functions and variables are not documented
 and I do not provide support on how to use them.
 */
uint8_t fch, fcl, bch, bcl;

long disp_x_size, disp_y_size;
uint8_t display_model, display_transfer_mode, display_serial_mode;

struct CurrentFont cfont;
bool _transparent;

void LCD_Write_COM(uint16_t data);
void LCD_Write_DATA(uint16_t data);
void LCD_Write_COM_DATA(uint16_t com1, uint16_t dat1);
void _hw_special_init();
void setPixel(uint16_t color);
void drawHLine(int x, int y, int l, uint16_t color);
void drawVLine(int x, int y, int l, uint16_t color5);
void printChar(uint8_t c, int x, int y, uint16_t color);
void rotateChar(uint8_t c, int x, int y, int pos, int deg,uint16_t color);
void print(char *st, int x, int y, int deg, uint16_t color);
void printNumI(long num, int x, int y, int length, char filler, uint16_t color);
void printNumF(double num, uint8_t dec, int x, int y, char divider, int length,
		char filler, uint16_t color);
void setXY(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void clrXY();

void _set_direction_registers(uint8_t mode);
void _fast_fill_16(uint8_t ch, uint8_t cl, long pix);
void _fast_fill_8(uint8_t ch, long pix);
void _convert_float(char *buf, double num, int width, uint8_t prec);

#endif /* SPFD5408_H_ */
