/**************************************************************************//**
* @file     SPIController.h
* @brief    Kontroler interfejsu SPI - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _SPI_CONTROLLER_H_
#define _SPI_CONTROLLER_H_

#include <stdint.h>

/// Inicjalizuje komunikacje po SPI
void SPIInit(void);

/// Wysyla / odbiera bajt danych z magistrali SPI
uint8_t SPICommunication(uint8_t data);

#endif		// _SPI_CONTROLLER_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
