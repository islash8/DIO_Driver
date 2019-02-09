/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 08 FEB 2019                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/*  This is the application file, where you can write a simple application to test  */
/*  the functionality of DIO														*/
/************************************************************************************/
#include "STD_Types.h"
#include "Lib_Delay.h"
#include "DIO_Interface.h"

void main (void)
{

	DIO_u8SetPortDirection(DIO_PORTD, DIO_PORT_OUTPUT);
		while (1)
		{
/*
			DIO_u8SetPinValue(DIO_PIN24, DIO_PIN_HIGH);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN24, DIO_PIN_LOW);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN25, DIO_PIN_HIGH);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN25, DIO_PIN_LOW);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN26, DIO_PIN_HIGH);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN26, DIO_PIN_LOW);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN27, DIO_PIN_HIGH);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN27, DIO_PIN_LOW);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN28, DIO_PIN_HIGH);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN28, DIO_PIN_LOW);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN29, DIO_PIN_HIGH);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN29, DIO_PIN_LOW);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN30, DIO_PIN_HIGH);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN30, DIO_PIN_LOW);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN31, DIO_PIN_HIGH);
			Lib_vDelayMs(500);
			DIO_u8SetPinValue(DIO_PIN31, DIO_PIN_LOW);
			Lib_vDelayMs(500);
*/
			DIO_u8SetPortValue(DIO_PORTD, 0x41);
			Lib_vDelayMs(500);
			DIO_u8SetPortValue(DIO_PORTD, DIO_PORT_LOW);
			Lib_vDelayMs(500);


		}
}
