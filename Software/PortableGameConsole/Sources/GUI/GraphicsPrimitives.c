/**************************************************************************//**
* @file     GraphicsPrimitives.c
* @brief    Prymitywy graficzne - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <stdbool.h>
#include <math.h>
#include <avr/io.h>
#define F_CPU 16000000UL //CPU 12MHz
#include <util/delay.h>
#include "GraphicsPrimitives.h"
#include "LCDController.h"
#include "ToolSet.h"

/**************************************************************************//**
 * @brief Czysci ekran na zadany kolor.
 * @param color - kolor czyszczenia ekranu
 *****************************************************************************/
void GraphicsClearScreen(uint16_t color)
{
	uint16_t i;
	uint8_t j;

	LCDWriteReg(INDEX_ENTRY_MODE, 0x1230);
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_START_POSITION, 0x0000);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_START_POSITION, 0x0000);
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_END_POSITION, 0xEF);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_END_POSITION, 0x013F);

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_SET, 0x0000);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_SET, 0x0000);

	LCDWriteIndex(INDEX_RAM_DATA_WRITE);
	LCD_CS_L();
	LCD_RS_H();

	for (i = 0; i < LCD_SIZE_Y; i++)
	{
		for (j = 0; j < LCD_SIZE_X; j++)
			LCDWriteData(color);
	}

	LCD_CS_H();
	LCDWriteReg(INDEX_ENTRY_MODE, 0x1030);
}

/**************************************************************************//**
 * @brief Zamalowuje obszar na zadany kolor.
 * @param color - kolor zamalowania obszaru
 * @param x - wspolrzedna x lewego gornego konca obszaru
 * @param y - wspolrzedna y lewego gornego konca obszaru
 * @param width - szerokosc obszaru
 * @param height - wysokosc obszaru
 *****************************************************************************/
void GraphicsClearArea(uint16_t color, uint8_t x, uint16_t y, uint8_t width, uint16_t height)
{
	uint16_t i;
	uint8_t j;

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_START_POSITION, x);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_START_POSITION, y);
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_END_POSITION, x + width - 1);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_END_POSITION, y + height - 1);

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_SET, x);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_SET, y);

	LCD_RS_L();
	LCDWriteIndex(INDEX_RAM_DATA_WRITE);
	LCD_CS_L();

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			LCDWriteData(color);
	}
	LCD_CS_H();
}

/**************************************************************************//**
 * @brief Ustawia kursor w punkcie o zadanych wspolrzednych.
 * @param x - wspolrzedna x
 * @param y - wspolrzedna y
 *****************************************************************************/
void GraphicsSetCursor(uint8_t x, uint16_t y)
{
  	if (x > LCD_SIZE_Y || y > LCD_SIZE_X)
		return;
  	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_SET, x);
  	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_SET, y);
}

/**************************************************************************//**
 * @brief Wyswietla punkt o zadanych wspolrzednych.
 * @param color - kolor punktu
 * @param x - wspolrzedna x
 * @param y - wspolrzedna y
 *****************************************************************************/
void GraphicsPutPixel(uint16_t color, uint8_t x, uint16_t y)
{
	LCDWriteReg(INDEX_ENTRY_MODE, 0x1230);

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_START_POSITION, x);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_START_POSITION, y);
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_END_POSITION, x);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_END_POSITION, y);

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_SET, x);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_SET, y);

	LCDWriteIndex(INDEX_RAM_DATA_WRITE);
	LCD_CS_L();
	LCD_RS_H();

	LCDWriteData(color);

	LCD_CS_H();
	LCDWriteReg(INDEX_ENTRY_MODE, 0x1030);
}

/**************************************************************************//**
 * @brief Wyswietla kropke 3x3 piksele o zadanych wspolrzednych.
 * @param color - kolor kropki
 * @param x - wspolrzedna x
 * @param y - wspolrzedna y
 *****************************************************************************/
void GraphicsDrawBigDot(uint16_t color, uint8_t x, uint16_t y)
{
	int i;

	LCDWriteReg(INDEX_ENTRY_MODE, 0x1230);

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_START_POSITION, x - 1);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_START_POSITION, y - 1);
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_END_POSITION, x + 1);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_END_POSITION, y + 1);

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_SET, x);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_SET, y);

	LCDWriteIndex(INDEX_RAM_DATA_WRITE);
	LCD_CS_L();
	LCD_RS_H();

	for (i = 0; i < 9; i++)
		LCDWriteData(color);

	LCD_CS_H();
	LCDWriteReg(INDEX_ENTRY_MODE, 0x1030);
}

