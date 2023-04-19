/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : HAL   		         ********************************/
/*****************************	  SWC     : DC_Motor             ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DCMOTOR_Interface.h"
#include "DCMOTOR_Config.h"
#include "DCMOTOR_Private.h"
#include <util/delay.h>
/*
 * Assuming Here we use H-Bridge and every 2 transistors are driven by 1 pin
 * to prevent short circuit we will use 1 pin in each direction */
void DCMotor_voidRotateCW(u8 Copy_u8PortID , u8 Copy_u8Pin1ID , u8 Copy_u8Pin2ID)
{
	DIO_u8SetPinValue(Copy_u8PortID,Copy_u8Pin2ID,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8PortID,Copy_u8Pin1ID,DIO_u8PIN_HIGH);
}
void DCMotor_voidRotateCCW(u8 Copy_u8PortID , u8 Copy_u8Pin1ID , u8 Copy_u8Pin2ID)
{
	DIO_u8SetPinValue(Copy_u8PortID,Copy_u8Pin1ID,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8PortID,Copy_u8Pin2ID,DIO_u8PIN_HIGH);
}
void DCMotor_voidStop(u8 Copy_u8PortID , u8 Copy_u8Pin1ID , u8 Copy_u8Pin2ID)
{
	DIO_u8SetPinValue(Copy_u8PortID,Copy_u8Pin1ID,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8PortID,Copy_u8Pin2ID,DIO_u8PIN_LOW);
}
