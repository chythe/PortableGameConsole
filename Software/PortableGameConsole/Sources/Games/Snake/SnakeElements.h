/**************************************************************************//**
* @file     SnakeElements.h
* @brief    Elementy weza dla gry Snake - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _SNAKE_ELEMENTS_H_
#define _SNAKE_ELEMENTS_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LCDController.h"
#include "GraphicsPrimitives.h"
#include "AccelerometerController.h"

#define ELEMENT_SIZE					20
#define CHANGE_SIZE_FREQUENCY			100

/// Wyswietlany element
typedef struct
{
	uint8_t x;
	uint8_t y;
	Color color;
	Direction newDirection;
	Direction oldDirection;
} Element;

/// Wyswietla element
void SnakeDiplayElement(Element* element, bool clear);

/// Tworzy nowy pokarm i rysuje go
void SnakeNewFood(Element** snakeElements, uint8_t snakeSize, Element* food);

/// Dodaje element do wenza
Element** SnakeElementAdd(Element** snakeElements, uint8_t* snakeSize, Color color, uint8_t x, uint8_t y, Direction direction);

/// Niszczy tablice elementow wenza
Element** SnakeDestroy(Element** snakeElements, uint8_t* snakeSize);

#endif		// _SNAKE_ELEMENTS_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
