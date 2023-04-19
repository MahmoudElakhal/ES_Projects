/************************************************************************************************/
/************************************************************************************************/
/**********************************	  Author  :  Mahmoud ELakhal ********************************/
/**********************************	  Layer   : HAL   		*************************************/
/**********************************	  SWC  : KEYPAD   		*****************************************/
/**********************************	  Version : 1.00   		*************************************/
/************************************************************************************************/
/************************************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"

u8 KEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KEYPAD_NO_PRESSED_KEY , Local_u8ColumnIndex , Local_u8RowIndex , Local_u8PinState;
	static	u8 Local_u8KEYPADArr[COLUMN_NUM][ROW_NUM]= KEYPAD_ARR_VAL;
	static	u8 Local_u8KEPYAD_ColumnArr[COLUMN_NUM] = {KEYPAD_COLUMN0_PIN,KEYPAD_COLUMN1_PIN,KEYPAD_COLUMN2_PIN,KEYPAD_COLUMN3_PIN};
	static	u8 Local_u8KEPYAD_RowArr[ROW_NUM] = {KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};

	for ( Local_u8ColumnIndex = 0 ; Local_u8ColumnIndex < COLUMN_NUM ; Local_u8ColumnIndex++)
	{
		/*Activate Current Column*/
		DIO_u8SetPinValue(KEYPAD_PORT ,Local_u8KEPYAD_ColumnArr[Local_u8ColumnIndex] ,DIO_u8PIN_LOW);
		for(Local_u8RowIndex = 0 ;Local_u8RowIndex < ROW_NUM ; Local_u8RowIndex++)
		{
			/*Read The Current Row*/
			DIO_u8GetPinValue(KEYPAD_PORT , Local_u8KEPYAD_RowArr[Local_u8RowIndex] , &Local_u8PinState);

			/*Check if switch is pressed*/
			if(DIO_u8PIN_LOW == Local_u8PinState )
			{
				/*Prevent if two buttons are pressed*/
				Local_u8PressedKey = Local_u8KEYPADArr[Local_u8RowIndex][Local_u8ColumnIndex];

				/*To check whether user still pressing or not
				 * busy waiting until key is released*/
				//Value is before the variable to send error if it`s not true
				while(DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KEYPAD_PORT , Local_u8KEPYAD_RowArr[Local_u8RowIndex] , &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KEYPAD_PORT ,Local_u8KEPYAD_ColumnArr[Local_u8ColumnIndex] ,DIO_u8PIN_HIGH);

	}



	return Local_u8PressedKey;
}
