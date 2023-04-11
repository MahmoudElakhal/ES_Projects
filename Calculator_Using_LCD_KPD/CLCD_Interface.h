/*
 * CLCD_Interface.h
 *
 *  Created on: Feb 12, 2023
 *      Author: Softlaptop
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define CLCD_CLEAR		0b00000001


void CLCD_VoidSendCommand (u8 Copy_u8Command);

void CLCD_VoidSendData (u8 Copy_u8Data);

void CLCD_VoidInit(void);

/*we use const to make sure that we will not change in the string*/
void CLCD_VoidSendString( const char * Copy_PcString);

void CLCD_VoidGoToXY (u8 Copy_u8XPos , u8 Copy_u8YPos);

void CLCD_VoidWriteSpecialCharacter(u8 * Copypu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos );

void LCD_VoidWriteNumber(u16 Copy_u32Number);

void CLCD_voidSendNumber( u32 Copy_u32Number);

void CLCD_voidSendFloatNumber(f64 number);

#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
