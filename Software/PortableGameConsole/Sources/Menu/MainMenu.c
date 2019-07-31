/**************************************************************************//**
* @file     MainMenu.c
* @brief    Menu glowne - source file
* @author   Mateusz Chudy
******************************************************************************/

#define F_CPU 16000000UL // CPU 16MHz
#include <util/delay.h>
#include "MainMenu.h"
#include "GraphicsPrimitives.h"
#include "Font.h"
#include <DisplayTexts.h>
#include "Button.h"
#include "TouchController.h"

/**************************************************************************//**
 * @brief Wyswietla menu glowne.
 *****************************************************************************/
void MainMenuShow(void)
{
	uint8_t i;
	interruptFlag = 0;

	for (i = 0; i < LAST; i++)
		buttonArray[i] = ButtonDestroy(buttonArray[i]);

	GraphicsClearScreen(GRAY);

	struct Button *buttonGames = ButtonCreate(GAMES_TEXT,
			DESKTOP,
			MAIN_GAMES_TEXT_COLOR,
			MAIN_GAMES_BUTTON_COLOR,
			MAIN_GAMES_BUTTON_X1,
			MAIN_GAMES_BUTTON_Y1,
			MAIN_GAMES_BUTTON_X2 - MAIN_GAMES_BUTTON_X1,
			MAIN_GAMES_BUTTON_Y2 - MAIN_GAMES_BUTTON_Y1);
	buttonArray[GAMES] = buttonGames;
	buttonArray[GAMES]->Display(buttonGames);

	struct Button *buttonApp = ButtonCreate(APPLICATION_TEXT,
			DESKTOP,
			MAIN_APP_TEXT_COLOR,
			MAIN_APP_BUTTON_COLOR,
			MAIN_APP_BUTTON_X1,
			MAIN_APP_BUTTON_Y1,
			MAIN_APP_BUTTON_X2 - MAIN_APP_BUTTON_X1,
			MAIN_APP_BUTTON_Y2 - MAIN_APP_BUTTON_Y1);
	buttonArray[APPLICATIONS] = buttonApp;
	buttonArray[APPLICATIONS]->Display(buttonApp);

	struct Button *buttonBack = ButtonCreate(BACK_TEXT,
			DESKTOP,
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

