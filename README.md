# DIO_Driver
This is a DIO driver for ATmega32 MCU

-> DIO_Interface.h:
File has all the API available for the DIO usage, Macros definitions

-> DIO_Private.h:
File has all the private function prototypes that are used internally

-> DIO_Config.h:
File is used set configurations for pins that will be used in application layer

-> DIO_Prog.c:
File that has the implementation itself of the DIO driver

-> STD_Types.h: 
Library that containts a user-defined data types that is commonly used in this project

-> main.c
File that has a simple application to test the functionality of DIO Driver

-> Lib_delay.h
File that has a delay APIs that can be used in the application
