/**************************************************************************//**
* @file     ApplicationMenu.c
* @brief    Menu z aplikacjami - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <DisplayTexts.h>
#include "ApplicationMenu.h"
#include "TouchController.h"

/**************************************************************************//**
 * @brief Wyswietla menu z aplikacjami.
 *****************************************************************************/
void ApplicationMenuShow(void)
{
	uint8_t i;
	interruptFlag = 0;

	for (i = 0; i < LAST; i++)
		buttonArray[i] = ButtonDestroy(buttonArray[i]);

	GraphicsClearScreen(GRAY);

	struct Button *buttonPaint = ButtonCreate(PAINT_TEXT,
			MAIN,
			APP_PAINT_TEXT_COLOR,
			APP_PAINT_BUTTON_COLOR,
			APP_PAINT_BUTTON_X1,
			APP_PAINT_BUTTON_Y1,
			APP_PAINT_BUTTON_X2 - APP_PAINT_BUTTON_X1,
			APP_PAINT_BUTTON_Y2 - APP_PAINT_BUTTON_Y1);
	buttonArray[PAINT] = buttonPaint;
	buttonArray[PAINT]->Display(buttonPaint);

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
