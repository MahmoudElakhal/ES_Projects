/************************************************************************************************/
/************************************************************************************************/
/**********************************	  Author  :  Mahmoud ELakhal ********************************/
/**********************************	  Layer   : MCAL   		*************************************/
/**********************************	  SWC  : DIO   		*****************************************/
/**********************************	  Version : 1.00   		*************************************/
/************************************************************************************************/
/************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

u8 DIO_u8SetPinValue(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0;

	if(Copy_u8pin <= DIO_u8PIN7)
	{
		if(Copy_u8Value==DIO_u8PIN_LOW)
		{
			switch(Copy_u8port)
			{
			case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8pin);break;
			case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8pin);break;
			case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8pin);break;
			case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8pin);break;
			default : Local_u8ErrorState = 1 ;
			}
		}
		else if(Copy_u8Value==DIO_u8PIN_HIGH)
		{
			switch(Copy_u8port)
			{
			case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8pin);break;
			case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8pin);break;
			case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8pin);break;
			case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8pin);break;
			default : Local_u8ErrorState = 1 ;
			}
		}
		else
		{
			Local_u8ErrorState = 1 ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}
u8 DIO_u8SetPortValue(u8 Copy_u8port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0 ;
	switch (Copy_u8port)
	{
	case DIO_u8PORTA : PORTA = Copy_u8Value; break ;
	case DIO_u8PORTB : PORTB = Copy_u8Value; break ;
	case DIO_u8PORTC : PORTC = Copy_u8Value; break ;
	case DIO_u8PORTD : PORTD = Copy_u8Value; break ;
	default : Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}
u8 DIO_u8GetPinValue(u8 Copy_u8port, u8 Copy_u8pin , u8 * Copy_pu8Value)

{
	u8 Local_u8ErrorState = 0 ;
	// any function receives function check if it equal to null or not
	if((Copy_pu8Value!=NULL ) && ( Copy_u8pin<=DIO_u8PIN7))
	{
		switch (Copy_u8port)
		{
		case DIO_u8PORTA : *Copy_pu8Value = GET_BIT(PINA ,Copy_u8pin); break ;
		case DIO_u8PORTB : *Copy_pu8Value = GET_BIT(PINB ,Copy_u8pin); break ;
		case DIO_u8PORTC : *Copy_pu8Value = GET_BIT(PINC ,Copy_u8pin); break ;
		case DIO_u8PORTD : *Copy_pu8Value = GET_BIT(PIND ,Copy_u8pin); break ;
		default : Local_u8ErrorState = 1 ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}







