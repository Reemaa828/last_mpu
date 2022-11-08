/*
 * I2C.h
 *
 *  Created on: 28 Oct 2022
 *      Author: Ahmed
 */

#ifndef I2C_H_
#define I2C_H_
#include "STD_Types.h"
#include <stdbool.h>
#include <util/twi.h>
typedef u16 ret_code_t;
#define DEBUG_LOG			0
#define SUCCESS				0

#define TW_SCL_PIN			PORTC5
#define TW_SDA_PIN			PORTC4

#define TW_SLA_W(ADDR)		((ADDR << 1) | TW_WRITE)
#define TW_SLA_R(ADDR)		((ADDR << 1) | TW_READ)
#define TW_READ_ACK			1
#define TW_READ_NACK		0

typedef enum {
	TW_FREQ_100K,
	TW_FREQ_250K,
	TW_FREQ_400K
} twi_freq_mode_t;

void tw_init(twi_freq_mode_t twi_freq, bool pullup_en);
void I2C_INT(void);
u8 I2C_Start_Condition(void);
void I2C_Stop_Condition(void);
void I2C_Writing(u8 data);
u8 I2C_Reading_ACK(void);
u8 I2C_Reading_NOT_ACK(void);
u8 I2C_Start_Repeated(void);
ret_code_t tw_master_transmit(u8 slave_addr, u8* p_data, u8 len, bool repeat_start);
ret_code_t tw_master_receive(u8 slave_addr, u8* p_data, u8 len);

#endif /* I2C_H_ */
