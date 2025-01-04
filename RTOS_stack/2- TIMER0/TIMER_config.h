/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : RTOS Stack    **********************************/
/************************* SWC    : TIMER0        **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
//------------------------------ TIMER0 Configuration -----------------------------

/* Waveform Generation Mode Bit Description
 * Option:
 *         1- Normal
 *         2- PWM_Phase_Correct
 *         3- CTC
 *         4- Fast_PWM
 *
 * */
#define TIMER0_WGM	CTC

/* Compare Output Mode, non-PWM Mode
 * Option :
 *  	1- OC0_disconnected --> 	Normal port operation, OC0 disconnected.
 *  	2- Toggle_OC0	   	--> 	on compare match
 *  	3- Clear_OC0        --> 	on compare match
 *  	4- Set_OC0 			-->		on compare match
 *
 * */
/*
 * Compare Output Mode, Fast PWM Mode
 * Option:
 * 		 1-OC0_disconnected  	-->     Normal port operation, OC0 disconnected.
 *       2-  -----            	-->     Reserved
 *       3- STCC_NONINVERTED	-->     Clear OC0 on compare match, set OC0 at TOP
 *       4- CTSC_INVERTED   	-->     Set OC0 on compare match, clear OC0 at TOP
 *
 * */
#define TIMER0_COM	OC0_disconnected
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
#define TIMER0_CLK_SELECT		clkI_8

#endif
