/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 08 FEB 2019                                                            */
/* Version : V03                                                                    */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/*  This source file is used for the implementation DIO driver, provides a layer of */
/*  abstraction of the hardware of MCU (ATmega32) itself.                           */
/************************************************************************************/

/************************************************************************************/
/* -------------------------------> Header files  <---------------------------------*/
/************************************************************************************/

#include "STD_Types.h"          /* ---> Contains the data types used in the project */
#include "LIB_Bit_Operations.h" /* ---> Contains bit and port operations            */

#include "DIO_Interface.h"		/* ---> Contains header files of used functions     */
#include "DIO_Private.h"        /* ---> Contains headers of private functions       */
#include "DIO_Config.h"			/* ---> Contains the configurations to be used      */

/************************************************************************************/

/************************************************************************************/
/* -------------------------> Functions implementation <----------------------------*/
/************************************************************************************/

/************************************************************************************/
/* Name: 0. DIO_vInit											     	            */
/* Description: Set pin direction													*/
/* Inputs:  -> void																	*/
/* Outputs: -> void                                                      			*/
/************************************************************************************/

void DIO_vInit (void)
{

}

/************************************************************************************/
/* Name: 1. DIO_u8SetPinDirection											     	*/
/* Description: Set pin direction													*/
/* Inputs:  -> Pin number (u8PinNB) (ranges from 0 -> 31)							*/
/*          -> Direction (u8Direction) (either 0 for input or 1 for output)			*/
/* Outputs: -> Error Status (u8Error), Expects either OK=1, or NOK=0				*/
/************************************************************************************/

u8 DIO_u8SetPinDirection(u8 u8PinNB, u8 u8Direction)
{
/*===========================>> Local variables <<==================================*/

	u8 u8Error  = ERROR_OK; /* ----> This is used as a return value                 */
	u8 u8PinID  = NULL;
	u8 u8PortID = NULL;

	/*
	 * validates the inputs, if it's more than MAXPINNB or Direction
	 * is any other value than input or output
	 */
	if( (u8PinNB >= DIO_MAXPINNB) || ( (u8Direction != DIO_OUTPUT) && (u8Direction != DIO_INPUT) ) )
	{
		u8Error = ERROR_NOK;
	}
	else
	{
		u8PinID = u8PinNB % NUMBER_PINS_IN_PORT;
		u8PortID = u8PinNB / NUMBER_PINS_IN_PORT;

		switch (u8PortID)
		{
		case 0:
			DDRA -> ByteAccess = ASSIGN_BIT((DDRA -> ByteAccess), u8PinID, u8Direction);
			break;
		case 1:
			DDRB -> ByteAccess = ASSIGN_BIT((DDRB -> ByteAccess), u8PinID, u8Direction);
			break;
		case 2:
			DDRC -> ByteAccess = ASSIGN_BIT((DDRC -> ByteAccess), u8PinID, u8Direction);
			break;
		case 3:
			DDRD -> ByteAccess = ASSIGN_BIT((DDRD -> ByteAccess), u8PinID, u8Direction);
			break;
		}
	}

	return u8Error;
}

/* Description: Set pin value
 * Inputs: Pin number (ranges from 0 -> 31), value
 * Outputs: return status of setting direction, either OK=1, or NOK=0
*/

u8 DIO_u8SetPinValue(u8 u8PinNB, u8 u8Value)
{
	/*Local variables*/
	u8 u8Error = ERROR_OK;
	u8 u8PinID;
	u8 u8PortID;

	/* Validates the input to check whether the user enter the
	 * correct pin number, and whether he enters the right which
	 * is not bigger than upper limit.
	 */
	if( (u8PinNB >= DIO_MAXPINNB) || (u8Value > HIGH))
	{
		u8Error = ERROR_NOK;
	}
	else
	{
		u8PinID = u8PinNB % NUMBER_PINS_IN_PORT;
		u8PortID = u8PinNB / NUMBER_PINS_IN_PORT;

		switch (u8PortID)
		{
		case 0:
			PORTA -> ByteAccess = ASSIGN_BIT((PORTA -> ByteAccess), u8PinID, u8Value);
			break;
		case 1:
			PORTB -> ByteAccess =ASSIGN_BIT((PORTB -> ByteAccess), u8PinID, u8Value);
			break;
		case 2:
			PORTC -> ByteAccess =ASSIGN_BIT((PORTC -> ByteAccess), u8PinID, u8Value);
			break;
		case 3:
			PORTD -> ByteAccess =ASSIGN_BIT((PORTD -> ByteAccess), u8PinID, u8Value);
			break;
		}
	}

	return u8Error;
}

