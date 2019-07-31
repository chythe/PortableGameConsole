/**************************************************************************//**
* @file     AccelerometerController.c
* @brief    Kontroler akcelerometru - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <avr/io.h>
#include <stdlib.h>
#include "AccelerometerController.h"
#include "I2CController.h"

/**************************************************************************//**
 * @brief Inicjalizuje akcelerometr.
 *****************************************************************************/
void AccelerometerInit(void)
{
	I2CStart();
	I2CWriteByte(0x3A); // wybranie akceleratora 38h czyli SD0 polaczone z VCC
	I2CWriteByte(0x20); // CTRL_REG1_A ustawienie predkosci transmisji na 400khz
	I2CWriteByte(0xC7); // 11 000 111 DR=1 (400Hz) PD=1 (power on) FS=0 (default) 0 0  111 (wlaczenie X Y Z)
	I2CStop();
}

/**************************************************************************//**
 * @brief Pobiera wartosc proporcjonalna do kata nachylenia do danej osi.
 * @param axis - indeks rejestru, pod ktorym znajduje sie wartosc dla danej osi
 * @return wartosc proporcjonalna do kata nachylenia do danej osi
 *****************************************************************************/
int8_t AccelerometerGetAngle(Axis axis)
{
	int8_t angle;
	static int8_t present = 0xFF;

	if (present)
	{
		I2CStart();
		I2CWriteByte(WRITE); // wysylanie
		I2CWriteByte(axis);
		I2CStart();
		I2CWriteByte(READ); // czytanie
		angle = I2CReadLastByte();
		I2CStop();
	}

	return angle;
}

/**************************************************************************//**
 * @brief Pobiera kierunek nachylenia.
 * @return kierunek nachylenia
 *****************************************************************************/
Direction AccelerometerGetDirection(void)
{
	int8_t ax, ay;

	ax = AccelerometerGetAngle(AXIS_X);
	if (ax < X0 - ACCE_SENSITIVITY) // lewo
		return LEFT;
	else if (ax > X0 + ACCE_SENSITIVITY) // prawo
		return RIGHT;
	ay = AccelerometerGetAngle(AXIS_Y);
	if (ay < Y0 - ACCE_SENSITIVITY) // dol
		return UP;
	else if (ay > Y0 + ACCE_SENSITIVITY) // gora
		return DOWN;

	return CONST;
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------

