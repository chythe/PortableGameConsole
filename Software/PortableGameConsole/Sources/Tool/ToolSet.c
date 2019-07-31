/**************************************************************************//**
* @file     ToolSet.c
* @brief    Zbior pomocnych funkcji - source file
* @author   Mateusz Chudy
******************************************************************************/

#include "ToolSet.h"

/**************************************************************************//**
 * @brief Generuje liczbe losowa z zadanego przedzialu.
 * @param min - ograniczenie dolne przedzialu
 * @param max - ograniczenie gorne przedzialu
 * @return wygenerowana liczba losowa
 *****************************************************************************/
uint16_t ToolsRandom(uint16_t min, uint16_t max)
{
	uint16_t tmp;
	if (max >= min) max -= min;
	else
	{
		tmp = min - max;
		min = max;
		max = tmp;
	}
	return max ? (rand() % max + min) : min;
}

/**************************************************************************//**
 * @brief Zamienia dwie zmienne wartosciami.
 * @param a - wskaznik na pierwsza zmienna
 * @param b - wskaznik na druga zmienna
 *****************************************************************************/
void ToolsSwap(uint16_t* a , uint16_t* b)
{
	uint16_t tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**************************************************************************//**
 * @brief Realizuje potegowanie.
 * @param m - liczba
 * @param n - potega
 * @return liczba m do potegi n
 *****************************************************************************/
uint32_t ToolsPow(uint16_t m, uint16_t n)
{
	uint32_t result = 1;
	while (n--)
		result *= m;
	return result;
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
