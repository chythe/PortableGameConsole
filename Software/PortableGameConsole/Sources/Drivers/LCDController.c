/**************************************************************************//**
* @file     LCDController.c
* @brief    Kontroler sterownika wyswietlacza BD663474 - source file
* @author   Mateusz Chudy
******************************************************************************/

#include <avr/io.h>
#define F_CPU 16000000UL // CPU 16MHz
#include <util/delay.h>
#include "LCDController.h"
#include "SPIController.h"

/**************************************************************************//**
 * @brief Inicjalizuje i wlacza sygnal PWM.
 *****************************************************************************/
void LCDPWMInit(void)
{
	TCCR0 |= (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00); // fast PWM
	OCR0 = 0x00; // 50%
}

/**************************************************************************//**
 * @brief Wpisuje do sterownika indeks rejestru.
 * @param index - indeks rejestru
 *****************************************************************************/
void LCDWriteIndex(uint16_t index)
{
	uint16_t valueIndex;

	LCD_CS_L();
	LCD_RS_L();

	valueIndex = index;
	valueIndex >>= 8;
    SPICommunication((uint8_t)(valueIndex));

    valueIndex = index;
    valueIndex &= 0x00FF;
    SPICommunication((uint8_t)(index));

	LCD_RS_H();
	LCD_CS_H();
}

/**************************************************************************//**
 * @brief Wpisuje dane do rejestru.
 * @param index - indeks rejestru
 * @param data - wpisywane dane
 *****************************************************************************/
void LCDWriteReg(uint16_t index, uint16_t data)
{
	LCD_CS_L();
	LCD_RS_L();

	SPICommunication((uint8_t)(index >> 8));
	SPICommunication((uint8_t)(index));

	LCD_RS_H();

	SPICommunication((uint8_t)(data >> 8));
	SPICommunication((uint8_t)(data));
	LCD_CS_H();
}

/**************************************************************************//**
 * @brief Wpisuje dane.
 * @param data - wpisywane dane
 *****************************************************************************/
void LCDWriteData(uint16_t data)
{
    SPICommunication((uint8_t)(data >> 8));
    SPICommunication((uint8_t)(data));
}

/**************************************************************************//**
 * @brief Inicjalizuje sterownik wyswietlacza.
 *****************************************************************************/
