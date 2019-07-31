/**************************************************************************//**
* @file     Question.h
* @brief    Pytanie z funkcjami wyboru - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _QUESTION_H_
#define _QUESTION_H_

#include <stdint.h>
#include <stdbool.h>
#include "MenuOptions.h"

#define QUESTION_BACKGROUND_COLOR	GRAY
#define QUESTION_TEXT_COLOR			BLACK
#define QUESTION_Y_POS				80
#define ANSWER_Y_POS				160
#define YES_X_POS					30
#define NO_X_POS					150
#define YES_COLOR					GREEN
#define NO_COLOR					RED
#define QUEST_BUTTON_WIDTH			60
#define QUEST_BUTTON_HEIGHT			40

/// Wyswietla pytanie i przyciski odpowiedzi
void QuestionDisplay(char* string, Option yes, Option no);

#endif		// _QUESTION_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
