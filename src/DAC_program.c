/*
 * DAC_program.c
 *
 *  Created on: Jul 27, 2024
 *      Author: user
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO_interface.h"
#include "../HAL/DAC_interface.h"
#include "../HAL/DAC_config.h"
#include "../HAL/DAC_private.h"

void DAC_voidSetAnalogValue(u8 Copy_u8Port,u16 Copy_u16Value_mV)
{
	DIO_u8SetPortValue(Copy_u8Port,(u8)((u16)((Copy_u16Value_mV*255UL)/5000UL)));
}
