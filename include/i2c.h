#ifndef I2C_H
#define I2C_H

#include <stm32f103xe.h>
#include <stdint.h>

// Hàm khởi tạo I2C
void I2C1_Init(void); // Khởi tạo I2C1 (PB6, PB7)
void I2C2_Init(void); // Khởi tạo I2C2 (PB10, PB11)

// Hàm gửi một byte qua I2C
void I2C1_SendByte(uint8_t address, uint8_t data); // Gửi qua I2C1
void I2C2_SendByte(uint8_t address, uint8_t data); // Gửi qua I2C2

// Hàm gửi nhiều byte qua I2C
void I2C1_SendBytes(uint8_t address, const uint8_t *data, uint8_t length); // Gửi qua I2C1
void I2C2_SendBytes(uint8_t address, const uint8_t *data, uint8_t length); // Gửi qua I2C2

#endif // I2C_H