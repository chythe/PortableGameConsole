/**************************************************************************//**
* @file     ToolSet.h
* @brief    Zbior pomocnych funkcji - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _TOOL_SET_H_
#define _TOOL_SET_H_

#include <stdint.h>
#include <stdlib.h>
#include "LCDController.h"

/// Generuje liczbe losowa z zadanego przedzialu
uint16_t ToolsRandom(uint16_t min, uint16_t max);

/// Zamienia dwie zmienne wartosciami
void ToolsSwap(uint16_t* a , uint16_t* b);

/// Realizuje potegowanie
uint32_t ToolsPow(uint16_t m, uint16_t n);

#endif		// _TOOL_SET_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
