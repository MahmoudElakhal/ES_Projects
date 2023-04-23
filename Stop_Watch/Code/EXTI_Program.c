/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : EXTI		         ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Register.h"
#include "EXTI_Config.h"

/*Global Pointer to Function to hold INT0 ISR Address*/
//pv is pointer to void
void (*EXTI_pvInt0Func)(void) = NULL;
void (*EXTI_pvInt1Func)(void) = NULL;
void (*EXTI_pvInt2Func)(void) = NULL;
//Pre build Configuration
void EXTI_voidInt0_INIT(void)
{
	/*1- Check Sense Control*/
#if INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error "Wrong INT0 Sense Configuration Option"
#endif

	/*Check peripheral interrupt enable initial state*/
#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);

#else
#error "Wrong INT0_INITIAL_STATE Configuration Option"
#endif

}
void EXTI_voidInt1_INIT(void)
{
#if INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#else
#error "Wrong INT1 Sense Configuration Option"
#endif


	/*Check peripheral interrupt enable initial state*/
#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);

#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);

#else
#error "Wrong INT1_INITIAL_STATE Configuration Option"
#endif
}
void EXTI_voidInt2_INIT(void)
{
#if INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR ,MCUCSR_INT2);
#elif INT2_SENSE == RISING_EGDE
	SET_BIT(MCUCSR ,MCUCSR_INT2);
#else
#error "Wrong INT2 Sense Configuration Option"
#endif

	/*Check peripheral interrupt enable initial state*/
#if INT2_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);

#elif INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);

#else
#error "Wrong INT2_INITIAL_STATE Configuration Option"
#endif

}

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func) (void))
{
	u8 Local_u8ErrorStatus = OK;
	if(Copy_pvInt0Func !=NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func) (void))
{
	u8 Local_u8ErrorStatus = OK;
	if(Copy_pvInt1Func !=NULL)
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func) (void))
{
	u8 Local_u8ErrorStatus = OK;
	if(Copy_pvInt2Func !=NULL)
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}
/*ISR of INT0*/
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvInt0Func !=NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*Do nothing*/
	}
}

/*ISR of INT1*/
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pvInt1Func !=NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/*Do nothing*/
	}
}
/*ISR of INT2*/
void __vector_18(void)  __attribute__((signal));
void __vector_18(void)
{
	if(EXTI_pvInt2Func !=NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/*Do nothing*/
	}
}