u8 DIO_u8ReadPinValue(u8 u8PinNB, u8 * u8Value)
{
	/*Local variables*/
	u8 u8Error = ERROR_OK;
	u8 u8PinID;
	u8 u8PortID;

	if( (u8PinNB >= DIO_MAXPINNB) )
	{
		u8Error = ERROR_NOK;
	}
	else
	{
		u8PinID = u8PinNB % NUMBER_PINS_IN_PORT;
		u8PortID = u8PinNB / NUMBER_PINS_IN_PORT;

		switch (u8PortID)
		{
		case 0:
			* u8Value = GET_BIT((PORTA -> ByteAccess), u8PinID);
			break;
		case 1:
			* u8Value = GET_BIT((PORTB -> ByteAccess), u8PinID);
			break;
		case 2:
			* u8Value = GET_BIT((PORTC -> ByteAccess), u8PinID);
			break;
		case 3:
			* u8Value = GET_BIT((PORTD -> ByteAccess), u8PinID);
			break;
		}

	}

	return u8Error;
}

/*-------------------------------------------------------------------*/
/*------------------------>PORT OPERATIONS<--------------------------*/
u8 DIO_u8SetPortDirection(u8 u8PortNB, u8 u8Direction)
{
	/*Local variables*/
	u8 u8Error = ERROR_OK;

	if( (u8PortNB >= DIO_MAXPORTNB) || (u8Direction > MAX_DIRECTION_VALUE) )
	{
		u8Error = ERROR_NOK;
	}
	else
	{

		switch (u8PortNB)
		{
		case 0:
			ASSIGN_PORT((DDRA -> ByteAccess), u8Direction);
			break;
		case 1:
			ASSIGN_PORT((DDRB -> ByteAccess), u8Direction);
			break;
		case 2:
			ASSIGN_PORT((DDRC -> ByteAccess), u8Direction);
			break;
		case 3:
			ASSIGN_PORT((DDRD -> ByteAccess), u8Direction);
			break;
		}
	}

	return u8Error;
}



u8 DIO_u8SetPortValue(u8 u8PortNB, u8 u8Value)
{
	/*Local variables*/
	u8 u8Error = ERROR_OK;

	if( (u8PortNB >= DIO_MAXPORTNB) )
	{
		u8Error = ERROR_NOK;
	}
	else
	{

		switch (u8PortNB)
		{
		case 0:
			ASSIGN_PORT((PORTA -> ByteAccess), u8Value);
			break;
		case 1:
			ASSIGN_PORT((PORTB -> ByteAccess), u8Value);
			break;
		case 2:
			ASSIGN_PORT((PORTC -> ByteAccess), u8Value);
			break;
		case 3:
			ASSIGN_PORT((PORTD -> ByteAccess), u8Value);
			break;
		}
	}

	return u8Error;
}

u8 DIO_u8ReadPortValue(u8 u8PortNB, u8 * u8Value)
{
	/*Local variables*/
	u8 u8Error = ERROR_OK;

	if( (u8PortNB >= DIO_MAXPINNB) )
	{
		u8Error = ERROR_NOK;
	}
	else
	{

		switch (u8PortNB)
		{
		case 0:
			GET_PORT((PORTA -> ByteAccess), *u8Value);
			break;
		case 1:
			GET_PORT((PORTB -> ByteAccess), *u8Value);
			break;
		case 2:
			GET_PORT((PORTC -> ByteAccess), *u8Value);
			break;
		case 3:
			GET_PORT((PORTD -> ByteAccess), *u8Value);
			break;
		}
	}

	return u8Error;
}
