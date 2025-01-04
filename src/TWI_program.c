/*
 * TWI_program.c
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/TWI_private.h"
#include "../MCAL/TWI_config.h"

#include "../MCAL/TWI_register.h"
#include "../MCAL/TWI_interface.h"


void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	if(Copy_u8SlaveAddress==0)
	{
		// Not assign address
	}
	else
	{
		TWAR &= MSTR_ADDR_MASK;
		TWAR |= Copy_u8SlaveAddress<<TWAR_TWA0;
	}
	// Set Prescaler
	TWSR &= 0xfc;
	TWSR |= TWI_PRE_VALUE;
	TWBR = TWI_BAUD_RATE;
	// Enable ACK bit
	TWI_ENABLE_ACK?SET_BIT(TWCR,TWCR_TWEA):CLR_BIT(TWCR,TWCR_TWEA);
	//TWI_GCALL_ENABLE
	TWI_GCALL_ENABLE?SET_BIT(TWAR,TWAR_TWGCE):CLR_BIT(TWAR,TWAR_TWGCE);
	// Enable TWI Peripheral
	SET_BIT(TWCR,TWCR_TWEN);
}
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	TWAR &= MSTR_ADDR_MASK;
	TWAR |= Copy_u8SlaveAddress<<TWAR_TWA0;
	// Enable ACK bit
	TWI_ENABLE_ACK?SET_BIT(TWCR,TWCR_TWEA):CLR_BIT(TWCR,TWCR_TWEA);

	//TWI_GCALL_ENABLE
	TWI_GCALL_ENABLE?SET_BIT(TWAR,TWAR_TWGCE):CLR_BIT(TWAR,TWAR_TWGCE);
	// Enable TWI Peripheral
	SET_BIT(TWCR,TWCR_TWEN);
}
u8 TWI_u8StartCondition()
{
	TWI_ErrStatus Local_intErrorState = OK;
	// send start condition
	SET_BIT(TWCR,TWCR_TWSTA);
	// Clear flag to start the previous operation
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);

	if((TWSR & STATUS_MASK)==START_ACK)
	{

	}
	else
		Local_intErrorState = ErrStartCondtion;
	return Local_intErrorState;
}
TWI_ErrStatus TWI_u8RepeatedStart()
{
	TWI_ErrStatus Local_intErrorState = OK;

	SET_BIT(TWCR,TWCR_TWSTA);

	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);

	if((TWSR & STATUS_MASK)==REP_START_ACK)
	{

	}
	else
		Local_intErrorState = ErrRepeatedStartCond;
	return Local_intErrorState;
}
TWI_ErrStatus TWI_u8SendSLA_WR(u8 Copy_u8Address)
{
	TWI_ErrStatus Local_intErrorState = OK;

	CLR_BIT(TWCR,TWCR_TWSTA);
	TWDR = Copy_u8Address<<1;
	CLR_BIT(TWDR,0);

	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);

	if((TWSR & STATUS_MASK)==SLAVE_ADD_AND_WR_ACK)
	{

	}
	else
		Local_intErrorState = ErrSlaveAddWithWrite;
	return Local_intErrorState;
}
TWI_ErrStatus TWI_u8SendSLA_RD(u8 Copy_u8Address)
{
	TWI_ErrStatus Local_intErrorState = OK;

	CLR_BIT(TWCR,TWCR_TWSTA);
	TWDR = (Copy_u8Address<<1|1);
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);

	if((TWSR & STATUS_MASK)==SLAVE_ADD_AND_RD_ACK)
	{

	}
	else
		Local_intErrorState = ErrSlaveAddWithRead;
	return Local_intErrorState;
}
TWI_ErrStatus TWI_u8MasterSendDataByte(u8 Copy_u8Data)
{
	TWI_ErrStatus Local_intErrorState = OK;
	// write data to send
	TWDR = Copy_u8Data;
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);

	if((TWSR & STATUS_MASK)==MSTR_WR_BYTE_ACK)
	{

	}
	else
		Local_intErrorState = ErrMasterSendDataByte;
	return Local_intErrorState;
}
TWI_ErrStatus TWI_u8MasterReadDataByte(u8* Copy_pu8Read)
{
	TWI_ErrStatus Local_intErrorState = OK;
	// clear flag to start the slave to send data
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);
	if((TWSR & STATUS_MASK)==MSTR_RD_BYTE_WITH_ACK)
	{
		*Copy_pu8Read = TWDR;
	}
	else
		Local_intErrorState = ErrMasterReadDataByte;
	return Local_intErrorState;


}

TWI_ErrStatus TWI_u8SlaveSendDataByte(u8 Copy_u8Data)
{
	TWI_ErrStatus Local_intErrorState = OK;

	TWDR = Copy_u8Data;
	// clear flag to start the slave to send data
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);
	if((TWSR & STATUS_MASK)==SLAVE_BYTE_TRANSMITTED){

	}
	else
		Local_intErrorState = ErrSlaveSendDataByte;
	return Local_intErrorState;
}
TWI_ErrStatus TWI_u8SlaveReadDataByte(u8* Copy_pu8Read)
{
	TWI_ErrStatus Local_intErrorState = OK;
	// clear flag to start the slave to send data
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);

	if((TWSR & STATUS_MASK)==SLAVE_ADD_RCVD_WR_REQ){

	}
	else
		Local_intErrorState = ErrSlaveAddRecvWithWriteReq;
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) != 1);
	if((TWSR & STATUS_MASK)==SLAVE_DATA_RECEIVED)
	{
		*Copy_pu8Read = TWDR;
	}
	else
		Local_intErrorState = ErrSlaveReadDataByte;
	return Local_intErrorState;
}
void TWI_voidAckEnable()
{
	// Enable ACK bit
	SET_BIT(TWCR,TWCR_TWEA);
}
void TWI_voidAckDisable()
{
	// Disable ACK bit
	CLR_BIT(TWCR,TWCR_TWEA);
}
void TWI_voidGeneralCallEnable()
{
	// Enable general call bit
	SET_BIT(TWAR,TWAR_TWGCE);
}


void TWI_voidGeneralCallDisable()
{
	// Disable general call bit
	CLR_BIT(TWAR,TWAR_TWGCE);
}
void TWI_u8StopCondition()
{
	SET_BIT(TWCR,TWCR_TWSTO);
	// clear flag to start the slave to send data
	SET_BIT(TWCR,TWCR_TWINT);
}
