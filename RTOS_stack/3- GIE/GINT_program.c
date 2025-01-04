/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : MCAL         **********************************/
/************************* SWC    : GINT          **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GINT_register.h"
#include "GINT_interface.h"

void GINT_voidEnable()
{
	SET_BIT(SREG,SREG_I);
}
void GINT_voidDisable()
{
	CLR_BIT(SREG,SREG_I);
}
