/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : RTOS Stack    **********************************/
/************************* SWC    : TIMER0        **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

typedef struct
{
	u8 TimerNum;
	u8 Mode;
	u8 CompMode;
	u8 ClkDiv;
	// special for TIMER1
	u8 ChannelType;
	// ICU in TIMER1
	u8 ICU_Edge;
} TIMERS_T;

#define TIMER0	            0
#define TIMER1	            1
#define TIMER2	            2
/*
 * Timer number
 * Option :
 * 			1- TIMER0
 * 			2- TIMER1
 * 			3- TIMER2
 * */

#define Normal				1
#define PWM_Phase_Correct  	2
#define CTC 				3
#define Fast_PWM           	4

/* Waveform Generation Mode Bit Description
 * Option:
 *         1- Normal
 *         2- PWM_Phase_Correct
 *         3- CTC
 *         4- Fast_PWM
 *
 * */

#define OC0_disconnected        0b0000
#define Toggle_OC0	   	        0b0001
#define Clear_OC0               0b0010
#define Set_OC0 			    0b0011

/* Compare Output Mode, non-PWM Mode
 * Option :
 *  	1- OC0_disconnected --> 	Normal port operation, OC0 disconnected.
 *  	2- Toggle_OC0	   	--> 	on compare match
 *  	3- Clear_OC0        --> 	on compare match
 *  	4- Set_OC0 			-->		on compare match
 *
 * */

#define STCC_NONINVERTED        0b0010
#define CTSC_INVERTED   		0b0011

/*
 * Compare Output Mode, Fast PWM Mode
 * Option:
 * 		 1-OC0_disconnected  	-->     Normal port operation, OC0 disconnected.
 *       2-  -----            	-->     Reserved
 *       3- STCC_NONINVERTED	-->     Clear OC0 on compare match, set OC0 at TOP
 *       4- CTSC_INVERTED   	-->     Set OC0 on compare match, clear OC0 at TOP
 *
 * */
#define SDCU_NONINVERTED	 0b0010
#define CDSU_INVERTED        0b0011
/*
 * Compare Output Mode, Phase Correct PWM Mode
 * Option:
 *	     1- OC0_disconnected    -->     Normal port operation, OC0 disconnected.
 *	     2-  -----              -->     Reserved
 *	     3- SDCU_NONINVERTED	-->     Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
 *	     4- CDSU_INVERTED   	-->     Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
 */

/*
 * Clock Select Bit Description
 * Option:
 * 	      1- No_clock 			(Timer/Counter stopped).
 *        2- clkI_No			 (prescaling)
 *        3- clkI_8 			(From prescaler)
 * 	      4- clkI_64 			(From prescaler)
 * 		  5- clkI_256 			(From prescaler)
 * 		  6- clkI_1024 			(From prescaler)
 * 		  7- Ext_Falling_Edge	 External clock source on T0 pin. Clock on falling edge.
 * 		  8- Ext_Rising_Edge	 External clock source on T0 pin. Clock on rising edge.
 *
 * */

#define No_clock 				0
#define clkI_No					1
#define clkI_8 			        2
#define clkI_64 			    3
#define clkI_256 			    4
#define clkI_1024 			    5
#define Ext_Falling_Edge	    6
#define Ext_Rising_Edge	        7

/*
 * for CTC Mode, You must indicate Compare match value.
 * */

u8 TIMER_u8Init(TIMERS_T* Copy_TimerOption);

u8 TIMER0_u8SetCallBack(TIMERS_T* Copy_TimerOption ,void(*Copy_pvCallBackFunc)());
//u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(),u8 *Copy_u8CeilValue,u8 *Copy_u8Preload);
/* for Compare match mode  ,You must indicate
 * Definition : TIMER0_voidSetCompareMatch
 * Input : Copy_u8Value
 * function : to Set value of CompareMatch
 * */
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);
/* for overflow (Normal Mode)
 * Definition : TIMER0_u8SetPreloadValue
 * Input : Copy_u8Value
 * function : to Set value of Preload
 * */
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);

#endif
