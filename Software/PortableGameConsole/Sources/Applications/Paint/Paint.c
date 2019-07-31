/**************************************************************************//**
* @file     Paint.c
* @brief    Aplikacja do rysowania - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <DisplayTexts.h>
#include "Paint.h"
#include "GraphicsPrimitives.h"
#include "TouchController.h"

/**************************************************************************//**
 * @brief Inicjalizuje aplikacje Paint.
 * @param buttonColors - tablica dostepnych kolorow rysowania
 * @param button - wskaźnik na strukture reprezentujaca przycisk exit
 *****************************************************************************/
void PaintInit(Color* buttonColors, struct Button* button)
{
	uint8_t i;

	GraphicsClearScreen(PAINT_BACKGROUND_COLOR);
	for (i = 0; i < PAINT_BUTTONS_MAX_X; i++)
	{
		GraphicsClearArea(buttonColors[i],
				i * PAINT_BUTTONS_SIZE,
				0,
				PAINT_BUTTONS_SIZE,
				PAINT_BUTTONS_SIZE);
	}
	ButtonDisplay(button);
}

/**************************************************************************//**
 * @brief Sprawdza zmiane koloru przez urzytkownika.
 * @param buttonColors - tablica dostepnych kolorow rysowania
 * @param currentColor - obecny kolor rysowania
 * @return obecnie wybrany kolor
 *****************************************************************************/
Color PaintCheckColorChange(Color* buttonColors, Color currentColor)
{
	uint8_t i, x = touchPoint.x + CORRECT_X;
	uint16_t y = touchPoint.y + CORRECT_Y;

	for (i = 0; i < PAINT_BUTTONS_MAX_X; i++)
	{
		if (buttonColors[i] != currentColor &&
				x >= i * PAINT_BUTTONS_SIZE &&
				x <= i * PAINT_BUTTONS_SIZE + PAINT_BUTTONS_SIZE &&
				y >= 0 &&
				y <= PAINT_BUTTONS_SIZE)
			return buttonColors[i];
	}
	return currentColor;
}

/**************************************************************************//**
 * @brief Wlacza aplikacje Paint.
 *****************************************************************************/
void PaintShow(void)
{
	ExecuteResult result = EXECUTE_OK;
	Color buttonColors[PAINT_BUTTONS_MAX_X] =
		{RED, GREEN, BLUE, YELLOW, ORANGE, BLACK, WHITE, DARKGRAY};
	Color currentColor = BLACK;
	struct Button* exit = ButtonCreate(EXIT_TEXT, PAINT, BLACK, RED,
			PAINT_EXIT_BUTTON_X, PAINT_EXIT_BUTTON_Y,
			PAINT_BUTTONS_SIZE + 10, PAINT_BUTTONS_SIZE);

	PaintInit(buttonColors, exit);

	while (!ButtonCheck(exit))
	{
		currentColor = PaintCheckColorChange(buttonColors, currentColor);
		result = TouchReadContinue();
		GraphicsPutPixel(currentColor, touchPoint.x + CORRECT_X, touchPoint.y + CORRECT_Y);
	}

	free(exit);
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
