/**************************************************************************//**
* @file     SPIController.c
* @brief    Kontroler interfejsu SPI - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <avr/io.h>
#include "SPIController.h"

/**************************************************************************//**
 * @brief Inicjalizuje komunikacje po SPI.
 *****************************************************************************/
void SPIInit(void)
{
	DDRB = 0xFF;
	PORTB = 0X00;

	SPCR = 0x50;
	SPSR = 0x00;
}

/**************************************************************************//**
 * @brief Wysyla / odbiera bajt danych z magistrali SPI.
 * @param data - wysylany bajt danych
 * @return odebrany bajt danych
 *****************************************************************************/
uint8_t SPICommunication(uint8_t data)
{
	SPDR = data;
	while (!(SPSR & (1 << SPIF)));
	return SPDR;
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
