/**************************************************************************//**
* @file     LCDController.h
* @brief    Kontroler sterownika wyswietlacza BD663474 - header file
* @author   Mateusz Chudy
******************************************************************************/

#ifndef _LCD_CONTROLLER_H_
#define _LCD_CONTROLLER_H_

#include <stdint.h>

#define	LCD_SIZE_X							240
#define	LCD_SIZE_Y							320

#define INDEX_START_OSCILLATION						                0x000
#define INDEX_DRIVER_OUTPUT_CONTROL					                0x001
#define INDEX_CRYSTAL_DRIVE_INVERSION_CONTROL			            0x002
#define INDEX_ENTRY_MODE								            0x003
#define INDEX_MOVING_IMAGE_DISPLAY_CONTROL			                0x006
#define INDEX_DISPLAY_CONTROL1					                    0x007
#define INDEX_DISPLAY_CONTROL2					                    0x008
#define INDEX_DISPLAY_CONTROL3					                    0x009
#define INDEX_DISPLAY_CONTROL4					                    0x00B
#define INDEX_EXTERNAL_DISPLAY_INTERFACE_CONTROL1		            0x00C
#define INDEX_FRAME_CYCLE_ADJUSTMENT_CONTROL			            0x00D
#define INDEX_SOURCE_DRIVER_INTERFACE_CONTROL1		                0x012
#define INDEX_GATE_DRIVER_INTERFACE_CONTROL1			            0x013
#define INDEX_SOURCE_DRIVER_INTERFACE_CONTROL2		                0x018
#define INDEX_GATE_DRIVER_INTERFACE_CONTROL2			            0x019
#define INDEX_POWER_CONTROL1					                    0x100
#define INDEX_POWER_CONTROL2					                    0x101
#define INDEX_POWER_CONTROL3					                    0x102
#define INDEX_POWER_CONTROL4					                    0x103
#define INDEX_POWER_CONTROL5					                    0x110
#define INDEX_POWER_CONTROL6					                    0x111
#define INDEX_HORIZONTAL_RAM_ADDRESS_SET							0x200
#define INDEX_VERTICAL_RAM_ADDRESS_SET								0x201
#define INDEX_RAM_DATA_WRITE										0x202
#define INDEX_RAM_WRITE_DATA_MASK1					                0x203
#define INDEX_RAM_WRITE_DATA_MASK2					                0x204
#define INDEX_HORIZONTAL_RAM_ADDRESS_START_POSITION	                0x210
#define INDEX_HORIZONTAL_RAM_ADDRESS_END_POSITION		            0x211
#define INDEX_VERTICAL_RAM_ADDRESS_START_POSITION		            0x212
#define INDEX_VERTICAL_RAM_ADDRESS_END_POSITION		                0x213
#define INDEX_MOVING_PICTURE_CONTROL_ADDRESS_START_POSITION1		0x214
#define INDEX_MOVING_PICTURE_CONTROL_ADDRESS_END_POSITION1			0x215
#define INDEX_MOVING_PICTURE_CONTROL_ADDRESS_START_POSITION2		0x216
#define INDEX_MOVING_PICTURE_CONTROL_ADDRESS_END_POSITION2			0x217
#define INDEX_GAMMA_CONTROL1										0x300
#define INDEX_GAMMA_CONTROL2										0x301
#define INDEX_GAMMA_CONTROL3										0x302
#define INDEX_GAMMA_CONTROL4										0x303
#define INDEX_GAMMA_CONTROL5										0x304
#define INDEX_GAMMA_CONTROL6										0x305
#define INDEX_GAMMA_CONTROL7										0x306
#define INDEX_GAMMA_CONTROL8										0x307
#define INDEX_GAMMA_CONTROL9										0x308
#define INDEX_GAMMA_CONTROL10										0x309
#define INDEX_LINE_NUMBER_CONTROL									0x400
#define INDEX_SCREEN_CONTROL										0x401
#define INDEX_FULL_SCREEN_IMAGE_RAM_AREA_START_LINE					0x402
#define INDEX_FULL_SCREEN_IMAGE_RAM_AREA_END_LINE					0x403
#define INDEX_VERTICAL_SCROLL_CONTROL								0x404

#define LCD_RST_H()		PORTB |= (1 << PB0);
#define LCD_RST_L()		PORTB &= ~(1 << PB0);

#define LCD_RS_H()		PORTB |= (1 << PB1);
#define LCD_RS_L()		PORTB &= ~(1 << PB1);

#define LCD_CS_H()		PORTB |= (1 << PB2);
#define LCD_CS_L()		PORTB &= ~(1 << PB2);

/// Kolory
typedef enum
{
	BLACK       = 0X0000,
	CYAN		= 0x07FF,
	PURPLE		= 0xF81F,
	RED         = 0XF800,
	GREEN       = 0X07E0,
	BLUE        = 0X001F,
	YELLOW      = 0XFFE0,
	ORANGE      = 0XFC08,
	GRAY  	    = 0X8430,
	LGRAY       = 0XC618,
	DARKGRAY    = 0X8410,
	PORPO       = 0X801F,
	PINK        = 0XF81F,
	GRAYBLUE    = 0X5458,
	LGRAYBLUE   = 0XA651,
	DARKBLUE    = 0X01CF,
	LIGHTBLUE   = 0X7D7C,
	WHITE       = 0XFFFF
} Color;

/// Inicjalizuje i wlacza sygnal PWM
void LCDPWMInit(void);

/// Wpisuje do sterownika indeks rejestru
void LCDWriteIndex(uint16_t index);

/// Wpisuje dane do rejestru
void LCDWriteReg(uint16_t index, uint16_t data);

/// Wpisuje dane
void LCDWriteData(uint16_t data);

/// Inicjalizuje sterownik wyswietlacza
void LCDInit(void);

#endif		// _LCD_CONTROLLER_H_

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
