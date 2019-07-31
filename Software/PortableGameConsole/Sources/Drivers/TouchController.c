/**************************************************************************//**
* @file     TouchController.c
* @brief    Kontroler sterownika dotyku XPT2046 - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <avr/io.h>
#define F_CPU 16000000UL // CPU 16MHz
#include <util/delay.h>
#include "SPIController.h"
#include "LCDController.h"
#include "TouchController.h"
#include "Desktop.h"

/**************************************************************************//**
 * @brief Procedura obslugi przerwania dotkniecia w ekran.
 *****************************************************************************/
ISR(INT0_vect)
{
	interruptFlag = 1;
}

/**************************************************************************//**
 * @brief Inicjalizuje sterownik dotyku.
 *****************************************************************************/
void TouchInit(void)
{
	DDRD |= 1 << PD4;
	TOUCH_CS_H();
	MCUCR |= (1 << ISC01);
	MCUCR &= ~(1 << ISC00);
	GICR |= (1 << INT0);
	sei();
	//DDRD=0XFF;
}

/**************************************************************************//**
 * @brief Pobiera ze sterownika pojedynczy wynik ADC.
 * @param cmdCode - komenda wskazujaca na os
 * @return wynik konwersji AD
 *****************************************************************************/
uint16_t TouchGetADC(uint8_t cmdCode)
{
	uint16_t numH, numL;
	uint16_t num;
	LCD_CS_H(); // TODO
	TOUCH_CS_L();

	_delay_us(2);
	SPICommunication(cmdCode);
	_delay_us(2);
	numH = SPICommunication(0x00);
	numL = SPICommunication(0x00);
	num = (numH << 8) + numL;
	num >>= 4;
	TOUCH_CS_H();

	return num;
}

/**************************************************************************//**
 * @brief Pobiera ze sterownika kilka razy wynik ADC i filtruje zwracana wartosc.
 * @param cmdCode - komenda wskazujaca na os
 * @return przefiltrowany wynik konwersji AD
 *****************************************************************************/
uint16_t TouchGetADCEx(uint8_t cmdCode)
{
	uint16_t i, j;
	uint16_t buf[READ_TIMES];
	uint16_t sum = 0;
	uint16_t tmp;

	for (i = 0; i < READ_TIMES; i++)
	{
		buf[i] = TouchGetADC(cmdCode);
	}
	for (i = 0; i < READ_TIMES - 1; i++)
	{
		for (j = i + 1; j < READ_TIMES; j++)
		{
			if(buf[i] > buf[j])
			{
				tmp = buf[i];
				buf[i] = buf[j];
				buf[j] = tmp;
			}
		}
	}

	sum = 0;
	for (i = LOST_VAL; i < READ_TIMES - LOST_VAL; i++)
		sum += buf[i];
	tmp = sum / (READ_TIMES - 2 * LOST_VAL);

	return tmp;
}

/**************************************************************************//**
 * @brief Pobiera ze sterownika przefiltrowane wyniki konwersji AD dla osi x i y.
 * @param xad - przefiltrowany wynik konwersji AD dla osi x
 * @param yad - przefiltrowany wynik konwersji AD dla osi y
 * @return rezultat operacji
 *****************************************************************************/
ExecuteResult TouchReadADS(uint16_t* xad, uint16_t* yad)
{
	uint16_t xtmp, ytmp;

	xtmp = TouchGetADCEx(CMD_READ_X);
	ytmp = TouchGetADCEx(CMD_READ_Y);
	if (xtmp < 100 || ytmp < 100)
        return OUT_OF_RANGE;
	*xad = xtmp;
	*yad = ytmp;

	return EXECUTE_OK;
}

/**************************************************************************//**
 * @brief Dwukrotnie pobiera ze sterownika przefiltrowane wyniki konwersji AD
 * 		  dla osi x i y. Wartosc obu odczytow dla porownania, w granicach
 * 		  dopuszczalnego bledu
 * @param xad - przefiltrowany wynik konwersji AD dla osi x
 * @param yad - przefiltrowany wynik konwersji AD dla osi y
 * @return rezultat operacji
 *****************************************************************************/
ExecuteResult TouchReadADS2(uint32_t* xad, uint32_t* yad)
{
	ExecuteResult result = EXECUTE_OK;
	uint16_t x1, y1;
	uint16_t x2, y2;

	result = TouchReadADS(&x1, &y1);
    if (EXECUTE_OK != result)
    	return result;
    result = TouchReadADS(&x2, &y2);
    if (EXECUTE_OK != result)
		return result;
    if ((( x2 <= x1 && x1 < x2 + ERR_RANGE) || (x1 <= x2 && x2 < x1 + ERR_RANGE))
		&& ((y2 <= y1 && y1 < y2 + ERR_RANGE) || (y1 <= y2 && y2 < y1 + ERR_RANGE)))
    {
        *xad = (x1 + x2) / 2;
        *yad = (y1 + y2) / 2;
        return EXECUTE_OK;
    }
    else
    	return OUT_OF_RANGE;
}

/**************************************************************************//**
 * @brief Konwertuje wartosci odczytanych ADC na wartosci wspolrzednych.
 *****************************************************************************/
void TouchConvertAdToXy(void)
{
	touchPoint.x = (LCD_SIZE_X * touchPoint.xad - 2100 * LCD_SIZE_X) / 1900;
	touchPoint.y = (LCD_SIZE_Y * touchPoint.yad - 2100 * LCD_SIZE_Y) / 1900;
}

/**************************************************************************//**
 * @brief Pobiera jednokrotnie wspolrzedne dotkniecia.
 * @return rezultat operacji
 *****************************************************************************/
ExecuteResult TouchReadOnce(void)
{
	ExecuteResult result = EXECUTE_OK;

	result = TouchReadADS2(&touchPoint.xad, &touchPoint.yad);
	if (EXECUTE_OK == result)
	{
		while ((PIND & (1<<PD3)) == 0);
		TouchConvertAdToXy();
	}

	return result;
}

/**************************************************************************//**
 * @brief Pobiera wspolrzedne dotkniecia w sposob ciagly.
 * @return rezultat operacji
 *****************************************************************************/
ExecuteResult TouchReadContinue(void)
{
	ExecuteResult result = EXECUTE_OK;

	result = TouchReadADS2(&touchPoint.xad, &touchPoint.yad);
	if (EXECUTE_OK == result)
		TouchConvertAdToXy();

	return result;
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
