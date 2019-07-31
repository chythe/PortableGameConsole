/**************************************************************************//**
* @file     GamesMenu.c
* @brief    Menu z grami - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <DisplayTexts.h>
#include "GamesMenu.h"
#include "Question.h"
#include "TouchController.h"

/**************************************************************************//**
 * @brief Wyswietla menu z grami.
 *****************************************************************************/
void GamesMenuShow(void)
{
	uint8_t i;
	interruptFlag = 0;

	for (i = 0; i < LAST; i++)
		buttonArray[i] = ButtonDestroy(buttonArray[i]);

	GraphicsClearScreen(GRAY);

	struct Button *buttonSnake = ButtonCreate(PING_PONG_TEXT,
			MAIN,
			GAMES_PONG_TEXT_COLOR,
			GAMES_PONG_BUTTON_COLOR,
			GAMES_PONG_BUTTON_X1,
			GAMES_PONG_BUTTON_Y1,
			GAMES_PONG_BUTTON_X2 - GAMES_PONG_BUTTON_X1,
			GAMES_PONG_BUTTON_Y2 - GAMES_PONG_BUTTON_Y1);
	buttonArray[PING_PONG] = buttonSnake;
	buttonArray[PING_PONG]->Display(buttonSnake);

	struct Button *buttonPong = ButtonCreate(SNAKE_TEXT,
			MAIN,
			GAMES_SNAKE_TEXT_COLOR,
			GAMES_SNAKE_BUTTON_COLOR,
			GAMES_SNAKE_BUTTON_X1,
			GAMES_SNAKE_BUTTON_Y1,
			GAMES_SNAKE_BUTTON_X2 - GAMES_SNAKE_BUTTON_X1,
			GAMES_SNAKE_BUTTON_Y2 - GAMES_SNAKE_BUTTON_Y1);
	buttonArray[SNAKE] = buttonPong;
	buttonArray[SNAKE]->Display(buttonPong);

	struct Button *buttonBack = ButtonCreate(BACK_TEXT,
			MAIN,
			BACK_TEXT_COLOR,
			BACK_BUTTON_COLOR,
			BACK_BUTTON_X1,
			BACK_BUTTON_Y1,
			BACK_BUTTON_X2 - BACK_BUTTON_X1,
			BACK_BUTTON_Y2 - BACK_BUTTON_Y1);
	buttonArray[BACK] = buttonBack;
	buttonArray[BACK]->Display(buttonBack);
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------

