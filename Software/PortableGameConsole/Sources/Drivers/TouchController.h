/**************************************************************************//**
* @file     TouchController.h
* @brief    Kontroler sterownika dotyku XPT2046 - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _TOUCH_CONTROLLER_H_
#define _TOUCH_CONTROLLER_H_

#include <stdint.h>
#include <avr/interrupt.h>
#include <GlobalErrors.h>

#define TOUCH_CS_H()	PORTD |= (1 << PD4);
#define TOUCH_CS_L()	PORTD &= ~(1 << PD4);

#define CMD_READ_X		0xD0
#define CMD_READ_Y		0x90

#define ERR_RANGE		50
#define READ_TIMES		10
#define LOST_VAL		4

#define CORRECT_X		-20
#define CORRECT_Y		-2

/// Punkt dotkniecia
typedef struct
{
	uint8_t x;
	uint16_t y;
	uint32_t xad;
	uint32_t yad;
	uint8_t status;
} TouchPoint;

/// Globalny punkt dotknięcia
TouchPoint touchPoint;

/// Globalna flaga wskazujaca na dotkniecie w ekran
volatile uint8_t interruptFlag;

/// Procedura obslugi przerwania dotkniecia w ekran
ISR(INT0_vect);

/// Inicjalizuje sterownik dotyku
void TouchInit(void);

/// Pobiera ze sterownika pojedynczy wynik ADC
uint16_t TouchGetADC(uint8_t cmdCode);

/// Pobiera ze sterownika kilka razy wynik ADC i filtruje zwracana wartosc
uint16_t TouchGetADCEx(uint8_t cmdCode);

/// Pobiera ze sterownika przefiltrowane wyniki konwersji AD dla osi x i y
ExecuteResult TouchReadADS(uint16_t* xad, uint16_t* yad);

/// Dwukrotnie pobiera ze sterownika przefiltrowane wyniki konwersji AD dla osi x i y
ExecuteResult TouchReadADS2(uint32_t* xad, uint32_t* yad);

/// Konwertuje wartosci odczytanych ADC na wartosci wspolrzednych
void TouchConvertAdToXy(void);

/// Pobiera jednokrotnie wspolrzedne dotkniecia
ExecuteResult TouchReadOnce(void);

/// Pobiera wspolrzedne dotkniecia w sposob ciagly
ExecuteResult TouchReadContinue(void);

#endif		// _TOUCH_SCREEN_CONTROLLER_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------

