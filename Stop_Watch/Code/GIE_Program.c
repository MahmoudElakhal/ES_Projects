/*
 * GIE_Program.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Softlaptop
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_Interface.h"
#include "GIE_Register.h"
void GIE_voidEnable(void)
{
	SET_BIT(SREG , SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG , SREG_I);
}
