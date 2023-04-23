#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_Interface.h"
#include "DIO_interface.h"
#include "EXTI_Interface.h"
#include "TIMER_Interface.h"
#include "GIE_Interface.h"
#include "util/delay.h"

#define SEG1_Enable		0b00000001
#define SEG2_Enable		0b00000010
#define SEG3_Enable		0b00000100
#define SEG4_Enable		0b00001000
#define SEG5_Enable		0b00010000
#define SEG6_Enable		0b00100000

u8 Sec = 0, Min = 0, Hr = 0;

void INT0ISR(void);
void INT1ISR(void);
void INT2ISR(void);

void TIMER1AISR(void);

void main(void)
{

	/*Initializing Port , pin Direction and initial values
	 * PortA pin0-->6 Output Low Data pins
	 * PortC Pin0-->4 Output low Control Pins
	 * PortD Pin2 input with internal pull-up resistor
	 * PortD Pin3 input
	 * PortB Pin2 input with internal pull-up resistor */
	PORT_voidInit();

	/*Enable Global interrupt*/
	GIE_voidEnable();

	/*Initialize External Interrupt int0*/
	EXTI_voidInt0_INIT();
	EXTI_u8Int0SetCallBack(INT0ISR);

	/*Initialize External Interrupt int1*/
	EXTI_voidInt1_INIT();
	EXTI_u8Int1SetCallBack(INT1ISR);

	/*Initialize External Interrupt int2*/
	EXTI_voidInt2_INIT();
	EXTI_u8Int2SetCallBack(INT2ISR);

	/*Initialize Timer1 on CTC mode*/
	TIMER1_voidINIT();
	TIMER1_u8SetCallBack(TIMER1AISR);

	while (1)
	{
		/*Enable First SSD*/
		DIO_u8SetPortValue(DIO_u8PORTA,SEG1_Enable);
		/*Send Seconds Data to display it*/
		DIO_u8SetPortValue(DIO_u8PORTC,((Sec%10)&0x0F));
		/*Delay for Mux 7-segments*/
		_delay_ms(2);

		/*Enable Second SSD*/
		DIO_u8SetPortValue(DIO_u8PORTA,SEG2_Enable);
		DIO_u8SetPortValue(DIO_u8PORTC,((Sec/10)&0x0F));
		_delay_ms(2);

		/*Enable Third SSD*/
		DIO_u8SetPortValue(DIO_u8PORTA,SEG3_Enable);
		DIO_u8SetPortValue(DIO_u8PORTC,((Min%10)&0x0F));
		_delay_ms(2);

		/*Enable Fourth SSD*/
		DIO_u8SetPortValue(DIO_u8PORTA,SEG4_Enable);
		DIO_u8SetPortValue(DIO_u8PORTC,((Min/10)&0x0F));
		_delay_ms(2);

		/*Enable Fifth SSD*/
		DIO_u8SetPortValue(DIO_u8PORTA,SEG5_Enable);
		DIO_u8SetPortValue(DIO_u8PORTC,((Hr%10)&0x0F));
		_delay_ms(2);

		/*Enable Sixth SSD*/
		DIO_u8SetPortValue(DIO_u8PORTA,SEG6_Enable);
		DIO_u8SetPortValue(DIO_u8PORTC,((Hr/10)&0x0F));
		_delay_ms(2);
	}
}


/*Reset Stop Watch*/
void INT0ISR(void)
{
	Sec = 0;
	Min = 0;
	Hr  = 0;
}

/*Pause Stop watch*/
void INT1ISR(void)
{
	TIMER1_voidStop();
}

/*Resume Stop watch*/
void INT2ISR(void)
{
	TIMER1_voidResume();
}
void TIMER1AISR(void)
{
	Sec++;
	if(Sec== 60){
		Min++;
		Sec=0;
	}
	if(Min== 60){
		Hr++;
		Min=0;
	}
	if(Hr == 60){
		Hr  = 0;
		Min = 0;
		Sec = 0;
	}

}

