/*
 * CLCD_Program.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Softlaptop
 */

#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_Interface.h"
#include "CLCD_Config.h"


void CLCD_VoidSendCommand (u8 Copy_u8Command)
{
	/* Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN ,DIO_u8PIN_LOW );

	/*Set RW to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN  ,DIO_u8PIN_LOW);

	/*Set Command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT , Copy_u8Command);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW);
}

void CLCD_VoidSendData (u8 Copy_u8Data)
{
	/* Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN ,DIO_u8PIN_HIGH );

	/*Set RW to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN  ,DIO_u8PIN_LOW);

	/*Set DATA to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT , Copy_u8Data);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW);
}

void CLCD_VoidInit(void)
{
	/*wait for more than 30 ms */
	_delay_ms(40);

	/*function set command : 2 lines , 5*8 font size*/
	CLCD_VoidSendCommand(0b00111000);

	/*Display on off control : Display enable , disable cursor , no blink cursor*/
	CLCD_VoidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_VoidSendCommand(0b00000001);
}

void CLCD_VoidSendString( const char * Copy_PcString)
{
	u8 Local_u8Counter = 0 ;
	while (Copy_PcString[Local_u8Counter]!='\0')
	{
		CLCD_VoidSendData(Copy_PcString[Local_u8Counter])  ;
		Local_u8Counter++;
	}
	/*Set DATA to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT , Copy_PcString );
}

void CLCD_VoidGoToXY (u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos== 0 )
	{
		/*location is at first line*/
		Local_u8Address = Copy_u8YPos ;
	}
	else if (Copy_u8XPos==1)
	{
		/*location is at second line*/
		Local_u8Address = 0x40 + Copy_u8YPos ;
	}
	/*Because 128 ==10000000 and in datasheet MSB is 1 always and we have only 7 addresses*/
	/*we can use the address | 10000000 or setbit*/
	CLCD_VoidSendCommand(Local_u8Address+128);
}

void CLCD_VoidWriteSpecialCharacter(u8 * Copypu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos )
{
	u8 Local_u8CGRAMAddress = 0 , Local_u8Iterator;

	/*calculate CGRAM address whose each block is 8 byte*/
	Local_u8CGRAMAddress = Copy_u8PatternNumber*8;

	/*Send CGRAM address command to lcd with setting bit 6 , clear bit 7*/
	CLCD_VoidSendCommand(Local_u8CGRAMAddress+64);

	/*Write pattern into CGRAM*/
	for(Local_u8Iterator = 0 ; Local_u8Iterator < 8 ; Local_u8Iterator++)
	{
		CLCD_VoidSendData(Copypu8Pattern[Local_u8Iterator]);
	}

	/*GO back to DDRAM to display the pattern*/
	CLCD_VoidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*Display the pattern written in the CGRAM*/
	CLCD_VoidSendData(Copy_u8PatternNumber);
}

void CLCD_voidSendNumber   ( u32 Copy_u32Number    )
{

	u32 Local_u32Reversed = 1 ;

	if( Copy_u32Number == 0 )
	{
		CLCD_VoidSendData ('0');
	}

	else{

		while( Copy_u32Number != 0 )
		{
			Local_u32Reversed = ( Local_u32Reversed * 10 ) + ( Copy_u32Number % 10 );
			Copy_u32Number /= 10 ;
		}
		while( Local_u32Reversed != 1 )
		{
			CLCD_VoidSendData ( ( Local_u32Reversed % 10 ) + 48 );
			Local_u32Reversed /= 10 ;
		}

	}

}

void CLCD_voidSendFloatNumber(f64 number)
{
	s8 i=0,j=0;
	u32 x=number;
	u8 base_NUM[10]={0};
	f64 y=0;
	if (number<0)
	{
		number*=-1;
		x=number;
		CLCD_VoidSendData('-');
	}
	y=(((number+1.0)-x)*10000000);
	while(x !=0)
	{
		base_NUM[i++] = x % 10;
		x/=10;
	}
	u8 k=i--;
	while(i>=0)
	{
		CLCD_VoidSendData(base_NUM[i--]+48);
	}
	u8 F_NUM[10]={0};
	i=0;
	u32 z=y;
	CLCD_VoidSendData('.');
	while(z !=0)
	{
		F_NUM[i++] = z % 10;
		z/=10;
	}
	i-=2;
	for(j=0;j<10;j++)
	{
		if(F_NUM[j]==0)
		{
			F_NUM[j]='k';
		}
		else
		{
			break;
		}
	}
	while(F_NUM[i]!='k'&& k!=7)
	{
		CLCD_VoidSendData(F_NUM[i--]+48);
		k++;
	}

}
