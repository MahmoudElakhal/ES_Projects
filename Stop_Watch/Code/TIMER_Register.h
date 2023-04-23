

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TIMSK			*((volatile u8*)0x59)	//timer mask
#define TIMSK_OCIE0		1						//output compare 0 interrupt enable
#define TIMSK_OCIE1A	4						//output compare 1A interrupt enable
#define TIMSK_OCIE1B	3						//output compare 1B interrupt enable
/*Setting Timer 1 for fast PWM */
#define TCCR1A			*((volatile u8*)0X4F)
#define TCCR1B			*((volatile u8*)0X4E)
#define TCNT1H          *((volatile u8 *)(0x4D))
#define TCNT1L          *((volatile u8 *)(0x4C))
#define TCNT1			*((volatile u16*)0X4C)    /* u16 for HIGH & LOW */
#define OCR1AL          *((volatile u8 *)(0x4A))
#define OCR1AH          *((volatile u8 *)(0x4B))
#define OCR1A			*((volatile u16*)0X4A)
#define OCR1BL          *((volatile u8 *)(0x48))
#define OCR1BH          *((volatile u8 *)(0x49))
#define OCR1B			*((volatile u16*)0X48)
#define ICR1H           *((volatile u8 *)(0x47))
#define ICR1L           *((volatile u8 *)(0x46))
#define ICR1			*((volatile u16*)0X46)

#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1

#define TCCR1A_COM1A1		7
#define TCCR1A_COM1A0		6
#define TCCR1A_COM1B1		5
#define TCCR1A_COM1B0		4
#define TCCR1A_FOC1A		3
#define TCCR1A_FOC1B		2

#define TCCR1B_WGM13		4
#define TCCR1B_WGM12		3

#define PRESCALER_MASK		0b11111000
#define DIVIDE_BY_1024		5
#define STOP_TIMER1			0

#define TIFR		    *((volatile u8*)0x58)
#define TIFR_OCF1A		4
#define TIFR_OCF1B		3

#endif /* TIMER_TIMER_REGISTER_H_ */
