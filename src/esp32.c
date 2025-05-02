#include "esp32.h"
#include "i2c.h"

void ESP32_Init(void) {
    // Khởi tạo I2C2 (PB10, PB11)
    I2C2_Init();
}

void ESP32_SendData(const uint8_t *data, uint8_t length) {
    // Gửi dữ liệu đến ESP32 qua I2C2
    I2C2_SendBytes(ESP32_I2C_ADDRESS, data, length);
}