void LCDInit(void)
{
	// start PWM
	LCDPWMInit();

	// reset LCD
	LCD_RST_L();
	_delay_us(10);
	LCD_RST_H();
	_delay_us(10);

	// start oscillation
	LCDWriteReg(INDEX_START_OSCILLATION, 0x0001);
	_delay_us(10);

	// power control settings
	LCDWriteReg(INDEX_POWER_CONTROL1, 0x0000);
	LCDWriteReg(INDEX_POWER_CONTROL2, 0x0000);
	LCDWriteReg(INDEX_POWER_CONTROL3, 0x3110);
	LCDWriteReg(INDEX_POWER_CONTROL4, 0xE200);
	LCDWriteReg(INDEX_POWER_CONTROL5, 0x009D);
	LCDWriteReg(INDEX_POWER_CONTROL6, 0x0022);
	LCDWriteReg(INDEX_POWER_CONTROL1, 0x0120);
	_delay_us(20);
	LCDWriteReg(INDEX_POWER_CONTROL1, 0x3120);
	_delay_us(80);

	// display control settings
	LCDWriteReg(INDEX_DRIVER_OUTPUT_CONTROL, 0x0100);
	LCDWriteReg(INDEX_CRYSTAL_DRIVE_INVERSION_CONTROL, 0x0000);
	LCDWriteReg(INDEX_ENTRY_MODE, 0x1230); // high-speed write mode
	LCDWriteReg(INDEX_MOVING_IMAGE_DISPLAY_CONTROL, 0x0000);
	LCDWriteReg(INDEX_DISPLAY_CONTROL1, 0x0101);
	LCDWriteReg(INDEX_DISPLAY_CONTROL2, 0x0808);
	LCDWriteReg(INDEX_DISPLAY_CONTROL3, 0x0000);
	LCDWriteReg(INDEX_DISPLAY_CONTROL4, 0x0000);
	LCDWriteReg(INDEX_EXTERNAL_DISPLAY_INTERFACE_CONTROL1, 0x0000);
	LCDWriteReg(INDEX_FRAME_CYCLE_ADJUSTMENT_CONTROL, 0x0018);

	// LTPS control settings
	LCDWriteReg(INDEX_SOURCE_DRIVER_INTERFACE_CONTROL1, 0x0000);
	LCDWriteReg(INDEX_GATE_DRIVER_INTERFACE_CONTROL1, 0x0000);
	LCDWriteReg(INDEX_SOURCE_DRIVER_INTERFACE_CONTROL2, 0x0000);
	LCDWriteReg(INDEX_GATE_DRIVER_INTERFACE_CONTROL2, 0x0000);

	// RAM access settings
	LCDWriteReg(INDEX_RAM_WRITE_DATA_MASK1, 0x0000);
	LCDWriteReg(INDEX_RAM_WRITE_DATA_MASK2, 0x0000);

	// window address control settings
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_START_POSITION, 0x0000);
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_END_POSITION, 0x00EF);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_START_POSITION, 0x0000);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_END_POSITION, 0x013F);
	LCDWriteReg(INDEX_MOVING_PICTURE_CONTROL_ADDRESS_START_POSITION1, 0x0000);
	LCDWriteReg(INDEX_MOVING_PICTURE_CONTROL_ADDRESS_END_POSITION1, 0x0000);
	LCDWriteReg(INDEX_MOVING_PICTURE_CONTROL_ADDRESS_START_POSITION2, 0x0000);
	LCDWriteReg(INDEX_MOVING_PICTURE_CONTROL_ADDRESS_END_POSITION2, 0x0000);

	// γ (gray scale) control settings
	LCDWriteReg(INDEX_GAMMA_CONTROL1, 0x5343);
	LCDWriteReg(INDEX_GAMMA_CONTROL2, 0x1021);
	LCDWriteReg(INDEX_GAMMA_CONTROL3, 0x0003);
	LCDWriteReg(INDEX_GAMMA_CONTROL4, 0x0011);
	LCDWriteReg(INDEX_GAMMA_CONTROL5, 0x050A);
	LCDWriteReg(INDEX_GAMMA_CONTROL6, 0x4342);
	LCDWriteReg(INDEX_GAMMA_CONTROL7, 0x1100);
	LCDWriteReg(INDEX_GAMMA_CONTROL8, 0x0003);
	LCDWriteReg(INDEX_GAMMA_CONTROL9, 0x1201);
	LCDWriteReg(INDEX_GAMMA_CONTROL10, 0x050A);

	// coordinate control settings
	LCDWriteReg(INDEX_LINE_NUMBER_CONTROL, 0x4027);
	LCDWriteReg(INDEX_SCREEN_CONTROL, 0x0000);
	LCDWriteReg(INDEX_FULL_SCREEN_IMAGE_RAM_AREA_START_LINE, 0x0000);
	LCDWriteReg(INDEX_FULL_SCREEN_IMAGE_RAM_AREA_END_LINE, 0x013F);
	LCDWriteReg(INDEX_VERTICAL_SCROLL_CONTROL, 0x0000);

	// RAM access settings
	LCDWriteReg(INDEX_HORIZONTAL_RAM_ADDRESS_SET, 0x0000);
	LCDWriteReg(INDEX_VERTICAL_RAM_ADDRESS_SET, 0x0000);

	LCDWriteReg(INDEX_POWER_CONTROL1, 0x7120);
	LCDWriteReg(INDEX_DISPLAY_CONTROL1, 0x0103);
	_delay_us(10);
	LCDWriteReg(INDEX_DISPLAY_CONTROL1, 0x0113);
	_delay_us(20);
}

// ----------------------------------------------------------------------------
// End of file ----------------------------------------------------------------
// ----------------------------------------------------------------------------
