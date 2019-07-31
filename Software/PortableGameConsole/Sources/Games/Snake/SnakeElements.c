/**************************************************************************//**
* @file     SnakeElements.c
* @brief    Elementy weza dla gry Snake - source file
* @author   Mateusz Chudy
******************************************************************************/

#include "SnakeElements.h"
#include "ToolSet.h"
#include "Snake.h"
#include <stdbool.h>

/**************************************************************************//**
 * @brief Wyswietla element.
 * @param element - wskaznik na wyswietlany element
 * @param clear - flaga oznaczajaca czy zamazujemy
 *****************************************************************************/
void SnakeDiplayElement(Element* element, bool clear)
{
	if (clear)
		GraphicsClearArea(SNAKE_BACKGROUND_COLOR,
				element->x * ELEMENT_SIZE,
				element->y * ELEMENT_SIZE,
				ELEMENT_SIZE, ELEMENT_SIZE);
	else
		GraphicsClearArea(element->color,
				element->x * ELEMENT_SIZE,
				element->y * ELEMENT_SIZE,
				ELEMENT_SIZE, ELEMENT_SIZE);
}

/**************************************************************************//**
 * @brief Tworzy nowy pokarm i rysuje go.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize - rozmiar weza
 * @param food - wskaznik na element pokarmu
 *****************************************************************************/
void SnakeNewFood(Element** snakeElements, uint8_t snakeSize, Element* food)
{
	uint8_t i;
	bool ok = true;

	food->color = ToolsRandom(BLACK + SNAKE_COLOR_FILTER,
			WHITE - SNAKE_COLOR_FILTER);
	do
	{
		food->x = ToolsRandom(0, SNAKE_MAX_X);
		food->y = ToolsRandom(0, SNAKE_MAX_Y);
		for (i = 0; i < snakeSize; i++)
		{
			if (snakeElements[i]->x == food->x &&
					snakeElements[i]->y == food->y)
			{
				ok = false;
				break;
			}
		}
	} while (false == ok);

	SnakeDiplayElement(food, false);
}

/**************************************************************************//**
 * @brief Dodaje element do wenza.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize - wskaznik na rozmiar weza
 * @param color - kolor elementu
 * @param x - wspolrzedna x elementu
 * @param y - wspolrzedna y elementu
 * @param direction - kierunek ruchu elementu
 * @return wskaznik na tablice elementow weza
 *****************************************************************************/
Element** SnakeElementAdd(Element** snakeElements, uint8_t* snakeSize,
		Color color, uint8_t x, uint8_t y, Direction direction)
{
	if ((*snakeSize) % CHANGE_SIZE_FREQUENCY == 0)
		snakeElements = (Element**)realloc((void*)snakeElements,
				((*snakeSize) + CHANGE_SIZE_FREQUENCY) * sizeof(Element*));
	(*snakeSize)++;
	snakeElements[*snakeSize - 1] = (Element*)malloc(sizeof(Element));
	snakeElements[*snakeSize - 1]->color = color;
	snakeElements[*snakeSize - 1]->x = x;
	snakeElements[*snakeSize - 1]->y = y;
	snakeElements[*snakeSize - 1]->newDirection = direction;
	snakeElements[*snakeSize - 1]->oldDirection = direction;

	SnakeDiplayElement(snakeElements[*snakeSize - 1], false);

	return snakeElements;
}

/**************************************************************************//**
 * @brief Niszczy tablice elementow wenza.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize -  wskaznik na rozmiar weza
 * @return wskaznik na tablice elementow weza
 *****************************************************************************/
Element** SnakeDestroy(Element** snakeElements, uint8_t* snakeSize)
{
	int i;
	for (i = 0; i < *snakeSize; i++)
		free(snakeElements[i]);
	free(snakeElements);
	*snakeSize = 0;

	return snakeElements;
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------

