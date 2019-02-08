/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 01 FEB 2019                                                            */
/* Version : V03                                                                    */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/* This file contains the DIO API prototypes and interfaces for external usage      */
/************************************************************************************/

/************************************************************************************/
/* -------------------------------> Guard Section <---------------------------------*/
/************************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/************************************************************************************/

/************************************************************************************/
/* ---------------------------> Macro Definitions <---------------------------------*/
/************************************************************************************/

#define DIO_PIN_OUTPUT 	1 		/* -> This is used to set pin direction to output  */
#define DIO_PIN_INPUT 	0		/* -> This is used to set pin direction to input   */

#define DIO_PORT_OUTPUT 0xFF	/* -> This is used to set the whole port as output */
#define DIO_PORT_INPUT  0x00	/* -> This is used to set the whole port as input  */

#define DIO_PORT_HIGH   0xFF 	/* -> This is used to set the whole port as high   */
#define DIO_PORT_LOW    0x00    /* -> This is used to set the whole port as low    */

#define DIO_PIN_HIGH    1		/* -> This is used to set pin value to high        */
#define DIO_PIN_LOW     0       /* -> This is used to set pin value to low         */

#define DIO_MAXPINNB 	31		/* -> This is used for input validation            */
#define DIO_MAXPORTNB   4		/* -> This is used for input validation            */

/************************************************************************************/

/************************************************************************************/
/* ---------------------------> Pin Number Definitions <----------------------------*/
/************************************************************************************/

typedef enum
{
	DIO_PIN0, 	/* -----> PORTA.0 */
	DIO_PIN1, 	/* -----> PORTA.1 */
	DIO_PIN2, 	/* -----> PORTA.2 */
	DIO_PIN3, 	/* -----> PORTA.3 */
	DIO_PIN4, 	/* -----> PORTA.4 */
	DIO_PIN5, 	/* -----> PORTA.5 */
	DIO_PIN6, 	/* -----> PORTA.6 */
	DIO_PIN7, 	/* -----> PORTA.7 */
	DIO_PIN8, 	/* -----> PORTB.0 */
	DIO_PIN9, 	/* -----> PORTB.1 */
	DIO_PIN10,	/* -----> PORTB.0 */
	DIO_PIN11,	/* -----> PORTB.1 */
	DIO_PIN12,	/* -----> PORTB.2 */
	DIO_PIN13,	/* -----> PORTB.3 */
	DIO_PIN14,	/* -----> PORTB.4 */
	DIO_PIN15,	/* -----> PORTB.5 */
	DIO_PIN16,	/* -----> PORTB.6 */
	DIO_PIN17,	/* -----> PORTC.0 */
	DIO_PIN18,	/* -----> PORTC.1 */
	DIO_PIN19,	/* -----> PORTC.2 */
	DIO_PIN20,	/* -----> PORTC.3 */
	DIO_PIN21,	/* -----> PORTC.4 */
	DIO_PIN22,	/* -----> PORTC.5 */
	DIO_PIN23,	/* -----> PORTC.6 */
	DIO_PIN24,	/* -----> PORTD.0 */
	DIO_PIN25,	/* -----> PORTD.1 */
	DIO_PIN26,	/* -----> PORTD.2 */
	DIO_PIN27,	/* -----> PORTD.3 */
	DIO_PIN28,	/* -----> PORTD.4 */
	DIO_PIN29,	/* -----> PORTD.5 */
	DIO_PIN30,	/* -----> PORTD.6 */
	DIO_PIN31,	/* -----> PORTD.7 */
}DIO_ENU_PIN;

/* ATmega32 Port Numbers definition */
typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_ENU_PORT;

/* Function Prototypes */
u8 DIO_u8Init(void);
u8 DIO_u8SetPinDirection	(u8 u8PinNB, u8 u8Direction);
u8 DIO_u8SetPinValue		(u8 u8PinNB, u8 u8Value);
u8 DIO_u8ReadPinValue		(u8 u8PinNB, u8 * u8Value);
u8 DIO_u8SetPortDirection	(u8 u8PortNB, u8 u8Direction);
u8 DIO_u8SetPortValue		(u8 u8PortNB, u8 u8Value);
u8 DIO_u8ReadPortValue		(u8 u8PortNB, u8 * u8Value);

#endif /* DIO_INTERFACE_H_ */
