/**************************************************************************//**
* @file     GamesMenu.h
* @brief    Menu z grami - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _GAMES_MENU_H_
#define _GAMES_MENU_H_

#include <stdint.h>
#include "Desktop.h"
#include "LCDController.h"

#define GAMES_PONG_BUTTON_X1			0
#define GAMES_PONG_BUTTON_Y1			0
#define GAMES_PONG_BUTTON_X2			240
#define GAMES_PONG_BUTTON_Y2			40
#define GAMES_PONG_BUTTON_COLOR			DARKBLUE
#define GAMES_PONG_TEXT_COLOR			WHITE

#define GAMES_SNAKE_BUTTON_X1		    0
#define GAMES_SNAKE_BUTTON_Y1		    40
#define GAMES_SNAKE_BUTTON_X2		    240
#define GAMES_SNAKE_BUTTON_Y2		    80
#define GAMES_SNAKE_BUTTON_COLOR	    0X01CA
#define GAMES_SNAKE_TEXT_COLOR		    WHITE

/// Wyswietla menu z grami
void GamesMenuShow(void);

#endif		// _GAMES_MENU_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
