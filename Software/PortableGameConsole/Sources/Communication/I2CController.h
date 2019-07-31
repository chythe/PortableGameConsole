/**************************************************************************//**
* @file     I2CController.h
* @brief    Kontroler interfejsu I2C - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _I2C_CONTROLLER_H_
#define _I2C_CONTROLLER_H_

#include <stdint.h>

/// Inicjalizuje komunikacje po I2C
void I2CInit(void);

/// Wlacza przesyl / odbior danych po I2C
void I2CStart(void);

/// Wysyla bajt danych
void I2CWriteByte(int8_t byte);

/// Odbiera bajt danych
int8_t I2CReadByte(void);

/// Odbiera ostatni bajt danych
int8_t I2CReadLastByte(void);

/// Wylacza przesyl / odbior danych po I2C
void I2CStop(void);

#endif		// _I2C_CONTROLLER_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
