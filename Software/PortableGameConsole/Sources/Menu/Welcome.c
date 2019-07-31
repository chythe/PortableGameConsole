/**************************************************************************//**
* @file     Welcome.c
* @brief    Ekran powitalny - source file
* @author   Mateusz Chudy
******************************************************************************/

#define F_CPU 16000000UL // CPU 16MHz
#include <util/delay.h>
#include "Welcome.h"
#include "GraphicsPrimitives.h"
#include "Font.h"
#include <DisplayTexts.h>

/**************************************************************************//**
 * @brief Wyswietla ekran powitalny.
 *****************************************************************************/
void WelcomeShow(void)
{
	GraphicsClearScreen(BLACK);
	FontDisplayString(WELCOME_TEXT, WELCOME_STRING_COLOR, BLACK, WELCOME_X_POS, WELCOME_Y_POS);
	_delay_ms(WELCOME_TIME);
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
