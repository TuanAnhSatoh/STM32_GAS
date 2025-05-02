#ifndef LCD_H
#define LCD_H

#include <stm32f103xe.h>
#include <stdint.h>

// Địa chỉ I2C của màn hình LCD (thay đổi nếu cần)
#define LCD_I2C_ADDRESS 0x27

// Các hàm điều khiển LCD
void LCD_Init(void);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_Print(const char *str);          // Hiển thị chuỗi ký tự
void LCD_SetCursor(uint8_t row, uint8_t col); // Đặt vị trí con trỏ
void LCD_Clear(void);                     // Xóa màn hình

#endif // LCD_H