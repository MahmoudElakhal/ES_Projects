/*
 * TIMER_Interface.h
 *
 *  Created on: Mar 15, 2023
 *      Author: Softlaptop
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER1_voidINIT(void);

void TIMER1_voidSetChannelACompareMatch(u16 Copy_u16CompareMatch);

u8 TIMER1_u8SetCallBack(void (* Copy_pvCallBackFunc) (void));

void TIMER1_voidStop(void);

void TIMER1_voidResume(void);

#endif /* TIMER_TIMER_INTERFACE_H_ */
