/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : RTOS Stack    **********************************/
/************************* SWC    : TIMER0        **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

static void(*TIMERS_pvCallBackFunc[8])()={NULL};

u8 TIMER_u8Init(TIMERS_T* Copy_TimerOption)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_TimerOption->TimerNum)
		{
		case TIMER0:
			// timer0 initialize
			switch(Copy_TimerOption->Mode){
			case Normal:CLR_BIT(TCCR0,TCCR0_WGM01);CLR_BIT(TCCR0,TCCR0_WGM00);break;
			case PWM_Phase_Correct :CLR_BIT(TCCR0,TCCR0_WGM01);SET_BIT(TCCR0,TCCR0_WGM00);break;
			case CTC:SET_BIT(TCCR0,TCCR0_WGM01);CLR_BIT(TCCR0,TCCR0_WGM00);SET_BIT(TIMSK,TIMSK_OCIE0);break;
			case Fast_PWM:SET_BIT(TCCR0,TCCR0_WGM01);SET_BIT(TCCR0,TCCR0_WGM00);break;
			default:
				Local_u8ErrorState=NOTOK;
			}
			//Compare Output Mode pin(OC0)
			if((0<=Copy_TimerOption->CompMode)&&(Copy_TimerOption->CompMode<=3)){
			TCCR0&= TIMER_COM_MASK;
			TCCR0|= Copy_TimerOption->CompMode<<TCCR0_COM00;
			}
			else
				Local_u8ErrorState=NOTOK;
			//Clock Select
			if((0<=Copy_TimerOption->ClkDiv)&&(Copy_TimerOption->ClkDiv<=7)){
			TCCR0&=	TIMER_PRESCALER_MASK;
			TCCR0|=	Copy_TimerOption->ClkDiv;
			}
			else
				Local_u8ErrorState=NOTOK;
			break;
		default:
				Local_u8ErrorState=NOTOK;
		}
	return Local_u8ErrorState;
}
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}

u8 TIMER0_u8SetCallBack(TIMERS_T* Copy_TimerOption ,void(*Copy_pvCallBackFunc)())
{

	u8 Local_u8ErrorState=OK;
	if((Copy_pvCallBackFunc==NULL))
	{
		Local_u8ErrorState=NULL_POINTER;

	}
	else {
		switch(Copy_TimerOption->Mode){
		case Normal:/*Normal mode */
			SET_BIT(TIMSK,TIMSK_TOIE0);
			TIMERS_pvCallBackFunc[TIMER0_OVF]=Copy_pvCallBackFunc;
			break;
		case CTC: /*compare match mode*/
			TIMERS_pvCallBackFunc[TIMER0_COMP]=Copy_pvCallBackFunc;
			break;
		}

	}
	return Local_u8ErrorState;
}

/* ISR of Timer/Counter0 Compare Match */

void __vector_10(void)	__attribute__((signal));
void __vector_10(void)
{

	if(TIMERS_pvCallBackFunc[TIMER0_COMP]!=NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_COMP]();
	}
	else{
		//Nothing;
	}
}

/* ISR of Timer/Counter0 Overflow */

void __vector_11(void)	__attribute__((signal));
void __vector_11(void)
{
	if(TIMERS_pvCallBackFunc[TIMER0_OVF]!=NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_OVF]();
	}
	else{
		//Nothing;
	}
}

