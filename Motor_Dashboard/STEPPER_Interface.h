/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author  : Mahmoud ELakhal      ********************************/
/*****************************    Layer   : HAL   		         ********************************/
/*****************************	  SWC     : STEPPER_Motor        ********************************/
/*****************************	  Version : 1.00   		         ********************************/
/************************************************************************************************/
/************************************************************************************************/
#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

typedef struct
{
	u8 Copy_u8PortID;
	u8 Copy_u8Pin1ID;
	u8 Copy_u8Pin2ID;
	u8 Copy_u8Pin3ID;
	u8 Copy_u8Pin4ID;
	u8 Copy_u8Speed;
	f32 Copy_u8Angle;
	f32 Copy_u8Resolution;
}Step_Motor;

void STEPPER_voidFullStepRotateCW( Step_Motor * STEP );
void STEPPER_voidFullStepRotateCCW(Step_Motor * STEP);
void STEPPER_voidHalfStepRotateCW(Step_Motor * STEP);
void STEPPER_voidHalfStepRotateCCW(Step_Motor * STEP);
void STEPPER_voidStop(Step_Motor * STEP);

#endif /* STEPPER_INTERFACE_H_ */
