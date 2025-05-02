#ifndef ESP32_H
#define ESP32_H

#include <stdint.h>

// Địa chỉ I2C của ESP32 (thay đổi nếu cần)
#define ESP32_I2C_ADDRESS 0x3C

// Các hàm giao tiếp với ESP32
void ESP32_Init(void);                     // Khởi tạo giao tiếp với ESP32
void ESP32_SendData(const uint8_t *data, uint8_t length); // Gửi dữ liệu đến ESP32

#endif // ESP32_H