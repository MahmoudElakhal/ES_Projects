#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_Interface.h"
#include "DIO_interface.h"
#include "CLCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "DCMOTOR_Interface.h"
#include "STEPPER_Interface.h"
#include "util/delay.h"
#define LCD_LINE_GRIDS		16

#define DC_MOTOR			1
#define STEPPER_MOTOR		2

#define MOTOR_CW			1
#define MOTOR_CCW			2

#define MAX			3

#define LCD_LINE_1		0
#define LCD_LINE_2		1

#define LCD_COL_1		0

void main(void)
{
	u8 Local_u8Counter=0 , Local_u8PressedKey ,Arr[MAX]={0} ;
	u16 Angle = 0;
	PORT_voidInit();
	CLCD_VoidInit();

	CLCD_VoidSendString("Welcome to");
	CLCD_VoidGoToXY(LCD_LINE_2,LCD_COL_1);
	CLCD_VoidSendString("Motor Dashboard");
	_delay_ms(1500);
	CLCD_VoidSendCommand(CLCD_CLEAR);

	while(1)
	{
		CLCD_VoidSendString("1:DC 2:Stepper");

		/*Reading Switch
		 * if 1 then go to DC motor options
		 * if 2 then go to Stepper Motor options
		 * */
		do
		{
			Local_u8PressedKey = KEYPAD_u8GetPressedKey();
		}while( Local_u8PressedKey == KEYPAD_NO_PRESSED_KEY );

		/*DC Motor Options
		 * 1: Rotate CW
		 * 2: Rotate CCW
		 * */
		if(Local_u8PressedKey == DC_MOTOR)
		{
			CLCD_VoidSendCommand(CLCD_CLEAR);
			CLCD_VoidSendString("Press 1:CW,2:CCW");
			/*Reading Rotation
			 * options 1 : Clock Wise
			 * 		   2 : Counter Clock Wise
			 * */
			do
			{
				Local_u8PressedKey = KEYPAD_u8GetPressedKey();
			}while( Local_u8PressedKey == KEYPAD_NO_PRESSED_KEY );
			if ( Local_u8PressedKey == MOTOR_CW)
			{
				DCMotor_voidRotateCW(DIO_u8PORTB , DIO_u8PIN0 ,DIO_u8PIN1 );
			}
			else if( Local_u8PressedKey == MOTOR_CCW)
			{
				DCMotor_voidRotateCCW(DIO_u8PORTB , DIO_u8PIN0 ,DIO_u8PIN1);
			}
			CLCD_VoidSendCommand(CLCD_CLEAR);
		}
		/*Stepper Motor Options for a given angle 0 : 360
		 * 1: Rotate CW
		 * 2: Rotate CCW
		 * */
		else if ( Local_u8PressedKey ==STEPPER_MOTOR )
		{
			CLCD_VoidSendCommand(CLCD_CLEAR);
			CLCD_VoidSendString("Set angle: ");
			/*Reading Angle*/
			while(1)
			{
				do
				{
					Local_u8PressedKey = KEYPAD_u8GetPressedKey();
				}while( Local_u8PressedKey == KEYPAD_NO_PRESSED_KEY );
				if (Local_u8PressedKey == '=' )
				{
					break;
				}
				/*Send Entered Digits of First Operand to LCD*/
				CLCD_voidSendNumber(Local_u8PressedKey);
				/*Saving Digits into and array */
				Arr[Local_u8Counter] = Local_u8PressedKey;
				Local_u8Counter++;
			}
			/*Calculation angle value*/
			switch(Local_u8Counter)
			{
			case 0 : Angle = 0 ; break ;
			case 1 : Angle = Arr[0]; break;
			case 2 : Angle = Arr[0] * 10 + Arr[1] ; break ;
			case 3 : Angle = Arr[0] * 100 + Arr[1]*10 + Arr[2] ; break ;
			}

			/*Setting the parameters of Stepper motor function */
			Step_Motor Step = {DIO_u8PORTB , DIO_u8PIN2 , DIO_u8PIN3 , DIO_u8PIN4 , DIO_u8PIN5 , 2 , Angle , 0.175};

			/*Move to next line in lcd*/
			CLCD_VoidGoToXY(LCD_LINE_2,LCD_COL_1);
			CLCD_VoidSendString("Press 1:CW,2:CCW");

			/*Reading Rotation
			 * options 1 : Clock Wise
			 * 		   2 : Counter Clock Wise
			 * */
			do
			{
				Local_u8PressedKey = KEYPAD_u8GetPressedKey();
			}while( Local_u8PressedKey == KEYPAD_NO_PRESSED_KEY );

			/*Rotation is CW*/
			if ( Local_u8PressedKey == MOTOR_CW)
			{
				CLCD_VoidSendCommand(CLCD_CLEAR);
				STEPPER_voidFullStepRotateCW(&Step);
				CLCD_VoidSendString("Angle Reached");
				_delay_ms(2000);

			}

			/*Rotation is CCW*/
			else if( Local_u8PressedKey == MOTOR_CCW)
			{
				CLCD_VoidSendCommand(CLCD_CLEAR);
				STEPPER_voidFullStepRotateCCW(&Step);
				CLCD_VoidSendString("Angle Reached");
				_delay_ms(2000);

			}
			CLCD_VoidSendCommand(CLCD_CLEAR);
		}
	}
}


