/**************************************************************************//**
* @file     MainMenu.h
* @brief    Menu glowne - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include <stdint.h>
#include "Desktop.h"
#include "LCDController.h"

#define MAIN_GAMES_BUTTON_X1			0
#define MAIN_GAMES_BUTTON_Y1			0
#define MAIN_GAMES_BUTTON_X2			240
#define MAIN_GAMES_BUTTON_Y2			40
#define MAIN_GAMES_BUTTON_COLOR			DARKBLUE
#define MAIN_GAMES_TEXT_COLOR			WHITE

#define MAIN_APP_BUTTON_X1				0
#define MAIN_APP_BUTTON_Y1				40
#define MAIN_APP_BUTTON_X2				240
#define MAIN_APP_BUTTON_Y2				80
#define MAIN_APP_BUTTON_COLOR			0X01CA
#define MAIN_APP_TEXT_COLOR				WHITE

/// Wyswietla menu glowne
void MainMenuShow(void);

#endif		// _MAIN_MENU_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
