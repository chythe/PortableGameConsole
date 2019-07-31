/**************************************************************************//**
* @file     Welcome.h
* @brief    Ekran powitalny - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _WELCOME_H_
#define _WELCOME_H_

#include <stdint.h>
#include "LCDController.h"

#define WELCOME_X_POS			88
#define WELCOME_Y_POS			140
#define WELCOME_STRING_COLOR	WHITE
#define WELCOME_TIME			2000

/// Wyswietla ekran powitalny
void WelcomeShow(void);

#endif		// _WELCOME_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
