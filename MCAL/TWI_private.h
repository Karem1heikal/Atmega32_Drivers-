/*
 * TWI_private.h
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define START_ACK				0x08	/* start has been sent */
#define REP_START_ACK           0x10	/* repeated start */
#define SLAVE_ADD_AND_WR_ACK    0x18	/* master transmit ( SLA + W ) ACK */
#define SLAVE_ADD_AND_RD_ACK    0x40	/* master transmit ( SLA + R ) ACK */
#define MSTR_WR_BYTE_ACK        0x28	/* master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK   0x50	/* master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK  0x58	/* master received data with NACK */

#define SLAVE_ADD_RCVD_RD_REQ   0xA8	/* means that slave address is received with read request*/
#define SLAVE_ADD_RCVD_WR_REQ   0x60    /* means that slave address is received with write request*/

#define SLAVE_DATA_RECEIVED     0x80	/* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED  0xB8	/* means that the written byte is transmitted */

#define MSTR_ADDR_MASK 0x01;

#define ENABLE 			1
#define DISABLE 		0

#define STATUS_MASK		0XF8


#endif /* TWI_PRIVATE_H_ */
