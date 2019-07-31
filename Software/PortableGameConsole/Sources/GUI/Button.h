/**************************************************************************//**
* @file     Button.h
* @brief    Przycisk na ekranie - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <stdint.h>
#include <stdbool.h>
#include "MenuOptions.h"

/// Struktura reprezentujaca przycisk
struct Button
{
	char* string;
	uint16_t textColor;
	uint16_t buttonColor;
	uint8_t x;
	uint16_t y;
	uint8_t width;
	uint16_t height;
	Option earlierOption;

	void (*Display)(struct Button *);
};

/// Tworzy nowy przycik
struct Button* ButtonCreate(char* string, Option option, uint16_t textColor, uint16_t buttonColor, uint8_t x, uint16_t y, uint8_t width, uint16_t height);

/// Niszczy przycisk
struct Button** ButtonDestroy(struct Button* button);

/// Wyswietla przycisk
void ButtonDisplay(struct Button* button);

/// Sprawdza czy przycisk zostal nacisniety
bool ButtonCheck(struct Button* button);

#endif		// _BUTTON_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
