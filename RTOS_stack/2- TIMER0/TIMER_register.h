/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : RTOS Stack    **********************************/
/************************* SWC    : TIMER0        **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0 			*((volatile u8*)0x53)
#define TCCR0_WGM00		6
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01		3

#define TCNT0 			*((volatile u8*)0x52)
#define TIMSK 			*((volatile u8*)0x59)
#define TIMSK_OCIE2     7
#define TIMSK_TOIE2     6
#define TIMSK_TICIE1	5						/*Timer1 Input Capture interrupt enable*/
#define TIMSK_OCIE1A 	4						/*Output Compare A Match Interrupt Enable*/
#define TIMSK_OCIE1B 	3						/*Output Compare B Match Interrupt Enable*/
#define TIMSK_TOIE1		2						/*Overflow Interrupt Enable*/
#define	TIMSK_OCIE0 	1
#define TIMSK_TOIE0		0


#define TIFR 		*((volatile u8*)0x58)
#define OCR0 		*((volatile u8*)0x5C)

/*timer 1 registers */

#define TCCR1A    			*((volatile u8*)0x4F)
#define TCCR1A_COM1A1 		7
#define TCCR1A_COM1A0 		6
#define TCCR1A_COM1B1 		5
#define TCCR1A_COM1B0 		4
#define TCCR1A_WGM11 		1
#define TCCR1A_WGM10		0

#define TCCR1B   	*((volatile u8*)0x4E)
#define TCCR1B_ICNC1				7							/*Input Capture Noise Canceler*/
#define TCCR1B_ICES1				6							/*Input capture Edge Select*/
#define TCCR1B_WGM13 				4
#define TCCR1B_WGM12 				3

#define TCNT1   	*((volatile u16*)0x4C)
#define OCR1A		*((volatile u16*)0x4A)

#define OCR1B		*((volatile u16*)0x48)

#define ICR1		*((volatile u16*)0x46)


/**************************************** TIMER2 registers ******************************/

#define TCCR2				*((volatile u16*)0x45)
#define TCCR2_WGM20		    6
#define TCCR2_COM21		    5
#define TCCR2_COM20		    4
#define TCCR2_WGM21		    3

#define TCNT2               *((volatile u16*)0x44)
#define OCR2                *((volatile u16*)0x43) /*Output Compare Register Timer/Counter2*/

#define ASSR                *((volatile u16*)0x42)
#define ASSR_AS2   			3						/*Asynchronous Timer/Counter2*/
#define ASSR_TCN2UB			2						/*Timer/Counter2 Update Busy*/
#define ASSR_OCR2UB			1						/*Output Compare Register2 Update Busy*/
#define ASSR_TCR2UB			0						/*Timer/Counter Control Register2 Update Busy*/

#define SFIOR				*((volatile u16*)0x50)	/*Prescaler Reset*/
#define SFIOR_PSR2 			1						/*Timer/Counter2 */
#define SFIOR_PSR10			0						/*Timer/Counter1 and Timer/Counter0*/
#endif
