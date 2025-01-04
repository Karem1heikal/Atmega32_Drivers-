/*
 * RTOS_program.c
 *
 *  Created on: Aug 24, 2024
 *      Author: user
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../RTOS_stack/RTOS/RTOS_interface.h"
#include "../RTOS_stack/RTOS/RTOS_private.h"
#include "../RTOS_stack/RTOS/RTOS_config.h"
#include "../MCAL/TIMER_interface.h"
#include "../MCAL/GIE_interface.h"

TASK_t SysTask [TASK_NUM]= {{NULL}};

void RTOS_voidStart()
{
	Timer_t t0 = {TIMER0,TIMER0_CTC,OC0_DIS,TIMER10_DIV_64,TIMER0_INT_ENABLE};
	TIMER0_voidSetCompMatchValue(125);
	TIMER0_u8SetCallBack(&t0,voidSceduler);
	GIE_voidEnable();
	TIMER_voidInit(&t0);
}

u8 RTOS_u8CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (* Notifiction)(),u16 Copy_u16FirstDelay)
{
	u8 Local_u8ErrorState = OK;
	if(SysTask[Copy_u8Priority].Notifiction == NULL)
	{
		SysTask[Copy_u8Priority].State = RESUME_TASK;
		SysTask[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
		SysTask[Copy_u8Priority].Notifiction = Notifiction;
		SysTask[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
	}
	else
		Local_u8ErrorState = NOTOK;

	return Local_u8ErrorState;
}

static void voidSceduler()
{
	/*
	static u16 Local_u16TickCounter = 0;
	u8 LocaL_u8TaskIterator = 0;
	Local_u16TickCounter++;
	for(LocaL_u8TaskIterator=0;LocaL_u8TaskIterator<TASK_NUM;LocaL_u8TaskIterator++)
	{
		if(SysTask[LocaL_u8TaskIterator].State == RESUME_TASK)
		{

				if((Local_u16TickCounter % SysTask[LocaL_u8TaskIterator].Periodicity)==0)
				{
					if(SysTask[LocaL_u8TaskIterator].Notifiction!=NULL)
					{
						SysTask[LocaL_u8TaskIterator].Notifiction();
					}
					SysTask[LocaL_u8TaskIterator].FirstDelay=SysTask[LocaL_u8TaskIterator].Periodicity-1;
				}
		}
		if(Local_u16TickCounter == 65535)
			Local_u16TickCounter = Local_u16TickCounter % SysTask[LocaL_u8TaskIterator].Periodicity;
	}
*/
	static u16 Local_u16TickCounter = 0;
	u8 LocaL_u8TaskIterator = 0;
	for(LocaL_u8TaskIterator=0;LocaL_u8TaskIterator<TASK_NUM;LocaL_u8TaskIterator++)
	{
		if(SysTask[LocaL_u8TaskIterator].State == RESUME_TASK)
		{
			if(SysTask[LocaL_u8TaskIterator].FirstDelay==0)
			{
				if(SysTask[LocaL_u8TaskIterator].Notifiction!=NULL)
				{
					SysTask[LocaL_u8TaskIterator].Notifiction();
					SysTask[LocaL_u8TaskIterator].FirstDelay=SysTask[LocaL_u8TaskIterator].Periodicity-1;
				}
			}
			else
				SysTask[LocaL_u8TaskIterator].FirstDelay--;
		}
	}
}
void RTOS_voidSuspendTask(u8 Copy_u8priodity)
{
	SysTask[Copy_u8priodity].State = SUSPENDED_TASK;
}

void RTOS_voidResumeTask(u8 Copy_u8priodity)
{
	SysTask[Copy_u8priodity].State = RESUME_TASK;
}
void RTOS_voidDeleteTask(u8 Copy_u8priodity)
{
	SysTask[Copy_u8priodity].Notifiction = NULL;
}
