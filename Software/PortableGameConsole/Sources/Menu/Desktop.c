/**************************************************************************//**
* @file     Desktop.c
* @brief    Pulpit z wejsciem menu - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <DisplayTexts.h>
#include <stdbool.h>
#include "string.h"
#include "Desktop.h"
#include "GraphicsPrimitives.h"
#include "Font.h"
#include "TouchController.h"
#include "ApplicationMenu.h"
#include "MainMenu.h"
#include "GamesMenu.h"
#include "Button.h"
#include "PingPong.h"
#include "Question.h"
#include "Snake/Snake.h"
#include "Paint.h"

/**************************************************************************//**
 * @brief Sprawdza wybranie opcji z menu.
 *****************************************************************************/
void DesktopCheckSelect(void)
{
	cli();
	uint8_t i;
	TouchReadContinue();
	for (i = 0; i < LAST; i++)
	{
		if (ButtonCheck(buttonArray[i]))
		{
			if (BACK == i || NO == i || YES == i)
				DesktopInvokeShowFunction(buttonArray[i]->earlierOption);
			else
				DesktopInvokeShowFunction(i);
			touchPoint.x = 0xFF;
			touchPoint.y = 0xFFFF;
			break;
		}
	}
	sei();
}

/**************************************************************************//**
 * @brief Uruchamia pulpit.
 *****************************************************************************/
void DesktopShow(void)
{
	uint8_t i;
	interruptFlag = 0;
	for (i = 0; i < LAST; i++)
		buttonArray[i] = ButtonDestroy(buttonArray[i]);
	GraphicsClearScreen(GRAY);
	struct Button *buttonMenu = ButtonCreate(MENU_TEXT,
			LAST,
			DESK_MENU_TEXT_COLOR,
			DESK_MENU_BUTTON_COLOR,
			DESK_MENU_BUTTON_X1,
			DESK_MENU_BUTTON_Y1,
			DESK_MENU_BUTTON_X2 - DESK_MENU_BUTTON_X1,
			DESK_MENU_BUTTON_Y2 - DESK_MENU_BUTTON_Y1);
	buttonArray[MAIN] = buttonMenu;
	buttonArray[MAIN]->Display(buttonMenu);
}

/**************************************************************************//**
 * @brief Wywoluje funkcje uruchomienia wybranej opcji menu.
 * @param option - opcja ktora uruchamiamy
 *****************************************************************************/
void DesktopInvokeShowFunction(Option option)
{
	switch (option)
	{
	case DESKTOP:
		DesktopShow();
		break;
	case MAIN:
		MainMenuShow();
		break;
	case GAMES:
		GamesMenuShow();
		break;
	case APPLICATIONS:
		ApplicationMenuShow();
		break;
	case SNAKE:
		SnakePlay();
		QuestionDisplay(GAME_RETRY_QUESTION, SNAKE, GAMES);
		break;
	case PING_PONG:
		PingPongPlay();
		QuestionDisplay(GAME_RETRY_QUESTION, PING_PONG, GAMES);
		break;
	case PAINT:
		PaintShow();
		break;
	default:
		FontDisplayString(UNKNOWN_OPTION_TEXT, RED, GRAY, 70, 110);
		break;
	}
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
