/**************************************************************************//**
* @file     PingPong.h
* @brief    Gra Ping Pong - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _PING_PONG_H_
#define _PING_PONG_H_

#include <stdint.h>
#include <stdbool.h>

#define PONG_ACCE_SENSITIVITY		10
#define PONG_DISP_SENSITIVITY		1
#define PONG_Y_POS					300
#define PONG_LINE_SIZE				60
#define PONG_BALL_SPEED				20
#define PONG_LINE_SPEED				2
#define PONG_MIN_X				    0
#define PONG_MAX_X				    240
#define PONG_MIN_Y				    0
#define PONG_MAX_Y				    320

/// Wektor
typedef struct
{
	int8_t x;
	int8_t y;
} Vector;

/// Oblicza nowe wspolrzedne pilki
bool CalculateBallPosition(uint8_t* newX, uint16_t* newY, uint8_t lineX, Vector* moveVector);

/// Oblicza nowe wspolrzedne lini
void CalculateLinePosition(uint8_t* newX);

/// Wlacza gre Ping Pong
void PingPongPlay(void);

#endif		// _PING_PONG_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
