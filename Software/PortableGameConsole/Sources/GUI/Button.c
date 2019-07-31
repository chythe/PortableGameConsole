/**************************************************************************//**
* @file     Button.c
* @brief    Przycisk na ekranie - source file
* @author   Mateusz Chudy
******************************************************************************/

#define F_CPU 16000000UL // CPU 16MHz
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include "Button.h"
#include "GraphicsPrimitives.h"
#include "Font.h"
#include <DisplayTexts.h>
#include "LCDController.h"
#include "TouchController.h"

/**************************************************************************//**
 * @brief Tworzy nowy przycik.
 * @param string - napis na przycisku
 * @param option - opcja z ktorej powstal przycisk
 * @param textColor - kolor tekstu
 * @param buttonColor - kolor przycisku
 * @param x - wspolrzedna x przycisku
 * @param y - wspolrzedna y przycisku
 * @param width - szerokosc przycisku
 * @param height - wysokosc przycisku
 * @return wskaznik na strukture nowego przycisku
 *****************************************************************************/
struct Button* ButtonCreate(char* string, Option option, uint16_t textColor,
		uint16_t buttonColor, uint8_t x, uint16_t y, uint8_t width, uint16_t height)
{
	struct Button *button = (struct Button*)malloc(sizeof(struct Button));
	button->string = string;
	button->x = x;
	button->y = y;
	button->width = width;
	button->height = height;
	button->buttonColor = buttonColor;
	button->textColor = textColor;
	button->earlierOption = option;
	button->Display = ButtonDisplay;
	return button;
}

/**************************************************************************//**
 * @brief Niszczy przycisk.
 * @param button - wskaznik na strukture przycisku
 * @return wskaznik na strukture przycisku
 *****************************************************************************/
struct Button** ButtonDestroy(struct Button* button)
{
	free(button);
	button = NULL;
	return button;
}

/**************************************************************************//**
 * @brief Wyswietla przycisk.
 * @param button - wskaznik na strukture przycisku
 *****************************************************************************/
void ButtonDisplay(struct Button* button)
{
	GraphicsClearArea(button->buttonColor,
			button->x,
			button->y,
			button->width,
			button->height);
	FontDisplayString(button->string,
			button->textColor,
			button->buttonColor,
			button->x + (button->width) / 2 - (strlen(button->string) * 8) / 2,
			button->y + (button->height / 2) - 16 / 2);
}

/**************************************************************************//**
 * @brief Sprawdza czy przycisk zostal nacisniety.
 * @param button - wskaznik na strukture przycisku
 * @return wartosc logiczna oznaczajaca czy przycisk zostal wcisniety
 *****************************************************************************/
bool ButtonCheck(struct Button* button)
{
	uint8_t x = touchPoint.x + CORRECT_X;
	uint16_t y = touchPoint.y + CORRECT_Y;

	if (x >= button->x &&
		x <= button->x + button->width &&
		y >= button->y &&
		y <= button->y + button->height)
		return true;
	else
		return false;
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
