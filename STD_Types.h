/*
 * STD_TYPES.h
 *
 *  Created on: Jan 29, 2019
 *      Author: islas
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*
 * types.h
 *
 *  Created on: Jan 29, 2019
 *      Author: islas
 */

/**************************************************************/
/*  This header file is used to define some standard some     */
/*  standard data types, in a predefined format.			  */
/*  u: unsigned, s: signed, f: float, then followed by the    */
/*  number of bits it can store 							  */
/**************************************************************/

/*======================Guard Section=========================*/

/**************************************************************/
/*  This is used as a guard format, in order not to define    */
/*  this header file more than once.                          */
/*  Checks if STD_TYPES is not defined before, if not         */
/*  it defines it, and includes the header file. 			  */
/**************************************************************/

typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int u16;
typedef signed short int   s16;
typedef unsigned long int  u32;
typedef signed long int    s32;
typedef float              f32;
typedef float              f64;

#define ERROR_NOK 0
#define ERROR_OK  1
#define NULL      0
#define LOW	      0x00
#define HIGH      0xFF

typedef union {
	struct
	{
		u8 Bit0 : 1;
		u8 Bit1 : 1;
		u8 Bit2 : 1;
		u8 Bit3 : 1;
		u8 Bit4 : 1;
		u8 Bit5 : 1;
		u8 Bit6 : 1;
		u8 Bit7 : 1;
	}BitAccess;
	u8 ByteAccess;
}Register;

#endif /* STD_TYPES_H_ */
