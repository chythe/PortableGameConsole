/**************************************************************************//**
* @file     Desktop.h
* @brief    Pulpit z wejsciem menu - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _DESKTOP_H_
#define _DESKTOP_H_

#include <stdint.h>
#include <avr/interrupt.h>
#include "LCDController.h"
#include "Button.h"
#include "MenuOptions.h"

#define DESK_MENU_BUTTON_X1			0
#define DESK_MENU_BUTTON_Y1			280
#define DESK_MENU_BUTTON_X2			240
#define DESK_MENU_BUTTON_Y2			320
#define DESK_MENU_BUTTON_COLOR		DARKBLUE
#define DESK_MENU_TEXT_COLOR		WHITE

#define BACK_BUTTON_X1			    0
#define BACK_BUTTON_Y1			    280
#define BACK_BUTTON_X2			    240
#define BACK_BUTTON_Y2			    320
#define BACK_BUTTON_COLOR		    RED
#define BACK_TEXT_COLOR			    WHITE

/// Globalna tablica przyciskow zawartych w menu
struct Button *buttonArray[LAST];

/// Sprawdza wybranie opcji z menu
void DesktopCheckSelect(void);

/// Uruchamia pulpit
void DesktopShow(void);

/// Wywoluje funkcje uruchomienia wybranej opcji menu
void DesktopInvokeShowFunction(Option option);

#endif		/// _DESKTOP_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
