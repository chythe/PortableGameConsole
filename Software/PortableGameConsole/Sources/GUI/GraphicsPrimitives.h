/**************************************************************************//**
* @file     GraphicsPrimitives.h
* @brief    Prymitywy graficzne - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _GRAPHICS_PRIMITIVES_H_
#define _GRAPHICS_PRIMITIVES_H_

#include <GlobalErrors.h>
#include <stdint.h>

#define MIN_ALPHA_SIZE			-180
#define MAX_ALPHA_SIZE			180

/// Czysci ekran na zadany kolor
void GraphicsClearScreen(uint16_t color);

/// Zamalowuje obszar na zadany kolor
void GraphicsClearArea(uint16_t color, uint8_t x, uint16_t y, uint8_t width, uint16_t height);

/// Ustawia kursor w punkcie o zadanych wspolrzednych
void GraphicsSetCursor(uint8_t x, uint16_t y);

/// Wyswietla punkt o zadanych wspolrzednych
void GraphicsPutPixel(uint16_t color, uint8_t x, uint16_t y);

/// Wyswietla kropke 3x3 piksele o zadanych wspolrzednych
void GraphicsDrawBigDot(uint16_t color, uint8_t x, uint16_t y);

/// Wyswietla okrag o srodku w zadanych wspolrzednych
void GraphicsDrawCircle(uint16_t color, uint8_t x, uint16_t y, uint8_t r);

/// Wyswietla linie pomiedzy dwoma punktami
ExecuteResult GraphicsDrawLine(uint16_t color, uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2);

/// Wyswietla linie w poziomie lub w pionie
void GraphicsDrawSimpleLine(uint16_t color, uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2);

/// Wyswietla obrazek
__attribute__((__deprecated__))
void GraphicsDisplayImage(const uint8_t* image, uint8_t x, uint16_t y, uint8_t width, uint16_t height);

#endif  	// _GRAPHICS_PRIMITIVES_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
