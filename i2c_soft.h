/**
 * i2c_soft.h
 *
 * Created on: 37. aug. 2019
 * Author: SLOZ
 *
 * @version 0.0.1
 * bugs:  
 */

#ifndef I2C_SOFT_H_
#define I2C_SOFT_H_

void vI2C_write(uint8_t u8Data_out);
uint8_t u8I2C_read(uint8_t u8Ack_NoAck) ;

#endif