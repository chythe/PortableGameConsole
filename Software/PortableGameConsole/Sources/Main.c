/**************************************************************************//**
* @file     Main.c
* @brief    Zrodlo z glowna funkcja programu - source file
* @author   Mateusz Chudy
******************************************************************************/

#define F_CPU 16000000UL // CPU 16MHz
#include <util/delay.h>
#include "AccelerometerController.h"
#include "SPIController.h"
#include "TouchController.h"
#include "LCDController.h"
#include "I2CController.h"
#include "Welcome.h"
#include "Desktop.h"

/**************************************************************************//**
 * @brief Glowna funkcja programu.
 * @return 0
 *****************************************************************************/
int main(void)
{
	_delay_us(100);
	I2CInit();
	AccelerometerInit();
	TouchInit();
	SPIInit();
	LCDInit();
	WelcomeShow();
	DesktopShow();
	while (1)
	{
		if (interruptFlag != 0)
			DesktopCheckSelect();
	}
	return 0;
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
