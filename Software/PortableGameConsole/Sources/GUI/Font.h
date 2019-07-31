/**************************************************************************//**
* @file     Font.h
* @brief    Czionka i zarzadzanie tekstami - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _FONT_H_
#define _FONT_H_

#include <stdint.h>

#define CHAR_MAX_X			8
#define CHAR_MAX_Y			16
#define CHAR_MASK			0x80
#define STRING_MAX_X		230
#define STRING_MAX_Y		300

/// Globalna tablica zawierajaca czcionke znakow ascii
const uint8_t ascii[];

/// Wyswietla znak
void FontDisplayChar(char character, uint16_t colorFront, uint16_t colorBackground, uint8_t x, uint16_t y);

/// Wyswietla napis
void FontDisplayString(char* string, uint16_t colorFront, uint16_t colorBackground, uint8_t x, uint16_t y);

#endif		// _FONT_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
