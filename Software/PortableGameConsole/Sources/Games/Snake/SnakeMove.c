/**************************************************************************//**
* @file     SnakeMove.c
* @brief    Ruch weza dla gry Snake - source file
* @author   Mateusz Chudy
******************************************************************************/

#define F_CPU 16000000UL // CPU 16MHz
#include <util/delay.h>
#include "SnakeMove.h"
#include "Snake.h"
#include "LCDController.h"

/**************************************************************************//**
 * @brief Sprawdza kolizje weza.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize - rozmiar weza
 * @param isFall - flaga wskazujaca czy w grze obecne sa sciany
 * @return wartosc logiczna wskazujaca na kolizje lub jej brak
 *****************************************************************************/
uint8_t SnakeCheckCollision(Element** snakeElements, uint8_t snakeSize, uint8_t isFall)
{
	int16_t i;

	if (snakeSize < 4)
		return 0x00;

	if (isFall && (snakeElements[snakeSize - 1]->x < 0 ||
			snakeElements[snakeSize - 1]->x > SNAKE_MAX_X ||
			snakeElements[snakeSize - 1]->y < 0 ||
			snakeElements[snakeSize - 1]->y > SNAKE_MAX_Y))
		return 0xFF;

	for (i = snakeSize - 4; i >= 0; --i)
	{
		if (snakeElements[i]->x == snakeElements[snakeSize - 1]->x &&
				snakeElements[i]->y == snakeElements[snakeSize - 1]->y)
			return 0xFF;
	}

	return 0x00;
}

/**************************************************************************//**
 * @brief Sprawdza i zmienia kierunek wenza.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize - wskaznik na rozmiar weza
 * @return wskaznik na tablice elementow weza
 *****************************************************************************/
Element** SnakeCheckChangeDirection(Element** snakeElements, uint8_t* snakeSize)
{
	switch (AccelerometerGetDirection())
	{
	case LEFT:
		if (snakeElements[*snakeSize - 1]->newDirection != LEFT &&
				snakeElements[*snakeSize - 1]->newDirection != RIGHT)
		{
			snakeElements[*snakeSize - 1]->oldDirection = LEFT;
			snakeElements[*snakeSize - 1]->newDirection = LEFT;
		}
		break;
	case RIGHT:
		if (snakeElements[*snakeSize - 1]->newDirection != RIGHT &&
				snakeElements[*snakeSize - 1]->newDirection != LEFT)
		{
			snakeElements[*snakeSize - 1]->oldDirection = RIGHT;
			snakeElements[*snakeSize - 1]->newDirection = RIGHT;
		}
		break;
	case UP:
		if (snakeElements[*snakeSize - 1]->newDirection != UP &&
				snakeElements[*snakeSize - 1]->newDirection != DOWN)
		{
			snakeElements[*snakeSize - 1]->oldDirection = UP;
			snakeElements[*snakeSize - 1]->newDirection = UP;
		}
		break;
	case DOWN:
		if (snakeElements[*snakeSize - 1]->newDirection != DOWN &&
				snakeElements[*snakeSize - 1]->newDirection != UP)
		{
			snakeElements[*snakeSize - 1]->oldDirection = DOWN;
			snakeElements[*snakeSize - 1]->newDirection = DOWN;
		}
		break;
	}
	return snakeElements;
}

/**************************************************************************//**
 * @brief Sprawdza czy waz natrafil na pokarm, jesli takrysuje nowy i zwieksza wenza.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize - wskaznik na rozmiar weza
 * @param food - wskaznik na element pokarmu
 * @return wskaznik na tablice elementow weza
 *****************************************************************************/
Element** SnakeCheckFood(Element** snakeElements, uint8_t* snakeSize, Element* food)
{
	if (snakeElements[*snakeSize - 1]->x == food->x &&
			snakeElements[*snakeSize - 1]->y == food->y)
	{
		switch (snakeElements[*snakeSize - 1]->newDirection)
		{
		case LEFT:
			snakeElements = SnakeElementAdd(snakeElements, snakeSize, food->color,
					snakeElements[*snakeSize - 1]->x - 1,
					snakeElements[*snakeSize - 1]->y, LEFT);
			break;
		case RIGHT:
			snakeElements = SnakeElementAdd(snakeElements, snakeSize, food->color,
					snakeElements[*snakeSize - 1]->x + 1,
					snakeElements[*snakeSize - 1]->y, RIGHT);
			break;
		case UP:
			snakeElements = SnakeElementAdd(snakeElements, snakeSize, food->color,
					snakeElements[*snakeSize - 1]->x,
					snakeElements[*snakeSize - 1]->y - 1, UP);
			break;
		case DOWN:
			snakeElements = SnakeElementAdd(snakeElements, snakeSize, food->color,
					snakeElements[*snakeSize - 1]->x,
					snakeElements[*snakeSize - 1]->y + 1, DOWN);
			break;
		}
		SnakeNewFood(snakeElements, (*snakeSize), food);
	}

	return snakeElements;
}

/**************************************************************************//**
 * @brief Aktualizuje kierunki dla elementow wenza.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize - wskaznik na rozmiar weza
 * @return wskaznik na tablice elementow weza
 *****************************************************************************/
Element** SnakeUpdateDirections(Element** snakeElements, uint8_t* snakeSize)
{
	int16_t i;

	for (i = (*snakeSize) - 2; i >= 0; --i)
	{
		snakeElements[i]->oldDirection = snakeElements[i]->newDirection;
		snakeElements[i]->newDirection = snakeElements[i + 1]->oldDirection;
	}

	return snakeElements;
}

/**************************************************************************//**
 * @brief Przemieszcza wenza na ekranie.
 * @param snakeElements - wskaznik na tablice elementow weza
 * @param snakeSize - wskaznik na rozmiar weza
 * @param food - wskaznik na element pokarmu
 * @return wskaznik na tablice elementow weza
 *****************************************************************************/
Element** SnakeMove(Element** snakeElements, uint8_t* snakeSize, Element* food)
{
	int16_t i;

	_delay_ms(SNAKE_DELAY);
	for (i = (*snakeSize) - 1; i >= 0; --i)
	{
		SnakeDiplayElement(snakeElements[i], true);
		switch (snakeElements[i]->newDirection)
		{
		case LEFT:
			if (0 >= snakeElements[i]->x)
				snakeElements[i]->x = SNAKE_MAX_X;
			else
				--(snakeElements[i]->x);
			break;
		case RIGHT:
			if (SNAKE_MAX_X <= snakeElements[i]->x)
				snakeElements[i]->x = 0;
			else
				++(snakeElements[i]->x);
			break;
		case UP:
			if (0 >= snakeElements[i]->y)
				snakeElements[i]->y = SNAKE_MAX_Y;
			else
				--(snakeElements[i]->y);
			break;
		case DOWN:
			if (SNAKE_MAX_Y <= snakeElements[i]->y)
				snakeElements[i]->y = 0;
			else
				++(snakeElements[i]->y);
			break;
		}
		SnakeDiplayElement(snakeElements[i], false);
	}

	return snakeElements;
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
