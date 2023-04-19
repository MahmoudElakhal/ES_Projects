/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : HAL   		         ********************************/
/*****************************	  SWC     : STEPPER_Motor        ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "STEPPER_Interface.h"
#include "STEPPER_Config.h"
#include "STEPPER_Private.h"
#include <util/delay.h>

void STEPPER_voidFullStepRotateCW(Step_Motor * STEP)
{
	u16 Local_u16Counter ;
	u16 Local_u16iteration = ((STEP->Copy_u8Angle / STEP->Copy_u8Resolution) / 4);
	for(Local_u16Counter = 0 ; Local_u16Counter<Local_u16iteration; Local_u16Counter++ )
	{
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_HIGH);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
	}
}
void STEPPER_voidFullStepRotateCCW( Step_Motor * STEP )
{
	u16 Local_u16Counter ;
	u16 Local_u16iteration = ((STEP->Copy_u8Angle / STEP->Copy_u8Resolution) / 4);
	for(Local_u16Counter = 0 ; Local_u16Counter<Local_u16iteration ; Local_u16Counter++ )
	{
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_HIGH);
		_delay_ms(STEP->Copy_u8Speed);
	}
}


void STEPPER_voidHalfStepRotateCW(Step_Motor * STEP)
{
	u16 Local_u16Counter ;
	u16 Local_u16iteration = ((STEP->Copy_u8Angle / STEP->Copy_u8Resolution) / 8);
	for(Local_u16Counter = 0 ; Local_u16Counter<Local_u16iteration ; Local_u16Counter++ )
	{
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_HIGH);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_HIGH);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_HIGH);
		_delay_ms(STEP->Copy_u8Speed);
	}
}
void STEPPER_voidHalfStepRotateCCW(Step_Motor * STEP)
{
	u16 Local_u16Counter ;
	u16 Local_u16iteration = ((STEP->Copy_u8Angle / STEP->Copy_u8Resolution) / 8);
	for(Local_u16Counter = 0 ; Local_u16Counter<Local_u16iteration ; Local_u16Counter++ )
	{
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_HIGH);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_HIGH);
		_delay_ms(STEP->Copy_u8Speed);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_HIGH);
		_delay_ms(STEP->Copy_u8Speed);
	}
}

void STEPPER_voidStop(Step_Motor * STEP)
{
	DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin1ID , DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin2ID , DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin3ID , DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEP->Copy_u8PortID, STEP->Copy_u8Pin4ID , DIO_u8PIN_LOW);
}

