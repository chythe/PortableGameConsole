/**************************************************************************//**
* @file     Paint.h
* @brief    Aplikacja do rysowania - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _PAINT_H_
#define _PAINT_H_

#include <stdint.h>
#include <stdbool.h>
#include "Button.h"
#include "LCDController.h"

#define PAINT_BACKGROUND_COLOR			WHITE
#define PAINT_BUTTONS_SIZE				30
#define PAINT_BUTTONS_SIZE				30
#define PAINT_BUTTONS_MAX_X				8
#define PAINT_EXIT_BUTTON_X				5
#define PAINT_EXIT_BUTTON_Y				285

/// Inicjalizuje aplikacje Paint
void PaintInit(Color* buttonColors, struct Button* button);

/// Sprawdza zmiane koloru przez urzytkownika
Color PaintCheckColorChange(Color* buttonColors, Color currentColor);

/// Wlacza aplikacje Paint
void PaintShow(void);

#endif		//	_PAINT_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------

