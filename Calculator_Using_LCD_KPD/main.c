#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_Interface.h"
#include "CLCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "util/delay.h"

#define MAX         5
void main (void)
{
	u16 FirstNum= 0  , SecondNum =  0;
	u8 Local_u8Key ,Local_u8Counter1= 0 ,Local_u8Counter2= 0  ,Operation ,FLAG1 = 0,FLAG2 = 1;
	u8  Num1[MAX] = {0} , Num2[MAX] = {0};
	PORT_voidInit();
	CLCD_VoidInit();

	while(1)
	{
		/*Reading First Number Digits */
		while(FLAG1 != 1 )
		{
			do
			{
				Local_u8Key = KEYPAD_u8GetPressedKey();
			}while(Local_u8Key == KEYPAD_NO_PRESSED_KEY);

			/*Break the Loop when an operation is entered*/
			if (Local_u8Key == '+' || Local_u8Key == '-' || Local_u8Key == '/' || Local_u8Key == '*')
			{
				FLAG1++;
				/*Sending Operation operator to LCD*/
				CLCD_VoidSendData(Local_u8Key);
				/*Saving Operation to use it in calculating result*/
				Operation = Local_u8Key;
				break;
			}
			/*Send Entered Digits of First Operand to LCD*/
			CLCD_voidSendNumber(Local_u8Key);
			/*Saving Digits into and array */
			Num1[Local_u8Counter1] = Local_u8Key;
			Local_u8Counter1++;

		}
		/*Reading Second Number Digits */
		while(FLAG2 != 0)
		{
			do
			{
				Local_u8Key = KEYPAD_u8GetPressedKey();
			}while(Local_u8Key == 0xff);
			/*Break the Loop when equal operator is entered*/
			if (Local_u8Key == '=' )
			{
				FLAG2--;
				CLCD_VoidSendData(Local_u8Key);

				break;
			}
			/*Send Entered Digits of Second Operand to LCD*/
			CLCD_voidSendNumber(Local_u8Key);
			/*Saving Digits into and array */
			Num2[Local_u8Counter2] = Local_u8Key;
			/*Counting Digits of Second Number*/
			Local_u8Counter2++;

		}
		if(Local_u8Key == '=' )
		{
			/*Calculating the value of the first and Second number
			 * This Code Supports only operation on 2-Bytes-Unsigned integers
			 */
			switch(Local_u8Counter1)
			{
			case 0 : FirstNum = 0; 			break;
			case 1 : FirstNum = Num1[0]; 	break;
			case 2 : FirstNum = Num1[0] * 10 + Num1[1] ; break;
			case 3 : FirstNum = Num1[0] * 10 * 10 + Num1[1] * 10 + Num1[2] ; break;
			case 4 : FirstNum = Num1[0] * 10 * 10 * 10 + Num1[1] * 10 * 10 + Num1[2] * 10 + Num1[3] ; break;
			case 5 : FirstNum = Num1[0] * 10 * 10 * 10 * 10 + Num1[1] * 10 * 10 * 10 + Num1[2] * 10 * 10 + Num1[3] * 10 + Num1[4] ; break;
			}
			switch(Local_u8Counter2)
			{
			case 0 : SecondNum = 0; 			break;
			case 1 : SecondNum = Num2[0]; 	break;
			case 2 : SecondNum = Num2[0] * 10 + Num2[1] ; break;
			case 3 : SecondNum = Num2[0] * 10 * 10 + Num2[1] * 10 + Num2[2] ; break;
			case 4 : SecondNum = Num2[0] * 10 * 10 * 10 + Num2[1] * 10 * 10 + Num2[2] * 10 + Num2[3] ; break;
			case 5 : SecondNum = Num2[0] * 10 * 10 * 10 * 10 + Num2[1] * 10 * 10 * 10 + Num2[2] * 10 * 10 + Num2[3] * 10 + Num2[4] ; break;
			}

			/*Calculating Results*/
			/*Addition*/
			if(Operation =='+')
			{
				CLCD_voidSendNumber(FirstNum + SecondNum);
			}
			/*Subtraction*/
			else if( Operation ==  '-' )
			{
				CLCD_voidSendNumber(FirstNum - SecondNum);
			}
			/*Multiplication*/
			else if( Operation == '*' )
			{
				CLCD_voidSendNumber(FirstNum * SecondNum);
			}
			/*Division*/
			else if( Operation =='/' )
			{
				if(SecondNum != 0)
				{
					if(FirstNum % SecondNum == 0)
					{
						CLCD_voidSendNumber(FirstNum /SecondNum);
					}
					else
					{
						/*Supporting Float Values*/
						CLCD_voidSendFloatNumber((float)FirstNum / SecondNum);
					}
				}
				else
				{
					/*Handling Division by Zero*/
					CLCD_VoidGoToXY(1,0);
					CLCD_VoidSendString("NO DIV by Zero");
					_delay_ms(2000);
					CLCD_VoidSendCommand(CLCD_CLEAR);
				}
			}
			/*Reset Key value*/
			Local_u8Key = KEYPAD_NO_PRESSED_KEY;
		}

	}
}


