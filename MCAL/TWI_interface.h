/*
 * TWI_interface.h
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	ErrStartCondtion = 4,
	ErrRepeatedStartCond,
	ErrSlaveAddWithWrite,
	ErrSlaveAddWithRead,
	ErrMasterSendDataByte,
	ErrMasterReadDataByte,
	ErrSlaveSendDataByte,
	ErrSlaveReadDataByte,
	ErrSlaveAddRecvWithWriteReq,

}TWI_ErrStatus;
/*pass 0 in SlaveAddress argument if will not be addressed*/
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_u8StartCondition();
TWI_ErrStatus TWI_u8RepeatedStart();

TWI_ErrStatus TWI_u8SendSLA_WR(u8 Copy_u8Address);
TWI_ErrStatus TWI_u8SendSLA_RD(u8 Copy_u8Address);

TWI_ErrStatus TWI_u8MasterSendDataByte(u8 Copy_u8Data);
TWI_ErrStatus TWI_u8MasterReadDataByte(u8* Copy_pu8Read);

TWI_ErrStatus TWI_u8SlaveSendDataByte(u8 Copy_u8Data);
TWI_ErrStatus TWI_u8SlaveReadDataByte(u8* Copy_pu8Read);

// Case of Enable Ack
// at receiving my own Slave address
// A General call has been received
// a data byte has been received
void TWI_voidAckEnable();

void TWI_voidAckDisable();

void TWI_voidGeneralCallEnable();

void TWI_voidGeneralCallDisable();

void TWI_u8StopCondition();





#endif /* TWI_INTERFACE_H_ */
