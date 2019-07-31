/**************************************************************************//**
* @file     AccelerometerController.h
* @brief    Kontroler akcelerometru - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _ACCELEROMETER_CONTROLLER_H_
#define _ACCELEROMETER_CONTROLLER_H_

#include <stdint.h>

#define X0						0
#define Y0						-5

#define WRITE					0x3A
#define READ					0x3B

#define ACCE_SENSITIVITY		10

/// Indeksy rejestrow, pod ktorymi znajduja sie dane proporcjonalne do kata nachylenia do danej osi
typedef enum
{
	AXIS_X = 0x29,
	AXIS_Y = 0x2B,
	AXIS_Z = 0x2D
} Axis;

/// Kierunek wyznaczany przez nachylenie urzadzenia
typedef enum
{
	CONST,
	UP,
	DOWN,
	LEFT,
	RIGHT
} Direction;

/// Inicjalizuje akcelerometr
void AccelerometerInit(void);

/// Pobiera wartosc proporcjonalna do kata nachylenia do danej osi
int8_t AccelerometerGetAngle(Axis axis);

/// Pobiera kierunek nachylenia
Direction AccelerometerGetDirection(void);

#endif		// _ACCELEROMETER_CONTROLLER_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
