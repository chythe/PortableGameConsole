/**************************************************************************//**
* @file     SnakeMove.h
* @brief    Ruch weza dla gry Snake - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _SNAKE_MOVE_H_
#define _SNAKE_MOVE_H_

#include <stdint.h>
#include <stdbool.h>
#include "SnakeElements.h"
#include "AccelerometerController.h"

/// Sprawdza kolizje weza
uint8_t SnakeCheckCollision(Element** snakeElements, uint8_t snakeSize, uint8_t isFall);

/// Sprawdza i zmienia kierunek wenza
Element** SnakeCheckChangeDirection(Element** snakeElements, uint8_t* snakeSize);

/// Sprawdza czy waz natrafil na pokarm, jesli takrysuje nowy i zwieksza wenza
Element** SnakeCheckFood(Element** snakeElements, uint8_t* snakeSize, Element* food);

/// Aktualizuje kierunki dla elementow wenza
Element** SnakeUpdateDirections(Element** snakeElements, uint8_t* snakeSize);

/// Przemieszcza wenza na ekranie
Element** SnakeMove(Element** snakeElements, uint8_t* snakeSize, Element* food);

#endif		// _SNAKE_MOVE_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
