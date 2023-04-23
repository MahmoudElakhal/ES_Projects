#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_Interface.h"
#include "TIMER_Register.h"
#include "TIMER_Config.h"
#include "TIMER_Private.h"
static void (*TIMER1_pvCallBackFunc)(void) = NULL;

void TIMER1_voidINIT(void)
{
	TCNT1 = 0;
	/*Set Waveform generation mode as CTC modes */
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	OCR1A = 1000;
	/*Timer1 CTC Interrupt Enable*/
	SET_BIT(TIMSK , TIMSK_OCIE1A) ;
	TCCR1A = (1 << TCCR1A_FOC1A) | (1 << TCCR1A_FOC1B);
	/*Initialize Pre-scaler*/
	TCCR1B &= PRESCALER_MASK ;
	TCCR1B |= DIVIDE_BY_1024 ;
}

void TIMER1_voidSetChannelACompareMatch(u16 Copy_u16CompareMatch)
{
	OCR1A = Copy_u16CompareMatch;
}

u8 TIMER1_u8SetCallBack(void (* Copy_pvCallBackFunc) (void))
{
	u8 Local_u8ErrorStatus = OK;
	if(Copy_pvCallBackFunc !=NULL)
	{
		TIMER1_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

void TIMER1_voidResume(void)
{
	TCCR1B &= PRESCALER_MASK ;
	TCCR1B |= DIVIDE_BY_1024 ;
}

void TIMER1_voidStop(void)
{
	TCCR1B &= PRESCALER_MASK ;
	TCCR1B |= STOP_TIMER1 ;
}
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMER1_pvCallBackFunc !=NULL)
	{
		TIMER1_pvCallBackFunc();
	}
}