/**************************************************************************//**
 * @brief Wyswietla okrag o srodku w zadanych wspolrzednych.
 * @param color - kolor kropki
 * @param x - wspolrzedna x
 * @param y - wspolrzedna y
 * @param r - promien okregu
 *****************************************************************************/
void GraphicsDrawCircle(uint16_t color, uint8_t x, uint16_t y, uint8_t r)
{
	int16_t alpha;

	for (alpha = MIN_ALPHA_SIZE; alpha < MAX_ALPHA_SIZE; alpha++)
		GraphicsPutPixel(color,
				(uint8_t)round(x + r * cos((alpha * M_PI) / MAX_ALPHA_SIZE)),
				(uint16_t)round(y + r * sin((alpha * M_PI) / MAX_ALPHA_SIZE)));
}

/**************************************************************************//**
 * @brief Wyswietla linie pomiedzy dwoma punktami.
 * @param color - kolor lini
 * @param x1 - wspolrzedna x pierwszego punktu
 * @param y1 - wspolrzedna y pierwszego punktu
 * @param x2 - wspolrzedna x drugiego punktu
 * @param y2 - wspolrzedna y drugiego punktu
 * @return rezultat operacji
 *****************************************************************************/
ExecuteResult GraphicsDrawLine(uint16_t color, uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2)
{
	uint8_t dx;
	uint16_t dy;
	int8_t tx, ty;
	uint16_t inc1, inc2;
	uint16_t d;
	uint8_t x;
	uint16_t y;
	bool flag;

	GraphicsPutPixel(color, x1, y1);

	if (x1 == x2 && y1 == y2)
		return INVALID_PARAMETER;

	flag = false;
	dx = (x2 - x1);
	dy = (y2 - y1);
	if (dx < dy)
	{
		flag = true;
		ToolsSwap(&x1, &y1);
		ToolsSwap(&x2, &y2);
		ToolsSwap(&dx, &dy);
	}
	tx = x2 - x1 > 0 ? 1 : -1;
	ty = y2 - y1 > 0 ? 1 : -1;
	x = x1;
	y = y1;
	inc1 = 2 * dy;
	inc2 = 2 * (dy - dx);
	d = inc1 - dx ;
	while (x != x2)
	{
		if (d < 0)
			d += inc1;
		else
		{
			y += ty;
			d += inc2;
		}

		if (flag)
			GraphicsPutPixel(color, y, x);
		else
			GraphicsPutPixel(color, x, y);
		x += tx ;
	}

	return EXECUTE_OK;
}

/**************************************************************************//**
 * @brief Wyswietla linie w poziomie lub w pionie.
 * @param color - kolor lini
 * @param x1 - wspolrzedna x pierwszego punktu
 * @param y1 - wspolrzedna y pierwszego punktu
 * @param x2 - wspolrzedna x drugiego punktu
 * @param y2 - wspolrzedna y drugiego punktu
 *****************************************************************************/
void GraphicsDrawSimpleLine(uint16_t color, uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2)
{
	uint16_t i;

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_START_POSITION, x1);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_START_POSITION, y1);
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_END_POSITION, x2 - 1);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_END_POSITION, y2 - 1);

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_SET, x1);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_SET, y2);

	LCD_RS_L();
	LCDWriteIndex(INDEX_RAM_DATA_WRITE);
	LCD_CS_L();

	for (i = 0; i < (x2 - x1); i++)
	{
		LCDWriteData(color);
	}
	LCD_CS_H();
}

/**************************************************************************//**
 * @brief Wyswietla obrazek.
 * @param image - obrazek
 * @param x - wspolrzedna x lewego gornego konca obrazka
 * @param y - wspolrzedna y lewego gornego konca obrazka
 * @param width - szerokosc obrazka
 * @param height - wysokosc obrazka
 *****************************************************************************/
void GraphicsDisplayImage(const uint8_t* image, uint8_t x, uint16_t y, uint8_t width, uint16_t height)
{
	uint16_t i;
	uint8_t j;
	uint16_t data;

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_START_POSITION, x);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_START_POSITION, y);
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_END_POSITION, x + width - 1);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_END_POSITION, y + height - 1);

	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_SET, x);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_SET, y);

	LCD_RS_L();
	LCDWriteIndex(INDEX_RAM_DATA_WRITE);


	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			data = (*(image + 1) << 8 ) | (*image);
			LCDWriteData(data);
			image += 2;
		}
	}
	LCD_CS_H();
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
