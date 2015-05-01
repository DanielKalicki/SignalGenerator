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

void LCD_Write_COM(char VL)
{
	if (display_transfer_mode!=1)
	{
		RS_LOW();
		LCD_Writ_Bus(0x00,VL,display_transfer_mode);
	}
	else
		LCD_Writ_Bus(0x00,VL,display_transfer_mode);
}

void LCD_Write_DATA(char VH,char VL)
{
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
void LCD_Write_COM_DATA(char com1,int dat1)
{
     LCD_Write_COM(com1);
     LCD_Write_DATA(dat1>>8,dat1);
}
