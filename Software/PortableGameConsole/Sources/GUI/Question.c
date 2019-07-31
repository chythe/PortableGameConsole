/**************************************************************************//**
* @file     Question.c
* @brief    Pytanie z funkcjami wyboru - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <DisplayTexts.h>
#include "Question.h"
#include "LCDController.h"
#include "MenuOptions.h"
#include "Desktop.h"
#include "Button.h"

/**************************************************************************//**
 * @brief Wyswietla pytanie i przyciski odpowiedzi.
 * @param string - napis z pytaniem
 * @param yes -	opcja do ktorej przechodzi gdy odpowiedz jest pozytywna
 * @param no - opcja do ktorej przechodzi gdy odpowiedz jest negatywna
 *****************************************************************************/
void QuestionDisplay(char* string, Option yes, Option no)
{
	uint8_t i;

	for (i = 0; i < LAST; i++)
		buttonArray[i] = ButtonDestroy(buttonArray[i]);

	GraphicsClearScreen(GRAY);
	GraphicsClearScreen(QUESTION_BACKGROUND_COLOR);
	FontDisplayString(string, QUESTION_TEXT_COLOR, QUESTION_BACKGROUND_COLOR, LCD_SIZE_X / 2 - (strlen(string) * 8) / 2, QUESTION_Y_POS);

	struct Button *buttonYes = ButtonCreate(YES_TEXT,
			yes,
			WHITE,
			YES_COLOR,
			YES_X_POS,
			ANSWER_Y_POS,
			QUEST_BUTTON_WIDTH,
			QUEST_BUTTON_HEIGHT);
	buttonArray[YES] = buttonYes;
	buttonArray[YES]->Display(buttonYes);

	struct Button *buttonNo = ButtonCreate(NO_TEXT,
			no,
			WHITE,
			NO_COLOR,
			NO_X_POS,
			ANSWER_Y_POS,
			QUEST_BUTTON_WIDTH,
			QUEST_BUTTON_HEIGHT);
	buttonArray[NO] = buttonNo;
	buttonArray[NO]->Display(buttonNo);
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
