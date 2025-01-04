/*
 * TWI_config.h
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */

#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_

#define TWI_PRE_Div_1	0
#define TWI_PRE_Div_4	1
#define TWI_PRE_Div_16	2
#define TWI_PRE_Div_64	3

#define TWI_PRE_VALUE 	TWI_PRE_Div_1

#define TWI_BAUD_RATE 	2
/*
 *	ACK By Default
 *	ENABLE
 *	DISABLE
 * */

#define TWI_ENABLE_ACK 	ENABLE

#define TWI_GCALL_ENABLE DISABLE

#endif /* TWI_CONFIG_H_ */
