/*
 * main.c
 *
 *  Created on: Feb 8, 2019
 *      Author: islash8
 */

#include "STD_Types.h"
#include "Lib_Delay.h"
#include "DIO_Interface.h"

void main (void)
{
	DIO_u8SetPortDirection(DIO_PORTD, DIO_PORT_OUTPUT);
		while (1)
		{
		DIO_u8SetPinValue(DIO_PIN24, 1);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN24, 0);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN25, 1);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN25, 0);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN26, 1);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN26, 0);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN27, 1);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN27, 0);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN28, 1);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN28, 0);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN29, 1);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN29, 0);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN30, 1);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN30, 0);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN31, 1);
		Lib_vDelayMs(500);
		DIO_u8SetPinValue(DIO_PIN31, 0);
		}
}
