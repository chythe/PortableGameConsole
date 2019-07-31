/**************************************************************************//**
* @file     PingPong.c
* @brief    Gra Ping Pong - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <DisplayTexts.h>
#include "PingPong.h"
#include "GraphicsPrimitives.h"
#include "AccelerometerController.h"
#include "LCDController.h"
#include <stdint.h>

/**************************************************************************//**
 * @brief Oblicza nowe wspolrzedne pilki.
 * @param newX - nowa wartosc wspolrzednej x
 * @param newX - nowa wartosc wspolrzednej y
 * @param lineX - wspolrzedna x lini
 * @param moveVector - wskaznik na wektor przesuniecia pilki
 *****************************************************************************/
bool CalculateBallPosition(uint8_t* newX, uint16_t* newY,
		uint8_t lineX, Vector* moveVector)
{
	if (PONG_MAX_X < *newX + 20 || PONG_MIN_X >= *newX)
	{
		moveVector->x = moveVector->x * -1;
	}
	if (PONG_MIN_Y >= *newY || (PONG_Y_POS < *newY + 20 &&
			(lineX < *newX + 10 && lineX + PONG_LINE_SIZE > *newX + 10)))
	{
		moveVector->y = moveVector->y * -1;
	}
	if (PONG_Y_POS < *newY && (lineX >= *newX + 10 ||
			lineX + PONG_LINE_SIZE <= *newX + 10))
	{
		FontDisplayString(GAME_OVER_TEXT, BLUE, BLACK, 10, 100);
		return true;
	}
	*newX += moveVector->x;
	*newY += moveVector->y;
	return false;
}

/**************************************************************************//**
 * @brief Oblicza nowe wspolrzedne lini.
 * @param newX - nowa wartosc wspolrzednej x lini
 *****************************************************************************/
void CalculateLinePosition(uint8_t* newX)
{
	int8_t angleX;
	angleX = AccelerometerGetAngle(AXIS_X);
	if (angleX < X0 - PONG_ACCE_SENSITIVITY) // lewo
	{
		if (*newX > PONG_MIN_X)
			*newX -= PONG_LINE_SPEED;
	}
	else if (angleX > X0 + PONG_ACCE_SENSITIVITY) // prawo
	{
		if (*newX + PONG_LINE_SIZE < PONG_MAX_X)
			*newX += PONG_LINE_SPEED;
	}
}

/**************************************************************************//**
 * @brief Wlacza gre Ping Pong.
 *****************************************************************************/
void PingPongPlay(void)
{
	Vector moveVector;
	int8_t pointX = 110, lineX = 90;
	uint16_t pointY = 150;
	moveVector.x = 1;
	moveVector.y = 1;

	GraphicsClearScreen(BLACK);
	while (1)
	{
		// line
		GraphicsClearArea(BLACK, lineX, PONG_Y_POS, PONG_LINE_SIZE, 5);
		CalculateLinePosition(&lineX);
		GraphicsClearArea(RED, lineX, PONG_Y_POS, PONG_LINE_SIZE, 5);

		// ball
		GraphicsClearArea(BLACK, pointX, pointY, 20, 20);
		if (CalculateBallPosition(&pointX, &pointY, lineX, &moveVector))
			break;
		GraphicsClearArea(GREEN, pointX, pointY, 20, 20);
	}
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
