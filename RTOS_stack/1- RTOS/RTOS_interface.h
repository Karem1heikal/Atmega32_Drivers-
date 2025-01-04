/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : RTOS Stack    **********************************/
/************************* SWC    : RTOS        **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart();

u8 RTOS_u8CreateTask(u8 Copy_u8Priority,u16 Copy_u16Priodicity,void (*Copy_pvTaskFunc)(),u16 Copy_u16FirstDelay);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumedTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);


#endif
