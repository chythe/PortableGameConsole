/**************************************************************************//**
* @file     Snake.h
* @brief    Gra Snake - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdint.h>
#include "LCDController.h"
#include "SnakeElements.h"
#include "AccelerometerController.h"

#define SNAKE_START_SIZE			3
#define SNAKE_START_X				6
#define SNAKE_START_Y				0
#define SNAKE_MAX_X					11
#define SNAKE_MAX_Y					15
#define SNAKE_START_DERECTION		DOWN
#define SNAKE_BACKGROUND_COLOR		0x1002
#define SNAKE_COLOR_FILTER			0x4444
#define SNAKE_DELAY					200

/// Inicjalizuje gre Snake
Element** SnakeInit(Element** snakeElements, uint8_t* snakeSize, Element* food);

/// Wlacza gre Snake
void SnakePlay(void);

#endif		// _SNAKE_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
