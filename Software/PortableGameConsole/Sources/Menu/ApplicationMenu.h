/**************************************************************************//**
* @file     ApplicationMenu.h
* @brief    Menu z aplikacjami - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _APPLICATION_MENU_H_
#define _APPLICATION_MENU_H_

#include <stdint.h>
#include "Desktop.h"
#include "LCDController.h"

#define APP_PAINT_BUTTON_X1		            0
#define APP_PAINT_BUTTON_Y1		            0
#define APP_PAINT_BUTTON_X2		            240
#define APP_PAINT_BUTTON_Y2		            40
#define APP_PAINT_BUTTON_COLOR		        DARKBLUE
#define APP_PAINT_TEXT_COLOR		        WHITE

#define APP_SPIRIT_LEVEL_BUTTON_X1		    0
#define APP_SPIRIT_LEVEL_BUTTON_Y1		    40
#define APP_SPIRIT_LEVEL_BUTTON_X2		    240
#define APP_SPIRIT_LEVEL_BUTTON_Y2		    80
#define APP_SPIRIT_LEVEL_BUTTON_COLOR	    0X01CA
#define APP_SPIRIT_LEVEL_TEXT_COLOR		    WHITE

/// Wyswietla menu z aplikacjami
void ApplicationMenuShow(void);

#endif		// _APPLICATION_MENU_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
