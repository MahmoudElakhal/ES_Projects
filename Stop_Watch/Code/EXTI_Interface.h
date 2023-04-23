/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : MCAL   		         ********************************/
/*****************************	  SWC     : EXTI		         ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL		1
#define ON_CHANGE		2
#define FALLING_EDGE	3
#define RISING_EGDE		4

#define ENABLED			1
#define DISABLED		2

void EXTI_voidInt0_INIT(void);

void EXTI_voidInt1_INIT(void);

void EXTI_voidInt2_INIT(void);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func) (void));
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func) (void));
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func) (void));

#endif /* EXTI_INTERFACE_H_ */
