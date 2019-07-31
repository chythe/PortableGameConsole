/**************************************************************************//**
* @file     Snake.c
* @brief    Gra Snake - source file
* @author   Mateusz Chudy
******************************************************************************/

#define F_CPU 16000000UL // CPU 16MHz
#include <util/delay.h>
#include <stdlib.h>
#include <time.h>
#include "Snake.h"
#include "ToolSet.h"
#include "Font.h"

/**************************************************************************//**
 * @brief Inicjalizuje gre Snake.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize - wskaznik na rozmiar weza
 * @param food - wskaznik na element pokarmu
 * @return wskaznik na tablice elementow weza
 *****************************************************************************/
Element** SnakeInit(Element** snakeElements, uint8_t* snakeSize, Element* food)
{
	uint8_t i;

	srand(time(NULL));
	GraphicsClearScreen(SNAKE_BACKGROUND_COLOR);
	for (i = 0; i < SNAKE_START_SIZE; i++)
	{
		snakeElements = SnakeElementAdd(snakeElements,
				snakeSize,
				ToolsRandom(BLACK + SNAKE_COLOR_FILTER,
						WHITE - SNAKE_COLOR_FILTER),
				SNAKE_START_X, SNAKE_START_Y + i,
				SNAKE_START_DERECTION);
	}
	food->newDirection = CONST;
	food->oldDirection = CONST;
	SnakeNewFood(snakeElements, (*snakeSize), food);

	return snakeElements;
}

/**************************************************************************//**
 * @brief Wlacza gre Snake.
 *****************************************************************************/
void SnakePlay(void)
{
	uint8_t collision, snakeSize = 0;
	Element food;
	Element** snakeElements = SnakeInit(snakeElements, &snakeSize, &food);

	do
	{
		snakeElements = SnakeCheckChangeDirection(snakeElements, &snakeSize);
		snakeElements = SnakeCheckFood(snakeElements, &snakeSize, &food);
		snakeElements = SnakeMove(snakeElements, &snakeSize, &food);
		snakeElements = SnakeUpdateDirections(snakeElements, &snakeSize);
		collision = SnakeCheckCollision(snakeElements, snakeSize, 0x00);
	} while (0x00 == collision);

	_delay_ms(SNAKE_DELAY);
	snakeElements = SnakeDestroy(snakeElements, &snakeSize);
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
